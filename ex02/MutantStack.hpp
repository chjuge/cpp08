/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:50:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/09 13:49:42 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack<T>() { return; }
	MutantStack<T>(MutantStack<T> const & src) { *this = src; }
	~MutantStack<T>() { return; }

	MutantStack<T> & operator=(MutantStack<T> const &src ) { (void)src;	return *this; }

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	reverse_iterator rbegin() { return (std::stack<T>::c.rbegin()); }
	reverse_iterator rend() { return (std::stack<T>::c.rend()); }
};

#endif
