//
// Declaration of the Error class.
//

#pragma once

#include "Models.Error.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Error : ErrorT<Error>, ::apicc::BaseModel {
  Error() = default;
  winrt::hstring Id() const noexcept { return m_id; }
  void Id(const winrt::hstring &id) noexcept { m_id = id; }
  winrt::hstring Name() const noexcept { return m_name; }
  void Name(const winrt::hstring &name) noexcept { m_name = name; }
  winrt::hstring Detail() const noexcept { return m_detail; }
  void Detail(const winrt::hstring &detail) noexcept { m_detail = detail; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_id;
  winrt::hstring m_name;
  winrt::hstring m_detail;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Error : ErrorT<Error, implementation::Error> {};
} // namespace winrt::YnabApi::Models::factory_implementation
