/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:35:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx, unsigned long arg)
{
    size_t const length    = get_number_length(arg, HEX_BASE);
    int const    precision = get_true_precision(length, ctx->flags.precision);

    if (buffer_append(ctx, "0x", 2) != 0)
        return (-1);
    if (precision)
        if (buffer_insert_fill(ctx, ctx->size, '0', precision) != 0)
            return (-1);
    if (number_to_buffer(ctx, arg, HEX_BASE, HEX_LOWERCASE) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, precision, length, 2) != 0)
            return (-1);
    return (0);
}

static int handle_null_pointer(t_buffer *ctx)
{
    char const  *nilstr = "(nil)";
    size_t const length = 5;

    if (buffer_append(ctx, nilstr, length) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, 0, length, 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_pointer(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned long);

    ++ctx->offset;
    if (!arg)
        return (handle_null_pointer(ctx));
    return (handle_flags(ctx, arg));
}
