/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cap_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:42:17 by seciurte          #+#    #+#             */
/*   Updated: 2021/02/20 11:14:47 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		convert_cap_hexa(va_list *vargs, t_format *f_info)
{
	unsigned int		*n;

	n = malloc(sizeof(unsigned int));
	if (n == NULL)
		return (-1);
	*n = va_arg(*vargs, unsigned int);
	f_info->value = n;
	f_info->conv_format = ft_itoa_base(*n, CAP_BASE_HEXA);
	f_info->len_format = ft_strlen(f_info->conv_format);
	if (f_info->conv_format == NULL)
		return (-1);
	return (0);
}
