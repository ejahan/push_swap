/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:24:28 by elisa             #+#    #+#             */
/*   Updated: 2021/11/10 12:22:29 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo(int ac, t_push_swap *ps)
{
	ps->count = 0;
	if (ac == 3 && ps->a->first->nbr > ps->a->first->next->nbr)
		s_swap_one(ps, ps->a, "sa\n");
	else if (ac == 4)
		sort_three(ps);
	else if (ac > 3 && ac <= 6)
		sort_five(ps);
	else if (ac > 6 && ac <= 101)
		ps->opti = malloc(sizeof(char *) * 1500);
	else if (ac > 101 && ac <= 501)
		ps->opti = malloc(sizeof(char *) * 10000);
	if (ac > 6)
	{
		if (ps->opti == NULL)
			return ;
		sort_hundred(ps, 'a', ps->ac);
	}
}

int	malloc_opti(t_push_swap *ps, char *str)
{
	int	i;

	i = 0;
	ps->opti[ps->count] = malloc(sizeof(char) * 5);
	if (ps->opti[ps->count] == NULL)
		return (-1);
	ps->opti[ps->count][4] = '\0';
	while (i < 4)
	{
		ps->opti[ps->count][i] = str[i];
		i++;
	}
	ps->count++;
	return (0);
}

int	push_swap(char **av, int ac, t_push_swap *ps)
{
	ps->ac = ac - 1;
	if (check_int(av, ac) == -1)
		return (-1);
	ps->a = init(0);
	ps->b = init(0);
	if (recup_int(av, ac, ps->a) == -1)
		return (-1);
	if (ac > 2 && check_if_sort(ps) == 0)
	{
		print_free(ps, ac, 1);
		return (1);
	}
	algo(ac, ps);
	print_free(ps, ac, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	ps;

	ps.count = 0;
	ps.ac_b = 0;
	if (ac == 1)
		return (0);
	if (push_swap(av, ac, &ps) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
