/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:49:36 by gmordele          #+#    #+#             */
/*   Updated: 2017/02/10 15:50:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int		buff_char(char **buff, char c, t_conv_spec cs)
{
	int	i;

	if (cs.min_field <= 1)
	{
		*buff = malloc(1);
		(*buff)[0] = c;
		return (1);
	}
	*buff = malloc(cs.min_field);
	i = cs.min_field - 1;
	if (cs.flags & MINUS)
	{
		(*buff)[0] = c;
		while (i != 0)
			(*buff)[i--] = ' ';
	}
	else
	{
		(*buff)[i] = c;
		while (--i >= 0)
			(*buff)[i] = (cs.flags & ZERO) ? '0' : ' ';
	}
	return (cs.min_field);
}
