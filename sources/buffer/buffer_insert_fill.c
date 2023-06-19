/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_insert_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:12:46 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 00:59:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_insert_fill(t_buffer *ctx, size_t pos, char c, size_t len)
{
    size_t n;
    size_t i;

    if (!len)
        return (0);
    if ((ctx->size + len) > ctx->capacity)
        if (buffer_mutate(ctx, NULL, (ctx->size + len)) != 0)
            return (-1);
    n = len;
    i = ctx->size;
    while (i > pos)
    {
        ctx->buffer[i + len - 1] = ctx->buffer[i - 1];
        --i;
    }
    i = pos + len - 1;
    while (n--)
        ctx->buffer[i--] = c;
    ctx->size += len;
    return (0);
}
