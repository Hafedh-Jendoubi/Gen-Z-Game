#include "players.h"

#ifndef TOOLS_H
#define TOOLS_H

#define FRAMES_PER_SECOND 30
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BIT 32

struct Timer {
    int startTicks;
    int pausedTicks;
    int paused;
    int started;
};

struct image {
    const char* filename;
    SDL_Rect* rect;
    int x;
    int y;
    SDL_Surface* surface;
};

void initTimer(struct Timer* timer);
void startTimer(struct Timer* timer);
void stopTimer(struct Timer* timer);
void pauseTimer(struct Timer* timer);
void unpauseTimer(struct Timer* timer);
int get_ticksTimer(struct Timer* timer);
int is_startedTimer(struct Timer* timer);
int is_pausedTimer(struct Timer* timer);

// SDL_Surface* load_image(const char* filename);
SDL_Surface* load_image(const char* filename);
void apply_surface(SDL_Surface* source, SDL_Rect* clip, SDL_Surface* destination, int x, int y);
void fill_screen_white(SDL_Surface* screen);
#endif
