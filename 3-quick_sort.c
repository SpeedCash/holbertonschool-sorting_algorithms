#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array according to the Lomuto scheme
 * @array: The array to order
 * @size: The size of the array
 * @lo: The lowest index of the subset
 * @hi: The highest index of the subset
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo;

	if (array == NULL || size < 2)
		return (-1);

	for (int j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[hi])
	{
		swap_ints(&array[i], &array[hi]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursion - Implements the quick sort algorithm using recursion
 * @array: The array to sort
 * @size: The size of the array
 * @lo: The lowest index of the subset to sort
 * @hi: The highest index of the subset to sort
 */
void quick_sort_recursion(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, size, lo, hi);

		quick_sort_recursion(array, size, lo, p - 1);
		quick_sort_recursion(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
