/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:09:44 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 21:16:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define MINIMUM_BUFFER_SIZE 16

#define MAXBUF    sizeof(long) * 8
#define DIGITS    "0123456789abcdef0123456789ABCDEF"
#define UPPERCASE 16
#define LOWERCASE 0

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

struct s_meta
{
    int         capital;
    int         base;
    char const *prefix;
};
typedef struct s_meta t_meta;

struct s_buffer
{
    char  *buffer;
    size_t size;
    size_t capacity;
    size_t bytes_written;
    t_meta meta;
};
typedef struct s_buffer t_buffer;

typedef int (*t_handler_specifier)(t_buffer *, va_list, char);

int ft_printf(char const *format, ...);

int process_format_string(t_buffer *ctx, char const *format, va_list ap);

int handler_character(t_buffer *, va_list, char);
int handler_decimal(t_buffer *, va_list, char);
int handler_hex(t_buffer *, va_list, char);
int handler_percent(t_buffer *, va_list, char);
int handler_pointer(t_buffer *, va_list, char);
int handler_string(t_buffer *, va_list, char);
int handler_unsigned(t_buffer *, va_list, char);

int buffer_create(t_buffer *ctx, size_t capacity);
int buffer_mutate(t_buffer *, char const *, size_t);
int buffer_append(t_buffer *, char const *, size_t);
int buffer_flush(t_buffer *ctx);
int number_to_buffer(t_buffer *, unsigned long);
int error(t_buffer *);

#endif /* FT_PRINTF_H */
