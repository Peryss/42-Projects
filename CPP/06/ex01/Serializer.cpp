/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:13:02 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 10:13:04 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer () {}

Serializer::~Serializer () {}

Serializer::Serializer (const Serializer &other) {
	*this = other;
}

Serializer &Serializer::operator= (const Serializer &other) {
	(void) other;
	return *this;
}

uintptr_t Serializer::serialize (Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize (uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}