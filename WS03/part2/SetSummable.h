#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "Set.h"
namespace sdds {
	template<size_t N, class T>
	class SetSummable : public Set<N,T> {
	public:
		T accumulate(const std::string& filter) const;
	};

	template<size_t N, class T>
	inline T SetSummable<N, T>::accumulate(const std::string& filter) const
	{
		T local(filter);
		for (size_t i = 0; i < this->size(); i++) {
			if (local.isCompatibleWith(this->get(i))) {
				local += this->get(i);
			}
		}
		return local;
	}

};
#endif // SETSUMMABLE_H
