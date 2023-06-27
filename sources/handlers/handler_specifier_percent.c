/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_specifier_percent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:17:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags(t_buffer *ctx)
{
    char const  *percent = "%";
    size_t const length  = 1;

    if (buffer_append(ctx, percent, length) != 0)
        return (-1);
    if (has_width(&ctx->flags))
        if (fill_width(ctx, 0, length, 0) != 0)
            return (-1);
    return (0);
}

int handler_specifier_percent(t_buffer *ctx, va_list ap)
{
    ++ctx->offset;
    return (handle_flags(ctx));
    (void)ap;
}
