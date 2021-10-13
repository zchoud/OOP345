#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender
	{
		const Reservation** c_reservations = nullptr;
		size_t c_cnt = 0;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& copy);
		ConfirmationSender& operator=(const ConfirmationSender& copy);
		~ConfirmationSender();
		size_t size()const;
		ConfirmationSender(ConfirmationSender&& copy)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& copy)noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		Reservation operator[](const int idx)const;
		bool exists(size_t idx)const;
		friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& confirm);
	};
}
#endif
