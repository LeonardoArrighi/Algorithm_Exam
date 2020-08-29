#include "quick_sort.h"
#include "swap.h"
#include "total_order.h"

int partition(void* A, const size_t elem_size,
               size_t l, size_t r, size_t pivot,
               total_order leq)
{
    swap(A + l * elem_size, A + pivot * elem_size, elem_size);
    size_t p = l;
    size_t i = l + 1;
    size_t j = r;

    while(i <= j)
    {
        if(!(leq(A + i * elem_size, A + p * elem_size)))
        {
            swap(A + i * elem_size, A + j * elem_size, elem_size);
            j--;
        }
        else
        {
            i++;
        }
    }

    swap(A + p * elem_size, A + j * elem_size, elem_size);

    return j;

}

void quick(void* A, void* idx_l, void* idx_r,
           const size_t elem_size, 
           total_order leq)
{
    int l = (idx_l - A)/elem_size;
    int r = (idx_r - A)/elem_size;
    while(l < r)
    {
        int p = partition(A, elem_size, l, r, l, leq);
        quick(A, A + l * elem_size, A + (p - 1) * elem_size, elem_size, leq);
        l = p + 1;
    }
}

void quick_sort(void* A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    quick(A, A, A + (n - 1) * elem_size, elem_size, leq);
}