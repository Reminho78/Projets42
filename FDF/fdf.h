/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:32:54 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/29 14:52:39 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_point {
    int x, y, z;
} t_point;

typedef struct s_map {
    int width, height;
    t_point **points;
} t_map;

#endif