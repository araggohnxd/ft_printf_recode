/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:30 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 15:27:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_handler_specifier get_specifier_handler(int type)
{
    static const t_handler_specifier handlers[__SCHAR_MAX__] = {
        ['%'] = handler_specifier_percent,
        ['X'] = handler_specifier_hex,
        ['c'] = handler_specifier_character,
        ['s'] = handler_specifier_string,
        ['p'] = handler_specifier_pointer,
        ['i'] = handler_specifier_decimal,
        ['d'] = handler_specifier_decimal,
        ['u'] = handler_specifier_unsigned,
        ['x'] = handler_specifier_hex,
    };

    return (handlers[type]);
}

static int handle_format_specifier(t_buffer *ctx, va_list ap, char const *conv)
{
    char                specifier;
    t_handler_specifier handler_specifier;

    specifier = *(conv + 1);
    if (!specifier)
        return (-1);
    handler_specifier = get_specifier_handler(specifier);
    if (!handler_specifier)
        return (buffer_append(ctx, conv, 2));
    return (*handler_specifier)(ctx, ap, specifier);
}

int process_format_string(t_buffer *ctx, char const *format, va_list ap)
{
    while (*format)
    {
        if (*format == '%')
        {
            if (handle_format_specifier(ctx, ap, format) != 0)
                return (-1);
            format += 2;
            continue;
        }
        if (ctx->size == ctx->capacity)
            if (buffer_mutate(ctx, NULL, 1) != 0)
                return (-1);
        ctx->buffer[ctx->size++] = *format;
        if (*format == '\n')
            if (buffer_flush(ctx) != 0)
                return (-1);
        ++format;
    }
    return (0);
}
