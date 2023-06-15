/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 04:36:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_hex(t_buffer *ctx, va_list ap, char specifier)
{
    unsigned long const arg = va_arg(ap, unsigned int);

    ctx->meta.base = 16;
    if (specifier == 'X')
        ctx->meta.uppercase = 16;
    else
        ctx->meta.uppercase = 0;
    ctx->meta.prefix = NULL;
    return (number_to_buffer(ctx, arg));
}
