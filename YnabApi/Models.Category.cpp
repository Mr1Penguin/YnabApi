#include "pch.h"
#include "Models.Category.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Category::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_category_group_id, writer, L"category_group_id");
  Write(m_name, writer, L"name");
  Write(m_hidden, writer, L"hidden");
  Write(m_original_category_group_id, writer, L"original_category_group_id");
  Write(m_note, writer, L"note");
  Write(m_budgeted, writer, L"budgeted");
  Write(m_activity, writer, L"activity");
  Write(m_balance, writer, L"balance");
  Write(Utilities::GoalTypeToString(m_goal_type), writer, L"goal_type");
  Write(m_goal_creation_month, writer, L"goal_creation_month");
  Write(m_goal_target, writer, L"goal_target");
  Write(m_goal_target_month, writer, L"goal_target_month");
  Write(m_goal_percentage_complete, writer, L"goal_percentage_complete");
  Write(m_deleted, writer, L"deleted");
}

void Category::Deserialize(rvalue const &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_category_group_id = Read<winrt::hstring>(document, L"category_group_id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_hidden = Read<bool>(document, L"hidden");
  m_original_category_group_id = Read<apicc::NullableString>(document, L"original_category_group_id");
  m_note = Read<winrt::hstring>(document, L"note");
  m_budgeted = Read<int64_t>(document, L"budgeted");
  m_activity = Read<int64_t>(document, L"activity");
  m_balance = Read<int64_t>(document, L"balance");
  m_goal_type = Utilities::StringToGoalType(Read<winrt::hstring>(document, L"goal_type"));
  m_goal_creation_month = Read<winrt::hstring>(document, L"goal_creation_month");
  m_goal_target = Read<uint64_t>(document, L"goal_target");
  m_goal_target_month = Read<winrt::hstring>(document, L"goal_target_month");
  m_goal_percentage_complete = Read<int32_t>(document, L"goal_percentage_complete");
  m_deleted = Read<bool>(document, L"deleted");
}
} // namespace winrt::YnabApi::Models::implementation
