/**
* @file ES.c
* @brief ennemi
* @author Generation Z
* @version 0.1
* @date 18 Avril 2022
*
* ennemi code
*
*/
/**
* @file ES.c
*/
#include "ES.h"
#include "bounding_box.h"
/**
* @brief initialiser le ennemi.
* @param p l'ennemi
* @return Nothing
*/
void init_es(ES *p)//initialisation de tout les attributs
{
(*p).d = 0;
(*p).pos.x = 400+rand()%200;
(*p).pos.y = 400;
(*p).pos.x = 300+rand()%200;//200
(*p).pos.y = 360;
(*p).sprite.x=0;
(*p).sprite.y=0;
(*p).sprite_n = 0;
(*p).image = IMG_Load("spritesheetwolf.png");
(*p).image = IMG_Load("wolfwolf-sans_attack.png");
(*p).pos.w = (*p).image->w/3; 
(*p).pos.h = (*p).image->h/4; //2
(*p).pos.h = (*p).image->h/2;
(*p).sprite.w = (*p).image->w/3;
(*p).sprite.h = (*p).image->h/4; //2
(*p).sprite.h = (*p).image->h/2;
(*p).sprite_count = 3;
(*p).state=WAITING;
}
/**
* @brief afficher l'ennemi.
SDL_BlitSurface(p.image,&p.sprite,screen,&p.pos);
*/
void animer_es(ES *p)//change l image à afficher
{
(*p).sprite_n++;  if((*p).sprite_n==(*p).sprite_count) (*p).sprite_n=0;
(*p).sprite_n++;
 SDL_Delay(300);
 if((*p).sprite_n==(*p).sprite_count) (*p).sprite_n=0;
(*p).sprite.x=(*p).sprite_n*(*p).sprite.w;
(*p).sprite.y=(*p).d*(*p).sprite.h;
}
void animer_es(ES *p)//change l image à afficher
void move_es(ES *p)
{
if((*p).sprite_n==(*p).sprite_count-1)(*p).d=rand()%2;
if ((*p).d==0) (*p).pos.x+=10; //5
if ((*p).d==1) (*p).pos.x+=10; //5
else (*p).pos.x-=10; 
if((*p).pos.x<700) (*p).d=0;
if((*p).pos.x>800) (*p).d=1;      //50
if((*p).pos.x<500) (*p).d=1; //700
if((*p).pos.x>700) (*p).d=0;      //800
}
void updateEnnemi(ES *p,SDL_Rect posHero)
{ int c;
c=collision(p->pos,posHero);
if(posHero.x<200) //>900
{
//animer_es(p);
//move_es(p); 
 void animer_es_follow(ES *p)//change l image à afficher
 {
 (*p).d=0;
 //(*p).sprite_n++;
 SDL_Delay(300);
 //if((*p).sprite_n==(*p).sprite_count) (*p).sprite_n=0;
 (*p).sprite.x=(*p).sprite.w;
 (*p).sprite.y=(*p).sprite.h;
 }
 //void move_es_follow(ES *p)
 //{

 //if((*p).sprite_n==(*p).sprite_count-1)(*p).d=rand()%2;
 //if ((*p).d==0) (*p).pos.x+=10; //5
 //else (*p).pos.x-=10; 
 //if((*p).pos.x<500) (*p).d=0;
 //if((*p).pos.x>700) (*p).d=1;      //50
 //}
}
else if((posHero.x>=200) && (posHero.x<400))//900 //700
{
//(*p).image = IMG_Load("wolfwolf-sans_attack.png");
 //void animer_es_follow(ES *p)//change l image à afficher
 //{
 //(*p).d=0;
 //(*p).sprite_n++;
 //SDL_Delay(300);
 //if((*p).sprite_n==(*p).sprite_count) (*p).sprite_n=0;
 //(*p).sprite.x=(*p).sprite_n*(*p).sprite.w;
 //(*p).sprite.y=(*p).d*(*p).sprite.h;
 //}
 //void move_es_follow(ES *p)
// {
//
// if((*p).sprite_n==(*p).sprite_count-1)(*p).d=rand()%2;
// if ((*p).d==0) (*p).pos.x+=10; //5
 //else (*p).pos.x-=10; 
 //if((*p).pos.x<500) (*p).d=0;
 //if((*p).pos.x>700) (*p).d=1;      //50
 //}
//}
animer_es(p);
move_es(p); 
}
 if((c==1) &&  (posHero.x>=400))              //(posHero.x>=400) 
{
(*p).image = IMG_Load("wolfwolf-attack.png");
animer_es(p);
move_es(p); 
}
else if (posHero.x>=700)
{
(*p).image = IMG_Load("wolfwolf-sans_attack.png");
 void animer_es_follow(ES *p)//change l image à afficher
 {
 (*p).d=0;
 //(*p).sprite_n++;
 SDL_Delay(300);
 //if((*p).sprite_n==(*p).sprite_count) (*p).sprite_n=0;
 (*p).sprite.x=(*p).sprite.w;
 (*p).sprite.y=(*p).sprite.h;
 }
}
}






