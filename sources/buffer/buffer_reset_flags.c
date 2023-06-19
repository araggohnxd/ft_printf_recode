/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_reset_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:10:30 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:26:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void buffer_reset_flags(t_buffer *ctx)
{
    ctx->flags.width      = -1;
    ctx->flags.precision  = -1;
    ctx->flags.minus      = FALSE;
}
