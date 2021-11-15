#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
namespace sdds {
	class Movie
	{
		std::string c_title;
		size_t c_year = 0;
		std::string c_desc;
		std::string& trimStr(std::string& str);
	public:
		Movie();
		const std::string& title()const;
		Movie(const std::string& strMovie);
		const size_t year()const;
		const std::string& desc()const;
		template <typename T>
		void fixSpelling(T& spellChecker);
		friend std::ostream& operator<<(std::ostream& os, const sdds::Movie& movie);
	};
	template<typename T>
	inline void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(this->c_title);
		spellChecker(this->c_desc);
	}
}
#endif // !MOVIE_H



