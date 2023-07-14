#ifndef ENIGME_H
#define ENIGME_H

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "minimap.h"


typedef struct enigme
{
char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int posrepvrai;


SDL_Surface *surfacequestion;
SDL_Surface *surfacereponse1;
SDL_Surface *surfacereponse2;
SDL_Surface *surfacereponse3;
SDL_Surface *surfacereponse;
SDL_Rect positionquestion;
SDL_Rect positionreponse1;
SDL_Rect positionreponse2;
SDL_Rect positionreponse3;
SDL_Rect positionreponse;
}enigme;

void afficherenigme(enigme e,SDL_Surface *screen);
void init_enigmes(enigme *e);
void animer(enigme *e,SDL_Rect *pos_sprite,int j);
void enig(SDL_Event event,enigme e,int *score,TTF_Font*police,TTF_Font*police2,SDL_Rect *pos_sprite,SDL_Rect *pos_screen,SDL_Surface *screen,SDL_Surface *surface_message,SDL_Surface *image,SDL_Rect *position,SDL_Surface *ANIME,SDL_Rect *position_message, int *p, minimap *m);


#endif
