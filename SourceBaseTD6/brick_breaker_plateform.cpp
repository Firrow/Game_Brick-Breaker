#include "brick_breaker_plateform.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include <random>



PlateformeCasseBrique::PlateformeCasseBrique(SDL_Renderer *renderer): monRenderer(renderer){
    initJoueurBalle();
    monRenderer = renderer;
    
    
    
}


void
PlateformeCasseBrique::initJoueurBalle(){
    monPlateau.x = ReglageJeu::LARGEUR_FENETRE/2.0;
    monPlateau.y = ReglageJeu::HAUTEUR_FENETRE - ReglageJeu::HAUTEUR_FENETRE/8.0 ;
    /*Balle b;
    b.x = ReglageJeu::LARGEUR_FENETRE/2.0;
    b.y = ReglageJeu::HAUTEUR_FENETRE/2.0;
    b.vDirX = 5.0;
    b.vDirY = -5.0;
    monVectBalles.push_back(b);*/

    for (int i = 0; i < 10; i++) {
        Balle b;
        b.x = rand() % ReglageJeu::LARGEUR_FENETRE / 2.0;
        b.y = rand() % ReglageJeu::HAUTEUR_FENETRE / 2.0;
        b.vDirX = rand() % 10;
        b.vDirY = rand() % 10;
        //mettre couleur aléatoire
        b.c = {unsigned char(rand()%255), unsigned char(rand() % 255), unsigned char(rand() % 255), 255};
        monVectBalles.push_back(b);
    }
}



void PlateformeCasseBrique::miseAjourPosPlateau(){
    
}



void
PlateformeCasseBrique::miseAjourVectVitesse(Balle &uneBalle){
    if (uneBalle.x >=  ReglageJeu::LARGEUR_FENETRE-1 || uneBalle.x <  0){
        uneBalle.vDirX *= -1;
    }
    if (uneBalle.y >=  ReglageJeu::HAUTEUR_FENETRE-1 || uneBalle.y <  0){
        uneBalle.vDirY *= -1;
    }
}



bool
PlateformeCasseBrique::tick(){
    SDL_SetRenderDrawColor(monRenderer, ReglageJeu::COL_BG.r,
                           ReglageJeu::COL_BG.g,
                           ReglageJeu::COL_BG.b,
                           255);
    SDL_RenderClear(monRenderer);
    SDL_Event event;
    // Gestion du clavier
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // Réponse à la question 1.3 ici:
            SDL_Quit();
        }
        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT:
                    break;
                case SDLK_RIGHT:
                    break;
            }
        }
        //If a key was released
        else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
        {
            //Adjust the velocity
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT:
                    break;
                case SDLK_RIGHT:
                    break;
            }
        }
    }
    
    // Mise à jour balle:
    // Suppression des doublons
    monVectBalles.remove_if(Balle::ballePerdue);
    for(auto &b: monVectBalles){
        b.render(monRenderer);
        b.x = ((int) (b.x+b.vDirX));
        b.y = ((int) (b.y+b.vDirY));
        miseAjourVectVitesse(b);
    }
    // Affichage Joueur
    
    
    if (monVectBalles.size()==0){
        initJoueurBalle();
    }
    SDL_RenderPresent(monRenderer);
    return  true;
}



bool 
PlateformeCasseBrique::gameOver(){
    return monVectBalles.size() <= 0 || abandon;
}



void fillCircle(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}


