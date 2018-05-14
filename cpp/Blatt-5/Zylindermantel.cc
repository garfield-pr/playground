#include "Zylindermantel.hh"

#include <cstdlib>
#include <cmath>

Zylindermantel::Zylindermantel(double nr, double nl)  
{
  r_ = nr;
  l_ = nl;
}

Vektor Zylindermantel::punkt() 
{
  double R   = r_;
  double phi =  2*M_PI * rand()/(double)RAND_MAX;
  double z   = l_*(rand()/(double)RAND_MAX -0.5);

  double x = 0;
  double y = 0;
  return Vektor(x,y,z);
};

