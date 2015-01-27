// RUN: %clang_cc1 -O3 -ffreestanding -triple x86_64-apple-macosx10.8.0 -target-feature +avx2 -emit-llvm %s -o - | FileCheck %s

#include <immintrin.h>

// Byte-shifts look reversed due to xmm register layout
__m256i test_mm256_slli_si256(__m256 a) {
  // CHECK-LABEL: @test_mm256_slli_si256
  // CHECK: shufflevector <16 x i8> <{{.*}}, i8 0, i8 0, i8 0, i8 0, i8 0>, <16 x i8> {{.*}}, <16 x i32> <i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26>
  return _mm256_slli_si256(a, 5);
}

//__m256 test_mm256_slli_si256_0(__m256 a) {
//  // CHECK-LABEL: @test_mm256_slli_si256_0
//  // CHECK-NOT: shufflevector
//  return _mm256_slli_si256(a, 0);
//}
//
//__m256 test_mm256_slli_si256_16(__m256 a) {
//  // CHECK-LABEL: @test_mm256_slli_si256_16
//  // CHECK-NOT: shufflevector
//  return _mm256_slli_si256(a, 16);
//}
//
//__m256 test_mm256_srli_si256(__m256 a) {
//  // CHECK-LABEL: @test_mm256_srli_si256
//  // CHECK: shufflevector <16 x i8> {{.*}}, <16 x i8> <i8 0, i8 0, i8 0, i8 0, i8 0, {{.*}}>, <16 x i32> <i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20>
//  return _mm256_srli_si256(a, 5);
//}
//
//__m256 test_mm256_srli_si256_0(__m256 a) {
//  // CHECK-LABEL: @test_mm256_srli_si256_0
//  // CHECK-NOT: shufflevector
//  return _mm256_srli_si256(a, 0);
//}
//
//__m256 test_mm256_srli_si256_16(__m256 a) {
//  // CHECK-LABEL: @test_mm256_srli_si256_16
//  // CHECK-NOT: shufflevector
//  return _mm256_srli_si256(a, 16);
//}
//
