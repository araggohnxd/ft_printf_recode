/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 22:23:22 by maolivei         ###   ########.fr       */
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

int handler_specifier_hex(t_buffer *ctx, va_list ap)
{
    unsigned long const arg = va_arg(ap, unsigned int);
    t_meta              info;

    info.base = 16;
    if (ctx->format[ctx->offset] == 'X')
        info.capital = UPPERCASE;
    else
        info.capital = LOWERCASE;
    info.prefix = NULL;
    if (handle_flags(ctx, get_number_length(arg, info.base)) != 0)
        return (-1);
    ++ctx->offset;
    return (number_to_buffer(ctx, arg, &info));
}
