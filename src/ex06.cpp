/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:41:54 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 23:36:37 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex06()
{
	{
		Vector<3, double> u({ 0., 0., 1. });
		Vector<3, double> v({ 1., 0., 0. });
		std::cout << cross_product(u, v) << '\n';
	}

	{
		Vector<3, double> u({ 1., 2., 3. });
		Vector<3, double> v({ 4., 5., 6. });
		std::cout << cross_product(u, v) << '\n';
	}

	{
		Vector<3, double> u({ 4., 2., -3. });
		Vector<3, double> v({ -2., -5., 16. });
		std::cout << cross_product(u, v) << '\n';
	}
}
