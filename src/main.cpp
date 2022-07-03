/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:19:49 by mamartin          #+#    #+#             */
/*   Updated: 2022/07/03 13:52:03 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include <cmath>

int main(int ac, char **av)
{
	std::vector<std::function<void(void)>> tests({
		ex00, ex01, ex02, ex03, ex04, ex05, ex06, ex07, ex08,
		ex09, ex10, ex11, ex12, ex13
	});

	try
	{
		if (ac == 1)
		{
			for (auto t = tests.begin(); t != tests.end(); t++)
				(*t)();
		}
		else if (ac == 2)
		{
			const std::string arg = av[1];
			if (!std::all_of(arg.begin(), arg.end(), [](char c) { return std::isdigit(c); }))
				throw std::invalid_argument("argument must be a positive integer");

			size_t num = std::atoi(av[1]);
			if (num < tests.size())
				tests[num]();
			else
				throw std::invalid_argument("There is no exercise #" + std::to_string(num));
		}
		else
			throw std::invalid_argument("bad arguments !\nusage: ./tester.out [exercise index]");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return -1;
	}

	return 0;
}
