/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:46 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 09:38:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdint.h>


class Fixed
{
private:
	int value;
	static const int fractionalbits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);

	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();     // Pre-increment
	Fixed operator++(int);   // Post-increment
	Fixed& operator--();     // Pre-decrement
	Fixed operator--(int);   // Post-decrement
	
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

	Fixed abs() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
