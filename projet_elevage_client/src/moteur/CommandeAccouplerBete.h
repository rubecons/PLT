// Generated by dia2code
#ifndef MOTEUR__COMMANDEACCOUPLERBETE__H
#define MOTEUR__COMMANDEACCOUPLERBETE__H

#include <memory>

namespace Etats {
  class Animal;
};
namespace moteur {
  class Commande;
}

#include "Etats/Animal.h"
#include "Commande.h"

namespace moteur {

  /// class CommandeAccouplerBete - 
  class CommandeAccouplerBete : public moteur::Commande {
    // Attributes
  protected:
    std::shared_ptr<Etats::Animal> male;
    std::shared_ptr<Etats::Animal> femelle;
    // Operations
  public:
    CommandeAccouplerBete ();
    CommandeAccouplerBete (std::shared_ptr<Etats::Animal> mal, std::shared_ptr<Etats::Animal> femel);
    ~CommandeAccouplerBete ();
    void effectuerCommande ();
  };

};

#endif
