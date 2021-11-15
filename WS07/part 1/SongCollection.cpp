#include "SongCollection.h"

sdds::SongCollection::SongCollection()
{

}

sdds::SongCollection::SongCollection(char* filename)
{
	if (filename) {
		std::ifstream file(filename);
		std::string line;
		for (size_t i = 0; getline(file, line, '\n'); i++) {
			if (line != "") {
				Song temp;
				std::stringstream ss(line);
				strSub(ss, 25, temp.c_title);
				strSub(ss, 25, temp.c_artist);
				strSub(ss, 25, temp.c_album);
				strSub(ss, 5, temp.c_year);
				strSub(ss, 5, temp.c_length);
				strSub(ss, 5, temp.m_price);
				c_collection.push_back(temp);
			}
		}

	}
	else {
		char err[] = "Not a file name";
		throw err;
	}
}

void sdds::SongCollection::display(std::ostream& out) const
{
	if (this->c_collection.size() > 0) {
		size_t tTime = 0;
		std::for_each(c_collection.begin(), c_collection.end(), [&tTime](const Song& song) {
			std::cout << song;
			tTime = tTime + song.c_length;
			});
		out << "----------------------------------------------------------------------------------------\n"
			<< "|                                                        Total Listening Time: ";
		SecondsTime(out, tTime, true);
		out << " |" << std::endl;
	}
}

std::string& sdds::SongCollection::trim(std::string& str)
{
	if (str.find_first_not_of(' ') != std::string::npos) {
		if (str.at(0) == ' ') {
			str = str.substr(str.find_first_not_of(' '), str.length());
		}
		if (*(str.end() - 1) == ' ') {
			str = str.substr(0, str.find_last_not_of(' ') + 1);
		}
	}
	return str;
}

void sdds::SongCollection::strSub(std::istream& ss, size_t size, std::string& set)
{
	char buffer[26];
	for (size_t i = 0; i < size; i++) {
		ss.get(buffer[i]);
	}
	buffer[size] = '\0';
	set = buffer;
	set = trim(set);
}

void sdds::SongCollection::strSub(std::istream& ss, size_t size, double& set)
{
	char buffer[26];
	for (size_t i = 0; i < size; i++) {
		ss.get(buffer[i]);
	}
	buffer[size] = '\0';
	std::string temp = buffer;
	set = std::stod(trim(temp));
}

void sdds::SongCollection::strSub(std::istream& ss, size_t size, size_t& set)
{
	char buffer[26];
	for (size_t i = 0; i < size; i++) {
		ss.get(buffer[i]);
	}
	buffer[size] = '\0';
	std::string temp = buffer;
	if (temp.find_first_not_of(' ') != std::string::npos) set = std::stoi(trim(temp));
}

std::ostream& sdds::operator<<(std::ostream& out, const sdds::Song& theSong)
{
	out << "| " << std::setw(20) << theSong.c_title
		<< " | " << std::setw(15) << theSong.c_artist
		<< " | " << std::setw(20) << theSong.c_album
		<< " | " << std::setw(6) << theSong.c_year
		<< " | ";
	SecondsTime(out, theSong.c_length);
	out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |" << std::endl;
	return out;
}

std::ostream& sdds::SecondsTime(std::ostream& out, const size_t seconds, bool hour) {
	std::ios init(NULL);
	init.copyfmt(out);
	size_t timeTotal = seconds;
	if (hour) {
		out << timeTotal / 3600 << ":";
		timeTotal = seconds % 3600;
		out << std::setw(2) << std::setfill('0');
	}
	out << timeTotal / 60 << ":" << std::setw(2) << std::setfill('0') << timeTotal % 60;
	out.copyfmt(init);
	return out;
}