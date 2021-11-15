#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
namespace sdds {
	struct Song {
		std::string c_artist; //unknown length string
		std::string c_title; //unknown length string
		std::string c_album; //unknown length string
		double m_price; //decimal number
		size_t c_year; //always a positive whole number
		size_t c_length; //asumption of length stored in seconds ussually at 1s presesion 
	};
	class SongCollection
	{
		std::vector<Song> c_collection;
		std::string& trim(std::string& str);
		void strSub(std::istream& ss, size_t size, std::string& set);
		void strSub(std::istream& ss, size_t size, double& set);
		void strSub(std::istream& ss, size_t size, size_t& set);
		double& operator=(double& ret, std::string& value);
		size_t& operator=(size_t& ret, std::string& value);
		template<typename T>
		void strSub(std::istream& ss, size_t size, T& set);
	public:
		SongCollection();
		SongCollection(char* filename);
		void display(std::ostream& out)const;
	};
	std::ostream& operator<<(std::ostream& out, const sdds::Song& theSong);
	std::ostream& SecondsTime(std::ostream& out, const size_t seconds, bool hour = false);
	template<typename T>
	inline void SongCollection::strSub(std::istream& ss, size_t size, T& set)
	{
		char buffer[26];
		for (size_t i = 0; i < size; i++) {
			ss.get(buffer[i]);
		}
		buffer[size] = '\0';
		std::string temp = buffer;
		temp = trim(temp);
		set = temp;
	}
}
#endif // !SONGCOLLECTION_H



