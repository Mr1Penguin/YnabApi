#include "pch.h"
#include "Models.Account.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation
{
void Account::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(Utilities::AccountTypeToString(m_type), writer, L"type");
  Write(m_on_budget, writer, L"on_budget");
  Write(m_closed, writer, L"closed");
  Write(m_note, writer, L"note");
  Write(m_balance, writer, L"balance");
  Write(m_cleared_balance, writer, L"cleared_balance");
  Write(m_uncleared_balance, writer, L"uncleared_balance");
  Write(m_transfer_payee_id, writer, L"transfer_payee_id");
  Write(m_deleted, writer, L"deleted");
}

void Account::Deserialize(const rvalue &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_type = Utilities::StringToAccountType(Read<winrt::hstring>(document, L"type"));
  m_on_budget = Read<bool>(document, L"on_budget");
  m_closed = Read<bool>(document, L"closed");
  m_note = Read<hstring>(document, L"note");
  m_balance = Read<int64_t>(document, L"balance");
  m_cleared_balance = Read<int64_t>(document, L"cleared_balance");
  m_uncleared_balance = Read<int64_t>(document, L"uncleared_balance");
  m_transfer_payee_id = Read<hstring>(document, L"transfer_payee_id");
  m_deleted = Read<bool>(document, L"deleted");
}
}
