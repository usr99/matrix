/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:21:33 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 23:48:49 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <cmath>

template <typename T>
T lerp(const T& u, const T& v, float t)
{
	return std::fma((v - u), t, u);
}

template <typename T>
T abs(T value)
{
	return value > 0 ? value : -value;
}

#endif
