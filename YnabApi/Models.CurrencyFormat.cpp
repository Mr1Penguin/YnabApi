#include "pch.h"
#include "Models.CurrencyFormat.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation
{
	void CurrencyFormat::Serialize(rwriter & writer) {
		Write(m_iso_code, writer, L"iso_code");
		Write(m_example_format, writer, L"example_format");
		Write(m_decimal_digits, writer, L"decimal_digits");
		Write(m_decimal_separator, writer, L"decimal_separator");
		Write(m_symbol_first, writer, L"symbol_first");
		Write(m_group_separator, writer, L"group_separator");
		Write(m_currency_symbol, writer, L"currency_symbol");
		Write(m_display_simbol, writer, L"display_symbol");
	}

	void CurrencyFormat::Deserialize(rvalue const & document) {
		m_iso_code = Read<winrt::hstring>(document, L"iso_code");
		m_example_format = Read<winrt::hstring>(document, L"example_format");
		m_decimal_digits = Read<int32_t>(document, L"decimal_digits");
		m_decimal_separator = Read<winrt::hstring>(document, L"decimal_separator");
		m_symbol_first = Read<bool>(document, L"symbol_first");
		m_group_separator = Read<winrt::hstring>(document, L"group_separator");
		m_currency_symbol = Read<winrt::hstring>(document, L"currency_symbol");
		m_display_simbol = Read<bool>(document, L"display_symbol");
	}
}
