#ifndef IMAGE_H
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface *img;
	SDL_Rect pos1;
	SDL_Rect pos2;
}image;

void initP0(image *A); void initP1(image *A); void initS0(image *A); void initS1(image *A); void initQ0(image *A); void initQ1(image *A);
void initfP0(image *A); void initfS0(image *A); void initfQ0(image *A); void initfP1(image *A); void initfS1(image *A); void initfQ1(image *A);
void initT0(image *A); void initT1(image *A); void initT0s(image *A); void initT1s(image *A);
void initPlus0(image *A); void initPlus1(image *A); void initMinus0(image *A); void initMinus1(image *A);
void initfPlus0(image *A); void initfPlus1(image *A); void initfMinus0(image *A); void initfMinus1(image *A);
void initRe0(image *A); void initRe1(image *A); void initfRe0(image *A); void initfRe1(image *A);
void initH0(image *A); void initH1(image *A); void initfH0(image *A); void initfH1(image *A);
void afficherBack(image p, SDL_Surface *screen); void afficherButton(image A, SDL_Surface *s); 
void initBackground(image *bg); void initBackground1(image *bg); void initBackground2(image *nbg); void hotkBackground(image *bg); 
void fhotkBackground(image *bg); void init_f_Background(image *backg); void init_f_Background1(image *backg); void initBackgroundLevel(image *nbg);
void finitBackground2(image *nbg); void finitBackgroundLevel(image *nbg); void initHigh0(image *A); void initHigh1(image *A); void initBackground333(image *a); void initY(image *A); void initN(image *A); void initbtn2(image *A); void initbtn(image *A); void lddd0(image *bg); void lddd1(image *bg); void lddd2(image *bg);
void liberer(image A);

#endif
