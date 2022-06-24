/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:39 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/24 14:19:35 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void ex12()
{
	{
		Matrix<3, 3, double> m;
		std::cout << m << '\n';
		std::cout << m.inverse() << "\n\n";
	}

	try
	{
		Matrix<3, 3, double> m({
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		});
		std::cout << m << '\n';
		std::cout << m.inverse() << "\n\n";
	} 
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n\n";
	}

	{
		Matrix<2, 2, double> m({
			{ 3, 2 },
			{ 4, 1 }
		});
		std::cout << m << '\n';
		std::cout << m.inverse() << "\n\n";
	}	

	{
		Matrix<3, 3, double> m({
			{ 1,  0, -1 },
			{ 1, -1,  0 },
			{ 1, -1,  1 }
		});
		std::cout << m << '\n';
		std::cout << m.inverse() << "\n\n";
	}	
}
