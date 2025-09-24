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

#include <algorithm>
#include <stdexcept> 
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
	    return "Element not found in container";
	}
};

template <typename T> typename T::iterator easyfind(T& container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end()) {
	    throw NotFoundException();
	}
	return it;
}

#endif