#include "Racecar.h"
#include "Utilities.h"
sdds::Racecar::Racecar(std::istream& in):Car(in)
{
	if (this->topSpeed() != 0.0) {
		std::string temp;
		std::getline(in, temp, ',');
		temp = trim(temp);
		c_booster = std::stod(temp);
	}
}

void sdds::Racecar::display(std::ostream& out) const
{
	Car::display(out);
	out << "*";
}

double sdds::Racecar::topSpeed() const
{
	return Car::topSpeed() * (1 + this->c_booster);
}
