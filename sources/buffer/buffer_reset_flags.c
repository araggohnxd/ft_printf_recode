/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_reset_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:10:30 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 21:48:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void buffer_reset_flags(t_buffer *ctx)
{
    ft_memset(&ctx->flags, -1, sizeof(t_flags));
}
