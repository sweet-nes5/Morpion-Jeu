#ifndef TOURNOI
#define TOURNOI

#include "Partie.hpp"

class Tournoi
{
private:
    bool inscri_ouvertes;
    std::vector<Joueur*> joueurs;
public:
    Tournoi();
    virtual ~Tournoi(); // destructeur
    void inscriptions(Joueur& joueurs);
    void  debut_tournoi();
    void vide_participants();
    // Setters 
    void setInscr_ouvertes(const bool inscri_ouvertes);
    void setJoueurs(Joueur* nvJoueur);
    // Getters
    bool getInscr_ouvertes();
    std::vector<Joueur*> &getJoueurs();
};
// surchage de l'operateur <<
std::ostream& operator<<(std::ostream& out, Tournoi& tournoi);

#endif