#pragma once

#include "winrt/base.h"

namespace apicc {
enum class TokenPassingTypes { Header, Parameter };

extern winrt::hstring Token;
extern winrt::hstring TokenParamName;
extern TokenPassingTypes TokenPassingType;
extern winrt::hstring BaseUri;
} // namespace apicc
