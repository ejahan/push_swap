/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:24:21 by ejahan            #+#    #+#             */
/*   Updated: 2021/10/13 18:02:20 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_list(t_list *list)
{
	t_element	*to_delete;

	if (list == NULL)
		return (-1);
	while (list->first != NULL)
	{
		to_delete = list->first;
		list->first = list->first->next;
		free(to_delete);
	}
	free(list);
	return (0);
}

int	recup_int(char **av, int ac, t_list *list)
{
	int	i;

	while (ac > 1)
	{
		i = insertion(list, ft_atoi(av[ac - 1]));
		if (i == -1)
		{
			free_list(list);
			return (-1);
		}
		ac--;
	}
	return (0);
}

int	check_int(char **av, int ac)
{
	int	i;
	int	j;

	j = ac - 1;
	while (j > 0)
	{
		i = 0;
		if (av[j][i] == '-')
			i++;
		while (ft_isdigit(av[j][i]) == 1)
			i++;
		if (av[j][i] != '\0')
			return (-1);
		if (ft_atoi2(av[j]) > 2147483647 || ft_atoi2(av[j]) < -2147483648)
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
