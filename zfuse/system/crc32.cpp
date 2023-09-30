#include "crc32.h"

zfuse::Crc32 zfuse::ComputeCrc32(const void* const buffer, size_t size) noexcept
{
    auto bytes = static_cast<const uint8_t*>(buffer);

    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < size; ++i)
    {
        crc = kCrc32Table[(crc ^ bytes[i]) & 0xFF] ^ (crc >> 8);
    }
    return Crc32(crc ^ 0xFFFFFFFF);
}
