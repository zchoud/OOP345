#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"
namespace sdds {
	template<class V, class K>
	class PairSummable : public Pair<V,K> {
		static V c_sum;
		static size_t c_width;
	public:
		PairSummable();
		~PairSummable();
		PairSummable(const K& key, const V& value = V());
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		PairSummable& operator+=(const PairSummable& value);
		virtual void display(std::ostream& os)const;
	};
	template<class V, class K>
	size_t PairSummable<V, K>::c_width = 0;
	template<class V, class K>
	V PairSummable<V, K>::c_sum = { };

	template<class V, class K>
	inline PairSummable<V, K>::PairSummable()
	{

	}

	template<class V, class K>
	inline sdds::PairSummable<V, K>::~PairSummable()
	{
		c_sum = V();
	}

	template<class V, class K>
	inline PairSummable<V, K>::PairSummable(const K& key, const V& value):Pair<V,K>(key,value)
	{
		if (key.size() > c_width) {
			c_width = key.size();
		}
	}
	template<class V, class K>
	inline bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const
	{
		return this->key() == b.key() ? true : false;
	}
	template<class V, class K>
	inline PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& value)
	{
		c_sum += value.value();
		Pair<V,K>::update(c_sum);
		return *this;
	}
	template<class V, class K>
	inline void PairSummable<V, K>::display(std::ostream& os) const
	{
		os << std::left << std::setw(c_width);
		Pair<V,K>::display(os);
		os << std::right;
	}
	template<>
	inline PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& value)
	{
		if (c_sum == "") {
			c_sum = value.value();
		}
		else {
			c_sum += ", " + value.value();
		}
		update(c_sum);
		return *this;
	}
};
#endif // PAIRSUMMABLE_H
