#ifndef RESTAURANT_H
#define RESTAURANT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* c_reservation = nullptr;
		size_t c_cnt = 0;
	public:
		Restaurant(const Reservation* reservation[], size_t cnt);
		~Restaurant();
		Restaurant(const Restaurant& copy);
		Restaurant& operator=(const Restaurant& copy);
		Restaurant(Restaurant&& copy)noexcept;
		Restaurant& operator=(Restaurant&& copy)noexcept;
		Reservation& operator[](const int idx)const;
		size_t size()const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif
