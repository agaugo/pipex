/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 16:16:21 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 16:16:23 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;
	int				count;

	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	count = (int)n;
	while (count)
	{
		if (*s1_cast > *s2_cast)
			return (*s1_cast - *s2_cast);
		if (*s1_cast < *s2_cast)
			return (*s1_cast - *s2_cast);
		s1_cast++;
		s2_cast++;
		count--;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_memcmp("dude", "dudeX", 10));
	printf("%d\n", memcmp("dude", "dudeX", 10));
	return (0);
}
*/