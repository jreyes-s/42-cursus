/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:57:45 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/29 13:52:31 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(char c, va_list *args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar(va_arg(*args, int));
	else if (c == 's')
		size = ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		size = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		size = ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (c == 'x')
		size = ft_puthex(va_arg(*args, unsigned int), 0);
	else if (c == 'X')
		size = ft_puthex(va_arg(*args, unsigned int), 1);
	else if (c == 'p')
		size = ft_putptr(va_arg(*args, void *));
	else if (c == '%')
		size = ft_putchar('%');
	return (size);
}

static int	cleanup_error(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (safe_add(&count, dispatch(format[i], &args)) == -1)
				return (cleanup_error(&args));
		}
		else
			if (safe_add(&count, ft_putchar(format[i])) == -1)
				return (cleanup_error(&args));
		i++;
	}
	va_end(args);
	return (count);
}
