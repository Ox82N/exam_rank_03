/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:18:36 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/24 15:35:55 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include <stdarg.h>

int write_string(char *str)
{
    int i = 0;

    if(!str)
        str = "(null)";
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return i;
}

int write_hexa(unsigned int i, int base)
{
    char *str = "0123456789abcdef";
    int count = 0;
    int n = i % base;

    if(i / base != 0)
        count += write_hexa(i / base, base);
    write(1, &str[n], 1);
    count++;
    return count;
}

int write_decimal(int i)
{
    int count = 0;
    
    if(i == -2147483648)
    {
        write(1, "-2147483648", 11);
        return 11;
    }
    if(i < 0)
    {
        write(1, "-", 1);
        i *= -1;
        count++;
    }
    count += write_hexa(i, 10);
    return count;
}

int	ft_printf(char *format, ...)
{
	int		count = 0;
	va_list	a;

	va_start(a, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				count += write_string(va_arg(a, char *));
			if (*format == 'd')
				count += write_decimal(va_arg(a, int));
			if (*format == 'x')
				count += write_hexa(va_arg(a, int), 16);
		}
		else
        {
            write(1, format, 1);
            count++;
        }
		format++;
	}
	va_end(a);
	return (count);
}
int main()
{
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}