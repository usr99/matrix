/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:49:55 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/02 16:06:15 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_rref(T matrix)
{
	std::cout << YELLOW << "A =\n" << matrix << BLUE << "Reduced row-echelon form of A is:\n" << GREEN << matrix.row_echelon() << '\n';
}

void ex10()
{
	std::cout << PURPLE << "ex10 - Reduced row-echelon form" << RESET << '\n';

	test_rref(Matrix<3, 3, double>());

	test_rref<Matrix<2, 2, double>>({
		{ 1., 2. }, 
		{ 3., 4. }	
	});
	
	test_rref<Matrix<2, 2, double>>({
		{ 1., 2. },
		{ 2., 4. }		
	});
	
	test_rref<Matrix<3, 5, double>>({
		{8., 5., -2., 4., 28.},
		{4., 2.5, 20., 4., -4.},
		{8., 5., 1., 4., 17.}		
	});	
}
