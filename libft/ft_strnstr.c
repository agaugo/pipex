/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 16:45:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/14 16:45:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	c;
	int				size;

	i = 0;
	c = 0;
	size = (int)len;
	if (needle[c] == '\0')
		return ((char *)haystack);
	size += 1;
	while (size-- != 1 && haystack[i] != '\0')
	{
		while (haystack[i + c] == needle[c] && needle[c] != '\0' && size--)
			c++;
		if (haystack[i] == needle[0] && needle[c] == '\0')
			return ((char *)haystack + i);
		size += c;
		i++;
		c = 0;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", ft_strnstr("alphabet", "alpha", -1));
	printf("%s\n", strnstr("alphabet", "alpha", -1));
	return (0);
}
*/