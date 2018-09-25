#pragma once

#include "winrt/base.h"
#include "winrt/YnabApi.Models.h"

namespace winrt::YnabApi::Utilities {
winrt::hstring AccountTypeToString(Models::AccountType type);
Models::AccountType StringToAccountType(const winrt::hstring & string);
}