#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 *
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t index, i, minimum_index;
	int temporary = 0;

	if (array == NULL || size < 2)
		return;

	for (index = 0; index < size - 1; index++)
	{
		minimum_index = index;
		for (i = index + 1; i < size; i++)
		{
			if (array[i] < array[minimum_index])
			{
				minimum_index = i;
			}
		}
			if (minimum_index != i)
			{
				temporary = array[index];
				array[index] = array[minimum_index];
				array[minimum_index] = temporary;
				print_array(array, size);
			}
	}
}
