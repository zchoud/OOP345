#include "Book.h"

sdds::Book::Book()
{

}

const std::string& sdds::Book::country() const
{
	return this->c_country;
}

const size_t& sdds::Book::year() const
{
	return this->c_year;
}

const std::string& sdds::Book::title() const
{
	return this->c_title;
}

double& sdds::Book::price()
{
	return this->c_price;
}

sdds::Book::Book(const std::string& strBook)
{
	std::istringstream in(strBook);
	std::string parseStr;
	std::string bookInfo[6];
	size_t i = 0;
	std::streampos prevLine = in.tellg();
	while (std::getline(in, parseStr, c_delim) && i < 5) {
		bookInfo[i] = parseStr;
		prevLine = in.tellg();
		i++;
	}
	in.seekg(prevLine);
	std::getline(in, parseStr, '\n');
	bookInfo[5] = parseStr;
	this->c_author = trimStr(bookInfo[0]);
	this->c_title = trimStr(bookInfo[1]);
	this->c_country = trimStr(bookInfo[2]);
	this->c_price = std::stod(trimStr(bookInfo[3]).c_str());
	this->c_year = std::stoi(trimStr(bookInfo[4]).c_str());
	this->c_desc = trimStr(bookInfo[5]);
}

std::string& sdds::Book::trimStr(std::string& str) {
	if (str.back() == ' ') {
		str = str.substr(0, str.find_last_not_of(' ') + 1);
	}
	if (str.front() == ' ') {
		str = str.substr(str.find_first_not_of(' '), str.size() + 1);
	}
	return str;
}

namespace sdds {
	std::ostream& operator<<(std::ostream& os, Book& book)
	{
		std::cout << std::setw(20) << book.c_author << " | "
			<< std::setw(22) << book.c_title << " | "
			<< std::setw(5) << book.c_country << " | "
			<< std::setw(4) << book.c_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.c_price << " | "
			<< book.c_desc << std::endl;
		return os;
	}
}
