#include "quick_sort.h"
#include "swap.h"
#include "total_order.h"
#include "select.h"
#include <stdio.h>

#define CONV(elem) (((elem) - A)/elem_size)
#define POS(elem) (A + (elem) * elem_size)

void quick(void* A, const unsigned int n, 
           void* idx_l, void* idx_r,
           const size_t elem_size, 
           total_order leq)
{
    int l = CONV(idx_l);
    int r = CONV(idx_r);
    
    if(l < r)
    { 
        pair p = threePartition(A, l, r, l, elem_size, leq);
        quick(A, n, idx_l, POS(p.first - 1), elem_size, leq);
        quick(A, n, POS(p.second + 1), idx_r, elem_size, leq);
    }
}

void quick_sort(void* A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    quick(A, n, A, POS(n - 1), elem_size, leq);
}