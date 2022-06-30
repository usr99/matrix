/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:21:33 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 11:49:16 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define PI 3.141592653589793238462643383279502884L

template <typename T>
T my_abs(T value)
{
	return value > 0 ? value : -value;
}

template <typename T>
T my_pow(T x, unsigned int y)
{
	if (y == 0)
		return 1;
	return x * my_pow(x, y - 1); 
}

template <typename T>
T my_mod(T a, T b)
{
	while (a > b)
		a -= b;
	return a;
}

#endif
