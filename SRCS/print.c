/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:23:15 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/13 17:02:10 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_push_a(t_push_swap *ps, int i)
{
	int	a;
	int	b;
	int	j;

	a = 0;
	b = 0;
	j = 0;
	while (ps->opti[i + a]
		&& ft_memcmp(ps->opti[i + a], "pa\n", 3) == 0)
		a++;
	while (ps->opti[i + a + b]
		&& ft_memcmp(ps->opti[i + a + b], "pb\n", 3) == 0)
		b++;
	if (b >= a)
		return (i + a * 2);
	else
	{
		while (a - j != b)
		{
			j++;
			write(1, "pa\n", 3);
		}
		return (i + a + b);
	}
}

int	print_push_b(t_push_swap *ps, int i)
{
	int	a;
	int	b;
	int	j;

	a = 0;
	b = 0;
	j = 0;
	while (ps->opti[i + a]
		&& ft_memcmp(ps->opti[i + a], "pb\n", 3) == 0)
		a++;
	while (ps->opti[i + a + b]
		&& ft_memcmp(ps->opti[i + a + b], "pa\n", 3) == 0)
		b++;
	if (b >= a)
		return (i + a * 2);
	else
	{
		while (a - j != b)
		{
			j++;
			write(1, "pb\n", 3);
		}
		return (i + a + b);
	}
}

void	print_ope(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->opti[ps->count] = NULL;
	while (ps->opti[i] != NULL)
	{
		if (ft_memcmp(ps->opti[i], "sa\n", 3) == 0)
			write(1, "sa\n", 3);
		else if (ft_memcmp(ps->opti[i], "sb\n", 3) == 0)
			write(1, "sb\n", 3);
		else if (ft_memcmp(ps->opti[i], "ra\n", 3) == 0)
			write(1, "ra\n", 3);
		else if (ft_memcmp(ps->opti[i], "rb\n", 3) == 0)
			write(1, "rb\n", 3);
		else if (ft_memcmp(ps->opti[i], "rra\n", 3) == 0)
			write(1, "rra\n", 4);
		else if (ft_memcmp(ps->opti[i], "rrb\n", 3) == 0)
			write(1, "rrb\n", 4);
		else if (ps->opti[i][0] == 'p' && ps->opti[i][1] == 'a')
			i = print_push_a(ps, i) - 1;
		else if (ps->opti[i][0] == 'p' && ps->opti[i][1] == 'b')
			i = print_push_b(ps, i) - 1;
		i++;
	}
}
