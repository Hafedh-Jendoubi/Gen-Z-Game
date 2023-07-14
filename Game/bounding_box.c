#include "bounding_box.h"
/**
* @file bounding_box.c
* @brief collision
* @author Generation Z
* @version 0.1
* @date 18 Avril 2022
*
* collision code
*
*/
/**

* @file bounding_box.c
*/
/**
* @brief tester si les deux entites se rencontrent .
* @param x1 entite1
* @param x2 entite2
* @return entier
*/

int in_bounds(SDL_Rect x1,SDL_Rect x2)//testi ken x1 f west x2
{
return(x1.x>=x2.x)&&(x1.x<=x2.x+x2.w)&&((x1.y>=x2.y)&&(x1.y<=x2.y+x2.h)||((x1.y<=x2.y)&&(x1.y+x2.h>=x2.y)));
}
/**
* @brief tester si il y a une collision .
* @param x1 entite1
* @param x2 entite2
* @return entier
*/
int collision(SDL_Rect x1,SDL_Rect x2)//testi ken bin x1 w x2 fama collision wale
{
return in_bounds(x1,x2)||in_bounds(x2,x1);
}
