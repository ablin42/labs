#include <stdio.h>

char    *ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		if (i <= j)
			break;
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
		}
	return (str);
}

int main(int ac, char **av)
{
	printf("Phrase initiale: [%s]\n", av[1]);
	printf("Phrase inversee: [%s]\n", ft_strrev(av[1]));
}
