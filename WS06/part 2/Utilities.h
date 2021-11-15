#ifndef UTILITIES_H
#define UTILITIES_H
#include <sstream>
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string& trim(std::string& str);

}
#endif // UTILITIES_H
