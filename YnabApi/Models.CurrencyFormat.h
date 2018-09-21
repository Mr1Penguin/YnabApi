//
// Declaration of the CurrencyFormat class.
//

#pragma once

#include "Models.CurrencyFormat.g.h"

namespace winrt::YnabApi::Models::implementation {
struct CurrencyFormat : CurrencyFormatT<CurrencyFormat>, ::apicc::BaseModel {
  CurrencyFormat() = default;
  winrt::hstring IsoCode() const noexcept { return m_iso_code; }
  void IsoCode(const winrt::hstring &iso_code) noexcept { m_iso_code = iso_code; }
  winrt::hstring ExampleFormat() const noexcept { return m_example_format; }
  void ExampleFormat(const winrt::hstring &example_format) noexcept { m_example_format = example_format; }
  int32_t DecimalDigits() const noexcept { return m_decimal_digits; }
  void DecimalDigits(int32_t decimal_digits) noexcept { m_decimal_digits = decimal_digits; }
  winrt::hstring DecimalSeparator() const noexcept { return m_decimal_separator; }
  void DecimalSeparator(const winrt::hstring &decimal_separator) noexcept { m_decimal_separator = decimal_separator; }
  bool SymbolFirst() const noexcept { return m_symbol_first; }
  void SymbolFirst(bool symbol_first) noexcept { m_symbol_first = symbol_first; }
  winrt::hstring GroupSeparator() const noexcept { return m_group_separator; }
  void GroupSeparator(const winrt::hstring &group_separator) noexcept { m_group_separator = group_separator; }
  winrt::hstring CurrencySymbol() const noexcept { return m_currency_symbol; }
  void CurrencySymbol(const winrt::hstring &currency_symbol) noexcept { m_currency_symbol = currency_symbol; }
  bool DisplaySymbol() const noexcept { return m_display_simbol; }
  void DisplaySymbol(bool display_symbol) noexcept { m_display_simbol = display_symbol; }
  virtual void Serialize(rwriter &writer) override;
  virtual void Deserialize(rvalue const &document) override;

private:
  winrt::hstring m_iso_code;
  winrt::hstring m_example_format;
  int32_t m_decimal_digits;
  winrt::hstring m_decimal_separator;
  bool m_symbol_first;
  winrt::hstring m_group_separator;
  winrt::hstring m_currency_symbol;
  bool m_display_simbol;
};
} // namespace winrt::YnabApi::Models::implementation

namespace winrt::YnabApi::Models::factory_implementation {
struct CurrencyFormat : CurrencyFormatT<CurrencyFormat, implementation::CurrencyFormat> {};
} // namespace winrt::YnabApi::Models::factory_implementation
