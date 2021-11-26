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

int	print_list(t_list *list, t_list *b)
{
	t_element	*element;
	t_element	*element2;

	element = list->first;
	element2 = b->first;
	if (list == NULL)
		return (-1);
	printf("\033[1;34m-> a	\n\033[0m");
	while (element != NULL)
	{
		printf("\033[1;35m%d\n\033[0m", element->nbr);
		element = element->next;
	}
	printf("\033[1;34m\n-> b	\n\033[0m");
	while (element2 != NULL)
	{
		printf("\033[1;35m%d\n\033[0m", element2->nbr);
		element2 = element2->next;
	}
	printf("\n\n\n");
	return (0);
}

int	recup_in_str(char *av, t_list *list)
{
	int	i;
	int	check;

	i = ft_strlen(av) - 1;
	printf("i = %d\n", i);
	while (i != 0)
	{
		printf("av = '%s'\n", av);
		while (av[i] == ' ' && i > 0)
			i--;
		printf("av[i] = '%c'\n", av[i]);
		while (ft_isdigit(av[i]) == 1 && i > 0)
			i--;
		if (!(av[i] == ' ' || ft_isdigit(av[i]) == 1))
		{
			printf("la\n");
			printf("%c\n", av[i]);
			return (-1);
		}
		check = ft_atoi2
		insertion(list, ft_atoi(&av[i]));
	}
	return (0);
}

int	recup_int(char **av, int ac, t_list *list)
{
	int	i;

	while (ac > 1)
	{
		i = recup_in_str(av[ac - 1], list);
		if (i == -1)
		{
			free_list(list);
			return (-1);
		}
		ac--;
	}
	print_list(list, list);
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
		while (ft_isdigit(av[j][i]) == 1 || av[j][i] == ' ')
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
