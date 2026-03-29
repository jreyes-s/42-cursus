/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:06:56 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/29 21:15:39 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	unsigned long	nbr;
	char			*hex_digits;
	int				count;

	nbr = (unsigned long)n;
	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (nbr >= 16)
		if (ft_safe_add(count, ft_puthex(nbr / 16, uppercase)) == -1)
			return (-1);
	if (ft_safe_add(count, ft_putchar(hex_digits[nbr % 16])) == -1)
		return (-1);
	return (count);
}
