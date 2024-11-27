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

int	format_flag_next(char flg, va_list args, int *prtd)
{
	int		i;

	i = 0;
	if (flg == 'p')
	{
		i += ft_print_nbrbase_ptr((unsigned long long)va_arg(args, void *),
				"0123456789abcdef", prtd);
	}
	if (flg == '%')
	{
		i += 1;
		ft_putchar_fd('%', 1);
		*prtd += 1;
	}
	return (i);
}

int	format_flag(char flg, va_list args, int *prtd)
{
	int		i;

	i = 1;
	if (!flg)
		return (i);
	if (flg == 'd' || flg == 'i')
		i += ft_print_nbrbase((long long)va_arg(args, int), "0123456789", prtd);
	if (flg == 'c')
		i += ft_print_char(va_arg(args, int), prtd);
	if (flg == 's')
		i += ft_print_str(va_arg(args, char *), prtd);
	if (flg == 'u')
		i += ft_print_nbrbase_u((unsigned int)va_arg(args, unsigned int),
				"0123456789", prtd);
	if (flg == 'x')
		i += ft_print_nbrbase_u((unsigned int)va_arg(args, unsigned int),
				"0123456789abcdef", prtd);
	if (flg == 'X')
		i += ft_print_nbrbase_u((unsigned int)va_arg(args, unsigned int),
				"0123456789ABCDEF", prtd);
	if (flg == 'p' || flg == '%')
		i += format_flag_next(flg, args, prtd);
	return (i);
}

int	ft_parsefmt(char *str, va_list args)
{
	int	i;
	int	prtd;

	i = 0;
	prtd = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += format_flag(str[i + 1], args, &prtd);
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		prtd++;
	}
	return (prtd);
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
