#include "tic.h"

void initialiserTic(tic *t)
{
	int i;

	initN(&t->n);
	initY(&t->y);
	for(i=0; i<9; i++)
		t->tabsuivi[i] = 0;	
	t->pos1.x = 350; t->pos1.y = 100;
	t->tour = 0;
}

int clicks(SDL_Event e)
{
	int coup;

	if(e.motion.x >= 350 && e.motion.x <= 450 && e.motion.y >= 100 && e.motion.y <= 200)
		coup = 0;
	else if(e.motion.x >= 450 && e.motion.x <= 550 && e.motion.y >= 100 && e.motion.y <= 200)
		coup = 1;
	else if(e.motion.x >= 550 && e.motion.x <= 650 && e.motion.y >= 100 && e.motion.y <= 200)
		coup = 2;
	else if(e.motion.x >= 350 && e.motion.x <= 450 && e.motion.y >= 200 && e.motion.y <= 300)
		coup = 3;
	else if(e.motion.x >= 450 && e.motion.x <= 550 && e.motion.y >= 200 && e.motion.y <= 300)
		coup = 4;
	else if(e.motion.x >= 550 && e.motion.x <= 650 && e.motion.y >= 200 && e.motion.y <= 300)
		coup = 5;
	else if(e.motion.x >= 350 && e.motion.x <= 450 && e.motion.y >= 300 && e.motion.y <= 400)
		coup = 6;
	else if(e.motion.x >= 450 && e.motion.x <= 550 && e.motion.y >= 300 && e.motion.y <= 400)
		coup = 7;
	else if(e.motion.x >= 550 && e.motion.x <= 650 && e.motion.y >= 300 && e.motion.y <= 400)
		coup = 8;

	return coup;
}

void afficherTic(tic t, SDL_Surface *s)
{
   //Displaying who's round is it:
	if((t.tour+t.joueur)%2 == 0)
		afficherButton(t.y, s);
	else
		afficherButton(t.n, s);

   //Displaying Background:
	int i; SDL_Rect tab[9];

	tab[0] = t.pos1;
	tab[1].x = t.pos1.x + 103; tab[1].y = t.pos1.y;
	tab[2].x = t.pos1.x + 206; tab[2].y = t.pos1.y;
	tab[3].x = t.pos1.x; tab[3].y = t.pos1.y + 100;
	tab[4].x = t.pos1.x + 100; tab[4].y = t.pos1.y + 100;
	tab[5].x = t.pos1.x + 200; tab[5].y = t.pos1.y + 100;
	tab[6].x = t.pos1.x; tab[6].y = t.pos1.y + 200;
	tab[7].x = t.pos1.x + 100; tab[7].y = t.pos1.y + 200;
	tab[8].x = t.pos1.x + 200; tab[8].y = t.pos1.y + 200;

	for(i=0; i<9; ++i){
		if(t.tabsuivi[i] == -1)
			SDL_BlitSurface(t.n.img, NULL, s, &tab[i]);
		else if(t.tabsuivi[i] == 1)
			SDL_BlitSurface(t.y.img, NULL, s, &tab[i]);
	}
}

int atilganer(int tabsuivi[])
{
	if((tabsuivi[0] == tabsuivi[1]) && (tabsuivi[0] == tabsuivi[2]))
		return tabsuivi[0];
	else if((tabsuivi[3] == tabsuivi[4]) && (tabsuivi[3] == tabsuivi[5]))
		return tabsuivi[3];
	else if((tabsuivi[6] == tabsuivi[7]) && (tabsuivi[6] == tabsuivi[8]))
		return tabsuivi[6];
	else if((tabsuivi[0] == tabsuivi[3]) && (tabsuivi[0] == tabsuivi[6]))
		return tabsuivi[0];
	else if((tabsuivi[1] == tabsuivi[4]) && (tabsuivi[1] == tabsuivi[7]))
		return tabsuivi[1];
	else if((tabsuivi[2] == tabsuivi[5]) && (tabsuivi[2] == tabsuivi[8]))
		return tabsuivi[2];
	else if((tabsuivi[0] == tabsuivi[4]) && (tabsuivi[0] == tabsuivi[8]))
		return tabsuivi[0];
	else if((tabsuivi[2] == tabsuivi[4]) && (tabsuivi[2] == tabsuivi[6]))
		return tabsuivi[2];
	else 
		return 0;
}

void Resultat(int tabsuivi[], SDL_Surface *s, text t)
{
	int result = atilganer(tabsuivi);

	if(result == 1) //Machine
		displayText(t, s, "You Lost!");
	else if(result == 0)
		displayText(t, s, "Draw");
	else
		displayText(t, s, "You won!");
}

int minmax(int tabsuivi[], int joueur)
{
	int gagnant = atilganer(tabsuivi);
	if(gagnant!=0)
		return gagnant*joueur;

	int coup = -1, score = -2, i;
	for(i=0; i<9; ++i){
		if(tabsuivi[i] == 0){
			tabsuivi[i] = joueur;
			int mmscore = -minmax(tabsuivi, joueur*-1);
			if(mmscore>score){
				score = mmscore;
				coup = i;
			}
			tabsuivi[i] = 0;
		}
	}
	if(coup == -1)
		return 0;
	return score;
}

void calcul_coup(int tabsuivi[])
{
	int coup = -1, score = -2, i;

	for(i=0; i<9; ++i){
		if(tabsuivi[i] == 0){
			tabsuivi[i] = 1;
			int mmscore = -minmax(tabsuivi, -1);
			tabsuivi[i] = 0;
			if(mmscore > score){
				score = mmscore;
				coup = i;
			}
		}
	}
	tabsuivi[coup] = 1;
}

void terminer(tic t)
{
	liberer(t.n); liberer(t.y);
}
