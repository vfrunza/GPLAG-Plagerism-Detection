/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>



class GradjaninBiH{
std::string name;
long long int jmbg;
long long int *pok_na_prosli_jmbg = nullptr;
public:
enum Pol {Musko, Zensko};
bool DaLiJeValidanJMBG(long long int jmbg);
bool DaLiJeValidanDatum(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja);
int Formula_za_posljednji_broj(int dan, int mjesec, int godina, int sifra_regije, Pol pol);

GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
std::string DajImeIPrezime() const { return GradjaninBiH::name; }
long long int DajJMBG() const { return GradjaninBiH::jmbg;}
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;
void PromijeniImeIPrezime(std::string novo_ime) { GradjaninBiH::name = novo_ime; }
};

int GradjaninBiH::Formula_za_posljednji_broj(int dan, int mjesec, int godina, int sifra_regije, Pol pol){
    
    int niz[13];
    
    niz[0] = (dan / 10) % 10;
    niz[1] = dan % 10;
    niz[2] = (mjesec / 10) % 10;
    niz[3] = mjesec % 10;
    niz[4] = (godina/100)%10;
    niz[5] = (godina/10)%10;
    niz[6] = godina%10;
    niz[7] = (sifra_regije/10)%10;
    niz[8] =  sifra_regije%10;
    int kod; if(pol == Pol::Musko) kod = 0; if(pol == Pol::Zensko)kod = 500;
    niz[9] = (kod / 100)%10;
    niz[10] = (kod/10)%10;
    niz[11] = kod%10;
    
    return 11 - (7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11])) %11;
}

bool GradjaninBiH::DaLiJeValidanJMBG(long long int jmbg){
    
    long long int broj = jmbg;
    while(broj > 100)
        broj /= 10;
    int dan = (broj%10) + ((broj/10)%10) * 10;
    
    broj = jmbg;
    while(broj > 10000)
        broj /= 10;
    int mjesec = (broj%10) + ((broj/10)%10) * 10;
    
    broj = jmbg;
     while(broj > 10000000)
        broj /= 10;
    int godina = 1000 + (broj%10) + ((broj/10)%10) * 10 + ((broj/100)%10) * 100;
    
    broj = jmbg;
    while(broj > 1000000000)
        broj /= 10;
    int sifra = (broj%10) + ((broj/10)%10) * 10 ;
    
    broj = jmbg;
    broj /= 10;
    Pol pol;
    if( (broj%10) + ((broj/10)%10) * 10 + ((broj/100)%10) * 100 < 500) pol = Pol::Musko;
    else pol = Pol::Zensko;
    
    
    //if(DaLiJeValidanDatum(dan, mjesec, godina) == false) return false;
    if( (jmbg%10) == 0 && (Formula_za_posljednji_broj(dan, mjesec, godina, sifra, pol)) == 11) return true;
    else if( (jmbg%10) != (Formula_za_posljednji_broj(dan, mjesec, godina, sifra, pol)) || (Formula_za_posljednji_broj(dan, mjesec, godina, sifra, pol)) == 10) return false;
    return true;
}

bool GradjaninBiH::DaLiJeValidanDatum(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja){
    int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if((godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0) || godina_rodjenja % 400 == 0) broj_dana[1]++;
    if(godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > broj_dana[mjesec_rodjenja-1]) 
        return false;
        
    return true;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    if(pok_na_prosli_jmbg != nullptr){
        if(*pok_na_prosli_jmbg == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    if(DaLiJeValidanJMBG(jmbg) == false) throw std::logic_error("JMBG nije validan");
    GradjaninBiH::name = ime_i_prezime; GradjaninBiH::jmbg = jmbg;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(DaLiJeValidanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) == false) throw std::logic_error("Neispravni podaci");
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    
    GradjaninBiH::name = ime_i_prezime;
    int niz[13];
    
    niz[0] = (dan_rodjenja / 10) % 10;
    niz[1] = dan_rodjenja % 10;
    niz[2] = (mjesec_rodjenja / 10) % 10;
    niz[3] = mjesec_rodjenja % 10;
    niz[4] = (godina_rodjenja/100)%10;
    niz[5] = (godina_rodjenja/10)%10;
    niz[6] = godina_rodjenja%10;
    niz[7] = (sifra_regije/10)%10;
    niz[8] =  sifra_regije%10;
    
    int kod;
    if(pol == Pol::Musko) kod = 0;
    if(pol == Pol::Zensko)kod = 500;
    
    if(pok_na_prosli_jmbg != nullptr){
    int pomocni[13]; long long int temp = *pok_na_prosli_jmbg;
    for(int i=0; i<13; i++){
        pomocni[i] = temp%10;
        temp /= 10;
    }
    bool ista_regija(true);
    for(int i=0; i<9; i++){
        if(niz[i] != pomocni[i]){
            ista_regija = false;
            break;
        }
    }
    if(ista_regija) kod++;
    }
    
    niz[9] = (kod / 100)%10;
    niz[10] = (kod/10)%10;
    niz[11] = kod%10;
    niz[12] = 11 - (7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11])) %11;
    if(niz[12] == 11) niz[12] = 0;
    
    long long int k = 1; long long int JBG(0); int i = 12;
    while(i >= 0){
        JBG += k * niz[i];
        k *= 10;
        i--;
    }
    GradjaninBiH::jmbg= JBG;
}

int GradjaninBiH::DajDanRodjenja() const{
    long long int broj = GradjaninBiH::jmbg;
    while(broj > 100)
        broj /= 10;
    return (broj%10) + ((broj/10)%10) * 10;
}

int GradjaninBiH::DajMjesecRodjenja() const {
    long long int broj = GradjaninBiH::jmbg;
    while(broj > 10000)
        broj /= 10;
    return (broj%10) + ((broj/10)%10) * 10;
}

int GradjaninBiH::DajGodinuRodjenja() const {
    
    long long int broj = GradjaninBiH::jmbg;
    while(broj > 10000000)
        broj /= 10;
    int godina;
    if(((broj/100)%10) == 0) godina = 2000 + (broj%10) + ((broj/10)%10) * 10 + ((broj/100)%10) * 100;
    else godina = 1000 + (broj%10) + ((broj/10)%10) * 10 + ((broj/100)%10) * 100;
    return godina;
}

int GradjaninBiH::DajSifruRegije() const {
    
    long long int broj = GradjaninBiH::jmbg;
    while(broj > 1000000000)
        broj /= 10;
    return (broj%10) + ((broj/10)%10) * 10 ;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    
    long long int broj = GradjaninBiH::jmbg;
    broj /= 10;
    
    if( (broj%10) + ((broj/10)%10) * 10 + ((broj/100)%10) * 100 < 500) return Pol::Musko;
    return Pol::Zensko;
}

int main (){
    
    std::cout << "Koliko gradjana zelite unijeti po JMBG? "<< std::endl;
    int br1;
    std::cin >> br1;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    
    std::string ime;
    long long int jmbg;
    for(int i=0; i<br1; i++){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;  std::getline(std::cin, ime);
        std::cout << "Unesite JMBG: " << std::endl; std::cin >> jmbg;
        try{ 
            GradjaninBiH g1(ime, jmbg);
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unijeli ste gradjanina " << g1.DajImeIPrezime() << " rodjenog " << g1.DajDanRodjenja() << "." << g1.DajMjesecRodjenja() << "." << g1.DajGodinuRodjenja() << " u regiji " << g1.DajSifruRegije() << ", " ;
        if(g1.DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko." << std::endl;
        else std::cout << "zensko."<< std::endl;
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        
        ime.erase();
    }
    
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    int br2;
    std::cin >> br2;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::string ime_i_prezime;
    int dan, mjesec, god, sifra;
    char spol, gutac;
    GradjaninBiH::Pol pol;
    for(int i=0; i<br2; i++){
        std::cout << "Unesite ime i prezime (u istom redu): "<< std::endl; std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl; std::cin >> dan; std::cin >> gutac; std::cin >> mjesec; std::cin >> gutac; std::cin >> god;
        std::cout << "Unesite sifru regije: " << std::endl; std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: "<< std::endl; std::cin >> spol; if(spol == 'M') pol = GradjaninBiH::Pol::Musko; if(spol == 'Z') pol = GradjaninBiH::Pol::Zensko;
        try{
            auto g2 = GradjaninBiH(ime_i_prezime, dan, mjesec, god, sifra, pol);
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unijeli ste gradjanina " << g2.DajImeIPrezime() << " JMBG: " << g2.DajJMBG() << "." << std::endl; 
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        
    }
    
	return 0;
}