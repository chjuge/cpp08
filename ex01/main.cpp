/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/09 12:56:56 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span span1(5);

	span1.addNumber(4);
	try
	{
		cout << span1 << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	span1.addNumber(7);
	cout << span1 << endl;
	span1.addNumber(2);
	cout << span1 << endl;
	span1.addNumber(6);
	cout << span1 << endl;
	span1.addNumber(25);
	cout << span1 << endl;

	cout << endl;
	try
	{
		span1.addNumber(4);
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << span1 << endl;
	cout << endl;

	// Span span2(5000000);
	// Span span2(10000);
	// Span span2(500);
	Span span2(20);

	span2.addNumber(3);
	span2.fillRandom();
	cout << span2 << endl << endl;


	Span span3(5);
	vector<int> vect;

	vect.push_back(25); //0
	vect.push_back(5);	//1
	vect.push_back(12);	//2
	vect.push_back(90);	//3
	vect.push_back(-2);	//4
	
	cout << "span 3!!!" << endl;
	span3.addByIteratorRange(vect.begin(), vect.end());
	cout << span3 << endl;
	cout << (span3.getStorage())[4] << endl;

	cout << endl;
	cout << "Main from subject" << endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}
