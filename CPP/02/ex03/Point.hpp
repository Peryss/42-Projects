/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:39:00 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 12:43:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef POINT_HPP
#define	POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

Fixed	area(Point const a, Point const b, Point const c);

#endif
