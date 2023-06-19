/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_flag_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:00:35 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 16:00:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_flag_space(t_buffer *ctx, va_list ap)
{
    ctx->flags.space = TRUE;
    return (handle_specifier_or_flag(ctx, ap));
}
