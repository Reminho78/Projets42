/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:08:15 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/28 11:08:17 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// While arguments are valid, we start to add them 
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer 
// value where we can make math operations.
// With stack new we create a new node for the current 
// argument without linking it to list.
// We make linking stage in ft_add_back call.
void	list_args(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

// This function frees the stack.
void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_atoi2(const char *str)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_error();
	return (sign * result);
}

// This function works and sorts the stacks
// in case of they are passed in between quotation
// marks. In this scenario, this function takes the
// string, and splits the numbers in order to create
// seperated integer number.
t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_lstadd_back(&a, ft_lstnew(j));
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (a);
}

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string. Call
//	  another function. <ft_sub_process>
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_lstadd_back(&a, ft_lstnew(j));
			i++;
		}
	}
	return (a);
}
