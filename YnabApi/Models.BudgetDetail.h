//
// Declaration of the BudgetDetail class.
//

#pragma once

#include "Models.BudgetDetail.g.h"

namespace mp = winrt::YnabApi::Models;

namespace winrt::YnabApi::Models::implementation
{
    struct BudgetDetail : BudgetDetailT<BudgetDetail>, ::apicc::BaseModel
    {
        BudgetDetail() = default;
		hstring Id() { return m_id; }
		void Id(const hstring & id) { m_id = id; }
		hstring Name() { return m_name; }
		void Name(const hstring & name) { m_name = name; }
		apicc::NullableString LastModifiedOn() { return m_last_modified_on; }
		void LastModifiedOn(const apicc::NullableString & lastModifiedOn) { m_last_modified_on = lastModifiedOn; }
		mp::DateFormat DateFormat() { return m_date_format; }
		void DateFormat(mp::DateFormat date_format) { m_date_format = date_format; }
		virtual void Serialize(rwriter & writer) override;
		virtual void Deserialize(rvalue const & document) override;
	private:
		hstring m_id;
		hstring m_name;
		apicc::NullableString m_last_modified_on;
		mp::DateFormat m_date_format;
    };
}

namespace winrt::YnabApi::Models::factory_implementation
{
    struct BudgetDetail : BudgetDetailT<BudgetDetail, Models::implementation::BudgetDetail>
    {
    };
}
