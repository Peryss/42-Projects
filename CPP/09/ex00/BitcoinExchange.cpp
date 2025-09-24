/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:40:21 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 16:25:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// ----------DATA and INPUT handling -------------------------

bool bad_filename(char* in) {
	std::string input = in;
	if (input.size() < 5)
		return true;
	const std::string ext = ".txt";
	if (input.compare(input.size() - ext.size(), ext.size(), ext) != 0)
		return true;
	return false ;
}

void	loadExchangeRates(std::map<Date , float>& rates) {
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
	else 
		throw std::runtime_error ("data.csv is empty.");
	while(std::getline(in, line)) {
		try {
			std::string::size_type pos = line.find(',');
			if (pos == std::string::npos) {
				throw std::runtime_error("Invalid format");
			}
			std::string date = line.substr(0, pos);
			std::string rate = line.substr(pos + 1);
			//if (!date || std::isspace(date[0]) == 1)
			float nr = static_cast<float>(std::atof(rate.c_str()));
			if (nr < 0)
				throw std::runtime_error("Negative exchange rate: " + rate);
			Date d(date);
			rates.insert(std::pair<Date,float> (d,nr));
		}
		catch (const std::exception& e) {
			std::cerr << "Error:Data: " << e.what() << std::endl;
		}
	}
}

static double to_float_checked(const std::string& s) {
	errno = 0;
	char* end = 0;
	const char* str = s.c_str();
	double v = std::strtod(str, &end);

	if (end == str || *end != '\0')
	    throw std::invalid_argument("Invalid");
	else if (errno == ERANGE || v > 1000)
	    throw std::out_of_range("Too large a number.");
	else if (v < 0)
		throw std::out_of_range("Not a positive number.");
	return (v);
}

static float getExchangeRate(Date d, std::map<Date, float> rates) {
	std::map<Date, float>::iterator it = rates.lower_bound(d);
	if (it != rates.end() && !(d < it->first)) {
	    // exact match (because !(a<b) and !(b<a) means a==b)
	    return it->second;
	}

	if (it == rates.begin()) {
	    // no earlier element exists
	    throw std::out_of_range("No earlier date found");
	}

	// step back one to get the closest date before query
	--it;
	return it->second;
}

void	loadInput(char* filename, std::map<Date, float> rates) {
	(void)rates;
	std::ifstream in(filename);
	if (!in) {
		throw std::runtime_error("Cannot open " + std::string(filename));
	}
	std::string line;
	std::string first_line = "date | value";
	if (std::getline(in, line)) {
		if (line.empty() || line.compare(first_line)) {
			throw std::runtime_error("Wrong header in " + std::string(filename));
		}
	}
	else 
		throw std::runtime_error (std::string(filename) + " is empty.");
	while(std::getline(in, line)) {
		try {
			std::string::size_type pos = line.find(' ');
			if (pos == std::string::npos || line.compare(pos, 3, " | ") != 0) {
				throw std::runtime_error("Bad input => " + line);
			}
			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 3);
			if (date.empty() || value.empty() || isspace(date[0]) || isspace (value[0]))
				throw std::runtime_error("Bad input => " + line);
			double nr = to_float_checked(value);
			Date d(date);
			float out  = getExchangeRate(d, rates);
			double total = nr * static_cast<double>(out);
			std::cout << date << " => " << total << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

//----------------------- DATE CLASS MEMBER FUNCTIONS -------------------------------------

Date::Date () : _datestr(std::string("0-1-1")), _day(1), _month(1), _year(0) {}

Date::Date (const Date& other): _datestr(other._datestr), _day(other._day), _month(other._month), _year(other._year) {
	(void)other;
}

static int to_int_checked(const std::string& s, const char* what) {
	errno = 0;
	char* end = 0;
	const char* str = s.c_str();
	long v = std::strtol(str, &end, 10);

	if (end == str || *end != '\0')
	    throw std::invalid_argument(std::string("invalid ") + what + ": " + s);
	else if (errno == ERANGE || v > INT_MAX)
	    throw std::out_of_range(std::string(what) + " out of range: " + s);
	else if (v < 0)
		throw std::out_of_range(std::string(what) + " not a positive number: " + s);
	return static_cast<int>(v);
}

void validate_date (Date date)
{
	bool leapyear = false;
	if (date.getYear() % 4 == 0 && (date.getYear() % 1000 == 0 || date.getYear() % 100 != 0))
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
	std::string daystr = datestr.substr(pos + 1 + pos2 + 1);
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

bool Date::operator<(const Date& rhs) const {
	if (_year  != rhs._year)
		return _year  < rhs._year;
	if (_month != rhs._month)
		return _month < rhs._month;
	return _day < rhs._day;
}
