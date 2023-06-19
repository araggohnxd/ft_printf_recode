/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:17:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 15:30:31 by maolivei         ###   ########.fr       */
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
    int const fill  = '0' * (ctx->flags.zero) + ' ' * (!ctx->flags.zero);
    size_t    pos;

    if (!width)
        return (0);
    if (ctx->flags.minus)
        pos = ctx->size;
    else
        pos = ctx->size - len - precision - offset;
    return (buffer_insert_fill(ctx, pos, fill, width));
}
