#include"Partie.hpp"

Partie::Partie(Joueur& joueur1, Joueur& joueur2): grille{{0,0,0},{0,0,0},{0,0,0}},nbcoups{0}{
    this->setJoueurs(&joueur1, &joueur2);

}
//setters
void Partie::setNbcoups(const unsigned int nbcoups){
    this->nbcoups = nbcoups;
}
void Partie::setJoueurs(Joueur* j1, Joueur* j2){
    this->joueurs.push_back(j1);
    this->joueurs.push_back(j2);
}
bool Partie::setGrille(const int value_player, const int i, const int j){

    if ((value_player == 0 || value_player == 1) && (i < 3)&& (j < 3) && (i>= 0) && (j >= 0)) {
		if (this->getGrille()[j][i] == 0) {
            this->grille[i][j] = value_player + 1; 
            return true;
            }
    }
    return false;

}
//getters
std::vector<Joueur*> &Partie::getJoueurs(){
    return this->joueurs;
}
int Partie::getNbcoups(){
    return this->nbcoups;
}

std::vector<std::vector<int>> &Partie::getGrille(){
    return this->grille;
}
void Partie::afficher_grille(){
    for(std::vector<int>& vector : this->getGrille()){
        for(int i : vector){
            std::cout<< i << " ";
        }
        std::cout<< std::endl;
    }

}
bool Partie::check_gagnant(){
    grille = this->getGrille();
    for(int i = 0; i< 3; i++){
        // verifier les lignes 
        if ( (grille[i][0]== grille[i][1]) && (grille[i][0]== grille[i][2]) && grille[i][0] > 0) {return true;}
        // verifier les colonnes 
        if( (grille[0][i]== grille[1][i]) && (grille[0][i]== grille[2][i]) && grille[0][i]> 0){ return true;}
        // verifier les diagonales
        if( (grille[0][0]== grille[1][1]) && (grille[0][0]== grille[2][2]) && grille[0][0] >0){return true;}
        if  ((grille[0][2] == grille[1][1] && ( grille[0][2]== grille[2][0]) && grille[0][2]>0 )){return true;}
    }
    return false;
    
}
void Partie::parite_en_cours(){

    bool gangeur = false;
    int i = -1;
    int j = -1;
    int num_joueur = -1;
    bool coups_joue = false;
    std::cout << "Partie entre "<< this->getJoueurs()[0]->getId( ) <<" et "<<this->getJoueurs()[1]->getId() << std::endl;
    
    while (gangeur== false &&  this->getNbcoups() < 9)// la partie continue tant qu'on a pas un gagnat ou 9 nbcoups = 9 veut dire match nul
    {
        num_joueur = (num_joueur +1)%2; // switch between players
        std::cout<< "Entrez une case i j"<< std::endl;
        this->afficher_grille();
        std::cin >>i>>j;
        coups_joue = this->setGrille(num_joueur, i,j);
        //Tant que le joueur ne joue pas sur une case autorisée, on lui demande de rejouer
		
        //met à jour le nombre de coups
        this->setNbcoups(this->getNbcoups() +1);
        gangeur = this->check_gagnant();
        
        
    }
    this->afficher_grille();
    if(gangeur){
            this->getJoueurs()[num_joueur]->UpdateScore(this->getNbcoups());
            std::cout << "---> Bravo Joueur "<<this->getJoueurs()[num_joueur]->getId()<< ", vous avez gagne! <---"<<std::endl<<std::endl;
            std::cout << *(this->getJoueurs()[num_joueur]);
            num_joueur = (num_joueur +1)%2;
            std::cout << *(this->getJoueurs()[num_joueur]);
        }
    else {
        std::cout << "Match nul!"<< std::endl;
    }
    

}
std::ostream& operator<<(std::ostream& os, Partie& p){
    os << "Partie entre "<< *p.getJoueurs()[0] <<" et "<< *p.getJoueurs()[1] << std::endl;
    return os;
}