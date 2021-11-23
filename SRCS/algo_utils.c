/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:04:14 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/04 14:23:36 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_list *list)
{
	int			i;
	int			min;
	t_element	*first_tmp;

	i = 0;
	first_tmp = list->first;
	min = list->first->nbr;
	while (list->first->next != NULL)
	{
		if (list->first->next->nbr < min)
		{
			i++;
			min = list->first->next->nbr;
		}
		list->first = list->first->next;
	}
	list->first = first_tmp;
	return (min);
}

int	find_min_len(t_list *list, int ac)
{
	int			i;
	int			min;
	t_element	*first_tmp;

	i = 0;
	first_tmp = list->first;
	min = list->first->nbr;
	while (list->first->next != NULL && ac-- > 1)
	{
		if (list->first->next->nbr < min)
			min = list->first->next->nbr;
		list->first = list->first->next;
	}
	list->first = first_tmp;
	return (min);
}

int	find_min_next_len(t_list *list, int len, int old)
{
	int			min;
	t_element	*tmp;

	min = find_max_len(list, len);
	tmp = list->first;
	while (list->first != NULL && len-- > 0)
	{
		if (list->first->nbr < min && list->first->nbr > old)
			min = list->first->nbr;
		list->first = list->first->next;
	}
	list->first = tmp;
	return (min);
}

void	find_min_five(t_push_swap *ps, t_list *list)
{
	int			i;
	t_element	*first_tmp;

	i = 0;
	first_tmp = list->first;
	ps->min = list->first->nbr;
	while (list->first->next != NULL)
	{
		if (list->first->next->nbr < ps->min)
			ps->min = list->first->next->nbr;
		list->first = list->first->next;
	}
	list->first = first_tmp;
	while (list->first->nbr != ps->min)
	{
		i++;
		rotate_one(ps, ps->a, &ps->a->first, "no");
	}
	ps->min_range = i + 1;
	while (i-- > 0)
		rev_one(ps, ps->a, &ps->a->first, "no");
}

void	median_three_a(t_push_swap *ps)
{
	int	i;
	int	j;

	j = 0;
	i = find_min_len(ps->a, 3);
	while (ps->a->first->nbr != i)
	{
		rotate_one(ps, ps->a, &ps->a->first, "ra\n");
		j++;
	}
	push_b(ps);
	while (j-- > 0)
		rev_one(ps, ps->a, &ps->a->first, "rra\n");
	if (ps->a->first->nbr > ps->a->first->next->nbr)
		swap_one(ps, ps->a, "sa\n");
}
