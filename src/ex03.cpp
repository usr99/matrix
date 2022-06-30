/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:15:10 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 15:33:36 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_dot(T u, T v)
{
	std::cout	<< YELLOW << u << RESET
				<< "\t• " << YELLOW << v << RESET
				<< " = " << GREEN << u.dot(v) << RESET << '\n';
}

void ex03()
{
	std::cout << PURPLE << "ex03 - Dot product" << RESET << '\n';
	test_dot<Vector<2, double>>({0., 0.}, {1., 1.});
	test_dot<Vector<2, double>>({1., 1.}, {1., 1.});
	test_dot<Vector<2, double>>({-1., 6.}, {3., 2.});
}
