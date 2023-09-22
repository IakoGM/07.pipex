/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:08:33 by jakgonza          #+#    #+#             */
/*   Updated: 2022/09/03 11:34:09 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *) dst;
	b = (char *) src;
	if (!dst && !src)
		return ("\0");
	while (n-- > 0)
	{
		*a = *b;
		a++;
		b++;
	}
	return (dst);
}
