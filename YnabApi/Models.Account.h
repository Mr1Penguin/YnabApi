//
// Declaration of the Models class.
//

#pragma once

#include "Models.Account.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Account : AccountT<Account>, ::apicc::BaseModel {
  Account() = default;
  hstring Id() const noexcept { return m_id; }
  void Id(const hstring &id) noexcept { m_id = id; }
  hstring Name() const noexcept { return m_name; }
  void Name(const hstring &name) noexcept { m_name = name; }
  AccountType Type() const noexcept { return m_type; }
  void Type(AccountType type) noexcept { m_type = type; }
  bool OnBudget() const noexcept { return m_on_budget; }
  void OnBudget(bool on_budget) noexcept { m_on_budget = on_budget; }
  bool Closed() const noexcept { return m_closed; }
  void Closed(bool closed) noexcept { m_closed = closed; }
  hstring Note() { return m_note; }
  void Note(const hstring &note) { m_note = note; }
  int64_t Balance() { return m_balance; }
  void Balance(int64_t balance) { m_balance = balance; }
  int64_t ClearedBalance() { return m_cleared_balance; }
  void ClearedBalance(int64_t cleared_balance) { m_cleared_balance = cleared_balance; }
  int64_t UnclearedBalance() { return m_uncleared_balance; }
  void UnclearedBalance(int64_t uncleared_balance) { m_uncleared_balance = uncleared_balance; }
  hstring TransferPayeeId() { return m_transfer_payee_id; }
  void TransferPayeeId(const hstring &transfer_payee_id) { m_transfer_payee_id = transfer_payee_id; }
  bool Deleted() { return m_deleted; }
  void Deleted(bool deleted) { m_deleted = deleted; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  hstring m_id;
  hstring m_name;
  AccountType m_type;
  bool m_on_budget;
  bool m_closed;
  hstring m_note;
  int64_t m_balance;
  int64_t m_cleared_balance;
  int64_t m_uncleared_balance;
  hstring m_transfer_payee_id;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Account : AccountT<Account, implementation::Account> {};
} // namespace winrt::YnabApi::Models::factory_implementation
