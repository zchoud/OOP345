#include "Autoshop.h"

sdds::Autoshop& sdds::Autoshop::operator+=(sdds::Vehicle* theVehicle)
{
	c_vehicles.push_back(theVehicle);
	return *this;
}

sdds::Autoshop::~Autoshop()
{
	for (auto i : c_vehicles)
	{
		delete i;
	}
}

void sdds::Autoshop::display(std::ostream& out) const
{
	out << "--------------------------------\n"
		<< "| Cars in the autoshop!        |\n"
		<< "--------------------------------\n";
	for(auto i : c_vehicles)
	{
		i->display(out);
		std::cout << std::endl;
	}
	out << "--------------------------------\n";
}


 