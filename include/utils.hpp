/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:21:33 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 15:56:20 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# define PI 3.141592653589793238462643383279502884L

template <typename T>
T my_abs(T value)
{
	return std::max(value, -value);
}

#endif
