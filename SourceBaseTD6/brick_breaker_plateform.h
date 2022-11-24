#ifndef CASSE_BRIQUE_HEADER
#define CASSE_BRIQUE_HEADER
#include <string>
#include <vector>
#include <list>
#include <SDL.h>

// fonction permettant de remplir un cercle
void fillCircle(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);

struct ReglageJeu { 
    static const int LARGEUR_FENETRE = 1020;
    static const int HAUTEUR_FENETRE = 640;
    static const int V_PLATEAU = 4;
    static const int EPAISSEUR_PLATEAU = 20;
    static const int LARGEUR_PLATEAU = 90;
    
    static const int LARGEUR_BALLE = 10;
    
    // Briques
    static const int LONGUEUR_BRIQUE = 60;
    static const int EPAISSEUR_BRIQUE = 20;
    static const int ESPACE_BRIQUE = 20;
    
    static constexpr  SDL_Color COL_BG {240, 200, 200, 255};
};


class PlateformeCasseBrique {
    
    struct Balle{
        double x;
        double y;
        double vDirX;
        double vDirY;
        bool estPerdue = false;
        SDL_Color c {250,20,20, 255};
        void render(SDL_Renderer *r){
            fillCircle(r, x, y, ReglageJeu::LARGEUR_BALLE, c);
        };
        static bool ballePerdue (const Balle& b) { return (b.estPerdue); };
        
    };
    
    struct PlateauJeu{
        int x;
        int y;
        int largeur = ReglageJeu::LARGEUR_PLATEAU;
        int epaisseur = ReglageJeu::EPAISSEUR_PLATEAU;
        double vitesse = 7.0;
        
        void render(SDL_Renderer *r){
            SDL_SetRenderDrawColor(r, 240, 100, 80, 255);
            SDL_Rect rec = { x, y, largeur, epaisseur };
            SDL_RenderFillRect(r, &rec);
        };
        bool collision(const Balle &b ) const {
            
        };
    };
    
    struct Brique {
        int x;
        int y;
        // Paramètre à utiliser pour rendre plus solide les briques bonus (et à utiliser pour faire disparaitre les briques touchées).
        int solide=1;
        int hauteur = ReglageJeu::EPAISSEUR_BRIQUE;
        int largeur = ReglageJeu::LONGUEUR_BRIQUE;
        void render(SDL_Renderer *r){
        };
        bool collision(const Balle &b ) const {
        };
        
    };
    
    // Stocke toutes les briques du jeu
    std::vector<Brique> monVectBriques;
    
    // Représente la liste des balles présentent dans le jeu
    std::list<Balle> monVectBalles;
    
    PlateauJeu monPlateau;
    SDL_Renderer *monRenderer;
    
    // attribut utilisé pour détecter quand le joueur arrête en fermant la fenêtre
    // bien utile pour la question 2.3
    bool abandon = false;
    
public:
    PlateformeCasseBrique(SDL_Renderer *renderer);
    bool tick();
    void miseAjourPosPlateau(int direction);
    void initJoueurBalle();
    void miseAjourVectVitesse(Balle &uneBalle);
    
    bool gameOver();
    
};

#endif
