/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cin; using std::cout; using std::endl;

class GradjaninBiH {
    std::string i_i_p;
    int jmbg[13];
    GradjaninBiH *prethodni;
    static GradjaninBiH *pok_na_posljednji; //Zajednicki za sve
    bool ValidanJMBG (long long int jmbg);
    bool VecPostoji(long long int jmbg);
    bool IspravanDatum (int d, int m, int g);
    int PrviSlobodanM(int d, int m, int g, int sifra_regije);
    int PrviSlobodanZ(int d, int m, int g, int sifra_regije);
    int Velicina(long long int jmbg);
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &g) = delete; //Zabrana kopiranja
    GradjaninBiH &operator =(const GradjaninBiH &g) = delete; //Zabrana dodjele
    ~GradjaninBiH(); 
    std::string DajImeIPrezime() const { return i_i_p; }
    long long int DajJMBG() const {
        long long int JMBG(0);
        for (int i=0; i<13; i++) {
            JMBG=JMBG*10+jmbg[i];
        }
        return JMBG; 
    }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime) {
        i_i_p=novo_ime;
    }
};

GradjaninBiH* GradjaninBiH::pok_na_posljednji(nullptr);

//Pomocne funkcije

int GradjaninBiH::Velicina(long long int jmbg) {
    int brojac(0);
    while (jmbg !=0) {
        jmbg/=10;
        brojac++;
    }
    return brojac;
}

bool GradjaninBiH::IspravanDatum (int d, int m, int g) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++; //Prestupna
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1]) return false;
    return true;
}
//iznimno je važno da pri testiranju programa nikada ovu vodeću nulu ne napišete, tj. da ne pošaljete 0311012715124 kao parametar u konstruktor.

//Metode i konstruktori
GradjaninBiH::~GradjaninBiH() {
    //Iskljucimo objekat iz lanca
    if (prethodni==nullptr) pok_na_posljednji=nullptr; //U pitanju je prvi
    else if (this==pok_na_posljednji) {
        //Zadnji element
        pok_na_posljednji=prethodni;
    }
    else {
        GradjaninBiH *p(pok_na_posljednji), ;
        while (p!=nullptr) {
            if (p==this) {
                p=prethodni;
                prethodni = nullptr;
            }
        p=p->prethodni;
        }
    }
}

bool GradjaninBiH::ValidanJMBG (long long int jmbg) {
    int JMBG[13], i(12);
    if (Velicina(jmbg)==12) {
        JMBG[0]=0; //?
    }
    while (jmbg!=0 && i>=0) {
        JMBG[i]=jmbg%10;
        jmbg/=10;
        i--;
    }
    if (jmbg!=0 || i>1) return false; //Ima vise od 13 cifara ili manje od 12
    //Provjerimo validnost datuma rodjenja
    int d(JMBG[0]*10+JMBG[1]);
    int m(JMBG[2]*10+JMBG[3]);
    int g(0); 
    //Niko nije stariji od sto godina, znaci JMBG[4] ili 0 ili 9? g>=1918 i g<=2017
    if (!(JMBG[4]==0 || JMBG[4]==9)) return false;
    if (JMBG[4]==0) {
        if ((JMBG[5]*10+JMBG[6])<=17)
        g=2000+JMBG[5]*10+JMBG[6];
        else return false;
    }
    else {
        if ((JMBG[5]*10+JMBG[6])<18) return false;
        g=1900+JMBG[5]*10+JMBG[6];
    }
    if (!IspravanDatum(d, m, g)) return false;
    //Provjerimo validnost kontrolne cifre
    int c13(0);
    c13=11-fmod((7*(JMBG[0]+JMBG[6])+ 6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11])), 11);
    if (c13==11) c13=0;
    if (c13==10 || c13!=JMBG[12]) return false;
    return true;
}

bool GradjaninBiH::VecPostoji(long long int jmbg) {
    GradjaninBiH *p(pok_na_posljednji);
    while (p!=nullptr) {
        if (jmbg==p->DajJMBG()) return true;
        p=p->prethodni;
    }
    return false;
}

int GradjaninBiH::PrviSlobodanM(int d, int m, int g, int sifra_regije) {
    int brojac(0);
    GradjaninBiH *p(pok_na_posljednji);
    while (p!=nullptr) {
        if (sifra_regije==p->DajSifruRegije() && d==p->DajDanRodjenja() && m==p->DajMjesecRodjenja() && g==p->DajGodinuRodjenja() && p->DajPol()==0) brojac++;
        /*cout << sifra_regije << " " << p->DajSifruRegije() << " " << d << " " << p->DajDanRodjenja() << " " << m << " " << p->DajMjesecRodjenja() << " " << 
        g << " " << p->DajGodinuRodjenja() << " " << brojac << endl;*/
        p=p->prethodni;
    }
    return brojac;
}

int GradjaninBiH::PrviSlobodanZ(int d, int m, int g, int sifra_regije) {
    int brojac(500);
    auto p(pok_na_posljednji); //p kopija
    while (p!=nullptr) { //Od posljednjeg ka pocetku
        if (sifra_regije==p->DajSifruRegije() && d==p->DajDanRodjenja() && m==p->DajMjesecRodjenja() && g==p->DajGodinuRodjenja() && p->DajPol()==1) brojac++;
        p=p->prethodni;
    }
    return brojac;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : prethodni(nullptr){
    if (!ValidanJMBG(jmbg)) throw std::logic_error ("JMBG nije validan");
    if (VecPostoji(jmbg)) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    i_i_p=ime_i_prezime; 
    if (Velicina(jmbg)==13) {
        for (int i=12; i>=0; i--) {
            GradjaninBiH::jmbg[i]=jmbg%10;
            jmbg/=10;
        }
    }
    if (Velicina(jmbg)==12) {
        GradjaninBiH::jmbg[0]=0;
        for (int i=11; i>=1; i--) {
            GradjaninBiH::jmbg[i]=jmbg%10;
            jmbg/=10;
        }
    }
    if (!pok_na_posljednji) {
        prethodni=nullptr;
        pok_na_posljednji=this; }//Za prvog gradjanina
    else {
        prethodni=pok_na_posljednji;
        pok_na_posljednji=this;
    }
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol) : prethodni(nullptr) {
    int JMBG[13]; auto god(godina_rodjenja);
    if (!IspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error ("Neispravni podaci");
    JMBG[0]=dan_rodjenja/10; JMBG[1]=dan_rodjenja%10; //Cjelobrojno dijeljenje pa dolazi do odsjecanja
    JMBG[2]=mjesec_rodjenja/10; JMBG[3]=mjesec_rodjenja%10;
    if (godina_rodjenja>=1918 && godina_rodjenja <=2017) { //Ne stariji od 100 god
        if (godina_rodjenja<2000) {
            godina_rodjenja-=1000;
            JMBG[4]=godina_rodjenja/100; JMBG[5]=godina_rodjenja/10-JMBG[4]*10; JMBG[6]=godina_rodjenja%10;
        }
        else {
            godina_rodjenja-=2000;
            JMBG[4]=godina_rodjenja/100; JMBG[5]=godina_rodjenja/10-JMBG[4]*10; JMBG[6]=godina_rodjenja%10;
        }
    }
    else throw std::logic_error ("Neispravni podaci");
    if (sifra_regije<0 || sifra_regije>99) throw std::logic_error ("Neispravni podaci");
    JMBG[7]=sifra_regije/10; JMBG[8]=sifra_regije%10;
    if (pol==Musko) {
        //Uzimamo prvi slobodan
        int kod(PrviSlobodanM(dan_rodjenja, mjesec_rodjenja, god, sifra_regije));
        JMBG[9]=kod/100; JMBG[10]=kod/10-JMBG[9]*10; JMBG[11]=kod%10;
    }
    else if (pol==Zensko) {
        //Uzimamo prvi slobodan
        int kod(PrviSlobodanZ(dan_rodjenja, mjesec_rodjenja, god, sifra_regije));
        JMBG[9]=kod/100; JMBG[10]=kod/10-JMBG[9]*10; JMBG[11]=kod%10;
    }
    //Provjerimo validnost kontrolne cifre
    int c13(0);
    c13=11-fmod((7*(JMBG[0]+JMBG[6])+ 6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11])),11);
    if (c13==11) c13=0;
    if (c13==10) throw std::logic_error ("Neispravni podaci");
    JMBG[12] = c13;
    for (int i=0; i<13; i++) {
        GradjaninBiH::jmbg[i]=JMBG[i];
    }
    i_i_p=ime_i_prezime;
    if (!pok_na_posljednji) {
        prethodni=nullptr;
        pok_na_posljednji=this; }//Za prvog gradjanina
    else {
        prethodni=pok_na_posljednji;
        pok_na_posljednji=this;
    }
}
int GradjaninBiH::DajDanRodjenja() const {
    return jmbg[0]*10+jmbg[1];
}
int GradjaninBiH::DajMjesecRodjenja() const {
    return jmbg[2]*10+jmbg[3];
}
int GradjaninBiH::DajGodinuRodjenja() const {
    //Izmedju 1918 i 2017
    if (jmbg[4]==9) {
        return 1900+jmbg[5]*10+jmbg[6];
    }
    else return 2000+jmbg[5]*10+jmbg[6];
}
int GradjaninBiH::DajSifruRegije() const {
    return jmbg[7]*10+jmbg[8];
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    if ((jmbg[9]*100+jmbg[10]*10+jmbg[11])<500) return Pol::Musko;
    else return Pol::Zensko;
}


int main ()
{
    /*U testnom programu u ovom zadatku dozvoljeno je kreirati niz fiksne
    veličine od 100 elemenata, čiji su elementi pokazivači na objekte
    tipa "GradjaninBiH". Bez ovoga se tražena funkcionalnost ne može
    realizirati.*/
    GradjaninBiH *niz_gr[100]; 
    for (int i=0; i<100; i++) {
        niz_gr[i]=nullptr;
    }
    int br(0);
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    int broj_gradjana(0);
    cin >> broj_gradjana;
    for (int i=0; i<broj_gradjana; i++) {
        std::string ime_i_prezime;
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        cin.ignore(1000, '\n');
        std::getline(cin, ime_i_prezime);
        cout << "Unesite JMBG: " << endl;
        long long int jmbg(0);
        cin >> std::ws >> jmbg;
        //cout << jmbg;
        try {
           niz_gr[br]=new GradjaninBiH(ime_i_prezime, jmbg);
           cout << "Unijeli ste gradjanina " <<  niz_gr[br]->DajImeIPrezime() << " rodjenog " << niz_gr[br]->DajDanRodjenja() << "." << niz_gr[br]->DajMjesecRodjenja() << "." <<
           niz_gr[br]->DajGodinuRodjenja() << " u regiji " << niz_gr[br]->DajSifruRegije() << ", ";
           if (niz_gr[br]->DajPol()==0) cout << "musko." << endl;
           else cout << "zensko." << endl;
           br++;
        }
        catch (std::logic_error izuzetak) {
           cout << izuzetak.what() << endl;
           i--;
        }
    }
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << endl;
    int broj_gr(0);
    cin >> broj_gr;
    for (int i=0; i<broj_gr; i++) {
        std::string ime_i_prezime;
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        cin.ignore(1000, '\n');
        std::getline(cin, ime_i_prezime);
        //cout << "Ime: " << ime_i_prezime;
        cout << "Unesite datum rodjenja (format dd/mm/gggg): " << endl;
        int d, m, god;
        char znak1, znak2;
        cin >> std::ws >> d >> znak1 >> m >> znak2 >> god;
        cout << "Unesite sifru regije: " << endl;
        int sifra;
        cin >> sifra;
        cout << "Unesite M za musko, Z za zensko: " << endl;
        char pol; int pol_i;
        cin >> pol;
        if (pol=='Z') { pol_i=1; }
        else {pol_i=0; }
        try {
            niz_gr[br]=new GradjaninBiH(ime_i_prezime, d, m, god, sifra, GradjaninBiH::Pol(pol_i)); //auto konverzija u pol?
            cout << "Unijeli ste gradjanina " << niz_gr[br]->DajImeIPrezime() << " JMBG: " << niz_gr[br]->DajJMBG() << "." << endl;
            br++;
        }
        catch (std::logic_error iz) {
            cout << iz.what() << endl;
            i--;
        }
    }
    for (int i=0; i<100; i++) {
        delete niz_gr[i];
    }
	return 0;
}