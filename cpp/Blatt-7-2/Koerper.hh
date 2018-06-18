#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:
//   Zylindermantel(double nr, double nl);
  double M;
  Vektor punkt();
  std::string name() {
      return "Koerper";
  }
private:
  double r_,l_;
};

#endif