#include "select.h"
#include "swap.h"
#include <stdio.h>

#define POS(elem) (A + ((elem) * elem_size))
#define CONST(elem) (const void*) (A + ((elem) * elem_size))


unsigned int select_pivot(void *A, const unsigned int n, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    return 0;	
}


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

// unsigned int select()
// {
//     return 0;
// }

// void select_aux()
// {
//     return;
// }


// // median of medians
// void median ()
// {  
//     return;
// }




// void quick_sort_select_aux()
// {
//     return;
// }




void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
   return;
}
