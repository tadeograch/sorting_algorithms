#include <stdio.h>
#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int hi = (size - 1);

    if (size < 2)
        return;
	rec_quick_sort_hoare(array, 0, hi, size);
}

/**
 * rec_quick_sort -  recursive function
 * @array: array to sort
 * @lo: smallest index
 * @hi: highest index
 * @size: size of array
 */
void rec_quick_sort_hoare(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition_hoare(array, lo, hi, size);
		rec_quick_sort_hoare(array, lo, p, size);
		rec_quick_sort_hoare(array, p + 1, hi, size);
	}
}

/**
 * partition -  swaps values in array
 * @array: array to sort
 * @lo: smallest index
 * @hi: highest index
 * @size: size of array
 * Return: position i
 */
int partition_hoare(int *array, int lo, int hi, size_t size)
{
    int pivot = array[lo];
    int i = lo;
    int j = hi;
    int temp = 0;

    while(1)
    {
        while(array[i] < pivot)
        {
            i++;
        }
        while(array[j] > pivot)
        {
            j--;
        }
        if (i >= j)
            return(j);
        temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
        print_array(array, size);
    }
}