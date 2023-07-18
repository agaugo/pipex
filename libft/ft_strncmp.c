/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:56:15 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 16:17:24 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	i = 0;
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (s1_cast[i] != '\0' && i < n)
	{
		if (s1_cast[i] > s2_cast[i])
			return (1);
		else if (s1_cast[i] < s2_cast[i])
			return (-1);
		else
			i++;
	}
	if (i != n && s2[i] != '\0')
		return (-1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_strncmp("1234", "1235", 4));
    printf("%d\n", strncmp("1234", "1235", 4));
	return 0;
}
*/