/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:30 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 17:28:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_handler get_handler(int char_to_handle)
{
    static const t_handler handlers[__SCHAR_MAX__] = {
        [' '] = handler_flag_space,         ['#'] = handler_flag_hash,
        ['+'] = handler_flag_plus,          ['-'] = handler_flag_minus,
        ['.'] = handler_flag_precision,     ['%'] = handler_specifier_percent,
        ['0'] = handler_flag_zero,          ['1'] = handler_flag_width,
        ['2'] = handler_flag_width,         ['3'] = handler_flag_width,
        ['4'] = handler_flag_width,         ['5'] = handler_flag_width,
        ['6'] = handler_flag_width,         ['7'] = handler_flag_width,
        ['8'] = handler_flag_width,         ['9'] = handler_flag_width,
        ['X'] = handler_specifier_hex,      ['c'] = handler_specifier_character,
        ['s'] = handler_specifier_string,   ['p'] = handler_specifier_pointer,
        ['i'] = handler_specifier_decimal,  ['d'] = handler_specifier_decimal,
        ['u'] = handler_specifier_unsigned, ['x'] = handler_specifier_hex,
    };

    return (handlers[char_to_handle]);
}

static int skip_format(t_buffer *ctx)
{
    char *p;

    p = ft_memrchr(ctx->format, '%', ctx->offset);
    if (!p)
        return (-1);
    if (buffer_append(ctx, p, (&ctx->format[ctx->offset] - p + 2)) != 0)
        return (-1);
    ctx->offset += 2;
    return (0);
}

int handle_specifier_or_flag(t_buffer *ctx, va_list ap)
{
    char      char_to_handle;
    t_handler handler;

    char_to_handle = ctx->format[ctx->offset + 1];
    if (!char_to_handle)
        return (-1);
    if (char_to_handle == ' ' || char_to_handle == '+')
        if (has_precision(&ctx->flags) || has_width(&ctx->flags))
            return (skip_format(ctx));
    handler = get_handler(char_to_handle);
    if (!handler)
        return (skip_format(ctx));
    ++ctx->offset;
    return ((*handler)(ctx, ap));
}

int process_format_string(t_buffer *ctx, va_list ap)
{
    while (ctx->format[ctx->offset])
    {
        if (ctx->format[ctx->offset] == '%')
        {
            buffer_reset_flags(ctx);
            if (handle_specifier_or_flag(ctx, ap) != 0)
                return (-1);
            continue;
        }
        if (buffer_append_one(ctx, ctx->format[ctx->offset]) != 0)
            return (-1);
        if (ctx->format[ctx->offset] == '\n')
            if (buffer_flush(ctx) != 0)
                return (-1);
        ++ctx->offset;
    }
    return (0);
}
