#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<string>
class Joueur{
    private:
    std::string  identifiant;
    float score_tournoi;
    float score_total;
    public:
    Joueur(std::string id);//constructeur de copie
    std::string getId() const; // assurer que l'etat de l'objet ne change pas
    void setId(std::string id);
    float getScore_tournoi() const;
    float getScore_total() const;
    void setScore_tournoi(float score);
    void setScore_total(float score);
    void UpdateScore(int nbcoups);


};
// surchage de l'operateur <<
std::ostream& operator<< (std::ostream &os,const Joueur &j);

#endif