/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:27:41 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/08 09:34:04 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	slen;

	slen = ft_strlen(s);
	c = (char *) malloc((slen + 1) * sizeof(char));
	if (!c)
		return (NULL);
	ft_memcpy(c, s, slen);
	*(c + slen) = '\0';
	return (c);
}
