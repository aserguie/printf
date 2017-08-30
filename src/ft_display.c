/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:10:02 by aserguie          #+#    #+#             */
/*   Updated: 2017/08/30 13:52:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_display_str(va_list *ap, t_parse data)
{
	char *s;

	s = NULL;
	s = ft_strdup(va_arg(*ap, const char*));
	data.length += ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (0);
}

int		handle_decimal(char converter, va_list *ap, t_parse data)
{
	char	*buff;
	int		len;

	buff = NULL;
	if (data.modifier == 'l' || converter == 'D')
		len = long_decimal_itoa(&buff, va_arg(*ap, long), data);
	else if (data.modifier == 0)
		len = decimal_itoa(&buff, va_arg(*ap, int), data);
	else if (data.modifier == 'H')
		len = decimal_itoa(&buff, (signed char)va_arg(*ap, int), data);
	else if (data.modifier == 'h')
		len = decimal_itoa(&buff, (short)va_arg(*ap, int), data);
	else if (data.modifier == 'L')
		len = llong_decimal_itoa(&buff, va_arg(*ap, long long), data);
	else if (data.modifier == 'j')
		len = llong_decimal_itoa(&buff, va_arg(*ap, intmax_t), data);
	else if (data.modifier == 'z')
		len = llong_decimal_itoa(&buff, va_arg(*ap, size_t), data);
	if (buff != NULL)
	{
		to_buff(buff, len);
		free(buff);
	}
	return (buff != NULL ? len : 0);
}

int		ft_display_char(va_list ap, t_parse *data)
{
	if (data->converter == '%')
		ft_putchar('%');
	else
		ft_putchar(va_arg(ap, int));
	(data->length)++;
	return (0);
}

int		ft_display(va_list *ap, t_parse data)
{
	if (data.converter == 'S' || (data.converter == 's'))
		return (1/*handle_str(data.converter, ap, data)*/);
	else if (data.converter == 'd' || data.converter == 'D'
			|| data.converter == 'i')
		return (handle_decimal(data.converter, ap, data));
	else if (data.converter == 'o' || data.converter == 'O'
			|| data.converter == 'u' || data.converter == 'U'
			|| data.converter == 'x' || data.converter == 'X'
			|| data.converter == 'p' || data.converter == 'b')
		return (1/*handle_unsigned(data.converter, ap, data)*/);
	else if (data.converter == 'c' || data.converter == 'C'
			|| data.converter == '%')
		return (1/*handle_char(data.converter, ap, data)*/);
	if (data.converter == '\0')
		return (1);
	to_buff(&data.converter, 1);
	return (2);
}
