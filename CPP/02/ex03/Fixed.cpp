/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:43 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 09:38:44 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

// Defalt constructor
Fixed::Fixed(): value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}
//const int contructor
Fixed::Fixed(const int value)
{
	//std::cout << "Const int constructor called" << std::endl;
	this->value = value * (1 << this->fractionalbits);
}

//const float constructor
Fixed::Fixed(const float value)
{
	//std::cout << "Const float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->fractionalbits));
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}


// Setter
void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

//to float
float Fixed::toFloat( void ) const
{
	//std::cout << "toFloat member function called" << std::endl;
	return (static_cast<float>(this->value) / (1 << this->fractionalbits));
}

// to int
int Fixed::toInt() const
{
    return (this->value >> this->fractionalbits);
}

//----------------OVERLOADS------------------

// << overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	int64_t rawA = static_cast<int64_t>(getRawBits());
	std::cout << "rawA:"<< rawA << std::endl;
	int64_t rawB = other.getRawBits();
	std::cout << "rawB:"<< rawB << std::endl;
	int64_t mul = rawA * rawB;
	std::cout << "mul:"<< mul << std::endl;
	res.setRawBits(static_cast<int>(mul >> fractionalbits));
	std::cout << "mul:"<< static_cast<int>(mul >> fractionalbits) << std::endl;
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	int64_t rawA = (static_cast<int64_t>(getRawBits()) << fractionalbits);
	int64_t rawB = other.getRawBits();
	result.setRawBits(static_cast<int>(rawA / rawB));
	return result;
}

Fixed& Fixed::operator++()
{
	++value;
	return *this;
}


Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return old;
}

Fixed& Fixed::operator--()
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return old;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}


Fixed Fixed::abs() const
{
    Fixed result = *this;
    if (result.getRawBits() < 0) {
        result.setRawBits(-result.getRawBits());
    }
    return result;
}