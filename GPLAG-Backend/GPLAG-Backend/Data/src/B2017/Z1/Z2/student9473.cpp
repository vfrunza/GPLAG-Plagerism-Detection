/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
 
class A {
  double x;
  int y, z;
public:
  A(int z, int x) : x(x), y(z), z(0) { std::cout << "A0 "; }
  A(int z = 2, double x = 1) : x(0), y(x), z(z) { std::cout << "A1 "; }
  explicit A(double A) : x(1), y(A), z(x) { std::cout << "A2 "; }
  A(A &a) : x(a.y), y(2), z(a.x) { a.x = 3; x *= 2; std::cout << "A3 "; }
  A(const A &a) : x(a.y), y(2), z(a.x) { x *= -2; std::cout << "A4 "; }
  int operator =(int x) {
    std::cout << "A5 ";
    return A(this->x + x + this->y).DajX();
  }
  int operator =(const A &y) {
    std::cout << "A6 ";
    return A(this->x + y.y + this->y, 1).DajY();
  }
  double DajX () const { return x; }
  int DajY () const { return -y; }
  int DajY () { return y; }
  int DajZ () const { return z; }
  void f() { std::cout << "Muu "; }
  virtual void g() { std::cout << "Bee "; }
  friend std::ostream &operator <<(std::ostream &tok, const A &a) {
    return tok << "x = " << a.DajY() << ", y = " << a.DajZ()
      << ", z = " << a.DajX() << " ";
  }
};
 
struct B : public A {
  B() { std::cout << "B0 ";}
  void f() { std::cout << "Njaa "; }
  void g() { std::cout << "Mjau "; }
};
 
void VoliMe(A a) { a.f(); a.g(); }
 
void NeVoliMe(A &a) { a.f(); a.g(); }
 
int main() {
  A a(4), b(3.5), c(1, 2), d, e(3, 2.);
  std::cout << std::endl;
  std::cout << B() << std::endl;
  const A f(7, 11);
  A g(f), h(c);
  B p;
  VoliMe(g); NeVoliMe(g); VoliMe(p); NeVoliMe(p);
  std::cout << std::endl << c << "| " << h << "| " << g << std::endl;
  auto op1 = (c = 3), op2 = (b = e);
  std::cout << op1 * 5; std::cout << " " << op2;
  return 0;
}