/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 22:19:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int set_precision(int length, int precision)
{
    if (precision > length)
        return (precision);
    return (length);
}

static int handle_flags(t_buffer *ctx, size_t length, long arg)
{
    if (ctx->flags.width > -1)
        if (fill_width(ctx, set_precision(length, ctx->flags.precision)) != 0)
            return (-1);
    if (arg < 0)
        if (buffer_append_one(ctx, '-') != 0)
            return (-1);
    if (ctx->flags.precision > -1)
        if (fill_precision(ctx, length) != 0)
            return (-1);
    return (0);
}

int handler_specifier_decimal(t_buffer *ctx, va_list ap)
{
    long const    arg = va_arg(ap, int);
    unsigned long num;
    t_meta        info;

    info.base    = 10;
    info.capital = LOWERCASE;
    if (arg < 0)
    {
        num = -arg;
        ++ctx->flags.precision;
    }
    else
        num = arg;
    if (handle_flags(ctx, get_number_length(arg, info.base), arg) != 0)
        return (-1);
    ++ctx->offset;
    if (arg == 0 && ctx->flags.precision == 0)
        return (0);
    return (number_to_buffer(ctx, num, &info));
}
