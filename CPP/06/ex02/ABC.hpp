/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:13:13 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 10:13:15 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A: public Base {
	private:
	public:
};

class B: public Base {
	private:
	public:
};

class C: public Base {
	private:
	public:
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif