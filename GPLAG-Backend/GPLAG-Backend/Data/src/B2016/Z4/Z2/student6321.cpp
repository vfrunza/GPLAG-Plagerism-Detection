/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<stdexcept>




class GradjaninBiH {
    
   
    
    std::string ime_i_prezime;
    long long int jmbg;
    
   static GradjaninBiH *zadnji;
   
   GradjaninBiH* prethodni;
   

    
    static int BrojDana(int mjesec_rodjenja,int godina_rodjenja);
    static bool IspravanDatum(int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja);

    public:

     enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    
    ~GradjaninBiH();
   
   GradjaninBiH(const GradjaninBiH &a)=delete;
   GradjaninBiH(GradjaninBiH &&a)=delete;
   GradjaninBiH &operator =(const GradjaninBiH &a)=delete;
   GradjaninBiH &operator =(GradjaninBiH &&a)=delete;
   
    
    std::string DajImeIPrezime() const{return ime_i_prezime;};
    long long int DajJMBG() const{return jmbg;};
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);

};

GradjaninBiH* GradjaninBiH::zadnji(nullptr);


int GradjaninBiH::BrojDana(int mjesec_rodjenja,int godina_rodjenja){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina_rodjenja%4==0 && godina_rodjenja%100!=0) || godina_rodjenja%400==0)
        broj_dana[1]++;
        
    return broj_dana[mjesec_rodjenja-1];
    
}

bool GradjaninBiH::IspravanDatum(int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja){
    
    if(godina_rodjenja<1 || dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>BrojDana(mjesec_rodjenja,godina_rodjenja)){
        
        return false;
    }
    return true;
}



GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
    
    int c[13];
   
   auto b(jmbg);
    for(int i=12;i>=0;i--){
        c[i]=b%10;
        
        b/=10;
        
        
    }
    
   
    int c13(11-((7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11));
    
    if(c13==10 || (c13==11 && c[12]!=0) || (c13<0 && c13!=c[12])) throw std::logic_error("JMBG nije validan");
    int dan(c[0]*10+c[1]);
    int mjesec(c[2]*10+c[3]);
    int godina(c[4]*100+c[5]*10+c[6]);
    if(c[4]==0) godina+=2000;
    else godina+=1000;
    
    bool pr(IspravanDatum(dan,mjesec,godina));
   
    if(!pr) throw std::logic_error("JMBG nije validan");
    

    if(zadnji==nullptr){
       
      
        GradjaninBiH::ime_i_prezime=ime_i_prezime; GradjaninBiH::jmbg=jmbg; GradjaninBiH::prethodni=nullptr;
        
        zadnji=this;
        
 
    }else{
       
        auto p(zadnji);
        while(p->prethodni!=nullptr){
            if(p->jmbg==jmbg){
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            }
            p=p->prethodni;
            
        }
        if(p->jmbg==jmbg){
            throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        
        
     GradjaninBiH::ime_i_prezime=ime_i_prezime;GradjaninBiH::jmbg=jmbg;prethodni=zadnji;
            zadnji=this;
    }
   
   
   
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol){
    
    if(!IspravanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    
    if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    
    int c[13];
    
    c[1]=dan_rodjenja%10;
    dan_rodjenja/=10;
    c[0]=dan_rodjenja;
    c[3]=mjesec_rodjenja%10;
    mjesec_rodjenja/=10;
    c[2]=mjesec_rodjenja;
    c[6]=godina_rodjenja%10;
    godina_rodjenja/=10;
    c[5]=godina_rodjenja%10;
    godina_rodjenja/=10;
    c[4]=godina_rodjenja%10;
    
    c[8]=sifra_regije%10;
    sifra_regije/=10;
    c[7]=sifra_regije;
    
    
    if(pol==Musko) {
        c[9]=0;c[10]=0;c[11]=0;
    }
    if(pol==Zensko){
        c[9]=5;c[10]=0;c[11]=0;
    }
    
    //fali dio ako ima vec sa istim jmbg onda c[11]++; if(c[11]==10) c[11]=0; c[10]++; if(c[10)==10) c[10]=0; c[9]++; onda racunamo c[12];
   A: 
    
    c[12]=11-((7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11);
    
    if(c[12]==11) c[12]=0;
    if(c[12]==10){
         c[11]++;
            if(c[11]==10){
                c[11]=0;
                c[10]++;
                if(c[10]==10){
                    c[10]=0;
                    c[9]++;
                }
            }
            goto A;
    }
    
  
    


    long long int jmbg(0);
    long long int k(1);
    for(int i=12;i>=0;i--){
        jmbg+=k*c[i];
        k=k*10;

    }
    
   // std::cout<<jmbg<<"|";
    
    
    if(zadnji==nullptr){
       
         GradjaninBiH::ime_i_prezime=ime_i_prezime; GradjaninBiH::jmbg=jmbg; GradjaninBiH::prethodni=nullptr;
         
        zadnji=this;
    }
    else {
    auto p(zadnji);
       while (p->prethodni!=nullptr){
          if(p->jmbg==jmbg){
            
            c[11]++;
            if(c[11]==10){
                c[11]=0;
                c[10]++;
                if(c[10]==10){
                    c[10]=0;
                    c[9]++;
                }
            }
        
            goto A;
          }
           p=p->prethodni; 
        }
        if(p->jmbg==jmbg){
             c[11]++;
            if(c[11]==10){
                c[11]=0;
                c[10]++;
                if(c[10]==10){
                    c[10]=0;
                    c[9]++;
                }
            }
        
            goto A;
            
        }
        GradjaninBiH::ime_i_prezime=ime_i_prezime; GradjaninBiH::jmbg=jmbg; GradjaninBiH::prethodni=zadnji;
     zadnji=this;
    }


}


GradjaninBiH::~GradjaninBiH(){
    
    
   if(zadnji!=nullptr){
  
    if(this!=zadnji ){
     
        auto a=this;
       
        auto p=zadnji;std::cout<<p->jmbg;
        for(;;){
         
            if(p->prethodni==a){
               
                
                if(a->prethodni==nullptr){
                  
                    p->prethodni=nullptr;
                   
                    break;
                }
                p->prethodni=a->prethodni;
                a->prethodni=nullptr;
              
                break;
                
            }
            p=p->prethodni;
        }
        
    }else {
    
    
        auto p(zadnji);
        if(zadnji->prethodni==nullptr) zadnji=nullptr;
        else{
        zadnji=zadnji->prethodni;
        }
        p->prethodni=nullptr;
      // std::cout<<"|"<<zadnji->jmbg<<"||";
       
        
    }
   }
    
}



int GradjaninBiH::DajDanRodjenja()const{
    
    long long int a(DajJMBG());
    
    return a/100000000000;
}
int GradjaninBiH::DajMjesecRodjenja()const{
    
    long long int a(DajJMBG());
    a=a%100000000000;
    a/=1000000000;

    return a;
}
int  GradjaninBiH::DajGodinuRodjenja() const{
    
    long long int d(DajJMBG());
  
  d=d%1000000000;
  d/=1000000;
    
    if(d/100==0) d+=2000;
    else d+=1000;
    return d;

}
int GradjaninBiH::DajSifruRegije()const{
    
    long long int a(DajJMBG());
    
    a=a%1000000;
    
    a/=10000;
    
    return a;

}

GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    
    long long int a(DajJMBG());
    
    a=a%10000;
    a/=10;
    
    if(a<=499) return Musko;
    else return Zensko;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    ime_i_prezime=novo_ime;
}
int main ()
{
 
    

    std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        
        try{
        std::string s;
        std::cout<<"Unesite ime i prezime (u istom redu): \n";
        std::cin.clear();
        std::cin.ignore(1000000,'\n');
        std::getline(std::cin,s);
        std::cout<<"Unesite JMBG: \n";
        long long int j;
        std::cin>>j;
        
        GradjaninBiH a(s,j);
        
        std::cout<<"Unijeli ste gradjanina "<<a.DajImeIPrezime();
      
        std::cout<<" rodjenog "<<a.DajDanRodjenja() <<"."<<a.DajMjesecRodjenja()<<"."<<a.DajGodinuRodjenja()<<" u regiji "<<a.DajSifruRegije()<<", ";
      auto g(a.DajPol());
      if(g) std::cout<<"zensko"; else std::cout<<"musko";
        std::cout<<"."<<std::endl;
    
 
 
    }catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
        i--;
    }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int m;
    std::cin>>m;
    for(int i=0;i<m;i++){
        
        try{
            std::cout<<"Unesite ime i prezime (u istom redu): \n";
            std::string s;
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            std::getline(std::cin,s);
            
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
            int d,m,g;
            std::cin>>d;
            std::cin.get();
            std::cin>>m;
            std::cin.get();
            std::cin>>g;
            std::cout<<"Unesite sifru regije: \n";
            int sifra;
            std::cin>>sifra;
            std::cout<<"Unesite M za musko, Z za zensko: \n";
            std::cin.ignore(10000,'\n');
            char pol(std::cin.get());
            GradjaninBiH::Pol spol;
            if(pol=='M') spol=GradjaninBiH::Musko; if(pol=='Z') spol=GradjaninBiH::Zensko;
            
            
            GradjaninBiH a(s,d,m,g,sifra,spol);
           std::cout<<"Unijeli ste gradjanina "<<a.DajImeIPrezime()<<" JMBG: "<<a.DajJMBG()<<".\n";
         
        }
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
        i--;
    }
    }
 
	return 0;
}