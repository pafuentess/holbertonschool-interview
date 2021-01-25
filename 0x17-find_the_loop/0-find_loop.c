#include "lists.h"

/**
 * loop - check the code for Holberton School students.
 * @tortoise: pointer one by one
 * @hare: pointer leap one
 * Return: poibter where the loop start
 */

listint_t *loop(listint_t *tortoise, listint_t *hare)
{
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	return (tortoise);
}

/**
 * find_listint_loop - finds loops inside lists
 * @head: address pointer head
 * Return: number of nodes
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head)
	{
		tortoise = head->next;
		hare = head->next->next;
		while (tortoise && hare)
		{
			if (tortoise == hare)
			{
				tortoise = head;
				return (loop(tortoise, hare));
			}
			tortoise = tortoise->next;
			hare = hare->next->next;
		}
	}
	return (0);
}
