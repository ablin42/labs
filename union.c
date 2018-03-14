/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:20:18 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:20:19 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		i;
	int		save;
	int		lever;

	i = -1;
	save = 0;
	lever = 1;
	if (ac == 3)
	{
		while (av[1][save] != '\0')
		{
			while (i >= 0)
			{
				if (av[1][save] == av[1][i])
					lever = 0;
				i--;
			}
			if (lever == 1)
				ft_putchar(av[1][save]);
			save++;
			lever = 1;
			i = save - 1;
		}
		i = -1;
		save = 0;;
		while (av[2][save] != '\0')
		{
			while (i >= 0)
			{
				if (av[2][save] == av[2][i])
					lever = 0;
				i--;
			}
			i = 0;
			while (av[1][i] != '\0')
			{
				if (av[2][save] == av[1][i])
					lever = 0;
				i++;
			}
			if (lever == 1)
				ft_putchar(av[2][save]);
			save++;
			lever = 1;
			i = save - 1;
		}


	}
	ft_putchar('\n');
	return (0);
}
