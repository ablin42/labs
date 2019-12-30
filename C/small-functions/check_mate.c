#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dst, char *src)
{
	int		i = 0;
	int		j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	check(char **board, int ac)
{
	int 	iroi = 0;
	int		jroi = 0;
	int 	i = 0;
	int 	j;
	int 	oldi = 0;
	int		oldj = 0;

	(void)ac;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == 'K')
			{
				iroi = i;
				jroi = j;
			}			
			j++;
		}
		i++;
	}
	j = 0;
	while (j < ft_strlen(board[iroi]))
	{
		if (board[iroi][j] == 'R' || board[iroi][j] == 'Q')
		{
			oldj = j;
			while (board[iroi][j + 1] != '\0')
			{
				j++;
				if (board[iroi][j] == 'P' || board[iroi][j] == 'B')
				{
					j = oldj;
					break ;
				}
				else if (board[iroi][j] == 'K')
				{
					ft_putstr("Success");
					return ;
				}
			}
			while (j >= 1)
			{
				j--;
				if (board[iroi][j] == 'P' || board[iroi][j] == 'B')
				{
					j = oldj;
					break ;
				}
				else if (board[iroi][j] == 'K')
				{
					ft_putstr("Success");
					return ;
				}
			}
		}
		j++;			
	}	
	i = 0;
	while (board[i] != NULL)
	{
		if (board[i][jroi] == 'R' || board[i][jroi] == 'Q')
		{
			oldi = i;
			while (board[i + 1] != NULL)
			{
				i++;
				if (board[i][jroi] == 'P' || board[i][jroi] == 'B') 
				{
					i = oldi;
					break ;	
				}
				else if (board[i][jroi] == 'K')
				{
					ft_putstr("Success");
					return ;
				}
			}
			while (i >= 1)
			{
				i--;
				if (board[i][jroi] == 'P' || board[i][jroi] == 'B') 
				{
					i = oldi;
					break;
				}
				else if (board[i][jroi] == 'K')
				{
					ft_putstr("Success");
					return ;
				}
			}
		}
		i++;
	}
	i = 1;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == 'P')
			{
				if ((board[i - 1][j + 1] != '\0' && board[i - 1][j + 1] == 'K')
					   	|| (j >= 1 && board[i - 1][j - 1] == 'K'))
				{
					ft_putstr("Success");
					return ;
				}
			}
		j++;
		}
		i++;
	}
	i = 0;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == 'B' || board[i][j] == 'Q')
			{
				oldi = i;
				oldj = j;
				while (i >= 1 && j >= 1)
				{
					if (board[i][j] == 'K')
					{
						ft_putstr("Success");
						return ;
					}
					if (board[i][j] == 'P' || board[i][j] == 'R')
					{
						i = oldi;
						j = oldj;		
						break ;	
					}
					i--;
					j--;
				}
				i = oldi;
				j = oldj;
				while (i >= 1 && j < ft_strlen(board[i]))
				{
					if (board[i][j] == 'K')
					{
						ft_putstr("Success");
						return ;
					}
					if (board[i][j] == 'P' || board[i][j] == 'R')
					{
						i = oldi;
						j = oldj;
						break ;
					}
					i--;
					j++;	
				}
				i = oldi;
				j = oldj;
				while (board[i] != NULL && j >= 1)
				{
					if (board[i][j] == 'K')
					{
						ft_putstr("Success");
						return ;
					}
					if (board[i][j] == 'P' || board[i][j] == 'R')
					{
						i = oldi;
						j = oldj;
						break;
					}
					i++;
					j--;
				}
				i = oldi;
				j = oldj;	
				while (board[i] != NULL  && j < ft_strlen(board[i]))
				{
					if (board[i][j] == 'K')
					{
						ft_putstr("Success");
						return ;
					}
					if (board[i][j] == 'P' || board[i][j] == 'R')
					{
						i = oldi;
						j = oldj;
						break ;
					}
					i++;
					j++;
				}
				i = oldi;
				j = oldj;
			}
			j++;
		}
		i++;
	}
	ft_putstr("Fail");
}

void	ft_set(char **arg, int ac)
{
	char **board;
	int		i = 0;	
	
	board = (char **)malloc(sizeof(char *) * (ac));
	board[ac - 1] = NULL;
	while (i < ac - 1)
	{
		board[i] = (char *)malloc(sizeof(char *) * ft_strlen(arg[i + 1]));
		board[i] = ft_strcpy(board[i], arg[i + 1]);
		i++;
	}
	check(board, i);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		ft_set(av, ac);
	}
	ft_putchar('\n');
	return (0);
}
