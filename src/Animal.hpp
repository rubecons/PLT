/// class Animal - 
class Animal {
  // Attributes
private:
  int const IDanimal;
  std::shared_ptr<Elevage> IDelevage;
  string nomAnimal;
  bool sexe;
  /// c'est la date de naissance, comme ca on calcule l'age, au lieu d'incr√©menter √
  std::array<int, 2> dateNaissance;
  int poids;
  std::array<int, nbAncetres> ancetres;
  // Operations
public:
  animal ();
  void supprimerAnimal ();
  void tuerAnimal ();
  void vendreAnimal ();
  int getIDAnimal ();
  int getIDElevage ();
  void setIDElevage (int id);
  string getNomAnimal ();
  void setNomAnimal (string nom);
  bool getSexe ();
  void setSexe (bool sexe);
  std::array<int, 2> getDateNaissance ();
  void setDateNaissance (int anneeNaissance, int moisNaissance);
  int getPoids ();
  void setPoids (int poids);
  std::array<int, nbAncetres> getAncetres ();
  void setAncetres (std::shared_ptr<std::array<int, nbAncetres>> ancetresPere, std::shared_ptr<std::array<int, nbAncetres>> ancetresMere);
};

