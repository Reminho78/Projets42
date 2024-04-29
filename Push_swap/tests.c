#include "push_swap.h"

int	check_double(int ac, char **a, f_list **List)
{
	int i;

	i = 3;
	while(i < ac)
	{
		while(1)
		{
			f_list *current = *List;
			if(atoi(a[i]) == current->value)
				return 1;
			current = current->next;
			if (current == *List)
				break;
		}
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{


	return 0;
}