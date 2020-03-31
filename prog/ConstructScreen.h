#ifndef CONSTRUCTSCREEN_H
#define CONSTRUCTSCREEN_H
//Using SDL and standard IO
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
private:
	    //The window we'll be rendering to
    SDL_Window* gwindow;
    //The surface contained by the window
    SDL_Surface* gscreenSurface;
    //The image we will load and show on the screen
    SDL_Surface* gimageOnSurface;

};

#endif