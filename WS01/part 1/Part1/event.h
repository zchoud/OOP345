#ifndef _EVENT_H
#define _EVENT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
extern int g_sysClock;
namespace sdds {
	class Event
	{
		char desc[128] = "\0";
		int startTime = 0;
	public:
		Event();
		void display();
		void set(char argv[] = nullptr);
	};
}
#endif // EVENT_H
