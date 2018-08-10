#pragma once

#include "winrt/base.h"
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Storage.h"
#include "winrt/Windows.Web.Http.h"
#include "winrt/apicc.h"

#include <map>

#include "config.h"

namespace wwh = winrt::Windows::Web::Http;

namespace apicc {
	template<class T>
	class Request {
	public:
		virtual ~Request() {}
		//To be set by consumer
		virtual winrt::Windows::Foundation::IAsyncOperation<T> ExecuteAsync() = 0;
	protected:
		winrt::Windows::Foundation::IAsyncOperation<T> ExecuteDefaultGetAsync(winrt::hstring path) {
			co_await winrt::resume_background();
			winrt::apicc::IModel result{ nullptr };
			try {
				// await Requester.CheckTokenAsync(cancellationToken).ConfigureAwait(false);
				winrt::Windows::Foundation::Uri uri{ BaseUri, path };
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

		winrt::Windows::Foundation::IAsyncOperation<T> ExecuteDefaultPostAsync(winrt::hstring path,
			std::map<winrt::hstring, winrt::hstring> && values) {
			co_await winrt::resume_background();
			winrt::apicc::IModel result{ nullptr };
			try {
				// await Requester.CheckTokenAsync(cancellationToken).ConfigureAwait(false);
				auto vals = winrt::single_threaded_map(std::move(values));
				wwh::IHttpContent content{ wwh::HttpFormUrlEncodedContent{ vals } };
				winrt::Windows::Foundation::Uri uri{ BaseUri, path };
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
	};
}