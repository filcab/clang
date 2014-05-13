#include <x86intrin.h>

__m128i swizzleexample1()
{
  const int x = 3, y = 2, z = 1, w = 0;
  return _mm_shuffle_epi8( _mm_set_epi32( x, y, z, w ), _mm_set_epi8( 15, 14, 13, 12, 11, 10, 9, 8,
7, 6, 5, 4, 3, 2, 1, 0 ) );
}

__m128 shuf_xyzd( __m128 xyzw, __m128 abcd )
{
      return _mm_blendv_ps( xyzw, abcd, _mm_castsi128_ps( _mm_setr_epi32(0,0,0,-1) ) );
}
