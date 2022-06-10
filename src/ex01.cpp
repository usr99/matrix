/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:56:52 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/08 22:59:23 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include <chrono>

void ex01()
{
	Vector<3, double> e1({1., 0., 0.});
	Vector<3, double> e2({0., 1., 0.});
	Vector<3, double> e3({0., 0., 1.});

	Vector<3, double> v1({1., 2., 3.});
	Vector<3, double> v2({0., 10., -100.});

	std::cout << linear_combination(std::vector<Vector<3, double>>({ e1, e2, e3 }), { 10., -2., 0.5 }) << '\n';
	std::cout << linear_combination(std::vector<Vector<3, double>>({ v1, v2 }), { 10., -2. }) << '\n';

// 	auto start = std::chrono::high_resolution_clock::now();
// 	for (int i = 0; i < 100000; i++)
// 		linear_combination(std::vector<Vector<3, double>>({e1, e2, e3}), {10., -2., 0.5});
// 	auto end = std::chrono::high_resolution_clock::now();
// 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
// 	std::cout << duration.count() << "µs\n";
}
