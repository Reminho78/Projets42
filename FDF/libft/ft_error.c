/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:37:38 by rcorroy       #+#    #+#             */
/*   Updated: 2024/08/28 10:58:23 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Here an error message is being printed out
void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
