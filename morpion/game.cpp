#include <iostream>

#include "game.h"
#include "Plateau.h"

void affichageFinPartie(int status);

void playerVsPlayer() {
    printf("Lancement d'une partie joueur contre joueur ...\n");
    Plateau partie{};
    partie.createGame();
    int winStatus;
    do {
        partie.affichage();
        int choix;
        std::cin >> choix;
        std::cin.ignore();
        partie.play(choix);
        winStatus = partie.checkWin();
    } while (not partie.partieFinie);
    partie.affichage();
    affichageFinPartie(winStatus);
}

void playerVsMonteCarlo() {}

void playerVsMinimax() {}

void affichageFinPartie(int status) {
    switch (status) {
        case 0:
            printf("Égalité !\n");
            break;
        case 1:
            printf("Le premier joueur a gagné !\n");
            break;
        case -1:
            printf("Le second joueur a gagné !\n");
            break;
        default:
            printf("Une erreur est survenue !\n");
            break;
    }
}