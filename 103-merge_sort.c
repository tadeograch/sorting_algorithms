#include <stdio.h>
#include "sort.h"

/**
 * merge_sort - Implements merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int n = (int)size;
	int *brray;

	brray = malloc(sizeof(int) * size);
	CopyArray(array, 0, n, brray);
	TopDownSplitMerge(brray, 0, n, array);
    free(brray);
}

/**
 * TopDownSplitMerge - Implements merge sort algorithm
 *
 * @B: The array to be sorted
 * @iBegin: Size of the array
 * @iEnd: asdsada
 * @A: dsdad
 */
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	int iMiddle, index;

	if (iEnd - iBegin <= 1)
		return;
	iMiddle = (iEnd + iBegin) / 2;

	TopDownSplitMerge(A, iBegin,  iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);

	printf("Merging...\n");
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	printf("[Done]: ");
	for (index = iBegin; index < iEnd; index++)
	{
		printf("%d", A[index]);
		if (index != iEnd - 1)
			printf(", ");
	}
	printf("\n");
}


/**
 * TopDownMerge - Implements merge sort algorithm
 *
 * @B: The array to be sorted
 * @iBegin: Size of the array
 * @iMiddle: ldasldsal
 * @iEnd: asdsada
 * @A: dsdad
 */
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin, j = iMiddle, k, index;

	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("[left]: ");
	for (index = iBegin; index < iMiddle; index++)
	{
		printf("%d ", A[index]);
		if (index != iMiddle - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (index = iMiddle; index < iEnd; index++)
	{
		printf("%d", A[index]);
		if (index != iEnd - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * CopyArray - Implements merge sort algorithm
 *
 * @B: The array to be sorted
 * @iBegin: Size of the array
 * @iEnd: asdsada
 * @A: dsdad
 */
void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}
