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
    if (n <= 10)
    {
        insertion_sort(A, n, elem_size, leq);
        return i;
    }

    unsigned int j = select_pivot(A, n, elem_size, leq);
    pair p = threePartition(A, 0, n - 1, j, elem_size, leq);

    if(i < p.first)
    {
        if(p.first > 0)
        {
            return select_aux(A, p.first - 1, i, elem_size, leq);
        }
        else
        {
            return p.first;
        }
    }
    
    if(i > p.second)
    {
        if(p.second < n)
        {
            return select_aux(POS(p.second), n - p.second - 1, i, elem_size, leq);
        }
        else
        {
            return p.second;
        }
    }
    
    return i;    
}

// median of medians
unsigned int select_pivot (void* A, const unsigned int n, 
            const size_t elem_size, 
            total_order leq)
{
    unsigned int last = n - 1;

    if(n < 10) //base case
    {
        insertion_sort(A, n, elem_size, leq);
        return n / 2;
    }

    unsigned int chunks = n / 5;

    for(unsigned int i = 0; i < chunks; i++)
    {
        unsigned int start = (5 * i); 
        unsigned int end = (5 * i + 4 < last) ? 5 * i + 4 : last; 
        unsigned int n = end - start + 1;
        insertion_sort(POS(start), n, elem_size, leq);
        unsigned int median = (5 * i + 2 < last) ? 5 * i + 2 : last; 
        swap(POS(i), POS(median), elem_size);
    }

    return select_aux(A, chunks, chunks / 2, elem_size, leq);
}


void quick_select(void* A, const unsigned int n, 
           size_t l, size_t r,
           const size_t elem_size, 
           total_order leq)
{
    while(l < r)
    {
        unsigned int j = l + select_pivot(POS(l), r - l, elem_size, leq);
        pair p = threePartition(A, l, r - 1, j, elem_size, leq);
        quick_select(A, n, l, p.first, elem_size, leq);
        l = p.second + 1;
    }
}


void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
   quick_select(A, n, 0, n, elem_size, leq);
}
