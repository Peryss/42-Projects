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

class Tracker {
	private:
		int		_value;
		Tracker *_pair;
	public:
		Tracker();
		Tracker (int value);
		Tracker (int value, Tracker *pair);
		~Tracker();
		Tracker(const Tracker& other);
		Tracker operator= (const Tracker& other);

		void setPair(Tracker *p);

		int getValue();
		Tracker* getPair();

		void print() const;

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

template <class Container> void	in_sort(Container& c) {
	long long start = current_time_ns();
	Container res = sort_recurs(c);
	long long end = current_time_ns();
	long long us = (end - start) / 1000;
	long long ns = (end-start) % 1000;
	std::string type = "vector/deque";
	std::cout << "Time to process a range of " << c.size() << " elements with std::" << type << " : "
		<< us << "." << ns << " us" << std::endl;
	print_container(res);
}

template <class PtrContainer> void binary_insert(PtrContainer& res, typename PtrContainer::size_type end_index, Tracker* to_insert) {
    typedef typename PtrContainer::size_type size_type;
    // Defensive checks
    if (!to_insert)
		throw std::runtime_error("binary_insert_ptr_bounded: null to_insert");
    if (end_index > res.size()) end_index = res.size();

    size_type lo = 0, hi = end_index;
    while (lo < hi) {
        size_type mid = lo + (hi - lo) / 2;
        if (res[mid]->getValue() < to_insert->getValue()) lo = mid + 1;
        else                                              hi = mid;
    }
    res.insert(res.begin() + lo, to_insert); // insert the POINTER
}

template <class Container> typename Container::iterator get_it(Tracker* rit, Container c) {
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		if ((*it)->getValue() == rit->getValue() && (*it)->getPair() == rit->getPair())
			return it;
	}
	throw std::runtime_error("Messed up something really bad");
}

template <class Container> Container sort_recurs(Container& c) {
	Container high;
	Container low;
	int	i = 0;
	Tracker *first = NULL;

	if (c.size() <= 1) 
		return c;
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
					//low.insert(high.end(), *it);
				}
				else {
					(*it)->setPair(&(*first));
					high.insert(high.end(), *it);
					//low.insert(high.end(), first);

				}
				std::cout << "Comparison" << std::endl;
				i = 0;
				break ;
		}
	}
	Container res = sort_recurs(high);
	Container highs_sorted = res;
	res.insert (res.begin(), (*res.begin())->getPair());
	print_container(res);
	int k = 1;
	//int inserted = 0;
	while(jacobstahl(k - 1) < highs_sorted.size()) {
		typename Container::reverse_iterator iter_start;
		std::cout << "0" << std::endl;
		if (jacobstahl(k) > highs_sorted.size())
			iter_start = highs_sorted.rbegin();
		else {
			std::cout << "1" << std::endl;
			iter_start = highs_sorted.rend() - jacobstahl(k) + 1;
			std::cout << "2" << std::endl;
		}
		std::cout << "3" << std::endl;
		print_container(res);
		for (typename Container::reverse_iterator rit = iter_start; rit != highs_sorted.rend() - jacobstahl(k - 1) + 1; ++rit) {
			//std::cout << "To insert upper pair:" << (*rit)->getValue() <<", insert value:" << (*rit)->getPair()->getValue() << std::endl;;
			binary_insert(res, res.size(), (*rit)->getPair());
		}
		std::cout << "4" << std::endl;
		print_container(res);
		k++;
	}
	return (res);
}

#endif