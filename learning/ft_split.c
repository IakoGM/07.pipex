/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:45:04 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/18 12:09:36 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > slen)
		len = slen;
	c = (char *) malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	if (start > slen)
	{
		*c = '\0';
		return (c);
	}
	while (s[i + start] && len--)
	{
		c[i] = s[i + start];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int	countwords(const char *s, char c)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (*s)
	{
		if (*s != c && checker == 0)
		{
			checker = 1;
			i++;
		}
		else if (*s == c)
			checker = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		slen;
	int		i;
	int		j;

	i = -1;
	j = 0;
	start = i;
	slen = ft_strlen(s);
	str = (char **) malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (slen >= ++i)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == slen))
		{
			str[j++] = ft_substr(s, start, i - start);
			start = -1;
		}
	}
	str[j] = NULL;
	return (str);
}