/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:51:22 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/29 21:17:18 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int			ft_printf(char const *format, ...);
int			ft_putchar(int c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_puthex(unsigned int n, int uppercase);
int			ft_putptr(void *ptr);
int			ft_safe_add(int *count, int ret);
#endif
