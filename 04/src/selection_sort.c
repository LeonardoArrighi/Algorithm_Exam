#include "selection_sort.h"
#include "swap.h"

#define POS(elem) (A + elem * elem_size)

void selection_sort(void *A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{
    for (size_t i = n - 1; i > 0; i--)
    {
        size_t max_j = 0;
        for(size_t j = 1; j <= i; j++)
        {
            if(!leq(POS(j), POS(max_j)))
            {
                max_j = j;
            }
        }
        swap(POS(max_j), POS(i), elem_size);
    }
}