/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:57 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 12:51:51 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Fixed x, const Fixed y): x(x), y(y)
{
	//std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point& other): x(other.x), y(other.y)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	//std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Point::~Point()
{
	//std::cout << "Deconstructor called" << std::endl;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

