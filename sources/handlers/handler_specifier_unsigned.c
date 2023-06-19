/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_unsigned.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:32:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx, unsigned long arg)
{
    size_t length;
    int    precision;

    length    = get_number_length(arg, 10);
    precision = get_true_precision(length, ctx->flags.precision);
    if (has_precision(&ctx->flags) && precision == 0 && arg == 0)
        length = 0;
    if (precision)
        if (buffer_insert_fill(ctx, ctx->size, '0', precision) != 0)
            return (-1);
    if (length)
        if (number_to_buffer(ctx, arg, 10, 0) != 0)
            return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, precision, length, 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_unsigned(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned int);

    ++ctx->offset;
    return (handle_flags(ctx, arg));
}
