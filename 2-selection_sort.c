#include "sort.h"
/**
* selection_sort - sorts an array of integers in ascending order
* @array: array
* @size: lenght of size
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, minimo, j;
	unsigned int aux;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (i < size - 1)
	{
		minimo = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[minimo] > array[j])
			{
				minimo = j;
			}
		}

		if (minimo != i)
		{
			aux = array[i];
			array[i] = array[minimo];
			array[minimo] = aux;

			print_array(array, size);
		}
		i++;
	}
}
