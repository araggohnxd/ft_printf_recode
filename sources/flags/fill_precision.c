/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:09:07 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:30:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_true_precision(int length, int precision)
{
    int true_precision;

    true_precision = precision - length;
    if (true_precision < 0)
        true_precision = 0;
    return (true_precision);
}
