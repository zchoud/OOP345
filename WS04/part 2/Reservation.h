#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
namespace sdds {
	class Reservation
	{
		std::string c_resID; //Normally would use fixed length array, there are different length IDs involved thus using dynamic
		std::string c_resName; //Name length can vary thus is dynamic
		std::string c_resEmail; //same reason as above
		unsigned int c_population = 0; //only positive int
		unsigned int c_day = 0; //only positive int
		unsigned int c_time = 0; //only positive int
	public:
		Reservation();
		Reservation(const std::string& res);
		void update(int day, int time);
		std::string id()const { return this->c_resID; };
		std::string name()const { return this->c_resName; };
		std::string email()const { return this->c_resEmail; };
		unsigned int pop()const { return this->c_population; };
		unsigned int day()const { return this->c_day; };
		unsigned int hour()const { return this->c_time; };
		std::string& trimStr(std::string& str, std::string& temp, char delim, size_t& lf);
		std::string& trimNum(unsigned int& num, std::string& temp, char delim, size_t& lf);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
	
}
#endif // RESERVATIONS_H