#include <iostream>
class KlasaA {
protected:
 int x, y;
public:
  KlasaA(){x=2; y=1;}
  KlasaA (int xx, int yy = 0) : x(xx), y(yy) {}
 virtual int DajX() const { return x; }
 virtual int DajY() const { return y; }
 virtual ~KlasaA();
};
class KlasaB : public KlasaA {
 int z;
public:
KlasaB(): KlasaA(0,1), z(0){}
 KlasaB (int x, int y, int z): KlasaA(x, y), z(z){}
 int DajX() const override { return x + z; }
 int DajY() const override { return y + z; }
 int DajZ()  const { return z; }
 ~KlasaB();
};
int main() {
 KlasaA ka1, ka2(5, 3), ka3 (3);
 KlasaB kb1, kb2(), kb3 (4, 2, 1);
 std::cout << ka1.DajX() << " " << ka1.DajY() << std::endl; // 2 1
 std::cout << ka2.DajX() << " " << ka2.DajY() << std::endl; // 5 3
 std::cout << ka3.DajX() << " " << ka3.DajY() << std::endl; // 3 0
 std::cout << kb1.DajX() << " " << kb1.DajY() << " " << kb1.DajZ() << "\n"; // 4 5 3
// std::cout << kb2.DajX() << " " << kb2.DajY() << " " << kb2.DajZ() << "\n"; // 1 2 0
 std::cout << kb3.DajX() << " " << kb3.DajY() << " " << kb3.DajZ() << "\n"; // 5 3 1
 return 0;
}
