#include "Movie.h"

std::string& sdds::Movie::trimStr(std::string& str)
{
	if (str.back() == ' ') {
		str = str.substr(0, str.find_last_not_of(' ') + 1);
	}
	if (str.front() == ' ') {
		str = str.substr(str.find_first_not_of(' '), str.size() + 1);
	}
	return str;
}

sdds::Movie::Movie()
{
}

const std::string& sdds::Movie::title() const
{
	return this->c_title;
}

const size_t sdds::Movie::year()const {
	return this->c_year;
}

const std::string& sdds::Movie::desc()const {
	return this->c_desc;
}

sdds::Movie::Movie(const std::string& strMovie)
{
	std::istringstream in(strMovie);
	std::string parseStr;
	std::string movieInfo[3];
	size_t i = 0;
	std::streampos prevLine = in.tellg();
	while (std::getline(in, parseStr, ',') && i < 2) {
		movieInfo[i] = parseStr;
		prevLine = in.tellg();
		i++;
	}
	in.seekg(prevLine);
	std::getline(in, parseStr, '\n');
	movieInfo[2] = parseStr;
	this->c_title = trimStr(movieInfo[0]);
	this->c_year = std::stoi(trimStr(movieInfo[1]).c_str());
	this->c_desc = trimStr(movieInfo[2]);
}

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		std::cout << std::setw(40) << movie.title() << " | "
			<< std::setw(4) << movie.year() << " | "
			<< movie.desc() << std::endl;
		return os;
	}
}
