#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node in a sorted way
 * @head: head pointer to linked list
 * @number: number of new node
 * Return: the new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp1, *tmp2;

	if (head == NULL)
		return (NULL);

	if (*head == NULL)
		return (add_nodeint_end(head, number));

	tmp1 = *head;
	tmp2 = tmp1->next;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (tmp1->n > number)
	{
		new->next = tmp1;
		*head = new;
		return (new);
	}
	while (tmp2->next != NULL)
	{
		if (tmp1->n <= number && tmp2->n > number)
		{
			tmp1->next = new;
			new->next = tmp2;
			break;
		}
		else
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	if (tmp2->next == NULL)
	{
		new = add_nodeint_end(head, number);
	}
	return (new);
}
