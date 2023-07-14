#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <SDL/SDL.h>
#include "tools.h"

#define PLAYER_SPEED 5.0
#define PLAYER_SPEED_INITIAL 0.5

#define PLAYER_MAX_STATES 3
#define PLAYER_MAX_FRAMES 12

#define STATE_IDLE 0
#define STATE_IDLE_MAX_FRAMES 1
#define STATE_RUNNING 1
#define STATE_RUNNING_MAX_FRAMES 8
#define STATE_JUMPING 2
#define STATE_JUMPING_MAX_FRAMES 2

#define GRAVITY 0.5f

#define DEF_COLL SCREEN_HEIGHT / 2 // for collision testing

typedef struct {
    SDL_Surface* sprite;
    SDL_Rect** clips;
    SDL_Rect* clip;
    SDL_Rect* pos;
    int frame , state , keydown , on_ground;
    double speed, acceleration, accelerationY;
} player;

void init_player (player* p);
void display_player (player p, SDL_Surface* screen);
void move_player (player* p, uint32_t dt, SDL_Event e , int perso);
void jump (player* p, SDL_Event e , int perso);
void animate_player(player* p);
void setClips(player* p);

#endif
