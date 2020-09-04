#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* check_cycle - Write a function in C that checks
* if a singly linked list has a cycle in it.
* @list: list to check
* Return: 1: has cycle, 0 no cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *tortoi, *hare;

	tortoi = list;
	hare = list;

	while (tortoi && hare && hare->next)
	{
		tortoi = tortoi->next;
		hare = hare->next->next;

		if (tortoi == hare)
			return (1);
	}
	return (0);
}
