/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:40:23 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 15:19:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <stdexcept>

bool	bad_filename(char* in);
void	loadExchangeRates(std::map<std::string, float> map);

class Date {
	private:
		std::string _datestr;
		int _day;
		int _month;
		int _year;
	public:
		Date ();
		Date (const Date& other);
		Date (std::string datestr);
		Date& operator=(const Date& other);
		~Date ();

		int getDay();
		int getMonth();
		int getYear();
		std::string getDatestr();
};

#endif