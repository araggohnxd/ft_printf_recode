/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 18:51:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_vprintf(char const *format, va_list ap)
{
    t_buffer ctx;

    if (buffer_create(&ctx, MINIMUM_BUFFER_SIZE) != 0)
        return (-1);
    if (process_format_string(&ctx, format, ap) != 0)
        return (-1);
    write(STDOUT_FILENO, ctx.buffer, ctx.size);
    free(ctx.buffer);
    return (ctx.size);
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
