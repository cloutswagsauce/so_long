/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:49:09 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/16 13:16:37 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define HEX_UPPER "0123456789ABCDEF"

# define HEX_LOWER "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	print_hex(unsigned int n, int uppercase);
int	print_u(unsigned int n);
int	print_s(char *str);
int	print_p(void *p);
int	print_di(int n);

#endif 
