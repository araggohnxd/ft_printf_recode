/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flag_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:35:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 18:14:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_flag_width(t_buffer *ctx, va_list ap)
{
    int width;

    width = 0;
    while (ctx->format[ctx->offset] && ft_isdigit(ctx->format[ctx->offset]))
        width = (width * 10) + (ctx->format[ctx->offset++] - '0');
    if (width < 0)
        return (-1);
    ctx->flags.width = width;
    --ctx->offset;
    return (handle_specifier_or_flag(ctx, ap));
}
