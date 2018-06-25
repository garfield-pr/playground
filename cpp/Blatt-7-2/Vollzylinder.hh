#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"
#include "Koerper.hh"
class Vollzylinder : public Koerper {
public:
  Vollzylinder(double nr, double nl, double M);

  Vektor punkt();
private:
  double r_,l_;
};

#endif
