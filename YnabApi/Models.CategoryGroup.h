//
// Declaration of the CategoryGroup class.
//

#pragma once

#include "Models.CategoryGroup.g.h"

namespace winrt::YnabApi::Models::implementation {
struct CategoryGroup : CategoryGroupT<CategoryGroup>, ::apicc::BaseModel {
  CategoryGroup() = default;
  winrt::hstring Id() const noexcept { return m_id; }
  void Id(winrt::hstring const &id) noexcept { m_id = id; }
  winrt::hstring Name() const noexcept { return m_name; }
  void Name(winrt::hstring const &name) noexcept { m_name = name; }
  bool Hidden() const noexcept { return m_hidden; }
  void Hidden(bool hidden) noexcept { m_hidden = hidden; }
  bool Deleted() const noexcept { return m_deleted; }
  void Deleted(bool deleted) noexcept { m_deleted = deleted; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_id;
  winrt::hstring m_name;
  bool m_hidden;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct CategoryGroup : CategoryGroupT<CategoryGroup, implementation::CategoryGroup> {};
} // namespace winrt::YnabApi::Models::factory_implementation
