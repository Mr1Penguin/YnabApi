#include "pch.h"
#include "Models.BudgetsResponse.h"
#include "Models.Budget.h"
#include "Models.Error.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void BudgetsResponse::Serialize(rwriter &writer) {
  Write(get_self<implementation::Error>(m_error), writer, L"error");
  writer.Key(L"data");
  writer.StartObject();
  Write<implementation::Budget>(m_budgets, writer, L"budgets");
  writer.EndObject();
}

void BudgetsResponse::Deserialize(rvalue const &document) {
  m_error = Read<implementation::Error>(document, L"error");
  auto it = document.FindMember(L"data");
  if (it == document.MemberEnd())
    return;
  m_budgets = Read<TVec<implementation::Budget>>(it->value, L"budgets");
}
} // namespace winrt::YnabApi::Models::implementation
