/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:04:40 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/26 13:17:52 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
