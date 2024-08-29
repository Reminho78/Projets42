/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:49 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/27 16:56:28 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function which checks the character if it is alphanumerical
int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}
