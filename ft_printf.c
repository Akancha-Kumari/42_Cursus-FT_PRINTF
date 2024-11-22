/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:41:13 by akumari           #+#    #+#             */
/*   Updated: 2024/11/22 09:23:01 by akumari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type(const char *format, int *i, va_list arg, int *count)
{
	if (format[*i] == '%')
		ft_putchar('%', count);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (format[*i] == 'p')
		ft_putptr(va_arg(arg, unsigned long long), count);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(arg, unsigned int), count);
	else if (format[*i] == 'x' || format[*i] == 'X')
		ft_puthex(va_arg(arg, unsigned int), format[*i], count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_type(format, &i, arg, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	char ch = 'a';
// 	ft_printf("%c\n", ch);
// 	char *str = "akancha";
// 	ft_printf("%s\n", str);
// 	int num = -5326626;
// 	ft_printf("%d\n", num);
// 	ft_printf("%i\n", num);
// 	char *ptr = "10";
// 	ft_printf("%p\n", &ptr); // 0x16f21f5f0
// 	ft_printf("%u\n", num);
// 	unsigned int val = 7685;
// 	ft_printf("%x\n", val); // 1e05
// 	ft_printf("%X\n", val); // 1E05
// 	return (0);
// }