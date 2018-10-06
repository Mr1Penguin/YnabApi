#include "pch.h"
#include "EnumHelper.h"

namespace winrt::YnabApi::Utilities {

namespace {
constexpr uint64_t mix(wchar_t m, uint64_t s) { return (((~m & 0XFF)) * 56377) % 11113 + (s * 56473) % 10613; }

constexpr uint64_t hash(const wchar_t *m) { return (*m) ? mix(*m, hash(m + 1)) : 0; }
} // namespace

winrt::hstring AccountTypeToString(Models::AccountType type) {
  switch (type) {
  case winrt::YnabApi::Models::AccountType::Checking:
    return L"checking";
  case winrt::YnabApi::Models::AccountType::Savings:
    return L"savings";
  case winrt::YnabApi::Models::AccountType::Cash:
    return L"cash";
  case winrt::YnabApi::Models::AccountType::CreditCard:
    return L"creditCard";
  case winrt::YnabApi::Models::AccountType::LineOfCredit:
    return L"lineOfCredit";
  case winrt::YnabApi::Models::AccountType::OtherAsset:
    return L"otherAsset";
  case winrt::YnabApi::Models::AccountType::OtherLiability:
    return L"otherLiability";
  case winrt::YnabApi::Models::AccountType::PayPal:
    return L"payPal";
  case winrt::YnabApi::Models::AccountType::MerchantAccount:
    return L"merchantAccount";
  case winrt::YnabApi::Models::AccountType::InvestmentAccount:
    return L"investmentAccount";
  case winrt::YnabApi::Models::AccountType::Mortgage:
    return L"mortgage";
  }
  return L"";
}

Models::AccountType StringToAccountType(const winrt::hstring &string) {
  switch (hash(string.c_str())) {
  case hash(L"checking"):
    return Models::AccountType::Checking;
  case hash(L"savings"):
    return Models::AccountType::Savings;
  case hash(L"cash"):
    return Models::AccountType::Cash;
  case hash(L"creditCard"):
    return Models::AccountType::CreditCard;
  case hash(L"lineOfCredit"):
    return Models::AccountType::LineOfCredit;
  case hash(L"otherAsset"):
    return Models::AccountType::OtherAsset;
  case hash(L"otherLiability"):
    return Models::AccountType::OtherLiability;
  case hash(L"payPal"):
    return Models::AccountType::PayPal;
  case hash(L"merchantAccount"):
    return Models::AccountType::MerchantAccount;
  case hash(L"investmentAccount"):
    return Models::AccountType::InvestmentAccount;
  case hash(L"mortgage"):
    return Models::AccountType::Mortgage;
  }
  return Models::AccountType::Unknown;
}

winrt::hstring GoalTypeToString(Models::GoalType type) {
  switch (type) {
  case Models::GoalType::MF:
    return L"MF";
  case Models::GoalType::TB:
    return L"TB";
  case Models::GoalType::TBD:
    return L"TBD";
  }
  return L"";
}

Models::GoalType StringToGoalType(const winrt::hstring &string) {
  switch (hash(string.c_str())) {
  case hash(L"MF"):
    return Models::GoalType::MF;
  case hash(L"TB"):
    return Models::GoalType::TB;
  case hash(L"TBD"):
    return Models::GoalType::TBD;
  }
  return Models::GoalType::Unknown;
}
} // namespace winrt::YnabApi::Utilities