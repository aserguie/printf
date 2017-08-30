/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:35:25 by aserguie          #+#    #+#             */
/*   Updated: 2017/08/30 14:43:07 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include "../include/libft.h"
#include <stdio.h>

static char	buff[BUFF_SIZE];
static int	pos = 0;

void		print_buff(void)
{
	write(1, buff, pos);
	pos = 0;
}

void		to_buff(const char *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (pos == BUFF_SIZE)
		{
			print_buff();
			buff[0] = s[i];
			pos = 1;
		}
		else
			buff[pos++] = s[i];
		i++;
	}
}

static int	ft_parse(const char *str, int n, va_list *ap, t_parse *data)
{
	n += ft_attribute(str, n, data);
	n += ft_field(str, n, data);
	n += ft_precision(str, n, data);
	n += ft_modifier(str, n, data);
	n += ft_converter(str, n, data);
	data->length += ft_display(ap, *data);
	return (n);
}

void		ft_set(t_parse *data)
{
	data->attribute = 0;
	data->field = -1;
	data->precision = -1;
	data->modifier = 'a';
	data->converter = 'a';
	data->length = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_parse	data;

	if (format == NULL)
		return (0);
	i = 0;
	ft_set(&data);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			to_buff(&format[i], 1);
			data.length++;
			i++;
		}
		if (format[i] && format[i] == '%')
			i = ft_parse(format, i + 1, &ap, &data);
	}
	print_buff();
	va_end(ap);
	return (data.length);
}
/*
int	main()
{
	unsigned long i = 2147483648 - 1;
	char c = 'c';
	char *str = "Adrien";
	char *str2 = "Lyon";
	ft_printf("%d\n", i);
	ft_printf("%o\n", i);
	ft_printf("%x\n", i);
	ft_printf("%X\n", i);
	ft_printf("%u\n\n", i);
	printf("%d\n", i);
	printf("%o\n", i);
	printf("%x\n", i);
	printf("%X\n", i);
	printf("%u\n", i);
	return (0);
}
*/







