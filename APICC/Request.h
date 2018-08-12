#pragma once

#include "winrt/base.h"
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Storage.h"
#include "winrt/Windows.Web.Http.h"
#include "winrt/Windows.Web.Http.Filters.h"
#include "winrt/apicc.h"

#include <map>

#include "config.h"

namespace wwh = winrt::Windows::Web::Http;
namespace wf = winrt::Windows::Foundation;

using namespace std::chrono_literals;

namespace apicc {
	class RequestCommon {
	public:
	protected:
		static wwh::HttpClient HttpClient() {
			static wwh::Filters::HttpBaseProtocolFilter filter;
			static wwh::HttpClient instance{ nullptr };
			if (!instance) {
				filter.AutomaticDecompression(true);
				instance = wwh::HttpClient(filter);
				auto defHeaders = instance.DefaultRequestHeaders();
				defHeaders.Accept().Append(wwh::Headers::HttpMediaTypeWithQualityHeaderValue{ L"application/json" });
				defHeaders.UserAgent().ParseAdd(L"APICC");
			}

			return instance;
		}

		inline static auto DelayTime = 0s;

	private:
	};

	template<class T>
	class Request : public RequestCommon {
	public:
		virtual ~Request() {}
		//To be set by consumer
		virtual wf::IAsyncOperation<T> ExecuteAsync() = 0;
	protected:
		wf::IAsyncOperation<T> ExecuteDefaultGetAsync(winrt::hstring path) {
			co_await winrt::resume_background();
			winrt::apicc::IModel result{ nullptr };
			try {
				// await Requester.CheckTokenAsync(cancellationToken).ConfigureAwait(false);
				if (TokenPassingType == TokenPassingTypes::kParameter)
					path += L"&" + TokenParamName + L"=" + Token;
				wf::Uri uri{ BaseUri, path };
				// result = await Requester.MakeRequestAsync<T>(uri, cancellationToken: cancellationToken).ConfigureAwait(false);
				co_return result.as<T>();
			}
			catch (winrt::hresult_canceled) {
				throw;
			}
			catch (winrt::hresult_error e) {
				result.ErrorText({ e.message(), false });
				co_return result.as<T>();
			}
		}

		wf::IAsyncOperation<T> ExecuteDefaultPostAsync(winrt::hstring path,
			std::map<winrt::hstring, winrt::hstring> && values) {
			co_await winrt::resume_background();
			winrt::apicc::IModel result{ nullptr };
			try {
				// await Requester.CheckTokenAsync(cancellationToken).ConfigureAwait(false);
				if (TokenPassingType == TokenPassingTypes::kParameter) {
					values.emplace({ TokenParamName, Token });
				}
				auto vals = winrt::single_threaded_map(std::move(values));
				wwh::IHttpContent content{ wwh::HttpFormUrlEncodedContent{ vals } };
				wf::Uri uri{ BaseUri, path };
				// result = await Requester.MakeRequestAsync<T>(uri, content, method: HttpMethod.Post, cancellationToken: cancellationToken).ConfigureAwait(false);
				co_return result.as<T>();
			}
			catch (winrt::hresult_canceled) {
				throw;
			}
			catch (winrt::hresult_error e) {
				result.ErrorText({ e.message(), false });
				co_return result.as<T>();
			}
		}
	private:
		wf::IAsyncOperation<T> MakeRequestAsync(wf::Uri const & uri, wwh::IHttpContent const & content, 
			wwh::HttpMethod const & method){
			auto token = co_await winrt::get_cancellation_token();
			//todo: print some debug log info about request
			if (token()) throw winrt::hresult_canceled();

			auto message = GetRequestMessage(uri, content, method);

			wf::IAsyncOperationWithProgress<wwh::HttpResponseMessage, wwh::HttpProgress> request{ nullptr };
			
			auto timeout_f = [](decltype(request) r) -> wf::IAsyncAction {
				co_await winrt::resume_background();
				auto token = co_await winrt::get_cancellation_token();
				co_await 30s;
				if (!token())
					r.Cancel();
			};

			do {
				co_await DelayTime;

				request = HttpClient().SendRequestAsync(message);
				auto timeout = timeout_f(request);
				wwh::HttpResponseMessage result{ nullptr };

				try {
					//it could be ignored so better check twice later
					result = co_await request;
				}
				catch (winrt::hresult_canceled) {
					if (timeout.Status() == wf::AsyncStatus::Completed)
						throw winrt::hresult_error(L"Request timed out");
					throw;
				}
				timeout.Cancel();

				if (result.StatusCode() != wwh::HttpStatusCode::TooManyRequests) {
					DelayTime = DelayTime == 1s ? 0s : DelayTime / 2;
					T res;
					rapidjson::GenericDocument<rapidjson::UTF16<>> doc;
					doc.Parse((co_await result.Content().ReadAsStringAsync()).c_str());
					res.Deserialize(doc);
					co_return T;
				}

				DelayTime = DelayTime == 0s ? 1s : DelayTime * 2;
				message = GetRequestMessage(uri, content, method);
			} while (true);
		}

		wwh::HttpRequestMessage GetRequestMessage(wf::Uri const & uri, wwh::IHttpContent const & content,
			wwh::HttpMethod method) noexcept {
			wwh::HttpRequestMessage httpRequestMessage{ method, uri };
			httpRequestMessage.Content(content);
			auto headers = httpRequestMessage.Headers();
			switch (TokenPassingType) {
			case TokenPassingTypes::kHeader:
				headers.Append(TokenParamName, Token);
				break;
			case TokenPassingTypes::kParameter:
				// handled by ExecuteDefaultMETHODAsync
				break;
			default:
				throw std::runtime_error("Unknown type of token passing!");
				break;
			}

			return httpRequestMessage;
		}

	};
}