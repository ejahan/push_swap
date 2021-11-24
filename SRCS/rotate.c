/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:57:53 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/24 19:21:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_one(t_push_swap *ps, t_list *list, t_element **elem, char *s)
{
	t_element	*first;
	t_element	*last;

	if ((list->first == NULL) || (list->first->next == NULL))
		return ;
	last = *elem;
	first = (*elem)->next;
	while ((*elem)->next)
		*elem = (*elem)->next;
	(*elem)->next = last;
	last->next = NULL;
	*elem = first;
	if (ft_memcmp(s, "ra\n", 3) == 0 || ft_memcmp(s, "rb\n", 3) == 0)
		malloc_opti(ps, s);
}

void	rev_one(t_push_swap *ps, t_list *list, t_element **elem, char *s)
{
	t_element	*tmp;
	t_element	*first;

	if ((list->first == NULL) || (list->first->next == NULL))
		return ;
	first = *elem;
	while ((*elem)->next != NULL)
	{
		tmp = *elem;
		*elem = (*elem)->next;
	}
	(*elem)->next = first;
	tmp->next = NULL;
	if (ft_memcmp(s, "rra\n", 4) == 0 || ft_memcmp(s, "rrb\n", 4) == 0)
	{
		malloc_opti(ps, s);
	}
}
