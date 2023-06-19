/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:09:07 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 22:19:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int fill_precision(t_buffer *ctx, size_t length)
{
    int precision;

    precision = ctx->flags.precision;
    while (precision > (int)length)
    {
        if (buffer_append_one(ctx, '0') != 0)
            return (-1);
        --precision;
    }
    return (0);
}
