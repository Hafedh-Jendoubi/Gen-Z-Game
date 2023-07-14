#include "sauv.h"

void sauvgrad (player p, image b, char * nomfichier, int score)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d %d %d %d\n", p.pos->x, p.pos->y,score,b.pos2.x,b.pos2.y);

	fclose(f);
}

int charger (player *p, image *b , char * nomfichier, int *score)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	
		
		fscanf(f,"%hd %hd %d %hd %hd \n",&p->pos->x,&p->pos->y,score,&b->pos2.x,&b->pos2.y);
		
	}
	fclose(f);
}
int mainsauvgrade(SDL_Surface *screen,player p, image b,int *done, int score)

{


		int continuer=1;
	 SDL_Surface *image,*btn,*btn2;
    SDL_Rect postionimage,posbtn,posbtn2;
    SDL_Event event2;
	
	
	
//initialisation  de BG et du perso 

	image=IMG_Load("background.jpeg");
    postionimage.x=0;
    postionimage.y=0;
	btn=IMG_Load("dntsave.png");
	btn2=IMG_Load("save.png");
	posbtn.x=650;
	posbtn.y=250;
	posbtn2.x=650;
	posbtn2.y=350;


        SDL_BlitSurface(image, NULL,screen,&postionimage);
	SDL_BlitSurface(btn,NULL,screen,&posbtn);
	SDL_BlitSurface(btn2,NULL,screen,&posbtn2);

       SDL_Flip(screen);

	
	while (continuer)
	{	
	SDL_PollEvent(&event2);
	switch(event2.type)
        {

       case SDL_QUIT: 
	
	continuer=0;
	*done=0;
	break;
	
	    case SDL_MOUSEBUTTONDOWN :
            
            if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.button.x<posbtn.x+btn->w && event2.button.x>posbtn.x)&&(event2.button.y<posbtn.y+btn->h && event2.button.y>posbtn.y))

{

        continuer=0;
	*done=0;
        p.pos->x=0;
	p.pos->y=200;
     sauvgrad(p,b,"sauv.txt", score);
}


 if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.button.x<posbtn2.x+btn2->w && event2.button.x>posbtn2.x)&&(event2.button.y<posbtn2.y+btn2->h && event2.button.y>posbtn2.y))
{

  sauvgrad(p,b,"sauv.txt", score);
  continuer=0;
	*done=0;
}



	}
		

	}

}
/*
void arduinoWriteData(char x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE *f;

    f=fopen(chemin,"w");
    if(f == NULL)
        printf("error");

    fprintf(f,"%d",x);
    fclose(f);

   
}

void arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE *f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        printf("error");

    fscanf(f,"%d",x);

    fclose(f);

    
}*/
