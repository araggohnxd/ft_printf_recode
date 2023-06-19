/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 22:19:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int set_precision(int length, int precision)
{
    if (precision > length)
        return (precision);
    return (length);
}

static int handle_flags(t_buffer *ctx, size_t len)
{
    if (ctx->flags.width > -1)
        if (fill_width(ctx, set_precision(len, ctx->flags.precision) + 2) != 0)
            return (-1);
    if (buffer_append(ctx, "0x", 2) != 0)
        return (-1);
    if (ctx->flags.precision > -1)
        if (fill_precision(ctx, len) != 0)
            return (-1);
    return (0);
}

static int handle_null_pointer(t_buffer *ctx)
{
    if (ctx->flags.width > -1)
        if (fill_width(ctx, 5) != 0)
            return (-1);
    return (buffer_append(ctx, "(nil)", 5));
}

int handler_specifier_pointer(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned long);
    t_meta              info;

    ++ctx->offset;
    if (!arg)
        return (handle_null_pointer(ctx));
    info.base    = 16;
    info.capital = LOWERCASE;
    if (handle_flags(ctx, get_number_length(arg, info.base)) != 0)
        return (-1);
    return (number_to_buffer(ctx, arg, &info));
}
