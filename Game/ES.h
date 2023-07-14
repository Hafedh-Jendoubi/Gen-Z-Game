#ifndef _ES_H_
#define _ES_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <time.h>
/**
* @struct entite
* @brief struct for ennemy
*/
typedef enum {WAITING,FOLLOWING,ATTACKING} STATE;
typedef struct
{
SDL_Rect pos; /*!< Rectangle*/
@@ -16,11 +17,19 @@ SDL_Surface *image; /*!< Surface. */
int sprite_count;
int sprite_n;//current sprite
int d;//direction
STATE state;
}ES;

void init_es(ES *p);
void afficher_es(ES p,SDL_Surface *screen);
void animer_es(ES *p);
void move_es(ES *p);
void move_es_attack(ES *p);
void animer_es_attack(ES *p);
void move_es_follow(ES *p);
void animer_es_follow(ES *p);
//void updateEnnemistate(ES *p,int posEH);
void updateEnnemi(ES *p,SDL_Rect posHero);


#endif
