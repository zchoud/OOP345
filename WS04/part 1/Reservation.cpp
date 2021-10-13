#include "Reservation.h"

sdds::Reservation::Reservation()
{

}

std::string& sdds::Reservation::trimStr(std::string& str, std::string& temp, char delim, int &lf) {
	lf = temp.find(delim);
	str = temp.substr(0, lf);
	std::cout << "-"<< str << "-   ";
	if (str.back() == ' ') {
		str = str.substr(0, str.find_last_not_of(' ') + 1);
	}
	if (str.front() == ' ') {
		str = str.substr(str.find_first_not_of(' '), str.size() + 1);
	}
	std::cout << "-" << str << "-" << std::endl;
	temp.erase(0, lf + 1);
	return temp;
}

std::string& sdds::Reservation::trimNum(unsigned int& num, std::string& temp, char delim, int& lf) {
	lf = temp.find(delim);
	num = std::atoi(temp.substr(0, lf).substr(temp.find_first_not_of(' '), temp.find_last_not_of(' ')).c_str());
	temp.erase(0, lf + 1);
	return temp;
}

sdds::Reservation::Reservation(const std::string& res)
{
	size_t total = std::count(res.begin(), res.end(), ',');
	int lastFind = 0;
	std::string temp = res;

	temp = trimStr(this->c_resID, temp, ':', lastFind);
	temp = trimStr(this->c_resName, temp, ',', lastFind);
	temp = trimStr(this->c_resEmail, temp, ',', lastFind);
	temp = trimNum(this->c_population, temp, ',', lastFind);
	temp = trimNum(this->c_day, temp, ',', lastFind);
	temp = trimNum(this->c_time, temp, ',', lastFind);
}

void sdds::Reservation::update(int day, int time)
{
	c_day = day;
	c_time = time;
}

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation "
			<< std::setw(11) << std::right << res.id() + ":"
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
			<< ":00 for #" << res.pop() << " people." << std::endl;
		return os;
	}
}
