/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:40:21 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 15:52:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool bad_filename(char* in) {
	std::string input = in;
	if (input.size() < 5)
		return true;
	const std::string ext = ".csv";
	if (input.compare(input.size() - ext.size(), ext.size(), ext) != 0)
		return true;
	return false ;
}

void	loadExchangeRates(std::map<Date , float> map) {
	std::ifstream in("data.csv");
	if (!in) {
		throw std::runtime_error("Cannot open data.csv");
	}
	std::string line;
	std::string first_line = "date,exchange_rate";
	if (std::getline(in, line)) {
		if (line.empty() || line.compare(first_line)) {
			throw std::runtime_error("Wrong header in data.csv file");
		}
	}
	while(std::getline(in, line)) {
		try {
			std::string::size_type pos = line.find(',');
			if (pos == std::string::npos) {
				throw std::runtime_error("Invalid format");
			}
			std::string date = line.substr(0, pos);
			std::string rate = line.substr(pos + 1);
			float nr = static_cast<float>(std::atof(rate.c_str()));
			if (nr < 0)
				throw std::runtime_error("Negative exchange rate: " + rate);
			Date d(date);
			map.insert(std::pair<Date,float> (d,nr));
		}
		catch (const std::exception& e) {
			std::cerr << "Error:" << e.what() << std::endl;
		}
	}
	
}

Date::Date () : _day(1), _month(1), _year(0), _datestr(std::string("0-1-1")) {}

Date::Date (const Date& other): _day(other._day), _month(other._month), _year(other._year), _datestr(other._datestr) {
	(void)other;
}

static int to_int_checked(const std::string& s, const char* what) {
    errno = 0;
    char* end = 0;
    const char* str = s.c_str();
    long v = std::strtol(str, &end, 10);

    if (end == str || *end != '\0')
        throw std::invalid_argument(std::string("invalid ") + what + ": " + s);
    if (errno == ERANGE || v > INT_MAX)
        throw std::out_of_range(std::string(what) + " out of range: " + s);
	if (v < 0)
		throw std::out_of_range(std::string(what) + " not a positive number: " + s);

    return static_cast<int>(v);
}

void validate_date (Date date)
{
	bool leapyear = false;
	if (date.getYear() % 4 == 0 && (date.getYear()%1000 == 0 || date.getYear() % 100 != 0))
		leapyear = true;
	if (date.getMonth() > 12 || date.getMonth() == 0)
		throw std::invalid_argument("bad input: " + date.getDatestr());
	switch (date.getMonth()) {
		case 1:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 2:
			if ((leapyear == false && date.getDay() > 28)  || (leapyear == true && date.getDay() > 29) || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 3:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 4:
			if (date.getDay() > 30 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 5:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 6:
			if (date.getDay() > 30 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 7:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 8:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 9:
			if (date.getDay() > 30 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 10:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 11:
			if (date.getDay() > 30 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
		case 12:
			if (date.getDay() > 31 || date.getDay() == 0)
				throw std::invalid_argument("bad input: " + date.getDatestr());
			break;
	}
}

Date::Date (std::string datestr): _datestr(datestr){
	std::string::size_type pos = datestr.find('-');
	if (pos == std::string::npos) {
		throw std::runtime_error("Invalid format: " + datestr);
	}
	std::string yearstr = datestr.substr(0, pos);
	std::string::size_type pos2 = datestr.substr(pos + 1).find('-');
	if (pos2 == std::string::npos) {
		throw std::runtime_error("Invalid format: " + datestr);
	}
	std::string monthstr = datestr.substr(pos + 1, pos2);
	std::string daystr = datestr.substr(pos2 +1);
	_year  = to_int_checked(yearstr,  "year");
	_month = to_int_checked(monthstr, "month");
	_day   = to_int_checked(daystr,   "day");
	validate_date (*this);
}

Date& Date::operator=(const Date& other) {
	if (this != &other) {
        _day = other._day;
        _month = other._month;
        _year = other._year;
    }
	return *this;
}

Date::~Date () {}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

std::string Date::getDatestr() {
	return _datestr;
}
