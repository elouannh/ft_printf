/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <elouannh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:21:49 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/23 12:21:49 by elouannh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_print_char(char c, int *prtd);
int		ft_print_nbrbase(long long n, char *base, int *prtd);
int		ft_print_nbrbase_ptr(unsigned long long n, char *base, int *prtd);
int		ft_print_nbrbase_u(unsigned int n, char *base, int *prtd);
int		ft_print_str(char *str, int *prtd);
int		ft_printf(const char *format, ...);

#endif
