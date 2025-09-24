#include "RPN.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Please provide 1 argument" << std::endl;
		return 0;
	}
	try {
		int res = stringToStack(argv[1]);
		std::cout << res << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}