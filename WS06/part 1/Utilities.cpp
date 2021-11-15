#include "Utilities.h"

sdds::Vehicle* sdds::createInstance(std::istream& in)
{
    std::string temp;
    Vehicle* vehicle = nullptr;
    if (getline(in, temp, '\n')) {
        std::istringstream ss(temp);
        vehicle = new Car(ss);
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
