#include <iostream>
#include <stdexcept>
#define DEBUG

using namespace std;

class GradjaninBiH {
public:
   enum Pol {Musko, Zensko};
private:
    static GradjaninBiH* zadnji;
    GradjaninBiH* prethodni = nullptr;
    long long int jmbg;
    string ime_i_prezime;
    static char to_char(int i) { return i + '0';}
    static int to_int(char i) { return i - '0';}
    static long long int to_lli(string s);
    bool leapYear(int year) {
        return(year % 100 != 0 && year % 4 == 0) || (year % 400 == 0); }
    int KreirajKontrolnuCifru(string jmbg);
    void ValidirajKontrolnuCifru(long long int jmbg);
    void ValidirajSifruRegije(int);
    void ValidirajDatum(int dan, int mjesec, int godina);
    void ValidirajPostojanje(long long int jmbg);
    long long int KreirajJMBG(int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    int KreirajKodOsobe(int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol, int neispravan_kod);
    GradjaninBiH* dajSljedeceg(GradjaninBiH*);
#ifdef DEBUG
    public:
#endif // DEBUG
    int DajKod() {
        return to_lli(to_string(jmbg).substr(9, 3));
    }
public:
    static string to_string(long long int i, int length = 13);
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const { return ime_i_prezime; };
    long long int DajJMBG() const { return jmbg; };
    int DajDanRodjenja() const { return to_lli(to_string(jmbg).substr(0, 2)); };
    int DajMjesecRodjenja() const { return to_lli(to_string(jmbg).substr(2, 2)); };
    int DajGodinuRodjenja() const {
        return to_lli((to_string(jmbg)[4] == '0' ? "2" : "1") + to_string(jmbg).substr(4, 3)); };
    int DajSifruRegije() const { return to_lli(to_string(jmbg).substr(7, 2)); };
    Pol DajPol() const { return ((to_int(to_string(jmbg)[9]) < 5) ? Pol::Musko : Pol::Zensko); };
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
};

GradjaninBiH* GradjaninBiH::zadnji;

string GradjaninBiH::to_string(long long int i, int length) {
    string ret = "";
    for(int j = 0; j < length; j++) {
        char c = to_char(i % 10);
        i /= 10;
        ret = string(1, c) + ret;
    }
    return ret;
}

long long int GradjaninBiH::to_lli(string s) {
    long long int ret = 0;
    for(int i = 0; i < s.size(); i++) {
        ret *= 10;
        ret += to_int(s[i]);
    }
    return ret;
}

int GradjaninBiH::KreirajKontrolnuCifru(string c) {
    int c13 = 11 - (7 * (to_int(c[0]) + to_int(c[6])) + 6 * (to_int(c[1]) + to_int(c[7]))
                         + 5 * (to_int(c[2]) + to_int(c[8])) + 4 * (to_int(c[3]) + to_int(c[9]))
                         + 3 * (to_int(c[4]) + to_int(c[10])) + 2 * (to_int(c[5]) + to_int(c[11]))) % 11;
    if(c13 == 11) c13 = 0;
    return c13;
}

void GradjaninBiH::ValidirajKontrolnuCifru(long long int jmbg) {
    int c13 = KreirajKontrolnuCifru(to_string(jmbg));
    if(c13 == 10 || c13 != jmbg % 10)
        throw logic_error("JMBG nije validan");
}

void GradjaninBiH::ValidirajSifruRegije(int sifra_regije) {
    if(sifra_regije < 0 || sifra_regije > 99)
        throw logic_error("Neispravni podaci");
};

void GradjaninBiH::ValidirajDatum(int day, int month, int year) {
    bool validation = true;
    if(!(year >= 1917 && year <=2017))
        validation = false;

    if(day < 1)
        validation = false;
    switch(month)
    {
    case 2:
        if(leapYear(year)) {
            if(day > 29)
                validation = false;
        }
        else {
            if(day > 28)
                validation = false;
        }
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if(day > 31)
            validation = false;
        break;
    case 4: case 6: case 9: case 11:
        if(day > 30)
            validation = false;
        break;
    default:
        validation = false;
        break;
    }
    if(!validation)
        throw logic_error("Neispravni podaci");
}

void GradjaninBiH::ValidirajPostojanje(long long int jmbg) {
    GradjaninBiH* lzadnji = GradjaninBiH::zadnji;
    while(lzadnji) {
        if(lzadnji->DajJMBG() == jmbg)
            throw logic_error("Vec postoji gradjanin sa istim JMBG");
        lzadnji = lzadnji->prethodni;
    }
}

long long int GradjaninBiH::KreirajJMBG(int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol) {
    string jmbg = "";
    jmbg = to_string(dan_rodjenja, 2) + to_string(mjesec_rodjenja, 2) +
    to_string(godina_rodjenja, 4).substr(1) + to_string(sifra_regije, 2);
    int neispravan_kod = -1;
    int kod_osobe;
    int kontrolna_cifra;
    do {
        kod_osobe = KreirajKodOsobe(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol, neispravan_kod);
        kontrolna_cifra = KreirajKontrolnuCifru(jmbg + to_string(kod_osobe, 3));
        neispravan_kod = kod_osobe;
    } while(kontrolna_cifra == 10);
    jmbg += to_string(kod_osobe, 3) + to_string(kontrolna_cifra, 1);
    return to_lli(jmbg);
}

int GradjaninBiH::KreirajKodOsobe(int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol, int neispravan_kod) {
    bool zauzet[500]{0};
    int offset = ((pol == Pol::Musko) ? 0 : 500);
    GradjaninBiH* lzadnji = zadnji;
    while(lzadnji) {
        if(lzadnji->DajDanRodjenja() == dan_rodjenja &&
           lzadnji->DajMjesecRodjenja() == mjesec_rodjenja &&
           lzadnji->DajGodinuRodjenja() == godina_rodjenja &&
           lzadnji->DajSifruRegije() == sifra_regije &&
           lzadnji->DajPol() == pol) {
            zauzet[lzadnji->DajKod() - offset] = true;
           }
        lzadnji = lzadnji->prethodni;
    }
    for(int i = neispravan_kod + 1; i < 500; i++)
        if(!zauzet[i])
            return i + offset;
    return -1;
}

GradjaninBiH* GradjaninBiH::dajSljedeceg(GradjaninBiH* trenutni) {
    GradjaninBiH* lzadnji = zadnji;
    if(lzadnji == trenutni)
        return nullptr;
    while(lzadnji->prethodni != trenutni)
        lzadnji = lzadnji->prethodni;
    return lzadnji;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) :
    ime_i_prezime(ime_i_prezime),
    jmbg(jmbg),
    prethodni(zadnji) {
        ValidirajKontrolnuCifru(DajJMBG());
        ValidirajPostojanje(DajJMBG());
        ValidirajSifruRegije(DajSifruRegije());
        ValidirajDatum(DajDanRodjenja(), DajMjesecRodjenja(), DajGodinuRodjenja());
        zadnji = this;
    }

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol) :
    ime_i_prezime(ime_i_prezime),
    prethodni(zadnji)
    {
        ValidirajDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja);
        ValidirajSifruRegije(sifra_regije);
        jmbg = KreirajJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
        zadnji = this;
    };

GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH* sljedeci = dajSljedeceg(this);
    if(sljedeci != nullptr)
        sljedeci->prethodni = prethodni;
    if(zadnji == this)
        zadnji = prethodni;
}

int main()
{
    int b;
    std::string ime_i_prezime;
    long long int jmbg;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? " <<std::endl;
    std::cin>>b;
    
    for(int i=0;i<b;i++){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin,ime_i_prezime);
        std::cout<<"Unesite JMBG: " <<std::endl;
        std::cin>>jmbg;
        try{
            GradjaninBiH g(ime_i_prezime,jmbg);
            std::string spol;
            if(g.DajPol() == 0) spol = "musko";
            else spol = "zensko";
            std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije()<<", "<<spol << "."<<std::endl;
    
        }    
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
            i--;
        }
    }
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " <<std::endl;
    std::cin>>n;
    
    for(int i=0;i<n;i++){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin,ime_i_prezime);
        int dan, mjesec,godina;
        string s;
       
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): " <<std::endl;
        std::getline(std::cin, s);
        dan = (s[0]-'0')*10 + (s[1]-'0');
        mjesec = (s[3]-'0')*10 + (s[4]-'0');
        godina = (s[6]-'0')*1000 + (s[7]-'0')*100 + (s[8]-'0')*10 + (s[9]-'0');
        
        int sifra;
        std::cout<<"Unesite sifru regije: " <<std::endl;
        std::cin>>sifra;
       
        char slovo;
        std::cout<<"Unesite M za musko, Z za zensko: " <<std::endl;
        std::cin>>slovo;
        
        GradjaninBiH::Pol p;
        if(slovo =='M') p = GradjaninBiH::Musko;
        else if(slovo =='Z') p = GradjaninBiH::Zensko;
        
        try{
            
            GradjaninBiH g(ime_i_prezime,dan,mjesec,godina,sifra,p);
           
            std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" JMBG: " <<g.DajJMBG()<<"."<<std::endl;
    
        }    
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
            i--;
        }
    }
    
           
    return 0;

}
