/**  
* @file minimap.c  
* @brief Testing Program.  
* @author Generation-Z Team  
* @version 0.1
* @date Apr 19, 2022  
*  
* Testing program for minimap *  
*/

#include "minimap.h"

/**  
* @brief To initialize the minimap m .  
* @param m the minimap 
* @return Nothing  
*/  
void initminimap(minimap *m) // It works fine
{
	m->img = IMG_Load("Pictures/Backgrounds/minimap.png");

	m->pimg.x = 250;
	m->pimg.y = 0;

	m->pl = IMG_Load("Pictures/Backgrounds/point.png");

	m->ppl.x = 270;
	m->ppl.y = 130;

	m->pos1.x = 0;
	m->pos1.y = 0;
	m->pos1.w = 500;
	m->pos1.h = 200;
}

/**  
* @brief To synchronize the movement of the player to the minimap icon
* @param posJoueur the position of the player
* @parm m the minimap
* @parm camera the coordinates of the camera
* @parm redimensionnement the percentage of redimensioning
* @return Nothing  
*/  
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement) // Probably fine, but we have no clue until we integrate things together I guess.
{
	SDL_Rect posJoueurABS;

	posJoueurABS.x = posJoueur.x + camera.x;
	posJoueurABS.y = posJoueur.y + camera.y;

	m->ppl.x = posJoueurABS.x * redimensionnement/100;
	m->ppl.y = posJoueurABS.y * redimensionnement/100;
}

/**  
* @brief To show the minimap on the screen
* @parm m the minimap
* @parm s the surface
* @return Nothing  
*/  
void afficher(minimap m, SDL_Surface *s) // It works fine
{
	SDL_BlitSurface(m.img, &m.pos1, s, &m.pimg);
	SDL_BlitSurface(m.pl, NULL, s, &m.ppl);
}

/**  
* @brief To liberate the minimap once we close the game
* @parm m the minimap
* @return Nothing  
*/  
void Liberer(minimap *m) //It works fine
{
	SDL_FreeSurface(m->img);
	SDL_FreeSurface(m->pl);
}

/**  
* @brief To calculate the time of each round
* @parm s The screen
* @parm te The text of the time
* @parm t0 The time initial of every new round
* @return t The time spent playing the round 
*/  
int timeGame(SDL_Surface *s, text te, int t0) // It works fine
{
	int t;
	char ti[3], time[20]="Time Played: ";

	t = SDL_GetTicks() - t0;
	sprintf(ti, "%d", t/1000);
	strcat(time, ti);
	strcat(time, "(s)");
	displayText(te, s, time);

	return t;
}

void timeEnigme(SDL_Surface *s) /** ### This is the current clue about the Enigme process. ### **/
{
	/**
	Uint32 t;
	char ti[3], time[20]="Time Remaining: ";

	do{
		t = SDL_GetTicks();
		sprintf(ti, "%d", 30-(t/1000)) //30 seconds.
		strcat(time, "(s)");
		displayText(te, s, time);
		if(30 - (t/1000) == 0){
			Enigme.Done() = 1;
			displayText(te, s, "Time is UP!");
		}
	}while(Enigme.Done() != 1) //How Engime.Done() function is going to work?
	**/
}

/**  
* @brief To type the name of the player before the game
* @parm e The event 
* @parm str The variable that contains the player's name in window mod
* @parm p The mod of game (Play, Settings etc..)
* @parm fstr The variable that containts the player's name in full screen
* @return Nothing
*/  
void HandleInput(SDL_Event e, text *str, int *p, text *fstr) // It works fine
{
	if(*p==3){
		SDL_Delay(200);
        	if((strlen(str->ch) <= 20) && (strlen(fstr->ch) <= 20)){
		    if(e.key.keysym.sym == SDLK_SPACE){
                	str->ch[strlen(str->ch)] = ' '; fstr->ch[strlen(fstr->ch)] = ' ';
		    }else if(e.key.keysym.sym == SDLK_a){
                	str->ch[strlen(str->ch)] = 'a'; fstr->ch[strlen(fstr->ch)] = 'a';
            	    }else if(e.key.keysym.sym == SDLK_b){
                	str->ch[strlen(str->ch)] = 'b'; fstr->ch[strlen(fstr->ch)] = 'b';
            	    }else if(e.key.keysym.sym == SDLK_c){
                	str->ch[strlen(str->ch)] = 'c'; fstr->ch[strlen(fstr->ch)] = 'c';
		    }else if(e.key.keysym.sym == SDLK_d){
                	str->ch[strlen(str->ch)] = 'd'; fstr->ch[strlen(fstr->ch)] = 'd';
            	    }else if(e.key.keysym.sym == SDLK_e){
                	str->ch[strlen(str->ch)] = 'e'; fstr->ch[strlen(fstr->ch)] = 'e';
            	    }else if(e.key.keysym.sym == SDLK_f){
                	str->ch[strlen(str->ch)] = 'f'; fstr->ch[strlen(fstr->ch)] = 'f';
		    }else if(e.key.keysym.sym == SDLK_g){
                	str->ch[strlen(str->ch)] = 'g'; fstr->ch[strlen(fstr->ch)] = 'g';
            	    }else if(e.key.keysym.sym == SDLK_h){
                	str->ch[strlen(str->ch)] = 'h'; fstr->ch[strlen(fstr->ch)] = 'h';
            	    }else if(e.key.keysym.sym == SDLK_i){
                	str->ch[strlen(str->ch)] = 'i'; fstr->ch[strlen(fstr->ch)] = 'i';
		    }else if(e.key.keysym.sym == SDLK_j){
                	str->ch[strlen(str->ch)] = 'j'; fstr->ch[strlen(fstr->ch)] = 'j';
            	    }else if(e.key.keysym.sym == SDLK_k){
                	str->ch[strlen(str->ch)] = 'k'; fstr->ch[strlen(fstr->ch)] = 'k';
            	    }else if(e.key.keysym.sym == SDLK_l){
                	str->ch[strlen(str->ch)] = 'l'; fstr->ch[strlen(fstr->ch)] = 'l';
		    }else if(e.key.keysym.sym == SDLK_m){
                	str->ch[strlen(str->ch)] = 'm'; fstr->ch[strlen(fstr->ch)] = 'm';
            	    }else if(e.key.keysym.sym == SDLK_n){
                	str->ch[strlen(str->ch)] = 'n'; fstr->ch[strlen(fstr->ch)] = 'n';
            	    }else if(e.key.keysym.sym == SDLK_o){
                	str->ch[strlen(str->ch)] = 'o'; fstr->ch[strlen(fstr->ch)] = 'o';
		    }else if(e.key.keysym.sym == SDLK_p){
                	str->ch[strlen(str->ch)] = 'p'; fstr->ch[strlen(fstr->ch)] = 'p';
            	    }else if(e.key.keysym.sym == SDLK_q){
                	str->ch[strlen(str->ch)] = 'q'; fstr->ch[strlen(fstr->ch)] = 'q';
            	    }else if(e.key.keysym.sym == SDLK_r){
                	str->ch[strlen(str->ch)] = 'r'; fstr->ch[strlen(fstr->ch)] = 'r';
		    }else if(e.key.keysym.sym == SDLK_s){
                	str->ch[strlen(str->ch)] = 's'; fstr->ch[strlen(fstr->ch)] = 's';
            	    }else if(e.key.keysym.sym == SDLK_t){
                	str->ch[strlen(str->ch)] = 't'; fstr->ch[strlen(fstr->ch)] = 't';
            	    }else if(e.key.keysym.sym == SDLK_u){
                	str->ch[strlen(str->ch)] = 'u'; fstr->ch[strlen(fstr->ch)] = 'u';
		    }else if(e.key.keysym.sym == SDLK_v){
                	str->ch[strlen(str->ch)] = 'v'; fstr->ch[strlen(fstr->ch)] = 'v';
            	    }else if(e.key.keysym.sym == SDLK_w){
                	str->ch[strlen(str->ch)] = 'w'; fstr->ch[strlen(fstr->ch)] = 'w';
            	    }else if(e.key.keysym.sym == SDLK_x){
                	str->ch[strlen(str->ch)] = 'x'; fstr->ch[strlen(fstr->ch)] = 'x';
		    }else if(e.key.keysym.sym == SDLK_y){
                	str->ch[strlen(str->ch)] = 'y'; fstr->ch[strlen(fstr->ch)] = 'y';
            	    }else if(e.key.keysym.sym == SDLK_z){
                	str->ch[strlen(str->ch)] = 'z'; fstr->ch[strlen(fstr->ch)] = 'z';
		    }
		}

		if((e.key.keysym.sym == SDLK_BACKSPACE) && (strlen(str->ch) != 0)){
		    str->ch[strlen(str->ch)-1] = '\0';
		}

		if((e.key.keysym.sym == SDLK_BACKSPACE) && (strlen(fstr->ch) != 0)){
		    fstr->ch[strlen(fstr->ch)-1] = '\0';
		}
	}
}

/**  
* @brief To show the player's name on the screen
* @parm str The variable that contains the player's name
* @parm s The screen
* @parm p The mod of game (Play, Settings etc..)
* @return Nothing
*/  
void showInput(text str, SDL_Surface *s, int *p) //It works fine
{
	if(strlen(str.ch) != 0)
		displayText(str, s, str.ch);
}

/**  
* @brief To save the player's name and his score
* @parm score The score of the player
* @parm nomjoueur The player's name
* @parm nomfichier The file's name that containts the name and the score of the player
* @return Nothing
*/  
void sauvegarder(int score, char nomjoueur[], char nomfichier[]) //It works fine
{
	FILE *f;

	f = fopen(nomfichier, "a");
	if(f == NULL)
		printf("Memory error (sauvegarder() function in minimap.c)\n");
	else{
		fprintf(f, "Name: %s  Score: %d\n", nomjoueur, score);
	}
	fclose(f);
}

/**  
* @brief To save the player's name and his score
* @parm score The score of the player
* @parm nom The player's name
* @parm nomfichier The file's name that containts the name and the score of the player
* @return Nothing
*/  
void meilleur(char nomfichier[], int *score, char nom[]) //It works fine
{
	FILE *f;
	int scor[100], max, k=0, i, indice=0;
	char nomjoueur[20][100];

	f = fopen(nomfichier, "r");
	if(f == NULL)
		printf("Memory error (meilleur() function in minimap.c)\n");
	else{
		while(!feof(f)){
			fscanf(f, "Name: %s  Score: %d\n", nomjoueur[k], &scor[k]);
			k++;
        }
		max = scor[0];
		for(i=1; i<k; i++){
			if(max < scor[i]){
				max = scor[i];
				indice = i;
			}
		}
		*score = max;
		strcpy(nom, nomjoueur[indice]);
	}
	fclose(f);
}

/**  
* @brief To modify the score of the player depending on the time and position of the player
* @parm score The score of the player
* @parm t Last time saved
* @parm Ti Time of the round
* @parm sct The text that contains the score of the player in the round
* @parm s The screen
* @return Nothing
*/  
void score_player(int *score, int t, int *Ti, text sct, SDL_Surface *s) //It works fine
{
	char scr[3];

	sprintf(scr, "%d", *score);
	strcat(sct.ch, scr);
    //Score decreases by 2 every second.
	if((t>*Ti) && (*score>0)){
		*Ti = t;
		*score = *score - 2;
	}
	displayText(sct, s, sct.ch);

    //Score will get decreased by touching the enemy! (Will get added once Enemy file gets ready)...
}

void AI_Play_Vs_Computer()
{
	// Waiting for Esprit
}
