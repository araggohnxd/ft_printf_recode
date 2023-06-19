/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flag_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:18:33 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 17:21:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_flag_minus(t_buffer *ctx, va_list ap)
{
    ctx->flags.minus = TRUE;
    if (ctx->flags.zero)
        ctx->flags.zero = FALSE;
    return (handle_specifier_or_flag(ctx, ap));
}
