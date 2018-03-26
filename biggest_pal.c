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

void	biggest(char *str)
{
	int i = 0;
	int start;
	int end = 0;
	int length;
	int oldlength;
	char cpy[ft_strlen(str) + 1];
	int j = 0;
	int start2;
	int boucle = 0;

	while (i < ft_strlen(str))
	{
		cpy[i] = '0';
		i++;
	}
	cpy[i] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		length = 1;
		if (end == 0 || start >= end - 1 || boucle == 1)
		{
			i++;
			start = i;
			end = ft_strlen(str);
			boucle = 0;
		}
		start2 = start;
	//	printf("/");
		while (str[start] == str[end - 1] && start <= end - 1)
		{
			boucle = 1;
		//	printf("[%c][%c] | [%d][%d] \n", str[start], str[end - 1], start, end );
			start++;
			end--;
			length++;
			if (start + 1 == end || start == end)
			{
				length = start - start2;
			//	printf("{%d}{%d}\n", start, length);
				while (j <= end + 1 && length >= oldlength)
				{
					cpy[j] = str[start2];
					j++;
					start2++;
				}
				oldlength = length;
				cpy[j] = '\0';
			//	printf("%s\n", cpy);
				boucle = 2;
				break ;
			}
		}
		start++;////
		end--;////
	}
		ft_putstr(cpy);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		biggest(av[1]);
	}
	write (1, "\n", 1);
	return (0);
}
