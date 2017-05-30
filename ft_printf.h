/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:54:21 by aserguie          #+#    #+#             */
/*   Updated: 2017/05/30 18:22:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "./libft/libft.h"
#include <stdarg.h>

typedef	struct	s_parse
{
	char	*attribute;
	int		field;
	int		precision;
	char	*modifier;
	char	converter;
	int		length;
}				t_parse;

int				ft_printf(const char *format, ...);
int				ft_attribute(const char *str, int n, t_parse *data);
int				ft_field(const char *str, int n, t_parse *data);
int				ft_precision(const char *str, int n, t_parse *data);
int				ft_modifier(const char *str, int n, t_parse *data);
int				ft_converter(const char *str, int n, t_parse *data);
int				ft_check(const char *str, int n, char c);
void			ft_display(va_list ap, t_parse *data);
#endif
