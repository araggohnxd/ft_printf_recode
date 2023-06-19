/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 15:55:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int append_alternate_form(t_buffer *ctx, char specifier)
{
    char const prefix[2] = {'0', specifier};

    return (buffer_append(ctx, prefix, 2));
}

static int handle_flags(t_buffer *ctx, unsigned long arg, char specifier)
{
    size_t length;
    size_t precision;
    int    capital;

    if (specifier == 'X')
        capital = HEX_UPPERCASE;
    else
        capital = HEX_LOWERCASE;
    length    = get_number_length(arg, HEX_BASE);
    precision = get_true_precision(length, ctx->flags.precision);
    if (ctx->flags.hash && arg > 0)
        if (append_alternate_form(ctx, specifier) != 0)
            return (-1);
    if (has_precision(&ctx->flags) && ctx->flags.precision == 0 && arg == 0)
        length = 0;
    if (precision)
        if (buffer_insert_fill(ctx, ctx->size, '0', precision) != 0)
            return (-1);
    if (length)
        if (number_to_buffer(ctx, arg, HEX_BASE, capital) != 0)
            return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, precision, length, (2 * ctx->flags.hash)) != 0)
            return (-1);
    return (0);
}

int handler_specifier_hex(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned int);

    ++ctx->offset;
    return (handle_flags(ctx, arg, ctx->format[ctx->offset - 1]));
}
