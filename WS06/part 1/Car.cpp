#include "Car.h"
#include "Utilities.h"
sdds::Car::Car(std::istream& in)
{
	std::string temp;
	std::getline(in, temp, ',');
	temp = trim(temp);
	if (temp.at(0) == 'c' || temp.at(0) == 'C') {
		std::getline(in, temp, ',');
		temp = trim(temp);
		c_maker = temp;
		std::getline(in, temp, ',');
		temp = trim(temp);
		if (temp.at(0) == 'n')
		{
			this->c_condition = condition::c_new;
		}
		else if (temp.at(0) == 'u')
		{
			this->c_condition = condition::c_used;
		}
		else {
			this->c_condition = condition::c_broken;
		}
		std::getline(in, temp, ',');
		temp = trim(temp);
		c_speed = std::stod(temp);
	}
	else {
		c_maker = "";
	}
}

std::string sdds::Car::condition() const
{
	std::string str;
	switch (c_condition)
	{
	case sdds::Car::condition::c_new:
		str = "new";
		break;
	case sdds::Car::condition::c_used:
		str = "used";
		break;
	case sdds::Car::condition::c_broken:
		str = "broken";
		break;
	default:
		str = "invalid";
		break;
	}
	return str;
}

double sdds::Car::topSpeed() const
{
	return c_speed;
}

void sdds::Car::display(std::ostream& os) const
{
	os << std::setw(10) << c_maker << " | "
		<< std::setw(6) << condition() << " | "
		<< std::setw(6) << topSpeed() << " |" << std::endl;
}
