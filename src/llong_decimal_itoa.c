/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 12:30:52 by aserguie          #+#    #+#             */
/*   Updated: 2017/08/30 14:20:03 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

static int		get_decimal_len(long long n)
{
	int len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static void		fill_number(char *buff, long long n, int start, int len)
{
	if (n < 0)
	{
		buff[start--] = -(n % 10) + '0';
		n /= -10;
		--len;
	}
	while (len--)
	{
		buff[start--] = n % 10 + '0';
		n /= 10;
	}
}

static void		fill_flags(char *buff, long long n, t_buff_nfo bi, t_parse data)
{
	int	pos_sign;

	pos_sign = bi.start - bi.len;
	if (data.precision < 0 && data.attribute & ZERO
			&& !(data.attribute & MINUS))
		while (data.field > bi.len + bi.add)
		{
			buff[bi.start - bi.len++] = '0';
			--pos_sign;
		}
	else if (data.field > bi.len + bi.add && !(data.attribute & MINUS))
		while (data.field-- > bi.len + bi.add)
			buff[bi.start - data.field] = ' ';
	else if (data.attribute & MINUS)
		while (++bi.start < data.field)
			buff[bi.start] = ' ';
	if (bi.add)
	{
		if (n < 0)
			buff[pos_sign] = '-';
		else
			buff[pos_sign] = data.attribute & PLUS ? '+' : ' ';
	}
}


int				llong_decimal_itoa(char **buff, long long n, t_parse data)
{
	t_buff_nfo bi;

	bi.add = (n < 0 || data.attribute & (SPACE | PLUS)) ? 1 : 0;
	bi.len = get_decimal_len(n);
	bi.len = bi.len < data.precision ? data.precision : bi.len;
	if (!n && !data.precision)
		bi.len = 0;
	if (bi.len + bi.add > data.field)
		bi.total_size = bi.len + bi.add;
	else
		bi.total_size = data.field;
	*buff = malloc(bi.total_size);
	if (buff == NULL)
		return (-1);
	bi.start = (data.attribute & MINUS) ? bi.len + bi.add - 1 :
		bi.total_size - 1;
	fill_number(*buff, n, bi.start, bi.len);
	fill_flags(*buff, n, bi, data);
	return (bi.total_size);
}
