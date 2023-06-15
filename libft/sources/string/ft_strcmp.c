/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:50:22 by maolivei          #+#    #+#             */
/*   Updated: 2023/04/25 13:30:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*us1 = (unsigned char *)s1;
	const unsigned char	*us2 = (unsigned char *)s2;

	while (*us1 || *us2)
		if (*us1++ != *us2++)
			return (*(us1 - 1) - *(us2 - 1));
	return (0);
}
