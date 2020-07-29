// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
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
#ifndef IOX_POSH_POPO_BUILDING_BLOCKS_CHUNK_RECEIVER_DATA_HPP
#define IOX_POSH_POPO_BUILDING_BLOCKS_CHUNK_RECEIVER_DATA_HPP

#include "iceoryx_posh/iceoryx_posh_types.hpp"
#include "iceoryx_posh/internal/mepoo/shared_chunk.hpp"
#include "iceoryx_posh/internal/popo/building_blocks/chunk_queue_data.hpp"
#include "iceoryx_posh/internal/popo/used_chunk_list.hpp"
#include "iceoryx_posh/mepoo/memory_info.hpp"
#include "iceoryx_utils/cxx/variant_queue.hpp"

namespace iox
{
namespace popo
{
template <typename ChunkQueueProperties>
struct ChunkReceiverData : public ChunkQueueData<ChunkQueueProperties>
{
    explicit ChunkReceiverData(const cxx::VariantQueueTypes queueType,
                               const mepoo::MemoryInfo& memoryInfo = mepoo::MemoryInfo()) noexcept;

    mepoo::MemoryInfo m_memoryInfo;

    static constexpr uint32_t MAX_CHUNKS_IN_USE = ChunkQueueProperties::m_maxChunksPerReceiver;
    UsedChunkList<MAX_CHUNKS_IN_USE> m_chunksInUse;
};

} // namespace popo
} // namespace iox

#include "iceoryx_posh/internal/popo/building_blocks/chunk_receiver_data.inl"

#endif // IOX_POSH_POPO_BUILDING_BLOCKS_CHUNK_RECEIVER_DATA_HPP
