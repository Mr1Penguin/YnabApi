﻿//
// Declaration of the Budgets class.
//

#pragma once

#include "Models.BudgetsResponse.g.h"

namespace mp = winrt::YnabApi::Models;

namespace winrt::YnabApi::Models::implementation {
struct BudgetsResponse : BudgetsResponseT<BudgetsResponse>, ::apicc::BaseModel {
  BudgetsResponse() = default;
  mp::Error Error() const noexcept { return m_error; }
  void Error(mp::Error error) noexcept { m_error = error; }
  Windows::Foundation::Collections::IVector<mp::Budget> Budgets() { return m_budgets; }
  void Budgets(const Windows::Foundation::Collections::IVector<mp::Budget> &budgets) { m_budgets = budgets; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  mp::Error m_error{nullptr};
  winrt::Windows::Foundation::Collections::IVector<mp::Budget> m_budgets;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct BudgetsResponse : BudgetsResponseT<BudgetsResponse, implementation::BudgetsResponse> {};
} // namespace winrt::YnabApi::Models::factory_implementation
