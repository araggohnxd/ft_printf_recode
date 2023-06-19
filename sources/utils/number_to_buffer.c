/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/18 21:42:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int number_to_buffer(t_buffer *ctx, unsigned long num, t_meta *info)
{
    char   buffer[MAXBUF];
    char  *current;
    size_t length;

    current = &buffer[MAXBUF - 1];
    while (TRUE)
    {
        *--current = DIGITS[(num % info->base) + info->capital];
        num /= info->base;
        if (num <= 0)
            break;
    }
    return (buffer_append(ctx, current, (&buffer[MAXBUF - 1] - current)));
}
