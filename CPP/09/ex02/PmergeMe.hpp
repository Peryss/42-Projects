/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:21 by pvass             #+#    #+#             */
/*   Updated: 2025/09/30 10:56:25 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <exception>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <iomanip>
#include <list>

extern std::size_t comparisons; 

class Tracker {
	private:
		int		_value;
		std::list<Tracker *> _pair;
	public:
		Tracker();
		Tracker (int value);
		Tracker (int value, std::list<Tracker*> pair);
		~Tracker();
		Tracker(const Tracker& other);
		Tracker operator= (const Tracker& other);

		void setPair(Tracker *p);
		void popPair();

		int getValue();
		Tracker* getPair();
		int	getSize();
		std::list<Tracker *> getList();

		void print() const;
		void printPairs() const;

};

unsigned int jacobstahl(int k);
long long current_time_ns();

template <class Container> void print_container(Container &v) {
	for (typename Container::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << " " << (*it)->getValue();
	std::cout << std::endl;
}

template <class Container> void parse_input(Container& container, std::string element) {
	std::istringstream iss(element);
	int value;
	(void) element;
	iss >> value;
	if (!iss.fail()) {
		if (value < 0)
			throw std::runtime_error("Negative number.");
	    container.insert(container.end(), Tracker(value));
	} else {
	    throw std::runtime_error("Parsing failed.");
	}
}

template <class Container> void	in_sort(Container& c, const std::string type) {
	long long start = current_time_ns();
	Container res = sort_recurs(c);
	long long end = current_time_ns();
	long long us = (end - start) / 1000;
	long long ns = (end-start) % 1000;
	if (type == "vector") {
	std::cout << "After:	";
	for (typename Container::iterator it = res.begin(); it != res.end(); ++it)
		std::cout << " " << (*it)->getValue();
	std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << c.size() << " elements with std::" << type << " : "
		<< us << "." << ns << " us" << std::endl;
	std::cout << "Number of comparisons " << comparisons << std::endl;
	comparisons = 0;
}

template <class PtrContainer> void binary_insert(PtrContainer& res, typename PtrContainer::size_type end_index, Tracker* to_insert) {
    typedef typename PtrContainer::size_type size_type;
    if (!to_insert)
		return ;
    size_type lo = 0, hi = end_index;
    while (lo < hi) {
        size_type mid = lo + (hi - lo) / 2;
        if (res[mid]->getValue() < to_insert->getValue())
			lo = mid + 1;
        else
			hi = mid;
		comparisons ++;
    }
    res.insert(res.begin() + lo, to_insert);
	//std::cout << "Inserted " << to_insert->getValue() << " with binary insertion" << std::endl;
}

template <class Container> unsigned int get_until(int k, Container res) {
	unsigned int jsth_limit = jacobstahl(k) + jacobstahl(k-1) - 1;
	if (jsth_limit > res.size())
		return res.size();
	else
		return jsth_limit;
}

template <class Container> Container sort_recurs(Container& c) {
	Container high;
	Container low;
	int	i = 0;
	Tracker *first = NULL;

	if (c.size() <= 1) {
		/*std::list<Tracker *> lst = (*(c.begin()))->getList();
		std::cout << "pairs of the highest:" ;
		for (std::list<Tracker *>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if (*it)
    			std::cout << (*it)->getValue() << " ";
		}
		std::cout << std::endl;*/
		return c;
	}
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		switch (i){
			case 0:
				first = *it;
				i++;
				break ;
			case 1:
				if(first->getValue() > (*it)->getValue()){
					first->setPair(&(**it));
					high.insert(high.end(), first);
				}
				else {
					(*it)->setPair(&(*first));
					high.insert(high.end(), *it);

				}
				comparisons ++;
				i = 0;
				break ;
		}
	}
	Container res = sort_recurs(high);
	Container highs_sorted = res;
	Tracker* f = *res.begin();
	res.insert (res.begin(), f->getPair());
	if (f->getSize() > 0)
		f->popPair();
	int k = 1;
	while(jacobstahl(k - 1) < highs_sorted.size()) {
		typename Container::reverse_iterator iter_start;
		if (jacobstahl(k) > highs_sorted.size())
		{
			if (i == 1) {
				binary_insert(res, get_until(k, res), c.back());
				i = 0;
			}
			iter_start = highs_sorted.rbegin(); 
		}
		else {
			iter_start = highs_sorted.rend() - jacobstahl(k);
		}
		for (typename Container::reverse_iterator rit = iter_start; rit != highs_sorted.rend() - jacobstahl(k - 1); ++rit) {
			//std::cout << "[]" << (*rit)->getValue();
			binary_insert(res, get_until(k, res), (*rit)->getPair());
			if ((*rit)->getSize() > 0 ) {
				//std::cout << "To insert upper pair:" << (*rit)->getPair()->getValue() << std::endl;
				(*rit)->popPair();
			}
		}
		k++;
	}
	if (i == 1) {
		binary_insert(res, get_until(k, res), c.back());
			i = 0;
	}
	//print_container(res);
	return (res);
}

#endif