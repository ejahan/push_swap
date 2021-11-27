/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:24:21 by ejahan            #+#    #+#             */
/*   Updated: 2021/11/27 11:27:43 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	recup_in_str(char *av, t_list *list)
{
	int	i;
	int	ac;

	i = ft_strlen(av) - 1;
	ac = 0;
	if (i == 0)
	{
		insertion(list, ft_atoi(av));
		return (1);
	}
	while (i > 0)
	{
		while (av[i] == ' ' && i > 0)
			i--;
		while (ft_isdigit(av[i]) == 1 && i > 0)
			i--;
		if (av[i] == '-')
			i--;
		insertion(list, ft_atoi(&av[i]));
		ac++;
	}
	return (ac);
}

int	recup_int(char **av, int ac, t_push_swap *ps)
{
	int	i;

	while (ac > 1)
	{
		i = recup_in_str(av[ac - 1], ps->a);
		ps->ac += i;
		if (i == -1)
		{
			free_list(ps->a);
			return (-1);
		}
		ac--;
	}
	return (0);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]) == 1)
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != '-' && ft_isdigit(str[i]) != 1)
			return (-1);
		if (str[i] == '-' && i >= 1 && str[i - 1] != ' ')
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return (1);
}

int	check_max(char *str)
{
	int		i;
	long	check;

	i = 0;
	while (str[i])
	{
		check = ft_atoi2(&str[i]);
		if (check > 2147483647 || check < -2147483648)
			return (-1);
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	return (1);
}

int	check_int(char **av, int ac)
{
	int	i;
	int	j;

	j = ac - 1;
	while (j > 0)
	{
		i = 0;
		if (check_digit(av[j]) == -1)
			return (-1);
		if (check_max(av[j]) == -1)
			return (-1);
		i = j - 1;
		while (i > 0)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (-1);
			i--;
		}
		j--;
	}
	return (0);
}
