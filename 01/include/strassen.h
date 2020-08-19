#ifndef __STRASSEN__
#include <stdio.h>

void strassen_matrix_multiplication(float** C, float const* const* const A, float const* const* const B, size_t n);

void strassen_matrix_multiplication_gen(float** C, float const* const* const A, float const* const* const B,
                                        size_t A_row, size_t A_col, size_t B_col);

void strassen_matrix_multiplication_gen_opt(float** C, float const* const* const A, float const* const* const B,
                                        size_t A_row, size_t A_col, size_t B_col);

#endif //__STRASSEN__
