/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 15:07:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_specifier_string(t_buffer *ctx, va_list ap, char specifier)
{
    char const *arg = va_arg(ap, char *);

    if (!arg)
        arg = "(null)";
    return (buffer_append(ctx, arg, ft_strlen(arg)));
    (void)specifier;
}
