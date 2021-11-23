/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:04:14 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/04 14:23:36 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_list *list)
{
	int			max;
	t_element	*first_tmp;

	first_tmp = list->first;
	max = list->first->nbr;
	while (list->first->next != NULL)
	{
		if (list->first->next->nbr > max)
			max = list->first->next->nbr;
		list->first = list->first->next;
	}
	list->first = first_tmp;
	return (max);
}

int	find_max_len(t_list *list, int ac)
{
	int			max;
	t_element	*first_tmp;

	first_tmp = list->first;
	max = list->first->nbr;
	while (list->first->next != NULL && ac-- > 1)
	{
		if (list->first->next->nbr > max)
			max = list->first->next->nbr;
		list->first = list->first->next;
	}
	list->first = first_tmp;
	return (max);
}

int	find_max_next_len(t_list *list, int len, int old)
{
	int			max;
	t_element	*tmp;

	tmp = list->first;
	max = find_min_len(list, len);
	while (list->first != NULL && len-- > 0)
	{
		if (list->first->nbr > max && list->first->nbr < old)
			max = list->first->nbr;
		list->first = list->first->next;
	}
	list->first = tmp;
	return (max);
}

int	find_med(t_list *list, int ac)
{
	int	i;
	int	med;

	i = 1;
	med = find_min_len(list, ac);
	while (i++ < (ac / 2))
		med = find_min_next_len(list, ac, med);
	if (ac % 2 != 0)
		med = find_min_next_len(list, ac, med);
	return (med);
}
