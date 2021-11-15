#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <iterator>
namespace sdds {
	struct Song {
		std::string c_artist; //unknown length string
		std::string c_title; //unknown length string
		std::string c_album; //unknown length string
		double m_price; //decimal number
		size_t c_year; //always a positive whole number
		size_t c_length; //asumption of length stored in seconds ussually at 1s presesion 
		Song& operator=(const std::string album);
	};
	class SongCollection
	{
		std::vector<Song> c_collection;
		std::string& trim(std::string& str);
		void strSub(std::istream& ss, size_t size, std::string& set);
		void strSub(std::istream& ss, size_t size, double& set);
		void strSub(std::istream& ss, size_t size, size_t& set);
	public:
		SongCollection();
		SongCollection(char* filename);
		void display(std::ostream& out)const;
		void sort(const std::string type);
		void cleanAlbum();
		bool inCollection(const std::string name) const;
		std::list<Song> getSongsForArtist(const std::string name) const;
	};
	std::ostream& operator<<(std::ostream& out, const sdds::Song& theSong);
	std::ostream& SecondsTime(std::ostream& out, const size_t seconds, bool hour = false);
	template<typename T>
	std::ostream& valid(std::ostream& out, T& value);

	template<typename T>
	inline std::ostream& valid(std::ostream& out, const T& value)
	{
		if (value != 0) {
			out << value;
		}
		else out << "";
		return out;
	}
}
#endif // !SONGCOLLECTION_H



