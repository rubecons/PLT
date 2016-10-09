/// class Race - 
class Race {
  // Attributes
public:
  int dureeGestation;
private:
  int const idRace;
  string nomRace;
  std::array<int, 2> esperanceDeVie;
  std::array<int,2> poidsMoyenAdulte;
  std::array<int, 2> ageMoyenMaturite;
  std::array<double, 2> prixNourritureVeterinaire;
  int nbEnfantsPortee;
  double gainVente_enfant;
  /// en euros
  double gainVente_adulte;
  int nbGenerations;
  /// totalise le nombre d'ancêtres à stocker dans le patrimoine génétique, à pa
  int nbAncetres;
  // Operations
public:
  race ();
  supprimmerRace ();
  int getIDRace ();
  string getNomRace ();
  void setNomRace (string nom);
  int getEsperanceDeVie (bool sexe);
  void setEsperanceDeVie (bool sexe, int duree_esperancedevie);
  int getPoidsMoyenAdulte (bool sexe);
  void setPoidsMoyenAdulte (bool sexe, int poids);
  int getAgeMoyenMaturite (bool sexe);
  void setAgeMoyenMaturite (bool sexe, int age);
  double getPrixNourritureVeterinaire (bool sexe);
  void setPrixNourritureVeterinaire (bool sexe, double prix);
  int getDureeGestation ();
  void setDureeGestation (int duree);
  int getNbEnfantsPortee ();
  void setNbEnfantsPortee (int nbEnfantsPortee);
  double getGainVente_enfant ();
  void setGainVente_enfant (double prix);
  double getGainVente_adulte ();
  void setGainVente_adulte (double prix);
  int getNbGenerations ();
  void setNbGenerations (int nbGen);
  int getNbAncetres ();
  void setNbAncetres (int nbGenerations);
};

