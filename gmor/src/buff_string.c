/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:44:09 by gmordele          #+#    #+#             */
/*   Updated: 2017/03/20 02:12:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	null_strlen(char *s)
{
	int l;

	l = 0;
	if (s == NULL)
		return (0);
	while (*s++)
		++l;
	return (l);
}

int			buff_string(char **buff, char *str, t_conv_spec cs)
{
	t_buff_info	bi;

	if (str == NULL)
		return (buff_string(buff, "(null)", cs));
	bi.len = null_strlen(str);
	bi.len = (cs.precision >= 0 &&
			cs.precision < bi.len) ? cs.precision : bi.len;
	bi.total_size = cs.min_field > bi.len ? cs.min_field : bi.len;
	*buff = malloc(bi.total_size);
	if (cs.flags & MINUS)
	{
		bi.start = 0;
		while (bi.start < bi.len)
			(*buff)[bi.start++] = *(str++);
		while (bi.start < bi.total_size)
			(*buff)[bi.start++] = ' ';
		return (bi.total_size);
	}
	bi.start = bi.total_size - bi.len;
	while (bi.start < bi.total_size)
		(*buff)[bi.start++] = *(str++);
	bi.start = bi.total_size - bi.len;
	while (--bi.start >= 0)
		(*buff)[bi.start] = (cs.flags & ZERO) ? '0' : ' ';
	return (bi.total_size);
}
