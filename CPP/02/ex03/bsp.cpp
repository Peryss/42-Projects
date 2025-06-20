/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:40 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:06:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Fixed	area(Point const a, Point const b, Point const c)
{
	return ((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())).abs() / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ABC, ABP, ACP, BCP;

	ABC = area(a, b, c);
	ABP = area(a, b, point);
	ACP = area(a, c, point);
	BCP = area(b, c, point);

	if(ABC < ABP + ACP + BCP)
		return false;
	return true;
}
