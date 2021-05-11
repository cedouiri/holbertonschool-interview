#include "sort.h"

/**
 * swap_val - swap 2 values
 * @array: array
 * @fi: First index
 * @si: Second index
 * @s: size
 * Return: always nothing
 *
 */
void swap_val(int *array, int fi, int si, const int s)
{
	int temp;
	(void)s;

	if (fi != si)
	{
		temp = array[fi];
		array[fi] = array[si];
		array[si] = temp;
		print_array(array, (size_t)s);
	}
}

/**
 * largest_num - Find the largest number
 * @array: array
 * @size: The menor element
 * @i: The largest.
 * @r_size: The size for print in swap
 * Return: Nothing.
 */
void largest_num(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != i)
	{
		swap_val(array, i, largest, r_size);
		largest_num(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @array: The array that generate the layers
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		largest_num(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap_val(array, 0, i, r_size);
		largest_num(array, i, 0, r_size);
	}
}
