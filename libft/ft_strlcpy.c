/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:32:47 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 10:30:01 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while ((dstsize - 1) != '\0' && *src)
		{
			*(dst++) = *(src++);
			dstsize--;
			i++;
		}
		*(dst) = '\0';
		src -= i;
		i = 0;
	}
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
/*
int	main(void)
{
	char test[30] = "broski dd";
	char test2[30] = "broski dd";
	printf("%lu\n", strlcpy(test, "alpha vet", 5));
	printf("%s\n", test);
	printf("%lu\n", ft_strlcpy(test2, "alpha vet", 5));
	printf("%s\n", test2);
	return (0);
}
*/