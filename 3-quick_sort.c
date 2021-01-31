#include <stdio.h>
#include "sort.h"
  
/**
 * quick_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int hi = (size - 1);

	rec_quick_sort(array, 0, hi, size);
}

/**
 * rec_quick_sort -  recursive function
 * @array: array to sort
 * @lo: smallest index
 * @hi: highest index
 * @size: size of array
 */
void rec_quick_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		rec_quick_sort(array, lo, p - 1, size);
		rec_quick_sort(array, p + 1, hi, size);
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
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int temp, j, i = lo;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	if (array[hi] != pivot)
		print_array(array, size);
	return (i);
}
