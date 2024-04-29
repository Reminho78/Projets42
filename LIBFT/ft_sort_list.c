#include <stdlib.h>
#include "libft.h"

t_list	*sort_list(t_list *lst, int (*cmp)(void*, void*))
{
	void*	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->content, lst->next->content)) == 0)
		{
			swap = lst->content;
			lst->content = lst->next->content;
			lst->next->content = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}