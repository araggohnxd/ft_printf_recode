/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 23:52:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx, size_t length)
{
    if (ctx->flags.width)
        if (fill_width(ctx, length) != 0)
            return (-1);
    return (0);
}

static int handle_null_pointer(t_buffer *ctx)
{
    if (handle_flags(ctx, 5) != 0)
        return (-1);
    return (buffer_append(ctx, "(nil)", 5));
}

int handler_specifier_pointer(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned long);
    t_meta              info;

    if (!arg)
        return (handle_null_pointer(ctx));
    info.base    = 16;
    info.capital = LOWERCASE;
    info.prefix  = "0x";
    if (handle_flags(ctx, (get_number_length(arg, info.base) + 2)) != 0)
        return (-1);
    ++ctx->offset;
    return (number_to_buffer(ctx, arg, &info));
}
