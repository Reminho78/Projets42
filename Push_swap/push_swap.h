/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:59:10 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/26 17:28:15 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

	typedef struct p_list
{
	int value;
	int index;
	struct p_list *prev;
	struct p_list *next;
}	f_list;

f_list *createNode(int a , int index);

void pushBack(f_list **head, char *a , int index);
void pushFront(f_list **head, char *a , int index);
void printLists(f_list *a, f_list *b);

 
#endif