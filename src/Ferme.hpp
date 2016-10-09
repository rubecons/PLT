#include "Race.h"
#include "Elevage.h"

/// class Ferme - 
class Ferme {
  // Associations
  Race* unnamed;
  Elevage* unnamed;
  // Attributes
private:
  std::vector <std::shared_ptr<Elevage>> mesElevages;
  std::vector<std::shared_ptr<Race>> mesRaces;
  double budget;
  double argentEmprunte;
  // Operations
public:
  ferme ();
  void supprimerFerme ();
  void ajouterElevageListe (std::shared_ptr<Cheptel> elevage);
  void supprimerElevageListe (std::shared_ptr<Elevage> elevage);
  void ajouterRaceListe (std::shared_ptr<Race> race);
  void supprimerRaceListe (std::shared_ptr<Race> race);
  double emprunt (double budget, double sommeEmprunt, double argentEmprunte);
  double remboursementEmprunt (double budget, double sommeRemboursee, double argentEmprunte);
  double plusbudget (double budget, double argentAjoute);
  double moinsbudget (double budget, double argentdepense);
};

