//
// Declaration of the BudgetDetail class.
//

#pragma once

#include "Models.Budget.g.h"

namespace mp = winrt::YnabApi::Models;

namespace winrt::YnabApi::Models::implementation {
struct Budget : BudgetT<Budget>, ::apicc::BaseModel {
  Budget() = default;
  hstring Id() const noexcept { return m_id; }
  void Id(const hstring &id) noexcept { m_id = id; }
  hstring Name() const noexcept { return m_name; }
  void Name(const hstring &name) noexcept { m_name = name; }
  apicc::NullableString LastModifiedOn() const noexcept { return m_last_modified_on; }
  void LastModifiedOn(const apicc::NullableString &last_modified_on) noexcept { m_last_modified_on = last_modified_on; }
  mp::DateFormat DateFormat() const noexcept { return m_date_format; }
  void DateFormat(mp::DateFormat date_format) noexcept { m_date_format = date_format; }
  mp::CurrencyFormat CurrencyFormat() const noexcept { return m_currency_format; }
  void CurrencyFormat(mp::CurrencyFormat currency_format) noexcept { m_currency_format = currency_format; }
  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  hstring m_id;
  hstring m_name;
  apicc::NullableString m_last_modified_on;
  mp::DateFormat m_date_format{nullptr};
  mp::CurrencyFormat m_currency_format{nullptr};
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Budget : BudgetT<Budget, implementation::Budget> {};
} // namespace winrt::YnabApi::Models::factory_implementation
