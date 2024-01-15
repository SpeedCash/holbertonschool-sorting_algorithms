#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, index;
	int temporary = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1])
			{
				temporary = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temporary;
				print_array(array, size);
			}
		}
	}
}
