/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedo-nas <nedo-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:38:11 by nedo-nas          #+#    #+#             */
/*   Updated: 2026/05/05 10:44:49 by nedo-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printf_nbr_hex(unsigned int nb, char *s)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n >= 16)
		count += printf_nbr_hex(n / 16, s);
	count += ft_putchar(s[n % 16]);
	return (count);
}
