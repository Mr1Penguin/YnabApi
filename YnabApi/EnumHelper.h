#pragma once

#include "winrt/base.h"
#include "winrt/YnabApi.Models.h"

namespace winrt::YnabApi::Utilities {
winrt::hstring AccountTypeToString(Models::AccountType type);
Models::AccountType StringToAccountType(const winrt::hstring &string);
winrt::hstring GoalTypeToString(Models::GoalType type);
Models::GoalType StringToGoalType(const winrt::hstring &string);
winrt::hstring ClearedToString(Models::Cleared type);
Models::Cleared StringToCleared(const winrt::hstring &string);
winrt::hstring FlagColorToString(Models::FlagColor type);
Models::FlagColor StringToFlagColor(const winrt::hstring &string);
} // namespace winrt::YnabApi::Utilities