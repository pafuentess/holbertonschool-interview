#include "search_algos.h"

/**
 * recursion - recursion function
 * @array: pointer to the first element of the array to search in
 * @start: start index
 * @end: end index
 * @value: value is the value to search for
 * Return: first index where value is located
 */

int recursion(int *array, int start, int end, int value)
{
	int i, mid;

	if (end < start)
		return (-1);
	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
	}
	mid = (start + end) / 2;
	if (array[mid] == value)
	{
		if (array[mid - 1] == value)
			return (recursion(array, start, mid,
						      value));
		return (mid);
	}
	else if (value <= array[mid])
		return (recursion(array, start, mid, value));
	else
		return (recursion(array, mid + 1, end, value));
	return (-1);
}

/**
 * advanced_binary - function that searches
 * @array: array to search
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{
	int i = 0;

	if (!array)
		return (-1);
	i = recursion(array, 0, size - 1, value);
	return (i);
}
