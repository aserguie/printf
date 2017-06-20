/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:39:07 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/31 16:55:53 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_attribute(const char *str, int n, t_parse *data)
{
	int i;

	i = 0;
	data->attribute = 0;
	while (ft_check(str, n + i, 'a'))
	{
		if (str[n + i] == '#')
			data->attribute |= SHARP;
		else if (str[n + i] == '0')
			data->attribute |= ZERO;
		else if (str[n + i] == '-')
			data->attribute |= MINUS;
		else if (str[n + i] == '+')
			data->attribute |= PLUS;
		else if (str[n + i] == ' ')
			data->attribute |= SPACE;
		i++;
	}
	return (i);
}

int		ft_field(const char *str, int n, t_parse *data)
{
	int i;

	i = 0;
	data->field = ft_atoi(&str[n]);
	while (ft_check(str, n + i, 'f'))
		i++;
	return (i);
}

int		ft_precision(const char *str, int n, t_parse *data)
{
	int i;

	i = 0;
	if (str[n] == '.')
		i++;
	if (i == 1)
	{
		data->precision = ft_atoi(&str[n + i]);
		while (ft_check(str, n + i, 'p'))
			i++;
	}
	return (i);
}

int		ft_modifier(const char *str, int n, t_parse *data)
{
	int i;

	i = 0;
	data->modifier = 'a';
	while (ft_check(str, n + i, 'm'))
	{
		if (data->modifier == 'a')
			data->modifier = str[n + i];
		else if (data->modifier == 'h' && str[n + i] == 'h')
			data->modifier = 'H';
		else if (data->modifier == 'l' && str[n + i] == 'l')
			data->modifier = 'L';
		i++;
	}
	return (i);
}

int		ft_converter(const char *str, int n, t_parse *data)
{
	int i;

	i = 0;
	if (!ft_check(str, n + i, 'c'))
		return (0);
	data->converter = (char)str[n + i];
	i++;
	return (i);
}
