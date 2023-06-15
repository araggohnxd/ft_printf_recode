/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:01:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 04:58:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_append(t_buffer *ctx, char const *str, size_t n)
{
    size_t const length = n + ctx->size;

    if (length <= ctx->capacity)
    {
        if (n)
            ft_memmove((ctx->buffer + ctx->size), str, n);
    }
    else
    {
        if (buffer_mutate(ctx, str, n) != 0)
            return (-1);
    }
    ctx->size = length;
    return (0);
}
