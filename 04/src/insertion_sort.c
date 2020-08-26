#include "insertion_sort.h"
#include "swap.h"

void insertion_sort(void* A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{
    void* j;
    for(void* i = A + elem_size; i != A + n*elem_size; i += elem_size)
    {
        j = i;
        while((j != A) && leq(j, j - elem_size))
        {
            swap(j - elem_size, j, elem_size);
            j -= elem_size;
        }   
    }
}