// Copyright (c) 2021 - 2022 by Apex.AI Inc. All rights reserved.
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
#ifndef IOX_HOOFS_CXX_STACK_INL
#define IOX_HOOFS_CXX_STACK_INL

#include "iceoryx_hoofs/cxx/stack.hpp"

namespace iox
{
namespace cxx
{
template <typename T, uint64_t Capacity>
inline stack<T, Capacity>::~stack() noexcept
{
    for (uint64_t i = 0; i < m_size; i++)
    {
        // replace cast with private method "getUnchecked" and reuse in c'tors etc.
        reinterpret_cast<T*>(&m_data[i])->~T();
    }
}

template <typename T, uint64_t Capacity>
inline cxx::optional<T> stack<T, Capacity>::pop() noexcept
{
    if (m_size == 0U)
    {
        return cxx::nullopt;
    }

    // AXIVION Next Construct AutosarC++19_03-A5.2.4 : low level memory management with access to the topmost element on
    // the untyped buffer; reinterpret_cast is safe since the size and the alignment of each array element is guaranteed
    // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
    return *reinterpret_cast<T*>(&m_data[--m_size]);
}

template <typename T, uint64_t Capacity>
template <typename... Targs>
inline bool stack<T, Capacity>::push(Targs&&... args) noexcept
{
    if (m_size >= Capacity)
    {
        return false;
    }

    new (&m_data[m_size++]) T(std::forward<Targs>(args)...);
    return true;
}

template <typename T, uint64_t Capacity>
inline uint64_t stack<T, Capacity>::size() const noexcept
{
    return m_size;
}

template <typename T, uint64_t Capacity>
inline constexpr uint64_t stack<T, Capacity>::capacity() noexcept
{
    return Capacity;
}


} // namespace cxx
} // namespace iox

#endif // IOX_HOOFS_CXX_STACK_INL
