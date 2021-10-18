/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <iomanip>


struct Upakovano {
    int niz[13];
};
class GradjaninBiH {
    private: 
        long long int JMBG;
        static int br;
        int br1;
        static GradjaninBiH *pok;
        GradjaninBiH *pok1;
        GradjaninBiH *pok2;
        Upakovano razdvojeno (long long int maticni) const{
            Upakovano vracamo;
            int i = 12;
            while (maticni!= 0){
                vracamo.niz[i]=maticni%10;
                maticni = maticni / 10;
                i--;
            }
            return vracamo;
        std::string imeiprezime;
        }  
    void TestDatuma(int d, int m, int g) const{
        int br_d[]{31,29,31,30,31,30,31,31,30,31,30,31};
        if((g%4!=0 && g%100==0) || g%400!=0) br_d[1]--;
        if(g<1 || d < 1 || m<1 || m>12 || d>br_d[m-1]) throw std::domain_error("Neispravan datum");
    }
    public:
        enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol): imeiprezime(ime_i_prezime){
        if(br==0){
            pok=this;
            pok1=this;
            pok2=nullptr;
        }
        else{
            pok1=this;
            pok2=pok;
            pok=this;
        }
        if(dan_rodjenja<1 || dan_rodjenja>31 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || godina_rodjenja<1 || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");        
        if(dan_rodjenja<10) {
            vracamo.niz[0] = 0; 
            vracamo.niz[1] = dan_rodjenja;
        }
        else {
        vracamo.niz[1] = dan_rodjenja%10;
        dan_rodjenja = dan_rodjenja/10;
        vracamo.niz[0] = dan_rodjenja%10;
        }

        if(vracamo.niz[12]==11) vracamo.niz[12]=0;
        if(vracamo.niz[12]==10) throw std::logic_error("JMBG nije validan");
        if(vracamo.niz[0]*10+vracamo.niz[1]<1 || vracamo.niz[0]*10+vracamo.niz[1]>31) throw std::logic_error("JMBG nije validan");
        if(vracamo.niz[2]*10+vracamo.niz[3]<1 || vracamo.niz[2]*10+vracamo.niz[3]>12) throw std::logic_error("JMBG nije validan");
        if(1000+vracamo.niz[4]*100+vracamo.niz[5]*10+vracamo.niz[6]<1917 || 1000+vracamo.niz[4]*100+vracamo.niz[5]*10+vracamo.niz[6]>2017) throw std::logic_error("JMBG nije validan");
        static int brojcanipol(0);
        if(pol==Pol::Musko){
            if(brojcanipol>499) throw std::logic_error("Prekoraceno");
            if(brojcanipol<10) {vracamo.niz[9]=0; vracamo.niz[10]=0; vracamo.niz[11]=brojcanipol;
                vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;
            }
            else if(brojcanipol<100){vracamo.niz[9]=0; vracamo.niz[11]=brojcanipol%10; brojcanipol/=10; vracamo.niz[10]=brojcanipol%10;
                 vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;
            }
            else{
                    vracamo.niz[11]=brojcanipol%10; brojcanipol/=10; vracamo.niz[10]=brojcanipol%10; brojcanipol/=10; vracamo.niz[9]=brojcanipol%10;
                    vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;
                }
            for(int i=12;i>=0;i--){GradjaninBiH::JMBG+=niz[i]*std::pow(10,br1);br1++;}
            br1=0;
            while(p->pok2!=nullptr){
                p=p->pok2->p;
                if(JMBG==p->JMBG){
                    brojcanipol++;
                    if(brojcanipol<10){niz[9]=0; niz[10]=0; niz[11]=brojcanipol;
                     vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;

                    }
                    else if(brojcanipol<100){niz[9]=0; niz[11]=brojcanipol%10; brojcanipol/=10; niz[10]=brojcanipol%10;
                     vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;
                    }
                    else{
                        niz[11]=brojcanipol%10; brojcanipol/=10; niz[10]=brojcanipol%10; brojcanipol/=10; niz[9]=brojcanipol%10;
                        vracamo.niz[12]=11-(7*(vracamo.niz[0]+vracamo.niz[6])+6*(vracamo.niz[1]+vracamo.niz[7])+5*(vracamo.niz[2]+vracamo.niz[8])+4*(vracamo.niz[3]+vracamo.niz[9])+3*(vracamo.niz[4]+vracamo.niz[10])+2*(vracamo.niz[5]+vracamo.niz[11]))%11;

                    }
                }
            }
        }
    }
    ~GradjaninBiH(){
        GradjaninBiH *poka=pok;
        GradjaninBiH *poka1=pok;
        if(poka==this){
            poka=poka->p; 
            pok=pok->p;
        }
        else{
            while(poka!=nullptr){
                poka=poka->p;
                if(poka==this){
                    poka=poka->p;
                    poka1->p=poka;
                    break;
                }
                poka1=poka1->p;
            }
        }
    }
    std::string Dajimeiprezime() const { 
        return imeiprezime; 
    }
    long long int DajJMBG() const {
        return JMBG;
    }
    int DajDanRodjenja() const { 
        auto raz = razdvojeno(JMBG);
        auto vracam = vracamo.niz[0]*10 + vracamo.niz[1];
        return vracam;
    }
    int DajMjesecRodjenja() const{ 
        auto raz = razdvojeno(JMBG);
        auto vracam = vracamo.niz[2]*10+vracamo.niz[3];
        return vracam;
    }
    int DajGodinuRodjenja() const {
        auto raz = razdvojeno(JMBG);
        auto vracam = 1000+vracamo.niz[4]*100+vracamo.niz[5]*10+vracamo.niz[6];
        return vracam;
    } 
    int DajSifruRegije() const{
        auto raz = razdvojeno(JMBG);
        auto vracam = vracamo.niz[7]*10+vracamo.niz[8];
        return vracam;
    }
    Pol DajPol() const{ 
        auto raz = razdvoji(JMBG);
        auto vracam = vracamo.niz[9]*100+vracamo.niz[10]*10+vracamo.niz[11];
        if (vracam >=0 && vracam<499) 
           return Pol::Musko;
        return Pol::Zensko;
    }
    void Promijeniimeiprezime(std::string novo_ime){
        imeiprezime = novo_ime;
    }
    void Ispisi() const{
        std::cout<<ime_i_prezime << std::endl;
        auto raz = razdvojeno(JMBG);
        for(int i = 0; i<=12; ++i){
            std::cout<<vracamo.niz[i];
            std::cout<<std::endl;
        }
    }
};
void GradjaninBiH::Ispisi()const {
    std::cout<<GradjaninBiH::JMBG<<std::endl;
}
};
int GradjaninBiH::br=0;
GradjaninBiH* GradjaninBiH::pok=nullptr;
int main(){
     GradjaninBiH x("ilma spahic", 2110996175100);
     GradjaninBiH y("ajla spahic", 1401992175150);
     x.Ispisi();
     y.Ispisi();
     return 0;
 }