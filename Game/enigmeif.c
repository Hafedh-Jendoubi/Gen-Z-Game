/**

* @file enigmeif.c
*/
#include "enigmeif.h"

/**
* @brief To generate  the random number  .
* @param e the enigme
* @return Nothing\
*/
void generate(enigmeif *e){	
	srand(time(NULL));
	e->d=rand()%3 + 1;
}

/**
* @brief To initialize  the enigme  .
* @param e the enigme 
* @param filename the name of the file
* @return Nothing
*/
void InitEnigme(enigmeif *e){
	char imr1[100],imr2[100],imr3[100], im[100];
	
 	e->pos_image.x=0;
  	e->pos_image.y=0;
  	
  	e->pos_response.x=0;
  	e->pos_response.y=0;

	sprintf(im,"Pictures/solution/%d.jpg",e->d);
	sprintf(imr1,"Pictures/response/%d/1.jpg",e->d); 
    	sprintf(imr2,"Pictures/response/%d/2.jpg",e->d); 
    	sprintf(imr3,"Pictures/response/%d/3.jpg",e->d);
      
	e->response1= IMG_Load(imr1);
	e->response2= IMG_Load(imr2);
    	e->response3= IMG_Load(imr3);
	e->image = e->response1;
	
	e->image_clock=IMG_Load("Pictures/Backgrounds/clock.jpg");  

	e->pos_image_clock.x=800;
	e->pos_image_clock.y=200;
	
	e->single_Clock.w=140;
	e->single_Clock.h=200;
	e->single_Clock.x=0;
	e->single_Clock.y=0; 

	e->clock_num=0;

	e->solution= IMG_Load(im);
	e->pos_solution.x=385;
	e->pos_solution.y=290;

	e->correct = IMG_Load("Pictures/Backgrounds/correct.png"); 
	e->pos_correct.x = 200;
	e->pos_correct.y = 75;

	e->lose= IMG_Load("Pictures/Backgrounds/lose.png");
    	e->pos_lose.x=300;
    	e->pos_lose.y=100;
}

/**
* @brief To display  the enigme  .
* @param e the enigme 
* @param screen the screen
* @return Nothing
*/
void displayEnigme(enigmeif e,SDL_Surface *screen){
	SDL_BlitSurface(e.image,NULL,screen,&e.pos_image); 
}

/**
* @brief To display  the clock  .
* @param e the enigme 
* @param screen the screen 
* @return Nothing
*/
void displayClock(enigmeif e,SDL_Surface *screen){
	SDL_BlitSurface(e.image_clock,&(e.single_Clock), screen, &e.pos_image_clock);
}

/**
* @brief To initialize  the correct answer.
* @param e the enigme 
* @param screen the screen
* @return Nothing
*/
void correct(SDL_Surface *screen,enigmeif e){
	SDL_BlitSurface(e.correct, NULL, screen, &e.pos_correct); 
	SDL_Flip(screen);
	SDL_Delay(1000);
}

/**
* @brief To initialize  the wrong answer  .
* @param e the enigme 
* @param fscreen the screen 
* @return Nothing
*/
void lose(SDL_Surface *screen,enigmeif e){     
    	SDL_BlitSurface(e.lose, NULL, screen, &e.pos_lose);
    	SDL_BlitSurface(e.solution,NULL,screen,&e.pos_solution);
	SDL_Flip(screen);
    	SDL_Delay(1000);
}

/**
* @brief To anime  the enigme  .
* @param e the enigme 
* @return Nothing
*/
void animerEnigme(enigmeif *e){ 
		 	
	if (e->clock_num >=0 && e->clock_num <8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	
	}
	
	if ( e->clock_num == 8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num=0;
	
	}
}
