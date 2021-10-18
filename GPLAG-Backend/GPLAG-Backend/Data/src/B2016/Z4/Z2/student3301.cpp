/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>

class GradjaninBiH{
  std::string ime_i_prezime;
  long long int jmbg;
  GradjaninBiH *prethodni;
  static GradjaninBiH *posljednji ;
  static int brojac;
  
  static bool IspravanDatum(long long int jmbg);
  static bool Datum (int dan, int mjesec, int godina);
  static int DajKod (long long int jmbg);
  public:
   enum Pol {Musko, Zensko};
   GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
   GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
   std::string DajImeIPrezime() const {return ime_i_prezime;}
   long long int DajJMBG()const{return jmbg ;}
   int DajDanRodjenja() const ;
   int DajMjesecRodjenja() const;
   int DajGodinuRodjenja() const;
   int DajSifruRegije() const ;
   Pol DajPol() const ;
   void PromijeniImeIPrezime (std::string novo_ime) {ime_i_prezime = novo_ime;}
   GradjaninBiH (const GradjaninBiH &gr) = delete;
   GradjaninBiH operator=(const GradjaninBiH &gr) = delete;
   ~GradjaninBiH(){
       if(this==posljednji)
         GradjaninBiH::posljednji=GradjaninBiH::posljednji->prethodni;
       else if(this->prethodni==nullptr){
         GradjaninBiH *q;
         for(q=GradjaninBiH::posljednji; q->prethodni!=this; q=q->prethodni);
        q->prethodni = nullptr;
           
       }
       else{
           GradjaninBiH *q;
           for(q = GradjaninBiH::posljednji; q->prethodni!=this; q=q->prethodni);
           q->prethodni = this->prethodni;
       }
   }
    
};



GradjaninBiH *GradjaninBiH::posljednji = nullptr;
int GradjaninBiH::brojac = 0;



bool GradjaninBiH::Datum(int dan, int mjesec, int godina){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
      broj_dana[1]++;
    if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
      return false;
    return true;
}


bool GradjaninBiH::IspravanDatum (long long int jmbg){
    long long int a(jmbg);
    int brojac(0);
    while(a!=0){
        a/=10;
        brojac++;
    }
   if(brojac>13 || brojac<0)
      return false;
    int niz[13];
    a = jmbg;
    for(int i=12; i>=0; i--){
        niz[i] = a%10;
        a/=10;
    }
    int dan(0), mjesec(0) , godina(0);
    dan = niz[0]*10 + niz[1];
    mjesec = niz[2]*10 + niz[3];
    godina = niz[4]*100 + niz[5]*10 + niz[6];
    if(godina>17)
      godina+=1000;
    else
      godina+=2000;
    if(Datum(dan, mjesec, godina))
      return true;
    
    return false;
    
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg){
    if(!GradjaninBiH::IspravanDatum(jmbg))
       throw std::logic_error("JMBG nije validan");
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::jmbg = jmbg;
    long long int a(jmbg);
    int c[13];
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    
    int izraz(0);
    izraz+=(11 - (7*(c[0] + c[6]) + 6*(c[1] + c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) + 3*(c[4] + c[10]) + 2*(c[5] + c[11]))%11);
    if(izraz==11)
      izraz = 0;
    if(c[12]!=izraz || izraz==10)
      throw std::logic_error("JMBG nije validan");
  if(GradjaninBiH::brojac!=0)
    prethodni = GradjaninBiH::posljednji;
   else
     prethodni = nullptr;
   GradjaninBiH::posljednji = this;
   for(auto q = GradjaninBiH::posljednji->prethodni; q!=nullptr; q = q->prethodni)
     if(q->jmbg == GradjaninBiH::jmbg){
         GradjaninBiH::posljednji = prethodni;
         prethodni = nullptr;
         throw std::logic_error("Vec postoji gradjanin s istim JMBG");
     }

   GradjaninBiH::brojac++;
  
}


int GradjaninBiH::DajKod(long long int jmbg){
    int c[13];
    auto a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    int kod(c[9]*100 + c[10]*10 + c[11]);
    return kod;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja,int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!GradjaninBiH::Datum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || !(sifra_regije>=0 && sifra_regije<=99))
      throw std::logic_error("Neispravni podaci");
    int min_kod(0);
    if(pol==Pol::Zensko)
      min_kod = 500;
     
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    
    if(brojac!=0)
      prethodni = GradjaninBiH::posljednji;
    else
      prethodni = nullptr;
   GradjaninBiH::posljednji = this;
    long long int JMBG(0);
    if(prethodni){
      
    for(auto q =GradjaninBiH::posljednji->prethodni; q!=nullptr; q=q->prethodni ){
        
        if(q->DajKod(q->DajJMBG())>min_kod && q->DajPol()==pol)
          min_kod = q->DajKod(q->jmbg);
          std::cout<<min_kod;
    }
    }
    if(min_kod!=0 && min_kod!=500)
      min_kod++;
    int niz[13];
    niz[1] = dan_rodjenja%10;
    dan_rodjenja/=10;
    niz[0] = dan_rodjenja%10;
    niz[3] = mjesec_rodjenja%10;
    mjesec_rodjenja/=10;
    niz[2] = mjesec_rodjenja%10;
    niz[6] = godina_rodjenja%10;
    godina_rodjenja/=10;
    niz[5] = godina_rodjenja%10;
    godina_rodjenja/=10;
    niz[4] = godina_rodjenja%10;
    niz[8] = sifra_regije%10;
    sifra_regije/=10;
    niz[7] = sifra_regije%10;
    niz[11] = min_kod%10;
    min_kod/=10;
    niz[10] = min_kod%10;
    min_kod/=10;
    niz[9] = min_kod%10;
    niz[12] = 11 - ((7*(niz[0] + niz[6]) + 6*(niz[1] + niz[7]) + 5*(niz[2] + niz[8]) + 4*(niz[3] + niz[9]) + 3*(niz[4]+ niz[10]) + 2*(niz[5] + niz[11]))%11);
    if(niz[12]==11)
      niz[12] = 0;
    
    long long int k(1);
    

    for(int i=12; i>=0; i--){
        
        JMBG+=(niz[i]*k);
        k*=10;
    }
    GradjaninBiH::jmbg = JMBG;
    brojac++;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    int c[13];
    long long int a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    int b(0);
    b+=c[9]*100 + c[10]*10 + c[11];
    if(b>=0 && b<=499)
      return Pol::Musko;
    else 
      return Pol::Zensko;
    
}

int GradjaninBiH::DajSifruRegije() const {
    int c[13];
    long long int a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    return (c[7]*10 + c[8]);
    
}

int GradjaninBiH::DajDanRodjenja()const {
    int c[13];
    long long int a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    return (c[0]*10 + c[1]);
}

int GradjaninBiH::DajMjesecRodjenja() const{
    int c[13];
    long long int a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    return (c[2]*10 + c[3]);
}

int GradjaninBiH::DajGodinuRodjenja()const {
    int c[13];
    long long int a(jmbg);
    for(int i=12; i>=0; i--){
        c[i] = a%10;
        a/=10;
    }
    int godina(0);
    godina+=(c[4]*100 + c[5]*10 + c[6]);
    if(godina>17)
      godina+=1000;
    else
      godina+=2000;
    return godina;
}
int main ()
{
   GradjaninBiH *niz[100];
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    std::cin>>n;
    for(int i=0; i<n; i++){
        try{
        std::cout<<"\nUnesite ime i prezime (u istom redu): ";
        std::string ime_i_prezime;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, ime_i_prezime);
        long long int jmbg;
        std::cout<<"\nUnesite JMBG: ";
        std::cin>>jmbg;
        GradjaninBiH gr(ime_i_prezime, jmbg);
        
        niz[i] = &gr;
        std::cout<<"\nUnijeli ste gradjanina "<<gr.DajImeIPrezime()<<" rodjenog "<<gr.DajDanRodjenja()<<"."<<gr.DajMjesecRodjenja()<<"."<<gr.DajGodinuRodjenja()<<" u regiji "<<gr.DajSifruRegije()<<", ";
        if(gr.DajPol()==GradjaninBiH::Pol::Musko)
          std::cout<<"musko.";
        else 
          std::cout<<"zensko.";
        }
        catch(std::logic_error e){
            std::cout<<"\n"<<e.what();
            i--;
        }
        catch(...){
            std::cout<<"Neispravni podaci";
            i--;
        }
    }
    
    int m;
    std::cout<<"\nKoliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin>>m;
    for(int i=0; i<m; i++){
        try{
        std::string ime_i_prezime;
        std::cout<<"\nUnesite ime i prezime (u istom redu): ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, ime_i_prezime);
        int d, m, g;
        char znak1, znak2;
        std::cout<<"\nUnesite datum rodjenja (format dd/mm/gggg): ";
        std::cin>>d>>znak1>>m>>znak2>>g;
        int sifra_regije;
        std::cout<<"\nUnesite sifru regije: ";
        std::cin>>sifra_regije;
        char znak;
        std::cout<<"\nUnesite M za musko, Z za zensko: ";
        std::cin>>znak;
        if(znak=='M'){
          GradjaninBiH gr1(ime_i_prezime, d, m, g, sifra_regije, GradjaninBiH::Pol::Musko);
          std::cout<<"\nUnijeli ste gradjanina "<<gr1.DajImeIPrezime()<<" JMBG: "<<gr1.DajJMBG()<<".";
          niz[i+n] = &gr1;
        }
        else if(znak=='Z'){
            GradjaninBiH gr2(ime_i_prezime, d, m, g, sifra_regije, GradjaninBiH::Pol::Zensko);
            std::cout<<"\nUnijeli ste gradjanina "<<gr2.DajImeIPrezime()<<" JMBG: "<<gr2.DajJMBG()<<".";
        
         niz[i+n] = &gr2;       
        }
        }
        catch(...){
            std::cout<<"\nNeispravni podaci";
            i--;
        }
    }
    
	return 0;
}