/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:06:22 by gmordele          #+#    #+#             */
/*   Updated: 2017/08/30 14:25:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static char	g_buff[BUF_SIZE_PF];
static int	g_pos = 0;

void	to_buff(const char *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (g_pos == BUF_SIZE_PF)
		{
			flush_buff(g_pos);
			g_buff[0] = s[i];
			g_pos = 1;
		}
		else
			g_buff[g_pos++] = s[i];
		++i;
	}
}

void	flush_buff(void)
{
	write(1, g_buff, g_pos);
	g_pos = 0;
}
