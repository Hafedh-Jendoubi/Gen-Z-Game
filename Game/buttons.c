#include "buttons.h"

void menu_buttons(SDL_Event e, int *a, int *p, int *done, Mix_Chunk *c, SDL_Surface *s, int *f, int *v, int *i, Mix_Music *mms, Mix_Music *ss, int *k, minimap *m, text str, image *l1, int *tini, int *c1, enigmeif *ee, int *score)
{
	switch(e.key.keysym.sym){
		case SDLK_p: //Play Key
		    if(*p != 3){
			if(*p==2)
				Mix_PlayMusic(mms, -1);
			if(*p!=1){
				*p = 1;
				Mix_PlayChannel(-1, c, 0);
			}
		    }
			break;
		case SDLK_ESCAPE: //Return Key
			if(*k == 1){
				*k = 0;
				Mix_PlayChannel(-1, c, 0);
			}else if(*k == 2){
				*k = 0;
				Mix_PlayChannel(-1, c, 0);
			}else{
			    if(*p == 3){
				*p = 1;
				Mix_PlayChannel(-1, c, 0);
			    }else if(*p != 0){
				*p = 0;
				*a = 0;
				Mix_PlayChannel(-1, c, 0);
				Mix_PlayMusic(mms, -1);
			    }
			}
			SDL_Delay(150);
			break;
		case SDLK_s: //Settings key
			if(*p!=2 && *p!=3){
				*p = 2;
				Mix_PlayChannel(-1, c, 0);
				Mix_PlayMusic(ss, -1);
			}
			break;
		case SDLK_DOWN: //Keyboard surfing down
			if(*p == 0){
			    if(*a == 0){
				Mix_PlayChannel(-1, c, 0);
				*i = *i + 1;
				if(*i>3)
				    *i = 1;
			    }
			    SDL_Delay(150);
			}
			if(*p == 6){
			    SDL_Delay(200);
		        	(*c1)++;
		        	if((*c1)==4)
		            	    (*c1)=1;
			        if((*c1)==1)
		        	    ee->image = ee->response1;
			        if((*c1)==2)
		        	    ee->image = ee->response2;
			        if((*c1)==3)
		        	    ee->image=ee->response3;		     
		        	break;
			}
			break;
		case SDLK_UP: //Keyboard surfing up
			if(*p == 0){
			    if(*a == 0){
				Mix_PlayChannel(-1, c, 0);
				*i = *i - 1;
				if(*i==0)
				    *i = 3;
			    }
			    SDL_Delay(150);
			}
			if(*p == 6){
			    SDL_Delay(200);
		        	(*c1)--;
		        	if((*c1)<=0)
		            	    (*c1)=3;
			        if((*c1)==1)
		        	    ee->image = ee->response1;
			        if((*c1)==2)
		        	    ee->image = ee->response2;
			        if((*c1)==3)
		        	    ee->image=ee->response3;		     
		        	break;
			}
			break;
		case SDLK_RETURN:
			if(*p == 3){
				*p = 4;
				*tini = SDL_GetTicks();
			}else if(*p == 0){
				SDL_Delay(100); Mix_PlayChannel(-1, c, 0);
				if(*i == 1)
					*p = 1;
				else if(*i == 2)
					*p = 2;
				else
					*done = 0;
			}
			if(*p == 6){
			    if((*c1)>=1 && (*c1)<=3){
		            	    if((*c1)==1 && ee->d%3==1){
					correct(s,*ee);
					*score = *score + 50;
					m->ppl.x = 601;
					*p=4;
		              	    }else if ((*c1)==1 && ee->d%3==2){
					correct(s,*ee);
					*score = *score + 50;
					m->ppl.x = 601;
					*p=4;
		            	    }else if ((*c1)==1 && ee->d%3==0){
					correct(s,*ee);
					*score = *score + 50;
					m->ppl.x = 601;
					*p=4;
		          	    }else{
					lose(s, *ee);
					m->ppl.x = 601;
					*score = *score - 50;
					SDL_Delay(500);
					*p=4;
		            	    }
		           	}
			}
			break;
		case SDLK_f: //Fullscreen
		    if(*p != 3){
			*f = *f + 1;
			Mix_PlayChannel(-1, c, 0);
			if(*f%2 == 0)
				s = SDL_SetVideoMode(1920, 962, 32, SDL_SWSURFACE | SDL_SRCALPHA | SDL_FULLSCREEN);
			else
				s = SDL_SetVideoMode(1000, 500, 32, SDL_SWSURFACE | SDL_SRCALPHA);
		    }
			break;
		case SDLK_KP_MINUS: //Low Sound by 25
			if(*v>0)
				*v = *v - 25;
			SDL_Delay(100);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
			break;
		case SDLK_KP_PLUS: //Raise Sound by 25
			if(*v<100)
				*v = *v + 25;
			SDL_Delay(100);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
			break;
		case SDLK_q: //Quit Key
		    if(*p != 3){
			Mix_PlayChannel(-1, c, 0); SDL_Delay(250);
			*done = 0;
		    }
			break;

		//Scorlling Background + Minimap!! Will get removed.. Just for test!

		case SDLK_RIGHT: //This one is temporarily cause MajMinimap is the one
			if((*p == 4) && (m->ppl.x < 700) && (m->pos1.x == 200))
				m->ppl.x++;
			if((*p == 4) && (m->pos1.x < 200))
				m->pos1.x++;
			if((*p == 4) && (l1->pos2.x < 2000))
				l1->pos2.x = l1->pos2.x + 7;
			break;
		case SDLK_LEFT:
			if((*p == 4) && (m->ppl.x > m->pimg.x) && (m->pos1.x == 0))
				m->ppl.x--;
			if((*p == 4) && (m->pos1.x > 0))
				m->pos1.x--;
			if((*p == 4) && (l1->pos2.x > 0))
				l1->pos2.x = l1->pos2.x - 3;
			break;
		case SDLK_F1:
			*p = 7;
			break;
	}
}

void mainMenu_display(SDL_Surface *s, int a, image b1, image p0, image s0, image q0, image p1, image q1, image s1, image fbg, int f, image Fp0, image Fs0, image Fq0, image Fp1, image Fs1, image Fq1, int i)
{
   //Full Screen
   if(f%2 == 0){
	afficherBack(fbg, s); afficherButton(Fp0, s);
	afficherButton(Fs0, s); afficherButton(Fq0, s); 
	if((a == 1)||(i == 1))
		afficherButton(Fp1, s);
	else if((a == 2)||(i == 2))
		afficherButton(Fs1, s);
	else if((a == 3)||(i == 3))
		afficherButton(Fq1, s);
   //Windowed Screen
   }else{
	afficherBack(b1, s);     
	afficherButton(p0, s); afficherButton(s0, s);
	afficherButton(q0, s);
	if((a == 1)||(i == 1))
		afficherButton(p1, s);
	else if((a == 2)||(i == 2))
		afficherButton(s1, s);
	else if((a == 3)||(i == 3))
		afficherButton(q1, s);
   }
}

void menu_mousemotions(int p, SDL_Event e, int *a, int f, int *i)
{
    //Windowed Menu
	if(f%2!=0){
	//Play Button
		if((p == 0)&&(e.motion.x >= 430 && e.motion.x <= 565 && e.motion.y >= 200 && e.motion.y <= 255)){
			*a = 1;
			*i = 1;
		}
	//Settings Button
		else if((p==0)&&(e.motion.x >= 360 && e.motion.x <= 630 && e.motion.y >= 280 && e.motion.y <= 330)){
			*a = 2;
			*i = 2;
		}
	//Quit Button
		else if((p == 0)&&(e.motion.x >= 435 && e.motion.x <= 560 && e.motion.y >= 340 && e.motion.y <= 410)){
			*a = 3;
			*i = 3;
		}
	//Mouse not pointing on any other buttons
		else if(p == 0)
			*a = 0;
	}
    //Full Screen
	else{
	//Play Button
		if((p == 0)&&(e.motion.x >= 815 && e.motion.x <= 950 && e.motion.y >= 345 && e.motion.y <= 405)){
			*a = 1;
			*i = 1;
		}
	//Settings Button
		else if((p==0)&&(e.motion.x >= 755 && e.motion.x <= 1020 && e.motion.y >= 450 && e.motion.y <= 510)){
			*a = 2;
			*i = 2;
		}
	//Quit Button
		else if((p == 0)&&(e.motion.x >= 820 && e.motion.x <= 945 && e.motion.y >= 555 && e.motion.y <= 605)){
			*a = 3;
			*i = 3;
		}
	//Mouse not pointing on any other buttons
		else if(p == 0)
			*a = 0;
	}
}

void menu_mouseclickdown(int *p, SDL_Event e, Mix_Chunk *c, int *done, int *f, SDL_Surface *s, int *v, Mix_Music *ss, Mix_Music *mms, int *k)
{
	int as;
	as = settings_mousemotions(*p, e, *f);
   //Windowed Mod:
	if(*f%2!=0){
	   //Main Menu:
		//Play Button
		if((*p == 0)&&(e.motion.x >= 430 && e.motion.x <= 565 && e.motion.y >= 200 && e.motion.y <= 255)){
			Mix_PlayChannel(-1, c, 0);
			*p = 1;
			SDL_Delay(200);
    		//Settings Button
		}else if((*p==0)&&(e.motion.x >= 360 && e.motion.x <= 630 && e.motion.y >= 280 && e.motion.y <= 330)){
			Mix_PlayMusic(ss, -1);
			Mix_PlayChannel(-1, c, 0);
			*p = 2;
    		//Quit Button
		}else if((*p == 0)&&(e.motion.x >= 435 && e.motion.x <= 560 && e.motion.y >= 340 && e.motion.y <= 410)){
			Mix_PlayChannel(-1, c, 0); SDL_Delay(500);
			*done = 0;
	   //Play Menu:
		}else if((*p == 1)&&(e.motion.x >= 925 && e.motion.x <= 975 && e.motion.y >= 435 && e.motion.y <= 475)){
			Mix_PlayChannel(-1, c, 0);
			*p = 0;
		}else if((*p == 1)&&(e.motion.x >= 430 && e.motion.x <= 565 && e.motion.y >= 200 && e.motion.y <= 255)){
			Mix_PlayChannel(-1, c, 0);
			*p = 3;
	   //Settings:
		//Full Screen Box
		}else if(as == 1){
			Mix_PlayChannel(-1, c, 0);
			s = SDL_SetVideoMode(1920, 962, 32, SDL_SWSURFACE | SDL_SRCALPHA | SDL_FULLSCREEN);
			*f = *f + 1;
		
		//Plus Button
		}else if(as == 2){
			if(*v<100)
				*v = *v + 25;
			SDL_Delay(250);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
		//Minus Button
		}else if(as == 3){
			if(*v>0)
				*v = *v - 25;
			SDL_Delay(250);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
		//Return Icon
		}else if(as == 4){
			*p = 0;
			Mix_PlayChannel(-1, c, 0);
			Mix_PlayMusic(mms, -1);
		//Hotkeys Button
		}else if(as == 5){
			*k = 1;
			Mix_PlayChannel(-1, c, 0);
		//Highscore Button 
		}else if(as == 6){
			*k = 2;
			Mix_PlayChannel(-1, c, 0);
		}
   //Fullscreen:
	}else{
	   //Main Menu:
		//Play Button
		if((*p == 0)&&(e.motion.x >= 815 && e.motion.x <= 950 && e.motion.y >= 345 && e.motion.y <= 405)){
			Mix_PlayChannel(-1, c, 0);
			*p = 1;
   		//Settings Button
		}else if((*p==0)&&(e.motion.x >= 755 && e.motion.x <= 1020 && e.motion.y >= 450 && e.motion.y <= 510)){
			Mix_PlayMusic(ss, -1);
			Mix_PlayChannel(-1, c, 0);
			*p = 2;
   		//Quit Button
		}else if((*p == 0)&&(e.motion.x >= 820 && e.motion.x <= 945 && e.motion.y >= 555 && e.motion.y <= 605)){
			Mix_PlayChannel(-1, c, 0); SDL_Delay(500);
			*done = 0;
	   //Play Menu:
		}else if((*p == 1)&&(e.motion.x >= 1845 && e.motion.x <= 1895 && e.motion.y >= 897 && e.motion.y <= 947)){
			Mix_PlayChannel(-1, c, 0);
			*p = 0;
		}else if((*p == 1)&&(e.motion.x >= 815 && e.motion.x <= 950 && e.motion.y >= 345 && e.motion.y <= 405)){
			Mix_PlayChannel(-1, c, 0);
			*p = 3;
	   //Settings:
		//Full Screen Box
		}else if(as == 1){
			Mix_PlayChannel(-1, c, 0);
			s = SDL_SetVideoMode(1000, 500, 32, SDL_SWSURFACE | SDL_SRCALPHA);
			*f = *f + 1;
		//Plus Button
		}else if(as == 2){
			if(*v<100)
				*v = *v + 25;
			SDL_Delay(250);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
		//Minus Button
		}else if(as == 3){
			if(*v>0)
				*v = *v - 25;
			SDL_Delay(250);
			Mix_VolumeMusic(*v); Mix_VolumeChunk(c, *v);
			Mix_PlayChannel(-1, c, 0);
		//Return Icon
		}else if(as == 4){
			*p = 0;
			Mix_PlayChannel(-1, c, 0);
			Mix_PlayMusic(mms, -1);
		//Hotkeys Button
		}else if(as == 5){
			*k = 1;
			Mix_PlayChannel(-1, c, 0); 
		}
	}
}

void playMenu_display(image bg1, SDL_Surface *s, int f, image fbg1, image re, image res, image fre, image fres, SDL_Event e, int p, image p0, image p1, image Fp0, image Fp1, image btn, image btn2)
{
	int as;
	as = play_mousemotions(p, e, f);
    //Fullscreen
	if(f%2 == 0){
		if(as == 0){
			afficherBack(fbg1, s); afficherButton(fre, s);
			afficherButton(Fp0, s);
		}else if(as == 1)
			afficherButton(fres, s);
		else if(as == 2)
			afficherButton(Fp1, s);
    //Window Mod
	}else{
		if(as == 0){
			afficherBack(bg1, s); afficherButton(re, s);
			afficherButton(p0, s); afficherButton(btn, s); afficherButton(btn2, s);
		}else if(as == 1)
			afficherButton(res, s);
		else if(as == 2)
			afficherButton(p1, s);
	}
}

int play_mousemotions(int p, SDL_Event e, int f)
{
	int as;

    //Fullscreen
	if(f%2 == 0){
		if((p == 1)&&(e.motion.x >= 1845 && e.motion.x <= 1895 && e.motion.y >= 897 && e.motion.y <= 947))
			as = 1;
		else if((p == 1)&&(e.motion.x >= 815 && e.motion.x <= 950 && e.motion.y >= 345 && e.motion.y <= 405))
			as = 2;
		else
			as = 0;
    //Window Mod
	}else{
		if((p == 1)&&(e.motion.x >= 925 && e.motion.x <= 975 && e.motion.y >= 435 && e.motion.y <= 475))
			as = 1;
		else if((p == 1)&&(e.motion.x >= 430 && e.motion.x <= 565 && e.motion.y >= 200 && e.motion.y <= 255))
			as = 2;
		else
			as = 0;
	}

	return as;
}

int settings_mousemotions(int p, SDL_Event e, int f)
{
	int as;

    //Windowed Mod:
	if(f%2!=0){
	//Full Screen Box
		if((p == 2)&&(e.motion.x >= 323 && e.motion.x <= 367 && e.motion.y >= 92 && e.motion.y <= 140))
			as = 1;
	//Plus Icon
		else if((p == 2)&&(e.motion.x >= 415 && e.motion.x <= 472 && e.motion.y >= 205 && e.motion.y <= 265))
			as = 2;
	//Minus Icon
		else if((p == 2)&&(e.motion.x >= 525 && e.motion.x <= 575 && e.motion.y >= 230 && e.motion.y <= 250))
			as = 3;
	//Return Icon
		else if((p == 2)&&(e.motion.x >= 925 && e.motion.x <= 975 && e.motion.y >= 435 && e.motion.y <= 475))
			as = 4;
	//Hotkeys Button
		else if((p == 2)&&(e.motion.x >= 55 && e.motion.x <= 360 && e.motion.y >= 310 && e.motion.y <= 405))
			as = 5;
	//Highscore Button
		else if((p == 2)&&(e.motion.x >= 380 && e.motion.x <= 830 && e.motion.y >= 306 && e.motion.y <= 406))
			as = 6;
	//Mouse not poining on any other buttons
		else if(p == 2)
			as = 0;
	}
    //Full Screen Mod
	else{
	//Full Screen Box
		if((p == 2)&&(e.motion.x >= 558 && e.motion.x <= 628 && e.motion.y >= 230 && e.motion.y <= 298))
			as = 1;
	//Plus Icon
		else if((p == 2)&&(e.motion.x >= 700 && e.motion.x <= 800 && e.motion.y >= 400 && e.motion.y <= 500))
			as = 2;
	//Minus Icon
		else if((p == 2)&&(e.motion.x >= 900 && e.motion.x <= 1000 && e.motion.y >= 430 && e.motion.y <= 475))
			as = 3;
	//Return Icon
		else if((p == 2)&&(e.motion.x >= 1845 && e.motion.x <= 1895 && e.motion.y >= 897 && e.motion.y <= 947))
			as = 4;
	//Hotkeys Button
		else if((p == 2)&&(e.motion.x >= 65 && e.motion.x <= 506 && e.motion.y >= 610 && e.motion.y <= 740))
			as = 5;
	//Mouse not poining on any other buttons
		else if(p == 2)
			as = 0;
	}

	return as;
}

void settingsMenu_display(SDL_Event e, image bg1, SDL_Surface *s, text t, text fst, int f, image fbg1, text ft, image t0, text st, int p, image t0s, image t1, image t1s, text s1t, image pl0, image pl1, image mi0, image mi1, text fs1t, image fpl0, image fpl1, image fmi0, image fmi1, image re, image res, image fre, image fres, image h0, image h1, int k, image hbg, image fh0, image fh1, image fhbg, image bg, text be, char meill[], image hi0, image hi1)
{
	int as, best;
	char bes[3];
	as = settings_mousemotions(p, e, f);

    //Full Screen
	if(f%2 == 0){
	    if(k==1)
		afficherBack(fhbg, s); 
	    else{
		if(as == 0){
			afficherBack(fbg1, s);
			displayText(ft, s, "Settings"); displayText(fst, s, "Full-Screen:"); displayText(fs1t, s, "Music Volume:");
			afficherButton(t1, s); afficherButton(fpl0, s); afficherButton(fmi0, s); afficherButton(fre, s); afficherButton(fh0, s);
		}else if(as == 1)
			afficherButton(t1s, s); 
		else if(as == 2)
			afficherButton(fpl1, s);
		else if(as == 3)
			afficherButton(fmi1, s); 
		else if(as == 4)
			afficherButton(fres, s);
		else if(as == 5)
			afficherButton(fh1, s);
	   }
    //Window Screen
	}else{
	   if(k==1)
		afficherBack(hbg, s);
	   else if(k==2){
		meilleur("players.txt", &best, meill); afficherBack(bg, s); sprintf(bes, "%d", best); strcat(be.ch, meill); strcat(be.ch, "  Score: "); strcat(be.ch , bes);
		displayText(be, s, be.ch);  
	   }else{
		if(as == 0){
			afficherBack(bg1, s);
			displayText(t, s, "Settings"); displayText(st, s, "Full-Screen:"); displayText(s1t, s, "Music Volume:");
			afficherButton(t0, s); afficherButton(pl0, s); afficherButton(mi0, s); afficherButton(re, s); afficherButton(h0, s);
			afficherButton(hi0, s);
	 	}else if(as == 1)
			afficherButton(t0s, s);
		else if(as == 2)
			afficherButton(pl1, s);
		else if(as == 3)
			afficherButton(mi1, s);
		else if(as == 4)
			afficherButton(res, s);
		else if(as == 5)
			afficherButton(h1, s);
		else if(as == 6)
			afficherButton(hi1, s);
	    }
	}
}

void typing_name(SDL_Surface *s, image nbg, text str, int *p, image fnbg, int f, text fstr)
{
   //Window Screen
	if(f%2 != 0){
		afficherBack(nbg, s);
		showInput(str, s, p);
   //Full Screen
	}else{
		afficherBack(fnbg, s);
		showInput(fstr, s, p);
	}
}

void level_display(image l1, SDL_Surface *s, minimap m, int *T, text te, text sct, int *score, int tini, int *Ti, image fl1, int f, int *p, text str, ES *enem)
{
   //Window Screen
	if(f%2 != 0){
		afficherBack(l1, s); afficher(m, s); 
		*T = timeGame(s, te, tini)/1000; 
		score_player(score, *T, Ti, sct, s);
		afficher_es(*enem,s);
                   animer_es(enem);
                   move_es(enem); 
		if(m.ppl.x == 700){
			*p = 1;
			sauvegarder(*score, str.ch, "players.txt");
		}
		if(*score == 0){
			*p = 1;
			sauvegarder(0, str.ch, "players.txt");
		}
   //Full Screen
	}else{
		afficherBack(fl1, s); afficher(m, s);
	}
}

void free_surfaces(image bg, image bg1, image fbg, image p0, image p1, image s0, image s1, image q0, image q1, image t0, image t0s, image t1, image t1s, image pl0, image pl1, image mi0, image mi1)
{
	liberer(bg); liberer(bg1); liberer(fbg); liberer(p0); liberer(p1); liberer(s0); liberer(s1); liberer(q0); liberer(mi1);
	liberer(q1); liberer(t0); liberer(t0s); liberer(t1); liberer(t1s); liberer(pl0); liberer(pl1); liberer(mi0);
}

void free_surfaces1(image Fp0, image Fs0, image Fq0, image Fp1, image Fs1, image Fq1, image fpl0, image fpl1, image fmi0, image fmi1, image re, image res, image fre, image fres)
{
	liberer(Fp0); liberer(Fs0); liberer(Fq0); liberer(Fp1); liberer(Fs1); liberer(Fq1); liberer(fre);
	liberer(fpl0); liberer(fpl1); liberer(fmi0); liberer(fmi1); liberer(re); liberer(res); liberer(fres);
}

void free_surfaces2(image h0, image h1, image hbg, image fh0, image fh1, image fhbg, minimap m, image l1, image nbg)
{
	liberer(h0); liberer(h1); liberer(hbg); liberer(fh0); liberer(fh1);
	liberer(fhbg); Liberer(&m); liberer(nbg); liberer(l1);
}

void free_text_audio(text t, text ft, text st, Mix_Music *mms, Mix_Chunk *cs, text fst, text s1t, text fs1t, Mix_Music *ss, text te, text sct)
{
	freeText(t); freeText(ft); freeText(st); freeText(fst); freeText(s1t); freeText(fs1t);
	Mix_FreeMusic(mms); Mix_FreeMusic(ss); Mix_FreeChunk(cs); freeText(te); freeText(sct);
}
