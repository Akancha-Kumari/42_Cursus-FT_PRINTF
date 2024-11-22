/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:17:24 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 09:11:23 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long num, int format, int *count)
{
	int		value;
	char	*hex;

	value = 0;
	if (num > 15)
	{
		ft_puthex(num / 16, format, count);
	}
	if (format == 'x')
	{
		hex = "0123456789abcdef";
		value = num % 16;
		write(1, &hex[value], 1);
		(*count)++;
	}
	else
	{
		hex = "0123456789ABCDEF";
		value = num % 16;
		write(1, &hex[value], 1);
		(*count)++;
	}
}
