#ifndef _TIMEDEVENTS_H
#define _TIMEDEVENTS_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <ctime>
#include <chrono>
//Zian Choudhury
//Zchoudhury
//131048209
//zchoudhury@myseneca.ca
	namespace sdds {
		class TimedEvents {
			const int c_maxNoOfEvents = 10;
			int c_numOfRecords = 0;
			std::chrono::steady_clock::time_point c_startTime;
			std::chrono::steady_clock::time_point c_endTime;
			struct {
				char* cs_eventName = nullptr;
				char* cs_unitOfTime = nullptr;
				std::chrono::steady_clock::duration cs_eventDuration;
			} c_events[10];
		public:
			TimedEvents(char* eventName = nullptr);
			//TimedEvents does not need to be copied so it is being removed
			TimedEvents(const TimedEvents& copy)=delete;
			TimedEvents& operator=(const TimedEvents& copy)=delete; 
			virtual ~TimedEvents();
			void startClock();
			void stopClock();
			void addEvent(const char* eventName = nullptr);
			int noOfRecords();
			friend std::ostream& operator<<(std::ostream& insert, TimedEvents& event);
		};
		
	}
#endif