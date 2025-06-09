/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:35:32 by pvass             #+#    #+#             */
/*   Updated: 2025/05/28 11:28:06 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool get_input(const std::string &prompt, std::string &input);
void printable(std::string str);
bool is_empty(std::string str);

#endif
