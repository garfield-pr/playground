#include <iostream>

#include "Vollzylinder.hh"
#include "Vektor.hh"

double traegheit( Koerper *k , Vektor a , Vektor u, Vektor x) {
  std :: cout << " berechne fuer " << k -> name() ;
  const int N = 10000;//Anzahl Integrationspunkte
  double J = 0;//Massentraegheitsmoment
  double m = (double) 1 / N;//Masse eines Massenpunktes
  double r = 0;
  
    // Vektor x = ->punkt();
    // Vektor x = k->punkt();
    //Abstand Punkt x und Gerade a + t*u
    //Vektor n = ...;//Normalenvektor x-a kreuz u 
    //|n|/|u|
   
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    r = (x-a).kreuz(u).betrag() / u.betrag();
    std::cout << x << " :" << r << std::endl;
    J = m * r*r;
  
  return J;
}


int main() 
{
  
  const double M = 1;//Masse des Zylindermantels
  const double ZM_R = 1.0;//Radius der Zylindermantels
  const double ZM_L = 1.0;//Laenge des Zylindermantels

  Vektor a;//Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u;//Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  Vollzylinder *zm = new Vollzylinder(ZM_R,ZM_L, M); 
  
  const int N = 10000;
  double J = 0;
  for(int i = 0 ; i < N ; ++i) {
    Vektor x = zm -> punkt();
    J += traegheit(zm, a, u, x);
    std::cout << J << std::endl;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
	    << " mit a = " << a << " und u = " << u 
	    << ": " << J << std::endl;
  delete zm;
  return 0;
}
