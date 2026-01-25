/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:27:15 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/25 20:27:40 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

int	ft_atoi(std::string nptr)
{
	int	ans;
	int	i;
	int	neg;

	i = 0;
	ans = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ans * 10 + nptr[i] - '0';
		i++;
	}
	return (ans * neg);
}
