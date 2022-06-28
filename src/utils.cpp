/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:45:26 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/27 21:25:21 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "utils.hpp"

double my_sin(double angle)
{
	double result = 0.;
	int sign = 1;
	int factorial = 1;

	angle = my_mod(angle + PI, 2 * PI) - PI;

	double power = angle;
	for (int i = 0; i < 10; i++)
	{
		result += (power / factorial) * sign;
		
		sign *= -1;
		factorial *= (i + 1) * (i + 2);
		power *= (angle * angle);
	}
	return result;
}

double my_cos(double angle)
{
	double result = 0.;
	int sign = 1;
	int factorial = 1;

	angle = my_mod(angle + PI, 2 * PI) - PI;

	double power = 1;
	for (int i = 0; i < 10; i++)
	{
		result += (power / factorial) * sign;
		
		sign *= -1;
		factorial *= (i + 1) * (i + 2);
		power *= (angle * angle);
	}
	return result;
}

double my_tan(double angle)
{
	return my_sin(angle) / my_cos(angle);
}

double to_radians(double degrees)
{
	return degrees * PI / 180;
}
