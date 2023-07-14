#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED
#include "players.h"
#include "image.h"

void sauvgrad (player p, image b, char * nomfichier, int score);
int charger (player *p, image *b , char * nomfichier, int *score);
int mainsauvgrade(SDL_Surface *screen,player p, image b,int *done, int score);
/*void arduinoWriteData(char x) ;
void arduinoReadData(int *x);*/
#endif
