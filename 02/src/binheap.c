#include <binheap.h>

// basic operation 

#define LEFT(node) (2 * (node) + 1)
#define RIGHT(node) (2 * ((node) + 1))
#define PARENT(node) (((node) - 1) / 2)

#define IS_VALID_NODE(H, node) ((H)->num_of_elem > (node))
#define ADDR(H, node) ((H)->A + (node) * (H)->key_size)
#define INDEX_OF(H, addr) (((addr) - ((H)->A))/((H)->key_size))

#define POS_FROM_KEY(H, key) ((H)->key_pos[key])
#define KEY_FROM_POS(H, pos) ((H)->rev_pos[pos])


int is_heap_empty(const binheap_type *H)
{
    return (H->num_of_elem == 0);
}

const void *min_value(const binheap_type *H)
{
    // This function must be re-implemented

    return NULL;
}

const void *extract_min(binheap_type *H)
{
    // This function must be re-implemented

    return NULL;
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    H->A = A;
    H->num_of_elem = num_of_elem;
    H->max_size = max_size;
    H->key_size = key_size;
    H->leq = leq;
    H->max_order_value = malloc(key_size);


    return H;
}

void delete_heap(binheap_type *H)
{
    // This function must be implemented
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    // This function must be re-implemented

    return NULL;
}

const void *insert_value(binheap_type *H, const void *value)
{
    // This function must be re-implemented

    return NULL;
}

void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
    // This function must be implemented
}