/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_append_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:59:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 21:52:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_append_one(t_buffer *ctx, char c)
{
    if (ctx->size == ctx->capacity)
        if (buffer_mutate(ctx, NULL, 1) != 0)
            return (-1);
    ctx->buffer[ctx->size++] = c;
    return (0);
}
