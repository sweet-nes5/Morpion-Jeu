#ifndef PARTIE_H
#define PARTIE_H
#include<vector>
#include<iostream>
#include"Joueur.hpp"
class Partie
{
private:
    std::vector<std::vector<int>> grille; // La grille de jeu
    unsigned int nbcoups; // Le nombre de coups joués dans cette partie
    std::vector<Joueur* > joueurs; // Les joueurs qui participent à la partie
    
public:
    Partie(Joueur& joueur1, Joueur& joueur2);
    //virtual ~Partie();  /* Destructeur */
    void parite_en_cours();
    void afficher_grille();
    bool check_gagnant();
    //getters
    int getNbcoups();
    std::vector<std::vector<int>> &getGrille();
    std::vector<Joueur*> &getJoueurs();
    //setters
    void setJoueurs(Joueur* joueur1, Joueur* joueur2);
    void setNbcoups(const  unsigned int nbcoups);
    bool setGrille(const int value_player, const int i, const int j);
   
    
    
};

std::ostream& operator<<(std::ostream& os, Partie& p);

#endif