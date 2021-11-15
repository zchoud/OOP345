#ifndef CAR_H
#define CAR_H
#include <string>
#include <iomanip>
#include "Vehicle.h" 
namespace sdds {
	enum condition // there are only 3 specific options
	{
		c_new,
		c_used,
		c_broken
	};
	class Car : public Vehicle
	{
		std::string c_maker = ""; // name of the maker as a string
		enum class condition // there are only 3 specific options
		{
			c_new,
			c_used,
			c_broken
		}c_condition;
		double c_speed = 0.0; // based on speed being a range
	public:
		Car() {};
		Car(std::istream& in);
		std::string condition()const;
		double topSpeed()const;
		void display(std::ostream& os)const;
	};
}
#endif // !CAR_H
