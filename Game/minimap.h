#ifndef MINIMAP_H_
#define MINIMAP_H_
#include "image.h"
#include "texte.h"

/**  
* @struct Minimap 
* @brief struct for minimap
*/ 

typedef struct{
	SDL_Surface *img; /*!< Surface*/
	SDL_Rect pimg; /*!< Rectangle*/
	SDL_Surface *pl; /*!< Surface*/
	SDL_Rect ppl; /*!< Rectangle*/
	SDL_Rect pos1; /*!< Rectangle*/
}minimap;

void initminimap(minimap *m);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);
void afficher(minimap m, SDL_Surface *s);
void Liberer(minimap *m);
int timeGame(SDL_Surface *s, text te, int t0);
void timeEnigme(SDL_Surface *s);
void HandleInput(SDL_Event e, text *str, int *p, text *fstr);
void showInput(text str, SDL_Surface *s, int *p);
void sauvegarder(int score, char nomjoueur[], char nomfichier[]);
void meilleur(char nomfichier[], int *score, char nom[]);
void score_player(int *score, int t, int *Ti, text sct, SDL_Surface *s);

#endif
