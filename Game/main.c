/**  
* @file main.c  
* @brief Testing Program.  
* @author Generation-Z Team  
* @version 0.1
* @date Apr 19, 2022  
*  
* Testing program for minimap *  
*/

#include "image.h"
#include "texte.h"
#include "buttons.h"
#include "minimap.h"
#include "enigme.h"
#include "enigmeif.h"
#include "tools.h"
#include "players.h"
#include "ES.h"
#include "bounding_box.h"
#include "tic.h"
#include "sauv.h"
#include <SDL/SDL_mixer.h>

TTF_Font* load_font(const char* filename, int size)
{
	TTF_Font* font = NULL;
	font = TTF_OpenFont(filename, size);

	if (font == NULL) {
		printf("Font failed to load. Error: %s\n", TTF_GetError());
		exit(1);
	}

	return font;
}

SDL_Surface* render_text(TTF_Font* font, const char* text, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Surface* message = NULL;
	SDL_Color color = {r, g, b};
	
	message = TTF_RenderText_Solid(font, text, color);
	if (message == NULL) {
		printf("text failed to render. Error: %s\n", TTF_GetError());
	}

	return message;
}

int main(int argc, char **argv[])
{
   //Initialisation	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	TTF_Init();

	TTF_Font*police=NULL; TTF_Font*police2=NULL, *font=NULL;
	SDL_Color red={125,0,0}; SDL_Color black={0,0,0}; SDL_Color green={0,200,0};
	police=TTF_OpenFont("texxte.ttf",40); police2=TTF_OpenFont("texxte.ttf",75);


   //Variables declaration
	image p0, s0, q0, p3,q1, s1, Fp0, Fs0, Fq0, Fp1, Fs1, Fq1; // <--- Main Menu Pictures Variables
	image t0, t0s, t1, t1s, pl0, pl1, fpl0, fpl1, mi0, mi1, fmi0, fmi1, h0, h1, fh0, fh1, hi0, hi1, background333; // <--- Settings Pictures Variables
	image bg, bg1, fbg, fbg1, hbg, fhbg, btn, btn2; // <--- Background Pictures Variables
	image re, res, fre, fres, nbg, l1, fnbg, fl1, ld0, ld1, ld2; // <--- General Pictures Variables
	minimap m; char meill[20];
	SDL_Surface *s, *image=NULL, *ANIME=NULL,*surface_message=NULL; SDL_Event e; enigme en; enigmeif ee; font = load_font("Font/MENUETTO.TTF", 28);
	int x_vel = 0, c1=1, done=1, a=0, p=0, i=1, f=1, v=100, k=0, score=200, tini, T, Ti=0, detect_sound=0, verif=0; player p1 , p2;
	Uint32 t_prev1 = 0, dt1 = 0, t_prev2 = 0, dt2 = 0;
	text t, ft, st, fst, s1t, fs1t, te, str, sct, fstr, be;
	Mix_Music *mms, *ss; Mix_Chunk *cs; struct Timer fps;
	atexit(SDL_Quit); SDL_Rect position, pos_sprite, pos_screen, position_message; ES enem;
 	tic tic1;
	
   //Setting up Screen
	s = SDL_SetVideoMode(1000, 500, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	if(!s){
		printf("Unable to set 1000x500 video: %s\n", SDL_GetError());
		return 1;
	}
	SDL_WM_SetCaption("STRANDED", NULL);  //Set Name & Icon of the Window

	position.x=0;
	position.y=0;

	image=IMG_Load("BG.jpg");
	ANIME=IMG_Load("animation.png");

	pos_sprite.x=0;
	pos_sprite.y=0;
	pos_sprite.w=785/9;
	pos_sprite.h=175/2;


    // position d'animation 
	pos_screen.x=321;
	pos_screen.y=470;

	surface_message=TTF_RenderText_Blended(police,"",green);

	position_message.x=422;
	position_message.y=468;
   //Initialisations Variables
	initBackground(&bg); /**/ initBackground1(&bg1); /**/ init_f_Background(&fbg); /**/ init_f_Background1(&fbg1);
	initText(&t); initfText(&ft); initText1(&st); initfText1(&fst); initText2(&s1t); initfText2(&fs1t);
	initP0(&p0); /**/ initP1(&p3); /**/ initS0(&s0); /**/ initS1(&s1); /**/ initQ0(&q0); /**/ initQ1(&q1);
	initfP0(&Fp0); /**/ initfS0(&Fs0); /**/ initfQ0(&Fq0); /**/ initfP1(&Fp1); /**/ initfS1(&Fs1); /**/ initfQ1(&Fq1);
	initT0(&t0); /**/ initT1(&t1); /**/ initT0s(&t0s); /**/ initT1s(&t1s); /**/ initRe0(&re); /**/ initRe1(&res);
	initPlus0(&pl0); /**/ initPlus1(&pl1); /**/ initMinus0(&mi0); /**/ initMinus1(&mi1); /**/ initfPlus0(&fpl0); /**/ initfPlus1(&fpl1);
	initfMinus0(&fmi0); /**/ initfMinus1(&fmi1); /**/ initfRe0(&fre); /**/ initfRe1(&fres); /**/ hotkBackground(&hbg);
	initH0(&h0); /**/ initH1(&h1); /**/ initfH0(&fh0); /**/ initfH1(&fh1); /**/ fhotkBackground(&fhbg); /**/ initminimap(&m);
	initTextTe(&te); /**/ initStringInp(&str); /**/ initBackground2(&nbg); /**/ initBackgroundLevel(&l1); /**/ initScoreText(&sct);
	finitBackground2(&fnbg); /**/ finitStringInp(&fstr); /**/ finitBackgroundLevel(&fl1); /**/ initBest(&be);
	initHigh0(&hi0); initHigh1(&hi1); init_enigmes(&en); generate(&ee); InitEnigme(&ee); init_player(&p1); init_player(&p2); init_es(&enem); initialiserTic(&tic1); initBackground333(&background333); initbtn2(&btn2); initbtn(&btn);
lddd0(&ld0); lddd1(&ld1); lddd2(&ld2);

   //Sounds
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	mms = Mix_LoadMUS("Music/mainbgst.mp3"); ss = Mix_LoadMUS("Music/settingsst.mp3");
	cs = Mix_LoadWAV("Music/Button click.wav");
	Mix_PlayMusic(mms, -1); t_prev1 = SDL_GetTicks(); t_prev2 = SDL_GetTicks();

	afficherBack(ld0, s); SDL_Flip(s); SDL_Delay(1500); afficherBack(ld1, s); SDL_Flip(s);  SDL_Delay(1000); afficherBack(ld2, s); SDL_Flip(s);  SDL_Delay(1000);
   //Game Loop
	while(done!=0){
		SDL_Flip(s); startTimer(&fps);
		SDL_PollEvent(&e);
		if ((p1.acceleration < 0.001) && (p1.acceleration > -0.001)) {
			t_prev1 = SDL_GetTicks();	// Reset timer when acceleration reaches 0
			dt1 = 0;
		}

		if ((p2.acceleration < 0.001) && (p2.acceleration > -0.001)) {
			t_prev2 = SDL_GetTicks();	// Reset timer when acceleration reaches 0
			dt2 = 0;
		}
		switch(e.type){
		    case SDL_QUIT:
			mainsauvgrade(s, p1, l1, &done, score);
			done = 0;
			break;

	    //Keyboard Input
		    case SDL_KEYDOWN:
			menu_buttons(e, &a, &p, &done, cs, s, &f, &v, &i, mms, ss, &k, &m, str, &l1, &tini, &c1, &ee, &score);
			HandleInput(e, &str, &p, &fstr);
			break;

	    //Mouse Input
		    case SDL_MOUSEMOTION:
			menu_mousemotions(p, e, &a, f, &i);
			break;
	    //Mouse Click Down
		    case SDL_MOUSEBUTTONDOWN:
			menu_mouseclickdown(&p, e, cs, &done, &f, s, &v, ss, mms, &k);
			if((e.button.button==SDL_BUTTON_LEFT)&&(e.button.x<btn.pos2.x+btn.pos1.w&&e.button.x>btn.pos2.x)&&(e.button.y<btn.pos2.y+btn.pos1.h&&e.button.y>btn.pos2.y)&&p==3){
				charger(&p1,&l1,"sauv.txt", &score);
				p = 4;
			}
			break;
		}

	    //Main Menu
		if(p == 0){
		    mainMenu_display(s, a, bg, p0, s0, q0, p3, q1, s1, fbg, f, Fp0, Fs0, Fq0, Fp1, Fs1, Fq1, i);
	    //Play Menu
		}else if(p == 1){
		    playMenu_display(bg1, s, f, fbg1, re, res, fre, fres, e, p, p0, p3, Fp0, Fp1, btn, btn2);
	    //Settings Menu
		}else if(p == 2){
		    settingsMenu_display(e, bg1, s, t, fst, f, fbg1, ft, t0, st, p, t0s, t1, t1s, s1t, pl0, pl1, mi0, mi1, fs1t, fpl0, fpl1, fmi0, fmi1, re, res, fre, fres, h0, h1, k, hbg, fh0, fh1, fhbg, bg, be, meill, hi0, hi1);
	    //Typing Player Name
	    	}else if(p == 3){
		    typing_name(s, nbg, str, &p, fnbg, f, fstr);
	    //Level
		}else if(p == 4){
		    level_display(l1, s, m, &T, te, sct, &score, tini, &Ti, fl1, f, &p, str, &enem);
		jump(&p1, e, 1); jump(&p2, e, 2);
		move_player(&p1, dt1, e, 1); move_player(&p2, dt2, e, 2);
		display_player(p1, s); display_player(p2, s);
		animate_player(&p1); animate_player(&p2);
		//Cap the frame rate
         if( get_ticksTimer(&fps) < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - get_ticksTimer(&fps) );
        }
                dt1 = SDL_GetTicks() - t_prev1;
		dt2 = SDL_GetTicks() - t_prev2;
	    //Engime Texte
		}else if(p == 5){
			SDL_BlitSurface(image, NULL, s, &position);
			afficherenigme(en, s);
			enig(e, en, &score, police, police2, &pos_sprite, &pos_screen, s, surface_message, image, &position, ANIME, &position_message, &p, &m);
	    //Enigme Image
		}else if(p == 6){
			displayEnigme(ee, s);
		//Tic Tac Toe
		}else if(p == 7){
			afficherBack(background333, s); afficherTic(tic1, s);
		if(tic1.tour<9 && atilganer(tic1.tabsuivi)==0){
			if((tic1.tour+tic1.joueur)%2 == 0){
				calcul_coup(tic1.tabsuivi);
				tic1.tour++;
			}else{
				SDL_WaitEvent(&e);
				if(e.type == SDL_MOUSEBUTTONDOWN){
					if(tic1.tabsuivi[clicks(e)] == 0){
						tic1.tabsuivi[clicks(e)] = -1;
						tic1.tour++;
					}
				}
			}
		}else{
			Resultat(tic1.tabsuivi, s, te);
		}
		}

		if(m.ppl.x == 400)
			p = 5;
		else if(m.ppl.x == 600)
			p = 6;
	}

   //Free Surfaces
	free_surfaces(bg, bg1, fbg, p0, p3, s0, s1, q0, q1, t0, t0s, t1, t1s, pl0, pl1, mi0, mi1);
	free_surfaces1(Fp0, Fs0, Fq0, Fp1, Fs1, Fq1, fpl0, fpl1, fmi0, fmi1, re, res, fre, fres);
	free_surfaces2(h0, h1, hbg, fh0, fh1, fhbg, m, l1, nbg);
	free_text_audio(t, ft, st, mms, cs, fst, s1t, fs1t, ss, te, sct);
	SDL_Quit();

	return 0;
}
