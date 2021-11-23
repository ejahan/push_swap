/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:24:21 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/13 18:02:20 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	median_a(t_push_swap *ps, int ac)
{
	int	med;
	int	rotate;
	int	i;

	rotate = 0;
	i = 0;
	med = find_med(ps->a, ac);
	while (ac-- > 0)
	{
		if (ps->a->first->nbr <= med)
		{
			i++;
			push_b(ps);
		}
		else
		{
			rotate++;
			rotate_one(ps, ps->a, &ps->a->first, "ra\n");
		}
	}
	while (rotate-- > 0)
		rev_one(ps, ps->a, &ps->a->first, "rra\n");
	return (i);
}

int	median_b(t_push_swap *ps, int ac)
{
	int	med;
	int	rotate;
	int	i;

	rotate = 0;
	i = 0;
	med = find_med(ps->b, ac);
	while (ac-- > 0)
	{
		if (ps->b->first->nbr < med)
		{
			rotate++;
			rotate_one(ps, ps->b, &ps->b->first, "rb\n");
		}
		else
		{
			i++;
			push_a(ps);
		}
	}
	while (rotate-- > 0)
		rev_one(ps, ps->b, &ps->b->first, "rrb\n");
	return (i);
}

int	median_four_a(t_push_swap *ps)
{
	int	m;
	int	i;
	int	j;

	j = 0;
	i = 0;
	m = find_min_next_len(ps->a, 4, find_min_len(ps->a, 4));
	while (i < 2)
	{
		if (ps->a->first->nbr <= m)
		{
			i++;
			push_b(ps);
		}
		else
		{
			j++;
			rotate_one(ps, ps->a, &ps->a->first, "ra\n");
		}
	}
	while (j-- > 0)
		rev_one(ps, ps->a, &ps->a->first, "rra\n");
	return (2);
}

int	median_four_b(t_push_swap *ps)
{
	int	i;
	int	m;
	int	j;

	i = 0;
	j = 0;
	m = find_max_next_len(ps->b, 4, find_max_len(ps->b, 4));
	while (i < 2)
	{
		if (ps->b->first->nbr >= m)
		{
			i++;
			push_a(ps);
		}
		else
		{
			j++;
			rotate_one(ps, ps->b, &ps->b->first, "rb\n");
		}
	}
	while (j-- > 0)
		rev_one(ps, ps->b, &ps->b->first, "rrb\n");
	return (2);
}

int	median_three(t_push_swap *ps, char c)
{
	int	i;
	int	j;

	j = 0;
	if (c == 'a')
		median_three_a(ps);
	else
	{
		i = find_max_len(ps->b, 3);
		while (ps->b->first->nbr != i)
		{
			rotate_one(ps, ps->b, &ps->b->first, "rb\n");
			j++;
		}
		push_a(ps);
		while (j-- > 0)
			rev_one(ps, ps->b, &ps->b->first, "rrb\n");
		if (ps->b->first->nbr < ps->b->first->next->nbr)
			swap_one(ps, ps->b, "sb\n");
	}
	return (1);
}
