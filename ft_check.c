/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:07:10 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/24 16:45:19 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check(const char *str, int n,  char c)
{
	if (c == 'a')
		return (str[n] == '#' || str[n] == '0' || str[n] == '-'
				|| str[n] == '+' || str[n] == ' ');
	if (c == 'f' || c == 'p')
		return(ft_isdigit(str[n]));
	if (c == 'm')
		return (str[n] == 'h' || str[n] == 'l' || str[n] == 'j'
				|| str[n] == 'z');
	if (c == 'c')
		return (str[n] == 's' || str[n] == 'S' || str[n] == 'p'
				|| str[n] == 'd' || str[n] == 'D' || str[n] == 'i'
				|| str[n] == 'o' || str[n] == 'O' || str[n] == 'u'
				|| str[n] == 'U' || str[n] == 'x' || str[n] == 'X'
				|| str[n] == 'c' || str[n] == 'C');
	return (0);
}
