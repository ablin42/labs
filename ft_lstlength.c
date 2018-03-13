
#include "libft.h"

int		ft_lstlength(t_list *lst)
{
	int		i;

	i = 0;
	if (li == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
