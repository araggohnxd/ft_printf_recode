/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 23:51:37 by maolivei         ###   ########.fr       */
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

int handler_specifier_decimal(t_buffer *ctx, va_list ap)
{
    long const    arg = va_arg(ap, int);
    unsigned long num;
    t_meta        info;

    info.base    = 10;
    info.capital = LOWERCASE;
    if (arg >= 0)
    {
        info.prefix = NULL;
        num         = arg;
    }
    else
    {
        info.prefix = "-";
        num         = -arg;
    }
    if (handle_flags(ctx, get_number_length(arg, info.base)) != 0)
        return (-1);
    ++ctx->offset;
    return (number_to_buffer(ctx, num, &info));
}
