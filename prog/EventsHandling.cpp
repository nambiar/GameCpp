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
            //User presses a key
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                    this->processEvents(KEY_PRESS_SURFACE_UP);
                    break;

                    case SDLK_DOWN:
                    this->processEvents(KEY_PRESS_SURFACE_DOWN);
                    break;

                    case SDLK_LEFT:
                    this->processEvents(KEY_PRESS_SURFACE_LEFT);
                    break;

                    case SDLK_RIGHT:
                    this->processEvents(KEY_PRESS_SURFACE_RIGHT);
                    break;

                    default:
                    this->processEvents(KEY_PRESS_SURFACE_DEFAULT);
                    break;
                }
            }           
        }
    }
}

Events::~Events(void)
{
    //this->isEventQuit = false;
}




