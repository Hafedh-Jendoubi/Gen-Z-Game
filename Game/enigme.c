#include "enigme.h"

#include <time.h>










void init_enigmes(enigme *e ){



int nbligne=0;

char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int posrepvrai;



FILE *f=NULL;
f=fopen("questionreponse","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",question,reponse1,reponse2,reponse3,&posrepvrai)!=EOF)
{
nbligne++;
}
fclose(f);
} 
//printf("%d",nbligne);





srand(time(0));
int alea=rand()%(2*nbligne);


int check=0;




///gener nombre aleatoire


f=fopen("questionreponse","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",e->question,e->reponse1,e->reponse2,e->reponse3,&e->posrepvrai)!=EOF)
{
check++;
if(check==alea){break;}

}
fclose(f);
}


e->positionquestion.x=220;
e->positionquestion.y=200;

e->positionreponse1.x=260;
e->positionreponse1.y=365;

e->positionreponse2.x=560;
e->positionreponse2.y=365;

e->positionreponse3.x=860;
e->positionreponse3.y=365;






TTF_Font*police=NULL;
police=TTF_OpenFont("texxte.ttf",50);

SDL_Color black={0,0,0};
SDL_Color red={155,0,0};



e->surfacequestion=TTF_RenderText_Blended(police,e->question,red);
e->surfacereponse1=TTF_RenderText_Blended(police,e->reponse1,black);
e->surfacereponse2=TTF_RenderText_Blended(police,e->reponse2,black);
e->surfacereponse3=TTF_RenderText_Blended(police,e->reponse3,black);}






void animer(enigme *e,SDL_Rect *pos_sprite,int j){
pos_sprite->x=j*pos_sprite->w;
}



void afficherenigme(enigme e,SDL_Surface *screen){
SDL_BlitSurface(e.surfacequestion,NULL,screen,&e.positionquestion);
SDL_BlitSurface(e.surfacereponse1,NULL,screen,&e.positionreponse1);
SDL_BlitSurface(e.surfacereponse2,NULL,screen,&e.positionreponse2);
SDL_BlitSurface(e.surfacereponse3,NULL,screen,&e.positionreponse3);
SDL_Flip(screen);
}

void enig(SDL_Event event,enigme e,int *score,TTF_Font*police,TTF_Font*police2,SDL_Rect *pos_sprite,SDL_Rect *pos_screen,SDL_Surface *screen,SDL_Surface *surface_message,SDL_Surface *image,SDL_Rect*position,SDL_Surface *ANIME,SDL_Rect *position_message, int *p ,minimap *m)
{
  SDL_Color red={125,0,0};
  SDL_Color black={0,0,0};
  SDL_Color green={0,200,0};
int i,j,verif=0;
int detect_sound=0;

Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Chunk* sonbref;
sonbref = Mix_LoadWAV("mixkit-game-click-1114.wav");

          switch(event.type)
{
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
             {
           case SDLK_a:
               {
               if(verif==0){
                    if(e.posrepvrai!=1)
          {
                                surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                                (*pos_sprite).x=0;
                                (*pos_sprite).y=0;
                 /////animation
                     for(int i=0;i<2;i++)
               {
                             for(int j=0;j<9;j++)
                   {
                                SDL_Flip(screen);
                                animer(&e,&(*pos_sprite),j);///fct animer
                                SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                SDL_Flip(screen);
                                SDL_Delay(100);
                                SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                SDL_Flip(screen);
}
                               (*pos_sprite).x=0;
                               (*pos_sprite).y+=(*pos_sprite).h;
                  }
                         surface_message=TTF_RenderText_Blended(police2,"",red);
                         }

                        else if(e.posrepvrai==1)
                         {
                            verif=1;
                            surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
                      }  }
                        (*score)=(*score) + 50;
			m->ppl.x = 401;
			*p = 4;
                        SDL_Delay(5000);         
}break;


                case SDLK_b:
                 {
               if(verif==0){
                        if(e.posrepvrai!=2){
                                surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                                (*pos_sprite).x=0;
                                (*pos_sprite).y=0;
                        for(int i=0;i<2;i++){
                                for(int j=0;j<9;j++){
                                                SDL_Flip(screen);
                                                animer(&e,&(*pos_sprite),j);
                                                SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                                SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                                SDL_Flip(screen);
                                                SDL_Delay(100);
                                                SDL_Flip(screen);
                                    }
                                (*pos_sprite).x=0;
                                (*pos_sprite).y+=(*pos_sprite).h;
                              }
                              surface_message=TTF_RenderText_Blended(police2,"",red);
                                  }
                             else if(e.posrepvrai==2)
                               {
                              verif=1;
                             surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
           }
            }
                 }
               (*score)=(*score) + 50;
		m->ppl.x = 401;
		*p = 4;
              SDL_Delay(5000);
               break;

                case SDLK_c:
                    {
                  if(verif==0){
                    if(e.posrepvrai!=3){
                                surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                                (*pos_sprite).x=0;
                                (*pos_sprite).y=0;
               for(int i=0;i<2;i++){
                        for(int j=0;j<9;j++){
                                SDL_Flip(screen);
                                animer(&e,&(*pos_sprite),j);
                                SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                SDL_Flip(screen);
                                 SDL_Delay(100);
                                SDL_Flip(screen);}
                                 (*pos_sprite).x=0;
                                (*pos_sprite).y+=(*pos_sprite).h;
                               }
                               surface_message=TTF_RenderText_Blended(police2,"",red);
                              }
                             else if(e.posrepvrai==3)
                                    {
                                    verif=1;
                                  surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
                                 }}}
                            (*score)=(*score) + 50;
				m->ppl.x = 401;
			     *p = 4;
                           SDL_Delay(5000);
                          break;}

case SDL_MOUSEBUTTONDOWN:
              {
              switch(event.button.button)
                    {
case SDL_BUTTON_LEFT: 
{
                  if(event.button.x>260 && event.button.x<409 && event.button.y>375 && event.button.y<402)
{
                    if(verif==0){
                       if(e.posrepvrai!=1){
                                surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                                (*pos_sprite).x=0;
                                (*pos_sprite).y=0;
                        for(int i=0;i<2;i++){
                                  for(int j=0;j<9;j++){
                                                 SDL_Flip(screen);
                                                 animer(&e,&(*pos_sprite),j);
                                                 SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                                 SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                                 SDL_Flip(screen);
                                                 SDL_Delay(100);
                                                 SDL_Flip(screen);}
                              (*pos_sprite).x=0;
                              (*pos_sprite).y+=(*pos_sprite).h;}
               surface_message=TTF_RenderText_Blended(police2,"",red);
             SDL_Delay(5000);
             (*score)=(*score) - 50;
		m->ppl.x = 401;
		*p = 4;
                        }
                          else if(e.posrepvrai==1){
                             verif=1;
                       surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
                       SDL_Delay(5000);
                      (*score)=(*score) + 50;
			m->ppl.x = 401;
			*p = 4;
                       }
                    }}
                else if(event.button.x>560 && event.button.x<742 && event.button.y>365 && event.button.y<403)
                 {
                   if(verif==0){
                        if(e.posrepvrai!=2){
                                    verif=0;
                                 surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                                (*pos_sprite).x=0;
                                (*pos_sprite).y=0;
                             for(int i=0;i<2;i++){
                                  for(int j=0;j<9;j++){
                                                SDL_Flip(screen);
                                                animer(&e,&(*pos_sprite),j);
                                                SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                                SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                                SDL_Flip(screen);
                                                SDL_Delay(100);
                                                SDL_Flip(screen);}
                                (*pos_sprite).x=0;
                                (*pos_sprite).y+=(*pos_sprite).h;}
            surface_message=TTF_RenderText_Blended(police2,"",red);
            SDL_Delay(5000);
           (*score)=(*score) - 50;
		m->ppl.x = 401;
		*p = 4;
                                }
                                 else if(e.posrepvrai==2){
                               verif=1;
                             surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
                              SDL_Delay(5000);
                                (*score)=(*score) + 50;
				m->ppl.x = 401;
				*p = 4;
} 
}
}
               else if(event.button.x>860 && event.button.x<1013 && event.button.y>365 && event.button.y<399)
               {
                      if(verif==0){
                        if(e.posrepvrai!=3){
                                      verif=0;
                                 surface_message=TTF_RenderText_Blended(police2,"REPONSE FAUSSE!",red);
                               (*pos_sprite).x=0;
                               (*pos_sprite).y=0;
                      for(int i=0;i<2;i++){
                          for(int j=0;j<9;j++){
                                                SDL_Flip(screen);
                                                animer(&e,&(*pos_sprite),j);
                                                SDL_BlitSurface(ANIME,&(*pos_sprite),screen,&(*pos_screen));
                                                SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
                                                SDL_Flip(screen);
                                                SDL_Delay(100);
                                                SDL_Flip(screen);}
                                (*pos_sprite).x=0;
                                (*pos_sprite).y+=(*pos_sprite).h;}
            surface_message=TTF_RenderText_Blended(police2,"",red);
            SDL_Delay(5000);
            (*score)=(*score) - 50;
		m->ppl.x = 401;
		*p = 4;
                    }
			else if(e.posrepvrai==3){
verif=1;
   surface_message=TTF_RenderText_Blended(police2,"BRAVO!",green);
  SDL_Delay(5000);
  (*score)=(*score) + 50;
m->ppl.x = 401;
*p = 4;
       }
       }
        }}
       }
       }
     case SDL_MOUSEMOTION:
{
           if(event.motion.x>260 && event.motion.x<409 && event.motion.y>375 && event.motion.y<402)
{
               if(detect_sound==0){
               Mix_PlayChannel(-1,sonbref,0);
               detect_sound=1;}
               e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,red);
               e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,black);
               e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,black);
}

      else if(event.motion.x>560 && event.motion.x<742 && event.motion.y>365 && event.motion.y<403)
             {
            if(detect_sound==0){
            Mix_PlayChannel(-1,sonbref,0);
            detect_sound=1;}
            e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,black);
            e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,red);
            e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,black);
               }
          else if(event.motion.x>860 && event.motion.x<1013 && event.motion.y>365 && event.motion.y<399)
              {
if(detect_sound==0){
          Mix_PlayChannel(-1,sonbref,0);
           detect_sound=1;}
           e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,black);
           e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,black);
           e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,red);
         }
         else{
       detect_sound=0;
        e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,black);
        e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,black);
        e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,black);
}
}
SDL_Flip(screen);
SDL_BlitSurface(surface_message,NULL,screen,&(*position_message));
SDL_Flip(screen);
SDL_Delay(20);
}

}










