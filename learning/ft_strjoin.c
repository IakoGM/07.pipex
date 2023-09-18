/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/18 13:46:20 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <string.h>

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
	strncpy(c, s1, s1len + 1);
	strncat(c, s2, s1len + s2len + 1);
	return (c);
}