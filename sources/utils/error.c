/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:04:02 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/15 14:31:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int error(t_buffer *ctx)
{
	free(ctx->buffer);
	ctx->buffer = NULL;
	ctx->size = -1;
	return (-1);
}
