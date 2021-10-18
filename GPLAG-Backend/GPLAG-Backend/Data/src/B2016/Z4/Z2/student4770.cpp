/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class GradjaninBiH {
    std::string i_i_p;
    int niz[13];
    static GradjaninBiH *kraj;
    GradjaninBiH *prethodni;
    static bool IspravanDatum(int dan, int mjesec, int godina);
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH &operator = (const GradjaninBiH &gr) = delete;
    GradjaninBiH(const GradjaninBiH &g) = delete;
    ~GradjaninBiH();
    std::string DajImeIPrezime() const {
        return i_i_p;
    }
    long long int DajJMBG() const {
        long long int jmbg(0), k(1);
        for(int i = 12; i >= 0; i--) {
            jmbg += niz[i]*k;
            k *= 10;
        } return jmbg;
    }
    int DajDanRodjenja() const {
        int dan = niz[0] * 10 + niz[1];
        return dan;
    }
    int DajMjesecRodjenja() const {
        int mjesec = niz[2] * 10 + niz[3];
        return mjesec;
    }
    int DajGodinuRodjenja() const {
        int godina;
        if(niz[4] == 0) godina = 2000 + 10 * niz[5] + niz[6];
        else godina = 1000 + 100 * niz[4] + 10 * niz[5] + niz[6];
        return godina;
    }
    int DajSifruRegije() const {
        int sifra = 10 * niz[7] + niz[8];
        return sifra;
    }
    Pol DajPol() const {
        int pol = 100 * niz[9] + 10 * niz[10] + niz[11];
        if(pol >= 500) return Pol::Zensko;
        return Pol::Musko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        i_i_p = novo_ime;
    }

};
GradjaninBiH *GradjaninBiH::kraj = nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) 
{
    i_i_p = ime_i_prezime;
    int brojac(12);
    int a;
    while(jmbg) {
        a = jmbg % 10;
        jmbg /= 10;
        niz[brojac] = a;
        brojac--;
        //if(brojac < 0) throw std::logic_error("JMBG nije validan");
    }
    if(!brojac) niz[brojac] = 0;
    int c = 11 - (7*(niz[0] + niz[6]) + 6*(niz[1] + niz[7]) + 5*(niz[2] + niz[8]) + 4*(niz[3] + niz[9]) + 3*(niz[4] + niz[10]) + 2*(niz[5] + niz[11])) % 11;
    if(c == 11) c = 0;
    if(c != niz[12]) throw std::logic_error("JMBG nije validan");
    int dan, mjesec, godina;
    dan = 10 * niz[0] + niz[1];
    mjesec = 10 * niz[2] + niz[3];
    if(niz[4] == 0) godina = 2000 + 10 * niz[5] + niz[6];
    else godina = 1000 + 100 * niz[4] + 10 * niz[5] + niz[6];
    if(!IspravanDatum(dan, mjesec, godina)) throw std::logic_error("JMBG nije validan");
    for(auto pok = kraj; pok != nullptr; pok = pok -> prethodni)
    {
        if(pok -> DajJMBG() == DajJMBG()) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    prethodni = kraj;
    kraj = this;
}
bool GradjaninBiH::IspravanDatum(int dan, int mjesec, int godina)
{
    int broj_dana[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(dan < 1 || dan > broj_dana[mjesec - 1] || mjesec < 1 || mjesec > 12 || godina > 2017 || godina <= 1917) return false;
    return true;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    i_i_p = ime_i_prezime;
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    if(!IspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    if(dan_rodjenja < 10) {
        niz[0] = 0; niz[1] = dan_rodjenja;
    }
    else {
        niz[0] = dan_rodjenja / 10; niz[1] = dan_rodjenja % 10;
    }
    niz[2] = mjesec_rodjenja / 10; niz[3] = mjesec_rodjenja % 10;
    if(godina_rodjenja >= 2000) {
        niz[4] = 0; 
        niz[5] = (godina_rodjenja % 100) / 10;
        niz[6] = godina_rodjenja % 10;
    }
    else {
        niz[4] = (godina_rodjenja - 1000) / 100;
        niz[5] = (godina_rodjenja % 100) / 10;
        niz[6] = godina_rodjenja % 10;
    }
    if(sifra_regije < 10) {
        niz[7] = 0; niz[8] = sifra_regije;
    }
    else {
        niz[7] = sifra_regije / 10; niz[8] = sifra_regije % 10;
    }
    if(pol == Pol::Zensko) {
        for(int i = 500; i < 1000; i++)
        {
            bool ima(false);
            niz[9] = i / 100; niz[10] = (i % 100) / 10; niz[11] = i % 10;
            int c = 11 - (7*(niz[0] + niz[6]) + 6*(niz[1] + niz[7]) + 5*(niz[2] + niz[8]) + 4*(niz[3] + niz[9]) + 
            3*(niz[4] + niz[10]) + 2*(niz[5] + niz[11])) % 11;
            if(c == 10) continue;
            if(c == 11) c = 0;
            niz[12] = c;
            for(auto pok = kraj; pok != nullptr; pok = pok -> prethodni)
            {
                if(pok -> DajJMBG() == DajJMBG()) 
                {   
                    ima = true; break;
                }
            }
            if(!ima) break;
        }
    }
    else if(pol == Pol::Musko) {
        for(int i = 0; i < 500; i++)
        {
            bool ima(false);
            niz[9] = i / 100; niz[10] = (i % 100) / 10; niz[11] = i % 10;
            int c = 11 - (7*(niz[0] + niz[6]) + 6*(niz[1] + niz[7]) + 5*(niz[2] + niz[8]) + 4*(niz[3] + niz[9]) + 
            3*(niz[4] + niz[10]) + 2*(niz[5] + niz[11])) % 11;
            if(c == 10) continue;
            if(c == 11) c = 0;
            niz[12] = c;
            for(auto pok = kraj; pok != nullptr; pok = pok -> prethodni)
            {
                if(pok -> DajJMBG() == DajJMBG()) 
                {
                    ima = true; break;
                }
            } if(!ima) break;
        }
    }
}
GradjaninBiH::~GradjaninBiH() {
    auto tmp = kraj;
    for(auto pok = kraj; pok != nullptr; pok = pok -> prethodni)
    {
        if(pok == this) {
            if(kraj == this) {
                kraj = prethodni; break;
            } tmp -> prethodni = prethodni; break;
        } tmp = pok;
    }
}
int main ()
{
    GradjaninBiH *niz[100] {};
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    for(int i = 0; i < n; i++)
    {
        try {
            std::cin.ignore(1000, '\n');
            long long int jmbg;
            std::string s;
            std::cout<<"Unesite ime i prezime (u istom redu): \n";
            std::getline(std::cin, s);
            std::cout<<"Unesite JMBG: \n";
            //std::cin.ignore(1000000, '\n');
            std::cin>>jmbg;
          //  std::cin.ignore(1000000, '\n');
            niz[i] = new GradjaninBiH(s, jmbg);
            std::cout<<"Unijeli ste gradjanina "<<niz[i] -> GradjaninBiH::DajImeIPrezime()<<" rodjenog "<<niz[i] -> GradjaninBiH::DajDanRodjenja()<<"."<<niz[i]->GradjaninBiH::DajMjesecRodjenja()<<"."<<
            niz[i]->GradjaninBiH::DajGodinuRodjenja()<<" u regiji "<<niz[i]->GradjaninBiH::DajSifruRegije()<<",";
            if(niz[i]->GradjaninBiH::DajPol() == GradjaninBiH::Pol::Zensko) std::cout<<" zensko.";
            else std::cout<<" musko.";
            
        }
        catch(std::logic_error a) {
            std::cin.ignore(10000, '\n');
            std::cout<<a.what();
            i--;
        }
        std::cout<<std::endl;
    } 
    int m;
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin>>m;
    for(int i = 0; i < m; i++)
    {
        try {
            std::cout<<"Unesite ime i prezime (u istom redu): ";
            std::string t;
            std::getline(std::cin, t);
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): ";
            int d, m, g;
            char a;
            std::cin>>d>>a>>m>>a>>g;
            std::cout<<"Unesite sifru regije: ";
            int sifra; std::cin>>sifra;
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite M za musko, Z za zensko: ";
            char x; std::cin>>x;
            auto spol = GradjaninBiH::Pol::Zensko;
            if(x == 'M') auto spol = GradjaninBiH::Pol::Musko;
            niz[i+n] = new GradjaninBiH(t, d, m, g, sifra, spol);
            std::cout<<"Unijeli ste gradjanina "<<niz[i+n]->DajImeIPrezime()<<" JMBG: "<<niz[i+n]->DajJMBG()<<".";
            std::cin.ignore(100000, '\n');
        } catch(std::logic_error izuzetak) {
            std::cin.ignore(10000, '\n');
            std::cout<<izuzetak.what();
            i--;
        } std::cout<<std::endl;
    } 
	return 0;
}