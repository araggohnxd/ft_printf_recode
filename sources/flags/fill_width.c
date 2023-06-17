/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:17:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 22:17:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int fill_width(t_buffer *ctx, size_t length)
{
    int true_width;

    true_width = ctx->flags.width - length;
    if (true_width <= 0)
        return (0);
    while (true_width--)
        if (buffer_append_one(ctx, ' ') != 0)
            return (-1);
    return (0);
}
