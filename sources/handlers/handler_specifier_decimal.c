/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 15:07:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_specifier_decimal(t_buffer *ctx, va_list ap, char specifier)
{
    long const    arg = va_arg(ap, int);
    unsigned long num;

    ctx->meta.base    = 10;
    ctx->meta.capital = LOWERCASE;
    if (arg >= 0)
    {
        ctx->meta.prefix = NULL;
        num              = arg;
    }
    else
    {
        ctx->meta.prefix = "-";
        num              = -arg;
    }
    return (number_to_buffer(ctx, num));
    (void)specifier;
}
