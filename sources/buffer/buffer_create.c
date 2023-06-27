/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:45:58 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 21:37:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_create(t_buffer *ctx, char const *format, size_t capacity)
{
    ctx->buffer = malloc(capacity * sizeof(*ctx->buffer));
    if (!ctx->buffer)
        return (-1);
    ctx->capacity      = capacity;
    ctx->size          = 0;
    ctx->bytes_written = 0;
    ctx->offset        = 0;
    ctx->format        = format;
    return (0);
}
