/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:22 by pvass             #+#    #+#             */
/*   Updated: 2025/10/07 16:35:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << "======== SUBJECT ==========" << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);	
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "======== SUBJECT WITH DEQUE ==========" << std::endl << std::endl;

	std::deque<int> d;
	d.push_back(5);
	d.push_back(17);
	std::cout << d.back() << std::endl;
	d.pop_back();
	std::cout << d.size() << std::endl;
	d.push_back(3);	
	d.push_back(5);
	d.push_back(737);
	//[...]
	d.push_back(0);
	std::deque<int>::iterator i = d.begin();
	std::deque<int>::iterator ie = d.end();
	++i;
	--i;
	while (i != ie)
	{
		std::cout << *i << std::endl;
		++i;
	}
	std::stack<int> s2(d);

	std::cout << std::endl << "======== MY OWN TESTS ==========" << std::endl << std::endl;


	MutantStack<int> mstack2;
	mstack2.push(1);
	mstack2.push(2);
	mstack2.push(6);

	std::cout << "Top: " << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << "Size: " << mstack2.size() << std::endl;

	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(42);
	mstack2.push(0);

	std::cout << "MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
	    std::cout << *it << std::endl;
	}

	std::cout << "MutantStack reverse: " << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit) {
	    std::cout << *rit << std::endl;
	}

	return 0;
}
