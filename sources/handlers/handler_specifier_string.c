/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:31:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int set_precision(int length, int precision)
{
    if (length > precision)
        return (precision);
    return (length);
}

static int handle_flags(t_buffer *ctx, char const *arg, size_t length)
{
    if (has_precision(&ctx->flags))
        length = set_precision(length, ctx->flags.precision);
    if (buffer_append(ctx, arg, length) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, 0, length, 0) != 0)
            return (-1);
    return (0);
}

static int handle_null_string(t_buffer *ctx)
{
    char const  *nullstr = "(null)";
    size_t const length  = 6;

    if (has_precision(&ctx->flags) && ctx->flags.precision < (int)length)
        return (fill_width(ctx, 0, 0, 0));
    if (buffer_append(ctx, nullstr, length) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, 0, length, 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_string(t_buffer *ctx, va_list ap)
{
    char const *arg = va_arg(ap, char *);
    size_t      length;

    ++ctx->offset;
    if (!arg)
        return (handle_null_string(ctx));
    length = ft_strlen(arg);
    return (handle_flags(ctx, arg, length));
}
