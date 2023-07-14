#include "players.h"
#include "tools.h"
#include <stdint.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Rect** allocMatrix(int nRow, int nCol)
{
    // int i;
    // int ext_status;
    SDL_Rect** matrix = NULL;
    matrix = malloc(nRow * sizeof(int));

    if (matrix == NULL) 
        exit(1);
    for (int i = 0; i < nRow; ++i) {
        matrix[i]= malloc(nCol * sizeof(int));

        if (matrix[i] == NULL)
            exit(1);
    }

    return matrix;
}


void init_player(player* p)
{
     SDL_Surface* sprite = load_image("SPRITESHEET2.png");
     p->sprite = sprite;

    p->clips = allocMatrix(PLAYER_MAX_STATES, PLAYER_MAX_FRAMES);
    
    setClips(p);

    p->state = STATE_IDLE;
    p->frame = 0;

    p->speed = PLAYER_SPEED;
    p->acceleration = 0;

    p->pos = malloc(sizeof(SDL_Rect));
    p->pos->x = 0;
    p->pos->y = 0;
    p->pos->h = 0;
    p->pos->w = 0;
    p->keydown = 0;
    p->on_ground = 0;
}

void display_player(player p, SDL_Surface* screen) 
{
    apply_surface(p.sprite, p.clip, screen, p.pos->x, p.pos->y);
}

void move_player(player* p, Uint32 dt, SDL_Event e , int perso)
{
    double v0 = PLAYER_SPEED_INITIAL;

    int LEFT, RIGHT;
    switch (perso) {
        case 1:
            LEFT = SDLK_LEFT;
            RIGHT = SDLK_RIGHT;
            break;
        case 2:
            LEFT = SDLK_a;
            RIGHT = SDLK_d;
            break;
    }

    if (p->keydown == 0) {
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == LEFT) {
                p->acceleration -= 0.005; 
                v0 = v0;
            }
            else if (e.key.keysym.sym == RIGHT) {
                p->acceleration += 0.005; 
                v0 = -v0;
            }

            p->keydown = 1;
        }
    }

    if ((e.type == SDL_KEYUP) && ((e.key.keysym.sym == LEFT) || (e.key.keysym.sym == RIGHT))) {
        p->keydown = 0;
    }
    
    if (p->keydown == 0) {
        if (p->acceleration > 0) {
            p->acceleration -= 0.001;
        }
        else if (p->acceleration < 0)
            p->acceleration += 0.001;
    }

    if (p->accelerationY < 0)
        p->state = STATE_JUMPING;
    else if ((p->acceleration > 0) || (p->acceleration < 0))
        p->state = STATE_RUNNING;
    else
        p->state = STATE_IDLE;

    
    if (p->speed > PLAYER_SPEED) p->speed = PLAYER_SPEED;
    else if (p->speed < -PLAYER_SPEED) p->speed = -PLAYER_SPEED;
    else
        p->speed = v0 + 0.5*p->acceleration*dt;
    
    if (p->acceleration != 0) 
        p->pos->x += p->speed; 

    p->accelerationY += GRAVITY;
    p->pos->y += p->accelerationY;

    if (p->pos->y > DEF_COLL) {
        p->pos->y = DEF_COLL;
        p->accelerationY = 0;
        p->on_ground = 1;
    }
}

void jump(player* p, SDL_Event e , int perso)
{ int UP;
    if (perso == 1) UP = SDLK_UP;
    else if (perso == 2) UP = SDLK_w;

    if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == UP) && p->on_ground) {
        p->accelerationY = -12;
        p->on_ground = 0;
    }
}

void animate_player(player* p)
{
    if (p->accelerationY < 0)
        p->state = STATE_JUMPING;
    else if ((p->acceleration > 0) || (p->acceleration < 0))
        p->state = STATE_RUNNING;
    else
        p->state = STATE_IDLE;

    if (p->state == STATE_RUNNING) {
        p->clip = &p->clips[STATE_RUNNING][p->frame];
        ++p->frame;

        if (p->frame > STATE_RUNNING_MAX_FRAMES)
            p->frame = 0;
    }
    else if (p->state == STATE_JUMPING) {

    }
    else
        p->clip = &p->clips[STATE_IDLE][0];
}

void setClips(player* p)
{
    p->clips[STATE_IDLE][0].x = 29;
    p->clips[STATE_IDLE][0].y = 631;
    p->clips[STATE_IDLE][0].w = 59;
    p->clips[STATE_IDLE][0].h = 95;
    p->clip = &p->clips[STATE_IDLE][0];
    
    p->clips[STATE_RUNNING][0].x = 17;
    p->clips[STATE_RUNNING][0].y = 34;
    p->clips[STATE_RUNNING][0].w = 69;
    p->clips[STATE_RUNNING][0].h = 96;

    p->clips[STATE_RUNNING][1].x = 85;
    p->clips[STATE_RUNNING][1].y = 34;
    p->clips[STATE_RUNNING][1].w = 69;
    p->clips[STATE_RUNNING][1].h = 96;

    p->clips[STATE_RUNNING][2].x = 153;
    p->clips[STATE_RUNNING][2].y = 34;
    p->clips[STATE_RUNNING][2].w = 69;
    p->clips[STATE_RUNNING][2].h = 96;

    p->clips[STATE_RUNNING][3].x = 221;
    p->clips[STATE_RUNNING][3].y = 34;
    p->clips[STATE_RUNNING][3].w = 69;
    p->clips[STATE_RUNNING][3].h = 96;

    p->clips[STATE_RUNNING][4].x = 291;
    p->clips[STATE_RUNNING][4].y = 25;
    p->clips[STATE_RUNNING][4].w = 69;
    p->clips[STATE_RUNNING][4].h = 96;

    p->clips[STATE_RUNNING][5].x = 355;
    p->clips[STATE_RUNNING][5].y = 25;
    p->clips[STATE_RUNNING][5].w = 69;
    p->clips[STATE_RUNNING][5].h = 61;

    p->clips[STATE_RUNNING][6].x = 420;
    p->clips[STATE_RUNNING][6].y = 25;
    p->clips[STATE_RUNNING][6].w = 69;
    p->clips[STATE_RUNNING][6].h = 61;

    p->clips[STATE_RUNNING][7].x = 487;
    p->clips[STATE_RUNNING][7].y = 25;
    p->clips[STATE_RUNNING][7].w = 69;
    p->clips[STATE_RUNNING][7].h = 61;

    p->clips[STATE_RUNNING][8].x = 554;
    p->clips[STATE_RUNNING][8].y = 25;
    p->clips[STATE_RUNNING][8].w = 69;
    p->clips[STATE_RUNNING][8].h = 61;
}
