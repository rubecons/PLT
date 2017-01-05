// Generated by dia2code
#ifndef SOLUTION__SERVICESMANAGER__H
#define SOLUTION__SERVICESMANAGER__H


namespace solution {
  class AbstractService;
}

#include "AbstractService.h"
#include "HttpStatus.h"

namespace solution {

  /// class ServicesManager - 
  class ServicesManager {
    // Associations
    // Attributes
  protected:
    vector<unique_ptr<AbstractService> > services;
    // Operations
  public:
    void registerService (unique_ptr<AbstractService> service);
    AbstractService* findService (const string& url) const;
    HttpStatus queryService (string& out, const string& in, const string& url, const string& method);
  };

};

#endif
