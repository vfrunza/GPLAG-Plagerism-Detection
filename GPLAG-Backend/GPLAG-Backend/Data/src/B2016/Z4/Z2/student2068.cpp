#include <iostream>
#include <string>
#include <stdexcept>
//
long long int stepen(int x) {
    long long int s=1;
    for(int i=0; i<x; i++) s*=10;
    return s;
}

void ValidanDatum(int d, int m, int g) {
    if(g<1917 || g>2017 || m<1 || m>12 || d<1 || d>31) throw std::logic_error("Neispravni podaci");
    int dani[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(d%400==0 || (d%100 && d%4==0)) dani[1]++;
    if(d>dani[m-1]) throw std::logic_error("Neispravni podaci");
}

class GradjaninBiH {
public:
    enum Pol { Musko, Zensko };
private :
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni;
    std::string s;
    long long int mat;
    Pol spol;
    int daj_d() const;
    int daj_m() const;
    int daj_g() const;
    int daj_sifru() const;
    int daj_kod() const;
    int daj_zadnju() const;
public :
    GradjaninBiH(const GradjaninBiH &G) =delete;
    GradjaninBiH& operator=(const GradjaninBiH &g) =delete;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const { return s; }
    long long int DajJMBG() const { return mat; }
    int DajDanRodjenja() const { return daj_d(); }
    int DajMjesecRodjenja() const { return daj_m(); }
    int DajGodinuRodjenja() const { int a=daj_g(); if(a>100) return a+1000; return a+2000; }
    int DajSifruRegije() const { return daj_sifru(); }
    Pol DajPol() const { return spol; }
    void PromijeniImeIPrezime(std::string novo_ime) { s=novo_ime; }
    ~GradjaninBiH() {
        auto p=zadnji;
        while(p->prethodni!=this) {
            if(!p->prethodni) {
                zadnji=zadnji->prethodni;
                return;
            }
            p=p->prethodni;
        }
        p->prethodni=prethodni;
    }
};

GradjaninBiH* GradjaninBiH::zadnji=nullptr;

int izracunaj_zadnju_cifru(int d, int m, int g, int sifra, int kod) {
    return 11-(7*(d/10+g%10)+6*(d%10+sifra/10)+5*(m/10+sifra%10)+4*(m%10+kod/100)+3*(g/100+(kod%100-kod%10)/10) +2*((g%100-g%10)/10+kod%10))%11;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : s(ime_i_prezime), mat(jmbg) {
    if(daj_kod()<500) spol=Musko; else spol=Zensko;
    int godina=daj_g(); if(godina>100) godina+=1000; else godina+=2000;
    try { ValidanDatum(daj_d(), daj_m(), godina); }
    catch(...) { throw std::logic_error("JMBG nije validan"); }
    int c13=izracunaj_zadnju_cifru(daj_d(), daj_m(), daj_g(), daj_sifru(), daj_kod());
    if(c13==11) c13=0;
    if(c13!=daj_zadnju() || c13==10) throw std::logic_error("JMBG nije validan");
    auto pointer=zadnji;
    while(pointer) {
        if(jmbg==pointer->mat) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pointer=pointer->prethodni;
    }
    prethodni=zadnji; zadnji=this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : s(ime_i_prezime), spol(pol) {  
    try { ValidanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja); }
    catch(...) { throw std::logic_error("Neispravni podaci"); }
    if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    int kod;
    if(pol==Musko) kod=0; else kod=500;
    auto p=zadnji; int godina; if(godina_rodjenja>1999) godina=godina_rodjenja-2000; else godina=godina_rodjenja-1000;
    for(;;) {
        while(p) {
            if(dan_rodjenja==p->daj_d() && mjesec_rodjenja==p->daj_m() && godina==p->daj_g() && sifra_regije==p->daj_sifru() && pol==p->spol && kod==p->daj_kod()) { kod++; p=zadnji; continue; }
            p=p->prethodni;
        }
        int z=izracunaj_zadnju_cifru(dan_rodjenja, mjesec_rodjenja, godina, sifra_regije, kod);
        if(z==10) {
            p=zadnji; kod++;
            continue;
        }
        if(z==11) z=0;
        mat=z;
        break;
    }
    prethodni=zadnji; zadnji=this;
    mat+=dan_rodjenja*stepen(11)+mjesec_rodjenja*stepen(9)+godina*stepen(6)+sifra_regije*stepen(4)+kod*10;
}

int GradjaninBiH::daj_d() const {
    return mat/stepen(11);
}

int GradjaninBiH::daj_m() const {
    return mat%stepen(11)/stepen(9);
}

int GradjaninBiH::daj_g() const {
    return mat%stepen(9)/stepen(6);
    /*if(x>100) x+=1000;
    else x+=2000;
    return x;*/
}

int GradjaninBiH::daj_sifru() const {
    return mat%stepen(6)/stepen(4);
}

int GradjaninBiH::daj_kod() const {
    return mat%stepen(4)/10;
}

int GradjaninBiH::daj_zadnju() const {
    return mat%10;
}

int main () {
    GradjaninBiH* niz[100];
	std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
	int n; std::cin >> n;
	for(int i=0; i<n; i++) {
	    std::cout << "Unesite ime i prezime (u istom redu): ";
	    std::string s;
	    std::cin.ignore(10000, '\n'); std::getline(std::cin, s);
	    std::cout << "\nUnesite JMBG: \n";
	    long long int jmbg; std::cin >> jmbg;
	    try { 
	        niz[i]=new GradjaninBiH(s, jmbg); 
	        std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", ";
	        if(niz[i]->DajPol()==GradjaninBiH::Musko) std::cout << "musko.\n"; else std::cout << "zensko.\n";
	    }
	    catch(std::logic_error izuzetak) { std::cout << izuzetak.what() << "\n"; i--; }
	}
	std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
	int n2; std::cin >> n2;
	for(int i=n; i<n+n2; i++) {
	    std::cout << "Unesite ime i prezime (u istom redu): ";
	    std::string s;
	    std::cin.ignore(10000, '\n'); std::getline(std::cin, s);
	    std::cout << "\nUnesite datum rodjenja (format dd/mm/gggg): ";
	    int d, m, g; char c; std::cin >> d >> c >> m >> c >>g;
	    std::cout << "\nUnesite sifru regije: ";
	    int si; std::cin >> si;
	    std::cout << "\nUnesite M za musko, Z za zensko: \n";
	    std::cin >> c; GradjaninBiH::Pol a;
	    if(c=='Z' || c=='z') a=GradjaninBiH::Zensko; else a=GradjaninBiH::Musko; 
	    try { 
	        niz[i]=new GradjaninBiH(s, d, m, g, si, a); 
	        std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << ".\n";
	    }
	    catch(std::logic_error izuzetak) { std::cout << izuzetak.what() << "\n"; i--; }
	}
	for(int j=0; j<n+n2; j++) delete niz[j];
	return 0;
}