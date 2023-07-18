/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:41:52 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/20 13:41:53 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		size;

	i = 0;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[len]))
		len--;
	size = len - i + 1;
	if (size < 0)
		return (ft_strdup(""));
	return (ft_substr(s1, i, size));
}
/*
int	main(void) 
{
	printf("$%s$\n", ft_strtrim("", ""));
	return (0);
}
*/