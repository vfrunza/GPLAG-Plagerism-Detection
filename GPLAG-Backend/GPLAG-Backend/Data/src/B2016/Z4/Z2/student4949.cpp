/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<cmath>
#include<stdexcept>
using namespace std;

class GradjaninBiH
{
    string ime_i_prezime;
    int JMBG;
    int dan,mjesec,godina, sifra,kod;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni;
    GradjaninBiH *sljedeci;
   
    static bool IspravanDatum(int dan, int mjesec, int godina){
        int br[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina%400==0) br[1]++;
        if(godina <1 || mjesec>12 || mjesec<1 || dan<1 || dan>br[mjesec-1] || godina>2017) return 0;
        else return 1;
    }
    
    public:
     enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        auto itt=this;
        for(auto it=zadnji; it!=nullptr;it=it->prethodni){
            if(itt->JMBG==it->JMBG) throw logic_error("Vec postoji gradjanin sa istim JMBG") ;
        }
        
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        
        int t=jmbg;
        int niz[13],dan,mjesec,godina,sifra,kod;
    
            for(int i=0;i<13;i++){
                int k=1;
                for(int j=0;j<i+1;j++) k*=10;
                
                niz[i]=t%k;
            }
            
        if(niz[0]==11) niz[0]=0;  
        int izraz= 11 - (7*(niz[12]+niz[6])+6*(niz[11]+niz[5])+ 5*(niz[10]+niz[4])+4*(niz[9]+niz[3])+3*(niz[8]+niz[2])+2*(niz[7]+niz[1]));
        dan=niz[12]*10+niz[11];
        mjesec=niz[10]*10+niz[9];
        if(niz[8]==0) godina=2*1000+niz[8]*100+niz[7]*10+niz[6];
        else godina=1000+niz[8]*100+niz[7]*10+niz[6];
        sifra=niz[5]*10+niz[4];
        kod=niz[3]*100+niz[2]*10+niz[1];
    


        if(!IspravanDatum(dan,mjesec,godina) || niz[0]==10 || niz[0]!=izraz)  throw logic_error("JMBG nije validan");
        else{
            GradjaninBiH::godina=godina; GradjaninBiH::dan=dan; GradjaninBiH::mjesec=mjesec; JMBG=jmbg;
            GradjaninBiH::sifra=sifra; GradjaninBiH::kod=kod;
            
        }
        
        zadnji->prethodni=sljedeci;
        sljedeci=zadnji;
        zadnji=this;
        
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
        if(!IspravanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije<0 || sifra_regije>99) throw logic_error("Neispravni podaci");
        
        int niz[13];
        niz[0]=dan_rodjenja/10; niz[1]=dan_rodjenja%10;
        niz[2]=mjesec_rodjenja/10; niz[3]=mjesec_rodjenja%10;
        niz[4]=(godina_rodjenja/100)%10; niz[5]=(godina_rodjenja/10)%10; niz[6]=godina_rodjenja%10;
        niz[7]=sifra_regije/10; niz[8]=sifra_regije%10;
        int kod;
        for(auto it=zadnji;it!=nullptr;it=it->prethodni){
            if(dan_rodjenja==it->dan && sifra_regije==it->sifra && pol==it->DajPol()) kod=it->kod+1;
        }
        
        
        int izraz= 11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+ 5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]));
        niz[12]=izraz;
        
        zadnji->prethodni=sljedeci;
        sljedeci=zadnji;
        zadnji=this;
        
    }
           
                 
    std::string DajImeIPrezime() const{
        return ime_i_prezime;
    }
    long long int DajJMBG() const{
        return JMBG;
    }
    int DajDanRodjenja() const{
        return dan;
    }
    int DajMjesecRodjenja() const{
        return mjesec;
    }
    int DajGodinuRodjenja() const{
        return godina;
    }
    int DajSifruRegije() const{return sifra;}
    Pol DajPol() const{
        if(kod>=0 && kod<500) return Musko;
        else if(kod>=500 && kod<1000) return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){
        ime_i_prezime=novo_ime;
    }
};



GradjaninBiH *GradjaninBiH::zadnji=nullptr;



int main ()
{
    return 0;
}