#include "Car.h"
#include "Utilities.h"
sdds::Car::Car(std::istream& in)
{
	std::string temp;
	std::getline(in, temp, ',');
	std::getline(in, temp, ',');
	temp = trim(temp);
	c_maker = temp;
	std::getline(in, temp, ',');
	if (temp == "" || temp.find_first_not_of(' ') == std::string::npos) {
		this->c_condition = condition::c_new;
	}
	else {
		temp = trim(temp);
		if (temp.at(0) == 'n')
		{
			this->c_condition = condition::c_new;
		}
		else if (temp.at(0) == 'u')
		{
			this->c_condition = condition::c_used;
		}
		else if (temp.at(0) == 'b') {
			this->c_condition = condition::c_broken;
		}
		else {
			this->c_condition = condition::c_new;
			const char* err = "Invalid Record!";
			throw err;
		}
	}
	std::getline(in, temp, ',');
	temp = trim(temp);
	auto check = ((std::istringstream(temp) >> c_speed >> std::ws).eof());
	if (!check) {
		c_speed = 0.0;
		const char* err = "Invalid Record!";
		throw err;
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
		str = "Unrecognized record type : " + str + "\n";
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
	os << "| " << std::setw(10) << std::right << c_maker << " | "
		<< std::setw(6) << std::left << condition() << " | "
		<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
}
