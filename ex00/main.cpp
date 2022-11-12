/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:07:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/09 10:59:39 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> vect;
	std::vector<int>::iterator	it;

	for (int i = 1; i < 42; i += 2)
		vect.push_back(i);
	it = easyfind(vect, 21);
	printIter(it, vect.end());
	it = easyfind(vect, 43);
	printIter(it, vect.end());
	std::cout << std::endl;
	return (0);
}
