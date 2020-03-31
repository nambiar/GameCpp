

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "ConstructScreen.h"
#include "EventsHandling.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Rgb rgb = {0x32,0x56,0xff};
ConstructScreen screen(SCREEN_WIDTH,SCREEN_HEIGHT,&rgb);
class ProcessEvents : public EventsCallbackInterface
{
public:
    int callbackProcessSDLEvents(int);
    
};
int ProcessEvents::callbackProcessSDLEvents(int events)
{
        screen.GetImage("images_1.bmp",true);
    screen.ScreenFlash(2000);
  printf("SCallback");
  return 0;
}

int main( int argc, char* args[] )
{
#if 0
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x31, 0x32, 0x33 ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
#endif

    screen.GetImage("images_1.bmp",false);
    ProcessEvents ProcessEvents;
    Events event;
    event.SubscibeEventsCallback(&ProcessEvents);    
    event.CheckEvent();


    return 0;
}