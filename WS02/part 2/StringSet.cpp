#include "StringSet.h"

sdds::StringSet::StringSet()
{
}

sdds::StringSet::StringSet(char* filename)
{
	if (filename) {
		char c;
		int count = 0;
		std::fstream filein;
		filein.open(filename);
		if (filein.is_open()) {
			while (filein.get(c)) {
				if (c == ' ') {
					count++;
				}
			}
			filein.close();
			delete[] c_strings;
			c_size = count + 1;
			c_strings = new std::string[c_size];
			filein.open(filename);
			for (size_t i = 0; i < c_size && std::getline(filein, c_strings[i], ' '); i++) {}
			filein.close();
		}
		else { std::cout << "Failed to open\n"; }
		
	}
}

sdds::StringSet::StringSet(const StringSet& copy)
{
	if (copy.c_strings != nullptr) {
		this->operator=(copy);
	}
}

sdds::StringSet::StringSet(StringSet&& copy)
{
	c_strings = new std::string[c_size];
	for (size_t i = 0; i < c_size; i++) {
		c_strings[i] = copy.c_strings[i];
	}
	copy.c_strings = nullptr;
	copy.c_size = 0;
}

sdds::StringSet& sdds::StringSet::operator=(const StringSet& copy)
{
	if (c_strings != copy.c_strings) {
		this->c_size = copy.c_size;
		delete[] c_strings;
		c_strings = new std::string[c_size];
		for (size_t i = 0; i < c_size; i++) {
			c_strings[i] = copy.c_strings[i];
		}
	}
	return *this;
}

sdds::StringSet& sdds::StringSet::operator=(StringSet&& copy)
{
	if (this != &copy) {
		delete[] c_strings;
		this->c_size = copy.c_size;
		c_strings = new std::string[c_size];
		for (size_t i = 0; i < c_size; i++) {
			c_strings[i] = copy.c_strings[i];
		}
		copy.c_strings = nullptr;
		copy.c_size = 0;
	}
	return *this;
}



sdds::StringSet::~StringSet()
{
	for (size_t i = 0; i < c_size; i++) {
		delete[] c_strings;
		c_strings = nullptr;
	}
}

size_t sdds::StringSet::size()
{
	return c_size;
}

std::string sdds::StringSet::operator[](size_t index)
{
	return index < c_size && !c_strings[index].empty() ? c_strings[index] : "";
}
