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

void	print_tests_result(int t1, int t2)
{
	printf("\n------------------------\nprintf\t\t%d\nft_printf\t%d\n", t1, t2);
	if (t1 != t2)
		return ((void)printf("\n❌ Exit codes are not the same.\n"));
	printf("✅ Test passed.\n");
}

void	run_tests(int test_id)
{
	int	t1;
	int	t2;

	if (test_id == 0)
	{
		t1 = printf("Ceci est un test\n");
		t2 = ft_printf("Ceci est un test\n");
		print_tests_result(t1, t2);
	}
	if (test_id == 1)
	{
		t1 = printf("Nombre: %d\nChar: %c\n", 42060, 'e');
		t2 = ft_printf("Nombre: %d\nChar: %c\n", 42060, 'e');
		print_tests_result(t1, t2);
	}
	if (test_id == 2)
	{
		t1 = printf("%c%c%c%c\n", 'a', 'b', 'c', 'd');
		t2 = ft_printf("%c%c%c%c\n", 'a', 'b', 'c', 'd');
		print_tests_result(t1, t2);
	}
	if (test_id == 3)
	{
		t1 = printf("%s\n", "Coucou je suis une banane");
		t2 = ft_printf("%s\n", "Coucou je suis une banane");
		print_tests_result(t1, t2);
	}
	if (test_id == 4)
	{
		t1 = printf("%p\n", 0);
		t2 = ft_printf("%p\n", 0);
		print_tests_result(t1, t2);
	}
	if (test_id == 5)
	{
		t1 = printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
		t2 = ft_printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
		print_tests_result(t1, t2);
	}
	if (test_id == 6)
	{
		t1 = printf("%x %x %x\n", 10, 11, 15);
		t2 = ft_printf("%x %x %x\n", 10, 11, 15);
		print_tests_result(t1, t2);
	}
}

int	main(int argc, char **argv)
{
	run_tests(ft_atoi(argv[1]));
	(void)argc;
	return (0);
}
