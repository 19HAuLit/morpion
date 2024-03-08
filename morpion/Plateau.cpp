#include <iostream>

#include "Plateau.h"

using namespace std;

void Plateau::createGame() {
    // Initialisation des valeurs de la grille de jeu.
    for (auto &i: grille) {
        for (int &j: i) {
            j = 0;
        }
    }
    // Initialisation des autres variables.
    playerRound = true;
}

void Plateau::affichage() {
    string ligne = "-------------\n";
    cout << ligne;
    for (int i(0); i < 3; i++) {
        for (int j(0); j < 3; j++) {
            if (grille[i][j] == 1) {
                printf("| x ");
            } else if (grille[i][j] == -1) {
                printf("| o ");
            } else cout << "| " << i * 3 + j << " ";
        }
        cout << "|\n";
        cout << ligne;
    }
}

bool Plateau::play(int emplacement) {
    // Recherche de l'emplacement dans la grille
    int i = emplacement % 3;
    int j = emplacement - 3 * i;
    // Verification d'une case valide
    if (emplacement < 0 or emplacement > 8) return false;
    if (grille[i][j] != 0) return false;
    // Modification de la grille
    if (playerRound) {
        grille[i][j] = 1;
        playerRound = false;
    } else {
        grille[i][j] = -1;
        playerRound = true;
    }
    return true;
}

int Plateau::checkWin() {
    /*
     Renvoie 0 en cas d'égalité
     Renvoie 1 si le premier joueur a gagné
     Renvoie -1 si le second joueur a gagné
     Renvoie 2 si la partie n'est pas terminée
    */
    // Vérification des lignes
    for (auto & i : grille){
        int joueurLigne = i[0];
        bool ligneJoueur = true;
        for (int j(1); j < 3; j++){
            if (i[j] != joueurLigne) {
                ligneJoueur = false;
                break;
            }
        }
        if (joueurLigne != 0 and ligneJoueur) {
            partieFinie = true;
            return joueurLigne;
        }
    }
    // Vérification des colones
    for (int j(0); j < 3; j++){
        int joueurLigne = grille[0][j];
        bool cologneJoueur = true;
        for (int i(1); i < 3; i++){
            if (grille[i][j] != joueurLigne) {
                cologneJoueur = false;
                break;
            }
        }
        if (joueurLigne != 0 and cologneJoueur) {
            partieFinie = true;
            return joueurLigne;
        }
    }
    // Vérification diagonale
    if (grille[0][0] != 0 and grille[0][0] == grille[1][1] and grille[0][0] == grille[2][2]) {
        partieFinie = true;
        return grille[0][0];
    }
    // Verification si le plateau est remplie
    for (auto & i : grille){
        for (int j : i){
            if (j == 0) {
                return 2;
            }
        }
    }
    partieFinie = true;
    return 0;
}
