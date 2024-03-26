#include "Tournoi.hpp"

Tournoi::Tournoi() : inscri_ouvertes {true}{}

Tournoi::~Tournoi(){
    // detruire le vecteur
    this->getJoueurs().clear();
    std::vector<Joueur*>().swap(this->joueurs);
}
void Tournoi::inscriptions(Joueur& joueur){
    if(this->getInscr_ouvertes()){
        this->setJoueurs(&joueur);
    }
}
void Tournoi::vide_participants(){this->getJoueurs().clear();}
//getters
bool Tournoi::getInscr_ouvertes(){return this->inscri_ouvertes;}
std::vector<Joueur*>& Tournoi::getJoueurs(){return this->joueurs;}
//setters
void Tournoi::setInscr_ouvertes(const bool inscri_ouvertes){
    this->inscri_ouvertes = inscri_ouvertes;

}
void Tournoi::setJoueurs(Joueur* nvj){
    for(Joueur* joueur : this->getJoueurs()){
        if(joueur->getId()== nvj->getId()){
            return;
        }
    }
    this->getJoueurs().push_back(nvj);
}
void Tournoi::debut_tournoi(){
    this->setInscr_ouvertes(false);
    // lancer des parties entre chaque joueur
    int nb_joueurs = this->getJoueurs().size();

    for(int i = 0; i< nb_joueurs -1; i++){
        for(int j = i+1; j<nb_joueurs ; j++ ){
            Partie p{*this->getJoueurs()[i],  *this->getJoueurs()[j]};
            p.parite_en_cours();
    }
    }
    // trouver les gagnant et les afficher 
    float score_max = 0;
    int num_gagnant = -1;
    std::vector<int> gagnants;
    for(Joueur* joueur : this->getJoueurs()){
        num_gagnant = num_gagnant +1;
        if(joueur->getScore_tournoi()> score_max){
            score_max= joueur ->getScore_tournoi();
            gagnants.clear();
            gagnants.push_back(num_gagnant);
        }
        else if (joueur->getScore_tournoi() ==score_max) {  
            gagnants.push_back(num_gagnant);
    }

}
std::cout << std::endl << "Le(s) gagnant(s) du turonoi est :"<< std::endl;
for(int id: gagnants ){
    std::cout << *this->getJoueurs()[id];}
 // afficher le score de tous les joueurs, tournoi fini
 std::cout << std::endl << "Score final des joueurs sont:" << std::endl;
 for(Joueur* joueur : this->getJoueurs()){
    std::cout<< *joueur;
    joueur->setScore_tournoi(0);
 }
 this->setInscr_ouvertes(true);

}
// surchage de l'operateur
std::ostream& operator<<(std::ostream& out, Tournoi& tournoi){
    out<<"Liste des joueurs participant au tournoi:"<< std::endl;
    for (Joueur* joueur : tournoi.getJoueurs()){
        out<< *joueur;
    }
    return out;
}