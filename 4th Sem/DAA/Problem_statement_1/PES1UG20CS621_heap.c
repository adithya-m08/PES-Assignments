// Name: Adithya M
// SRN: PES1UG20CS621

#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = (int *)malloc(max_size * sizeof(int));
}

// Max heap
// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
    int i = heap->size;
    heap->arr[i] = key;
    heap->size++;
    while (i != 0)
    {
        int p = (i - 1) / 2;
        if (++*count_ptr && heap->arr[p] < heap->arr[i])
        {
            int temp = heap->arr[p];
            heap->arr[p] = heap->arr[i];
            heap->arr[i] = temp;
            i = p;
        }
        else
            return;
    }
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    int max = heap->arr[0];
    int i = 0;
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    while (i < heap->size)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (++*count_ptr && l < heap->size && heap->arr[l] > heap->arr[largest])
            largest = l;

        if (++*count_ptr && r < heap->size && heap->arr[r] > heap->arr[largest])
            largest = r;

        if (largest != i)
        {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[largest];
            heap->arr[largest] = temp;
            i = largest;
        }
        else
            i = heap->size;
    }
    return max;
}

// Searches for the element key in the heap
// Returns the element if found, else returns -1
int search(const heap_t *heap, int key, int *count_ptr)
{
    int ans = -1;
    for (int i = 0; i < heap->size; i++)
    {
        if (++*count_ptr && heap->arr[i] == key)
            ans = key;
    }
    return ans;
}

// Returns the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    *count_ptr = 0;
    return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{
    int min = heap->arr[heap->size / 2];
    for (int i = heap->size / 2 + 1; i < heap->size; i++)
    {
        if (++*count_ptr && min > heap->arr[i])
            min = heap->arr[i];
    }
    return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
    heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
    heap->size = 0;
    free(heap->arr);
    heap->arr = NULL;
}
