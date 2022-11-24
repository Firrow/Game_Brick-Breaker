#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL.h>

#include "brick_breaker_plateform.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("Fenêtre TP 6 Prog C++",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       ReglageJeu::LARGEUR_FENETRE, ReglageJeu::HAUTEUR_FENETRE, SDL_WINDOW_RESIZABLE);
    
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
                                                SDL_RENDERER_PRESENTVSYNC);
    
    PlateformeCasseBrique jeu(renderer);
    while (!jeu.gameOver()) {
        jeu.tick();
    }
    return EXIT_SUCCESS;
}

//ceci est un test

