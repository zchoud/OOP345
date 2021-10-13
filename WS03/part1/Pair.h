#ifndef PAIR_H
#define PAIR_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
	template<class V, class K>
	class Pair {
		V c_value;
		K c_key;
	public:
		Pair();
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		void display(std::ostream& os) const;	
	};

	template<class V, class K>
	std::ostream& operator<<(std::ostream& os, const sdds::Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

	template<class V, class K>
	inline Pair<V, K>::Pair()
	{
	}

	template<class V, class K>
	inline Pair<V, K>::Pair(const K& key, const V& value)
	{
		c_value = value;
		c_key = key;
	}

	template<class V, class K>
	inline const V& Pair<V, K>::value() const
	{
		return c_value;
	}

	template<class V, class K>
	inline const K& Pair<V, K>::key() const
	{
		return c_key;
	}

	template<class V, class K>
	inline void Pair<V, K>::display(std::ostream& os) const
	{
		os << c_key << " : " << c_value << std::endl;
	}
	
}
#endif // PAIR_H