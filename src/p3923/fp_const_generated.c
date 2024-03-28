#include "precomputed.h"

// Field constants
fp minus_one_half =
  { 0xffffffffffffffffULL, 0xa9ac02fd374f2458ULL, 0x5b988d31b19f81edULL, 0x1a43abf56fae4a98ULL };
fp minus_one_third =
  { 0xaaaaaaaaaaaaaaaaULL, 0x1bc801fe24df6d90ULL, 0x3d105e2121150149ULL, 0x118272a39fc98710ULL };
// fp2_non_residue()^((p-1)/2)
fp2 non_residue_p_minus_1_halves = {
  { 0x62dcb88ab26d67e3ULL, 0x6753105cabc3ec0cULL, 0xd07b8b51cea919d1ULL, 0x2959d0db12ca7133ULL },
  { 0xfb93e6ad5f08c1dcULL, 0xec51d2f53b0d54e2ULL, 0x96ce278d69839f4eULL, 0x268e6f171fa5e834ULL }
};
