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

int	ft_parsefmt(char *str, va_list args)
{
	(void)str;
	(void)args;
	return (0);
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
