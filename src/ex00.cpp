/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:17:42 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/08 16:52:20 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex00()
{
	{
		Vector<2, double> u({2., 3.});
		const Vector<2, double> v({5., 7.});

		std::cout << "Vectors\n";
		std::cout << u + v << '\n';
		std::cout << u - v << '\n';
		std::cout << u * 2. << '\n';
		std::cout << '\n';
	}

	{
		Matrix<2, 2, double> u({{1., 2.},
								{3., 4.}});

		const Matrix<2, 2, double> v({{ 7., 4.},
									  {-2., 2.}});

		std::cout << "Matrices\n";
		std::cout << u + v << '\n';
		std::cout << u - v << '\n';
		std::cout << u * 2. << '\n';
	}
}
