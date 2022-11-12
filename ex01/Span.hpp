/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:14:06 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/09 12:53:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
using std::vector;
using std::cout;
using std::endl;

class Span {
private:
	unsigned int _storedSize;
	vector<int> _storage;

public:
	Span();
	Span(unsigned int storedSize);
	Span(Span const & src);
	~Span();

	Span & operator = (Span const &src);

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	void addByIteratorRange(vector<int>::iterator start, vector<int>::iterator end);

	
	vector<int> & getStorage();
	void fillRandom();
	unsigned int size() const;
	unsigned int maxSize() const;
	unsigned int spaceLeft() const;
};

std::ostream & operator << (std::ostream & stream, const Span & src);

#endif
