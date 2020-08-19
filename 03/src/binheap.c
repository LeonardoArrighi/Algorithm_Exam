#include <binheap.h>
#include <string.h>
#include <stdio.h>


// basic operation 

#define LEFT(node) (2 * (node) + 1)
#define RIGHT(node) (2 * ((node) + 1))
#define PARENT(node) (((node) - 1) / 2)

#define IS_VALID_NODE(H, node) ((H)->num_of_elem > (node))

#define ADDR(H, node) ((H)->A + (node) * (H)->key_size)
#define INDEX_OF(H, addr) (((addr) - ((H)->A))/((H)->key_size))

#define POS(H, key) ((H)->key_pos[key])
#define KEY(H, pos) ((H)->rev_pos[pos])

int is_heap_empty(const binheap_type *H)
{
    return (H->num_of_elem == 0);
}

const void* min_value(const binheap_type *H)
{
    if (is_heap_empty(H))
    {
        return NULL;
    }
    
    return ADDR(H, 0);
}

void swap_keys(binheap_type* H, unsigned int a, unsigned int b)
{
    unsigned int pa = POS(H, a);
    unsigned int pb = POS(H, b);
    unsigned int tmp = POS(H, a);

    POS(H, a) = POS(H, b);
    POS(H, b) = tmp;

    KEY(H, pa) = b;
    KEY(H, pb) = a;
}

void heapify(binheap_type* H, unsigned int node)
{
    unsigned int dst_node = node;
    unsigned int child; 
    unsigned int node_p;
    unsigned int child_p;

    do
    {
        dst_node = node;
        node_p = POS(H, node);

        child_p = RIGHT(node_p);
        if(IS_VALID_NODE(H, child_p))
        {
            child = KEY(H, child_p);
            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
            {
                dst_node = child;
            }
        }

        child_p = LEFT(node_p);
        if(IS_VALID_NODE(H, child_p))
        {
            child = KEY(H, child_p);
            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
            {
                dst_node = child;
            }
        }

        if(dst_node != node)
        {
            swap_keys(H, dst_node, node);
        }
    } while (dst_node != node);
}

const void* extract_min(binheap_type* H)
{
    if (is_heap_empty(H))
    {
        return NULL;
    }

    swap_keys(H, KEY(H, 0), KEY(H, H->num_of_elem - 1));

    H->num_of_elem--;

    heapify(H, KEY(H, 0));

    return ADDR(H, KEY(H, H->num_of_elem));
}

const void* find_the_max(void* A, const unsigned int num_of_elem,
                         const unsigned int key_size, total_order_type leq)
{
    if(num_of_elem == 0)
    {
        return NULL;
    }

    const void* max_value = A;

    for(const void* addr = A + key_size; addr != A + num_of_elem * key_size; addr += key_size)
    {
        if (!leq(addr, max_value))
        {
            max_value = addr;
        }
    }

    return max_value;
}

binheap_type* build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    binheap_type* H = (binheap_type*)malloc(sizeof(binheap_type));

    H->A = A;
    H->num_of_elem = num_of_elem;
    H->max_size = max_size;
    H->key_size = key_size;
    H->leq = leq;
    H->max_order_value = malloc(key_size);
    // arrays
    H->key_pos = (unsigned int*)malloc(max_size * sizeof(unsigned int));
    H->rev_pos = (unsigned int*)malloc(max_size * sizeof(unsigned int));
    
    for (unsigned int i = 0; i < max_size; i++)
    {
        H->key_pos[i] = i;
        H->rev_pos[i] = i;
    }
    
    if (num_of_elem == 0)
    {
        return H;
    }

    // Get the maximum among A[:num_of_elem-1] and store it in max_value_order
    const void* value = find_the_max(A, num_of_elem, key_size, leq);
    memcpy(H->max_order_value, value, key_size);

    // Fix the heap property from the second-last level up to the root
    for (unsigned int i = num_of_elem / 2; i > 0; i--)
    {
        heapify(H, KEY(H, i));
    }
    //heapify(H, KEY(H, 0));

    return H;
}


void delete_heap(binheap_type *H)
{
    free(H->max_order_value);
    free(H->key_pos);
    free(H->rev_pos);
    free(H);   
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    unsigned int node_x = INDEX_OF(H, node);
    unsigned int node_p = POS(H, node_x);

    if (!IS_VALID_NODE(H, node_x) || !(H->leq(value, node)))
    {
        return NULL;
    }

    memcpy(node, value, H->key_size);

    unsigned int parent_x = KEY(H, PARENT(node_x));
    void* parent = ADDR(H, parent_x);

    while ((node_x != 0) && (!H->leq(parent, node)))
    {
        // swap keys of parent and node
        swap_keys(H, parent_x, node_x);

        // node's parent
        node_p = POS(H, node_x);
        parent_x = KEY(H, PARENT(node_p));
        parent = ADDR(H, parent_x);
    }

    return node;
}

const void *insert_value(binheap_type *H, const void *value)
{
    // if heap is full
    if (H->max_size == H->num_of_elem)
    {
        return NULL;
    }

    // if new value is higher than *max_order_value
    if ((H->num_of_elem == 0) || (!H->leq(value, H->max_order_value)))
    {
        memcpy(H->max_order_value, value, H->key_size);
    }

     // get the position of the new node
    void* new_node_address = ADDR(H, KEY(H, H->num_of_elem));
    memcpy(new_node_address, H->max_order_value, H->key_size);

    // increase the size of the heap
    H->num_of_elem++;

    // decrease the key of the new node
    return decrease_key(H, new_node_address, value);
}

void print_heap(const binheap_type* H, void (*key_printer)(const void* value))
{
    unsigned int next_level_node = 1;  

    for (unsigned int node = 0; node < H->num_of_elem; node++)
    {
        if (node == next_level_node)
        {
            printf("\n");
            next_level_node = LEFT(node);
        }
        else
        {
            printf("\t");
        }

        key_printer(ADDR(H, KEY(H, node)));
    }

    printf("\n\n");
}