/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:36:22 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 10:49:55 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	chars(int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nb += 1;
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	output[12];
	int		i;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	i = chars(n);
	if (n < 0)
	{
		n *= -1;
		output[0] = '-';
	}
	output[i] = '\0';
	i--;
	while (i >= 0 && output[i] != '-')
	{
		output[i] = n % 10 + '0';
		n -= n % 10;
		n = n / 10;
		i--;
	}
	ft_putstr_fd (output, fd);
}
/*
int main(void)
{
    ft_putnbr_fd(-348, 1);
    return 0;
}
*/