/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:36:09 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/13 14:36:09 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t				i;
	size_t				dst_len;
	size_t				src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len || dstsize == 0)
		return (src_len + dstsize);
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dstsize - (dst_len + i) == 1 || src[i] == '\0')
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	dest[20] = "pqrstuvwxyz";
	char	dest_b[20] = "pqrstuvwxyz";
	printf("%lu\n", ft_strlcat(dest, "abcd", 20));
	printf("%lu\n", strlcat(dest_b, "abcd", 20));
	printf("%s$\n", dest);
	printf("%s$\n", dest_b);
}
*/