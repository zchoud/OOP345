#ifndef RACECAR_H
#define RACECAR_H
#include <string>
#include "Car.h"
namespace sdds {
    class Racecar :
        public Car
    {
        double c_booster = 0.0;
    public:
        Racecar(std::istream& in);
        void display(std::ostream& out)const;
        double topSpeed()const;
    };
}
#endif // !RACECAR_H



