/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>


class GradjaninBiH {
    
    std::string ime_i_prezime;
    int Jmbg [13];
    GradjaninBiH *prethodni;
    static GradjaninBiH *posljednji;
    
    
    static int BrojDana(int mjesec, int godina){
        if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) return 31;
        if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) return 30;
        if((godina%4==0 && godina%100!=0) || godina%400==0) return 29;
        return 28;
    }

    static bool DaLiJeIspravan (int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja ){
        if(godina_rodjenja<1 || dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>GradjaninBiH::BrojDana(mjesec_rodjenja, godina_rodjenja) ) return false;
        return true;
    }
  
  public:
  
    enum Pol{Musko,Zensko};
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja,  int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &gradjanin) = delete;
    GradjaninBiH &operator = (const GradjaninBiH &gradjanin) = delete;
    ~GradjaninBiH();
    
    std::string DajImeIPrezime() const {return ime_i_prezime;}
    long long int DajJMBG() const;
    int DajDanRodjenja() const {return Jmbg[0]*10+Jmbg[1];}
    int DajMjesecRodjenja() const{return Jmbg[2]*10+Jmbg[3] ;}
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const{ return Jmbg[7]*10+Jmbg[8]; }
    Pol DajPol() const;
    
    void PromijeniImeIPrezime(std::string novo_ime) {ime_i_prezime=novo_ime;}
    
};

GradjaninBiH *GradjaninBiH::posljednji=nullptr;



GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg): ime_i_prezime(ime_i_prezime){
  
    int niz [13];
      for(int i(12); i>=0; i--){
          niz[i]=jmbg%10;
          jmbg=jmbg/10;
      } 
     GradjaninBiH *temp(posljednji);
    if(posljednji!=nullptr){
     while(temp->prethodni!=nullptr){
         bool ima(true);
          for(int i(12); i>=0; i--){
              if(temp->Jmbg[i]!=niz[i]) {ima=false; break;}
            }
         if(ima) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
          temp=temp->prethodni;
        }
    }
  
      int dan(niz[0]*10+niz[1]), mjesec(niz[2]*10+niz[3]), godina(niz[4]*100+niz[5]*10+niz[6]);
      if(godina<=17) godina+=2000;
      else godina+=1000;
  
      
  
     if(DaLiJeIspravan(dan,mjesec,godina)==false ) throw std::logic_error("JMBG nije validan");
  
      for(int i(0); i<13; i++){
          Jmbg[i]=niz[i];
     }
    
    prethodni=posljednji;
    posljednji=this;
    
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol): ime_i_prezime(ime_i_prezime){
    
    if(sifra_regije<0 || sifra_regije>99) throw std::domain_error ("Neispravni podaci");
     if (DaLiJeIspravan(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false) throw std::domain_error ("Neispravni podaci");
    
    int kod_osobe;
    if(pol==GradjaninBiH::Zensko) kod_osobe=500;
    else kod_osobe=0;
    
    
    
    if(posljednji!=nullptr) {
        for(;;){
            bool ima_veci(false), bilo_povecanje(false);
            GradjaninBiH *temp(posljednji);
            while(temp->prethodni!=nullptr){
                int kod(temp->Jmbg[9]*100+temp->Jmbg[8]*10+temp->Jmbg[7]);
                if(kod>kod_osobe) ima_veci=true;
                if(kod==kod_osobe) { kod_osobe++; bilo_povecanje=true;}
                temp=temp->prethodni;
            }
            if((bilo_povecanje && ima_veci)==false) break;
        }
    }
    
    int niz[13];
    
    for(int i(11); i>8;i--){
        niz[i]=kod_osobe%10; kod_osobe=kod_osobe/10;
    }
    
    niz[8]=sifra_regije%10; sifra_regije=sifra_regije/10; 
    niz[7]=sifra_regije%10;
    
    for(int i(6); i>3; i--){
        niz[i]=godina_rodjenja%10; godina_rodjenja=godina_rodjenja/10;
    }
    
    niz[3]=mjesec_rodjenja%10; mjesec_rodjenja=mjesec_rodjenja/10;
    niz[2]=mjesec_rodjenja%10;
    niz[1]=dan_rodjenja%10; dan_rodjenja=dan_rodjenja/10;
    niz[0]=dan_rodjenja%10;
    
    int c13 ( 11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]) )%11 );
    if(c13==11) c13=0;
    niz[12]=c13;
    
    for(int i(0); i<13; i++){
        Jmbg[i]=niz[i];
    }
    
    prethodni=posljednji;
    posljednji=this;
    
}

GradjaninBiH::~GradjaninBiH(){
    if(this==posljednji) posljednji=prethodni;
    else if(prethodni==nullptr) {
        GradjaninBiH *temp(GradjaninBiH::posljednji);
        while(temp->prethodni!=this) temp=temp->prethodni;
        prethodni=nullptr;
    }
    
    else {
        GradjaninBiH *temp(posljednji);
        while(temp->prethodni!=this) temp=temp->prethodni;
        temp->prethodni=prethodni;
    }
}

long long int GradjaninBiH::DajJMBG () const{
    long long int povratni(0), stepen(1);
    for(int i(12); i>=0; i-- ){
        povratni+=Jmbg[i]*stepen;
        stepen*=10;
       
    }
    return povratni;
}

int GradjaninBiH::DajGodinuRodjenja () const {
    int temp(Jmbg[4]*100+Jmbg[5]*10+Jmbg[6]);
    if(temp<=17) return temp+2000;
    return temp+1000;
}

GradjaninBiH::Pol GradjaninBiH::DajPol ()const{
    int temp(Jmbg[9]*100+Jmbg[10]*10+Jmbg[11]);
    if(temp<500) return GradjaninBiH::Musko;
    return GradjaninBiH::Zensko;
}



int main ()
{  
 GradjaninBiH *niz[100];
   std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
  int n;
  std::cin>>n;
  std::cin.ignore(1000, '\n');
  std::cout<<std::endl;
  for(int i(0); i<n; i++){
      std::cout<<"Unesite ime i prezime (u istom redu): ";
      std::string s;
      std::getline(std::cin, s);
      
      std::cout<<std::endl<<"Unesite JMBG: ";
      long long int j;
      std::cin>>j;
      std::cin.ignore(1000,'\n');
    try{ niz[i]= new GradjaninBiH (s,j);
      std::cout<<std::endl<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()<<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<",";
      if(niz[i]->DajPol()==GradjaninBiH::Zensko) std::cout<<" zensko."<<std::endl;
      else std::cout<<" musko."<<std::endl;
      
    }
    catch(std::logic_error izuzetak){
        std::cout<<std::endl<<izuzetak.what()<<std::endl; i--;
    }
  }
  
  std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int n2;
  std::cin>>n2;
  std::cin.ignore(1000,'\n');
  
  for(int i(n); i<n+n2; i++){
      std::cout<<std::endl<<"Unesite ime i prezime (u istom redu): ";
      std::string s;
      std::getline(std::cin,s);
      std::cout<<std::endl<<"Unesite datum rodjenja (format dd/mm/gggg): ";
      int dan, mjesec, godina;
      char temp;
      std::cin>>dan>>temp>>mjesec>>temp>>godina;
      
      std::cout<<std::endl<<"Unesite sifru regije: ";
      int sifra;
      std::cin>>sifra;
      
      std::cout<<std::endl<<"Unesite M za musko, Z za zensko: ";
      char p;
      std::cin>>p;
      GradjaninBiH::Pol pol;
      if(p=='M') pol=GradjaninBiH::Musko;
      if(p=='Z') pol=GradjaninBiH::Zensko;
      std::cin.ignore(1000,'\n');
      try{
          niz[i]= new GradjaninBiH(s,dan,mjesec,godina,sifra,pol);
          std::cout<<std::endl<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" JMBG: "<<niz[i]->DajJMBG()<<".";
          
      }
      catch(std::logic_error izuzetak){
          std::cout<<std::endl<<izuzetak.what(); i--;
      }
  }
  
  for(int i(0); i<n+n2; i++) delete niz[i];
}