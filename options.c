#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}

}

char	*options(char *str, char *arr)
{
	int	i;
	char letter;
	int index;

	index = 6;
	letter = 'z';
	while (letter >= 'a')
	{
		i = 0;
		if (arr[index] == ' ')
			index++;
		while (str[i] != '\0')
		{
			if (str[i] == letter)
			{
				arr[index] = '1';
				break;
			}
			i++;
		}	
		letter--;
		index++;
	}
	return (arr);	
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		verif(char **arg)
{
	int		i;
	int		j;

	i = 1;
	while (arg[i] != NULL)
	{
		j = 1;
		if (ft_strlen(arg[i]) <= 1)
			return (0);
		while (arg[i][j] != '\0')
		{
			if (arg[i][0] != '-')
				break;
			if (arg[i][0] == '-' && arg[i][1] >= '0' && arg[i][1] <= '9')
				break;
			if (arg[i][j] < 'a' || arg[i][j] > 'z')
				return (-1);
			if (arg[i][j] == 'h')
				return (-2);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char arr[36];
	int i;
	int	j;
	int	err;

	j = 0;
	i = 1;
	if (ac < 2)
	{
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
		return (0);
	}
	if ((err = verif(av)) < 0)
	{
		if (err == -1)
			ft_putstr("Invalid Option\n");
		if (err == -2)
			ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
		return (0);
	}
	while (j <= 35)
	{
		arr[j] = '0';
		if (j == 8 || j == 17 || j == 26)
			arr[j] = ' ';
		j++;
	}
	arr[35] = '\0';
	while (i < ac)
	{
		if (av[i][0] == '-')
			options(av[i], arr);
			i++;
	}
	ft_putstr(arr);
	ft_putchar('\n');
	return (0);
}
