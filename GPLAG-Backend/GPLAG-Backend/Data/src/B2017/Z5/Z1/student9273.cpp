/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <string>

class VektorNd {
 int dimenzija;
 double *koordinate;
 void TestIndeksa(int indeks) const {
 if(indeks < 1 || indeks > dimenzija)
 throw std::range_error("Pogrešan indeks!");
 }
public:
 explicit VektorNd(int dimenzija): dimenzija(dimenzija),
 koordinate(new double[dimenzija]) {
 std::fill(koordinate, koordinate + dimenzija, 0);
}
 ~VektorNd() { delete[] koordinate; }
  double *begin() const { return koordinate; }
 double *end() const { return koordinate + dimenzija; }
 
 VektorNd::VektorNd(std::initializer_list<double> lista) :
 dimenzija(lista.size()), koordinate(new double[lista.size()]) {
 std::copy(lista.begin(), lista.end(), koordinate);
}

VektorNd::VektorNd(const VektorNd &v) : dimenzija(v.dimenzija),
 koordinate(new double[v.dimenzija]) {
 std::copy(v.koordinate, v.koordinate + v.dimenzija, koordinate);
}

VektorNd(VektorNd &&v) : dimenzija(v.dimenzija),
 koordinate(v.koordinate) { v.koordinate = nullptr; }
 
/* VektorNd &operator =(const VektorNd &v) {
 double *novi_prostor(new double[v.dimenzija]);
 std::copy(v.koordinate, v.koordinate + v.dimenzija, novi_prostor);
 delete[] koordinate;
 dimenzija = v.dimenzija; koordinate = novi_prostor;
 return *this;
}*/
VektorNd &VektorNd::operator =(VektorNd v) {
 std::swap(dimenzija. v.dimenzija); std::swap(koordinate, v.koordinate);
 return *this;
}

/*VektorNd &VektorNd::operator =(VektorNd &&v) {
 if(&v != this) { // Samododjela?
 delete[] koordinate; koordinate = v.koordinate;
 dimenzija = v.dimenzija; v.koordinate = nullptr;
 }
 return *this;
}*/
VektorNd &VektorNd::operator =(VektorNd &&v) {
 std::swap(dimenzija. v.dimenzija); std::swap(koordinate, v.koordinate);
 return *this;
}

 

 void PromijeniDimenziju(int nova_dimenzija) {
 if(nova_dimenzija > dimenzija) {
 double *novo_mjesto(new double[nova_dimenzija]);
 std::copy(koordinate, koordinate + dimenzija, novo_mjesto);
 std::fill(novo_mjesto + dimenzija, novo_mjesto + nova_dimenzija, 0);
 delete[] koordinate; koordinate = novo_mjesto;
 }
 dimenzija = nova_dimenzija;
}

 void PostaviKoordinatu(int indeks, double vrijednost) {
 TestIndeksa(indeks); koordinate[indeks – 1] = vrijednost;
 }
 double DajKoordinatu(int indeks) const {
 TestIndeksa(indeks); return koordinate[indeks - 1];
 }
 double &DajKoordinatu(int indeks) {
 TestIndeksa(indeks); return koordinate[indeks - 1];
 }
 void Ispisi() constt {
 std::cout << "{";
 for(int i = 0; i < dimenzija; i++) {
 std::cout << koordinate[i];
 if(i != dimenzija – 1) std::cout << ",";
 }
 std::cout << "}";
}

};


int main ()
{
	return 0;
}
