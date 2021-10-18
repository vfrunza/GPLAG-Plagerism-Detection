/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

enum Pol {Musko, Zensko};
class GradjaninBiH{
    static GradjaninBiH* pok_na_zadnjeg(nullptr) ;
    std::string ime_i_prezime;
    long long int jmbg;
    int c[13];
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
    Pol pol;
    GradjaninBiH* veza(nullptr);
    bool JeLiDatumValidan(int dan, int mjesec, int godina){
        int broj_dana[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        
        if(mjesec>12 || mjesec<1 || dan<1 || dan>broj_dana[mjesec-1] || godina<1)
        return false;
        else return true;
    }
    void JeLiJMBGValidan(long long int jmbg, int &dan, int& mjesec, int& godina, int& regija){
        long long int jmbg_kopija(jmbg);
          
          jmbg/=10000;
        regija=jmbg%100;    jmbg/=100;
        godina=jmbg%1000; jmbg/=1000;
        mjesec=jmbg%100;    jmbg/=100;
        dan=jmbg%100;
        if(godina>=917 && godina<=999) godina_rodjenja=godina+1000;
    else if(godina>=0 && godina<=17)  godina_rodjenja=godina+2000;
        int cifre[13];
        for(int i=12; i>=0; i--)
        {
            cifre[i]=jmbg_kopija%10;        
            jmbg_kopija/=10;
        }
        int c13(11-(7*(cifre[0]+cifre[6]) + 6*(cifre[1]+cifre[7]) + 5*(cifre[2]+cifre[8]) + 4*(cifre[3]+cifre[9]) + 3*(cifre[4]+cifre[10]) + 2*(cifre[5]+cifre[11]))%11);
        if(!JeLiDatumValidan(dan,mjesec,godina) || c13!=cifre[12] || cifre[12]==10)
            throw std::logic_error("JMBG nije validan");
        
    }
public:

GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int dan,mjesec,godina,regija;
    JeLiJMBGValidan(jmbg,dan,mjesec,godina,regija);
    int isti_dan((jmbg%10000)/10);
    if(pok_na_zadnjeg==nullptr){
        pok_na_zadnjeg=this;
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::jmbg=jmbg;
        GradjaninBiH::dan_rodjenja=dan;
        GradjaninBiH::mjesec_rodjenja=mjesec;
        GradjaninBiH::godina_rodjenja=godina;
        GradjaninBiH::sifra_regije=regija;
        
        if(isti_dan>=0 && isti_dan<=499) pol=Musko;
        else pol=Zensko;
        long long int jmbg_kopija(jmbg);
        for(int i=12; i>=0; i--)
        {
            c[i]=jmbg_kopija%10;        
            jmbg_kopija/=10;
        }
       
    }
    else{
        GradjaninBiH* pomocni=pok_na_zadnjeg;
        bool ponavlja_se(0);
        for(GradjaninBiH* p=pomocni; p!=nullptr; p=p->veza)
        {
            if(p->jmbg==jmbg)
            ponavlja_se=1;
        }
        if(!ponavlja_se)
        {
             GradjaninBiH::ime_i_prezime=ime_i_prezime;
             GradjaninBiH::jmbg=jmbg;
             GradjaninBiH::dan_rodjenja=dan;
             GradjaninBiH::mjesec_rodjenja=mjesec;
             GradjaninBiH::godina_rodjenja=godina;
             GradjaninBiH::sifra_regije=regija;
             
             if(isti_dan>=0 && isti_dan<=499) pol=Musko;
             else pol=Zensko;
             long long int jmbg_kopija(jmbg);
             for(int i=12; i>=0; i--)
            {
                c[i]=jmbg_kopija%10;        
                jmbg_kopija/=10;
            }
             veza=pok_na_zadnjeg;
             pok_na_zadnjeg=this;
        }
        else{ throw std::logic_error("Vec postoji gradjanin sa istim JMBG"); }
    }
    
    
}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!JeLiDatumValidan(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije>99 || sifra_regije<0)
    throw std::logic_error("Neispravni podaci");
    else {
           
           
            c[1]=dan_rodjenja%10; c[0]=dan_rodjenja/10; 
            c[3]=mjesec_rodjenja%10; c[2]=mjesec_rodjenja/10;
            c[6]=godina_rodjenja%10; c[5]=(godina_rodjenja%100)/10; 
            if(godina_rodjenja<2000)
            c[4]=((godina_rodjenja-1000)/100);
            else c[4]=((godina_rodjenja-2000)/100);
            c[8]=sifra_regije%10;
            c[7]=sifra_regije/10;
            
            if(pok_na_zadnjeg==nullptr){
                pok_na_zadnjeg=this;
                GradjaninBiH::ime_i_prezime=ime_i_prezime;
                GradjaninBiH::dan_rodjenja=dan_rodjenja;
                GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
                GradjaninBiH::godina_rodjenja=godina_rodjenja;
                GradjaninBiH::sifra_regije=sifra_regije;
            if(pol==Musko) { c[9]=0; c[10]=0; c[11]=0; }
            else  { c[9]=5; c[10]=0; c[11]=0; }
            c[12]=(11-(7*(c[0]+c[6])+ 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11);
            jmbg=0;
            for(int i=0; i<12; i++)
            {
                jmbg+=c[i];
                jmbg*=10;
            }
            jmbg+=c[12];
    }
            else{
                GradjaninBiH* pomocni=pok_na_zadnjeg;
                int najmanji_dostupan(0);
                for(GradjaninBiH* p=pomocni; p!=nullptr; p=p->veza)
                    {
                       if(dan_rodjenja==(p->dan_rodjenja) && mjesec_rodjenja==(p->mjesec_rodjenja) && godina_rodjenja==(p->godina_rodjenja) && pol==(p->pol)){
                        int sifra(((p->jmbg)%10000)/10);
                        
                        if(sifra>najmanji_dostupan)
                        najmanji_dostupan=sifra;
                       }
                    }
                    najmanji_dostupan++;
                c[11]=najmanji_dostupan%10; c[10]=(najmanji_dostupan%100)/10; c[9]=najmanji_dostupan/100;
                c[12]=(11-(7*(c[0]+c[6])+ 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11);
                jmbg=0;
            for(int i=0; i<12; i++)
            {
                jmbg+=c[i];
                jmbg*=10;
            }
            jmbg+=c[12];
                GradjaninBiH::ime_i_prezime=ime_i_prezime;
                GradjaninBiH::dan_rodjenja=dan_rodjenja;
                GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
                GradjaninBiH::godina_rodjenja=godina_rodjenja;
                GradjaninBiH::sifra_regije=sifra_regije;
                GradjaninBiH::pol=pol;
                
                veza=pok_na_zadnjeg;
                pok_na_zadnjeg=this;
            
            }
        
        
        
        
        /*GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::sifra_regije=sifra_regije;
        GradjaninBiH::pol=pol;*/
    
        
    }
}
std::string DajImeIPrezime() const { return ime_i_prezime; }
long long int DajJMBG() const { return jmbg; }
int DajDanRodjenja() const { return dan_rodjenja; }
int DajMjesecRodjenja() const { return mjesec_rodjenja; }
int DajGodinuRodjenja() const { return godina_rodjenja;}
int DajSifruRegije() const { return sifra_regije; }
Pol DajPol() const { return pol; }
void PromijeniImeIPrezime(std::string novo_ime){ ime_i_prezime=novo_ime; }
};

int main ()
{
	return 0;
}