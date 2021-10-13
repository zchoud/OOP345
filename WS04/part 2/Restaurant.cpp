#include "Restaurant.h"

sdds::Restaurant::Restaurant(const sdds::Reservation* reservation[], size_t cnt)
{
	c_cnt = cnt;
	c_reservation = new Reservation[c_cnt];
	for (size_t i = 0; i < c_cnt; i++) {
		c_reservation[i] = *reservation[i];
	}
}

sdds::Restaurant::~Restaurant()
{
	delete[] c_reservation;
	c_reservation = nullptr;
	c_cnt = 0;
}

sdds::Restaurant::Restaurant(const sdds::Restaurant& copy)
{
	*this = copy;
}

sdds::Restaurant& sdds::Restaurant::operator=(const Restaurant& copy)
{
	if (this != &copy) {
		c_cnt = copy.c_cnt;
		delete[] c_reservation;
		c_reservation = new Reservation[c_cnt];
		for (size_t i = 0; i < c_cnt; i++) {
			c_reservation[i] = copy.c_reservation[i];
		}
	}
	return *this;
}

sdds::Restaurant::Restaurant(sdds::Restaurant&& copy)noexcept
{
	c_reservation = new Reservation[copy.c_cnt];
	c_cnt = copy.c_cnt;
	for (size_t i = 0; i < c_cnt; i++) {
		c_reservation[i] = copy.c_reservation[i];
	}
	copy.c_reservation = nullptr;
	copy.c_cnt = 0;
}

sdds::Restaurant& sdds::Restaurant::operator=(sdds::Restaurant&& copy)noexcept
{
	if (this != &copy) {
		delete[] c_reservation;
		c_reservation = nullptr;
		c_reservation = copy.c_reservation;
		c_cnt = copy.c_cnt;
		copy.c_reservation = nullptr;
		copy.c_cnt = 0;
	}
	return *this;
}

sdds::Reservation& sdds::Restaurant::operator[](const int idx)const
{
	return c_reservation[idx % c_cnt];
}

size_t sdds::Restaurant::size() const
{
	return c_cnt;
}
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		static int call_cnt = 0;
		call_cnt++;
		std::cout << "--------------------------" << std::endl
			<< "Fancy Restaurant (" << call_cnt << ")" << std::endl
			<< "--------------------------" << std::endl;
		if (res.size() == 0) {
			std::cout << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < res.size(); i++) {
				std::cout << res[i];
			}
		}
		std::cout << "--------------------------" << std::endl;
		return os;
	}
}