/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:20:19 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/16 22:20:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t get_number_length(long num, int base)
{
    size_t length;

    if (num == 0)
        return (1);
    length = 0;
    if (num < 0)
    {
        ++length;
        num = -num;
    }
    while (num != 0)
    {
        ++length;
        num /= base;
    }
    return (length);
}
