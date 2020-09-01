#include "insertion_sort.h"
#include "swap.h"

#define POS(elem) (A + ((elem) * elem_size))
#define CONST(elem) (const void*) (A + ((elem) * elem_size))

void insertion_sort(void* A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{
    void* j;
    for(void* i = POS(1); i != POS(n); i += elem_size)
    {
        j = i;
        while((j != POS(0)) && leq(j, j - elem_size))
        {
            swap(j - elem_size, j, elem_size);
            j -= elem_size;
        }   
    }
}