/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:39:07 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/30 19:09:52 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_attribute(const char *str, int n, t_parse *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (data->attribute)
		ft_strdel(&(data->attribute));
	while (ft_check(str, n + i, 'a'))
		i++;
	if (!(data->attribute = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (j < i)
	{
		data->attribute[j] = str[n + j];
		j++;
	}
	data->attribute[j] = '\0';
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
	int j;

	i = 0;
	j = 0;
	while (ft_check(str, n + i, 'm'))
		i++;
	if ((data->modifier = (char*)malloc(sizeof(char) * (i + 1))))
	{
		while (j < i)
		{
			data->modifier[j] = str[n + j];
			j++;
		}
		data->modifier[j] = '\0';
	return (i);
	}
	return (0);
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























