/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <elouannh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:18 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/23 12:17:18 by elouannh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_flag(char *str, va_list args)
{
	int		i;
	char	c;

	i = 1;
	if (!&str[i] || !str[i])
		return (i);
	c = str[i];
	if (c == 'd')
		i += ft_print_int(va_arg(args, int));
	if (c == 'c')
		i += ft_print_char(va_arg(args, char));
	return (i);
}

int	ft_parsefmt(char *str, va_list args)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += format_flag(&str[i], args);
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	(void)args;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	*str;

	if (!format || !*format)
		return (0);
	str = ft_strdup(format);
	if (!str || !*str)
		return (0);
	i = 0;
	va_start(args, format);
	i = ft_parsefmt(str, args);
	va_end(args);
	free(str);
	return (i);
}
