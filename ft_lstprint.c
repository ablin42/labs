
#include "libft.h"

void	ft_printlst(t_list lst)
{
	while (lst != NULL)
	{
		ft_putstr(lst->content);
		lst = lst->next;
	}
	
}
