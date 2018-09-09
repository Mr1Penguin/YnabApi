#include "pch.h"
#include "Models.BudgetDetail.h"
#include "Models.DateFormat.h"

using namespace winrt;

namespace winrt::YnabApi::Models::implementation
{
	void BudgetDetail::Deserialize(const rvalue & document) {
		m_id = Read<winrt::hstring>(document, L"id");
		m_name = Read<winrt::hstring>(document, L"name");
		m_last_modified_on = Read<apicc::NullableString>(document, L"last_modified_on");
		m_date_format = Read<implementation::DateFormat>(document, L"date_format");
	}

	void BudgetDetail::Serialize(rwriter & writer) {
		Write(m_id, writer, L"id");
		Write(m_name, writer, L"name");
		Write(m_last_modified_on, writer, L"last_modified_on");
		Write(static_cast<::apicc::BaseModel *>(get_self<implementation::DateFormat>(m_date_format)), writer,
			  L"date_format");
	}
}
