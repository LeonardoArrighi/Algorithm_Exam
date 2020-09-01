#include "select.h"
#include "swap.h"
#include <stdio.h>

#define POS(elem) (A + ((elem) * elem_size))
#define CONST(elem) (const void*) (A + ((elem) * elem_size))


pair threePartition(void* A, const unsigned int left,
                    const unsigned int right,
                    const unsigned int pivot,
                    const size_t elem_size,
                    total_order leq)
{
    swap(POS(left), POS(pivot), elem_size);

    // following 
    unsigned int i = left + 1;
    unsigned int j = left + 1;
    unsigned int k = right;

    while(i <= k)
    {
        if(!leq(CONST(i), CONST(left)))
        {
            swap(POS(i), POS(k), elem_size);
            k--;
        }
        else if(!leq(CONST(left), CONST(i)))
        {
            i++;
        }
        else
        {
            swap(POS(i), POS(j), elem_size);
            i++;
            j++;
        }
    }

    for(size_t inc = 0; inc <= (j - left - 1); inc++)
    {
        swap(POS(k - inc), POS(left + inc), elem_size);
    }

    pair pivots;
    pivots.first = k - (j - left - 1);
    pivots.second = k;

    return pivots;
}

unsigned int select_aux(void* A, const unsigned int n, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    return 0;
    
}

// median of medians
unsigned int select_pivot (void* A, const unsigned int n, 
            const size_t elem_size, 
            total_order leq)
{
    if (n < 10)
    {
        insertion_sort(A, n, elem_size, leq);
        return n / 2;
    }

    int chunks = n/5;

    for(unsigned int i = 0; i <= chunks; i++)
    {
        unsigned int start = 5 * i;
        unsigned int end = ((5 * i + 4) <= (n - 1)) ? 5 * i + 4 : (n - 1); 
        unsigned int n_in = end - start + 1;
        insertion_sort(POS(start), n_in, elem_size, leq);
        unsigned int median = ((5 * i + 2) < (n- 1)) ? 5 * i + 2 : (n - 1);
        swap(POS(i), POS(median), elem_size);
    }

    return select_aux(A, chunks, chunks / 2, elem_size, leq);
}



void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
   select_pivot(A, n, elem_size, leq);
   return;
}
