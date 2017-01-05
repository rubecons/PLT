// Generated by dia2code
#ifndef ELEVAGE__HPP
#define ELEVAGE__HPP

#include "librairiesQt.hpp"
#include "Race.hpp"
#include "Animal.hpp"
/// class Elevage - 
class Elevage {
  // Associations
//  Race regroupe;
//  Animal* compose;
  // Attributes
private:
  int idElevage;
  std::shared_ptr<Race> raceElevage;
  std::vector<std::shared_ptr<Animal>> animauxElevage;
  // Operations
public:
  Elevage (int identifiant, std::shared_ptr<Race> race);
  ~Elevage ();
  void rajouterAnimalListe ();
  void supprimerAnimalListe ();
  std::shared_ptr<Race> getRace ();
  void setRace (std::shared_ptr<Race>);
};

#endif
