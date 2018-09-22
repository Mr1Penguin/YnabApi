#include "pch.h"
#include "Models.Error.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void Error::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(m_detail, writer, L"detail");
}

void Error::Deserialize(rvalue const &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_detail = Read<winrt::hstring>(document, L"detail");
}
} // namespace winrt::YnabApi::Models::implementation
