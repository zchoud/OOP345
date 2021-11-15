#include "SpellChecker.h"

sdds::SpellChecker::SpellChecker(const char* filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		const char* err = "Bad file name!";
		throw err;
	}
	else {
		std::string temp;
		for (size_t i = 0; std::getline(file, temp, '\n') && i < 6; i++)
		{
			temp.substr(temp.find_first_not_of(' '), temp.find_last_not_of(' '));
			m_badWords[i] = temp.substr(0, temp.find_first_of(' '));
			temp.erase(0, temp.find_last_of(' '));
			while (temp.at(0) == ' ') {
				temp.erase(0, 1);
			}
			m_goodWords[i] = temp;
		}
	}
}

void sdds::SpellChecker::operator()(std::string& text)
{
	size_t index = 0;
	size_t searchNew = 0;
	size_t searchOld = 0;
	for (size_t i = 0; i < 6; i++)
	{
		index = 0;
		searchNew = text.find(m_badWords[i], index);
		searchOld = searchNew;
		while (searchNew != std::string::npos) {
			text.replace(searchNew, m_badWords[i].size(), m_goodWords[i]);
			index = searchNew + m_goodWords[i].size();
			searchNew = text.find(m_badWords[i], index);
			if (searchOld != searchNew) {
				searchOld = searchNew;
				m_count[i]++;
			}
		}
	}
}

void sdds::SpellChecker::showStatistics(std::ostream& out) const
{
	std::cout << "Spellcheker Statistics" << std::endl;
	for (size_t i = 0; i < 6; i++)
	{
		out << std::setw(15) << std::right << m_badWords[i] + ": " 
			<< m_count[i] << " replacements" << std::endl;
	}
}
