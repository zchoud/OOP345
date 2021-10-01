#include "event.h"
int g_sysClock;
namespace sdds {

	Event::Event()
	{
		set();
	}
	void Event::display()
	{
		static int counter = 1;
		int hours, mins, secs;
		hours = startTime / 3600;
		mins = (startTime % 3600) / 60;
		secs = (startTime % 3600) % 60;
		std::cout << std::setfill(' ') << std::setw(2) << counter << ". ";
		counter++;
		if (desc[0] != '\0') {
			std::cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0')
				<< mins << ":" << std::setw(2) << std::setfill('0') << secs
				<< " => ";
			for (size_t i = 0; i < strlen(desc); i++)
				{
					std::cout << desc[i];
				}
		}
		else
		{
			std::cout << "| No Event |";
		}
		std::cout << std::endl;
	}
	void Event::set(char argv[])
	{
		startTime = ::g_sysClock;
		if (argv != nullptr && argv[0] != '\0') {
			strcpy_s(desc, argv);
		}
		else
		{
				desc[0] = '\0';
		}
	}
}