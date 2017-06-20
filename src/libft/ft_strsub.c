/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:16:56 by aserguie          #+#    #+#             */
/*   Updated: 2017/04/24 16:17:04 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL || s == NULL)
		return (NULL);
	while (i != len)
	{
		str[i] = s[start];
		i = i + 1;
		start = start + 1;
	}
	str[i] = '\0';
	return (str);
}
