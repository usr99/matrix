/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:49:55 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/10 00:36:07 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex07()
{
	{
		Matrix<2, 2, double> u({
			{ 1., 0. },
			{ 0., 1. }
		});

		Vector<2, double> v({ 4., 2.});
		std::cout << u * v << '\n';
	}

	{
		Matrix<2, 2, double> u({
			{ 2., 0. },
			{ 0., 2. }
		});

		Vector<2, double> v({ 4., 2.});
		std::cout << u * v << '\n';
	}

	{
		Matrix<2, 2, double> u({
			{ 2., -2. },
			{ -2., 2. }
		});

		Vector<2, double> v({ 4., 2.});
		std::cout << u * v << '\n';
	}

}
