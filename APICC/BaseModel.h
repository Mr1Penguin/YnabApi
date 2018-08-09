#pragma once

#include <rapidjson\document.h>
#include <rapidjson\stringbuffer.h>
#include <rapidjson\writer.h>
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
		void Write(winrt::Windows::Foundation::IReference<T> obj, rwriter & writer, wchar_t * key,
			rapidjson::SizeType keyLength, bool forceNull = false) {
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

		template<class T>
		winrt::Windows::Foundation::IReference<T> Read(const rvalue & document, wchar_t * key) {
			winrt::Windows::Foundation::IReference<T> obj = nullptr;
			const rvalue * val = &document;
			if (key != nullptr) {
				auto it = val->FindMember(key);
				if (it == val->MemberEnd() || it->value.IsNull()) {
					return obj;
				}

				val = &it->value;
			}

			if constexpr(std::is_same_v<T, int32_t>) {
				obj = val->GetInt();
			}

			return obj;
		}
	};
}