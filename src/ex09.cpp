/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:49:55 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/02 15:54:18 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_transpose(T matrix)
{
	std::cout << YELLOW << "A =\n" << matrix << BLUE << "Aᵀ =\n" << GREEN << matrix.transpose() << '\n';
}

void ex09()
{
	std::cout << PURPLE << "ex09 - Transpose" << RESET << '\n';

	test_transpose<Matrix<3, 3, int>>({
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }	
	});

	test_transpose<Matrix<2, 3, char>>({
		{ 'a', 'b', 'c' },
		{ 'd', 'e', 'f' }
	});

	test_transpose<Matrix<5, 3, int>>({
		{ 1, 4, 3 },
		{ 8, 2, 6 },
		{ 7, 8, 3 },
		{ 4, 9, 6 },
		{ 7, 8, 1 }
	});
}
