#include<iostream>
#include "Tournoi.hpp"
int main(){
    Tournoi tournoi;
    Joueur j1{"cerise"}, j2{"pomme"}, j3{"fraise"};
    tournoi.inscriptions(j1);
    tournoi.inscriptions(j2);
    tournoi.inscriptions(j3);
    tournoi.debut_tournoi();
    tournoi.vide_participants();
    std::cout << std::endl << "Nouveau Tournoi" << std::endl;
    Joueur j4{"mangue"}, j5{"acai"};
    tournoi.inscriptions(j1);
    tournoi.inscriptions(j3);
    tournoi.inscriptions(j4);
    tournoi.inscriptions(j5);
    tournoi.debut_tournoi();
    
    return 0;
}