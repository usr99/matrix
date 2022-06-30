/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:17:42 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 11:57:59 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex00()
{
	std::cout << PURPLE << "ex00 - Add, Substract and Scale" << RESET << '\n';

	{
		Vector<2, double> u({2., 3.});
		const Vector<2, double> v({5., 7.});

		std::cout << BLUE << "Vectors:" << RESET << '\n';
		std::cout << u << " + " << v << " = " << u + v << '\n';
		std::cout << u << " - " << v << " = " << u - v << '\n';
		std::cout << u << " * 2 = " << u * 2 << '\n';
		std::cout << '\n';
	}

	{
		Matrix<2, 2, double> u({{1., 2.},
								{3., 4.}});

		const Matrix<2, 2, double> v({{ 7., 4.},
									  {-2., 2.}});

		std::cout << BLUE << "Matrices:" << RESET << '\n';
		std::cout << "u =\n" << u << '\n';
		std::cout << "v =\n" << v << '\n';

		std::cout << "u + v =\n" << u + v << '\n';
		std::cout << "u - v =\n" << u - v << '\n';
		std::cout << "u * 2 =\n" << u * 2. << '\n';
	}
}
