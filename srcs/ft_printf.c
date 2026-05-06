/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedo-nas <nedo-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:37:22 by nedo-nas          #+#    #+#             */
/*   Updated: 2026/05/05 12:58:01 by nedo-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	check_type(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	// else if (c == 's')
	// 	return (ft_putstr(va_arg(*args, char *)));
	// else if (c == 'p')
	// 	return (ft_puthex(va_arg(*args, void *)));
	// else if (c == 'd')
	// 	return (ft_putnbr(va_arg(*args, int)));
	// else if (c == 'i')
	// 	return (ft_putnbr(va_arg(*args, int)));
	// else if (c == 'u')
	// 	return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	// else if (c == 'x')
	// 	return (printf_nbr_hex(va_arg(*args, unsigned int),
	// 			"0123456789abcdef"));
	// else if (c == 'X')
	// 	return (printf_nbr_hex(va_arg(*args, unsigned int),
	// 			"0123456789ABCDEF"));
	else if (c == 'a')
		return (ft_putstr("my awsome"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				i++;
				count += check_type(format[i], &args);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

