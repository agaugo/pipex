/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:55:31 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/07 14:13:06 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_buffer;
	unsigned char	*src_buffer;

	dst_buffer = (unsigned char *) dst;
	src_buffer = (unsigned char *) src;
	if (dst_buffer != NULL || src_buffer != NULL)
	{
		while (n)
		{
			*(dst_buffer++) = *(src_buffer++);
			n--;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	str[17] = "wednesday my dude";
	char	str2[17] = "wednesday my dude";

	printf("%s\n", ft_memcpy(str, str + 2, sizeof(str)));
    printf("%s\n", memcpy(str2, str2 + 2, sizeof(str2)));
	return (0);
}
*/
