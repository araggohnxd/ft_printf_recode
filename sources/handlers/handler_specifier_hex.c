/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 15:07:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_specifier_hex(t_buffer *ctx, va_list ap, char specifier)
{
    unsigned long const arg = va_arg(ap, unsigned int);

    ctx->meta.base = 16;
    if (specifier == 'X')
        ctx->meta.capital = UPPERCASE;
    else
        ctx->meta.capital = LOWERCASE;
    ctx->meta.prefix = NULL;
    return (number_to_buffer(ctx, arg));
}
