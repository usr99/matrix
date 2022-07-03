/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:39 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/02 18:35:49 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_inverse(T matrix)
{
	try {
		std::cout << YELLOW << "A =\n" << matrix << BLUE;

		auto inv = matrix.inverse();
		std::cout << "A⁻¹ =\n" << GREEN << inv << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n\n";
	}
}

void ex12()
{
	std::cout << PURPLE << "ex12 - Inverse" << RESET << '\n';

	std::cout << BLUE << "\nBasic tests" << RESET << '\n';
	test_inverse(Matrix<3, 3, double>());
	test_inverse(Matrix<3, 3, double>() * 2);
	test_inverse<Matrix<3, 3, double>>({
		{ 8, 5, -2 },
		{ 4, 7, 20 },
		{ 7, 6, 1 }
	});

	std::cout << BLUE << "\nMore tests" << RESET << '\n';
	test_inverse<Matrix<2, 2, double>>({
		{ 3, 2 },
		{ 4, 1 }
	});
	test_inverse<Matrix<3, 3, double>>({
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	});
	test_inverse<Matrix<3, 3, double>>({
		{ 1,  0, -1 },
		{ 1, -1,  0 },
		{ 1, -1,  1 }
	});
}
