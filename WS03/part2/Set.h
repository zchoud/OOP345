#ifndef SET_H
#define SET_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
	template <size_t N, class T>
	class Set {
		T c_collection[N];
		size_t c_idx = 0;
	public:
		size_t size()const;
		const T& get(size_t idx)const;
		void operator+=(const T& item);
	};

	template<size_t N, class T>
	inline size_t Set<N, T>::size()const
	{
		return c_idx;
	}
	template<size_t N, class T>
	inline const T& Set<N, T>::get(size_t idx) const
	{
		return c_collection[idx];
	}
	template<size_t N, class T>
	inline void Set<N, T>::operator+=(const T& item)
	{
		if (c_idx < N) {
			c_collection[c_idx] = item;
			c_idx++;
		}
	}
}
#endif // SET_H