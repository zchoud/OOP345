#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace sdds {
	class Book
	{
		std::string c_author;
		std::string c_title;
		std::string c_country;
		size_t c_year = 0;
		double c_price = 0;
		std::string c_desc;
		char c_delim = ',';
		std::string& trimStr(std::string& str);
	public:
		Book();
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		
		friend std::ostream& operator<<(std::ostream& os, Book& book);
	};
}
#endif // !BOOK_H

