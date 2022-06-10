/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:29:51 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 23:49:21 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex02()
{
	std::cout << "Double\n";
	std::cout << lerp(0., 1., 0.) << '\n';
	std::cout << lerp(0., 1., 1.) << '\n';
	std::cout << lerp(0., 1., 0.5) << '\n';
	std::cout << lerp(21., 42., 0.3) << '\n';

	std::cout << "\nVector\n";
	Vector<2, double> v1({2., 1.});
	Vector<2, double> v2({4., 2.});
	std::cout << lerp(v1, v2, 0.3) << '\n';

	std::cout << "\nMatrix\n";
	Matrix<2, 2, double> m1({{2., 1.}, {3., 4.}});
	Matrix<2, 2, double> m2({{20., 10.}, {30., 40.}});
	std::cout << lerp(m1, m2, 0.5) << '\n';
}
