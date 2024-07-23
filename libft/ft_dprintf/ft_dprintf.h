/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:48:25 by achak             #+#    #+#             */
/*   Updated: 2024/02/16 14:21:49 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_dprintf(int fd, const char *format, ...);
int				print_char(int c, int fd);
int				print_str(char *str, int fd);
int				print_digit(long n, int base, char specifier, int fd);
int				print_format(char sp, va_list ap, int fd);
int				ft_ptrlen(unsigned long int ptr);
void			ft_putptr(unsigned long int ptr, int fd);
int				print_ptr(unsigned long int ptr, int fd);

#endif
