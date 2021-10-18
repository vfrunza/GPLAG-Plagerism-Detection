/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>


using namespace std;

class GradjaninBiH{
    string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prev;
public:
enum Pol {Musko, Zensko};
long long int f(){
    int cjedan=dan_rodjenja/10;
    int cdva=dan_rodjenja%10;
    int ctri=mjesec_rodjenja/10;
    int ccetri=mjesec_rodjenja%10;
    int cpet=godina_rodjenja/100;
    int csest=(godina_rodjenja/10)%10;
    int csedam=godina_rodjenja%100;
    int cosam=sifra_regije/10;
    int cdevet=sifra_regije%10;
    int cdeset=0;
        int cjedanaest=0;
        int cdvanaest=0;
    while(Pol::Musko==Pol::pol){
        
        while(cdvanaest<10){
            cdvanaest++;
            if(cdvanaest>9){
                cjedanaest++;
            }
            if(cjedanaest>9){
                cdeset++;
            }
        }
    }        

}
     int p=(((cdeset*10)+cjedanaest)*10+cdvanaest);
    int ctrinaest=11-(7*(cjedan+csedam)+6*(cdva+cosam)+5*(ctri+cdevet)+4*(ccetri+cedeset)+3*(cpet+cjedanaest)+2*(csest+cdvanaest))%11;
    long long int jmbg=(((((dan_rodjenja*100+mjesec_rodjenja)*1000)+(godina_rodjenja&1000))*100+sifra_regije)*1000+p)*10+ctrinaest;
    return jmbg;
}
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::sifra_regije=sifra_regije;
        zadnji=nullptr;
        if(zadnji==nullptr){
            prev=nullptr;
            zadnji=this;
        }
        if(f()==jmbg) jmbg==jmbg;
        else throw "Izuzetak";
    }
    std::string DajImeIPrezime() const{
        return ime_i_prezime;
    }
    long long int DajJMBG() const{
        return jmbg;
    }
    int DajDanRodjenja() const{
        return dan_rodjenja;
    }
    int DajMjesecRodjenja() const{
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja() const{
        return godina_rodjenja;
    }
    int DajSifruRegije() const{
        return sifra_regije;
    }
    Pol DajPol() const{
        return pol;
    }
    ~GradjaninBiH(){
        GradjaninBiH *t=zadnji;
        while(t->prev!=this){
            t=t->prev;
        }
        t->prev=this->prev;
    }
    void PromijeniImeIPrezime(std::string novo_ime);
};

int main ()
{
	return 0;
}