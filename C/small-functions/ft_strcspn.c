#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t nb;
	int		i;

	nb = 0;
	while (*s1 != '\0')
	{
		i = 0;
		while (s2[i] != '\0')
		{
			if (*s1 == s2[i])
				return (nb);
			i++;
		}
		s1++;
		nb++;
	}
	return (nb);
}

int		main(int ac, char **av)
{
	printf("%lu\n", ft_strcspn(av[1], av[2]));
	printf("%lu\n", strcspn(av[1], av[2]));
	return (0);
}
