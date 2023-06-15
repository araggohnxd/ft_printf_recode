/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:45:58 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 18:48:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int buffer_create(t_buffer *ctx, size_t capacity)
{
	ctx->buffer = malloc(capacity * sizeof(*ctx->buffer));
	if (!ctx->buffer)
		return (-1);
	ctx->capacity = capacity;
	ctx->size = 0;
	return (0);
}
