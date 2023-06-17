/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 15:48:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_vprintf(char const *format, va_list ap)
{
    t_buffer ctx;

    if (buffer_create(&ctx, format, MINIMUM_BUFFER_SIZE) != 0)
        return (-1);
    if (process_format_string(&ctx, ap) != 0)
        return (error(&ctx));
    if (buffer_flush(&ctx) != 0)
        return (error(&ctx));
    free(ctx.buffer);
    return (ctx.bytes_written);
}

int ft_printf(char const *format, ...)
{
    int     bytes;
    va_list ap;

    bytes = 0;
    va_start(ap, format);
    bytes = ft_vprintf(format, ap);
    va_end(ap);
    return (bytes);
}
