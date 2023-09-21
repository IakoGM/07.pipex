/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:15:53 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/06 15:16:18 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	strlength;
	size_t	dstlen;
	size_t	originaldstlen;

	strlength = ft_strlen(dst);
	dstlen = ft_strlen(src);
	originaldstlen = strlength;
	if (dstsize == 0 || dstsize <= strlength)
		return (dstsize + dstlen);
	while (*src && strlength < dstsize - 1)
	{
		*(dst + strlength) = *src++;
		strlength++;
	}
	*(dst + strlength) = '\0';
	return (originaldstlen + dstlen);
}
