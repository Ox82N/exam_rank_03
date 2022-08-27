/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:11:12 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/29 16:11:26 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int  g_var = 0;

void	write_number_1(unsigned long len, unsigned long base, char *str)
{
	if (len < base)
	{
		write(1, &str[len], 1);
		g_var += 1;
	}
	else
	{
		write_number_1(len / base, base, str);
		write_number_1(len % base, base, str);
	}
}

void	write_number_x(unsigned int len, unsigned int base, char *str)
{
	if (len < base)
	{
		write(1, &str[len], 1);
		g_var += 1;
	}
	else
	{
		write_number_1(len / base, base, str);
		write_number_1(len % base, base, str);
	}
}

int ft_printf(const char *format, ...)
{
	va_list		a;
	long long	b;
	char		*str;
	int			len;
	int			x;

	g_var = 0;
	va_start(a, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				len = 0;
				str = va_arg(a, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				g_var += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				b = va_arg(a, int);
				if (b < 0)
				{
					write(1, "-", 1);
					g_var++;
					b = -b;
				}
				write_number_1(b, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				x = va_arg(a, int);
				write_number_x(x, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(a);
	return(g_var);
}