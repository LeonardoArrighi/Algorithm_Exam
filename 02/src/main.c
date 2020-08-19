#include "binheap.h"
#include "total_orders.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 13

void int_printer(const void* value)
{
  printf("%d", *((const int* )value));
}

int main(){
	int* try=(int*)malloc(sizeof(int) * MAX_SIZE);
  	
  	for(int i = 0; i < MAX_SIZE; i++)
    {
        try[i] = (rand() % (MAX_SIZE + 1)); 
  	}

	printf("Build_heap\n");
	binheap_type * H1 = build_heap(try, MAX_SIZE-2, MAX_SIZE, sizeof(int), leq_int);
	print_heap(H1, int_printer);
	
	printf("\n\nHeapify on %d \n", try[MAX_SIZE/2]);
	heapify(H1, try[0]);
	print_heap(H1, int_printer);

	printf("\n\nIs_heap_empty? %d \n\n", is_heap_empty(H1));
	
	int min = *((int*) min_value(H1));
	printf("Min_value: %d\n\n", min);
	
	
	int insert = 5;
	printf("Insert_value = %d\n", insert);
	insert_value(H1, &insert);
	print_heap(H1, int_printer);	

	delete_heap(H1);

	return 0;

	
	
}

