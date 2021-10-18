/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

int polM = 0;
int polZ = 500;
int brKreiranih = 0;




class GradjaninBiH {
    public :  enum Pol {Musko, Zensko};
    private:
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    GradjaninBiH *posljednji = nullptr;
    static  GradjaninBiH *zadnji;
   
    void provjeraJMBG(long long int jmbg);
    static int duzinaJMBG(long long int jmbg) {
                                                      //DUZINA JMBG
       int duzina = 0;
      
       while (jmbg) {
           duzina++;
           jmbg /= 10;
       }
       return duzina;
   }
    
    static long long int preokreniJMBG(long long int jmbg) {  long long int preokrenut = 0;
       int cifra = 0;
       
       while (jmbg) {
           cifra = jmbg%10;
           preokrenut *= 10;
           preokrenut += cifra;
           jmbg /= 10;
       }
       return preokrenut;
   }
    static int cifraNaPoziciji(long long int jmbg, int pozicija) {  int brojac = 0;
        int cifra = 0;
        while (true) {
            brojac++;
            cifra = jmbg%10;
            if(brojac == pozicija) break;
            jmbg /= 10;
        }
        
        return cifra;
    }
      
    bool provjeraDatuma(int d, int m, int g);
    void izJmbgIzvadiOstalo(long long int jmbg);
    long long int napraviJMBG(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, int pol);
    int tlinest(long long int jmbg,bool jel);
    
    public:
   
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};



  
       
   
   
   bool GradjaninBiH::provjeraDatuma(int d, int m, int g) {                                               // PROVJERA DATUMA
       int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
       if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
       return true;
   }
   
   
   void GradjaninBiH::izJmbgIzvadiOstalo(long long int jmbg) {                                                           //POSTAVKA AT IZ JMBG
       int duzina = GradjaninBiH::duzinaJMBG(jmbg);
       bool jel = true;
       int d = 0, m = 0, g = 1, sif = 0,cifra = 0,poly = 0;
       int g1 = 3, g2 = 2, g3 = 5, g4 = 4, g5 = 8, g6 = 7, g7 = 10;
       int g8 = 9, g9 = 13;
             
           
       
      
     
       jmbg = GradjaninBiH::preokreniJMBG(jmbg);
       if(duzina == 12) {
           --g1;
           --g2;
           --g3;
           --g4;
           --g5;
           --g6;
           --g7;
           --g8;
           --g9;
           
       }
       for(int i = 1; i <= duzina; i++) {
           cifra = jmbg%10;
           if( i < g1) { d *= 10;
            d += cifra;
           }
           else if(i > g2 && i < g3) { m *= 10;
           m += cifra;
           }
           else if( i > g4 && i < g5) {
               if(cifra == 0  && jel) { g = 2; jel = false; }
               g *= 10;
               g += cifra;
           }
           else if( i > g6 && i < g7) {
               sif *= 10;
               sif += cifra;
           }else if( i >g8 && i < g9) {
               poly *= 10;
               poly += cifra;
           
           }
           
           jmbg /= 10;
       }
       
        if( poly >= 500 && poly <= 999) GradjaninBiH::pol = GradjaninBiH::Pol::Zensko;
        else GradjaninBiH::pol = GradjaninBiH::Pol::Musko;
       GradjaninBiH::dan_rodjenja = d;
       GradjaninBiH::mjesec_rodjenja = m;
       GradjaninBiH::godina_rodjenja = g;
       GradjaninBiH::sifra_regije = sif;
       
   }
   
   
   long long int GradjaninBiH::napraviJMBG(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, int pol) {            // NAPRAVIT JMBG IZ OSTALIH
       int trenutno = 0,br =0,cifra =0;
        long long int jmbg  = 0;
       bool da = false;
       int po  = 0;
       if( pol == 0) po = polM;
       else po = polZ;
       
       for(int i = 0; i < 5; i++) {
           if( i == 0) trenutno = po;
           else if( i == 1) trenutno = sifra_regije;
           else if ( i == 2) { trenutno = godina_rodjenja;  }
           else if (i == 3) trenutno = mjesec_rodjenja;
           else if (i == 4) trenutno = dan_rodjenja;
       
       while (true) {
        if(trenutno == mjesec_rodjenja && mjesec_rodjenja < 10){
            jmbg *=  10;
            jmbg += mjesec_rodjenja;
            jmbg *= 10;
            break;
        }   
           
       else if(trenutno == po && pol == 0) {
           if(po < 10) {
              if(po%10 == 0) jmbg = 1;
              jmbg *=10;
              jmbg += po;
              
               jmbg*=10;
               jmbg *= 10;
              
               
           }
           else if(po < 100) {
               jmbg *= 10;
               jmbg += po;
               jmbg *= 10;
              
               
           }else {  
               while (trenutno) {
                   if(po%10 == 0) jmbg = 1;
                   jmbg *= 10;
                   jmbg += (trenutno%10);
                   
               }
               }
           break;
       }
      else if(trenutno == godina_rodjenja) {
           while (true) {
               br++;
               if(br == 4) break;
           cifra = trenutno%10;
           jmbg *= 10;
           jmbg += cifra;
           trenutno/=10;
       }
       break;
      }
       else {
           if(po%10 == 0 && trenutno == po) { jmbg = 1; da = true; }
           while(trenutno) {
          
           cifra = trenutno%10;
           jmbg *= 10;
            if(cifra == 0 && trenutno!= po) jmbg*=10;
           jmbg += cifra;
           trenutno /= 10;
       }
       
       break;
      }
       }
       }
      
       
       int t = GradjaninBiH::tlinest(jmbg,true);
       //trebal bacat sta
      jmbg = GradjaninBiH::preokreniJMBG(jmbg);
      if(po%10 == 0) {jmbg/=10; }
      if(da) jmbg/=10;
       jmbg*=10;
       jmbg += t;
       
    
      
       return jmbg;
       
   
   }
   
   
   int GradjaninBiH::tlinest(long long int jmbg,bool jel) {                                                                        //ODREDIT C13
        int duzina = GradjaninBiH::duzinaJMBG(jmbg),tlinest = 0;
        
        
       
       if(   jel || duzina == 13) {
       tlinest = 11- ( 7*(GradjaninBiH::cifraNaPoziciji(jmbg,1) + GradjaninBiH::cifraNaPoziciji(jmbg,7) ) + 6*( GradjaninBiH::cifraNaPoziciji(jmbg,2) + GradjaninBiH::cifraNaPoziciji(jmbg,8) ) + 5*( GradjaninBiH::cifraNaPoziciji(jmbg,3) + GradjaninBiH::cifraNaPoziciji(jmbg,9) ) +  4*( GradjaninBiH::cifraNaPoziciji(jmbg,4) + GradjaninBiH::cifraNaPoziciji(jmbg,10) ) + 3*( GradjaninBiH::cifraNaPoziciji(jmbg,5) + GradjaninBiH::cifraNaPoziciji(jmbg,11) ) + 2*(GradjaninBiH::cifraNaPoziciji(jmbg,6) + GradjaninBiH::cifraNaPoziciji(jmbg,12) ))%11; 
       
      

       }else {
       tlinest = 11- ( 7*GradjaninBiH::cifraNaPoziciji(jmbg,6)  + 6*( GradjaninBiH::cifraNaPoziciji(jmbg,1) + GradjaninBiH::cifraNaPoziciji(jmbg,7) ) + 5*( GradjaninBiH::cifraNaPoziciji(jmbg,2) + GradjaninBiH::cifraNaPoziciji(jmbg,8) )  +  4*( GradjaninBiH::cifraNaPoziciji(jmbg,3) + GradjaninBiH::cifraNaPoziciji(jmbg,9) ) + 3*( GradjaninBiH::cifraNaPoziciji(jmbg,4) + GradjaninBiH::cifraNaPoziciji(jmbg,10) ) + 2*(GradjaninBiH::cifraNaPoziciji(jmbg,5) + GradjaninBiH::cifraNaPoziciji(jmbg,11) ))%11;
       
       }
       
       if(tlinest == 11) tlinest = 0;
       if(tlinest == 10 ) throw std::logic_error("JMBG nije validan");
     
       return tlinest;
   }
   
   
   
   
   void GradjaninBiH::provjeraJMBG(long long int jmbg) {                                                      //PROVJERA JMBG VALJAL
       int duzina = GradjaninBiH::duzinaJMBG(jmbg);
      
       int dan = 0,m = 0,g = 1,tlines = 0, t = 0,cifra = 0;
       int g1 = 3, g2 = 2, g3 = 5, g4 = 4, g5 = 8;
     
       if(duzina != 13 && duzina != 12 ) throw std::logic_error("JMBG nije validan");
       t = jmbg%10;
       
       jmbg = GradjaninBiH::preokreniJMBG(jmbg);
     
      
       if( duzina == 12) {
           --g1;
           --g2;
           --g3;
           --g4;
           --g5;
       }
       for( int i = 1; i <= 13; i++) {
           cifra = jmbg%10;
       if( i < g1) { 
           dan = dan*10;
           dan += cifra;
       }
       else if( i > g2 && i < g3) {
           m = m*10;
           m += cifra;
       }
       else if( i > g4 && i < g5) {
           g = g*10;
           g += cifra;
       }
       if( i == g5) break;
       jmbg /= 10;
       }
          
      
       if(!GradjaninBiH::provjeraDatuma(dan,m,g)) throw std::logic_error("JMBG nije validan"); //duzina izvrsavanja rip

       
     
       tlines = GradjaninBiH::tlinest(jmbg,false);
       
      
    }
     
   GradjaninBiH* GradjaninBiH::zadnji = nullptr;
   GradjaninBiH *t = nullptr;  //pomocin
   

    GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
      
        
        GradjaninBiH::ime_i_prezime = ime_i_prezime;
        GradjaninBiH::provjeraJMBG(jmbg);
        GradjaninBiH::jmbg = jmbg;
        GradjaninBiH::izJmbgIzvadiOstalo(jmbg);
        
      
       
       
         GradjaninBiH *novi(this);
          
          if(!t) {zadnji= novi; t = novi; }
          else { 
              //GradjaninBiH *n = zadnji;
              novi->posljednji = zadnji; 
          zadnji = novi;
          }
           for(GradjaninBiH *i = zadnji; i != nullptr; i = i->posljednji) {
               if( i != zadnji && i->DajJMBG() == jmbg) { zadnji = nullptr; zadnji = i->posljednji; throw std::logic_error("Vec postoji gradjanin sa istim JMBG"); }
           }
        
       
           
          
        }
   
   
    
    GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, GradjaninBiH::Pol pol) {
       
        if(!GradjaninBiH::provjeraDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error ("Neispravni podaci");
        if( !(sifra_regije >= 0 && sifra_regije <= 99)) throw std::logic_error("Neispravni podaci");
        brKreiranih++;
        GradjaninBiH::ime_i_prezime = ime_i_prezime;
        GradjaninBiH::dan_rodjenja = dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja = godina_rodjenja;
        GradjaninBiH::sifra_regije = sifra_regije;
        GradjaninBiH::jmbg = GradjaninBiH::napraviJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,int(pol));
        GradjaninBiH *novi(this);
          
          if(!t) {zadnji= novi; t = novi; }
          else { 
            
              //GradjaninBiH *n = zadnji;
              novi->posljednji = zadnji; 
          zadnji = novi;
          }
          
        
          for(GradjaninBiH *i = zadnji; i != nullptr; i = i->posljednji) {
             if( i!= zadnji && i->DajJMBG() == jmbg){ zadnji = nullptr; zadnji = i->posljednji; throw std::logic_error("Vec postoji gradjanin sa istim JMBG"); }
          }
    }
    
    
    GradjaninBiH::~GradjaninBiH() {
        auto i = zadnji;
        while (true) {
            
            if(zadnji == nullptr) break;
            else if(i->posljednji == nullptr) break;
            GradjaninBiH *n = i->posljednji;
           // i = nullptr;
           delete i;
            i= n;
            
        }
    }
    
    
    std::string GradjaninBiH::DajImeIPrezime() const {
        return GradjaninBiH::ime_i_prezime;
    }
    
    
    long long int GradjaninBiH::DajJMBG() const {
        return GradjaninBiH::jmbg;
    }
    
    
    int GradjaninBiH::DajDanRodjenja() const {
        return dan_rodjenja;
    }
    
    
    int GradjaninBiH::DajMjesecRodjenja() const {
       return mjesec_rodjenja;
    }
    
    
    int GradjaninBiH::DajGodinuRodjenja() const {
       return godina_rodjenja;
    }
    
    
    int GradjaninBiH::DajSifruRegije() const {
       return sifra_regije;
    }
    
    
    GradjaninBiH::Pol GradjaninBiH::DajPol() const {
      return GradjaninBiH::pol;
            
    }
    
    
    void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
        GradjaninBiH::ime_i_prezime = novo_ime;
    }




int main ()
{
   
    GradjaninBiH *niz[100] {};
   
    int br = 0;
    try{
      std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
        int j =0;
        std::cin>>j;
    
        for(int i =0; i <j; i++) {
    std::cout<<"Unesite ime i prezime (u istom redu): \n";
    std::string ime;
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,ime);
    std::cout<<"Unesite JMBG: \n";
    long long int jmbg;
    std::cin>>jmbg;
    try{
    GradjaninBiH *ovaj = new  GradjaninBiH(ime,jmbg);
    niz[br] = ovaj;
    br++;
    
    int p = int(ovaj->DajPol());
    std::string l;
    if(p == 1 ) l = "zensko";
    else l = "musko";
    std::cout<<"Unijeli ste gradjanina "<<ovaj->DajImeIPrezime()<<" rodjenog "<<ovaj->DajDanRodjenja()<<"."<<ovaj->DajMjesecRodjenja()<<"."<<ovaj->DajGodinuRodjenja()<<" u regiji "<<ovaj->DajSifruRegije()<<", "<<l<<".\n";
    }catch(std::logic_error l){
        std::cout << l.what() << std::endl;
        i--;
    }
        }
        
        std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
        int k =0;
        std::cin>>k;
        for(int i =0; i <k; i++) {
            std::cout<<"Unesite ime i prezime (u istom redu): \n";
            std::string ime;
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,ime);
          std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
          int d=0,m=0,g=0;
          char z,l;
          std::cin>>d>>z>>m>>l>>g;
          std::cout<<"Unesite sifru regije: \n";
          int sifra;
          std::cin>>sifra;
          std::cout<<"Unesite M za musko, Z za zensko: \n";
          char znak;
          std::cin>>znak;
          GradjaninBiH::Pol o;
          if( znak == 'M') o = GradjaninBiH::Pol::Musko;
          else o = GradjaninBiH::Pol::Zensko;
          
          try{
              GradjaninBiH *go = new GradjaninBiH(ime,d,m,g,sifra,o);
              niz[i] = go;
              br++;
              std::cout<<"Unijeli ste gradjanina "<<go->DajImeIPrezime()<<" JMBG: "<<go->DajJMBG()<<".\n";
              
          }catch(std::logic_error a){
              std::cout << a.what() << std::endl;
              i--;
          }
          
    
        }
        
      
   
   
    
    
    
   
    }catch( std::logic_error l) {
        std::cout << l.what() << std::endl;
    } catch( ...) {
        std::cout << "Problem" << std::endl;
    }
    
    
	return 0;
}