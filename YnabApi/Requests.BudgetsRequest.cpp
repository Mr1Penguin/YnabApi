#include "Requests.BudgetsRequest.h"
#include "pch.h"

using namespace winrt;

namespace wf = Windows::Foundation;

namespace winrt::YnabApi::Requests::implementation {
wf::IAsyncOperation<Models::BudgetsResponse> BudgetsRequest::ExecuteAsync() const {
  winrt::hstring path{L"/budgets"};
  return ExecuteDefaultGetAsync(path);
}
} // namespace winrt::YnabApi::Requests::implementation
