#include "Pair.h"
template<class V, class K>
std::ostream& operator<<(std::ostream& os, const sdds::Pair<V, K>& pair)
{
	pair.display(os);
	return os;
}