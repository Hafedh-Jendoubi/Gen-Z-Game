#include "image.h"

void initP0(image *A) //Play Button Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 70;
	A->pos1.y = 25;
	A->pos1.w = 135;
	A->pos1.h = 60;
	A->pos2.x = 430;
	A->pos2.y = 200;
}

void initP1(image *A) //Play Button Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 395;
	A->pos1.y = 28;
	A->pos1.w = 150;
	A->pos1.h = 60;
	A->pos2.x = 430;
	A->pos2.y = 200;
}

void initfP0(image *A) //Play Button Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 70;
	A->pos1.y = 25;
	A->pos1.w = 135;
	A->pos1.h = 60;
	A->pos2.x = 820;
	A->pos2.y = 350;
}

void initfP1(image *A) //Play Button Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 395;
	A->pos1.y = 28;
	A->pos1.w = 150;
	A->pos1.h = 60;
	A->pos2.x = 820;
	A->pos2.y = 350;
}

void initS0(image *A) //Settings Button Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 20;
	A->pos1.y = 100;
	A->pos1.w = 260;
	A->pos1.h = 60;
	A->pos2.x = 370;
	A->pos2.y = 270;
}

void initS1(image *A) //Settings Button Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 332;
	A->pos1.y = 100;
	A->pos1.w = 280;
	A->pos1.h = 60;
	A->pos2.x = 370;
	A->pos2.y = 270;
}

void initfS0(image *A) //Settings Button Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 20;
	A->pos1.y = 100;
	A->pos1.w = 260;
	A->pos1.h = 60;
	A->pos2.x = 760;
	A->pos2.y = 450;
}

void initfS1(image *A) //Settings Button Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 332;
	A->pos1.y = 100;
	A->pos1.w = 280;
	A->pos1.h = 60;
	A->pos2.x = 760;
	A->pos2.y = 450;
}

void initQ0(image *A) //Quit Button Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 70;
	A->pos1.y = 180;
	A->pos1.w = 130;
	A->pos1.h = 65;
	A->pos2.x = 430;
	A->pos2.y = 340;
}

void initQ1(image *A) //Quit Button Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 401;
	A->pos1.y = 178;
	A->pos1.w = 130;
	A->pos1.h = 65;
	A->pos2.x = 430;
	A->pos2.y = 340;
}

void initfQ0(image *A) //Quit Button Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 70;
	A->pos1.y = 180;
	A->pos1.w = 130;
	A->pos1.h = 65;
	A->pos2.x = 820;
	A->pos2.y = 550;
}

void initfQ1(image *A) //Quit Button Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/buttons.png");
	
	A->pos1.x = 401;
	A->pos1.y = 178;
	A->pos1.w = 130;
	A->pos1.h = 65;
	A->pos2.x = 820;
	A->pos2.y = 550;
}

void initT0(image *A) //Fullscreen Box Button in Settings Not Selected in Window 
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");

	A->pos1.x = 265;
	A->pos1.y = 85;
	A->pos1.w = 42;
	A->pos1.h = 42;
	A->pos2.x = 320;
	A->pos2.y = 92;
}

void initT0s(image *A) //Fullscreen Box Button in Settings Selected in Window 
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");

	A->pos1.x = 265;
	A->pos1.y = 28;
	A->pos1.w = 45;
	A->pos1.h = 45;
	A->pos2.x = 320;
	A->pos2.y = 92;
}

void initT1(image *A) //Fullscreen Box Button in Settings Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");

	A->pos1.x = 250;
	A->pos1.y = 245;
	A->pos1.w = 100;
	A->pos1.h = 100;
	A->pos2.x = 555;
	A->pos2.y = 225;
}

void initT1s(image *A) //Fullscreen Box Button in Settings Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");

	A->pos1.x = 248;
	A->pos1.y = 148;
	A->pos1.w = 100;
	A->pos1.h = 80;
	A->pos2.x = 555;
	A->pos2.y = 225;
}

void initPlus0(image *A) //Sound Plus Icon in Settings Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 19;
	A->pos1.y = 20;
	A->pos1.w = 50;
	A->pos1.h = 50;
	A->pos2.x = 415;
	A->pos2.y = 215;
}

void initfPlus0(image *A) //Sound Plus Icon in Settings Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 12;
	A->pos1.y = 150;
	A->pos1.w = 100;
	A->pos1.h = 100;
	A->pos2.x = 700;
	A->pos2.y = 400;
}

void initPlus1(image *A) //Sound Plus Icon in Settings Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 90;
	A->pos1.y = 20;
	A->pos1.w = 58;
	A->pos1.h = 58;
	A->pos2.x = 415;
	A->pos2.y = 215;
}

void initfPlus1(image *A) //Sound Plus Icon in Settings Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 140;
	A->pos1.y = 149;
	A->pos1.w = 105;
	A->pos1.h = 105;
	A->pos2.x = 700;
	A->pos2.y = 400;
}

void initMinus0(image *A) //Sound Minus Icon in Settings Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 19;
	A->pos1.y = 101;
	A->pos1.w = 50;
	A->pos1.h = 35;
	A->pos2.x = 525;
	A->pos2.y = 230;
}

void initfMinus0(image *A) //Sound Minus Icon in Settings Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 15;
	A->pos1.y = 280;
	A->pos1.w = 100;
	A->pos1.h = 50;
	A->pos2.x = 900;
	A->pos2.y = 435;
}

void initMinus1(image *A) //Sound Minus Icon in Settings Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 90;
	A->pos1.y = 99;
	A->pos1.w = 60;
	A->pos1.h = 35;
	A->pos2.x = 525;
	A->pos2.y = 230;
}

void initfMinus1(image *A) //Sound Minus Icon in Settings Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/plus.png");
	
	A->pos1.x = 138;
	A->pos1.y = 278;
	A->pos1.w = 105;
	A->pos1.h = 55;
	A->pos2.x = 900;
	A->pos2.y = 435;
}

void initRe0(image *A) //Return Icon Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/return.png");
	
	A->pos1.x = 18;
	A->pos1.y = 20;
	A->pos1.w = 50;
	A->pos1.h = 50;
	A->pos2.x = 925;
	A->pos2.y = 435;
}

void initRe1(image *A) //Return Icon Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/return.png");
	
	A->pos1.x = 120;
	A->pos1.y = 20;
	A->pos1.w = 60;
	A->pos1.h = 60;
	A->pos2.x = 922;
	A->pos2.y = 435;
}

void initfRe0(image *A) //Return Icon Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/return.png");
	
	A->pos1.x = 18;
	A->pos1.y = 20;
	A->pos1.w = 50;
	A->pos1.h = 50;
	A->pos2.x = 1845;
	A->pos2.y = 897;
}

void initfRe1(image *A) //Return Icon Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/return.png");
	
	A->pos1.x = 120;
	A->pos1.y = 20;
	A->pos1.w = 60;
	A->pos1.h = 60;
	A->pos2.x = 1845;
	A->pos2.y = 897;
}

void initH0(image *A) //Hotkeys Icon Not Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/hotkeys.png");
	
	A->pos1.x = 95;
	A->pos1.y = 7;
	A->pos1.w = 305;
	A->pos1.h = 95;
	A->pos2.x = 55;
	A->pos2.y = 310;
}

void initH1(image *A) //Hotkeys Icon Selected in Window
{
	A->img = IMG_Load("Pictures/Buttons/hotkeys.png");
	
	A->pos1.x = 95;
	A->pos1.y = 110;
	A->pos1.w = 305;
	A->pos1.h = 95;
	A->pos2.x = 58;
	A->pos2.y = 306;
}

void initfH0(image *A) //Hotkeys Icon Not Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/hotkeys.png");
	
	A->pos1.x = 24;
	A->pos1.y = 220;
	A->pos1.w = 441;
	A->pos1.h = 130;
	A->pos2.x = 65;
	A->pos2.y = 610;
}

void initfH1(image *A) //Hotkeys Icon Selected in Fullscreen
{
	A->img = IMG_Load("Pictures/Buttons/hotkeys.png");
	
	A->pos1.x = 24;
	A->pos1.y = 365;
	A->pos1.w = 441;
	A->pos1.h = 130;
	A->pos2.x = 65;
	A->pos2.y = 610;
}

void initBackground(image *bg) //Main Menu Background in Window
{
	bg->img = IMG_Load("Pictures/Backgrounds/MMBG.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void initBackground1(image *bg) //Settings & Play Background in Window
{
	bg->img = IMG_Load("Pictures/Backgrounds/OBG.jpeg");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void init_f_Background(image *fbg) //Main Menu Background in Fullscreen
{
	fbg->img = IMG_Load("Pictures/Backgrounds/fMMBG.png");
	
	fbg->pos1.x = 0;
	fbg->pos1.y = 0;
	fbg->pos2.x = 0;
	fbg->pos2.y = 0;
	fbg->pos2.w = 1920;
	fbg->pos2.h = 962;
}

void init_f_Background1(image *fbg) //Settings & Play Background in Fullscreen
{
	fbg->img = IMG_Load("Pictures/Backgrounds/fOBG.jpeg");
	
	fbg->pos1.x = 0;
	fbg->pos1.y = 0;
	fbg->pos2.x = 0;
	fbg->pos2.y = 0;
	fbg->pos2.w = 1920;
	fbg->pos2.h = 962;
}

void initBackground2(image *nbg) //Play Background in Window to type the name
{
	nbg->img = IMG_Load("Pictures/Backgrounds/name.jpg");

	nbg->pos1.x = 0;
	nbg->pos1.y = 0;
	nbg->pos2.x = 0;
	nbg->pos2.y = 0;
	nbg->pos2.w = 1000;
	nbg->pos2.h = 500;
}

void finitBackground2(image *nbg) //Play Background in Window to type the name
{
	nbg->img = IMG_Load("Pictures/Backgrounds/fname.jpg");

	nbg->pos1.x = 0;
	nbg->pos1.y = 0;
	nbg->pos2.x = 0;
	nbg->pos2.y = 0;
	nbg->pos2.w = 1920;
	nbg->pos2.h = 962;
}

void initBackgroundLevel(image *nbg) //Level 1 Background
{
	nbg->img = IMG_Load("Pictures/Backgrounds/l1b.png");

	nbg->pos1.x = 0;
	nbg->pos1.y = 0;
	nbg->pos2.x = 0;
	nbg->pos2.y = 0;
	nbg->pos2.w = 1000;
	nbg->pos2.h = 500;
}

void finitBackgroundLevel(image *nbg) //Level 1 Background Full Screen
{
	nbg->img = IMG_Load("Pictures/Backgrounds/fl1b.png");

	nbg->pos1.x = 0;
	nbg->pos1.y = 0;
	nbg->pos2.x = 0;
	nbg->pos2.y = 0;
	nbg->pos2.w = 1920;
	nbg->pos2.h = 962;
}

void hotkBackground(image *bg) //Background of the Hotkeys in Window (Small Resolution)
{
	bg->img = IMG_Load("Pictures/Backgrounds/hotk1.jpg");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void fhotkBackground(image *bg) //Background of the Hotkeys in Fullscreen (Big Resolution)
{
	bg->img = IMG_Load("Pictures/Backgrounds/fhotk1.jpg");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1920;
	bg->pos2.h = 962;
}

void initHigh0(image *A)
{
	A->img = IMG_Load("Pictures/Buttons/hs.png");
	
	A->pos1.x = 25;
	A->pos1.y = 10;
	A->pos1.w = 450;
	A->pos1.h = 100;
	A->pos2.x = 380;
	A->pos2.y = 306;
}

void initHigh1(image *A)
{
	A->img = IMG_Load("Pictures/Buttons/hs.png");
	
	A->pos1.x = 25;
	A->pos1.y = 127;
	A->pos1.w = 450;
	A->pos1.h = 100;
	A->pos2.x = 380;
	A->pos2.y = 306;
}

void initBackground333(image *bg) //Background Initialisation
{
	bg->img = IMG_Load("Tic.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void initY(image *A) //Green Image Initialisation
{
	A->img = IMG_Load("Y.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 10;
	A->pos2.y = 10;
	A->pos1.w = 80;
	A->pos1.h = 80;
}

void initN(image *A) //Red Image Initialisation
{
	A->img = IMG_Load("N.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 10;
	A->pos2.y = 10;
	A->pos1.w = 80;
	A->pos1.h = 80;
}

void initbtn(image *A) //Red Image Initialisation
{
	A->img = IMG_Load("loadgame.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 400;
	A->pos2.y = 250;
}

void initbtn2(image *A) //Red Image Initialisation
{
	A->img = IMG_Load("newgame.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 400;
	A->pos2.y = 250;
}

void lddd0(image *bg)
{
	bg->img = IMG_Load("Pictures/Backgrounds/ld0.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void lddd1(image *bg)
{
	bg->img = IMG_Load("Pictures/Backgrounds/ld1.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void lddd2(image *bg)
{
	bg->img = IMG_Load("Pictures/Backgrounds/ld2.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}


void afficherBack(image p, SDL_Surface *screen) //Function to show background on screen 
{
	SDL_BlitSurface(p.img, &p.pos2, screen, &p.pos1);
}

void afficherButton(image A, SDL_Surface *s) //Function to show buttons on screen
{
	SDL_BlitSurface(A.img, &A.pos1, s, &A.pos2);
}

void liberer(image A) //Function to free surfaces
{
	SDL_FreeSurface(A.img);
}
