/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:34:05 by psprawka          #+#    #+#             */
/*   Updated: 2017/11/27 11:34:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** print_width prints both precision and width for either characher or string
*/

void	parse(t_flags *bag)
{
	ZERO = PRECISION < 0 ? false : ZERO;
	LEN = (PRECISION < LEN && IF_PREC == true) ? PRECISION : LEN;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH - LEN;
	WIDTH = (TYPE == 'c' && PRECISION < 0) ? 0 : WIDTH;
}

/*
** ----------------------- STRING - s | WSTRING - S ----------------------------
*/

void	print_string(t_flags *bag, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	str = (str == NULL ? "(null)" : str);
	if (colors(str, bag) == 1)
		return ;
	LEN = ft_strlen(str);
	parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	while (LEN-- > 0 && *str != '\0')
		ft_putchar(*str++, bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
}

void	print_wchar_str(t_flags *bag, va_list ap)
{
	char	*str;
	wchar_t	*wstr;

	wstr = (wchar_t *)va_arg(ap, wchar_t *);
	str = ARGUMENT == 7 ? convert_uni(*wstr++) : conv_w(wstr, ft_wstrlen(wstr));
	if (ft_wstrlen(wstr) == -1 && ARGUMENT != 7)
	{
		free(str);
		return ;
	}
	while (*wstr != '\0' && ARGUMENT == 7)
		str = ft_strjoin(str, convert_uni(*wstr++));
	LEN = ft_strlen(str);
	parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	while (LEN-- > 0 && *str != '\0')
		ft_putchar(*str++, bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
	free(str);
}

/*
** ----------------------------- CHAR - c, C -----------------------------------
*/

void	print_char(t_flags *bag, va_list ap)
{
	unsigned char x;

	x = (unsigned char)va_arg(ap, int);
	LEN = 1;
	parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	ft_putchar(x, bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
}

void	print_wchar(t_flags *bag, va_list ap)
{
	char	*x;
	wchar_t	wx;

	wx = va_arg(ap, wint_t);
	x = convert_uni((wchar_t)(wx));
	LEN = 1;
	parse(bag);
	while (MINUS == false && WIDTH-- > 0)
		ZERO == true ? ft_putchar('0', bag) : ft_putchar(' ', bag);
	ft_putstr(x, bag);
	while (WIDTH-- > 0)
		ft_putchar(' ', bag);
	free(x);
}
