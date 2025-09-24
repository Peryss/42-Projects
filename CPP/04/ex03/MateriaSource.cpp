/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:26:13 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 12:58:17 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	    _storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
	    if (other._storage[i])
	        _storage[i] = other._storage[i]->clone();
	    else
	        _storage[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
	    for (int i = 0; i < 4; ++i)
		{
	        delete _storage[i];
	        _storage[i] = (other._storage[i]) ? other._storage[i]->clone() : NULL;
	    }
	}
	//std::cout << "MateriaSource copy operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	    delete _storage[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) return;

	for (int i = 0; i < 4; ++i) {
	    if (!_storage[i]) {
	        _storage[i] = m; // Clone it!
	        return;
	    }
	}
	// If all slots are full, do nothing
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i) {
	    if (_storage[i] && _storage[i]->getType() == type)
	        return _storage[i]->clone(); // Return a clone
	}
	return NULL; // Not found
}
