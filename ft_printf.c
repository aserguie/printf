/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:35:25 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/30 19:14:26 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "./libft/libft.h"
#include <stdio.h>

static	int		ft_parse(const char *str, int n, va_list ap, t_parse *data)
{
	n += ft_attribute(str, n, data);
//	printf("att = %s\n", data->attribute);
	n += ft_field(str, n, data);
//	printf("field = %d\n", data->field);
	n += ft_precision(str, n, data);
//	printf("pre = %d\n", data->precision);
	n += ft_modifier(str, n, data);
//	printf("mod = %s\n", data->modifier);
/*	if (ft_converter(str, n, data))
		n++;
	else
		ft_putstr("Error\n");*/
	n += ft_converter(str, n, data);
	printf("conv = %c\n", data->converter);
//	printf("n = %d\n", n);
	ft_display(ap, data);

	return (n);
}
void			ft_free_n_reset(t_parse *data)
{
	if (data->attribute)
		ft_strdel(&(data->attribute));
	if (data->modifier)
		ft_strdel(&(data->modifier));
	data->field = -1;
	data->precision = -1;
	data->converter = 'a';
}

void			ft_set(t_parse *data)
{
	data->attribute = NULL;
	data->field = -1;
	data->precision = -1;
	data->modifier = NULL;
	data->converter = 'a';
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*s;
	t_parse	data;

	i = 0;
	ft_set(&data);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] && format[i] == '%')
		{
			i = ft_parse(format, i + 1, ap, &data);
			ft_free_n_reset(&data);
		}
	}
	va_end(ap);
	return (0);
}

int	main()
{
	int i = 26;
	char c = 'c';
	char *str = "Adrien";
	char *str2 = "Lyon";
	ft_printf("ab%");
	return (0);
}


