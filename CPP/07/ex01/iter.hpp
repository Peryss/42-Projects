/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:33:20 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 11:47:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T* array, int size, void (*function)(T&)) {
	if (array && function && size > 0)
		for (int i = 0; i < size; i++)
			function(array[i]);
	return ;
}

template <typename T> void iter(const T* array, int size, void (*function)(const T&)) {
	if (array && function && size > 0)
		for (int i = 0; i < size; i++)
			function(array[i]);
	return ;
}

template <typename T> void add5(T& item) {
	if (item)
		item += 5;
	return;
}

template <typename T> void print_elem(const T& elem) {
    std::cout << elem << " ";
}

#endif