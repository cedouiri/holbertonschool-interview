#include "search_algos.h"

/**
 * parray - Prints an array
 * @array: pointer to the first element of the array
 * @min: min
 * @max: max
 *
 *
 * Return: No Return
 */
void parray(int *array, int min, int max)
{
	int i;

	for (i = min; i < max; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}
/**
 * binary_search - searches for a value in array
 * @array: pointer that point o the first element of arr
 * @min: min
 * @max: max
 * @value: value to search for
 *
 * Return: Index where value is located or -1
 */
int binary_search(int *array, int min, int max, int value)
{
	int mid;

	if (min > max)
		return (-1);

	printf("Searching in array: ");
	parray(array, min, max);

	if (min == max && array[max] == value)
		return (max);

	if (min == max && array[max] != value)
		return (-1);

	mid = min + (max - min) / 2;

	if ((mid == min || value != array[mid - 1]) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (binary_search(array, min, mid, value));
	return (binary_search(array, mid + 1, max, value));
}
/**
 * advanced_binary - searches for a value in arr
 * @array: pointer that point to the first element of arr
 * @size: size of arr
 * @value: value to search for
 *
 * Return: First index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
