/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:10:02 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/30 18:47:10 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_display(va_list ap, t_parse *data)
{
	if (data->converter == 's' || data->converter == 'S')
		ft_putstr(va_arg(ap, const char *));
	if (data->converter == 'd' || data->converter == 'D')
		ft_putnbr(va_arg(ap, int));
	if (data->converter == 'c' || data->converter == 'C')
		ft_putchar(va_arg(ap, int));
}
