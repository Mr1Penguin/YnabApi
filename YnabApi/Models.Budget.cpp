#include "pch.h"
#include "Models.Budget.h"
#include "Models.CurrencyFormat.h"
#include "Models.DateFormat.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Budget::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(m_last_modified_on, writer, L"last_modified_on");
  Write(get_self<implementation::DateFormat>(m_date_format), writer, L"date_format");
  Write(get_self<implementation::CurrencyFormat>(m_currency_format), writer, L"currency_format");
}

void Budget::Deserialize(const rvalue &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_last_modified_on = Read<apicc::NullableString>(document, L"last_modified_on");
  m_date_format = Read<implementation::DateFormat>(document, L"date_format");
  m_currency_format = Read<implementation::CurrencyFormat>(document, L"currency_format");
}
} // namespace winrt::YnabApi::Models::implementation
