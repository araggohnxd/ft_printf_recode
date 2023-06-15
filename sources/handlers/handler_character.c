/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 04:03:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_character(t_buffer *ctx, va_list ap, char specifier)
{
    char arg;
    char tmp[2];

    arg    = va_arg(ap, int);
    tmp[0] = arg;
    tmp[1] = '\0';
    return (buffer_append(ctx, tmp, 1));
    (void)specifier;
}
