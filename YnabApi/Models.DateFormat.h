//
// Declaration of the DateFormat class.
//

#pragma once

#include "Models.DateFormat.g.h"

namespace winrt::YnabApi::Models::implementation
{
	struct DateFormat : DateFormatT<DateFormat>, ::apicc::BaseModel
	{
		DateFormat() = default;
		hstring Format() const noexcept { return m_format; }
		void Format(const hstring & format) noexcept { m_format = format; }
		virtual void Serialize(rwriter & writer) override;
		virtual void Deserialize(const rvalue & document) override;
	private:
		hstring m_format;
    };
}

namespace winrt::YnabApi::Models::factory_implementation
{
    struct DateFormat : DateFormatT<DateFormat, Models::implementation::DateFormat>
    {
    };
}
