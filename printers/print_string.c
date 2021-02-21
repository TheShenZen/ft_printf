/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:55:43 by seciurte          #+#    #+#             */
/*   Updated: 2021/02/20 11:20:33 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void		print_flag(t_format f_info, int *c_disp)
{
	int			n;
	char		c;

	if (f_info.width < 0)
		f_info.width *= -1;
	c = ' ';
	if (f_info.precision == '.' && f_info.length <= f_info.len_format
			&& f_info.length >= 0)
		n = f_info.width - f_info.length;
	else
		n = f_info.width - f_info.len_format;
	print_nchar(n, c);
	if (n > 0)
		(*c_disp) += n;
}

void			print_string(t_format *f_info, int *c_disp)
{
	if (f_info->flag == '?' && f_info->width > 0)
		print_flag(*f_info, c_disp);
	if (f_info->precision != '?'
			&& f_info->length >= 0 && f_info->length <= f_info->len_format
			&& f_info->conv_format != NULL)
	{
		write(1, f_info->conv_format, f_info->length);
		(*c_disp) += f_info->length;
	}
	else
	{
		write(1, f_info->conv_format, f_info->len_format);
		(*c_disp) += f_info->len_format;
	}
	if (f_info->flag == '-' || f_info->width < 0)
		print_flag(*f_info, c_disp);
}
