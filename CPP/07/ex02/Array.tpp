#include <iostream>
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
	delete[this->data];
	this->_data = new_d;
	return *this;
}

template <typename T> Array<T>::Array (const Array&other) {

}

template <typename T> Array<T>::~Array() {}

template <typename T> T& Array<T>::operator[] (unsigned int index) {}

template <typename T> const T& Array<T>::operator[](unsigned int index) const {}

template <typename T> unsigned int Array<T>::size() const{}