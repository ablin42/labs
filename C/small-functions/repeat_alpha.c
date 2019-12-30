/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:20:00 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:20:01 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 97 && av[1][i] <= 122)
				j = av[1][i] - 96;
			if (av[1][i] >= 65 && av[1][i] <= 90)
				j = av[1][i] - 64;
			while (j > 0)
			{
				ft_putchar(av[1][i]);
				j--;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
