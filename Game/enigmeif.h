#ifndef ENIGMEIF_H_INCLUDED
#define ENIGMEIF_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>     
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
/**
* @struct enigme_image
* @brief enigme_image
*/
typedef struct{  
	
	SDL_Surface *image; /*!< Surface*/  
	SDL_Rect pos_image; /*!< Rectangle*/
	
	SDL_Surface *image_clock;  /*!< Surface*/ 
	SDL_Rect pos_image_clock; /*!< Rectangle*/
	
	SDL_Rect single_Clock; /*!< Rectangle*/
	
	SDL_Surface *response1; /*!< Surface*/ 
	SDL_Surface *response2; /*!< Surface*/ 
	SDL_Surface *response3; /*!< Surface*/ 
	SDL_Rect pos_response; /*!< Rectangle*/
	
	SDL_Surface *correct; /*!< Surface*/ 
	SDL_Rect pos_correct; /*!< Rectangle*/
	
	SDL_Surface *lose; /*!< Surface*/ 
	SDL_Rect pos_lose; /*!< Rectangle*/
	
	SDL_Surface *solution; /*!< Surface*/ 
	SDL_Rect pos_solution; /*!< Rectangle*/
	
	int d; 

	int clock_num;
}enigmeif;

void InitEnigme(enigmeif *e);
void displayEnigme(enigmeif e,SDL_Surface *screen);
void resolution(SDL_Surface *screen,enigmeif *e);
void correct(SDL_Surface *screen,enigmeif e);
void lose(SDL_Surface *screen,enigmeif e);
void generate(enigmeif *e);
void displayClock(enigmeif e,SDL_Surface *screen);
void animerEnigme(enigmeif *e);


#endif  

