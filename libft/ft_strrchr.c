/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:39:00 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:52:11 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*target;
	char			c_char;
	unsigned int	len;

	len = 0;
	target = (char *)s;
	c_char = (char)c;
	if (!(*s) && c != 0)
		return (0);
	while (*target)
	{
		target++;
		len++;
	}
	while (len != 0)
	{
		if (*(target) == c_char)
			return (target);
		if (len == 0)
			break ;
		len--;
		target--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[30] = "";
	printf("%s\n", ft_strrchr(str, 0));
    printf("%s\n", strrchr(str, 0));
	return 0;
}
*/