/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_character.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:13:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx, char const *arg)
{
    size_t const length = 1;

    if (buffer_append(ctx, arg, length) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, 0, length, 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_character(t_buffer *ctx, va_list ap)
{
    char const arg = va_arg(ap, int);

    ++ctx->offset;
    return (handle_flags(ctx, &arg));
}
