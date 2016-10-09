/// class Elevage - 
class Elevage {
  // Attributes
private:
  int idElevage;
  std::shared_ptr<Race> raceElevage;
  std::vector<std::shared_ptr<Animal>> animauxElevage;
  // Operations
public:
  elevage (int identifiant, std::shared_ptr<Race> race);
  supprimmerElevage ();
  void rajouterAnimalListe ();
  void supprimerAnimalListe ();
  std::shared_ptr getRace ();
  void setRace (std::shared_ptr race);
};

