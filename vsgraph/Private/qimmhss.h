#pragma once

#include "intrin.h"

double hss(const double& x);
float hss(const float& x);

extern __m512d _mm512_hss_pd(__m512d x);
extern __m256d _mm256_hss_pd(__m256d x);
extern __m128d _mm_hss_pd(__m128d x);
extern __m512 _mm512_hss_ps(__m512 x);
extern __m256 _mm256_hss_ps(__m256 x);
extern __m128 _mm_hss_ps(__m128 x);

