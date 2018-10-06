//
// Declaration of the Category class.
//

#pragma once

#include "Models.Category.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Category : CategoryT<Category>, ::apicc::BaseModel {
  Category() = default;
  winrt::hstring Id() const noexcept { return m_id; }
  void Id(winrt::hstring const &id) noexcept { m_id = id; }
  winrt::hstring CategoryGroupId() const noexcept { return m_category_group_id; }
  void CategoryGroupId(winrt::hstring const &category_group_id) noexcept { m_category_group_id = category_group_id; }
  winrt::hstring Name() const noexcept { return m_name; }
  void Name(winrt::hstring const &name) noexcept { m_name = name; }
  bool Hidden() const noexcept { return m_hidden; }
  void Hidden(bool hidden) noexcept { m_hidden = hidden; }
  apicc::NullableString OriginalCategoryGroupId() const noexcept { return m_original_category_group_id; }
  void OriginalCategoryGroupId(apicc::NullableString original_category_group_id) noexcept {
    m_original_category_group_id = original_category_group_id;
  }
  winrt::hstring Note() const noexcept { return m_note; }
  void Note(winrt::hstring const &note) noexcept { m_note = note; }
  uint64_t Budgeted() const noexcept { return m_budgeted; }
  void Budgeted(uint64_t budgeted) noexcept { m_budgeted = budgeted; }
  uint64_t Activity() const noexcept { return m_activity; }
  void Activity(uint64_t activity) noexcept { m_activity = activity; }
  uint64_t Balance() const noexcept { return m_balance; }
  void Balance(uint64_t balance) noexcept { m_balance = balance; }
  Models::GoalType GoalType() const noexcept { return m_goal_type; }
  void GoalType(Models::GoalType goal_type) noexcept { m_goal_type = goal_type; }
  winrt::hstring GoalCreationMonth() const noexcept { return m_goal_creation_month; }
  void GoalCreationMonth(winrt::hstring const &goal_creation_month) noexcept {
    m_goal_creation_month = goal_creation_month;
  }
  uint64_t GoalTarget() const noexcept { return m_goal_target; }
  void GoalTarget(uint64_t goal_target) noexcept { m_goal_target = goal_target; }
  winrt::hstring GoalTargetMonth() const noexcept { return m_goal_target_month; }
  void GoalTargetMonth(winrt::hstring const &goal_target_month) noexcept { m_goal_target_month = goal_target_month; }
  int32_t GoalPercentageComplete() const noexcept { return m_goal_percentage_complete; }
  void GoalPercentageComplete(int32_t goal_percentage_complete) noexcept {
    m_goal_percentage_complete = goal_percentage_complete;
  }
  bool Deleted() const noexcept { return m_deleted; }
  void Deleted(bool deleted) noexcept { m_deleted = deleted; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_id;
  winrt::hstring m_category_group_id;
  winrt::hstring m_name;
  bool m_hidden;
  apicc::NullableString m_original_category_group_id;
  winrt::hstring m_note;
  uint64_t m_budgeted;
  uint64_t m_activity;
  uint64_t m_balance;
  Models::GoalType m_goal_type;
  winrt::hstring m_goal_creation_month;
  uint64_t m_goal_target;
  winrt::hstring m_goal_target_month;
  int32_t m_goal_percentage_complete;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Category : CategoryT<Category, implementation::Category> {};
} // namespace winrt::YnabApi::Models::factory_implementation
