#include "sort.h"
void _qsort(int *array, size_t size, int left, int right);
int partition(int *array, size_t size, int left, int right);
void swap_int(int *a, int *b);
/**
* quick_sort - partitions sorts by half
* @array: Array
* @size: size of lenght
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_qsort(array, size, 0, size - 1);
}

/**
* _qsort - recursively calls itself to move left and right
* @array: the array
* @left: left pointer
* @right: right pointer
* @size: size of lenght
*/
void _qsort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		_qsort(array, size, left, part - 1);
		_qsort(array, size, part + 1, right);
	}
}
/**
* partition - partition sorts by pivot point
* @array: the array
* @left: left pointer
* @right: right pointer
* @size: size of lenght
* Return: integer
*/
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}
/**
 * swap_int - check the code
 * @a: swaps the values of two integers.
 * @b: swaps the values of two integers.
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
