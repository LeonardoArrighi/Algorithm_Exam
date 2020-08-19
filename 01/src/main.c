#include "matrix.h"
#include "strassen.h"
#include "test.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
  size_t n = 1 << 12;

  float** A = allocate_random_matrix(n, n);
  float** B = allocate_random_matrix(n, n);
  float** C = allocate_matrix(n, n);
  float** D = allocate_matrix(n, n);
  float** E = allocate_matrix(n, n);
  
  printf("n\tNaive Alg.\tStrassen's Alg.\tStrasOpt's Alg.\tSame result\n");
  for (size_t j = 2; j <= n; j *= 2)
  {
    
    printf("%ld\t", j);
    fflush(stdout);
    printf("%lf\t", test_gen(naive_matrix_multiplication_gen, C, A, B, j - 1, j, j + 1));
    fflush(stdout);
    printf("%lf\t", test_gen(strassen_matrix_multiplication_gen, D, A, B, j - 1, j, j + 1));
    fflush(stdout);
    printf("%lf\t", test_gen(strassen_matrix_multiplication_gen_opt, E, A, B, j - 1, j, j + 1));
    fflush(stdout);
    
    
    printf("%d\n", same_matrix((float const* const* const)C, (float const* const* const)E, j, j));
  }
    deallocate_matrix(A, n);
    deallocate_matrix(B, n);
    deallocate_matrix(C, n);
    deallocate_matrix(D, n);
    deallocate_matrix(E, n);

    return 0;
}