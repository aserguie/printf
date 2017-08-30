/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:10:02 by aserguie          #+#    #+#             */
/*   Updated: 2017/06/20 17:23:28 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_display_str(va_list ap, t_parse *data)
{
	char *s;

	s = NULL;
	s = ft_strdup(va_arg(ap, const char*));
	data->length += ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (0);
}

int		ft_display_nbr(va_list ap, t_parse *data)
{
	char *s;

	s = NULL;
	if (data->converter == 'i' || data->converter == 'd'
			|| data->converter == 'D')
		s = ft_itoa_base(va_arg(ap, int), 10);
	else if (data->converter == 'o' || data->converter == 'O')
		s = ft_itoa_base(va_arg(ap, unsigned int), 8);
	else if (data->converter == 'x' || data->converter == 'X')
	{
		s = ft_itoa_base(va_arg(ap, unsigned int), 16);
		if (data->converter == 'x')
			s = ft_str_tolower(s);
	}
	else if (data->converter == 'u' || data->converter == 'U')
		s = ft_itoa_base(va_arg(ap, unsigned int), 10);
	data->length += ft_strlen(s);
	ft_putstr(s);
	free (s);
	return (0);
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

void	ft_display(va_list ap, t_parse *data)
{
	if (data->converter == 's' || data->converter == 'S')
		ft_display_str(ap, data);
	if (data->converter == 'd' || data->converter == 'D'
			|| data->converter == 'i' || data->converter == 'o'
			|| data->converter == 'O' || data->converter == 'u'
			|| data->converter == 'U' || data->converter =='x'
			|| data->converter == 'X')
		ft_display_nbr(ap, data);
	if (data->converter == 'c' || data->converter == 'C'
			|| data->converter == '%')
		ft_display_char(ap, data);
}













