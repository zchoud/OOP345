#include "ConfirmationSender.h"

sdds::ConfirmationSender::ConfirmationSender()
{

}

sdds::ConfirmationSender::~ConfirmationSender()
{
	delete[] c_reservations;
	c_reservations = nullptr;
}

size_t sdds::ConfirmationSender::size() const
{
	return c_cnt;
}

sdds::ConfirmationSender::ConfirmationSender(const sdds::ConfirmationSender& copy)
{
	*this = copy;
}

sdds::ConfirmationSender& sdds::ConfirmationSender::operator=(const sdds::ConfirmationSender& copy)
{
	if (this != &copy) {
		delete[] c_reservations;
		c_reservations = nullptr;
		c_reservations = copy.c_reservations;
		c_cnt = copy.c_cnt;
	}
	return *this;
}

sdds::ConfirmationSender::ConfirmationSender(sdds::ConfirmationSender&& copy)noexcept
{
	c_reservations = new const Reservation * [copy.c_cnt];
	c_cnt = copy.c_cnt;
	for (size_t i = 0; i < c_cnt; i++) {
		c_reservations[i] = copy.c_reservations[i];
	}
	copy.c_reservations = nullptr;
	copy.c_cnt = 0;
}

sdds::ConfirmationSender& sdds::ConfirmationSender::operator=(sdds::ConfirmationSender&& copy)noexcept
{
	delete[] c_reservations;
	c_reservations = nullptr;
	c_reservations = copy.c_reservations;
	c_cnt = copy.c_cnt;
	copy.c_reservations = nullptr;
	copy.c_cnt = 0;
	return *this;
}

sdds::ConfirmationSender& sdds::ConfirmationSender::operator+=(const sdds::Reservation& res)
{
	bool found = false;
	if (c_cnt == 0) {
		c_reservations = new const Reservation * [1];
		c_reservations[0] = &res;
		c_cnt = 1;
	}
	else {
		for (size_t i = 0; i < c_cnt && !found; i++)
		{
			if (c_reservations[i] == &res) {
				found = true;
			}
		}
		if (!found) {
			const Reservation** t_reservations[100] = {};
			for (size_t j = 0; j < c_cnt; j++) {
				*t_reservations[j] = c_reservations[j];
			}
			*t_reservations[c_cnt] = &res;
			c_cnt++;
			delete[] c_reservations;
			for (size_t j = 0; j < c_cnt; j++) {
				c_reservations[j] = *t_reservations[j];
			}
		}
	}
	return *this;
}

sdds::ConfirmationSender& sdds::ConfirmationSender::operator-=(const sdds::Reservation& res)
{
	bool found = false;
	for (size_t i = 0; c_cnt > 0 && i < c_cnt && !found; i++)
	{
		if (this->c_reservations[i] == &res) {
			found = true;
			const Reservation** t_reservations = new const Reservation * [c_cnt - 1];
			size_t k = 0;
			for (size_t j = 0; j < c_cnt; j++, k++) {
				if (j == i) {
					k++;
				}
				t_reservations[j] = c_reservations[k];
			}
			delete[] c_reservations;
			c_cnt--;
			c_reservations = t_reservations;
			
		}
	}
	return *this;
}

sdds::Reservation sdds::ConfirmationSender::operator[](const int idx)const {
	return *c_reservations[idx % c_cnt];
}

bool sdds::ConfirmationSender::exists(size_t idx) const
{
	return c_reservations[idx % c_cnt] != nullptr;
}

namespace sdds {
	std::ostream& operator<<(std::ostream& os, ConfirmationSender& confirm)
	{
		std::cout << "--------------------------" << std::endl
			<< "Confirmations to Send" << std::endl
			<< "--------------------------" << std::endl;
		if (confirm.size() == 0) {
			std::cout << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < confirm.size(); i++) {
				if (confirm.exists(i - 1)) {
					std::cout << confirm[i - 1];
				}
			}
		}
		std::cout << "--------------------------" << std::endl;
		return os;
	}
}