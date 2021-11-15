#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> c_vehicles;
	public:
		Autoshop() {};
		Autoshop(const Autoshop& copy) = delete;
		Autoshop& operator=(const Autoshop& copy) = delete;
		Autoshop(Autoshop&& copy) = delete;
		Autoshop& operator=(Autoshop&& copy) = delete;
		virtual ~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
	};
	template<typename T>
	void select(T test, std::list<const Vehicle*>& vehicles);

	template<typename T>
	void select(T test, std::list<const Vehicle*>& vehicles)
	{

	}
}
#endif // AUTOSHOP_H
