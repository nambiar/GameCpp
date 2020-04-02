#include "ConstructScreen.h"
#include <SDL2/SDL.h>


ConstructScreen::ConstructScreen(int width, int height,Rgb* rgb)
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        gwindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
        if( gwindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            gscreenSurface = SDL_GetWindowSurface( gwindow );
            gCurrentSurface = gscreenSurface;
            SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ] = {0};

            //Fill the surface white
            //SDL_FillRect( gscreenSurface, NULL, SDL_MapRGB( gscreenSurface->format, rgb->red, rgb->green, rgb->blue ) );
            
            //Update the surface
            //SDL_UpdateWindowSurface( gwindow );
        }
    }
}

ConstructScreen::~ConstructScreen(void)
{
	SDL_FreeSurface( gimageOnSurface );
	//Destroy window
    SDL_DestroyWindow( gwindow );

    //Quit SDL subsystems
    SDL_Quit();
	
}

ConstructScreen::ScreenFlash(int milliSeconds)
{
	SDL_Delay(milliSeconds);
}

ConstructScreen::GetImage(const char* path, bool apply)
{
    //Load splash image
	gimageOnSurface = SDL_LoadBMP(path);
	if( gimageOnSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
	}
    if (apply)
    {
    //Apply the image
    SDL_BlitSurface( gimageOnSurface, NULL, gscreenSurface, NULL );
    //Update the surface
    SDL_UpdateWindowSurface( gwindow );
    //Wait two seconds
    SDL_Delay( 2000 );  
    }
}

SDL_Surface* ConstructScreen::LoadSurface(const char* filename)
{
    SDL_Surface* surface = NULL;
    if(filename != NULL)
    {
        /* laod image */
        surface = SDL_LoadBMP(filename);
        if( surface == NULL )
        {
            printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        }
    }
    return surface;
}

bool ConstructScreen::LoadMedia(const char* filename,KeyPressEvents events)
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[ events ] = this->LoadSurface( filename );
    if( gKeyPressSurfaces[ events ] == NULL )
    {
        printf( "Failed to load %d default image!\n", events);
        success = false;
    }
    
    return success;    
}

//yygjkjafsddfjsdfjkasdfjkasdf
bool ConstructScreen::SetCurrentSurface(KeyPressEvents events)
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gCurrentSurface = gKeyPressSurfaces[ events ];
    if( gCurrentSurface == NULL )
    {
        printf( "Init of media failed");
        success = false;
    }
    
    return success;  
}

void ConstructScreen::LoadScreen(void)
{
    //Apply the current image
    SDL_BlitSurface( gCurrentSurface, NULL, gscreenSurface, NULL );

    //Update the surface
    SDL_UpdateWindowSurface( gwindow );   
}
