/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:56:52 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/30 13:45:57 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

typedef std::vector<Vector<3, double>> vector_type;

void ex01()
{
	std::cout << PURPLE << "ex01 - Linear combination" << RESET << '\n';

	Vector<3, double> e1({1., 0., 0.});
	Vector<3, double> e2({0., 1., 0.});
	Vector<3, double> e3({0., 0., 1.});

	Vector<3, double> v1({1., 2., 3.});
	Vector<3, double> v2({0., 10., -100.});

	std::vector<std::pair<double, Vector<3, double>>> inputs({
		std::make_pair(10., e1),
		std::make_pair(-2., e2),
		std::make_pair(0.5, e3),
		std::make_pair(10., v1),
		std::make_pair(-2., v2)
	});

	auto print_test = [&](int start, int last) {
		std::cout << BLUE;
		for (int i = start; i < last; i++)
		{
			std::cout	<< inputs[i].first << " * " << inputs[i].second << ' '
						<< (i == last - 1 ? '=' : '+') << ' ';
		}
	};

	print_test(0, 3);
	std::cout << YELLOW << linear_combination(vector_type({ e1, e2, e3 }), { 10., -2., 0.5 }) << RESET << '\n';

	print_test(3, 5);
	std::cout << YELLOW << linear_combination(vector_type({ v1, v2 }), { 10., -2 }) << RESET << '\n';
}
