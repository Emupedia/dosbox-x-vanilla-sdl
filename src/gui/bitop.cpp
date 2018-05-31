
#include <assert.h>

#include "bitop.h"

namespace bitop {

void self_test(void) {
    // DEBUG
    static_assert(bitcount2masklsb<0u>() == 0u);
    static_assert(bitcount2masklsb<1u>() == 1u, "whoops");
    static_assert(bitcount2masklsb<2u>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,1u>() == 6u, "whoops");
    static_assert(bitcount2masklsb<2u,uint8_t>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,0u,uint8_t>() == 3u, "whoops");
    static_assert(bitcount2masklsb<2u,1u,uint8_t>() == 6u, "whoops");
    static_assert(bitcount2masklsb<type_bits<>()>() == allones(), "whoops");
    assert(allones<uint32_t>() == (uint32_t)0xFFFFFFFFUL);
    assert(allzero<uint32_t>() == (uint32_t)0);
    assert(allones<uint64_t>() == (uint64_t)0xFFFFFFFFFFFFFFFFULL);
    assert(allzero<uint64_t>() == (uint64_t)0);
    assert((~allones<uint32_t>()) == allzero<uint32_t>());
    assert((~allzero<uint32_t>()) == allones<uint32_t>());
    assert(type_bits<uint64_t>() == 64u);
    assert(type_bits<uint32_t>() == 32u);
    assert(type_bits<uint16_t>() == 16u);
    assert(type_bits<uint8_t>() == 8u);
    assert(bit2mask<unsigned int>(0u) == 1u);
    assert(bit2mask<unsigned int>(8u) == 256u);
    assert((bit2mask<8u,unsigned int>() == 256u));
    assert((bit2mask<9u,unsigned int>() == 512u));
    assert((bit2mask<33u,uint64_t>() == (1ull << 33ull)));
    assert(bitlength(0u) == 0u);
    assert(bitlength(1u) == 1u);
    assert(bitlength(2u) == 2u);
    assert(bitlength(3u) == 2u);
    assert(bitlength(4u) == 3u);
    assert(bitlength(7u) == 3u);
    assert(bitlength(8u) == 4u);
    assert(bitlength(~0u) == type_bits<unsigned int>());
    assert(type_msb_mask<uint8_t>() == 0x80u);
    assert(type_msb_mask<uint16_t>() == 0x8000u);
    assert(type_msb_mask<uint32_t>() == 0x80000000UL);
    assert(type_msb_mask<uint64_t>() == 0x8000000000000000ULL);
}

}

