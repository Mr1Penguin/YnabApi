//
// Declaration of the BudgetDetail class.
//

#pragma once

#include "Models.Budget.g.h"

namespace mp = winrt::YnabApi::Models;
namespace wfc = winrt::Windows::Foundation::Collections;

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
  winrt::Windows::Foundation::Collections::IVector<mp::Account> Accounts() { return m_accounts; }
  void Accounts(const wfc::IVector<mp::Account> &accounts) { m_accounts = accounts; }
  wfc::IVector<mp::Payee> Payees() { return m_payees; }
  void Payees(const wfc::IVector<mp::Payee> &payees) { m_payees = payees; }
  wfc::IVector<mp::PayeeLocation> PayeeLocations() { return m_payee_locations; }
  void PayeeLocations(const wfc::IVector<mp::PayeeLocation> &payee_locations) { m_payee_locations = payee_locations; }
  wfc::IVector<mp::CategoryGroup> CategoryGroups() const noexcept { return m_category_groups; }
  void CategoryGroups(wfc::IVector<mp::CategoryGroup> category_groups) noexcept { m_category_groups = category_groups; }
  wfc::IVector<mp::Category> Categories() const noexcept { return m_categories; }
  void Categories(wfc::IVector<mp::Category> categories) noexcept { m_categories = categories; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  hstring m_id;
  hstring m_name;
  apicc::NullableString m_last_modified_on;
  mp::DateFormat m_date_format{nullptr};
  mp::CurrencyFormat m_currency_format{nullptr};
  wfc::IVector<mp::Account> m_accounts;
  wfc::IVector<mp::Payee> m_payees;
  wfc::IVector<mp::PayeeLocation> m_payee_locations;
  wfc::IVector<mp::CategoryGroup> m_category_groups;
  wfc::IVector<mp::Category> m_categories;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Budget : BudgetT<Budget, implementation::Budget> {};
} // namespace winrt::YnabApi::Models::factory_implementation
