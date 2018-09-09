#include "pch.h"
#include "Models.DateFormat.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation
{
	void DateFormat::Deserialize(const rvalue & document) {
		m_format = Read<winrt::hstring>(document, L"format");
	}

	void DateFormat::Serialize(rwriter & writer) {
		Write(m_format, writer, L"format");
	}
}
