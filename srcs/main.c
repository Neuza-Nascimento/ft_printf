/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedo-nas <nedo-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/05/04 10:28:41 by nedo-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

/* Macro para comparar ft_printf vs printf e mostrar resultado */
 #define TEST(fmt, ...) do { \
	int r1, r2; \
	printf("  printf : "); \
	r2 = printf(fmt, ##__VA_ARGS__); \
	printf("\n"); \
	printf("ft_printf: "); \
	r1 = ft_printf(fmt, ##__VA_ARGS__); \
	ft_printf("\n"); \
	if (r1 == r2) \
		printf("[OK] return: %d\n\n", r1); \
	else \
		printf("[KO] ft_printf=%d | printf=%d\n\n", r1, r2); \
} while (0)

int	main(void)
{
	printf("=== TESTES %%c ===\n\n");

	// 1
	printf("Teste 1 - char simples:\n");
	TEST("%c", 'A');

	// 2
	printf("Teste 2 - char minusculo:\n");
	TEST("%c", 'z');

	// 3
	printf("Teste 3 - char espaco:\n");
	TEST("%c", ' ');

	// 4
	printf("Teste 4 - char numero:\n");
	TEST("%c", '9');

	printf("=== TESTES %%s ===\n\n");

	// 5
	printf("Teste 5 - string normal:\n");
	TEST("%s", "hello world");

	// 6
	printf("Teste 6 - string vazia:\n");
	TEST("%s", "");

	// 7
	printf("Teste 7 - string NULL:\n");
	TEST("%s", (char *)NULL);

	// 8
	printf("Teste 8 - string longa:\n");
	TEST("%s", "Esta e uma string muito longa para testar o ft_putstr");

	printf("=== TESTES %%d / %%i ===\n\n");

	// 9
	printf("Teste 9 - inteiro positivo:\n");
	TEST("%d", 42);

	// 10
	printf("Teste 10 - inteiro negativo:\n");
	TEST("%d", -42);

	// 11
	printf("Teste 11 - zero:\n");
	TEST("%d", 0);

	// 12
	printf("Teste 12 - INT_MAX:\n");
	TEST("%d", INT_MAX);

	// 13
	printf("Teste 13 - INT_MIN:\n");
	TEST("%d", INT_MIN);

	// 14
	printf("Teste 14 - %%i positivo:\n");
	TEST("%i", 100);

	// 15
	printf("Teste 15 - %%i negativo:\n");
	TEST("%i", -100);

	printf("=== TESTES %%u ===\n\n");

	// 16
	printf("Teste 16 - unsigned normal:\n");
	TEST("%u", 42u);

	// 17
	printf("Teste 17 - unsigned zero:\n");
	TEST("%u", 0u);

	// 18
	printf("Teste 18 - UINT_MAX:\n");
	TEST("%u", UINT_MAX);

	printf("=== TESTES %%x / %%X ===\n\n");

	// 19
	printf("Teste 19 - hex minusculo:\n");
	TEST("%x", 255);

	// 20
	printf("Teste 20 - hex maiusculo:\n");
	TEST("%X", 255);

	// 21
	printf("Teste 21 - hex zero:\n");
	TEST("%x", 0);

	// 22
	printf("Teste 22 - hex grande:\n");
	TEST("%x", 4294967295u);

	// 23
	printf("Teste 23 - hex maiusculo grande:\n");
	TEST("%X", 4294967295u);

	printf("=== TESTES %%p ===\n\n");

	// 24
	int var = 42;
	printf("Teste 24 - ponteiro valido:\n");
	TEST("%p", (void *)&var);

	// 25
	printf("Teste 25 - ponteiro NULL:\n");
	TEST("%p", NULL);

	printf("=== TESTES %%%% ===\n\n");

	// 26
	printf("Teste 26 - percentagem literal:\n");
	TEST("100%%");

	printf("=== TESTES MISTOS ===\n\n");

	// 27
	printf("Teste 27 - string + inteiro:\n");
	TEST("Nome: %s, Idade: %d", "Neuza", 20);

	// 28
	printf("Teste 28 - multiplos inteiros:\n");
	TEST("%d + %d = %d", 3, 4, 7);

	// 29
	printf("Teste 29 - todos os tipos:\n");
	TEST("c:%c s:%s d:%d i:%i u:%u x:%x X:%X", 'A', "ola", -1, 42, 99u, 255,
		255);

	// 30
	printf("Teste 30 - negativos e hex:\n");
	TEST("neg:%d hex:%x", -255, 255);

	// 31
	printf("Teste 31 - so texto sem especificadores:\n");
	TEST("Nenhum especificador aqui");

	// 32
	printf("Teste 32 - percentagem no meio:\n");
	TEST("100%% de %d testes", 32);

	// 33
	printf("Teste 33 - char + string:\n");
	TEST("%c %s!", 'O', "la");

	// 34
	printf("Teste 34 - ponteiro + inteiro:\n");
	TEST("ptr: %p val: %d", (void *)&var, var);

	// 35
	printf("Teste 35 - zero em hex:\n");
	TEST("hex: %x HEX: %X", 0, 0);

	ft_printf(" NULL %s NULL ", NULL);
	printf(" NULL %s NULL ", (char *)NULL);

	return (0);
}
