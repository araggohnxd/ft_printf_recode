/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:17:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:22:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int get_true_width(int length, int precision, int width, int offset)
{
    int true_width;

    true_width = width - length - precision - offset;
    if (true_width < 0)
        true_width = 0;
    return (true_width);
}

int fill_width(t_buffer *ctx, int precision, size_t len, size_t offset)
{
    int const width = get_true_width(len, precision, ctx->flags.width, offset);

    if (!width)
        return (0);
    if (ctx->flags.minus)
        return (buffer_insert_fill(ctx, ctx->size, ' ', width));
    return (buffer_insert_fill(ctx, (ctx->size - len - offset), ' ', width));
}
