#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
* right - move to right
* @line: array to mmove
* @size: array length
*/

void right(int *line, size_t size)
{
	int i, store = 0;
	int f = size - 1;
	int amount = 0;

	for (i = f; i >= 0; i--)
	{
		if (line[i] == 0)
			store += 1;
		if (line[i] > 0)
			amount += 1;
		if (line[i] > 0 && store > 0)
		{
			line[i + store] = line[i];
			line[i] = 0;
			i = i + store;
			store = 0;
		}
	}
	store = f;
	for (i = f; i > f - amount; i--)
	{
		if (i > f - amount + 1 && line[i] == line[i - 1])
		{
			line[store] = line[i] + line[i - 1];
			line[i - 1] = 0;
			if (store != i)
				line[i] = 0;
			store -= 1;
		}
		else if (line[i] > 0 && store < f)
		{
			line[store] = line[i];
			if (store != i)
				line[i] = 0;
			store -= 1;
		}
		else if (line[i] > 0)
			store -= 1;
	}
}

/**
* left - move to left
* @line: array to mmove
* @size: array length
*/

void left(int *line, size_t size)
{
	int i, store = 0;
	int amount = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			store += 1;
		if (line[i] > 0)
			amount += 1;
		if (line[i] > 0 && store > 0)
		{
			line[i - store] = line[i];
			if (store != i)
				line[i] = 0;
			i = i - store;
			store = 0;
		}
	}
	store = 0;
	for (i = 0; i < amount; i++)
	{
		if (i < amount - 1 && line[i] == line[i + 1])
		{
			line[store] = line[i] + line[i + 1];
			line[i + 1] = 0;
			if (store != i)
				line[i] = 0;
			store += 1;
		}
		else if (line[i] > 0 && store > 0)
		{
			line[store] = line[i];
			if (store != i)
				line[i] = 0;
			store += 1;
		}
		else if (line[i] > 0)
			store += 1;
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to head of line
 * @size: size of the int array
 * @direction: direction to slide
 * Return: 1 if accomplish, 0
 */

int slide_line(int *line, size_t size, int direction)
{
	/**
	*if (line == NULL || size < 1)
	*	return (0);
	*if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
	*	return (0);
	*/
	if (direction == 0)
		left(line, size);
	if (direction == 1)
		right(line, size);
	return (1);
}
