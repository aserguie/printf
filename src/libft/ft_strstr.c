/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:51:18 by aserguie          #+#    #+#             */
/*   Updated: 2016/11/09 16:23:57 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (str);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] != '\0') && (big[i + j] == little[j]))
				j++;
			if (little[j] == '\0')
				return (str + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
