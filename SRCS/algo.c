/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:31:54 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/15 23:40:52 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_push_swap *ps)
{
	if (check_if_sort(ps) == 0)
		return ;
	if (ps->a->first->nbr > ps->a->first->next->nbr
		&& ps->a->first->nbr > ps->a->first->next->next->nbr)
	{
		s_rotate_one(ps, ps->a, &ps->a->first, "ra\n");
		if (ps->a->first->nbr > ps->a->first->next->nbr)
			s_swap_one(ps, ps->a, "sa\n");
	}
	else if (ps->a->first->nbr > ps->a->first->next->next->nbr
		&& ps->a->first->next->nbr > ps->a->first->next->next->nbr)
		s_rev_one(ps, ps->a, &ps->a->first, "rra\n");
	else
	{
		s_swap_one(ps, ps->a, "sa\n");
		if (ps->a->first->nbr > ps->a->first->next->nbr)
			s_rotate_one(ps, ps->a, &ps->a->first, "ra\n");
	}
}

void	sort_five(t_push_swap *ps)
{
	find_min_five(ps, ps->a);
	if (ps->min_range < 4)
		while (ps->a->first->nbr != ps->min)
			s_rotate_one(ps, ps->a, &ps->a->first, "ra\n");
	else
		while (ps->a->first->nbr != ps->min)
			s_rev_one(ps, ps->a, &ps->a->first, "rra\n");
	s_push_b(ps);
	if (ps->ac == 4)
	{
		find_min_five(ps, ps->a);
		if (ps->min_range < 4)
			while (ps->a->first->nbr != ps->min)
				s_rotate_one(ps, ps->a, &ps->a->first, "ra\n");
		else
			s_rev_one(ps, ps->a, &ps->a->first, "rra\n");
		s_push_b(ps);
	}
	sort_three(ps);
	s_push_a(ps);
	if (ps->ac == 4)
		s_push_a(ps);
}

int	median_small(t_push_swap *ps, char c, int ac)
{
	if (ac == 4)
	{
		if (c == 'a')
			return (median_four_a(ps));
		else
			return (median_four_b(ps));
	}
	if (ac == 3)
		return (median_three(ps, c));
	if (ac == 2)
	{
		if (c == 'a')
		{
			if (ps->a->first->nbr > ps->a->first->next->nbr)
				swap_one(ps, ps->a, "sa\n");
		}
		else if (c == 'b')
		{
			if (ps->b->first->nbr < ps->b->first->next->nbr)
				swap_one(ps, ps->b, "sb\n");
		}
	}
	return (0);
}

int	median(t_push_swap *ps, char c, int ac)
{
	if (ac < 5)
		return (median_small(ps, c, ac));
	else
	{
		if (c == 'a')
			return (median_a(ps, ac));
		else
			return (median_b(ps, ac));
	}
}

void	sort_hundred(t_push_swap *ps, char c, int ac)
{
	int	i;

	i = median(ps, c, ac);
	if (ac > 3)
	{
		if (c == 'a')
		{
			sort_hundred(ps, 'a', ac - i);
			sort_hundred(ps, 'b', i);
		}
		else
		{
			sort_hundred(ps, 'b', ac - i);
			sort_hundred(ps, 'a', i);
		}
	}
	while (i-- > 0)
	{
		if (c == 'a')
			push_a(ps);
		else
			push_b(ps);
	}
}
