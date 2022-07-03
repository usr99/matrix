/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:21:53 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/03 15:13:09 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_rank(T matrix)
{
	std::cout << YELLOW << "A =\n" << matrix << BLUE << "rank(A) = " << GREEN << matrix.rank() << '\n';
}

void ex13()
{
	std::cout << PURPLE << "ex13 - Rank" << RESET << '\n';
	std::cout << BLUE << "\nBasic tests" << RESET << '\n';

	test_rank(Matrix<3, 3, double>());
	test_rank<Matrix<3, 3, double>>({
		{  1, 2, 0, 0 },
		{  2, 4, 0, 0 },
		{ -1, 2, 1, 1 }
	});
	test_rank<Matrix<4, 3, double>>({
		{ 8,  5,  -2 },
		{ 4,  7,  20 },
		{ 7,  6,  1 },
		{ 21, 18, 7 }
	});

	std::cout << BLUE << "\nMore tests" << RESET << '\n';

	test_rank<Matrix<3, 5, double>>({
		{8., 5., -2., 4., 28.},
		{4., 2.5, 20., 4., -4.},
		{8., 5., 1., 4., 17.}
	});
}
