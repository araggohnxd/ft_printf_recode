/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 21:08:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_unsigned(t_buffer *ctx, va_list ap, char specifier)
{
    unsigned long const arg = va_arg(ap, unsigned int);

    ctx->meta.base    = 10;
    ctx->meta.capital = LOWERCASE;
    ctx->meta.prefix  = NULL;
    return (number_to_buffer(ctx, arg));
    (void)specifier;
}
