/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:27:16 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/09 10:55:52 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	c = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, s1len + 1);
	ft_strlcat(c, s2, s1len + s2len + 1);
	return (c);
}
