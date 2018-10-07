#include "pch.h"
#include "Models.MonthInfo.h"
#include "Models.Category.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void MonthInfo::Serialize(rwriter &writer) {
  Write(m_month, writer, L"month");
  Write(m_note, writer, L"note");
  Write(m_income, writer, L"income");
  Write(m_budgeted, writer, L"budgeted");
  Write(m_activity, writer, L"activity");
  Write(m_to_be_budgeted, writer, L"to_be_budgeted");
  Write(m_age_of_money, writer, L"age_of_money");
  Write<implementation::Category>(m_categories, writer, L"categories");
}

void MonthInfo::Deserialize(rvalue const &document) {
  m_month = Read<decltype(m_month)>(document, L"month");
  m_note = Read<decltype(m_note)>(document, L"note");
  m_income = Read<decltype(m_income)>(document, L"income");
  m_budgeted = Read<decltype(m_budgeted)>(document, L"budgeted");
  m_activity = Read<decltype(m_activity)>(document, L"activity");
  m_to_be_budgeted = Read<decltype(m_to_be_budgeted)>(document, L"to_be_budgeted");
  m_age_of_money = Read<decltype(m_age_of_money)>(document, L"age_of_money");
  m_categories = Read<TVec<implementation::Category>>(document, L"categories");
}
} // namespace winrt::YnabApi::Models::implementation
