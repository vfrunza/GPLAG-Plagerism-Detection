/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class GradjaninBiH {
    long long int jmbg;
    std::string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    int spol;
    static bool JeLiIspravanDatum (int dan, int mjesec, int godina);
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH &operator =(const GradjaninBiH &g) = delete;
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg) : jmbg(jmbg), ime_i_prezime(ime_i_prezime) {
    int v[13];
    long long int pom(jmbg);
    for (int i=12; i>=0; i--) {
        v[i]=pom%10;
        pom/=10;
    }
    
    dan_rodjenja=v[0]*10+v[1];
    mjesec_rodjenja=v[2]*10+v[3];
    godina_rodjenja=v[4]*100+v[5]*10+v[6];
    if (godina_rodjenja>=917 && godina_rodjenja<=999)
        godina_rodjenja+=1000;
    else
        godina_rodjenja+=2000;
    if (!JeLiIspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("JMBG nije validan");
    if (v[12]!=(11-(7*(v[0]+v[6])+6*(v[1]+v[7])+5*(v[2]+v[8])+4*(v[3]+v[9])+3*(v[4]+v[10])+2*(v[5]+v[11]))%11)) throw std::logic_error("JMBG nije validan");
    sifra_regije=v[7]*10+v[8];
    int br_spol=v[9]*100+v[10]*10+v[11];
    if (br_spol>=0 && br_spol<=499)
        spol=0;
    else if (br_spol>=500 && br_spol<=999)
        spol=1;
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime), dan_rodjenja(dan_rodjenja), mjesec_rodjenja(mjesec_rodjenja), 
    godina_rodjenja(godina_rodjenja), sifra_regije(sifra_regije) {
        if (pol==Musko)
            spol=0;
        else
            spol=1;
        if (!JeLiIspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("Neispravni podaci");
        if (sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
        int v[13];
        int cifra, dan(dan_rodjenja), mjesec(mjesec_rodjenja), godina(godina_rodjenja), sifra(sifra_regije);
        cifra=dan%10;
        v[1]=cifra;
        dan/=10;
        cifra=dan%10;
        v[0]=cifra;
        cifra=mjesec%10;
        v[3]=cifra;
        mjesec/=10;
        cifra=mjesec%10;
        v[2]=cifra;
        cifra=godina%10;
        v[6]=cifra;
        godina/=10;
        cifra=godina%10;
        v[5]=cifra;
        godina/=10;
        cifra=godina%10;
        v[4]=cifra;
        cifra=sifra%10;
        v[8]=cifra;
        sifra/=10;
        cifra=sifra%10;
        v[7]=cifra;
    }

bool GradjaninBiH::JeLiIspravanDatum (int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        return false;
    return true;
}

std::string GradjaninBiH::DajImeIPrezime () const {
    return ime_i_prezime;
}

long long int GradjaninBiH::DajJMBG () const {
    return jmbg;
}

int GradjaninBiH::DajDanRodjenja () const {
    return dan_rodjenja;
}

int GradjaninBiH::DajMjesecRodjenja () const {
    return mjesec_rodjenja;
}

int GradjaninBiH::DajGodinuRodjenja () const {
    return godina_rodjenja;
}

int GradjaninBiH::DajSifruRegije () const {
    return sifra_regije;
}

GradjaninBiH::Pol GradjaninBiH::DajPol () const {
    if (spol==0)
        return Pol::Musko;
    return Pol::Zensko;
}

void GradjaninBiH::PromijeniImeIPrezime (std::string novo_ime) {
    ime_i_prezime=novo_ime;
} 

int main ()
{
    int n;
    long long int jmbg;
    std::string ime;
    GradjaninBiH *niz[100];
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    std::cin >> n;
    for (int i=0; i<n; i++) {
    std::cin.ignore (10000, '\n');
    std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
    std::getline (std::cin, ime);
    std::cout << "Unesite JMBG: " << std::endl;
    std::cin >> jmbg;
    try {
    GradjaninBiH g(ime, jmbg);
    std::cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " rodjenog " << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "." << g.DajGodinuRodjenja() << " u regiji " << g.DajSifruRegije() << ", ";
    if (g.DajPol()==0) std::cout << "musko." << std::endl;
    else std::cout << "zensko." << std::endl;
    }
    catch (std::logic_error e) {
        std::cout << e.what() << std::endl;
        i--;
    }
    }
    
	return 0;
}