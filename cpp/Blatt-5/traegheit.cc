#include <iostream>

#include "Vollzylinder.hh"
#include "Vektor.hh"

int main() 
{
  const int N = 10000;//Anzahl Integrationspunkte
  const double M = 1;//Masse des Zylindermantels
  const double ZM_R = 1.0;//Radius der Zylindermantels
  const double ZM_L = 1.0;//Laenge des Zylindermantels

  Vektor a;//Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u;//Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  Vollzylinder *zm = new Vollzylinder(ZM_R,ZM_L); 


  double J = 0;//Massentraegheitsmoment
  double m = M/N;//Masse eines Massenpunktes
  for(int i = 0 ; i < N ; ++i) {
    Vektor x = zm->punkt();
    //Abstand Punkt x und Gerade a + t*u
    //Vektor n = ...;//Normalenvektor x-a kreuz u 
    double r = 0;//|n|/|u|
   
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    r = (x-a).kreuz(u).betrag() / u.betrag();
    // std::cout << x << " :" << r << std::endl;
    J += m * r*r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
	    << " mit a = " << a << " und u = " << u 
	    << ": " << J << std::endl;
  delete zm;
  return 0;
}
