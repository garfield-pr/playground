#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"
#include "Koerper.hh"
class Vollzylinder : public Koerper {
public:
  Vollzylinder(double nr, double nl, double M);

  Vektor punkt();
  double M = 1; //Masse des Zylindermantels

private:
  double r_,l_;
};

#endif
