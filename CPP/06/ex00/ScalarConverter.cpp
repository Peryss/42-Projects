#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>   // strtod, strtol
#include <climits>   // INT_MIN, INT_MAX
#include <cctype>    // std::isdigit
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return *this;
}

//Classification
static bool isCharLiteral(const std::string& s, char& out) {
    if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]))) {
        out = s[0];
        return true;
    }
    if (s.size() == 3 && s[0] == '\'' && s[2] == '\'') {
        out = s[1];
        return true;
    }
    return false;
}

static bool isIntLiteral(const std::string& s) {
    if (s.empty())
		return false;
    std::string::size_type i = 0;
    if (s[i] == '+' || s[i] == '-')
		++i;
    if (i >= s.size())
		return false;
    for (; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
    return true;
}

static bool isPseudoFloat(const std::string& s) {
    return (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff");
}

static bool isPseudoDouble(const std::string& s) {
    return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf");
}

static bool endsWithFNumeric(const std::string& s) {
    if (s.size() < 2 || s[s.size()-1] != 'f')
		return false;
    std::string core = s.substr(0, s.size()-1);
    // Allow forms like 42f or 42.0f
    std::string::size_type i = 0;
    if (core[i] == '+' || core[i] == '-')
		++i;
    bool hasDigit = false;
	bool hasDot = false;
    for (; i < core.size(); ++i) {
        char c = core[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
			hasDigit = true;
			continue;
		}
        if (c == '.') {
			if (hasDot)
				return false;
			hasDot = true;
			continue;
		}
        return false;
    }
    return hasDigit;
}

static bool isDoubleNumeric(const std::string& s) {
    // Typical forms: 42.0, 0.0
    std::string::size_type i = 0;
    if (s.empty())
		return false;
    if (s[i] == '+' || s[i] == '-')
		++i;
    bool hasDigit = false;
	bool hasDot = false;
    for (; i < s.size(); ++i) {
        char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c))) {
			hasDigit = true; continue;
		}
        if (c == '.') {
			if (hasDot) 
				return false;
			hasDot = true;
			continue;
		}
        return false;
    }
    return hasDigit && hasDot; // treat numbers with a dot as double
}

//Parsing
static bool parseLong(const std::string& s, long& out) {
    char* end = 0;
    const char* cs = s.c_str();
    out = std::strtol(cs, &end, 10);
    return (end && *end == '\0');
}

static bool parseDouble(const std::string& s, double& out) {
    char* end = 0;
    const char* cs = s.c_str();
    out = std::strtod(cs, &end);
    return (end && *end == '\0');
}

//Printing
static void printCharFromLong(long v) {
    std::cout << "char:		";
    if (v < 0 || v > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(v);
    if (c >= 32 && c <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void printCharFromDouble(double d, bool isPseudo) {
    if (isPseudo || d < 0.0 || d > 127.0) {
		std::cout << "char:		";
        std::cout << "impossible" << std::endl;
        return;
    }
    long v = static_cast<long>(d);
    if (d != static_cast<double>(v)) {
		std::cout << "char:		";
        std::cout << "impossible" << std::endl;
        return;
    }
    printCharFromLong(v);
}

static void printIntFromLong(long v) {
    std::cout << "int:		";
    if (v < static_cast<long>(INT_MIN) || v > static_cast<long>(INT_MAX)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(v) << std::endl;
    }
}

static void printIntFromDouble(double d, bool isPseudo) {
    std::cout << "int:		";
    if (isPseudo || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    double truncd = static_cast<double>(static_cast<long>(d));
    if (truncd != d) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(d) << std::endl;
}

static void printFloatSpecial(const std::string& s) {
    if (s == "nan" || s == "nanf")
		std::cout << "float:		nanf" << std::endl;
    else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff")
		std::cout << "float:		+inff" << std::endl;
    else if (s == "-inf" || s == "-inff")
		std::cout << "float:		-inff" << std::endl;
}

static void printDoubleSpecial(const std::string& s) {
    if (s == "nan" || s == "nanf")
		std::cout << "double:		nan" << std::endl;
    else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff")
		std::cout << "double:		+inf" << std::endl;
    else if (s == "-inf" || s == "-inff")
		std::cout << "double:		-inf" << std::endl;
}

static void printFloatFromDouble(double d, bool isPseudo) {
    std::cout << "float:		";
    if (isPseudo) {
        // handled in special print path; caller should not call this if pseudo
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::fabs(d) > static_cast<double>(std::numeric_limits<float>::max())) {
        std::cout << "impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDoubleFromDouble(double d, bool isPseudo) {
    std::cout << "double:		";
    if (isPseudo) {
        // handled in special print path; caller should not call this if pseudo
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

//Converter
void ScalarConverter::convert(const std::string& input) {
    // 1) Char
    char c;
    if (isCharLiteral(input, c)) {
		//std::cout << "CHAR" << std::endl;
        // char
        std::cout << "char:		";
        if (c >= 32 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
        else
			std::cout << "Non displayable" << std::endl;

        std::cout << "int:		"   << static_cast<int>(c) << std::endl;
        std::cout << "float:		" << std::fixed << std::setprecision(1) << static_cast<float>(c)  << "f" << std::endl;
        std::cout << "double:		" << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }

    // 2) Pseudo
    if (isPseudoFloat(input) || isPseudoDouble(input)) {
		//std::cout << "PSEUDO" << std::endl;
        std::cout << "char:		impossible" << std::endl;
        std::cout << "int:		impossible"  << std::endl;
        printFloatSpecial(input);
        printDoubleSpecial(input);
        return;
    }

    // 3) Int
    if (isIntLiteral(input)) {
		//std::cout << "INT" << std::endl;
        long v;
        if (!parseLong(input, v)) {
            // parsing failed unexpectedly; treat as impossible for all
            std::cout << "char:		impossible" << std::endl;
            std::cout << "int:		impossible"  << std::endl;
            std::cout << "float:	impossible" << std::endl;
            std::cout << "double:	impossible" << std::endl;
            return;
        }
        printCharFromLong(v);
        printIntFromLong(v);
        std::cout << "float:		" << std::fixed << std::setprecision(1) << static_cast<float>(v)  << "f" << std::endl;
        std::cout << "double:		" << std::fixed << std::setprecision(1) << static_cast<double>(v) << std::endl;
        return;
    }

    // 4) Float
    if (endsWithFNumeric(input)) {
		//std::cout << "FLOAT" << std::endl;
        const std::string core = input.substr(0, input.size()-1);
        double d;
        if (!parseDouble(core, d)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible"  << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        printCharFromDouble(d, false);
        printIntFromDouble(d, false);
        printFloatFromDouble(d, false);
        printDoubleFromDouble(d, false);
        return;
    }

    // 5) Double
    if (isDoubleNumeric(input)) {
        double d;
		//std::cout << "DOUBLE" << std::endl;
        if (!parseDouble(input, d)) {
            std::cout << "char:		impossible" << std::endl;
            std::cout << "int:		impossible" << std::endl;
            std::cout << "float:	impossible" << std::endl;
            std::cout << "double:	impossible" << std::endl;
            return;
        }
        printCharFromDouble(d, false);
        printIntFromDouble(d, false);
        printFloatFromDouble(d, false);
        printDoubleFromDouble(d, false);
        return;
    }

    // Fallbacks treated as invalid
    std::cout << "char:		impossible" << std::endl;
    std::cout << "int:		impossible" << std::endl;
    std::cout << "float:	impossible" << std::endl;
    std::cout << "double:	impossible" << std::endl;
}
