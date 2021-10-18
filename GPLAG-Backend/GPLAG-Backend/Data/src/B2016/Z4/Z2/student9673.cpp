/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <new>

using std::cin;
using std::cout;
using std::endl;

struct Datum {
    int dan = 0, mjesec = 0, godina = 0;
                                                                                // prekopirano sa predavanja 9_a
    void Postavi(int d, int m, int g);
    int DajDan(){ return dan; };
    int DajMjesec(){ return mjesec; };
    int DajGodinu(){ return godina; };
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 and godina % 100 != 0) or godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 or dan < 1 or mjesec < 1 or mjesec > 12 or dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

int Cifra13(int c[]){
    return 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))% 11;
}


class GradjaninBiH{
    std::string ime_i_prezime;
    int jmbg[13]{}, sifra_regije;                                               // uvijek broji od 1  - > c1 = jmbg[0] !!!
    Datum dat_rodjenja;
    
public:
    static GradjaninBiH* zadnji;
    GradjaninBiH *prosli = nullptr;                                                         // veza u listi
    enum Pol {Musko, Zensko} pol;

    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol);                                                // konstruktori i 
    GradjaninBiH(const GradjaninBiH &g) =delete;                                                        // zabrana na dodjelu/ kopiranje
    GradjaninBiH &operator=(const GradjaninBiH &g) =delete;                                                     
    ~GradjaninBiH();                                                                                    // destruktor            

    std::string DajImeIPrezime() const{ return ime_i_prezime; }
    int DajDanRodjenja() const { return dat_rodjenja.dan; }
    int DajMjesecRodjenja() const { return dat_rodjenja.mjesec;}
    int DajGodinuRodjenja() const { return dat_rodjenja.godina; }
    int DajSifruRegije() const { return sifra_regije; }
    long long int DajJMBG() const;
    Pol DajPol() const { return pol;}
    void PromijeniImeIPrezime(std::string novo_ime){ ime_i_prezime = novo_ime; }
};

GradjaninBiH* GradjaninBiH::zadnji = nullptr;               // inicijalizacija staticke varijable klase

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    for(auto p = zadnji; p != nullptr; p = p -> prosli)
        if(p -> DajJMBG() == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    
    this -> ime_i_prezime = ime_i_prezime;
    
    int i(0);
    while(jmbg != 0){
        this -> jmbg[12-i] = jmbg%10;
        jmbg/=10;
        i++;
    }

    int dan (this -> jmbg[0] * 10 + this -> jmbg[1]);
    int mjesec (this -> jmbg[2] * 10 + this -> jmbg[3]);
    int godina (this -> jmbg[4] * 100 + this -> jmbg[5] * 10 + this -> jmbg[6]);

    if(this -> jmbg[4] == 0) godina += 2000;
    else godina += 1000;
    if(godina > 2017) throw std::logic_error("JMBG nije validan");

    try{
        dat_rodjenja.Postavi(dan, mjesec, godina);
    }
    catch(std::domain_error e){
        throw std::logic_error("JMBG nije validan");
    }
    int c13(Cifra13(this -> jmbg));
    if(c13 == 11) c13 = 0;
    if(c13 == 10 || c13 != this -> jmbg[12]) throw std::logic_error("JMBG nije validan");

    sifra_regije = this -> jmbg[7] * 10 + this -> jmbg[8];

    int za_pol(this -> jmbg[9] * 100 + this -> jmbg[10] * 10 + this -> jmbg[11]);
    if(za_pol <= 499) pol = Musko;
    else pol = Zensko;
    
    prosli = zadnji;
    zadnji = this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    try{
        dat_rodjenja.Postavi(dan_rodjenja, mjesec_rodjenja, godina_rodjenja);
    }
    catch(std::domain_error e){
        throw std::logic_error("Neispravni podaci");
    }
    if(sifra_regije < 0 or sifra_regije > 99 or godina_rodjenja > 2017 or godina_rodjenja < 1917) throw std::logic_error("Neispravni podaci");
    
    jmbg[0] = dan_rodjenja/10; jmbg[1] = dan_rodjenja%10; jmbg[2] = mjesec_rodjenja/10; jmbg[3] = mjesec_rodjenja%10;
    jmbg[6] = godina_rodjenja%10; godina_rodjenja /= 10;  jmbg[5] = godina_rodjenja%10; godina_rodjenja /= 10; jmbg[4] = godina_rodjenja%10;    // obradi datum
    jmbg[7] = sifra_regije/10;   jmbg[8] = sifra_regije%10;                                                                                     // sifra regije
    if(pol == Musko) jmbg[9] = 0, jmbg[10] = 0, jmbg[11] = 0;
    else jmbg[9] = 5, jmbg[10] = 0, jmbg[11] = 0;       // pol
    
    jmbg[12] = 11 - (7*(jmbg[0]+jmbg[6]) + 6*(jmbg[1]+jmbg[7]) + 5*(jmbg[2]+jmbg[8]) + 4*(jmbg[3]+jmbg[9]) + 3*jmbg[4]+jmbg[10] + 2*(jmbg[5]+jmbg[11]))% 11;
    if(jmbg[12] == 11) jmbg[12] = 0;
    
    
    for(auto p = zadnji; p != nullptr; p = p -> prosli){
        if(pol == p -> DajPol() and sifra_regije == p -> DajSifruRegije() and dan_rodjenja == p -> DajDanRodjenja()
            and mjesec_rodjenja == p -> DajMjesecRodjenja() and godina_rodjenja == p -> DajDanRodjenja()){
            jmbg[12] = p -> jmbg[12] + 1;
            if(jmbg[12] == 10) jmbg[12] = 0;                                                                            // c13 JMBG
        }
    }
    
    this -> sifra_regije = sifra_regije;
    this -> pol = pol;
    this -> ime_i_prezime = ime_i_prezime;
    
    prosli = zadnji;                                                                                                // azuriranje pokazivaca
    zadnji = this;                                                                                                  // povezane liste
}

GradjaninBiH::~GradjaninBiH(){
    auto p(zadnji);
    if(p == this) zadnji = this -> prosli;
    
    if(this -> prosli == nullptr) {
        while(p -> prosli != this && p -> prosli != nullptr) p = p -> prosli;
        p -> prosli = nullptr;
    }
    
    else{ 
        while(p != nullptr){
            if(p -> prosli == this) p -> prosli = this -> prosli; 
            p = p -> prosli;
        }
    }
}

long long int GradjaninBiH::DajJMBG() const {
    long long int broj(0);
    
    for(int i = 0; i < 13; i++){
        broj *= 10;
        broj += jmbg[i];
    }
    return broj;
}

int main(){
    int n(0), m(0), i(0), brojac(0);
    
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    cin >> n;
    cin.ignore(1000, '\n');

    GradjaninBiH** pok = new GradjaninBiH*[n]{};
    
    while(i != n ){
        std::string i_i_p("");
        long long int jmbg(0);
        
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        std::getline(std::cin, i_i_p);
        cout << "Unesite JMBG: " << endl;
        cin >> jmbg;
        cin.ignore(1000, '\n');
        
        try{
            pok[brojac] = new GradjaninBiH(i_i_p, jmbg);

            cout << "Unijeli ste gradjanina " << pok[brojac] -> DajImeIPrezime() << " rodjenog " << pok[brojac] -> DajDanRodjenja() << "." << pok[brojac] -> DajMjesecRodjenja()
            << "." << pok[brojac] -> DajGodinuRodjenja() << " u regiji " << pok[brojac] -> DajSifruRegije() << ", ";
            auto pol(pok[brojac] -> DajPol());
            if(pol == GradjaninBiH::Musko) cout << "musko." << endl;
            else cout << "zensko." << endl;
            
            brojac++;
            i++;
        }
        catch(std::logic_error e){
            cout << e.what() << endl;
        }
        catch(std::bad_alloc){
            for(int i = 0; i < n; i++) delete pok[i];
            delete[] pok;
            return 0;
        }
    }
    
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << endl;
    cin >> m;
    
    GradjaninBiH **p;
    try{
        p = new GradjaninBiH* [n+m]{};
        for(int i = 0; i < n; i++) p[i] = pok[i];
    }
    catch(...){
        delete[] p;
        delete[] pok;
        p[0] -> ~GradjaninBiH();
        return 0;
    }
                                                                                        // alociraj novi  - > stari nema dovoljno kapaciteta
    cin.ignore(1000, '\n');
    
    i = 0;
    while(i != m){
        std::string i_i_p("");
        int d(0), m(0), g(0), sifra(0);
        char znak, pol;
        
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        std::getline(std::cin, i_i_p);
        
        cout << "Unesite datum rodjenja (format dd/mm/gggg): " << endl;
        cin >> d >> znak >> m >> znak >> g;
        
        cout << "Unesite sifru regije: " << endl;
        cin >> sifra;
        
        cout << "Unesite M za musko, Z za zensko: " << endl;
        cin >> pol;
        
        try{
            if(pol == 'M'){
                p[brojac] = new GradjaninBiH (i_i_p, d, m, g, sifra, GradjaninBiH::Musko);
                cout << "Unijeli ste gradjanina " << p[brojac] -> DajImeIPrezime() << " JMBG: " << p[brojac] -> DajJMBG() << "." << endl;
            }
            else if(pol == 'Z'){
                p[brojac] = new GradjaninBiH (i_i_p, d, m, g, sifra, GradjaninBiH::Zensko);
                cout << "Unijeli ste gradjanina " <<  p[brojac] -> DajImeIPrezime() << " JMBG: " << p[brojac] -> DajJMBG() << "." << endl; 
            }
            i++; 
            brojac++;
        }
        catch(std::logic_error e){
            cout << e.what() << endl;
        }
        catch(std::bad_alloc){
            p[0] -> ~GradjaninBiH();
            delete []p;
            delete []pok;
        }
        cin.ignore(1000, '\n');
    }
    delete []p;
    delete []pok;
    return 0;
} 