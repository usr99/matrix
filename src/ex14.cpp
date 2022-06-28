/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:21:21 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/28 23:51:28 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

Matrix<4, 4, float> projection(float fov, float ratio, float near, float far)
{
	float fov_factor = 1 / my_tan(fov / 2);
	float z_ratio = far / (far - near);

	return Matrix<4, 4, float>({
		{ ratio * fov_factor,	0,			0,			0 },
		{ 0,					fov_factor,	0,			0 },
		{ 0,					0,			z_ratio,	-z_ratio * near },
		{ 0,					0,			1,			0 }
	});
}

void ex14()
{
	std::cout << projection(to_radians(70.f), 800.f / 600.f, 1.f, 100.f) << '\n';
}