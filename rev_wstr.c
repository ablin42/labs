/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:19:10 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:19:12 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int		count_words(char *str)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			words++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		if (str[i] == ' ')
			i++;
	}
	return (words);
}

char	*fill(char **board, int words, char *str)
{
	char *rstr;
	int		j;
	int		k;

	k = 0;
	words--;
	rstr = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (words >= 0)
	{
		j = 0;
		while (board[words][j] != '\0')
		{
			rstr[k] = board[words][j];
			j++;
			k++;
		}
		rstr[k] = ' ';
		k++;
		words--;
	}
	rstr[ft_strlen(str)] = '\0';
	return (rstr);
}

char	**board(char *str, int words)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (words + 1));
	while (i < words)
	{
		k = 0;
		tmp[i] = (char *)malloc(sizeof(char *) * (ft_strlen(str) + 1));
		while (str[j] != '\0' && str[j] != ' ')
		{
			tmp[i][k] = str[j];
			j++;
			k++;
		}
		i++;
		j++;
	}
	return (tmp);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(fill(board(av[1], count_words(av[1])), count_words(av[1]), av[1]));
	write(1, "\n", 1);
	return (0);
}
