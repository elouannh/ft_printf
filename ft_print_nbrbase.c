/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <elouannh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:48:36 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/23 15:48:36 by elouannh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbrbase(long long n, char *base, int *prtd)
{
	size_t	blen;

	blen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		*prtd += 1;
	}
	if (n >= (long long)blen)
	{
		ft_print_nbrbase(n / blen, base, prtd);
		ft_putchar_fd(base[n % blen], 1);
		*prtd += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*prtd += 1;
	}
	return (1);
}

int	ft_print_nbrbase_u(unsigned int n, char *base, int *prtd)
{
	size_t	blen;

	blen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		*prtd += 1;
	}
	if (n >= blen)
	{
		ft_print_nbrbase(n / blen, base, prtd);
		ft_putchar_fd(base[n % blen], 1);
		*prtd += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*prtd += 1;
	}
	return (1);
}

int	ft_print_nbrbase_ptr(unsigned long long n, char *base, int *prtd)
{
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*prtd += 5;
		return (1);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*prtd += 2;
	}
	if (n >= (unsigned long long)ft_strlen(base))
	{
		ft_print_nbrbase(n / ft_strlen(base), base, prtd);
		ft_putchar_fd(base[n % ft_strlen(base)], 1);
		*prtd += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*prtd += 1;
	}
	return (1);
}
