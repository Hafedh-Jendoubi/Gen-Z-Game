#include "texte.h"

void initText(text *t)
{
	t->position.x = 15;
	t->position.y = 420;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 60);
}

void initfText(text *t)
{
	t->position.x = 15;
	t->position.y = 820;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 120);
}

void initText1(text *t)
{
	t->position.x = 50;
	t->position.y = 75;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 75);
}

void initfText1(text *t)
{
	t->position.x = 75;
	t->position.y = 185;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 135);
}

void initText2(text *t)
{
	t->position.x = 50;
	t->position.y = 200;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 75);
}

void initfText2(text *t)
{
	t->position.x = 75;
	t->position.y = 375;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 135);
}

void initTextTe(text *t)
{
	t->position.x = 830;
	t->position.y = 10;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 30);
}

void initStringInp(text *t)
{
	t->position.x = 450;
	t->position.y = 195;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 50);

	strcpy(t->ch, "");
}

void finitStringInp(text *t)
{
	t->position.x = 800;
	t->position.y = 375;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 90);

	strcpy(t->ch, "");
}

void initBest(text *t)
{
	t->position.x = 50;
	t->position.y = 200;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 75);

	strcpy(t->ch, "Name: ");
}

void initScoreText(text *t)
{
	t->position.x = 10;
	t->position.y = 10;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 30);

	strcpy(t->ch, "Score: ");
}

void freeText(text t)
{
	SDL_FreeSurface(t.surfaceTexte);
}

void displayText(text t, SDL_Surface *screen, char ch[])
{
	t.surfaceTexte = TTF_RenderText_Solid(t.font, ch, t.textColor);
	SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}
