/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:23:15 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/27 11:06:48 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi2(const char *str)
{
	int		i;
	int		n;
	long	nb;

	i = 0;
	n = 0;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		n = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (n == 1)
		nb = -nb;
	return (nb);
}

int	check_if_sort(t_push_swap *ps)
{
	t_element	*first_tmp;

	first_tmp = ps->a->first;
	while (ps->a->first->next != NULL)
	{
		if (ps->a->first->nbr > ps->a->first->next->nbr)
		{
			ps->a->first = first_tmp;
			return (-1);
		}
		ps->a->first = ps->a->first->next;
	}
	ps->a->first = first_tmp;
	return (0);
}

void	print_free(t_push_swap *ps, int ac, int check)
{
	int	i;

	i = 0;
	if (ac > 6 && ac <= 501 && check == 0)
	{
		print_ope(ps);
		while (ps->opti[i] != NULL)
		{
			free(ps->opti[i]);
			i++;
		}
		free(ps->opti);
	}
	free_list(ps->a);
	free_list(ps->b);
}
