/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:11 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 09:53:45 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

// Defalt constructor
Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}
//const int contructor
Fixed::Fixed(const int value)
{
	std::cout << "Const int constructor called" << std::endl;
	this->value = value * (1 << this->fractionalbits);
}

//const float constructor
Fixed::Fixed(const float value)
{
	std::cout << "Const float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->fractionalbits));
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}


// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

//to float
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->value) / (1 << this->fractionalbits));
}

// to int
int Fixed::toInt() const
{
	return (this->value >> this->fractionalbits);
}

// << overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
