/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 23:52:12 by maolivei         ###   ########.fr       */
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

int handler_specifier_string(t_buffer *ctx, va_list ap)
{
    char const *arg = va_arg(ap, char *);
    size_t      length;

    if (!arg)
        arg = "(null)";
    length = ft_strlen(arg);
    if (handle_flags(ctx, length) != 0)
        return (-1);
    ++ctx->offset;
    return (buffer_append(ctx, arg, length));
}
