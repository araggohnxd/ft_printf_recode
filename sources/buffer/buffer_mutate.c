/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_mutate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:01:55 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 17:42:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_mutate(t_buffer *ctx, char const *str, size_t length)
{
    size_t new_capacity;
    char  *new_buffer;

    new_capacity = ctx->size + length;
    if (new_capacity > ctx->capacity && (ctx->capacity * 2) > new_capacity)
        new_capacity = ctx->capacity * 2;
    new_buffer = malloc(new_capacity * sizeof(*new_buffer));
    if (!new_buffer)
        return (-1);
    if (ctx->size)
        ft_memmove(new_buffer, ctx->buffer, ctx->size);
    if (str && length)
        ft_memmove((new_buffer + ctx->size), str, length);
    free(ctx->buffer);
    ctx->buffer   = new_buffer;
    ctx->capacity = new_capacity;
    return (0);
}
