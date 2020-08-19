#include "matrix.h"

#include <stdio.h>

/*
 * this functions perform the element-wise
 * subtraction of B from A and put the resulting
 * sub-matrix in C. The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void sub_matrix_blocks(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                       const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                       const size_t B_f_col, const size_t n)
{
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            C[y + C_f_row][x + C_f_col] = A[y + A_f_row][x + A_f_col] - B[y + B_f_row][x + B_f_col];
        }
    }
}

void sub_matrix_blocks_gen(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                           const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                           const size_t B_f_col, const size_t Rows, const size_t Cols)
{
    for (size_t y = 0; y < Rows; y++)
    {
        for (size_t x = 0; x < Cols; x++)
        {
            C[y + C_f_row][x + C_f_col] = A[y + A_f_row][x + A_f_col] - B[y + B_f_row][x + B_f_col];
        }
    }
}

/*
 * this functions perform the element-wise
 * sum of A and B and put the resulting
 * sub-matrix in C. The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void sum_matrix_blocks(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                       const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                       const size_t B_f_col, const size_t n)
{
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            C[y + C_f_row][x + C_f_col] = A[y + A_f_row][x + A_f_col] + B[y + B_f_row][x + B_f_col];
        }
    }
}

void sum_matrix_blocks_gen(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                           const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                           const size_t B_f_col, const size_t Rows, const size_t Cols)
{
    for (size_t y = 0; y < Rows; y++)
    {
        for (size_t x = 0; x < Cols; x++)
        {
            C[y + C_f_row][x + C_f_col] = A[y + A_f_row][x + A_f_col] + B[y + B_f_row][x + B_f_col];
        }
    }
}

/*
 * this functions implement the naive algorithm
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void naive_aux(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
               const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
               const size_t B_f_col, const size_t n)
{
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            float value = 0.0;
            for (size_t z = 0; z < n; z++)
            {
                value += A[y + A_f_row][z + A_f_col] * B[z + B_f_row][x + B_f_col];
            }

            C[y + C_f_row][x + C_f_col] = value;
        }
    }
}

void naive_aux_gen(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                   const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                   const size_t B_f_col, const size_t A_row, const size_t A_col, const size_t B_col)
{
    for (size_t y = 0; y < A_row; y++)
    {
        for (size_t x = 0; x < B_col; x++)
        {
            float value = 0.0;
            for (size_t z = 0; z < A_col; z++)
            {
                value += A[y + A_f_row][z + A_f_col] * B[z + B_f_row][x + B_f_col];
            }

            C[y + C_f_row][x + C_f_col] = value;
        }
    }
}

/*
 * This function implements the Strassen's algorithm
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void strassen_aux(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                  const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                  const size_t B_f_col, const size_t n)
{
    if (n <= (1 << 6))
    {
        naive_aux(C, A, B, C_f_row, C_f_col, A_f_row, A_f_col, B_f_row, B_f_col, n);

        return;
    }

    size_t n2 = n / 2;  // This is the size of the blocks

    float*** S = (float***)malloc(sizeof(float**) * 10);
    for (size_t i = 0; i < 10; i++)
    {
        S[i] = allocate_matrix(n2, n2);
    }

    float*** P = (float***)malloc(sizeof(float**) * 7);
    for (size_t i = 0; i < 7; i++)
    {
        P[i] = allocate_matrix(n2, n2);
    }

    // S1 = B12 - B22
    sub_matrix_blocks(S[0], B, B, 0, 0, B_f_row, B_f_col + n2, B_f_row + n2, B_f_col + n2, n2);

    // P1 = A11 x S1
    strassen_aux(P[0], A, (const float* const* const)S[0], 0, 0, A_f_row, A_f_col, 0, 0, n2);

    // S2 = A11 + A12
    sum_matrix_blocks(S[1], A, A, 0, 0, A_f_row, A_f_col, A_f_row, A_f_col + n2, n2);


    // P2 = S2 x B22
    strassen_aux(P[1], (const float* const* const)S[1], B, 0, 0, 0, 0, B_f_row + n2, B_f_col + n2, n2);

    // S3 = A21 + A22
    sum_matrix_blocks(S[2], A, A, 0, 0, A_f_row + n2, A_f_col, A_f_row + n2, A_f_col + n2, n2);

    // P3 = S3 x B11
    strassen_aux(P[2], (const float* const* const)S[2], B, 0, 0, 0, 0, B_f_row, B_f_col, n2);

    // S4 = B21 - B11
    sub_matrix_blocks(S[3], B, B, 0, 0, B_f_row + n2, B_f_col, B_f_row, B_f_col, n2);

    // P4 = A22 x S4
    strassen_aux(P[3], A, (const float* const* const)S[3], 0, 0, A_f_row + n2, A_f_col + n2, 0, 0, n2);

    // S5 = A11 + A22
    sum_matrix_blocks(S[4], A, A, 0, 0, A_f_row, A_f_col, A_f_row + n2, A_f_col + n2, n2);

    // S6 = B11 + B22
    sum_matrix_blocks(S[5], B, B, 0, 0, B_f_row, B_f_col, B_f_row + n2, B_f_col + n2, n2);

    // P5 = S5 x S6
    strassen_aux(P[4], (const float* const* const)S[4], (const float* const* const)S[5], 0, 0, 0, 0, 0, 0, n2);

    // S7 = A12 - A22
    sub_matrix_blocks(S[6], A, A, 0, 0, A_f_row, A_f_col + n2, A_f_row + n2, A_f_col + n2, n2);

    // S8 = B21 + B22
    sum_matrix_blocks(S[7], B, B, 0, 0, B_f_row + n2, B_f_col, B_f_row + n2, B_f_col + n2, n2);

    // P6 = S7 x S8
    strassen_aux(P[5], (const float* const* const)S[6], (const float* const* const)S[7], 0, 0, 0, 0, 0, 0, n2);

    // S9 = A11 - A21
    sub_matrix_blocks(S[8], A, A, 0, 0, A_f_row, A_f_col, A_f_row + n2, A_f_col, n2);

    // S10 = B11 + B12
    sum_matrix_blocks(S[9], B, B, 0, 0, B_f_row, B_f_col, B_f_row, B_f_col + n2, n2);

    // P7 = S9 x S10
    strassen_aux(P[6], (const float* const* const)S[8], (const float* const* const)S[9], 0, 0, 0, 0, 0, 0, n2);

    // C11 = P5 + P4 - P2 + P6
    sum_matrix_blocks(C, (const float* const* const)P[4], (const float* const* const)P[3], C_f_row, C_f_col, 0, 0, 0, 0,
                      n2);
    sub_matrix_blocks(C, (const float* const* const)C, (const float* const* const)P[1], C_f_row, C_f_col, C_f_row,
                      C_f_col, 0, 0, n2);
    sum_matrix_blocks(C, (const float* const* const)C, (const float* const* const)P[5], C_f_row, C_f_col, C_f_row,
                      C_f_col, 0, 0, n2);

    // C12 = P1 + P2
    sum_matrix_blocks(C, (const float* const* const)P[0], (const float* const* const)P[1], C_f_row, C_f_col + n2, 0, 0,
                      0, 0, n2);

    // C21 = P3 + P4
    sum_matrix_blocks(C, (const float* const* const)P[2], (const float* const* const)P[3], C_f_row + n2, C_f_col, 0, 0,
                      0, 0, n2);

    // C22 = P5 + P1 - P3 - P7
    sum_matrix_blocks(C, (const float* const* const)P[4], (const float* const* const)P[0], C_f_row + n2, C_f_col + n2,
                      0, 0, 0, 0, n2);
    sub_matrix_blocks(C, (const float* const* const)C, (const float* const* const)P[2], C_f_row + n2, C_f_col + n2,
                      C_f_row + n2, C_f_col + n2, 0, 0, n2);
    sub_matrix_blocks(C, (const float* const* const)C, (const float* const* const)P[6], C_f_row + n2, C_f_col + n2,
                      C_f_row + n2, C_f_col + n2, 0, 0, n2);

    for (size_t i = 0; i < 10; i++)
    {
        deallocate_matrix(S[i], n2);
    }
    free(S);

    for (size_t i = 0; i < 7; i++)
    {
        deallocate_matrix(P[i], n2);
    }
    free(P);
}



// auxiliary function
size_t getmax (size_t x, size_t y, size_t z)
{
    if(x < y) x = y;
    if(x < z) x = z;
    return x;
}

/*
 *Auxiliary function, useful to set blocks of a matrix to 0
 */
void zero(float** C, const size_t row, const size_t col, 
     const size_t e_row, const size_t e_col)
{
    for (size_t i = row; i < e_row; i++)
    {
        for (size_t j = col; j < e_col; j++)
        {
            C[i][j] = 0;
        }
    }
    return;
}


/*
 * This function implements the Strassen's algorithm, using peeling technique
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void strassen_aux_gen(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                      const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                      const size_t B_f_col, const size_t A_row, const size_t A_col, const size_t B_col)
{
    if (((A_row <= (1 << 6)) && (A_col <= (1 << 6)) && (B_col <= (1 << 6))) || (A_row == 1) || (A_col == 1) || (B_col == 1))
    {
        naive_aux_gen(C, A, B, C_f_row, C_f_col, A_f_row, A_f_col, B_f_row, B_f_col, A_row, A_col, B_col);
        return;
    }

    // we will store all the operations in blocks of C matrix
    zero(C, C_f_row, C_f_col, C_f_row + A_row, C_f_col + B_col);
    

    // recall: all dimensions must be even to compute Strassen_aux_gen
    // peeling options
    size_t resto_A_row = A_row % 2;
    size_t resto_A_col = A_col % 2;
    size_t resto_B_col = B_col % 2;
    
    // peeling
    // obs. the comments are about the results, but all the pieces are obtained by sums
    if ((resto_A_row != 0) || (resto_A_col != 0) || (resto_B_col != 0))
    {
        // C11 = A11 x B11 peeled
        strassen_aux_gen(C, A, B, C_f_row, C_f_col, A_f_row, A_f_col, B_f_row, B_f_col,
                        A_row - resto_A_row, A_col - resto_A_col, B_col - resto_B_col);
        
        // cases
        // A_row odd
        if (resto_A_row != 0)
        {   
            // C11 = A11 x B11
            // c21 = a21 x B11
            strassen_aux_gen(C, A, B, C_f_row + A_row - resto_A_row, C_f_col,
                             A_f_row + A_row - resto_A_row, A_f_col, B_f_row, B_f_col,
                             1, A_col - resto_A_col, B_col - resto_B_col);
            
        }
        if (resto_A_row != 0 && resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c21 = a21 x B11 + a22 x b21
            float** to_delete = allocate_matrix(1, B_col - resto_B_col);
            strassen_aux_gen(to_delete, A, B, 0, 0, 
                             A_f_row + A_row - resto_A_row, A_f_col + A_col - resto_A_col,
                             B_f_row + A_col - resto_A_col, B_f_col,
                             1, 1, B_col - resto_B_col);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row + A_row - resto_A_row, C_f_col,
                                  C_f_row + A_row - resto_A_row, C_f_col,
                                  0, 0, 1, B_col - resto_B_col);
            deallocate_matrix(to_delete, 1);
        }
        if (resto_A_row != 0 && resto_B_col != 0)
        {
            // C11 = A11 x B11
            // c21 = a21 x B11 + a22 x b21
            // c12 = A11 x b12 + a12 x b22 
            // c22 = a21 x b12
            strassen_aux_gen(C, A, B, C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                             A_f_row + A_row - resto_A_row, A_f_col,
                             B_f_row, B_f_col + B_col - resto_B_col,
                             1, A_col - resto_A_col, 1);
        }
        // A_col odd (and B_row so)
        if (resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            float** to_delete = allocate_matrix(A_row - resto_A_row, B_col - resto_B_col);
            strassen_aux_gen(to_delete, A, B, 0, 0, A_f_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col, 
                             A_row - resto_A_row, 1, B_col - resto_B_col);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row, C_f_col, C_f_row, C_f_col, 
                                  0, 0, A_row - resto_A_row, B_col - resto_B_col);
            deallocate_matrix(to_delete, A_row - resto_A_row);
        }
        // B_col odd
        if (resto_B_col != 0)
        {
            // C11 = A11 x B11
            // c12 = A11 x b12
            strassen_aux_gen(C, A, B, C_f_row, C_f_col + B_col - resto_B_col, 
                             A_f_row, A_f_col, B_f_row, B_f_col + B_col - resto_B_col,
                             A_row - resto_A_row, A_col - resto_A_col, 1);        
        }
        if (resto_B_col != 0 && resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c12 = A11 x b12 + a12 x b22 
            float** to_delete = allocate_matrix(A_row - resto_A_row, 1);
            strassen_aux_gen(to_delete, A, B, 0, 0, A_f_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col + B_col - resto_B_col, 
                             A_row - resto_A_row, 1, 1);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row, C_f_col + B_col - resto_B_col, C_f_row, C_f_col + B_col - resto_B_col, 
                                  0, 0, A_row - resto_A_row, 1);
            deallocate_matrix(to_delete, A_row - resto_A_row);
        }
        // all dims are odd
        if (resto_A_row != 0 && resto_A_col != 0 && resto_B_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c12 = A11 x b12 + a12 x b22
            // c21 = a21 x B11 + a22 x b21
            // c22 = a21 x b12 + a22 x b22
            float** to_delete = allocate_matrix(1, 1);
            strassen_aux_gen(to_delete, A, B, 0, 0, A_f_row + A_row - resto_A_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col + B_col - resto_B_col, 
                             1, 1, 1);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                                  C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                                  0, 0, 1, 1);
            deallocate_matrix(to_delete, 1);
        }
        return;
    }

    // now are all even
    size_t A_row_e = A_row / 2;
    size_t A_col_e = A_col / 2;
    size_t B_col_e = B_col / 2;

    size_t max = getmax(A_row_e, A_col_e, B_col_e);

    float*** S = (float***)malloc(sizeof(float**) * 10);
    for (size_t i = 0; i < 10; i++)
    {
        S[i] = allocate_matrix(max, max);
    }

    float*** P = (float***)malloc(sizeof(float**) * 7);
    for (size_t i = 0; i < 7; i++)
    {
        P[i] = allocate_matrix(max, max);
    }

    // Strassen's Algorithm
    // S1 = B12 - B22
    sub_matrix_blocks_gen(S[0], B, B, 0, 0, B_f_row, B_f_col + B_col_e, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P1 = A11 x S1
    strassen_aux_gen(P[0], A, (const float* const* const)S[0], 0, 0, A_f_row, A_f_col, 0, 0, A_row_e, A_col_e, B_col_e);
    
    // S2 = A11 + A12
    sum_matrix_blocks_gen(S[1], A, A, 0, 0, A_f_row, A_f_col, A_f_row, A_f_col + A_col_e, A_row_e, A_col_e);

    // P2 = S2 x B22
    strassen_aux_gen(P[1], (const float* const* const)S[1], B, 0, 0, 0, 0, B_f_row + A_col_e, B_f_col + B_col_e, A_row_e, A_col_e, B_col_e);

    // S3 = A21 + A22
    sum_matrix_blocks_gen(S[2], A, A, 0, 0, A_f_row + A_row_e, A_f_col, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);
    
    // P3 = S3 x B11
    strassen_aux_gen(P[2], (const float* const* const)S[2], B, 0, 0, 0, 0, B_f_row, B_f_col, A_row_e, A_col_e, B_col_e);

    // S4 = B21 - B11
    sub_matrix_blocks_gen(S[3], B, B, 0, 0, B_f_row + A_col_e, B_f_col, B_f_row, B_f_col, A_col_e, B_col_e);

    // P4 = A22 x S4
    strassen_aux_gen(P[3], A, (const float* const* const)S[3], 0, 0, A_f_row + A_row_e, A_f_col + A_col_e, 0, 0, A_row_e, A_col_e, B_col_e);

    // S5 = A11 + A22
    sum_matrix_blocks_gen(S[4], A, A, 0, 0, A_f_row, A_f_col, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);

    // S6 = B11 + B22
    sum_matrix_blocks_gen(S[5], B, B, 0, 0, B_f_row, B_f_col, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P5 = S5 x S6
    strassen_aux_gen(P[4], (const float* const* const)S[4], (const float* const* const)S[5], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e, B_col_e);
    
    // S7 = A12 - A22
    sub_matrix_blocks_gen(S[6], A, A, 0, 0, A_f_row, A_f_col + A_col_e, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);

    // S8 = B21 + B22
    sum_matrix_blocks_gen(S[7], B, B, 0, 0, B_f_row + A_col_e, B_f_col, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P6 = S7 x S8
    strassen_aux_gen(P[5], (const float* const* const)S[6], (const float* const* const)S[7], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e, B_col_e);
    
    // S9 = A11 - A21
    sub_matrix_blocks_gen(S[8], A, A, 0, 0, A_f_row, A_f_col, A_f_row + A_row_e, A_f_col, A_row_e, A_col_e);

    // S10 = B11 + B12
    sum_matrix_blocks_gen(S[9], B, B, 0, 0, B_f_row, B_f_col, B_f_row, B_f_col + B_col_e, A_col_e, B_col_e);

    // P7 = S9 x S10
    strassen_aux_gen(P[6], (const float* const* const)S[8], (const float* const* const)S[9], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e, B_col_e);
    
    // C11 = P5 + P4 - P2 + P6
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[4], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[3], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[1], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[5], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);

    // C12 = P1 + P2
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[1], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // C21 = P3 + P4
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[2], C_f_row + A_row_e, C_f_col,
                          C_f_row + A_row_e, C_f_col, 0, 0, A_row_e, B_col_e);
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[3], C_f_row + A_row_e, C_f_col,
                          C_f_row + A_row_e, C_f_col, 0, 0, A_row_e, B_col_e);

    // C22 = P5 + P1 - P3 - P7
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[4], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[2], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[6], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    for (size_t i = 0; i < 10; i++)
    {
        deallocate_matrix(S[i], max);
    }
    free(S);

    for (size_t i = 0; i < 7; i++)
    {
        deallocate_matrix(P[i], max);
    }
    free(P);
}

/*
 * This function implements the Strassen's algorithm, using peeling technique
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void strassen_aux_gen_opt(float** C, float const* const* const A, float const* const* const B, const size_t C_f_row,
                      const size_t C_f_col, const size_t A_f_row, const size_t A_f_col, const size_t B_f_row,
                      const size_t B_f_col, const size_t A_row, const size_t A_col, const size_t B_col)
{
    if (((A_row <= (1 << 6)) && (A_col <= (1 << 6)) && (B_col <= (1 << 6))) || (A_row == 1) || (A_col == 1) || (B_col == 1))
    {
        naive_aux_gen(C, A, B, C_f_row, C_f_col, A_f_row, A_f_col, B_f_row, B_f_col, A_row, A_col, B_col);
        return;
    }

    // we will store all the operations in blocks of C matrix
    zero(C, C_f_row, C_f_col, C_f_row + A_row, C_f_col + B_col);
    

    // recall: all dimensions must be even to compute Strassen_aux_gen
    // peeling options
    size_t resto_A_row = A_row % 2;
    size_t resto_A_col = A_col % 2;
    size_t resto_B_col = B_col % 2;
    
    // peeling
    // obs. the comments are about the results, but all the pieces are obtained by sums
    if ((resto_A_row != 0) || (resto_A_col != 0) || (resto_B_col != 0))
    {
        // C11 = A11 x B11 peeled
        strassen_aux_gen_opt(C, A, B, C_f_row, C_f_col, A_f_row, A_f_col, B_f_row, B_f_col,
                        A_row - resto_A_row, A_col - resto_A_col, B_col - resto_B_col);
        
        // cases
        // A_row odd
        if (resto_A_row != 0)
        {   
            // C11 = A11 x B11
            // c21 = a21 x B11
            strassen_aux_gen_opt(C, A, B, C_f_row + A_row - resto_A_row, C_f_col,
                             A_f_row + A_row - resto_A_row, A_f_col, B_f_row, B_f_col,
                             1, A_col - resto_A_col, B_col - resto_B_col);
            
        }
        if (resto_A_row != 0 && resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c21 = a21 x B11 + a22 x b21
            float** to_delete = allocate_matrix(1, B_col - resto_B_col);
            strassen_aux_gen_opt(to_delete, A, B, 0, 0, 
                             A_f_row + A_row - resto_A_row, A_f_col + A_col - resto_A_col,
                             B_f_row + A_col - resto_A_col, B_f_col,
                             1, 1, B_col - resto_B_col);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row + A_row - resto_A_row, C_f_col,
                                  C_f_row + A_row - resto_A_row, C_f_col,
                                  0, 0, 1, B_col - resto_B_col);
            deallocate_matrix(to_delete, 1);
        }
        if (resto_A_row != 0 && resto_B_col != 0)
        {
            // C11 = A11 x B11
            // c21 = a21 x B11 + a22 x b21
            // c12 = A11 x b12 + a12 x b22 
            // c22 = a21 x b12
            strassen_aux_gen_opt(C, A, B, C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                             A_f_row + A_row - resto_A_row, A_f_col,
                             B_f_row, B_f_col + B_col - resto_B_col,
                             1, A_col - resto_A_col, 1);
        }
        // A_col odd (and B_row so)
        if (resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            float** to_delete = allocate_matrix(A_row - resto_A_row, B_col - resto_B_col);
            strassen_aux_gen_opt(to_delete, A, B, 0, 0, A_f_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col, 
                             A_row - resto_A_row, 1, B_col - resto_B_col);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row, C_f_col, C_f_row, C_f_col, 
                                  0, 0, A_row - resto_A_row, B_col - resto_B_col);
            deallocate_matrix(to_delete, A_row - resto_A_row);
        }
        // B_col odd
        if (resto_B_col != 0)
        {
            // C11 = A11 x B11
            // c12 = A11 x b12
            strassen_aux_gen_opt(C, A, B, C_f_row, C_f_col + B_col - resto_B_col, 
                             A_f_row, A_f_col, B_f_row, B_f_col + B_col - resto_B_col,
                             A_row - resto_A_row, A_col - resto_A_col, 1);        
        }
        if (resto_B_col != 0 && resto_A_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c12 = A11 x b12 + a12 x b22 
            float** to_delete = allocate_matrix(A_row - resto_A_row, 1);
            strassen_aux_gen_opt(to_delete, A, B, 0, 0, A_f_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col + B_col - resto_B_col, 
                             A_row - resto_A_row, 1, 1);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row, C_f_col + B_col - resto_B_col, C_f_row, C_f_col + B_col - resto_B_col, 
                                  0, 0, A_row - resto_A_row, 1);
            deallocate_matrix(to_delete, A_row - resto_A_row);
        }
        // all dims are odd
        if (resto_A_row != 0 && resto_A_col != 0 && resto_B_col != 0)
        {
            // C11 = A11 x B11 + a12 x b21
            // c12 = A11 x b12 + a12 x b22
            // c21 = a21 x B11 + a22 x b21
            // c22 = a21 x b12 + a22 x b22
            float** to_delete = allocate_matrix(1, 1);
            strassen_aux_gen_opt(to_delete, A, B, 0, 0, A_f_row + A_row - resto_A_row, A_f_col + A_col - resto_A_col, 
                             B_f_row + A_col - resto_A_col, B_f_col + B_col - resto_B_col, 
                             1, 1, 1);
            sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)to_delete,
                                  C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                                  C_f_row + A_row - resto_A_row, C_f_col + B_col - resto_B_col, 
                                  0, 0, 1, 1);
            deallocate_matrix(to_delete, 1);
        }
        return;
    }

    // now are all even
    size_t A_row_e = A_row / 2;
    size_t A_col_e = A_col / 2;
    size_t B_col_e = B_col / 2;

    size_t max = getmax(A_row_e, A_col_e, B_col_e);
    
    float*** S = (float***)malloc(sizeof(float**) * 2);
    S[0] = allocate_matrix(max, max);
    S[1] = allocate_matrix(max, max);

    float*** P = (float***)malloc(sizeof(float**));
    P[0] = allocate_matrix(max, max);

    // Strassen's Algorithm
     // S1 = B12 - B22
    sub_matrix_blocks_gen(S[0], B, B, 0, 0, B_f_row, B_f_col + B_col_e, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P1 = A11 x S1
    strassen_aux_gen_opt(P[0], A, (const float* const* const)S[0], 0, 0, A_f_row, A_f_col, 0, 0, A_row_e, A_col_e, B_col_e);

    // Store P1 in C12
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col + B_col_e,
                          C_f_row, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // Store P1 in C22
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // S2 = A11 + A12
    sum_matrix_blocks_gen(S[0], A, A, 0, 0, A_f_row, A_f_col, A_f_row, A_f_col + A_col_e, A_row_e, A_col_e);

    // P2 = S2 x B22
    strassen_aux_gen_opt(P[0], (const float* const* const)S[0], B, 0, 0, 0, 0, B_f_row + A_col_e, B_f_col + B_col_e, A_row_e, A_col_e, B_col_e);

    // Store P2 in C11
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);

    // Store P2 in C12
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col + B_col_e,
                          C_f_row, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // S3 = A21 + A22
    sum_matrix_blocks_gen(S[0], A, A, 0, 0, A_f_row + A_row_e, A_f_col, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);

    // P3 = S3 x B11
    strassen_aux_gen_opt(P[0], (const float* const* const)S[0], B, 0, 0, 0, 0, B_f_row, B_f_col, A_row_e, A_col_e, B_col_e);

    // Store P3 in C21
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e, C_f_col,
                          C_f_row + A_row_e, C_f_col, 0, 0, A_row_e, B_col_e);

    // Store P3 in C22
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // S4 = B21 - B11
    sub_matrix_blocks_gen(S[0], B, B, 0, 0, B_f_row + A_col_e, B_f_col, B_f_row, B_f_col, A_col_e, B_col_e);

    // P4 = A22 x S4
    strassen_aux_gen_opt(P[0], A, (const float* const* const)S[0], 0, 0, A_f_row + A_row_e, A_f_col + A_col_e, 0, 0, A_row_e, A_col_e, B_col_e);

    // Store P4 in C21
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e, C_f_col,
                          C_f_row + A_row_e, C_f_col, 0, 0, A_row_e, B_col_e);

    // Store P4 in C11
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);

    // S5 = A11 + A22
    sum_matrix_blocks_gen(S[0], A, A, 0, 0, A_f_row, A_f_col, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);

    // S6 = B11 + B22
    sum_matrix_blocks_gen(S[1], B, B, 0, 0, B_f_row, B_f_col, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P5 = S5 x S6
    strassen_aux_gen_opt(P[0], (const float* const* const)S[0], (const float* const* const)S[1], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e,
                     B_col_e);

    // Store P5 in C11
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);

    // Store P5 in C22
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // S7 = A12 - A22
    sub_matrix_blocks_gen(S[0], A, A, 0, 0, A_f_row, A_f_col + A_col_e, A_f_row + A_row_e, A_f_col + A_col_e, A_row_e, A_col_e);

    // S8 = B21 + B22
    sum_matrix_blocks_gen(S[1], B, B, 0, 0, B_f_row + A_col_e, B_f_col, B_f_row + A_col_e, B_f_col + B_col_e, A_col_e, B_col_e);

    // P6 = S7 x S8
    strassen_aux_gen_opt(P[0], (const float* const* const)S[0], (const float* const* const)S[1], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e,
                     B_col_e);

    // Store P6 in C11
    sum_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row, C_f_col, C_f_row,
                          C_f_col, 0, 0, A_row_e, B_col_e);

    // S9 = A11 - A21
    sub_matrix_blocks_gen(S[0], A, A, 0, 0, A_f_row, A_f_col, A_f_row + A_row_e, A_f_col, A_row_e, A_col_e);

    // S10 = B11 + B12
    sum_matrix_blocks_gen(S[1], B, B, 0, 0, B_f_row, B_f_col, B_f_row, B_f_col + B_col_e, A_col_e, B_col_e);

    // P7 = S9 x S10
    strassen_aux_gen_opt(P[0], (const float* const* const)S[0], (const float* const* const)S[1], 0, 0, 0, 0, 0, 0, A_row_e, A_col_e,
                     B_col_e);

    // Store P7 in C22
    sub_matrix_blocks_gen(C, (const float* const* const)C, (const float* const* const)P[0], C_f_row + A_row_e,
                          C_f_col + B_col_e, C_f_row + A_row_e, C_f_col + B_col_e, 0, 0, A_row_e, B_col_e);

    // deallocate
    deallocate_matrix(S[0], max);
    deallocate_matrix(S[1], max);
    free(S);

    deallocate_matrix(P[0], max);
    free(P);
}


/*
 * this functions are exclusively meant to provide an
 * easy to use API
 */
void strassen_matrix_multiplication(float** C, float const* const* const A, float const* const* const B, size_t n)
{

    strassen_aux(C, A, B, 0, 0, 0, 0, 0, 0, n);
}

void strassen_matrix_multiplication_gen(float** C, float const* const* const A, float const* const* const B,
                                        size_t A_row, size_t A_col, size_t B_col)
{

    strassen_aux_gen(C, A, B, 0, 0, 0, 0, 0, 0, A_row, A_col, B_col);
}

void strassen_matrix_multiplication_gen_opt(float** C, float const* const* const A, float const* const* const B,
                                        size_t A_row, size_t A_col, size_t B_col)
{

    strassen_aux_gen_opt(C, A, B, 0, 0, 0, 0, 0, 0, A_row, A_col, B_col);
}



