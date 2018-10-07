#include "pch.h"
#include "Models.Transaction.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Transaction::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_date, writer, L"date");
  Write(m_amount, writer, L"amount");
  Write(m_memo, writer, L"memo");
  Write(Utilities::ClearedToString(m_cleared), writer, L"cleared");
  Write(m_approved, writer, L"approved");
  Write(Utilities::FlagColorToString(m_flag_color), writer, L"flag_color");
  Write(m_account_id, writer, L"account_id");
  Write(m_payee_id, writer, L"payee_id");
  Write(m_category_id, writer, L"category_id");
  Write(m_transfer_account_id, writer, L"transfer_account_id");
  Write(m_transfer_transaction_id, writer, L"transfer_transaction_id");
  Write(m_import_id, writer, L"import_id");
  Write(m_deleted, writer, L"deleted");
}

void Transaction::Deserialize(rvalue const &document) {
  m_id = Read<decltype(m_id)>(document, L"id");
  m_date = Read<decltype(m_date)>(document, L"date");
  m_amount = Read<decltype(m_amount)>(document, L"amount");
  m_memo = Read<decltype(m_memo)>(document, L"memo");
  m_cleared = Utilities::StringToCleared(Read<winrt::hstring>(document, L"cleared"));
  m_approved = Read<decltype(m_approved)>(document, L"approved");
  m_flag_color = Utilities::StringToFlagColor(Read<winrt::hstring>(document, L"flag_color"));
  m_account_id = Read<decltype(m_account_id)>(document, L"account_id");
  m_payee_id = Read<decltype(m_payee_id)>(document, L"payee_id");
  m_category_id = Read<decltype(m_category_id)>(document, L"category_id");
  m_transfer_account_id = Read<decltype(m_transfer_account_id)>(document, L"transfer_account_id");
  m_transfer_transaction_id = Read<decltype(m_transfer_transaction_id)>(document, L"transfer_transaction_id");
  m_import_id = Read<decltype(m_import_id)>(document, L"import_id");
  m_deleted = Read<decltype(m_deleted)>(document, L"deleted");
}
} // namespace winrt::YnabApi::Models::implementation
