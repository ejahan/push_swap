/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:55:46 by elisa             #+#    #+#             */
/*   Updated: 2021/11/15 23:31:09 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_element
{
	int					nbr;
	struct s_element	*next;
}				t_element;

typedef struct s_list
{
	t_element	*first;
}				t_list;

typedef struct s_push_swap
{
	int		ac;
	int		ac_b;
	int		count;
	int		min_range;
	int		min;
	int		med;
	int		first_med;
	int		rotate;
	char	**opti;
	t_list	*a;
	t_list	*b;
}				t_push_swap;

int		recup_int(char **av, int ac, t_list *list);
int		check_int(char **av, int ac);
int		free_list(t_list *list);
t_list	*init(int i);
int		insertion(t_list *list, int new_nbr);
int		delete(t_list *list);
int		print_list(t_list *list, t_list *b);
long	ft_atoi2(const char *str);
void	rotate_one(t_push_swap *ps, t_list *l, t_element **e, char *s);
void	rotate_both(t_push_swap *ps);
void	rev_one(t_push_swap *ps, t_list *l, t_element **e, char *s);
void	rev_rotate_both(t_push_swap *ps);
void	push_b(t_push_swap *ps);
void	push_a(t_push_swap *ps);
void	swap_one(t_push_swap *ps, t_list *list, char *s);
void	swap_both(t_push_swap *ps);
void	sort_three(t_push_swap *ps);
void	sort_five(t_push_swap *push);
void	sort_hundred(t_push_swap *ps, char c, int ac);
int		median_three(t_push_swap *ps, char c);
int		median_four(t_push_swap *ps, char c);
int		check_if_sort(t_push_swap *ps);
int		find_max_len(t_list *list, int ac);
int		find_min_len(t_list *list, int ac);
int		find_max(t_list *list);
int		find_min(t_list *list);
int		find_min_next_len(t_list *list, int len, int old);
int		find_max_next_len(t_list *list, int len, int old);
int		find_med(t_list *list, int ac);
int		median_a(t_push_swap *ps, int ac);
int		median_b(t_push_swap *ps, int ac);
void	find_min_five(t_push_swap *ps, t_list *list);
int		median_four_a(t_push_swap *ps);
int		median_four_b(t_push_swap *ps);
void	median_three_a(t_push_swap *ps);
int		malloc_opti(t_push_swap *ps, char *str);
void	s_rotate_one(t_push_swap *ps, t_list *list, t_element **elem, char *s);
void	s_rev_one(t_push_swap *ps, t_list *list, t_element **elem, char *s);
void	s_push_a(t_push_swap *ps);
void	s_push_b(t_push_swap *ps);
void	s_swap_one(t_push_swap *ps, t_list *list, char *s);
void	print_ope(t_push_swap *ps);
int		print_push_b(t_push_swap *ps, int i);
int		print_push_a(t_push_swap *ps, int i);

#endif
