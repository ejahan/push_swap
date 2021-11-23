/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:56:41 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/28 16:40:55 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s_push_a(t_push_swap *ps)
{
	if (ps->b->first == NULL)
		return ;
	insertion(ps->a, ps->b->first->nbr);
	delete(ps->b);
	write(1, "pa\n", 3);
	ps->ac++;
	ps->ac_b--;
	ps->count++;
}

void	s_push_b(t_push_swap *ps)
{
	if (ps->a->first == NULL)
		return ;
	insertion(ps->b, ps->a->first->nbr);
	delete(ps->a);
	write(1, "pb\n", 3);
	ps->ac--;
	ps->ac_b++;
	ps->count++;
}

void	s_swap_one(t_push_swap *ps, t_list *list, char *s)
{
	int	tmp;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	tmp = list->first->next->nbr;
	list->first->next->nbr = list->first->nbr;
	list->first->nbr = tmp;
	if (ft_memcmp(s, "sa\n", 3) == 0 || ft_memcmp(s, "sb\n", 3) == 0)
	{
		ps->count++;
		write(1, s, 3);
	}
}

void	s_rotate_one(t_push_swap *ps, t_list *list, t_element **elem, char *s)
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
	{
		write(1, s, 3);
		ps->count++;
	}
}

void	s_rev_one(t_push_swap *ps, t_list *list, t_element **elem, char *s)
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
		ps->count++;
		write(1, s, 4);
	}
}
