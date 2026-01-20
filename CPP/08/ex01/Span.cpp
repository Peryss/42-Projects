/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:16 by pvass             #+#    #+#             */
/*   Updated: 2025/10/07 16:07:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0) {}

Span::Span(unsigned int n): _size(n) {
	_numbers.reserve(n);
}

Span::~Span() {}

Span Span::operator=(const Span& other) {
	_size = other._size;
	_numbers = other._numbers;
	return (*this);
}

Span::Span (const Span& other) {
	*this = other;
}

void Span::addNumber(int n) {
	if (_numbers.size() >= _size)
		throw std::overflow_error("Span is full");
	_numbers.push_back(n);
}

unsigned long long Span::shortestSpan() {
	unsigned long long length;
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers");
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	int temp = sorted[0];
	length = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); ++it) {
		if (static_cast<long long>(length) > static_cast<long long>(*it) - static_cast<long long>(temp))
			length = static_cast<long long>(*it) - static_cast<long long>(temp);
		temp = *it;
	}
	return length;
}

unsigned long long Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers");
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	return (static_cast<long long> (sorted[sorted.size() - 1] - sorted[0]));
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _size)
		throw std::overflow_error("Span is full");
	_numbers.insert(_numbers.end(), begin, end);
}
