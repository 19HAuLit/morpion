//
// Created by lolo4 on 08/03/2024.
//

#ifndef MORPION_PLATEAU_H
#define MORPION_PLATEAU_H


class Plateau {
public:
    int grille[3][3];
    bool playerRound;

    bool play(int emplacement);

    bool partieFinie = false;

    int checkWin();

    void createGame();

    void affichage();
};


#endif //MORPION_PLATEAU_H
