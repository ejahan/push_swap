/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:13:49 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/20 18:55:25 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*init(int i)
{
	t_list		*list;

	(void)i;
	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	return (list);
}

int	insertion(t_list *list, int new_nbr)
{
	t_element	*new;

	if (list == NULL)
		return (-1);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (-1);
	new->nbr = new_nbr;
	new->next = list->first;
	list->first = new;
	return (0);
}

int	delete(t_list *list)
{
	t_element	*to_delete;

	if (list == NULL)
		return (-1);
	if (list->first != NULL)
	{
		to_delete = list->first;
		list->first = list->first->next;
		free(to_delete);
	}
	return (0);
}

// int	print_list(t_list *list, t_list *b)
// {
// 	t_element	*element;
// 	t_element	*element2;

// 	element = list->first;
// 	element2 = b->first;
// 	if (list == NULL)
// 		return (-1);
// 	printf("\033[1;34m-> a				-> b\n\033[0m");
// 	while (element != NULL || element2 != NULL)
// 	{
// 		if (element != NULL)
// 		{
// 			printf("\033[1;35m%d				\033[0m", element->nbr);
// 			element = element->next;
// 		}
// 		if (element2 != NULL)
// 		{
// 			printf("\033[1;35m%d\033[0m", element2->nbr);
// 			element2 = element2->next;
// 		}
// 		printf("\n");
// 		if (element == NULL)
// 			printf("				");
// 	}
// 	printf("\n");
// 	// printf("-> NULL\n\n");
// 	return (0);
// }

int	print_list(t_list *list, t_list *b)
{
	t_element	*element;
	t_element	*element2;

	element = list->first;
	element2 = b->first;
	if (list == NULL)
		return (-1);
	printf("\033[1;34m-> a	\n\033[0m");
	while (element != NULL)
	{
		printf("\033[1;35m%d\n\033[0m", element->nbr);
		element = element->next;
	}
	printf("\033[1;34m\n-> b	\n\033[0m");
	while (element2 != NULL)
	{
		printf("\033[1;35m%d\n\033[0m", element2->nbr);
		element2 = element2->next;
	}
	printf("\n\n\n");
	return (0);
}
