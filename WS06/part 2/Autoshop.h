#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include <list>
#include <algorithm>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> c_vehicles;
	public:
		Autoshop() {};
		virtual ~Autoshop();
		Autoshop(const Autoshop& copy) = delete;
		Autoshop(const Autoshop&& copy) = delete;
		Autoshop& operator=(const Autoshop&& copy) = delete;
		Autoshop& operator=(const Autoshop& copy) = delete;
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};
	template<typename T>
	inline void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		for (auto& i : c_vehicles) {
			if (test(i)) {
				vehicles.push_back(i);
			}
		}
	}
}
#endif // AUTOSHOP_H
