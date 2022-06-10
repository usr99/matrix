/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:15:10 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 18:18:31 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex03()
{
	{
		Vector<2, double> u({0., 0.});
		Vector<2, double> v({1., 1.});
		std::cout << u.dot(v) << '\n';
	}

	{
		Vector<2, double> u({1., 1.});
		Vector<2, double> v({1., 1.});
		std::cout << u.dot(v) << '\n';
	}

	{
		Vector<2, double> u({-1., 6.});
		Vector<2, double> v({3., 2.});
		std::cout << u.dot(v) << '\n';
	}
}
