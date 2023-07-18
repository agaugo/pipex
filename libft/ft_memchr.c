/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:17:57 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 16:30:23 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_char;
	unsigned char	*buffer;
	size_t			i;

	c_char = (unsigned char)c;
	buffer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*buffer == c_char)
			return (buffer);
		buffer++;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[5] = "hello";
	printf("%s", ft_memchr(str, 'l', 5));
	return 0;
}
*/
