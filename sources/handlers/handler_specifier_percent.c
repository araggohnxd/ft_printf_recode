/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_percent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 23:51:44 by maolivei         ###   ########.fr       */
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

int handler_specifier_percent(t_buffer *ctx, va_list ap)
{
    if (handle_flags(ctx, 1) != 0)
        return (-1);
    ++ctx->offset;
    return (buffer_append(ctx, "%", 1));
    (void)ap;
}
