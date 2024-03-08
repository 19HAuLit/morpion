#include <iostream>

#include "morpion/game.h"

int menu();

using namespace std;

int main() {
    bool marche = true;
    do {
        int choix = menu();
        switch (choix) {
            case 1:
                playerVsPlayer();
                break;
            case 2:
                playerVsMonteCarlo();
                break;
            case 3:
                playerVsMinimax();
                break;
            default:
                marche = false;
                break;
        }
    } while (marche);
    return 0;
}

int menu() {
    string input;
    bool correctInput = false;
    int choix = 0;
    do {
        printf("==========Choix du mode de jeu=========\n       1 - Joueur contre Joueur\n       2 - Joueur contre Monte Carlo\n       3 - Joueur contre Minimax\n       0 - Quitter le programme\n=======================================\n\nVotre choix: \n");
        cin >> input;
        cin.ignore();
        if (input == "1") {
            choix = 1;
            correctInput = true;
        } else if (input == "2") {
            choix = 2;
            correctInput = true;
        } else if (input == "3") {
            choix = 3;
            correctInput = true;
        } else if (input == "0") {
            choix = 0;
            correctInput = true;
        }
    } while (not correctInput);
    return choix;
}
