/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:33:21 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 09:11:58 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *count)
{
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
		ft_putnbr(num, count);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10, count);
		ft_putnbr(num % 10, count);
	}
	else
		ft_putchar(num + 48, count);
}
