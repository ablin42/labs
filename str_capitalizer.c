/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:20:09 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:20:10 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void		ft_putstr(char *str)
{
	int		i;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		word;
	int		arg;

	i = 0;
	word = 1;
	arg = 1;
	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (arg != ac)
	{
		while (av[arg][i] != '\0')
		{
			if (i > 0)
			{
				if (av[arg][i - 1] == ' ' || av[arg][i - 1] == '\t')
					word = 1;
			}
			if (word == 1)
			{
				if (av[arg][i] >= 97 && av[arg][i] <= 122)
					av[arg][i] = av[arg][i] - 32;
			}
			if (word == 0 && av[arg][i] >= 65 && av[arg][i] <= 90)
				av[arg][i] = av[arg][i] + 32;
			i++;
			word = 0;
		}
		ft_putstr(av[arg]);
		write(1, "\n", 1);
		arg++;
		i = 0;
		word = 1;
	}
	return (0);
}
