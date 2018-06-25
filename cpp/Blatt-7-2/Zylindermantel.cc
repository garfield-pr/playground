 #include "Zylindermantel.hh"

#include <cstdlib>
#include <cmath>

#include "Koerper.hh"

Zylindermantel::Zylindermantel(double nr, double nl, double m)
{
  M = m;
  Name = "zylindermntl";
  r_ = nr;
  l_ = nl;
}

Vektor Zylindermantel::punkt() 
{
  double R   = r_ * rand()/(double)RAND_MAX;
  double phi =  2*M_PI * rand()/(double)RAND_MAX;
  double z   = l_*(rand()/(double)RAND_MAX -0.5);

  double x = R * cos(phi);
  double y = R * sin(phi);
  return Vektor(x,y,z);
};

