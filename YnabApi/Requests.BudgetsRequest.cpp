#include "pch.h"
#include "Requests.BudgetsRequest.h"

using namespace winrt;

namespace wf = Windows::Foundation;

namespace winrt::YnabApi::Requests::implementation
{
    wf::IAsyncOperation<Models::BudgetsResponse> BudgetsRequest::ExecuteAsync() const {
        winrt::hstring path{ L"/budgets" };
        return ExecuteDefaultGetAsync(path);
    }
}
