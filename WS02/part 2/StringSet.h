#ifndef _STRINGSET_H
#define _STRINGSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <ctime>
#include <chrono>
namespace sdds {
	class StringSet {
		std::string* c_strings = nullptr;
		size_t c_size = 0;
	public:
		StringSet();
		StringSet(char* filename);
		StringSet(const StringSet& copy);
		StringSet(StringSet&& copy);
		StringSet& operator=(const StringSet& copy);
		StringSet& operator=(StringSet&& copy);
		virtual ~StringSet();
		size_t size();
		std::string operator[](size_t index);
	};
}
#endif