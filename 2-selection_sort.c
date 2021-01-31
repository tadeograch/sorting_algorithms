#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int lower = 0, position = 0, first = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		first = array[i];
		lower = first;
		for (j = i; j < size; j++)
		{
			if (lower > array[j])
			{
				lower = array[j];
				position = j;
			}
		}
		if (lower < first)
		{
			array[i] = lower;
			array[position] = first;
			print_array(array, size);
		}
	}
}
