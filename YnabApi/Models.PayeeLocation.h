//
// Declaration of the PayeeLocation class.
//

#pragma once

#include "Models.PayeeLocation.g.h"

namespace winrt::YnabApi::Models::implementation {
struct PayeeLocation : PayeeLocationT<PayeeLocation>, ::apicc::BaseModel {
  PayeeLocation() = default;

  winrt::hstring Id() { return m_id; }
  void Id(const winrt::hstring &id) { m_id = id; }
  winrt::hstring PayeeId() { return m_payee_id; }
  void PayeeId(const winrt::hstring &payee_id) { m_payee_id = payee_id; }
  winrt::hstring Latitude() { return m_latitude; }
  void Latitude(const winrt::hstring &latitude) { m_latitude = latitude; }
  winrt::hstring Longitude() { return m_longitude; }
  void Longitude(const winrt::hstring &longitude) { m_longitude = longitude; }
  bool Deleted() { return m_deleted; }
  void Deleted(bool deleted) { m_deleted = deleted; }

  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_id;
  winrt::hstring m_payee_id;
  winrt::hstring m_latitude;
  winrt::hstring m_longitude;
  bool m_deleted;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct PayeeLocation : PayeeLocationT<PayeeLocation, implementation::PayeeLocation> {};
} // namespace winrt::YnabApi::Models::factory_implementation
