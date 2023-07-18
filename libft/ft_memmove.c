/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:34:44 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/07 16:18:10 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buffer;
	unsigned char	*src_buffer;

	dst_buffer = (unsigned char *)dst;
	src_buffer = (unsigned char *)src;
	if (src_buffer == NULL && dst_buffer == NULL && len != '\0')
		return (0);
	else if ((src_buffer < dst_buffer) && (dst_buffer < src_buffer + len))
	{
		while (len)
		{
			len--;
			*(dst_buffer + len) = *(src_buffer + len);
		}
	}
	else
	{
		while (len)
		{
			*(dst_buffer++) = *(src_buffer++);
			len--;
		}
	}
	return (dst);
}
