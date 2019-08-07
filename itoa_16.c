/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:11:52 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:06:56 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		count_of_digits(int n)
{
	int		ret;

	ret = 0;
	while (n > 0)
	{
		ret++;
		n /= 16;
	}
	return (ret);
}

char	to_ascii(int n)
{
	if (n < 10)
		return (n + 48);
	else if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	return (48);
}

char	*itoa_16(int n)
{
	char	*ret;
	int		tmp;
	int		count;
	int		i;

	count = count_of_digits(n);
	i = count - 1;
	ret = (char *)malloc(count + 1);
	while (i >= 0)
	{
		tmp = n % 16;
		ret[i] = to_ascii(tmp);
		i--;
		n /= 16;
	}
	ret[count] = 0;
	return (ret);
}
