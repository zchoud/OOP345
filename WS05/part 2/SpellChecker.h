#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t m_count[6] = { 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SPELLCHECKER_H



