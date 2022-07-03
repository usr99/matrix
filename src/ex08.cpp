/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:49:55 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/02 15:48:09 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_trace(T matrix)
{
	std::cout << YELLOW << "A =\n" << matrix << BLUE << "Tr(A) = " << GREEN << matrix.trace() << "\n\n";
}

void ex08()
{
	std::cout << PURPLE << "ex08 - Trace" << RESET << '\n';

	test_trace<Matrix<2, 2, double>>({
		{ 1., 0. },
		{ 0., 1. }
	});

	test_trace<Matrix<3, 3, double>>({
		{2., -5., 0.},
		{4., 3., 7.},
		{-2., 3., 4.}
	});

	test_trace<Matrix<3, 3, double>>({
		{-2., -8., 4.},
		{1., -23., 4.},
		{0., 6., 4.}
	});
}
