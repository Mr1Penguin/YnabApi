//
// Declaration of the BudgetsRequest class.
//

#pragma once

#include "Requests.BudgetsRequest.g.h"

#include "Models.BudgetsResponse.h"

#include "Request.h"

namespace winrt::YnabApi::Requests::implementation
{
    struct BudgetsRequest : BudgetsRequestT<BudgetsRequest>, ::apicc::Request<Models::implementation::BudgetsResponse>
    {
        BudgetsRequest() = default;
        Windows::Foundation::IAsyncOperation<Models::BudgetsResponse> ExecuteAsync() const override;
    };
}

namespace winrt::YnabApi::Requests::factory_implementation
{
    struct BudgetsRequest : BudgetsRequestT<BudgetsRequest, implementation::BudgetsRequest>
    {
    };
}
