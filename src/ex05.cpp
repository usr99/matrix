/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:31:07 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 16:05:41 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_cosine(T u, T v)
{
	std::cout	<< "Cosine of the angle between "
				<< YELLOW << u << RESET
				<< " and "
				<< YELLOW << v << RESET
				<< " is "
				<< GREEN << angle_cos(u, v) << '\n' << RESET;
}

void ex05()
{
	std::cout << PURPLE << "ex05 - Cosine" << RESET << '\n';
	std::cout << std::setprecision(10);

	test_cosine<Vector<2, double>>({1., 0.}, {1., 0.});
	test_cosine<Vector<2, double>>({1., 0.}, {0., 1.});
	test_cosine<Vector<2, double>>({-1., 1.}, {1., -1.});
	test_cosine<Vector<2, double>>({2., 1.}, {4., 2.});
	test_cosine<Vector<3, double>>({1., 2., 3.}, {4., 5., 6.});
}
