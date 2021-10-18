/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

class GradjaninBiH{
    
    public:
        enum Pol {Musko,Zensko};
    private:
        std::string ime_i_prezime;
        long long int jmbg;
        int dan_rodjenja;
        int mjesec_rodjenja;
        int godina_rodjenja;
        Pol pol;
        int sifra_regije;
        static GradjaninBiH* posljednji;
        GradjaninBiH* prethodni=nullptr;
        void Postavi(std::string ime_i_prezime, long long int jmbg);
        void Postavi(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
        static bool LegalanDatum(int dan, int mjesec, int godina);
    public:
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg){Postavi(ime_i_prezime,jmbg);}
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){Postavi(ime_i_prezime, dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol);};
        long long int DajJMBG() const{return jmbg;};
        std::string DajImeIPrezime() const {return ime_i_prezime;}
        int DajDanRodjenja() const{return dan_rodjenja;};
        int DajMjesecRodjenja() const{return mjesec_rodjenja;};
        int DajGodinuRodjenja() const{return godina_rodjenja;};
        int DajSifruRegije() const{return sifra_regije;};
        Pol DajPol() const{return pol;};
        void PromijeniImeIPrezime(std::string novo_ime){ime_i_prezime=novo_ime;}
        ~GradjaninBiH();
};
    bool GradjaninBiH::LegalanDatum(int dan, int mjesec, int godina){
        int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;
        if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>dani[mjesec-1])
            return false;
        return true;
    }
    GradjaninBiH* GradjaninBiH::posljednji=nullptr;
    GradjaninBiH::~GradjaninBiH(){
        if(this==posljednji)//zadnji gradjanin
            posljednji=posljednji->prethodni;
        else if(this->prethodni==nullptr && this==posljednji){
            posljednji=nullptr;
        }
        else if(this->prethodni==nullptr)//prvi gradjanin
        {
            auto pok=posljednji;
            while(pok->prethodni!=this){
                pok=pok->prethodni;
            }
            pok->prethodni=nullptr;
        }
        else {auto pom=posljednji;
        while(pom->prethodni!=this){
            pom=pom->prethodni;
        }
        pom->prethodni=this->prethodni;
        
    }}
    void GradjaninBiH::Postavi(std::string ime_i_prezime, long long int jmbg){
        
        int Jmbg[13];
        
        long long int pom = jmbg;
        
        for(int i=12 ; i>=0 ; i--)
            Jmbg[i]=pom%10, pom/=10;
        
        dan_rodjenja=Jmbg[0]*10+Jmbg[1];
        mjesec_rodjenja=Jmbg[2]*10+Jmbg[3];
        if(Jmbg[4]==0) godina_rodjenja=2000+Jmbg[5]*10+Jmbg[6];
        else godina_rodjenja=1000+Jmbg[4]*100+Jmbg[5]*10+Jmbg[6];
        if(!LegalanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || godina_rodjenja<1917)
            throw std::logic_error("JMBG nije validan");
        sifra_regije=Jmbg[7]*10+Jmbg[8];
        if(sifra_regije<0 || sifra_regije>99)
            throw std::logic_error("JMBG nije validan");
        int c13=11-(7*(Jmbg[0]+Jmbg[6])+6*(Jmbg[1]+Jmbg[7])+5*(Jmbg[2]+Jmbg[8])+4*(Jmbg[3]+Jmbg[9])+3*(Jmbg[4]+Jmbg[10])+2*(Jmbg[5]+Jmbg[11]))%11;
        if(c13==11) c13=0;
        if(c13!=Jmbg[12] || c13==10)
            throw std::logic_error("JMBG nije validan");
        
        int p=Jmbg[9]*100+Jmbg[10]*10+Jmbg[11];
        if(p>=0 && p<500) pol=Musko;
        else pol=Zensko;
        GradjaninBiH::jmbg=jmbg;
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        
        GradjaninBiH* pom2=posljednji;
        while(pom2!=nullptr){
            if(pom2->jmbg==jmbg)
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            pom2=pom2->prethodni;
        }
        
        prethodni=posljednji;
        posljednji=this;
    }
    void GradjaninBiH::Postavi(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        
        if(!LegalanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || godina_rodjenja<1917){
            throw std::logic_error("Neispravni podaci");}
        if(sifra_regije<0||sifra_regije>99){
            throw std::logic_error("Neispravni podaci");}
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::sifra_regije=sifra_regije;
        GradjaninBiH::pol=pol;
        int Jmbg[13];
        Jmbg[1]=dan_rodjenja%10;
        Jmbg[0]=dan_rodjenja/10;
        Jmbg[3]=mjesec_rodjenja%10;
        Jmbg[2]=mjesec_rodjenja/10;
        int pgod=godina_rodjenja%1000;
        Jmbg[6]=pgod%10;
        pgod/=10;
        Jmbg[5]=pgod%10;
        Jmbg[4]=pgod/10;
        Jmbg[8]=sifra_regije%10;
        Jmbg[7]=sifra_regije/10;
        int dg,gg;
        if(pol==Musko)dg=0, gg=499;
        else dg=500,gg=999;
        bool ispravan=true;
        bool registrovan=false;
        for(int i=dg;i<=gg;i++){
            ispravan=true;
            int pom=i;
            Jmbg[11]=pom%10;
            pom/=10;
            Jmbg[10]=pom%10;
            Jmbg[9]=pom/10;
            Jmbg[12]=11-(7*(Jmbg[0]+Jmbg[6])+6*(Jmbg[1]+Jmbg[7])+5*(Jmbg[2]+Jmbg[8])+4*(Jmbg[3]+Jmbg[9])+3*(Jmbg[4]+Jmbg[10])+2*(Jmbg[5]+Jmbg[11]))%11;
            if(Jmbg[12]==10) continue;
            if(Jmbg[12]==11) Jmbg[12]=0;
        
        long long int JMBG = 0;
        for(int j=0;j<13;j++){
            JMBG=JMBG*10+Jmbg[j];
        }
        
        GradjaninBiH* pom2=posljednji;
        while(pom2!=nullptr){
            if(JMBG==pom2->jmbg){
                ispravan=false;
                break;
            }
            pom2=pom2->prethodni;
            
        }
        if(ispravan){
            registrovan=true;
            jmbg=JMBG;
            break;
        }
        
        }
        
        if(!registrovan)
            throw std::logic_error("Svi JMBG su zauzeti");
        prethodni=posljednji;
        posljednji=this;
    }

int main ()
{
    
    std::string ime;
    long long int jmbg;
    GradjaninBiH* niz[100]{nullptr};
    std::string ppp[]{"musko","zensko"};
    int broj1;
    GradjaninBiH::Pol pol;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>broj1;
    
    for(int i=0;i<broj1;i++){
        bool neispravan=false;
        do{
            neispravan=false;
            try{
                std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
                std::cin.ignore(100,'\n');
                std::getline(std::cin,ime);
                std::cout<<"Unesite JMBG: "<<std::endl;
                std::cin>>jmbg;
                niz[i]=new GradjaninBiH(ime,jmbg);
                std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()
                <<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<", "<<ppp[int(niz[i]->DajPol())]<<"."<<std::endl;
            }
            catch(std::logic_error e){
                std::cout<<e.what()<<std::endl;
                neispravan=true;
                
            }
        }
        while(neispravan);
    }
    
    int broj2,dd, mm, gg, sifra;
    char z,pp;
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>broj2;
    
    for(int i=broj1;i<broj1+broj2;i++){
        bool neispravan;
        do{
            
            neispravan=false;
            try{
                std::cin.ignore(100,'\n');
                std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
                
                std::getline(std::cin,ime);
                
                
                std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
                std::cin>>dd>>z>>mm>>z>>gg;
                
                std::cout<<"Unesite sifru regije: "<<std::endl;
                std::cin>>sifra;
                std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
                std::cin>>pp;
                if(pp=='M') pol=GradjaninBiH::Pol::Musko;
                else pol=GradjaninBiH::Pol::Zensko;
                niz[i]= new GradjaninBiH(ime,dd,mm,gg,sifra,pol);
                std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" JMBG: "<<niz[i]->DajJMBG()<<"."<<std::endl;
                
            }
            catch(std::logic_error e){
                std::cout<<e.what()<<std::endl;
                neispravan=true;
               
            }
        }
        while(neispravan);
    }
    
    for(int i=0;i<broj1+broj2;i++){
        delete niz[i];
    }
    


return 0;
}