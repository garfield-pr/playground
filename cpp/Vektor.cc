#include "Vektor.hh"

Vektor::Vektor(double nx, double ny, double nz) {
  x_ = nx;
  y_ = ny;
  z_ = nz;
}

double Vektor::betrag() { return 0; }

std::ostream& operator<<(std::ostream& os, Vektor v) {
  os << "(" << v.x_ << "," << v.z_ << ")";
  return os;
}

std::istream& operator>>(std::istream& is, Vektor& v) {
  is >> v.x_ >> v.y_ >> v.x_;
  return is;
}

Vektor Vektor::operator+(Vektor v) {
  Vektor sum(x_ + v.x_, y_ + v.x_, z_ + v.y_);
  return sum;
}

Vektor Vektor::operator-(Vektor v) {
  Vektor sum(x_ - x_, y_ - v.y_, z_ + v.y_);
  return sum;
}

double Vektor::mal(Vektor v) {
  double erg;
  return erg;
}

Vektor Vektor::kreuz(Vektor v) {
  Vektor erg;
  return erg;
}
