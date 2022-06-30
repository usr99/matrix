/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:49:55 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 16:28:43 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename Mat, typename Vec>
void test_mat_vec(Mat m, Vec v)
{
	std::cout	<< YELLOW << m << RESET
				<< " * " << YELLOW << v << RESET
				<< " = " << GREEN << m * v << RESET << "\n\n";
}

template <typename MatA, typename MatB>
void test_mat_mat(MatA u, MatB v)
{
	std::cout	<< YELLOW << u << RESET
				<< " *\n" << YELLOW << v << RESET
				<< " =\n" << GREEN << u * v << RESET << "\n\n";
}


void ex07()
{
	std::cout << PURPLE << "ex07 - Linear map, Matrix multiplication" << RESET << '\n';
	
	std::cout << BLUE << "Matrix / Vector multiplication" << RESET << '\n';
	test_mat_vec<Matrix<2, 2, double>, Vector<2, double>>({
		{ 1., 0. },
		{ 0., 1. },
	},
		{ 4., 2. }
	);
	test_mat_vec<Matrix<2, 2, double>, Vector<2, double>>({
		{ 2., 0. },
		{ 0., 2. }
	},
		{ 4., 2. }
	);
	test_mat_vec<Matrix<2, 2, double>, Vector<2, double>>({
		{ 2., -2. },
		{ -2., 2. }
	},
		{ 4., 2. }
	);

	std::cout << BLUE << "Matrix multiplication" << RESET << '\n';
	test_mat_mat<Matrix<2, 2, double>, Matrix<2, 2, double>>({
		{ 1., 0. },
		{ 0., 1. }
	},{
		{ 1., 0.},
		{ 0., 1.}
	});
	test_mat_mat<Matrix<2, 2, double>, Matrix<2, 2, double>>({
		{ 1., 0. },
		{ 0., 1. }
	},{
		{ 2., 1.},
		{ 4., 2.}
	});
	test_mat_mat<Matrix<2, 2, double>, Matrix<2, 2, double>>({
		{ 3., -5. },
		{ 6., 8. }
	},{
		{ 2., 1.},
		{ 4., 2.}
	});
	test_mat_mat<Matrix<3, 2, double>, Matrix<2, 3, double>>({
		{ 3., -5. },
		{ 6., 8. },
		{ 21., 18. },
	},{
		{ 2., 1., 0. },
		{ 4., 2., 0. }
	});
}
