#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:
//   Zylindermantel(double nr, double nl);
  double M;
  virtual Vektor punkt() = 0;
  std::string Name;
};


#endif