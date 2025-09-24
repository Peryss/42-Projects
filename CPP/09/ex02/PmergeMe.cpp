#include "PmergeMe.hpp"

Tracker::Tracker(): _value(0), _pair(NULL) {};

Tracker::Tracker (int value): _value(value), _pair(NULL) {}

Tracker::Tracker (int value, Tracker *pair) : _value(value), _pair(pair) {}

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
	_pair = p;
}

int Tracker::getValue() {
	return (_value);
}

Tracker* Tracker::getPair() {
	return (_pair);
}

void Tracker::print() const {
	std::cout << "Value: " << _value << ", Pair: " << _pair << std::endl;
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
