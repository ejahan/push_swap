/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:56:41 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/28 16:40:55 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_push_swap *ps)
{
	if (ps->b->first == NULL)
		return ;
	insertion(ps->a, ps->b->first->nbr);
	delete(ps->b);
	malloc_opti(ps, "pa\n");
	ps->ac++;
	ps->ac_b--;
}

void	push_b(t_push_swap *ps)
{
	if (ps->a->first == NULL)
		return ;
	insertion(ps->b, ps->a->first->nbr);
	delete(ps->a);
	malloc_opti(ps, "pb\n");
	ps->ac--;
	ps->ac_b++;
}

void	swap_one(t_push_swap *ps, t_list *list, char *s)
{
	int	tmp;

	if (list->first == NULL || list->first->next == NULL)
		return ;
	tmp = list->first->next->nbr;
	list->first->next->nbr = list->first->nbr;
	list->first->nbr = tmp;
	if (ft_memcmp(s, "sa\n", 3) == 0 || ft_memcmp(s, "sb\n", 3) == 0)
		malloc_opti(ps, s);
}
