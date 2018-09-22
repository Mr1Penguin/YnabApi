//
// Declaration of the Models class.
//

#pragma once

#include "Models.Account.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Account : AccountT<Account> {
  Account() = default;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Account : AccountT<Account, implementation::Account> {};
} // namespace winrt::YnabApi::Models::factory_implementation
