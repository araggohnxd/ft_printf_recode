/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:25:20 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int number_to_buffer(t_buffer *ctx, unsigned long num, int base, int capital)
{
    char   buffer[MAXBUF];
    char  *current;

    current = &buffer[MAXBUF - 1];
    while (TRUE)
    {
        *--current = DIGITS[(num % base) + capital];
        num /= base;
        if (num <= 0)
            break;
    }
    return (buffer_append(ctx, current, (&buffer[MAXBUF - 1] - current)));
}
