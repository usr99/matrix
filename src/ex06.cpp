/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:41:54 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 16:11:35 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_cross_product(Vector<3, T> u, Vector<3, T> v)
{
	std::cout	<< YELLOW << u << RESET
				<< " x "
				<< YELLOW << v << RESET
				<< " = " << GREEN << cross_product(u, v) << RESET << '\n';
}

void ex06()
{
	std::cout << PURPLE << "ex06 - Cross product" << RESET << '\n';

	test_cross_product<double>({ 0., 0., 1. }, { 1., 0., 0. });
	test_cross_product<double>({ 1., 2., 3. }, { 4., 5., 6. });
	test_cross_product<double>({ 4., 2., -3. }, { -2., -5., 16. });
}
