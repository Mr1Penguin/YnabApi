//
// Declaration of the Transaction class.
//

#pragma once

#include "Models.Transaction.g.h"

namespace winrt::YnabApi::Models::implementation {
struct Transaction : TransactionT<Transaction>, ::apicc::BaseModel {
  Transaction() = default;
  winrt::hstring Id() const noexcept { return m_id; }
  void Id(winrt::hstring const &id) noexcept { m_id = id; }
  winrt::hstring Date() const noexcept { return m_date; }
  void Date(winrt::hstring const &date) noexcept { m_date = date; }
  int64_t Amount() const noexcept { return m_amount; }
  void Amount(int64_t amount) noexcept { m_amount = amount; }
  winrt::hstring Memo() const noexcept { return m_memo; }
  void Memo(winrt::hstring const &memo) noexcept { m_memo = memo; }
  Models::Cleared Cleared() const noexcept { return m_cleared; }
  void Cleared(Models::Cleared cleared) noexcept { m_cleared = cleared; }
  bool Approved() const noexcept { return m_approved; }
  void Approved(bool approved) noexcept { m_approved = approved; }
  Models::FlagColor FlagColor() const noexcept { return m_flag_color; }
  void FlagColor(Models::FlagColor flag_color) noexcept { m_flag_color = flag_color; }
  winrt::hstring AccountId() const noexcept { return m_account_id; }
  void AccountId(winrt::hstring const &account_id) noexcept { m_account_id = account_id; }
  winrt::hstring PayeeId() const noexcept { return m_payee_id; }
  void PayeeId(winrt::hstring const &payee_id) noexcept { m_payee_id = payee_id; }
  winrt::hstring CategoryId() const noexcept { return m_category_id; }
  void CategoryId(winrt::hstring const &category_id) noexcept { m_category_id = category_id; }
  winrt::hstring TransferAccountId() const noexcept { return m_transfer_account_id; }
  void TransferAccountId(winrt::hstring const &transfer_account_id) noexcept {
    m_transfer_account_id = transfer_account_id;
  }
  winrt::hstring TransferTransactionId() const noexcept { return m_transfer_transaction_id; }
  void TransferTransactionId(winrt::hstring const &transfer_transaction_id) noexcept {
    m_transfer_transaction_id = transfer_transaction_id;
  }
  winrt::hstring ImportId() const noexcept { return m_import_id; }
  void ImportId(winrt::hstring const &import_id) noexcept { m_import_id = import_id; }
  bool Deleted() const noexcept { return m_deleted; }
  void Deleted(bool deleted) noexcept { m_deleted = deleted; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_id;
  winrt::hstring m_date;
  int64_t m_amount;
  winrt::hstring m_memo;
  Models::Cleared m_cleared;
  bool m_approved;
  Models::FlagColor m_flag_color;
  winrt::hstring m_account_id;
  winrt::hstring m_payee_id;
  winrt::hstring m_category_id;
  winrt::hstring m_transfer_account_id;
  winrt::hstring m_transfer_transaction_id;
  winrt::hstring m_import_id;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct Transaction : TransactionT<Transaction, implementation::Transaction> {};
} // namespace winrt::YnabApi::Models::factory_implementation
