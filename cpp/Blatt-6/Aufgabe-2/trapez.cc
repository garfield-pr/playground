#include <iostream>
#include <vector>
#include <cmath>

//Testfunktionen als Funktor
class Pol1 {
public:
  double operator()(double x)
  {
    return 3 * x + 2;
  }
};

class Pol2 {
public:
  double operator()(double x)
  {
    return -2 *x*x + 3 *x +1;
  }
};

class Gauss {
public:
  double operator()(double x)
  {
    return 1/(sqrt(M_PI * 2)) * exp(-x*x/2);
  }
};

class sinus {
public:
  double operator()(double x)
  {
    return sin(x);
  }
};

class cosinus {
public:
  double operator()(double x)
  {
    return cos(x);
  }
};

class exponential {
public:
  double operator()(double x)
  {
    return exp(x);
  }
};



//berechet Naeherungen ueber das Romberg-Verfahren
std::vector<std::vector<double> > romberg(std::vector<double> I) {
  const int N = I.size() - 1;
  std::vector<std::vector<double> > R(N+1);
  for(int k = 0 ; k <= N ; ++k) {
    R[k].push_back(I[k]);
  }
//   for(int k=0 ; k < N; ++k) {
//     double extr = R[k+1][0] + (R[k+1][0] - R[k][0])/3;
//     R[k].push_back(extr);

//     // for(int k=0 ; k < N; ++k) {
//     // double extr = R[k+1][1] + (R[k+1][1] - R[k][1])/3;
//     // R[k].push_back(extr);
//     // }

//     for(int a=1 ; a < N - k ; a++) {
//     double extr = R[k+1][a-1] + (R[k+1][a-1] - R[k][a-1])/(pow(2,2 * a) - 1);
//     R[k].push_back(extr);
//     }
//     // double extr = R[k+1][0] + (R[k+1][0] - R[k][0])/3;
//     // R[k].push_back(extr);
//   }
//   return R;
// }
    // for(int k=0 ; k < N; ++k) {
    // double extr = R[k+1][1] + (R[k+1][1] - R[k][1])/3;
    // R[k].push_back(extr);
    // }
for(int a=1 ; a < N+1; a++) {
for(int k=0 ; k < N-a+1; ++k) {
    double extr = R[k+1][a-1] + (R[k+1][a-1] - R[k][a-1])/(pow(2,2*a)-1);
    R[k].push_back(extr);

    // for(int k=0 ; k < N; ++k) {
    // double extr = R[k+1][1] + (R[k+1][1] - R[k][1])/3;
    // R[k].push_back(extr);
    // }

    // for(int a=1 ; a < N - k ; a++) {
    // double extr = R[k+1][a-1] + (R[k+1][a-1] - R[k][a-1])/(pow(2,2 * a) - 1);
    // R[k].push_back(extr);
    // }
    // double extr = R[k+1][0] + (R[k+1][0] - R[k][0])/3;
    // R[k].push_back(extr);
  }}
  return R;
}


//berechnet Werte nach Trapezformel von I_0 bis I_N
template<class Functor> std::vector<double> trapez(Functor f, double a, double b, int N) {
  // Pol1 f;
  std::vector<double> I(N+1);//Feld mit N+1 Eintraegen
  double h = b - a;
  I[0] = h/2 *(f(a) + f(b)); 
  
  for(int k = 1 ; k <= N ; ++k) {
    //...
    h = h/2;
    int n = 0;
    n = pow(2, k);
    double sum = 0;
    for (int i=1; i < n ; i=i+2){
      sum = sum + f(a + i*h);
    }
    I[k] =  (double) I[k-1]/2 + h*sum;//setze k-ten Wert im Feld
    // I[k] =  I[k-1] + h*f(a + k*h);//setze k-ten Wert im Feld
  }
  return I;
}


int main()
{
  //Testfunktion:
  Pol1 f;
  std::cout << "f(0) = " << f(0) << '\n';
  // berechne Trapezformel fuer f
  std::vector<double> tf = trapez(f, 0.,3.,3);
  std::cout << "#############################################################\n";
  //Ausgabe:
  std::cout << "Trapez:\n";
  for(int i = 0; i < tf.size() ; ++i) {//Schleife ueber Werte im Feld
    std::cout << "I_" << i <<  " = " << tf[i] << std::endl;  
  }
  std::cout << "#############################################################\n";
  std::cout << "I1-I2:" << (double) 4/3*tf[1] - (double) 1/3 * tf[0]<< std::endl;
   std::cout << "#############################################################\n";
  std::cout << "I2-I1:" << (double) 4/3*tf[2] - (double) 1/3 * tf[1]<< std::endl;
   std::cout << "#############################################################\n";
  std::cout << "I3-I2:" << (double) 4/3*tf[3] - (double) 1/3 * tf[2]<< std::endl;
  std::cout << "#############################################################\n";
  std::vector<std::vector<double> > R = romberg(tf);
  std::cout << "Romberg:\n";
  for(int k = 0, l = R.size() ;  k < l ; ++k) {
    for(int n = 0, m = R[k].size() ;  n < m ; ++n) {
      std::cout << R[k][n] << " ";
    }
    std::cout << std::endl;
  }
}
