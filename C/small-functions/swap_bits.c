/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:19:20 by ablin             #+#    #+#             */
/*   Updated: 2018/03/12 23:19:21 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	if (octet >= 16)
		return (octet>>4);
	return (octet<<4);
}

int		main(int ac, char **av)
{
	unsigned char a;

	a = 80;
	printf("a = %d\n", a);
	printf("a = %d\n", swap_bits(a));
	return (0);
}
