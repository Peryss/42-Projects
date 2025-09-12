/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:09:50 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 16:59:36 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NotFoundException: public std::exception {
	private:
		std::string _massage;
	public:
		NotFoundException(std::string msg);
};

template <typename T> typename T::iterator easyfind(T& container, int to_find) {
	for (typename T::iterator it = container.begin(); it != container.end(); i++)
		if (i == to_find)
			return (to_find);
}

#endif