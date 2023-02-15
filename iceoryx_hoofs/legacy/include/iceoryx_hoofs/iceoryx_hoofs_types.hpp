// Copyright (c) 2023 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef IOX_HOOFS_ICEORYX_HOOFS_TYPES_HPP
#define IOX_HOOFS_ICEORYX_HOOFS_TYPES_HPP

#include "iox/iceoryx_hoofs_types.hpp"

namespace iox
{
/// @todo iox-#1593 Deprecate include
/// [[deprecated("Deprecated in 3.0, removed in 4.0, please include 'iox/iceoryx_hoofs_types.hpp' instead")]]
namespace cxx
{
/// @deprecated use `iox::byte_t` instead of `iox::cxx::byte_t`
using iox::byte_t;
} // namespace cxx
namespace log
{
/// @deprecated use `iox::log::LogLevel` instead of `iox::cxx::log::LogLevel`
using iox::log::LogLevel;
} // namespace log
} // namespace iox

#endif // IOX_HOOFS_ICEORYX_HOOFS_TYPES_HPP
