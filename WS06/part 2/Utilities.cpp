#include "Utilities.h"

sdds::Vehicle* sdds::createInstance(std::istream& in)
{
	std::string line;
	Vehicle* vehicle = nullptr;
	if (getline(in, line, '\n')) {
		std::stringstream ss(line);
		char type = line.at(line.find_first_not_of(' '));
		if (type == 'c' || type == 'C') {
			vehicle = new Car(ss);
		}
		else if (type == 'r' || type == 'R') {
			vehicle = new Racecar(ss);
		}
		else {
			std::string strErr = "Unrecognized record type: [";
			strErr.push_back(type);
			strErr.push_back(']');
			const char* err = strErr.c_str();
			std::cout << err << std::endl;
		}
	}
	return vehicle;
}

std::string& sdds::trim(std::string& str)
{
	if (str.at(0) == ' ') {
		str = str.substr(str.find_first_not_of(' '), str.length());
	}
	if (*(str.end() - 1) == ' ') {
		str = str.substr(0, str.find_last_not_of(' ') + 1);
	}
	return str;
}
