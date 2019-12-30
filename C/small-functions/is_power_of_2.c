#include <stdio.h>

int		is_power_of_2(unsigned int n)
{
	unsigned int  x;

	x = 2;
	while (x <= 4294967295 && x != 0 && x <= n)
	{
		printf("%u		||	%u\n", x, n);
		if (x == n)
			return (1);
		x = x * 2;
	}
	return (0);
}

int		main()
{
	int ret;

	ret = is_power_of_2(6);
	if (ret == 0)
		printf("NOT a power of 2");
	else
		printf("IS power of 2");
}
