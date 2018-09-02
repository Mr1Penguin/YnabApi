#pragma once

#include "winrt/apicc.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <type_traits>

using rwriter = rapidjson::Writer<rapidjson::GenericStringBuffer<rapidjson::UTF16<>>, rapidjson::UTF16<>>;
using rvalue = rapidjson::GenericValue<rapidjson::UTF16<>>;

namespace apicc {
	struct BaseModel {
		virtual ~BaseModel() {}
		virtual void Serialize(rwriter & writer) = 0; // writer creates json string from current and nested objects
		virtual void Deserialize(const rvalue & document) = 0; // document created from json string
	protected:

		template<class T>
		void Write(winrt::Windows::Foundation::IReference<T> obj, rwriter & writer, const wchar_t * key,
			rapidjson::SizeType keyLength, bool forceNull = false) noexcept {
			if (key != nullptr && (obj || forceNull))
				writer.Key(key, keyLength);

			if (!obj) {
				if (forceNull)
					writer.Null();
				return;
			}

			if constexpr (std::is_same_v<int32_t, T>) {
				writer.Int(obj.GetInt32());
			}
		}

		void Write(const winrt::apicc::NullableString & obj, rwriter & writer, const wchar_t * key,
			rapidjson::SizeType keyLength, bool forceNull = false) noexcept {
			if (key != nullptr && (!obj.IsNull || forceNull))
				writer.Key(key, keyLength);

			if (obj.IsNull) {
				if (forceNull)
					writer.Null();
				return;
			}

			writer.String(obj.Value.c_str(), static_cast<rapidjson::SizeType>(obj.Value.size()));
		}

		void Write(const winrt::hstring & obj, rwriter & writer, const wchar_t * key,
				   rapidjson::SizeType keyLength) noexcept {
			Write({ obj, false }, writer, key, keyLength, false);
		}

		template<class T>
		winrt::Windows::Foundation::IReference<T> Read(const rvalue & document, wchar_t * key) noexcept {
			winrt::Windows::Foundation::IReference<T> obj = nullptr;
			const rvalue * val = &document;
			if (key != nullptr) {
				auto it = val->FindMember(key);
				if (it == val->MemberEnd() || it->value.IsNull()) {
					return obj;
				}

				val = &it->value;
			}

			if constexpr (std::is_same_v<T, int32_t>) {
				obj = val->GetInt();
			}

			return obj;
		}

		template<class T>
		winrt::apicc::NullableString Read<winrt::apicc::NullableString>(const rvalue & document,
																		 wchar_t * key) noexcept {
			const rvalue * val = &document;
			if (key != nullptr) {
				auto it = val->FindMember(key);
				if (it == val->MemberEnd() || it->value.IsNull()) {
					return { L"", true };
				}

				val = &it->value;
			}

			return { val->GetString(), false };
		}

		template<class T>
		winrt::hstring Read<winrt::hstring>(const rvalue & document, wchar_t * key) noexcept {
			const rvalue * val = &document;
			if (key != nullptr) {
				val = &val->FindMember(key)->value;
			}

			return val->GetString();
		}
	};
}