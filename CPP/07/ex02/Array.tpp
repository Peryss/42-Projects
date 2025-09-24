/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:33:30 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 14:48:00 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <typename T> Array<T>::Array (): _data(0), _size(0) {}

template <typename T> Array<T>::Array (unsigned int n): _data(0), _size(n) {
	if (_size == 0)
		return ;
	_data = new T[_size]();
}

template <typename T> Array<T> Array<T>::operator= (const Array& other) {
	if (*this == other)
		return *this;
	T* new_d = 0;
	this->_size = other._size;
	if (other._size != 0) {
		new_d = new T[this->size];
		for (unsigned int i = 0; i < this->size; i++)
			other._data[i] = new_d[i];
	}
	delete[] _data;
	this->_data = new_d;
	return *this;
}

template <typename T> Array<T>::Array (const Array&other) : _size(other._size), _data(0){
	if (_size > 0) {
	    _data = new T[_size];
	    for (unsigned int i = 0; i < _size; ++i) {
	        _data[i] = other._data[i];
	    }
	}
}

template <typename T> Array<T>::~Array() {
	delete[] _data;
}

template <typename T> T& Array<T>::operator[] (unsigned int index) {
	if	(index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T> const T& Array<T>::operator[](unsigned int index) const {
	if	(index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T> unsigned int Array<T>::size() const{
	return _size;
}
