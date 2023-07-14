#include "tools.h"
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>

void initTimer(struct Timer* timer)
{
    // Initialize the variables
    timer->startTicks = 0;
    timer->pausedTicks = 0;
    timer->paused = 0;
    timer->started = 0;
}

void startTimer(struct Timer* timer)
{
    //Start the timer
    timer->started = true;

    //Unpause the timer
    timer->paused = false;

    //Get the current clock time
    timer->startTicks = SDL_GetTicks();
}

void stopTimer(struct Timer* timer)
{
    //Stop the timer
    timer->started = false;

    //Unpause the timer
    timer->paused = false;
}

void pauseTimer(struct Timer* timer)
{
    //If the timer is running and isn't already paused
    if( ( timer->started == true ) && ( timer->paused == false ) )
    {
        //Pause the timer
        timer->paused = true;

        //Calculate the paused ticks
        timer->pausedTicks = SDL_GetTicks() - timer->startTicks;
    }
}

void unpauseTimer(struct Timer* timer)
{
    //If the timer is paused
    if( timer->paused == true )
    {
        //Unpause the timer
        timer->paused = false;

        //Reset the starting ticks
        timer->startTicks = SDL_GetTicks() - timer->pausedTicks;

        //Reset the paused ticks
        timer->pausedTicks = 0;
    }
}

int get_ticksTimer(struct Timer* timer)
{
    //If the timer is running
    if( timer->started == true )
    {
        //If the timer is paused
        if( timer->paused == true )
        {
            //Return the number of ticks when the timer was paused
            return timer->pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - timer->startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

int is_startedTimer(struct Timer* timer)
{
    return timer->started;
}

int is_pausedTimer(struct Timer* timer)
{
    return timer->paused;
}

// TODO

// SDL_Surface* load_image(const char* filename)
// {
//     SDL_Surface* loaded_image = NULL;
//     SDL_Surface* optimized_image = NULL;

//     loaded_image = IMG_Load(filename);
//     if (loaded_image == NULL) {
//         printf("Could not load image. Error: %s", IMG_GetError());
//         exit(1);
//     }

//     optimized_image = SDL_DisplayFormatAlpha(loaded_image);  // Match display bits

//     SDL_FreeSurface(loaded_image);  // Free old image

//     return optimized_image;
// }

SDL_Surface* load_image(const char* filename)
{
    SDL_Surface* loaded_image = NULL;
    SDL_Surface* optimized_image = NULL;

    loaded_image = IMG_Load(filename);
    if (loaded_image == NULL) {
        printf("Could not load image. Error: %s\n", IMG_GetError());
        exit(1);
    }

    optimized_image = SDL_DisplayFormatAlpha(loaded_image);  // Match display bits

    if (optimized_image == NULL) {
        printf("Image failed to optimize. Error: %s\n", IMG_GetError());
    }

    SDL_FreeSurface(loaded_image);  // Free old image

    return optimized_image;
}

void apply_surface(SDL_Surface* source, SDL_Rect* clip, SDL_Surface* destination, int x, int y)
{
    // Store offsets in a temporary rectangle:
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, clip, destination, &offset);    // Blit the surface
}




// void remove_background(SDL_Surface* loaded_image, Uint8 r, Uint8 g, Uint8 b)
// {
//     Uint32 color_key = SDL_MapRGB(loaded_image->format, r, g, b);    // Map the color key

//     SDL_SetColorKey(loaded_image, SDL_SRCCOLORKEY, color_key);  // Make the color key transparent
// }

void fill_screen_white(SDL_Surface* screen) 
{
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
}
