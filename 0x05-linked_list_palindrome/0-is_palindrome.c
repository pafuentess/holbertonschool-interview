#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* list_len - count members of list
* @h: list to print
* Return: number of lenght list
*/

int list_len(const listint_t *h)
{
	unsigned int i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}

/**
 * is_palindrome - check if a list is palindrome
 * @head: head of linked list
 * Return: 0 no palindrome 1 palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int lenght = 0, i = 0, j = 0;
	int store[1024];

	current = *head;
	lenght = list_len(*head);

	while (i < (lenght / 2))
	{
		store[i] = current->n;
		current = current->next;
		i++;
	}
	j = i - 1;
	while (j >= 0)
	{
		if (store[j] != current->n)
			return (0);
		current = current->next;
		j = j - 1;
	}
	return (1);
}
