#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <cmath>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int d, int m, int g) { Postavi(d,m,g); }
    void Postavi(int d, int m, int g);
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina; }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
};
void Datum::Postavi(int d, int m, int g) {
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0  && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1 || m<1 || d<1 || m>12 || d>broj_dana[m-1])
        throw std::domain_error ("Neispravni podaci");
        dan=d; mjesec=m; godina=g;
}

class GradjaninBiH {
    public: enum Pol{Musko,Zensko};
   private:  std::string ime_i_prezime;
    long long int JMBG;
    Datum datum_rodjenja;
    int sifra_regije;
    Pol pol;
    GradjaninBiH *Prethodni=nullptr;
    static GradjaninBiH *Posljednji_kreirani;
    
    static std::unique_ptr<int[]> KreirajNiz(long long int n) {
        std::unique_ptr<int[]> niz(new int[13]);
        for(int i=12; i>=0; i--) {
            niz[i]=n%10;
            n/=10;
        }
        return niz;
    }
    
    static long long int KreirajJMBG(int d, int m, int g, int sifra, Pol pol, GradjaninBiH *gradjanin) {
        try { Datum dat(d,m,g); } catch(...) { throw std::logic_error ("JMBG nije validan"); }
        int kod_m(0), kod_z(500);
        ispocetka:
        int niz[13];
        niz[1]=d%10; niz[0]=(d/10)%10; niz[3]=m%10; niz[2]=(m/10)%10; //dan i mjesec
        niz[6]=g%10; niz[5]=(g/10)%10; niz[4]=(g/10/10)%10;             //godina
        niz[8]=sifra%10; niz[7]=(sifra/10)%10;                       //sifra
        if(pol==GradjaninBiH::Pol::Musko) {
        niz[9]=(kod_m/10/10)%10; niz[10]=(kod_m/10)%10; niz[11]=kod_m%10;  }                              //kod osobe - potrebna dopuna i provjera
        else {
        niz[9]=(kod_z/10/10)%10; niz[10]=(kod_z/10)%10; niz[11]=kod_z%10; }
        niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        
        if(niz[12]==11) niz[12]=0;
        else if(niz[12]==10) throw std::logic_error ("JMBG nije validan");
        long long int jmbg(0);
        for(int i=0; i<13; i++) {
            jmbg+=niz[i]*std::pow(10,12-i);
        }
       
        for(auto pom(Posljednji_kreirani); pom!=nullptr; pom=pom->Prethodni) {
            if(pom!=gradjanin && pom->DajJMBG()==jmbg) {
                kod_z++; kod_m++;
                goto ispocetka;
            }
        }
        return jmbg;
    }
    
    static int Nabavi(long long int jmbg, std::string sta) {
        std::unique_ptr<int[]> niz(KreirajNiz(jmbg));

        if(sta=="Dan") return niz[0]*10+niz[1];
        else if(sta=="Mjesec") return niz[2]*10+niz[3];
        else if(sta=="Godina") {
            if(niz[4]==0)
                return 2000+niz[4]*100+niz[5]*10+niz[6]; //Nije hardkodiranje, samo se iz zadnje 3 cifre godine rodjenja ne moze znati koji je milenij u pitanju
            else
               return 1000+niz[4]*100+niz[5]*10+niz[6]; 
        }
        else if(sta=="Sifra") return niz[7]*10+niz[8];
        else if(sta=="Pol") return niz[9]*100+niz[10]*10+niz[11];
        return 0;
    }
    
    public:
    
    
    GradjaninBiH &operator=(GradjaninBiH &g) =delete;
    GradjaninBiH(const GradjaninBiH &g) =delete;
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : datum_rodjenja(Nabavi(jmbg, "Dan"), Nabavi(jmbg, "Mjesec"), Nabavi(jmbg, "Godina")) {
          
          for(auto pom(Posljednji_kreirani); pom!=nullptr; pom=pom->Prethodni) {
              if(pom->DajJMBG()==jmbg) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
          }
              JMBG=jmbg;
              GradjaninBiH::ime_i_prezime=ime_i_prezime;
              sifra_regije=Nabavi(jmbg, "Sifra");
          
          int indikacija_pola(Nabavi(jmbg, "Pol"));
          if(indikacija_pola<500) pol=GradjaninBiH::Pol::Musko;
          else pol=GradjaninBiH::Pol::Zensko;
          
          if(Posljednji_kreirani!=nullptr) Prethodni=Posljednji_kreirani;
          else Prethodni=nullptr;
          Posljednji_kreirani=this;
      }
    
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) 
    : datum_rodjenja(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) {
          if(sifra_regije<0 || sifra_regije>99) throw std::logic_error ("Neispravni podaci");
           GradjaninBiH::sifra_regije=sifra_regije;
           GradjaninBiH::ime_i_prezime=ime_i_prezime;
           JMBG=(KreirajJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol, this));
           GradjaninBiH::pol=pol;
           
          if(Posljednji_kreirani==nullptr) Prethodni=nullptr;
          else if(Posljednji_kreirani!=nullptr)
            Prethodni=Posljednji_kreirani;
            
            Posljednji_kreirani=this;
      }
      
    ~GradjaninBiH();
    
    
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return JMBG; }
    int DajDanRodjenja() const { return datum_rodjenja.DajDan(); }
    int DajMjesecRodjenja() const { return datum_rodjenja.DajMjesec(); }
    int DajGodinuRodjenja() const { return datum_rodjenja.DajGodinu(); }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime=novo_ime; }

};

    GradjaninBiH* GradjaninBiH::Posljednji_kreirani=nullptr;
    
    GradjaninBiH::~GradjaninBiH() {
        if(Posljednji_kreirani==this) Posljednji_kreirani=this->Prethodni;
        
        for(auto pom(Posljednji_kreirani); pom!=nullptr ; pom=pom->Prethodni) {
            
            if (pom->Prethodni==this) {
            
                pom->Prethodni=this->Prethodni;
                break;
            }
        }
    }

int main ()
{
int n;

std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
std::cin>>n;

for(int i=0; i<n; i++) {
    std::cout<<"\nUnesite ime i prezime (u istom redu): ";
    std::string ime;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, ime);
    std::cout<<"\nUnesite JMBG: ";
    long long int br;
    std::cin>>br;
    try {
    GradjaninBiH g(ime,br);
    std::cout<<"\nUnijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<
    g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije()<<", ";
    if(g.DajPol()==0) std::cout<<"musko.";
    else std::cout<<"zensko.";
    }
    catch(std::domain_error) {
        std::cout<<"\nJMBG nije validan";
        i--;
    }
    catch(std::logic_error g) {
        std::cout<<g.what()<<std::endl;
        i--;
    }
    
}

std::cout<<"\nKoliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
std::cin>>n;
for(int i=0; i<n; i++) {
    std::cout<<"\nUnesite ime i prezime (u istom redu): ";
    std::string ime;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, ime);
    std::cout<<"\nUnesite datum rodjenja (format dd/mm/gggg): ";
    int d,m,god;
    std::cin>>d;
    std::cin.ignore(1);
    std::cin>>m;
    std::cin.ignore(1);
    std::cin>>god;
    std::cout<<"\nUnesite sifru regije: ";
    int sifra;
    std::cin>>sifra;
    std::cout<<"\nUnesite M za musko, Z za zensko: ";
    char pol;
    std::cin>>pol;
    GradjaninBiH::Pol p;
    if(pol=='M') p=GradjaninBiH::Pol::Musko;
    else if(pol=='Z') p=GradjaninBiH::Pol::Zensko;
    try {
        GradjaninBiH g(ime,d,m,god,sifra,p);
        std::cout<<"\nUnijeli ste gradjanina "<<g.DajImeIPrezime()<<" JMBG: "<<g.DajJMBG()<<".";
    }
    catch(std::logic_error g) {
        std::cout<<"\n"<<g.what();
        i--;
    }
    
}


	return 0;
}