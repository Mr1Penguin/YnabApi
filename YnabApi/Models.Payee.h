//
// Declaration of the Payee class.
//

#pragma once

#include "Models.Payee.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Payee : PayeeT<Payee>, ::apicc::BaseModel {
  Payee() = default;
  hstring Id() const noexcept { return m_id; }
  void Id(const hstring &id) noexcept { m_id = id; }
  hstring Name() const noexcept { return m_name; }
  void Name(const hstring &name) noexcept { m_name = name; }
  hstring TransferAccountId() { return m_transfer_account_id; }
  void TransferAccountId(const hstring &transfer_account_id) { m_transfer_account_id = transfer_account_id; }
  bool Deleted() { return m_deleted; }
  void Deleted(bool deleted) { m_deleted = deleted; }
  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  hstring m_id;
  hstring m_name;
  hstring m_transfer_account_id;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Payee : PayeeT<Payee, implementation::Payee> {};
} // namespace winrt::YnabApi::Models::factory_implementation
