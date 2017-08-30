/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:38:35 by aserguie          #+#    #+#             */
/*   Updated: 2016/11/09 16:07:46 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	s = src;
	d = dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
