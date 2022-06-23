/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:02:04 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/24 01:06:28 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <>
double Matrix<2, 2, double>::determinant() const
{
	return std::fma(_mData[0][0], _mData[1][1], -(_mData[0][1] * _mData[1][0]));
}

template <>
double Matrix<3, 3, double>::determinant() const
{
	// [ a, b, c ]
	// [ d, e, f ]
	// [ g, h, i ]

	// aei + dhc + bfg - gec - dbi - ahf
	// a(ei - hf) + d(hc - bi) + g(bf - ec)
	return std::fma(
		_mData[0][0], std::fma(_mData[1][1], _mData[2][2], -(_mData[2][1] * _mData[1][2])), // a * (e * i - h * f)
		std::fma(
			_mData[1][0], std::fma(_mData[2][1], _mData[0][2], -(_mData[0][1] * _mData[2][2])), // d * (h * c - b * i)
			_mData[2][0] * std::fma(_mData[0][1], _mData[1][2], -(_mData[1][1] * _mData[0][2])) // g * (b * f - e * c)
	));
}

template <>
double Matrix<4, 4, double>::determinant() const
{
	for (int i = 0; i < 4; i++)
	{
		
	}
}

void ex11()
{
	Matrix<3, 3, double> m({
		{  2, 1, 3 },
		{ -1, 1, 0 },
		{ -2, 4, 1 },
	});

	std::cout << m.determinant() << '\n';
}
