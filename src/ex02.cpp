/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:29:51 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 13:59:30 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_lerp(T a, T b, double t, bool newlines = false)
{
	if (!newlines)
	{
		std::cout << YELLOW << t * 100 << '%' << RESET
				  << "\t| " << YELLOW << a << RESET
				  << " -> " << YELLOW << b << RESET
				  << " = " << GREEN << lerp(a, b, t) << '\n' << RESET;
	}
	else
	{
		std::cout << YELLOW << a << RESET
				  << "and\n" << YELLOW << b << RESET
				  << "at " << YELLOW << t * 100 << '%' << RESET
				  << " becomes\n" << GREEN << lerp(a, b, t) << '\n' << RESET;
	}
}

void ex02()
{
	std::cout << PURPLE << "ex02 - Linear interpolation" << RESET << '\n';
	
	std::cout << BLUE << "Doubles:\n" << RESET;
	test_lerp(0., 1., 0.);
	test_lerp(0., 1., 1.);
	test_lerp(0., 1., 0.5);
	test_lerp(21., 42., 0.3);

	std::cout << BLUE << "\nVectors:\n" << RESET;
	test_lerp<Vector<2, double>>({2., 1.}, {4., 2.}, 0.3);

	std::cout << BLUE << "\nMatrices:\n" << RESET;
	Matrix<2, 2, double> m1({{2., 1.}, {3., 4.}});
	Matrix<2, 2, double> m2({{20., 10.}, {30., 40.}});
	test_lerp<Matrix<2, 2, double>>(m1, m2, 0.5, true);
}
