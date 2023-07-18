/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 19:32:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/22 19:32:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chars(int n)
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

static char	*edge_cases(char *buffer)
{
	*buffer = '0';
	*(buffer + 1) = '\0';
	return (buffer);
}

static char	*ft_itoa_two(int n, char *buffer, int ri, int i)
{
	if (n == 0)
		return (edge_cases(buffer));
	if (n < 0)
	{
		buffer[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		buffer[i] = n % 10 + '0';
		n -= n % 10;
		n = n / 10;
		i--;
	}
	buffer[ri] = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char			*buffer;
	int				ri;
	int				i;

	ri = chars(n);
	i = ri - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buffer = malloc(sizeof(char) * chars(n) + 1);
	if (!buffer)
		return (0);
	return (ft_itoa_two(n, buffer, ri, i));
}
/*
int main(void)
{
    printf("$%s$\n", ft_itoa(-2147483648));
    return 0;
}
*/