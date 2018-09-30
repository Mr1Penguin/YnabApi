#include "pch.h"
#include "Models.PayeeLocation.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void PayeeLocation::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_payee_id, writer, L"payee_id");
  Write(m_latitude, writer, L"latitude");
  Write(m_longitude, writer, L"longitude");
  Write(m_deleted, writer, L"deleted");
}

void PayeeLocation::Deserialize(const rvalue &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_payee_id = Read<winrt::hstring>(document, L"payee_id");
  m_latitude = Read<hstring>(document, L"latitude");
  m_longitude = Read<hstring>(document, L"longitude");
  m_deleted = Read<bool>(document, L"deleted");
}
} // namespace winrt::YnabApi::Models::implementation
