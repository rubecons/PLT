#include "Animal.h"

/// class AnimalFemelle - 
class AnimalFemelle : public Animal {
  // Attributes
private:
  bool isEnceinte;
  std::array<int,2> dateAccouplement;
  std::array<int, nbAncetres> geniteur;
  // Operations
public:
  animal ();
  void tuerAnimal ();
  void vendreAnimal ();
  void accoupler (bool isEnceinte, std::shared_ptr<Animal> male);
  std::array<Animal, nbEnfantsPortee> mettreBas (bool isEnceinte, std::array<int,2> dateAccouplement, int dureeGestation);
};

