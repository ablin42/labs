/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:19:48 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:19:52 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/ablin/Projets/Libft/libft.h"

int		main(int ac, char **av)
{
	int i;
	int nb;

	i = 1;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(nb * i);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
