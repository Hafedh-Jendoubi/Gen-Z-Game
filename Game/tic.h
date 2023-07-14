#ifndef TIC_H
#define TIC_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "image.h"
#include "texte.h"

typedef struct{
	image n;
	image y;
	int tabsuivi[9];
	SDL_Rect pos1;
	int joueur;
	int tour;
	text result;
}tic;

void initialiserTic(tic *t);
int clicks(SDL_Event e);
void afficherTic(tic t, SDL_Surface *s);
int atilganer(int tabsuivi[]);
void Resultat(int tabsuivi[], SDL_Surface *s, text t);
int minmax(int tabsuivi[], int joueur);
void calcul_coup(int tabsuivi[]);
void terminer(tic t);

#endif
