#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath>

class GradjaninBiH{
    std::string ime_i_prezime;
    int jmbg[13]{};
    GradjaninBiH* veza;
    static GradjaninBiH* kraj;
    static bool TestDatuma(int d,int m,int g);
    static void TestJMBG(GradjaninBiH *veza,int* jmbg);
   
    public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime () const{return ime_i_prezime;}
    long long int DajJMBG() const;
    int DajDanRodjenja() const {return jmbg[0]*10+jmbg[1];}
    int DajMjesecRodjenja() const{return jmbg[2]*10+jmbg[3];}
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const{return jmbg[7]*10+jmbg[8];}
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime){ ime_i_prezime=novo_ime; } 
    ~GradjaninBiH();
};
GradjaninBiH* GradjaninBiH::kraj=nullptr;
    GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg):ime_i_prezime(ime_i_prezime){
        std::string s(std::to_string(jmbg));
        for(int i=0; i<13; i++){
            if(s.size()==12){
                if(i==0){ GradjaninBiH::jmbg[i]=0; continue; }
                GradjaninBiH::jmbg[i]=s[i-1]-'0';
            }else{
                GradjaninBiH::jmbg[i]=s[i]-'0';
            }
        }
        {
         int d=GradjaninBiH::jmbg[0]*10+GradjaninBiH::jmbg[1],m=GradjaninBiH::jmbg[2]*10+GradjaninBiH::jmbg[3],g=GradjaninBiH::jmbg[4]*100+GradjaninBiH::jmbg[5]*10+GradjaninBiH::jmbg[6];
         if(g>17)
            g+=1000;
        else g+=2000;
      //  std::cout<<d<<" "<<m<<" "<<g;
        if(!TestDatuma(d,m,g)) throw std::logic_error("JMBG nije validan");
        int c=11-(7*(GradjaninBiH::jmbg[0]+GradjaninBiH::jmbg[6])+6*(GradjaninBiH::jmbg[1]+GradjaninBiH::jmbg[7])+5*(GradjaninBiH::jmbg[2]+GradjaninBiH::jmbg[8])+4*(GradjaninBiH::jmbg[3]+GradjaninBiH::jmbg[9])+3*(GradjaninBiH::jmbg[4]+GradjaninBiH::jmbg[10])+2*(GradjaninBiH::jmbg[5]+GradjaninBiH::jmbg[11]))%11;
        if(c!=GradjaninBiH::jmbg[12]) throw std::logic_error("JMBG nije validan");
        }
        veza=kraj;
        kraj=this;
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        TestJMBG(veza,GradjaninBiH::jmbg);
    }
    void GradjaninBiH::TestJMBG (GradjaninBiH * veza,int* jmbg){
        for(GradjaninBiH* p(veza); p!=nullptr; p=p->veza){
            if( std::equal(jmbg,jmbg+13,(p->jmbg)) ) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
        }
    }
    bool GradjaninBiH::TestDatuma(int d,int m,int g){
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(((g%4==0) and (g%100!=0)) or (g%400==0))
            broj_dana[1]++;
        return !(g<1 or m<1 or m>12 or d<1 or d>broj_dana[m-1]);
            
    }
    
    GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        if(!TestDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error ("Nesipravni podaci");
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        if(sifra_regije<0 or sifra_regije>99) throw std::logic_error ("Nesipravni podaci");
        std::string s(std::to_string(dan_rodjenja));
        if(s.size()==1){
            jmbg[0]=0;
            jmbg[1]=s[0]-'0';
        }else{
            jmbg[0]=s[0]-'0';
            jmbg[1]=s[1]-'0';
        }
        s=std::to_string(mjesec_rodjenja);
        for(int i=0; i<2; i++)
            jmbg[2+i]=s[i]-'0';
        s=std::to_string(godina_rodjenja);
        for(int i=0; i<3; i++)
            jmbg[4+i]=s[i+1]-'0';
        s=std::to_string(sifra_regije);
        for(int i=0; i<2; i++)
            jmbg[7+i]=s[i]-'0';
        veza=kraj;
        kraj=this;
        int a(0);
        if(pol==Zensko)
            a=500;
        for(GradjaninBiH* p(veza); p!=nullptr; p=p->veza){
            bool pom(true);
            for(int i=0; i<9; i++){
                if(p->jmbg[i]!=jmbg[i])
                    pom=false;
            }
        if(pom){
            int b(jmbg[9]*100+jmbg[10]*10+jmbg[11]);
            if(pol==Musko){
                if(b>=a and b<500)
                    a=++b;
            }else{
                if(b>=a) a=++b;
            }
        }
        }
        s=std::to_string(a);
        if(s.size()==1){
            s="00"+std::to_string(a);
        }else if(s.size()==2){
            s="0"+std::to_string(a);
        }
        for(int i=0; i<3; i++)
            jmbg[9+i]=s[i]-'0';
  //      for(int i=0; i<12; i++)
    //    std::cout<<jmbg[i]<<" ";
    // = 11−(7∙ ( + )+6∙ ( + )+5∙ ( + )+4∙ ( + )+3∙ ( + )+2∙ ( + ))%11
        jmbg[12]=11-(7*(jmbg[0]+jmbg[6])+6*(jmbg[1]+jmbg[7])+5*(jmbg[2]+jmbg[8])+4*(jmbg[3]+jmbg[9])+3*(jmbg[4]+jmbg[10])+2*(jmbg[5]+jmbg[11]))%11;
 //  std::cout<<jmbg[12]<<" ";
   //     for(int i=0; i<13; i++)
     //   std::cout<<jmbg[i];
    }
    long long int GradjaninBiH::DajJMBG()const{
        long long int a(0);
        for(int i=0; i<13; i++){
            a+=jmbg[12-i]*std::pow(10,i);
        }
        return a;
    }
    int GradjaninBiH::DajGodinuRodjenja() const{
        int a(jmbg[4]*100+jmbg[5]*10+jmbg[6]);
        if(a<=17) a+=2000;     
        else a+=1000;
        return a;
    }
    GradjaninBiH::Pol GradjaninBiH::DajPol() const{
        int a(jmbg[9]*100+jmbg[10]*10+jmbg[11]);
        if(a>=500) return Zensko;
        return Musko;
    }
    GradjaninBiH::~GradjaninBiH(){
        if(this==kraj){
            kraj=this->veza;
        }else
        for(GradjaninBiH* p(kraj); p!=nullptr; p=p->veza){
            if(p->veza==this) p->veza=this->veza;
        }
        
    }
int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int n;
    std::cin>>n;
    std::cin.ignore(10000,'\n');
    for(int i=0; i<n; i++){
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string s;
        std::getline(std::cin,s);
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int br;
        std::cin>>br;
         std::cin.ignore(10000,'\n');
        try{
        GradjaninBiH neko(s,br);
        std::cout<<"Unijeli ste gradjanina "<<neko.DajImeIPrezime()<<" rodjenog "<<neko.DajDanRodjenja()<<"."<<neko.DajMjesecRodjenja()<<"."<<neko.DajGodinuRodjenja()<<" u regiji "<<neko.DajSifruRegije()<<", ";
        if(neko.DajPol()==0) std::cout<<"musko."<<std::endl;
        else std::cout<<"zensko."<<std::endl;
        }catch(std::logic_error iz){
            std::cout<<iz.what();
            i--;
        }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>n;
     std::cin.ignore(10000,'\n');
    for(int i=0; i<n; i++){
         std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
         std::string s;
         std::getline(std::cin,s);
         std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
         char znak1,znak2;
         int d,m,g;
         std::cin>>d>>znak1>>m>>znak2>>g;
          std::cin.ignore(10000,'\n');
         std::cout<<"Unesite sifru regije: "<<std::endl;
         int sr;
         std::cin>>sr;
          std::cin.ignore(10000,'\n');
         std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
         GradjaninBiH::Pol pol;
         char pom;
         std::cin>>pom;
          std::cin.ignore(10000,'\n');
         if(pom=='M') pol=GradjaninBiH::Musko;
         else if (pom=='Z') pol=GradjaninBiH::Zensko;
         else{
             std::cout<<"Nesipravni podaci";
             i--;
             continue;
         }
         try{
         GradjaninBiH neko(s,d,m,g,sr,pol);
         std::cout<<"Unijeli ste gradjanina "<<neko.DajImeIPrezime()<<" JMBG: "<<neko.DajJMBG()<<"."<<std::endl;
         }catch(std::logic_error iz){
             std::cout<<iz.what();
             i--;
         }
    }     
/*   try{
    GradjaninBiH s("Murga Drot",12,12,1992,17,GradjaninBiH::Musko);
    std::cout<<s.DajJMBG();
    }catch(...){
        std::cout<<"flaksčf";
    } */
	return 0;
}