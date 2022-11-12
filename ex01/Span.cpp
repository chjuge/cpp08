/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:03 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/09 12:54:40 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _storedSize(0)
{
	// cout << "Default constructor called" << endl;
}

Span::Span(unsigned int storedSize): _storedSize(storedSize),
	_storage(0)
{
	// cout << "Standard constructor called" << endl;
}

Span::Span(Span const & src)
{
	// cout << "Copy constructor called" << endl;
	this->_storedSize = src._storedSize;
	this->_storage = src._storage;
}

Span::~Span()
{
	// cout << "Destructor called" << endl;
}

Span & Span::operator = (Span const & src)
{
	// cout << "Assignement operator called" << endl;
	
	if (this == &src)
		return *this;
	this->_storedSize = src._storedSize;
	this->_storage = src._storage;
	return *this;
}

std::ostream & operator << (std::ostream & stream, Span const & src)
{
	int	shortest = src.shortestSpan();
	int	longest = src.longestSpan();

	stream << "Span of max size " << src.maxSize() << " contains ";
	stream << src.size() << " numbers, shortest span is ";
	stream << shortest << " and longest is " << longest;

	return stream;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void Span::fillRandom()
{
	unsigned int numbersToFill = this->spaceLeft();

	cout << "randomFill function called" << endl;

	for (unsigned int i = 0; i < numbersToFill; i++)
		this->addNumber(rand() % (this->maxSize() * 10));
}

unsigned int Span::size() const
{
	return _storage.size();
}

unsigned int Span::maxSize() const
{
	return _storedSize;
}

unsigned int Span::spaceLeft() const
{
	return maxSize() - size();
}

vector<int>  &  Span::getStorage()
{
	return this->_storage;
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void Span::addNumber(int number)
{
	cout << "addNumber [" << number << "]"	<< endl;

	if (_storage.size() == _storedSize)
		throw std::out_of_range("Cannot add any more numbers");

	_storage.push_back(number);
}

int	Span::shortestSpan() const
{
	vector<int> tmp = _storage;
	vector<int>::iterator it;
	int res = -1;

	if (_storage.size() <= 1)
		throw std::logic_error("Not enough numbers stored to provide a span");

	sort(tmp.begin(), tmp.end());
	res = *(tmp.begin() + 1) - *tmp.begin();
	if (this->size() == 2)
		return res;
	for (it = tmp.begin() + 1; it != tmp.end() - 1 && res != 0; it++)
	{
		if (*(it + 1) - *it < res)
			res = *(it + 1) - *it;
	}
	return res;
}

int	Span::longestSpan() const
{
	vector<int> tmp = _storage;

	if (_storage.size() <= 1)
		throw std::logic_error("Not enough numbers stored to provide a span");

	// sort(tmp.begin(), tmp.end());
	// return *(tmp.end() - 1) - *tmp.begin();

	vector<int>::iterator it = tmp.begin();
	vector<int>::iterator min = it;
	vector<int>::iterator max = it;
	while (it != tmp.end())
	{
		if (*it < *min)
			min = it;
		else if (*it > *max)
			max = it;
		++it;
	}
	return(*max - *min);
}

void Span::addByIteratorRange(vector<int>::iterator begin, 
							  vector<int>::iterator end)
{
	// cout << "addByIteratorRange function called" << endl;

	vector<int> tmp(begin, end);

	if (tmp.size() > this->spaceLeft())
		throw std::out_of_range("Cannot add any more numbers");
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->_storage));
}
