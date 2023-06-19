/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:34:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx, unsigned long num, t_bool negative)
{
    size_t length;
    int    precision;

    length    = get_number_length(num, DEC_BASE);
    precision = get_true_precision(length, ctx->flags.precision);
    if (has_precision(&ctx->flags) && precision == 0 && num == 0)
        length = 0;
    if (negative)
        if (buffer_append_one(ctx, '-') != 0)
            return (-1);
    if (precision)
        if (buffer_insert_fill(ctx, ctx->size, '0', precision) != 0)
            return (-1);
    if (length)
        if (number_to_buffer(ctx, num, DEC_BASE, NO_CASE) != 0)
            return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, precision, (length + negative), 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_decimal(t_buffer *ctx, va_list ap)
{
    long const    arg = va_arg(ap, int);
    unsigned long num;

    if (arg < 0)
        num = -arg;
    else
        num = arg;
    ++ctx->offset;
    return (handle_flags(ctx, num, (arg < 0)));
}
