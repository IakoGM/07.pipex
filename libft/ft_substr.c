/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:22:58 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/13 23:59:26 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
