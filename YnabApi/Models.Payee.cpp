#include "pch.h"
#include "Models.Payee.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Payee::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(m_transfer_account_id, writer, L"transfer_payee_id");
  Write(m_deleted, writer, L"deleted");
}

void Payee::Deserialize(const rvalue &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_transfer_account_id = Read<hstring>(document, L"transfer_payee_id");
  m_deleted = Read<bool>(document, L"deleted");
}
}
