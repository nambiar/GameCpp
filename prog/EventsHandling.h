#ifndef EVENTSHANDLING_H
#define EVENTSHANDLING_H
#include <cstddef>



class EventsCallbackInterface
{

public:
	virtual int callbackProcessSDLEvents(int events);
};


class Events
{
public:
	Events(void);
	~Events(void);
	void processEvents(int event);
    void SubscibeEventsCallback(EventsCallbackInterface *);
    void CheckEvent(void);
private:
	int index =0;
	bool isEventQuit;
	//list <CallbackInterface *> :: callbacks; 
    // The callback provided by the client via connectCallback().
    EventsCallbackInterface *m_cb[10] = {NULL};	
};

#endif