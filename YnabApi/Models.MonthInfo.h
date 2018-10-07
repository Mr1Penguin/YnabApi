//
// Declaration of the Month class.
//

#pragma once

#include "Models.MonthInfo.g.h"

namespace mp = winrt::YnabApi::Models;
namespace wfc = winrt::Windows::Foundation::Collections;

namespace winrt::YnabApi::Models::implementation {
struct MonthInfo : MonthInfoT<MonthInfo>, ::apicc::BaseModel {
  MonthInfo() = default;
  winrt::hstring Month() const noexcept { return m_month; }
  void Month(winrt::hstring const &month) noexcept { m_month = month; }
  winrt::hstring Note() const noexcept { return m_note; }
  void Note(winrt::hstring const &note) noexcept { m_note = note; }
  int64_t Income() const noexcept { return m_income; }
  void Income(int64_t income) noexcept { m_income = income; }
  int64_t Budgeted() const noexcept { return m_budgeted; }
  void Budgeted(int64_t budgeted) noexcept { m_budgeted = budgeted; }
  int64_t Activity() const noexcept { return m_activity; }
  void Activity(int64_t activity) noexcept { m_activity = activity; }
  int64_t ToBeBudgeted() const noexcept { return m_to_be_budgeted; }
  void ToBeBudgeted(int64_t to_be_budgeted) noexcept { m_to_be_budgeted = to_be_budgeted; }
  int32_t AgeOfMoney() const noexcept { return m_age_of_money; }
  void AgeOfMoney(int32_t age_of_money) noexcept { m_age_of_money = age_of_money; }
  wfc::IVector<mp::Category> Categories() const noexcept { return m_categories; }
  void Categories(wfc::IVector<mp::Category> categories) noexcept { m_categories = categories; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_month;
  winrt::hstring m_note;
  int64_t m_income;
  int64_t m_budgeted;
  int64_t m_activity;
  int64_t m_to_be_budgeted;
  int32_t m_age_of_money;
  wfc::IVector<mp::Category> m_categories;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct MonthInfo : MonthInfoT<MonthInfo, implementation::MonthInfo> {};
} // namespace winrt::YnabApi::Models::factory_implementation
