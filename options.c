#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	options(char *str, char *line)
{
	int		i = 1;
	int		index = 6;
	char	letter = 'z';

	while (letter >= 'a')
	{
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] == letter)
				line[index] = '1';
			i++;
		}
		index++;
		if (index == 8 || index == 17 || index == 26)
			index++;
		letter--;
	}
}

int		error(char **arg, int ac)
{
	int		i = 1;
	int		j = 1;

	while (i < ac)
	{
		j = 1;
		while (arg[i][j] != '\0' && arg[i][0] == '-')
		{
			if (arg[i][j] < 'a' || arg[i][j] > 'z')
				return (-2);
			if (arg[i][j] == 'h')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i = 0;
	int		errn = 0;
	char	line[36];

	while (i < 35)
	{
		line[i] = '0';
		if (i == 8 || i == 17 || i == 26)
			line[i] = ' ';
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	i = 1;
	if (ac >= 2)
	{
		errn = error(av, ac);
		if (errn != 0)
		{
			if (errn == -1)
				ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
			if (errn == -2)
				ft_putstr("Invalid Option\n");
			return (0);
		}
		while (i < ac)
		{
			if (av[i][0] == '-')
				options(av[i], line);
			i++;
		}
		ft_putstr(line);
		return (0);
	}
	ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	return (0);
}
