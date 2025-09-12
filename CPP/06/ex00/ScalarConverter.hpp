/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:12:44 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 10:45:25 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

#endif
