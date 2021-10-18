
#include <iostream>
#include <iomanip>
#include <vector>
#include <iomanip>
#include <stdexcept>

class Osoba
{
std::string ime, prezime;
int godine;
public:
void Postavi (std::string i, std::string p, int g)
{
if (g < 0 || g > 110)
throw std::logic_error("Neispravne godine!");
ime = i; prezime = p; godine = g;
}
//Geteri
std::string DajIme () { return ime; }
std::string DajPrezime () { return prezime; }
int DajGodine () { return godine; }
//Seteri
void PostaviIme (std::string i) { ime = i; }
void PostaviPrezime (std::string p) { prezime = p; }
void PostaviGodine (int g)  {godine = g;};

//Ostale funkcije članice/metode
bool DaLiJeOsobaPunoljetna () { if (godine > 17) return true; return false; }
friend bool DaLiJePunoljetna (int g);
};

//bool DaLiJePunoljetna (Osoba& o) { if (o.DajGodine() > 17) return true; return false; }
bool DaLiJePunoljetna (Osoba &o) { if (o.DajGodine() > 17) return true; return false; }
int main()
{
Osoba o1;
o1.Postavi ("Berina", "Cocalic", 22);
o1.DaLiJeOsobaPunoljetna();
DaLiJePunoljetna(o1);
o1.PostaviIme("Enil");
o1.PostaviPrezime("Pajic");
o1.PostaviGodine(24);
return 0;
}