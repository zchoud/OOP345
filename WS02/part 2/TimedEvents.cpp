#include "TimedEvents.h"

sdds::TimedEvents::TimedEvents(char* eventName)
{
	if (eventName != nullptr) {
		addEvent(eventName);
	}
}

//sdds::TimedEvents::TimedEvents(const TimedEvents& copy)
//{
//
//}
//
//TimedEvents& sdds::TimedEvents::operator=(const TimedEvents& copy)
//{
//	// TODO: insert return statement here
//}

sdds::TimedEvents::~TimedEvents()
{
	this->c_startTime;
	for (int i = 0; i < c_maxNoOfEvents; i++)
	{
		delete[] c_events[i].cs_eventName;
		c_events[i].cs_eventName = nullptr;
		delete[] c_events[i].cs_unitOfTime;
		c_events[i].cs_unitOfTime = nullptr;
	}
	this->c_endTime;
}

void sdds::TimedEvents::startClock()
{
	c_startTime = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::stopClock()
{
	c_endTime = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::addEvent(const char* eventName)
{
	if (eventName != nullptr) {
		c_numOfRecords++;
		delete[] c_events[c_numOfRecords].cs_eventName;
		c_events[c_numOfRecords].cs_eventName = new char[strlen(eventName) + 1];
		strcpy(c_events[c_numOfRecords].cs_eventName, eventName);
		delete[] c_events[c_numOfRecords].cs_unitOfTime;
		c_events[c_numOfRecords].cs_unitOfTime = new char[strlen("nanoseconds") + 1];
		strcpy(c_events[c_numOfRecords].cs_unitOfTime, "nanoseconds");
		c_events[c_numOfRecords].cs_eventDuration = c_endTime - c_startTime;
	}
}

int sdds::TimedEvents::noOfRecords()
{
	return c_numOfRecords;
}

namespace sdds {
	std::ostream& operator<<(std::ostream& insert, TimedEvents& event)
	{
		insert << "Execution Times:\n--------------------------\n";
		for (int i = 1; i <= event.noOfRecords(); i++)
		{
			insert << std::setw(21) << std::left << event.c_events[i].cs_eventName << " "
				<< std::setw(13) << std::right << event.c_events[i].cs_eventDuration.count() << " " << event.c_events[i].cs_unitOfTime << std::endl;
		}
		insert << "\n--------------------------\n";
		return insert;
	}
}
