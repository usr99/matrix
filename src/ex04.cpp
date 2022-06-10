/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:19:22 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 22:35:29 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex04()
{
	std::cout << std::setprecision(10);
	{
		Vector<3, double> u({ 0., 0., 0. });
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << '\n';
	}

	{
		Vector<3, double> u({ 1., 2., 3. });
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << '\n';
	}

	{
		Vector<2, double> u({ -1., -2. });
		std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << '\n';
	}		
}
