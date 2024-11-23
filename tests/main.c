/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <elouannh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:32:03 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/23 14:32:03 by elouannh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	run_tests(int test_id)
{
	if (test_id == 0)
	{
		printf("Ceci est un test\n");
		ft_printf("Ceci est un test\n");
	}
}

int	main(int argc, char **argv)
{
	run_tests(ft_atoi(argv[0]));
	(void)argc;
	return (0);
}
