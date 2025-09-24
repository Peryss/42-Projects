#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1){
		std::cerr << "Please provide numbers to sort" << std::endl;
		return 0;
	}
	std::vector<Tracker> v;
	std::deque<Tracker> d;
	try {
		for (int i = 1; i < argc; i++)
		{
			parse_input(v, argv[i]);
			//parse_input(d, argv[i]);
		}
		std::vector<Tracker*> v_2;            // or std::deque<Tracker*> if you prefer
        v_2.reserve(v.size());
        for (std::vector<Tracker>::size_type i = 0; i < v.size(); ++i)
            v_2.push_back(&v[i]);

		std::cout << "Before:	";
		for (std::vector<Tracker>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << " " << (*it).getValue();
		std::cout << std::endl;



		in_sort(v_2);

		//in_sort(d);
	}
	catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}