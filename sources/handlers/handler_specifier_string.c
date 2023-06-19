/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 22:19:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int set_precision(int length, int precision)
{
    if (length > precision)
        return (precision);
    return (length);
}

static int handle_flags(t_buffer *ctx, size_t *length)
{
    if (ctx->flags.precision > -1)
        *length = set_precision(*length, ctx->flags.precision);
    if (ctx->flags.width > -1)
        if (fill_width(ctx, *length) != 0)
            return (-1);
    return (0);
}

static int handle_null_string(t_buffer *ctx)
{
    if (ctx->flags.precision > -1 && ctx->flags.precision < 6)
        return (fill_width(ctx, 0));
    if (ctx->flags.width > -1)
        if (fill_width(ctx, 6) != 0)
            return (-1);
    return (buffer_append(ctx, "(null)", 6));
}

int handler_specifier_string(t_buffer *ctx, va_list ap)
{
    char const *arg = va_arg(ap, char *);
    size_t      length;

    ++ctx->offset;
    if (!arg)
        return (handle_null_string(ctx));
    length = ft_strlen(arg);
    if (handle_flags(ctx, &length) != 0)
        return (-1);
    return (buffer_append(ctx, arg, length));
}
