/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:04:02 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 20:19:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int error(t_buffer *ctx)
{
    free(ctx->buffer);
    ctx->buffer = NULL;
    ctx->size   = 0;
    return (-1);
}
