/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:19:22 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 15:57:51 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <typename T>
void test_norm(T vector)
{
	std::cout 	<< YELLOW << vector << '\t' << RESET
				<< vector.norm_1() << '\t'
				<< vector.norm() << '\t'
				<< vector.norm_inf() << '\n';
}

void ex04()
{
	std::cout << PURPLE << "ex04 - Norm" << RESET << '\n';
	std::cout << std::setprecision(6);

	std::cout << BLUE << "vector\t\tnorm_1\tnorm\tnorm_inf" << RESET << '\n';
	test_norm<Vector<3, double>>({0., 0., 0.});
	test_norm<Vector<3, double>>({1., 2., 3.});
	test_norm<Vector<2, double>>({-1., -2.});
}
