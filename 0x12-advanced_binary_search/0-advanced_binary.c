#include "search_algos.h"

/**
 * parray - Prints array of integers
 * @arr: a pointer that point to the first case
 * @start: The index of the first element to print in the array.
 * @end: the index of the last element to print in the array.
*/
void parray(int *arr, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in arr: ");
	while (i <= end)
	{
		printf("%d", arr[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
		i += 1;
	}
}

/**
 * binary_search - Searches for a value in array
 * @arr: A pointer
 * @start: the first index
 * @end: the last index
 * @value: is the value to search for
 * Return: the index of the value
*/
int binary_search(int *arr, int start, int end, int value)
{
	int middle = (start + end) / 2;

	if (end >= start)
	{
		if (arr[middle] == value && end == start)
			return (middle);

		parray(arr, start, end);

		if (arr[middle] >= value)
			return (binary_search(arr, start, middle, value));
		else
			return (binary_search(arr, middle + 1, end, value));
	}
	return (-1);
}

/**
 * advanced_binary -  searches for a value in a sorted array of integers
 * @array:  is a pointer to the first element of the array to search in
 * @size: is the value to search for
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int advanced_binary(int *array, size_t size, int value)
{
	int result, end;

	if (!array)
		return (-1);
	end = ((int)size) - 1;
	result = binary_search(array, 0, end, value);
	return (result);
}
