#ifndef CONSTRUCTSCREEN_H
#define CONSTRUCTSCREEN_H
//Using SDL and standard IO
#include "EventsHandling.h"
#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct rgb
{
	int red;
	int green;
	int blue;
}Rgb;
class ConstructScreen
{
public:
	ConstructScreen(int width, int height,Rgb* rgb);
	~ConstructScreen(void);
	GetImage(const char* filename,bool apply);
	ScreenFlash(int milliseconds);
	bool LoadMedia(const char* filename,KeyPressEvents events);
	bool SetCurrentSurface(KeyPressEvents events);	
	//Loads individual image
	SDL_Surface* LoadSurface(const char* filename);
	void LoadScreen(void);
private:
	    //The window we'll be rendering to
    SDL_Window* gwindow;
    //The surface contained by the window
    SDL_Surface* gscreenSurface;
    //The image we will load and show on the screen
    SDL_Surface* gimageOnSurface;
    //The images that correspond to a keypress
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
    //Current displayed image
    SDL_Surface* gCurrentSurface = NULL;    

};

#endif