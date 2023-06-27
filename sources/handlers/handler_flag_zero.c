/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flag_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:18:33 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 17:21:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_flag_zero(t_buffer *ctx, va_list ap)
{
    if (!ctx->flags.minus)
        ctx->flags.zero = TRUE;
    return (handle_specifier_or_flag(ctx, ap));
}
