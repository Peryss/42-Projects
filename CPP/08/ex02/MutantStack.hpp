/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:25 by pvass             #+#    #+#             */
/*   Updated: 2025/10/07 16:09:25 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> > class MutantStack : public std::stack<T, Container> {
public:
	// Inherit std::stack constructors
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	MutantStack& operator=(const MutantStack& other) {
	    std::stack<T, Container>::operator=(other);
	    return *this;
	}
	~MutantStack() {}

	// Typedefs for iterator types
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	//Iterators
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}
};


#endif