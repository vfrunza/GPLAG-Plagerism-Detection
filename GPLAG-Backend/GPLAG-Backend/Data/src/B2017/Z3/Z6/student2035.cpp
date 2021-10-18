/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <cmath>



class Vektor3d {
      double x, y, z; 
      public: 
      void Postavi(double x, double y, double z) {
            this->x=x; this->y=y; this->z=z;     }
      Vektor3d &PostaviX(double x) { this->x=x; return *this; }
      Vektor3d &PostaviY(double y) { this->y=y;  return *this; }
      Vektor3d &PostaviZ(double z) { this->z=z; return *this; }
      void Ocitaj(double &x, double &y, double &z) {
            x=this->x; y=this->y; z=this->z;       }
      
      void Ispisi() const { std::cout << "{" << x << "," << y << "," << z << "}"; }
      double DajX() const { return x; } 
      double DajY() const { return y; } 
      double DajZ() const { return z; }
      double DajDuzinu() const { return std::sqrt(x*x + y*y + z*z); }
      Vektor3d &PomnoziSaSkalarom(double s) { x*=s; y*=s; z*=s;  return *this; }
      Vektor3d &SaberiSa(const Vektor3d &v) { x+=v.x; y+=v.y; z+=v.z; return *this; }
      friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
      Vektor3d v;
      v.x=v1.x+v2.x;
      v.y=v1.y+v2.y;
      v.z=v1.z+v2.z;
      return v;
}
int main ()
{
	return 0;
}
