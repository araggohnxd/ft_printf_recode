/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 21:02:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int number_to_buffer(t_buffer *ctx, unsigned long num)
{
    char  buffer[MAXBUF];
    char *current;
    char *prefix;

    prefix  = ctx->meta.prefix;
    current = &buffer[MAXBUF - 1];
    while (TRUE)
    {
        *--current = DIGITS[(num % ctx->meta.base) + ctx->meta.capital];
        num /= ctx->meta.base;
        if (num <= 0)
            break;
    }
    if (prefix)
        if (buffer_append(ctx, prefix, ft_strlen(prefix)) != 0)
            return (-1);
    return (buffer_append(ctx, current, (&buffer[MAXBUF - 1] - current)));
}
