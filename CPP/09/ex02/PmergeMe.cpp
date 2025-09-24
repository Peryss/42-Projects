#include "PmergeMe.hpp"

std::size_t comparisons = 0;

Tracker::Tracker(): _value(0), _pair() {};

Tracker::Tracker (int value): _value(value), _pair() {}

Tracker::Tracker (int value, std::list<Tracker *> pair) : _value(value), _pair(pair) {}

Tracker::~Tracker() {}
	
Tracker::Tracker(const Tracker& other) : _value(other._value), _pair(other._pair)  {}

Tracker Tracker::operator= (const Tracker& other) {
	if (this != &other) {
	    _value = other._value;
	    _pair  = other._pair;
	}
	return *this;
}

void Tracker::setPair(Tracker *p){
	_pair.push_front(p);
}

void Tracker::popPair() {
	_pair.pop_front();
}

int Tracker::getValue() {
	return (_value);
}

Tracker* Tracker::getPair() {
	return (_pair.front());
}

int	Tracker::getSize() {
	return (_pair.size());
}

std::list<Tracker *> Tracker::getList() {
	return (_pair);
}

void Tracker::print() const {
	std::cout << "Value: " << _value << ", Pair: " << _pair.front() << std::endl;
}

void Tracker::printPairs() const {
	std::list<Tracker *> lst = _pair;
	std::cout << "Pairs of " << _value << ":" ;
	for (std::list<Tracker *>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it)
    		std::cout << (*it)->getValue() << " ";
	}
	std::cout << std::endl;
}

long long current_time_ns() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);  
	return (long long)ts.tv_sec * 1000000000LL + (long long)ts.tv_nsec;
}

unsigned int jacobstahl(int k) {
	if (k == 0)
		return 1;
	else if (k == 1)
		return 3;
	else 
		return (jacobstahl(k-1) + 2 * jacobstahl(k-2)) ;
}
