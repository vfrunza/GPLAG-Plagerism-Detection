#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

class GradjaninBiH{
    static GradjaninBiH* cuvar;
    static int brojac;
    std::string imeprezime;
    long long int JMBG;
    bool ProvjeraDatuma(int dan,int mjesec ,int godina){
        int dani[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0 )|| godina % 400 == 0) dani[1]++;
        if(dan<1 || dan>dani[mjesec-1] || mjesec<1 || mjesec>12)
        return false;
        return true;
  }
  
  void JeLi0(long long int maticni,int * p) const  {
      int br=0;
      long long int pom=maticni;
      while (maticni!=0) {
          maticni/=10;
          br++;
      }
      if(br==13){
      for(int i=12;i>=0;i--){
          p[i]=pom%10;
          pom/=10;
      }
      }
      if(br==12){
      p[0]=0;
       for(int i=12;i>0;i--){
          p[i]=pom%10;
          pom/=10;
      }
      }
  }
  GradjaninBiH * veza;
  public:
  GradjaninBiH(const GradjaninBiH &g)=delete;
  /*~GradjaninBiH(){
      if(veza==nullptr){
          GradjaninBiH*p=cuvar;
          while (p->veza!=this){
              p=p->veza;
          }
          p->veza=nullptr;
      }
      else if(cuvar==this){
          cuvar=this->veza;
      }
      else {
          GradjaninBiH *p=cuvar;
          while(p->veza!=this){
              p=p->veza;
          }
          p->veza=this->veza;
      }
  }
  */
  enum Pol{Musko,Zensko}; 
 GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
 GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
 std::string DajImeIPrezime() const{ return imeprezime; }
 long long int DajJMBG() const{ return JMBG; }
 int DajDanRodjenja() const;
 int DajMjesecRodjenja() const;
 int DajGodinuRodjenja() const;
 int DajSifruRegije() const;
 Pol DajPol() const;
 void PromijeniImeIPrezime(std::string novo_ime){ imeprezime=novo_ime;}
};
int GradjaninBiH::DajDanRodjenja() const{
    int  maticni[13];
    JeLi0(JMBG,maticni);
    return maticni[0]*10+maticni[1];
}
int GradjaninBiH::DajMjesecRodjenja() const {
    int maticni[13];
    JeLi0(JMBG,maticni);
    return maticni[2]*10+maticni[3];
}
int GradjaninBiH::DajGodinuRodjenja() const{
        int maticni[13];
        JeLi0(JMBG,maticni);
        
        if(maticni[4]==9) return 1900+maticni[5]*10+maticni[6];
        return 2000+maticni[5]*10+maticni[6];
}
int GradjaninBiH::DajSifruRegije() const{
    int maticni[13];
    JeLi0(JMBG,maticni);
    return maticni[7]*10+maticni[8];
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    int maticni[13];
    JeLi0(JMBG,maticni);
    int n(maticni[9]*100+maticni[10]*10+maticni[11]);
    if(n>=0 && n<=499) return Musko;
    else return Zensko;
}
 GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
     if(brojac==0){
          veza=nullptr;
          cuvar=this;
          }
          else {
              veza=cuvar;
              cuvar=this;
          }
          brojac++;
    imeprezime=ime_i_prezime;
    int br(0); auto pom=jmbg;
    while(pom!=0){
        br++; pom/=10;
        }
        int niz[13];
        if(br==13){
            auto novi=jmbg;
            for(int i=12;i>=0;i--){
                niz[i]=novi%10;
                novi/=10;
            }
        }
        if(br==12){
            niz[0]=0;
            auto novi=jmbg;
            for(int i=12;i>0;i--){
                niz[i]=novi%10;
                novi/=10;
            }
        }
           int dan=niz[0]*10+niz[1];
           int mjesec=niz[2]*10+niz[3];
           int godina;
           if(niz[4]==9) godina=1900+niz[5]*10+niz[6];
           else godina=2000+niz[5]*10+niz[6];
           if(!ProvjeraDatuma(dan,mjesec,godina))
           throw std::logic_error("JMBG nije validan");
           if( niz[12]==10)
           throw std::logic_error("JMBG nije validan");
           for(GradjaninBiH * p=veza;p!=nullptr;p=p->veza){
           if(jmbg==p->JMBG)
           throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
           }
           
           this->JMBG=jmbg;
        
}
 GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
          if(brojac==0){
          veza=nullptr;
          cuvar=this;
          }
          else {
              veza=cuvar;
              cuvar=this;
          }
          brojac++;
          imeprezime=ime_i_prezime;
          if(!ProvjeraDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || (sifra_regije>99 || sifra_regije<0))
          throw std::logic_error("Neispravni podaci");
          int maticni[13];
          if(dan_rodjenja<=9){ maticni[0]=0; maticni[1]=dan_rodjenja; }
          else { maticni[1]=dan_rodjenja%10; maticni[0]=dan_rodjenja/10; }
          if(mjesec_rodjenja<=9){ maticni[2]=0; maticni[3]=mjesec_rodjenja; }
          else { maticni[3]=mjesec_rodjenja%10; maticni[2]=mjesec_rodjenja/10; }
          maticni[6]=godina_rodjenja%10; godina_rodjenja/=10;
          maticni[5]=godina_rodjenja%10; godina_rodjenja/=10;
          maticni[4]=godina_rodjenja%10; godina_rodjenja/=10;
          maticni[8]=sifra_regije%10; maticni[7]=sifra_regije/10;
          long long int jmbg;
          for(;;){
          int unik(0);
          for(int i=11;i>=9;i--){
          maticni[i]=unik%10;
          unik/=10;
          }
          maticni[12]=11-(7*(maticni[0]+maticni[6])+6*(maticni[1]+maticni[7])+5*(maticni[2]+maticni[8])+4*(maticni[3]+maticni[9])+3*(maticni[4]+maticni[10])+2*(maticni[5]+maticni[11]))%11;
              if(maticni[12]==11) maticni[12]=0;
              jmbg=0;
              bool imal(true);
              for(int j=12;j>=0;j--){
              jmbg=jmbg+(maticni[12-j]*pow(10,j));
              }
              for(GradjaninBiH*p=veza;p!=nullptr;p=p->veza){
              if(jmbg==p->JMBG){
              unik++;
              imal=false;
              break;
              }
              }
              if(imal)
              break;
          }
          
          this->JMBG=jmbg;
}
int GradjaninBiH::brojac=0;
GradjaninBiH* GradjaninBiH::cuvar=nullptr;
int main(){
    int n; 
    GradjaninBiH *cuvar;
    std::cout <<"Koliko gradjana zelite unijeti po JMBG?"  << std::endl;
    std::cin >> n;
     std::cin.clear();
        std::cin.ignore(10000,'\n');
    for(int i=0;i<n;i++){
        std::string ime;
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin,ime);
        long long int j;
        std::cout << "Unesite JMBG: " << std::endl;
        std::cin >>  j;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        try{
        cuvar=new GradjaninBiH(ime,j);
        }
        catch(std::logic_error l){
            std::cout << l.what() << std::endl;
            i--;
            continue;
        }
        if(cuvar->DajPol()==0)
        std::cout <<"Unijeli ste gradjanina "<< cuvar->DajImeIPrezime() <<" rodjenog "<<cuvar->DajDanRodjenja()<<"."<<cuvar->DajMjesecRodjenja()<<"."<<cuvar->DajGodinuRodjenja()<<" u regiji "<<cuvar->DajSifruRegije()<<", musko"<<std::endl ;
        else
        std::cout <<"Unijeli ste gradjanina "<< cuvar->DajImeIPrezime() <<" rodjenog "<<cuvar->DajDanRodjenja()<<"."<<cuvar->DajMjesecRodjenja()<<"."<<cuvar->DajGodinuRodjenja()<<" u regiji "<<cuvar->DajSifruRegije()<<", zensko"<<std::endl ;
    }
    GradjaninBiH* cuvar2;
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja,regiji i polu?" << std::endl;
    int m;
    std::cin >> m;
     std::cin.clear();
        std::cin.ignore(10000,'\n');
    for(int i=0;i<m;i++){
        std::string datum;
         std::string ime;
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin,ime);
        int d,m,g;
        std::cout << "Unesite datum rodjenja(format dd/mm/gggg): " << std::endl;
            std::getline(std::cin,datum);
            std::string da,mj,go;
            int zagrade(0);
            for(int i=0;i<datum.length();i++){
                int pm;
                if(datum[i]=='/'  && zagrade==0){
                da=datum.substr(0,i);
                zagrade++;
                pm=i+1;
                }
                if(datum[i]=='/' && zagrade==1){
                    mj=datum.substr(pm,i-pm);
                    int pg=i+1;
                    go=datum.substr(pg,datum.length()-pg);
                }
                
            }
            d=atoi(da.c_str());
            m=atoi(mj.c_str()); 
            g=atoi(go.c_str()); 
        int sifra;
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> sifra;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::string pol;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        std::getline(std::cin,pol);
        if(pol=="M"){
        try{
        cuvar2=new GradjaninBiH(ime,d,m,g,sifra,GradjaninBiH::Pol::Musko);
        }
        catch(std::logic_error l){
            std::cout << l.what() << std::endl;
            i--;
            continue;
        }
        }
        if(pol=="Z"){
        try{
        cuvar2=new GradjaninBiH(ime,d,m,g,sifra,GradjaninBiH::Pol::Zensko);
        }
        catch(std::logic_error l){
            std::cout << l.what() << std::endl;
            i--;
            continue;
        }
        }
        std::cout << "Unijeli ste gradjanina " <<cuvar2->DajImeIPrezime()<<" JMBG: "<<cuvar2->DajJMBG()<< std::endl;
        
    }
    
    return 0;
}