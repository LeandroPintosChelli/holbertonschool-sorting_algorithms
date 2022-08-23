#include "sort.h"

void selection_sort(int *array, size_t size)
{
	unsigned int PEPE1 = 0, PEPINIMO, PEPE2, PEPAUX;

	PEPINIMO = array[PEPE1];

	while (size > PEPE1)
	{
		PEPINIMO = PEPE1;
		for (PEPE2 = PEPE1 + 1; size > PEPE2; PEPE2++)
		{
			if (array[PEPINIMO] > array[PEPE2])
			{
				PEPINIMO = PEPE2;
			}
		}

		if (PEPINIMO != PEPE1)
		{
			PEPAUX = array[PEPE1];
			array[PEPE1] = array[PEPINIMO];
			array[PEPINIMO] = array[PEPAUX];

			print_array(array, size);
		}
		PEPE1++;
	}
}
