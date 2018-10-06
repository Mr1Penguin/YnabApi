#include "pch.h"
#include "Models.CategoryGroup.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation {
void CategoryGroup::Serialize(rwriter &writer) {
  Write(m_id, writer, L"id");
  Write(m_name, writer, L"name");
  Write(m_hidden, writer, L"hidden");
  Write(m_deleted, writer, L"deleted");
}

void CategoryGroup::Deserialize(rvalue const &document) {
  m_id = Read<winrt::hstring>(document, L"id");
  m_name = Read<winrt::hstring>(document, L"name");
  m_hidden = Read<bool>(document, L"hidden");
  m_deleted = Read<bool>(document, L"deleted");
}
} // namespace winrt::YnabApi::Models::implementation
