#include "Reservation.h"

sdds::Reservation::Reservation()
{

}


std::string& sdds::Reservation::trimStr(std::string& str, std::string& temp, char delim, size_t &lf) {
	lf = temp.find(delim);
	str = temp.substr(0, lf);
	if (str.back() == ' ') {
		str = str.substr(0, str.find_last_not_of(' ') + 1);
	}
	if (str.front() == ' ') {
		str = str.substr(str.find_first_not_of(' '), str.size() + 1);
	}
	lf++;
	temp.erase(0, lf);
	return temp;
}

std::string& sdds::Reservation::trimNum(unsigned int& num, std::string& temp, char delim, size_t& lf) {
	lf = temp.find(delim);
	num = std::atoi(temp.substr(0, lf).substr(temp.find_first_not_of(' '), temp.find_last_not_of(' ')).c_str());
	lf++;
	temp.erase(0, lf);
	return temp;
}

sdds::Reservation::Reservation(const std::string& res)
{
	size_t lastFind = 0;
	std::string temp = res;

	temp = trimStr(this->c_resID, temp, ':', lastFind);
	temp = trimStr(this->c_resName, temp, ',', lastFind);
	temp = trimStr(this->c_resEmail, temp, ',', lastFind);
	temp = trimNum(this->c_population, temp, ',', lastFind);
	temp = trimNum(this->c_day, temp, ',', lastFind);
	temp = trimNum(this->c_time, temp, ',', lastFind);
	c_time = std::atoi(temp.c_str());
}

void sdds::Reservation::update(int day, int time)
{
	c_day = day;
	c_time = time;
}

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << std::left << "Reservation "
			<< std::setw(12) << std::right << res.id() + ": "
			<< std::setw(20) << std::right << res.name()
			<< std::setw(22) << std::left << "  <" + res.email() + ">";
		std::string meal;
		if (res.hour() >= 6 && res.hour() <= 9) {
			meal = "Breakfast";
		}
		else if (res.hour() >= 11 && res.hour() <= 15) {
			meal = "Lunch";
		}
		else if (res.hour() >= 17 && res.hour() <= 21) {
			meal = "Dinner";
		}
		else {
			meal = "Drinks";
		}
		os << std::left << "    " + meal << " on day " << res.day() << " @ " << res.hour()
			<< ":00 for " << res.pop();
		if(res.pop() == 1) os << " person." << std::endl;
		else os << " people." << std::endl;
		return os;
	}
}
