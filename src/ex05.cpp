/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:31:07 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 22:36:39 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex05()
{
	std::cout << std::setprecision(10);
	{
		Vector<2, double> u({ 1., 0. });
		Vector<2, double> v({ 1., 0. });
		std::cout << angle_cos(u, v) << '\n';
	}

	{
		Vector<2, double> u({ 1., 0. });
		Vector<2, double> v({ 0., 1. });
		std::cout << angle_cos(u, v) << '\n';
	}

	{
		Vector<2, double> u({ -1., 1. });
		Vector<2, double> v({ 1., -1. });
		std::cout << angle_cos(u, v) << '\n';
	}

	{
		Vector<2, double> u({ 2., 1. });
		Vector<2, double> v({ 4., 2. });
		std::cout << angle_cos(u, v) << '\n';
	}

	{
		Vector<3, double> u({ 1., 2., 3. });
		Vector<3, double> v({ 4., 5., 6. });
		std::cout << angle_cos(u, v) << '\n';
	}
}
