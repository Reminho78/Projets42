/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:04:40 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/02 17:39:12 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Elle convertit une chaîne de caractères (string) en un entier (int). 

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

// int main(int ac, char **av) {
//     (void) ac;
//     char *str = " -1234ab567";
//     printf("%d\n", ft_atoi(av[1]));
//     printf("%d\n", atoi(str));
//     return 0;
// }