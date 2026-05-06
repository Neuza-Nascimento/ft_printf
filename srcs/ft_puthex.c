/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedo-nas <nedo-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:57:53 by nedo-nas          #+#    #+#             */
/*   Updated: 2026/05/05 10:44:41 by nedo-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	printf_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += printf_hex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_puthex(void *s)
{
	int				i;
	unsigned long	addr;

	i = 0;
	if (!s)
	{
		return (ft_putstr("(nil)"));
	}
	addr = (unsigned long)s;
	i += ft_putstr("0x");
	i += printf_hex(addr);
	return (i);
}
