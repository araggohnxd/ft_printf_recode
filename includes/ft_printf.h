/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:09:44 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:37:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define MINIMUM_BUFFER_SIZE 16

#define MAXBUF        sizeof(long) * 8
#define DIGITS        "0123456789abcdef0123456789ABCDEF"
#define HEX_UPPERCASE 16
#define HEX_LOWERCASE 0
#define NO_CASE       0
#define HEX_BASE      16
#define DEC_BASE      10

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

struct s_flags
{
    int    width;
    int    precision;
    t_bool minus;
};
typedef struct s_flags t_flags;

struct s_buffer
{
    char       *buffer;
    size_t      size;
    size_t      capacity;
    size_t      bytes_written;
    t_flags     flags;
    size_t      offset;
    char const *format;
};
typedef struct s_buffer t_buffer;

typedef int (*t_handler)(t_buffer *, va_list);

int ft_printf(char const *format, ...);

int process_format_string(t_buffer *, va_list);
int handle_specifier_or_flag(t_buffer *, va_list);

int handler_specifier_character(t_buffer *, va_list);
int handler_specifier_decimal(t_buffer *, va_list);
int handler_specifier_hex(t_buffer *, va_list);
int handler_specifier_percent(t_buffer *, va_list);
int handler_specifier_pointer(t_buffer *, va_list);
int handler_specifier_string(t_buffer *, va_list);
int handler_specifier_unsigned(t_buffer *, va_list);
int handler_flag_width(t_buffer *, va_list);
int handler_flag_precision(t_buffer *, va_list);
int handler_flag_minus(t_buffer *, va_list);

int fill_width(t_buffer *, int, size_t, size_t);
int get_true_precision(int, int);

t_bool has_precision(t_flags *);
t_bool has_width(t_flags *);

int  buffer_create(t_buffer *, char const *, size_t);
int  buffer_mutate(t_buffer *, char const *, size_t);
int  buffer_append(t_buffer *, char const *, size_t);
int  buffer_append_one(t_buffer *, char);
int  buffer_insert_fill(t_buffer *, size_t, char, size_t);
int  buffer_flush(t_buffer *);
void buffer_reset_flags(t_buffer *);

size_t get_number_length(unsigned long, int);
int    number_to_buffer(t_buffer *, unsigned long, int, int);
int    error(t_buffer *);

#endif /* FT_PRINTF_H */
