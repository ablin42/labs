#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{	
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_type(char c)
{
	if (c == '}' || c == '{')
		return (1);
	if (c == ']' || c == '[')
		return (2);
	if (c == ')' || c == '(')
		return (3);
	return (0);
}

int	ft_count(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '}' || str[i] == ')' || str[i] == ']')
			j++;
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
			k++;
		i++;
	}
	if (k != j)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}
void	brackets(char *str)
{
	int		type;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (ft_count(str) == -1)
		return ;
	while (i >= 0)
	{
		if (str[i] == '}' || str[i] == ')' || str[i] == ']')
		{
			type = ft_type(str[i]);
			j = i;
		}
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			if (type != ft_type(str[i]))
			{
				write(1, "Error\n", 6);
				return ;
			}
			else if (type == ft_type(str[i]))
			{
				str[i] = 'x';
				while (str[i] != '\0' && (str[i] != '}' || str[i] != ')' || str[i] != ']'))
					i++;
				str[j] = 'x';
			}
		}
		i--;
	}
	write(1, "OK\n", 3);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (i < ac)
	{
		brackets(av[i]);
		i++;
	}
}
