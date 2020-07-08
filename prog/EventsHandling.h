#ifndef EVENTSHANDLING_H
#define EVENTSHANDLING_H
#include <cstddef>


//Key press surfaces constants
typedef enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
}KeyPressEvents;

class EventsCallbackInterface
{

public:
	virtual int callbackProcessSDLEvents(int events)=0;
    /* Added this based on this link */
    /* https://stackoverflow.com/questions/307352/g-undefined-reference-to-typeinfo */
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