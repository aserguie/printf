/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:15:01 by aserguie          #+#    #+#             */
/*   Updated: 2017/04/24 16:18:47 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strdup(const char *s1)
{
	char		*tab;
	size_t		i;

	tab = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i = i + 1;
	}
	tab[i] = '\0';
	return (tab);
}
