/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:28:32 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/29 21:17:27 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned long	nbr;
	int				count;

	nbr = (unsigned long)n;
	count = 0;
	if (nbr >= 10)
		if (ft_safe_add(&count, ft_putnbr_unsigned(nbr / 10)) == -1)
			return (-1);
	if (ft_safe_add(&count, ft_putchar((nbr % 10) + '0')) == -1)
		return (-1);
	return (count);
}
