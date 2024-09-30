/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:08:15 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 20:47:05 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cette fonction vide la stack
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

//Atoi plus strict
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

/* Cette fonction fonctionne dans le cas où il n'y aurait que 2 aruguments
avec plusieurs nombre entre guillemet dans le 2e.Dans ce scénario,
cette fonction prend la chaîne de caractères et sépare les nombres
afin de créer des nombres distincts. */
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

/* Cette fonction fait trois choses.
1. Elle vérifie si le nombre d'entrées est inférieur à 2.
2. Elle vérifie si le nombre d'entrées est égal à 2.
Si c'est le cas, cela signifie qu'il s'agit d'une chaîne entre guillemets.
Appeler une autre fonction. <ft_sub_process>
3. Elle vérifie si le nombre d'entrées est supérieur à 2.
Si c'est le cas, elle liste les arguments. */
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
