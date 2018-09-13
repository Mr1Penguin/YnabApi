#pragma once

#include "winrt/apicc.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using rwriter = rapidjson::Writer<rapidjson::GenericStringBuffer<rapidjson::UTF16<>>, rapidjson::UTF16<>>;
using rvalue = rapidjson::GenericValue<rapidjson::UTF16<>>;

namespace apicc {
    struct BaseModel {
        virtual ~BaseModel() {}
        virtual void Serialize(rwriter & writer) = 0; // writer creates json string from current and nested objects
        virtual void Deserialize(const rvalue & document) = 0; // document created from json string
    protected:
        //first arg = get_self<T>(T())
        template<rapidjson::SizeType N>
        static void Write(::apicc::BaseModel * model, rwriter & writer, const wchar_t(&key)[N],
                          bool forceNull = false) noexcept {
            Write(model, writer, static_cast<const wchar_t *>(key), N - 1, forceNull);
        }

        static void Write(::apicc::BaseModel * model, rwriter & writer, const wchar_t * key,
                          rapidjson::SizeType key_length, bool forceNull) noexcept {

            if (HandleKeyAndNull(key, key_length, !model, forceNull, writer))
                return;

            writer.StartObject();
            model->Serialize(writer);
            writer.EndObject();
        }

        template<class T, rapidjson::SizeType N, 
            typename = std::enable_if_t<!std::is_base_of_v<::apicc::BaseModel, std::remove_pointer_t<T>>>>
        static void Write(const T & obj, rwriter & writer, const wchar_t(&key)[N]) noexcept {
            Write(obj, writer, static_cast<const wchar_t *>(key), N - 1);
        }

        template<class T, typename = std::enable_if_t<!std::is_base_of_v<::apicc::BaseModel, std::remove_pointer_t<T>>>>
        static void Write(const T & obj, rwriter & writer, const wchar_t * key,
                          rapidjson::SizeType key_length) noexcept {
            if (HandleKeyAndNull(key, key_length, false, false, writer))
                return;


            if constexpr (std::is_same_v<bool, T>) {
                writer.Bool(obj);
            }
            else if constexpr (std::is_same_v<int32_t, T>) {
                writer.Int(obj);
            }
        }

        template<class T, rapidjson::SizeType N>
        static void Write(const winrt::Windows::Foundation::IReference<T> & obj, rwriter & writer,
                          const wchar_t(&key)[N], bool forceNull = false) noexcept {
            Write(obj, writer, static_cast<const wchar_t *>(key), N - 1, forceNull);
        }

        template<class T>
        static void Write(const winrt::Windows::Foundation::IReference<T> & obj, rwriter & writer, const wchar_t * key,
                          rapidjson::SizeType key_length, bool forceNull = false) noexcept {
            if (HandleKeyAndNull(key, key_length, !obj, forceNull, writer))
                return;

            if constexpr (std::is_same_v<int32_t, T>) {
                writer.Int(obj.GetInt32());
            }
        }

        template<rapidjson::SizeType N>
        static void Write(const winrt::apicc::NullableString & obj, rwriter & writer, const wchar_t(&key)[N],
                          bool forceNull = false) noexcept {
            Write(obj, writer, static_cast<const wchar_t *>(key), N - 1, forceNull);
        }

        static void Write(const winrt::apicc::NullableString & obj, rwriter & writer, const wchar_t * key,
                          rapidjson::SizeType key_length, bool forceNull) noexcept {
            if (HandleKeyAndNull(key, key_length, obj.IsNull, forceNull, writer))
                return;

            writer.String(obj.Value.c_str(), static_cast<rapidjson::SizeType>(obj.Value.size()));
        }

        template<rapidjson::SizeType N>
        static void Write(const winrt::hstring & obj, rwriter & writer, const wchar_t(&key)[N]) noexcept {
            Write(obj, writer, static_cast<const wchar_t *>(key), N - 1);
        }

        static void Write(const winrt::hstring & obj, rwriter & writer, const wchar_t * key,
                          rapidjson::SizeType key_length) noexcept {
            if (HandleKeyAndNull(key, key_length, false, false, writer))
                return;

            writer.String(obj.c_str(), static_cast<rapidjson::SizeType>(obj.size()));
        }

        template<class T>
        static auto Read(const rvalue & document, const wchar_t * key) noexcept {
            constexpr bool is_hstring = std::is_same_v<T, winrt::hstring>;
            constexpr bool is_nullable_string = std::is_same_v<T, winrt::apicc::NullableString>;
            constexpr bool is_derived_from_base_model = std::is_base_of_v<::apicc::BaseModel, T>;
            constexpr bool is_iref = is_iref_type<T>::value;
            //real type or stub if nullptr is not an option
            using obj_type =
                std::conditional_t<is_hstring || is_nullable_string,
                nullptr_t,
                std::conditional_t<is_derived_from_base_model,
                get_class_type<T, is_derived_from_base_model>::type,
                std::conditional_t<is_iref,
                get_iref_type<T, is_iref>::type,
                nullptr_t>>>;
            [[maybe_unused]] obj_type obj = nullptr;
            const rvalue * val = &document;
            if (key != nullptr) {
                auto it = val->FindMember(key);
                if constexpr (!is_hstring) {
                    if (it == val->MemberEnd() || it->value.IsNull()) {
                        if constexpr (is_nullable_string) {
                            return winrt::apicc::NullableString{ winrt::hstring(), true };
                        }
                        else if constexpr (is_iref || is_derived_from_base_model) {
                            return obj;
                        }
                    }
                }
                val = &it->value;
            }

            if constexpr (is_derived_from_base_model) {
                obj = winrt::make<T>();
                auto impl = winrt::get_self<T>(obj);
                impl->Deserialize(*val);
                return obj;
            }
            else if constexpr (is_nullable_string) {
                return winrt::apicc::NullableString{ { val->GetString(), val->GetStringLength() }, false };
            }
            else if constexpr (is_hstring) {
                return winrt::hstring{ val->GetString(), val->GetStringLength() };
            }
            else if constexpr (is_iref) {
                // set obj
                return obj;
            }
            else {
                //from smallest to largest numbers
                if constexpr (std::is_same_v<T, bool>) {
                    return val->GetBool();
                }
                else if constexpr (std::is_same_v<T, int32_t>) {
                    return val->GetInt();
                }
            }
        }

    private:
        // *_type help to suppress compile error 
        // in cases where std::conditional_t<false, ..., nullptr_t/std::conditional_t< ... >>
        template<class T, bool is_derived>
        struct get_class_type {
            using type = nullptr_t;
        };

        template<class T>
        struct get_class_type<T, true> {
            using type = typename T::class_type;
        };

        template<class T, bool iref>
        struct get_iref_type {
            using type = nullptr_t;
        };

        template<class T>
        struct get_iref_type<T, true> {
            using type = winrt::Windows::Foundation::IReference<T>;
        };

        template<class T>
        struct is_iref_type : std::false_type
        {};

        template<class T>
        struct is_iref_type<winrt::Windows::Foundation::IReference<T>> : std::true_type
        {};

        static bool HandleKeyAndNull(const wchar_t * key, rapidjson::SizeType key_length,
                                     bool is_null, bool forceNull, rwriter &writer) {
            if (key != nullptr && (!is_null || forceNull))
                writer.Key(key, key_length);

            if (is_null) {
                if (forceNull)
                    writer.Null();
                return true;
            }

            return false;
        }
    };
}
