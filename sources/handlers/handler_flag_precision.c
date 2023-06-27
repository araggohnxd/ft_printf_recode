/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flag_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:35:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 15:10:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_flag_precision(t_buffer *ctx, va_list ap)
{
    int precision;

    ++ctx->offset;
    precision = 0;
    while (ctx->format[ctx->offset] && ft_isdigit(ctx->format[ctx->offset]))
        precision = (precision * 10) + (ctx->format[ctx->offset++] - '0');
    if (precision < 0)
        return (-1);
    ctx->flags.precision = precision;
    if (ctx->flags.zero)
        ctx->flags.zero = FALSE;
    --ctx->offset;
    return (handle_specifier_or_flag(ctx, ap));
}
