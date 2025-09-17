/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:19 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 10:33:20 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

class Span {
	private:
		unsigned int _size;
		std::vector<int> _numbers;
		Span();
	public:
		Span(unsigned int n);
		~Span();
		Span operator=(const Span& other);
		Span (const Span& other);

		void addNumber(int n);

		unsigned long long shortestSpan();
		unsigned long long longestSpan();

		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif