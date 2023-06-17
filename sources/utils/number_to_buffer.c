/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 22:22:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int number_to_buffer(t_buffer *ctx, unsigned long num, t_meta *info)
{
    char  buffer[MAXBUF];
    char *current;

    current = &buffer[MAXBUF - 1];
    while (TRUE)
    {
        *--current = DIGITS[(num % info->base) + info->capital];
        num /= info->base;
        if (num <= 0)
            break;
    }
    if (info->prefix)
        if (buffer_append(ctx, info->prefix, ft_strlen(info->prefix)) != 0)
            return (-1);
    return (buffer_append(ctx, current, (&buffer[MAXBUF - 1] - current)));
}
