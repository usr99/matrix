/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:02:04 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/02 18:28:50 by mamartin         ###   ########.fr       */
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
	Matrix<3, 3, double> tmp;
	double det = 0.;

	// for each column
	for (int current = 0; current < 4; current++)
	{
		// create a 3x3 matrix with the values that are not in the first row nor the current column
		for (int row = 1; row < 4; row++)
		{
			int c = 0;
			for (int column = 0; column < 4; column++)
			{
				if (column != current)
				{
					tmp[row - 1][c] = _mData[row][column];
					c++;
				}
			}
		}

		// add or substract the product of the value in the current column with the determinant of this new matrix
		if (current % 2 == 0)
			det = std::fma(_mData[0][current], tmp.determinant(), det);
		else
			det = std::fma(-_mData[0][current], tmp.determinant(), det);
	}
	return det;
}

template <typename T>
void test_determinant(T matrix)
{
	std::cout << YELLOW << "A =\n" << matrix << BLUE << "det(A) = " << GREEN << matrix.determinant() << "\n\n";
}

void ex11()
{
	std::cout << PURPLE << "ex11 - Determinant" << RESET << '\n';

	std::cout << BLUE << "\nBasic tests" << RESET << '\n';
	test_determinant<Matrix<2, 2, double>>({
		{  1, -1 },
		{ -1,  1 }
	});
	test_determinant<Matrix<3, 3, double>>({
		{  2, 0, 0 },
		{  0, 2, 0 },
		{  0, 0, 2 }		
	});
	test_determinant<Matrix<3, 3, double>>({
		{  8, 5, -2 },
		{  4, 7,  20 },
		{  7, 6,  1 }		
	});
	test_determinant<Matrix<4, 4, double>>({
		{  8,  5, -2, 4 },
		{  4,  2.5, 20, 4 },
		{  8,  5, 1, 4 },
		{  28, -4, 17, 1 }
	});

	std::cout << BLUE << "\nMore tests" << RESET << '\n';
	test_determinant<Matrix<2, 2, double>>({
		{  18, 21 },
		{ -42, 3 }
	});
	test_determinant<Matrix<3, 3, double>>({
		{  2, 1, 3 },
		{ -1, 1, 0 },
		{ -2, 4, 1 }
	});
	test_determinant<Matrix<4, 4, double>>({
		{  2,  4, 0, 6 },
		{ -1,  0, 7, 0 },
		{  3,  7, 0, 0 },
		{  4, -2, 0, 5 }		
	});	
}
