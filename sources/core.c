/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:30 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 17:11:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_handler_specifier get_specifier_handler(int type)
{
    static const t_handler_specifier handlers[__SCHAR_MAX__] = {
        ['%'] = handler_percent,
        ['X'] = handler_hex,
        ['c'] = handler_character,
        ['s'] = handler_string,
        ['p'] = handler_pointer,
        ['i'] = handler_decimal,
        ['d'] = handler_decimal,
        ['u'] = handler_unsigned,
        ['x'] = handler_hex,
    };

    return (handlers[type]);
}

static int handle_format_specifier(t_buffer *ctx, va_list ap, char *conversion)
{
    char                specifier;
    t_handler_specifier handler_specifier;

    specifier = *(conversion + 1);
    if (!specifier)
        return (error(ctx));
    handler_specifier = get_specifier_handler(specifier);
    if (!handler_specifier)
        return (buffer_append(ctx, conversion, 2));
    if ((*handler_specifier)(ctx, ap, specifier) != 0)
        return (error(ctx));
    return (0);
}

int process_format_string(t_buffer *ctx, char const *format, va_list ap)
{
    char *conversion;

    while (*format)
    {
        conversion = ft_strchr(format, '%');
        if (!conversion)
            return (buffer_append(ctx, format, ft_strlen(format)));
        if (buffer_append(ctx, format, (conversion - format)) != 0)
            return (error(ctx));
        if (handle_format_specifier(ctx, ap, conversion) != 0)
            return (error(ctx));
        if (!*(conversion + 1))
            return (0);
        format = conversion + 2;
    }
    return (0);
}
