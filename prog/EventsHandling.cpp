#include "EventsHandling.h"
#include <SDL2/SDL.h>
#include <stdio.h>


Events::Events(void)
{
	this->isEventQuit = false;
}

void Events::SubscibeEventsCallback(EventsCallbackInterface* callBack)
{
        this->m_cb[index] = callBack;
        this->index++;
}
//void EventsCallback(EventsCallbackInterface *);
void Events::processEvents(int event)
{
	for (int i = 0; i < index ; ++i)
	{
		((EventsCallbackInterface*)this->m_cb[i])->callbackProcessSDLEvents(event);
    }
}

void Events::CheckEvent(void)
{
	SDL_Event e;
	while (!Events::isEventQuit)
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			printf("EventType%d\n",e);
			if ( e.type == SDL_QUIT )
			{
				this->isEventQuit = true;
				//this->processEvents(e.type);
			}
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				this->processEvents(e.type);
			}
		}
	}
}

Events::~Events(void)
{
	//this->isEventQuit = false;
}




