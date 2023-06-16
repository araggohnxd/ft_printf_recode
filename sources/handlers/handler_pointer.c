/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 21:08:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_pointer(t_buffer *ctx, va_list ap, char specifier)
{
    unsigned long const arg = va_arg(ap, unsigned long);

    if (!arg)
        return (buffer_append(ctx, "(nil)", 5));
    ctx->meta.base    = 16;
    ctx->meta.capital = LOWERCASE;
    ctx->meta.prefix  = "0x";
    return (number_to_buffer(ctx, arg));
    (void)specifier;
}
