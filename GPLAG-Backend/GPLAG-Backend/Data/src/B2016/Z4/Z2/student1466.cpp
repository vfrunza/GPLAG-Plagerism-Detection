#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    
std::string ime; 
long long int broj=0;
GradjaninBiH *pok{};   
static GradjaninBiH *zad;
public: 
enum Pol {Musko, Zensko};


GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {

auto pom(jmbg);
int zadnji = pom % 10;
pom = pom / 10;
int kod = (pom % 10);
pom = pom / 10;
kod+= (pom % 10)*10;
pom = pom / 10;
kod+=(pom % 10)*100;

pom = pom / 10;
int sifra = pom % 10;
pom = pom / 10;
sifra += (pom % 10)*10;

if (sifra < 0 or sifra > 99) throw std::logic_error("JMBG nije validan");

pom = pom / 10;

int godina = (pom % 10);
pom = pom / 10;
godina+= (pom % 10)*10;
pom = pom / 10;
godina+=(pom % 10)*100;

if(godina > 900) { int godina1=godina+1000; if (godina1 < 1916) throw std::logic_error("JMBG nije validan");}
else  {int godina1 =godina + 2000; if (godina1 > 2017) throw std::logic_error("JMBG nije validan"); }

pom = pom/10;
int mjesec = pom % 10;
pom = pom / 10;
mjesec+=(pom%10)*10;

if( mjesec > 12 or mjesec < 1) throw std::logic_error("JMBG nije validan");

pom = pom/10;
int dan = pom % 10;
pom = pom / 10;
dan+=(pom%10)*10;

if (dan > 31 or dan < 1)  throw std::logic_error("JMBG nije validan");

int zadnjib = 11 - ( 7*(dan/10 + godina%10) + 6* (dan%10 + sifra/10) + 5* (mjesec/10 + sifra%10) + 4* (mjesec%10 + kod/100) + 3* (godina/100 + (kod/10)%10) + 2*((godina/10)%10 + kod%10)) % 11;
if (zadnjib==11) zadnjib=0;

if ( zadnji != zadnjib or zadnjib==10) throw std::logic_error("JMBG nije validan");
ime = ime_i_prezime;   
broj = jmbg;
    

    auto pomocni(pok);

while (pomocni != nullptr ) {
if (pomocni->broj == jmbg)  throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
pomocni=pomocni->pok;
}
    pok = zad;

  zad = this;
  

}

GradjaninBiH(const GradjaninBiH &g) = delete;

GradjaninBiH &operator = (const GradjaninBiH &g) = delete;


GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) { 

    ime = ime_i_prezime;
    
    
    broj+=dan_rodjenja;
    broj*=100;
    broj+=mjesec_rodjenja;
    broj*=1000;
    broj+=(godina_rodjenja%1000);
    broj*=100;
    broj+=sifra_regije;
    broj*=1000;
    if (pol == Zensko) broj+=500;
        if (pol == Musko) broj+=0;
        auto dan=dan_rodjenja;
        auto godina=godina_rodjenja;
        auto mjesec= mjesec_rodjenja;
        int kod;
        auto sifra=sifra_regije;
        if (pol == Musko ) kod=0;
        else kod=500;

    int zadnjib = 11 - ( 7*(dan_rodjenja/10 + godina%10) + 6* (dan%10 + sifra/10) + 5* (mjesec_rodjenja/10 + sifra_regije%10) + 4* (mjesec%10 + kod/100) + 3* (godina/100 + (kod/10)%10) + 2*((godina/10)%10 + kod%10)) % 11;
if (zadnjib==11) zadnjib=0;
    
       broj*=10;
   broj+=0;
   


   auto pomocni(pok);

while (pomocni != nullptr ) {
if (broj == pomocni->broj) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
pomocni=pomocni->pok;
}
  pok = zad;
  zad = this;
   
}
std::string DajImeIPrezime() const { return ime; }
long long int DajJMBG() const { return broj; }

int DajDanRodjenja() const { return (broj / 100000000000); }
int DajMjesecRodjenja() const {  int g=broj / 1000000000;  return g%100; }
int DajGodinuRodjenja() const {  int g=broj / 1000000; if (g%1000 > 900 ) return (1000+g%1000); else return (2000+g%1000); }
int DajSifruRegije() const { int g=broj / 10000; return g%100; }
Pol DajPol() const { if(((broj/10)%1000) >= 500) return Zensko; else return Musko; } 

void PromijeniImeIPrezime(std::string novo_ime) {
    
  ime=novo_ime; 
}

};
GradjaninBiH *GradjaninBiH::zad{};

int main ()
{
     std::cout<<"Koliko gradjana zelite unijeti po JMBG?"<<std::endl;
     int n;
     std::cin>>n;
GradjaninBiH *gradjani[100];

for (int i = 0; i < n; i++) {
    
    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::string ime;
    std::getline(std::cin,ime);
    long long int br;
    std::cout<<"Unesite JMBG: "<<std::endl;
    std::cin>>br;
    try {
        
        GradjaninBiH novi(ime,br);
        gradjani[i] = &novi;
        std::cout<<"Unijeli ste gradjanina "<< gradjani[i]->DajImeIPrezime() << " rodjenog "<<gradjani[i]->DajDanRodjenja()<<"."<<gradjani[i]->DajMjesecRodjenja()<<".";
        std::cout<<gradjani[i]->DajGodinuRodjenja()<<" u regiji "<<gradjani[i]->DajSifruRegije()<<", ";
        if(gradjani[i]->DajPol()==0) std::cout<<"musko.";
        else std::cout<<"zensko.";
        std::cout<<std::endl;
        
    }
 catch(std::logic_error e) {
    
    std::cout<<e.what()<<std::endl;
    i--;

     
 }   
    
}

std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?"<<std::endl;

     int b;
     std::cin>>b;


for (int i = 0; i < n; i++) {

    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::string ime;
    std::getline(std::cin,ime);
    int br;
    std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
    int dan,mjesec,godina;
    std::cin>>dan>>mjesec>>godina;
    std::cout<<"Unesite sifru regije: "<<std::endl;
    std::cin>>br;
    
    std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
    char pol;
    std::cin>>pol;
    
    try {
        

       GradjaninBiH novi(ime,dan,mjesec,godina,br,GradjaninBiH::Zensko);

        gradjani[i] = &novi;
        std::cout<<"Unijeli ste gradjanina "<< gradjani[i]->DajImeIPrezime() << " JMBG: "<< gradjani[i]->DajJMBG();

        std::cout<<std::endl;
        
    }
 catch(std::logic_error e) {
    
    std::cout<<e.what()<<std::endl;
    i--;

     
 }   
    
}


	return 0;
}