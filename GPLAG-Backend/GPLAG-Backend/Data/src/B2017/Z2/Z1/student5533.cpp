#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
static constexpr double PI=3.141592653589793;
struct Krug { 
	double x, y, r; 
};
class Krugovi {
	int kapacitet, broj_krugova;
	Krug *pok;
public:
    explicit Krugovi (int max): kapacitet (max), broj_krugova (0), pok (new Krug [max]) {}
    ~Krugovi () { delete [] pok; }
    Krugovi (const Krugovi &k);
    Krugovi (Krugovi &&k);
    Krugovi &operator= (const Krugovi &k);
    Krugovi &operator= (Krugovi &&k);
    void DodajNoviKrug (double x, double y, double r);
    Krug &operator[] (int indeks);
    Krug operator[] (int indeks) const;
    void IspisiSortirano ();
};
Krugovi::Krugovi (const Krugovi &k): kapacitet (k.kapacitet), broj_krugova (k.broj_krugova) {
	pok = new Krug[kapacitet];
	for (int i=0; i<broj_krugova; i++) 
		pok[i] = k.pok[i];
}
Krugovi::Krugovi (Krugovi &&k): kapacitet (k.kapacitet), broj_krugova (k.broj_krugova), pok (k.pok) {
	k.pok=nullptr; k.kapacitet =0; k.broj_krugova=0;
}
Krugovi &Krugovi::operator= (const Krugovi &k) {
	if (&k==this) return *this;
	Krug *novi = new Krug[k.kapacitet];
	for (int i=0; i<k.broj_krugova; i++) novi[i]=k.pok[i];
	delete [] pok;
	kapacitet=k.kapacitet; broj_krugova=k.broj_krugova;
	pok=novi;
	return *this;
}
Krugovi &Krugovi::operator = (Krugovi &&k) {
	std::swap (kapacitet, k.kapacitet); std::swap (broj_krugova, k.broj_krugova); std::swap (pok, k.pok);
	return *this;
}
void Krugovi::DodajNoviKrug (double x, double y, double r) {
	if (broj_krugova == kapacitet) throw std::logic_error ("Popunjeno");
	for (int i=0; i<broj_krugova; i++) 
		if ( (pok[i].r+r) > sqrt ((pok[i].x-x)*(pok[i].x-x) + (pok[i].y-y)*(pok[i].y-y))) throw std::domain_error("Preklapaju se");
		Krug k; k.x=x; k.y=y; k.r=r;
	    pok[broj_krugova++]=k;
}
Krug &Krugovi::operator[] (int indeks) {
	if (indeks<0 || indeks >=broj_krugova) throw std::domain_error ("Nije validan indeks");
	for (int i=0; i<broj_krugova; i++) 
		if (i==indeks) return pok[i];
}
Krug Krugovi::operator[] (int indeks) const {
	if (indeks<0 || indeks >=broj_krugova) throw std::domain_error ("Nije validan indeks");
	for (int i=0; i<broj_krugova; i++) 
		if (i==indeks) return pok[i];
}
void Krugovi::IspisiSortirano () {
	std::sort (pok, pok+broj_krugova, [] (Krug k1, Krug k2) {
		return k1.r*k1.r*PI > k2.r*k2.r*PI;
	});
	for (int i=0; i<broj_krugova; i++) std:: cout << "[ ( " << pok[i].x << ", " << pok[i].y << ") , " << pok[i].r << "]";
}
int main ()
{
	return 0;
}