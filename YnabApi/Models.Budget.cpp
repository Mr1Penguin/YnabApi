#include "pch.h"
#include "Models.Budget.h"
#include "Models.CurrencyFormat.h"
#include "Models.DateFormat.h"
#include "Models.Account.h"
#include "Models.Payee.h"
#include "Models.PayeeLocation.h"
#include "Models.CategoryGroup.h"
#include "Models.Category.h"
#include "Models.MonthInfo.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Budget::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(m_last_modified_on, writer, L"last_modified_on");
  Write(get_self<implementation::DateFormat>(m_date_format), writer, L"date_format");
  Write(get_self<implementation::CurrencyFormat>(m_currency_format), writer, L"currency_format");
  Write<implementation::Account>(m_accounts, writer, L"accounts");
  Write<implementation::Payee>(m_payees, writer, L"payees");
  Write<implementation::PayeeLocation>(m_payee_locations, writer, L"payee_locations");
  Write<implementation::CategoryGroup>(m_category_groups, writer, L"category_groups");
  Write<implementation::Category>(m_categories, writer, L"categories");
  Write<implementation::MonthInfo>(m_months, writer, L"months");
}

void Budget::Deserialize(const rvalue &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_last_modified_on = Read<apicc::NullableString>(document, L"last_modified_on");
  m_date_format = Read<implementation::DateFormat>(document, L"date_format");
  m_currency_format = Read<implementation::CurrencyFormat>(document, L"currency_format");
  m_accounts = Read<TVec<implementation::Account>>(document, L"accounts");
  m_payees = Read<TVec<implementation::Payee>>(document, L"payees");
  m_payee_locations = Read<TVec<implementation::PayeeLocation>>(document, L"payee_location");
  m_category_groups = Read<TVec<implementation::CategoryGroup>>(document, L"category_groups");
  m_categories = Read<TVec<implementation::Category>>(document, L"categories");
  m_months = Read<TVec<implementation::MonthInfo>>(document, L"months");
}
} // namespace winrt::YnabApi::Models::implementation
