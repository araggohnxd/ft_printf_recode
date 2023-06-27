/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:12:54 by maolivei          #+#    #+#             */
/*   Updated: 2023/06/19 13:13:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool has_precision(t_flags *flags)
{
    return (flags->precision > -1);
}

t_bool has_width(t_flags *flags)
{
    return (flags->width > -1);
}
