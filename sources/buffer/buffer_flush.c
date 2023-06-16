/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_flush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:48:56 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 19:53:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_flush(t_buffer *ctx)
{
    int bytes;

    bytes = write(STDOUT_FILENO, ctx->buffer, ctx->size);
    if (bytes < 0 || bytes != (int)ctx->size)
        return (-1);
    ctx->size = 0;
    ctx->bytes_written += bytes;
    return (0);
}
