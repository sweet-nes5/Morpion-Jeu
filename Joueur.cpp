#include "Joueur.hpp"

Joueur::Joueur(const std::string id): identifiant{id}, score_tournoi{0}, score_total{0}{}

void Joueur::UpdateScore(const int nbcoups){
    float score = 9/((float)nbcoups + (float)(nbcoups%2));
    this->setScore_tournoi(this->getScore_tournoi()+score);
    this->setScore_total(this->getScore_total()+score);

}
//getters
float Joueur::getScore_tournoi() const{
    return this->score_tournoi;
}
float Joueur::getScore_total() const{
    return this->score_total;
}
std::string Joueur::getId()const{
    return this->identifiant;
}
//setters
void Joueur::setScore_tournoi(float s) {
    this->score_tournoi = s;
}
void Joueur::setScore_total(float s){
    this->score_total = s;
}
void Joueur::setId(std::string id){
    this->identifiant = id;
}
std::ostream& operator<<(std::ostream& os, const Joueur& joueur)
{
    os << "Joueur: " << joueur.getId() << " score du tournoi: "<< joueur.getScore_tournoi() << ", score total "<< joueur.getScore_total()<<std::endl;
    return os;
    
}