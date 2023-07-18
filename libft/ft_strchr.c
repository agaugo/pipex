/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:17:40 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:38:35 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			*target;
	char			c_char;

	target = (char *)s;
	c_char = (char)c;
	while (*target)
	{
		if (*target == c_char)
			return (target);
		target++;
	}
	if (c_char == '\0')
		return (target);
	else
		return (0);
}
/*
int	main(void)
{
	char str[5] = "abcde";
	printf("%s", ft_strchr(str, 'c'));
	return 0;
}
*/
