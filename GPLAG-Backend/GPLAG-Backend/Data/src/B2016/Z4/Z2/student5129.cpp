/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int kod;
    int sifra_regije;
    int pol;
    // Pokazivac na proslog unesenog
    GradjaninBiH* prethodni;
    // Staticka varijabla koja pokazuje na trenutnog prethodnog
    static GradjaninBiH* prosli;
    static GradjaninBiH* zadnji;
    
    // Vraca broj cifara JMBG
    int BrojCifara(long long int jmbg){
        int broj_cifara(0);
        while(jmbg){
            jmbg/=10;
            broj_cifara++;
        }
        return broj_cifara;
    }
    
    // Vrati JMBG kao niz od 13 elemenata
    int NapraviNiz(int niz[], long long int jmbg) const {
        for(int i=12; i>=0; i--){
            niz[i] = jmbg%10;
            jmbg /= 10;
        }
        
        return *niz;
    }
    
    // Provjerava datum
    bool IspravanDatum(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(dan<1 || dan>broj_dana[mjesec-1]) return false;
        if(mjesec<1 || mjesec>12) return false;
        // 1907-2017 je dozvoljeni opseg godina
        if(godina>17 && godina <907) return false;
        return true;
    }
    
    // Zabranjivanje kopirajuceg konstruktora
    GradjaninBiH(GradjaninBiH &osoba) = delete;
    // Zabranjivanje dodjele
    void operator=(GradjaninBiH &osoba);
    
public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        int broj_cifara(BrojCifara(jmbg));
        if(broj_cifara>13 || broj_cifara<12) throw std::logic_error("JMBG nije validan");
        
        int niz[13];
        NapraviNiz(niz, jmbg);
        
        int dan(niz[0]*10 + niz[1]), mjesec(niz[2]*10 + niz[3]), godina(niz[4]*100 + niz[5]*10 + niz[6]);
        if(!IspravanDatum(dan, mjesec, godina)) throw std::logic_error("JMBG nije validan");
        
        int trinaesta(11 - (7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11]))%11);
        if(trinaesta==11) trinaesta=0;
        if(trinaesta!=niz[12]) throw std::logic_error("JMBG nije validan");
        
        prethodni=prosli;
        auto temp(prethodni);
        while(temp){
            if(jmbg == temp->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            temp = temp->prethodni;
        }
        
        prosli=this;
        zadnji=this;
        this->ime_i_prezime = ime_i_prezime;
        this->jmbg = jmbg;
        
        dan_rodjenja=dan;
        mjesec_rodjenja=mjesec;
        godina_rodjenja=godina;
        GradjaninBiH::sifra_regije=niz[7]*10 + niz[8];
        kod=niz[9]*100 + niz[10]*10 + niz[11];
        if(kod<500) pol=Musko;
        else pol=Zensko;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        // Postavljanje trocifrenog koda koji ovisi o spolu osobe
        if(pol==Musko) kod=0;
        else if(pol==Zensko) kod=500;
        auto temp(zadnji);
        while(temp){
            if(temp->dan_rodjenja==dan_rodjenja && temp->mjesec_rodjenja==mjesec_rodjenja && temp->godina_rodjenja==godina_rodjenja && temp->sifra_regije==sifra_regije && temp->pol==pol) kod++;
            temp = temp->prethodni;
        }
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
        if(godina_rodjenja<=17) godina_rodjenja-=2000;
        else godina_rodjenja-=1000;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::sifra_regije=sifra_regije;
        if(kod<500) GradjaninBiH::pol=Musko;
        else GradjaninBiH::pol=Zensko;
        
        jmbg=(dan_rodjenja*100000000000 + mjesec_rodjenja*1000000000 + godina_rodjenja*1000000 + sifra_regije*10000 + kod*10)*10;
        int niz[13];
        NapraviNiz(niz, jmbg);
        int trinaesta(11 - (7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11]))%11);
        if(trinaesta==11) trinaesta=0;
        jmbg=dan_rodjenja*100000000000 + mjesec_rodjenja*1000000000 + godina_rodjenja*1000000 + sifra_regije*10000 + kod*10 + trinaesta;
        
        // Uvezivanje
        prethodni=prosli;
        prosli=this;
        zadnji=this;
    }
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    // Komentari ispod su od prethodne verzije programa koja je jedino imala JMBG kao atribut (pored pokazivaca)
    int DajDanRodjenja() const {
        /* int niz[13];
        NapraviNiz(niz, jmbg);
        int dan(niz[0]*10 + niz[1]);
        return dan; */
        return dan_rodjenja;
    }
    int DajMjesecRodjenja() const {
        /* int niz[13];
        NapraviNiz(niz, jmbg);
        return niz[2]*10 + niz[3]; */
        return mjesec_rodjenja;
    }
    int DajGodinuRodjenja() const {
        /* int niz[13];
        NapraviNiz(niz, jmbg);
        int godina(niz[4]*100 + niz[5]*10 + niz[6]);
        if(godina<=17) godina+=2000;
        else godina+=1000;
        return godina; */
        if(godina_rodjenja<=17) return 2000+godina_rodjenja;
        else return 1000+godina_rodjenja;
    }
    int DajSifruRegije() const {
        /* int niz[13];
        NapraviNiz(niz, jmbg);
        return niz[7]*10 + niz[8]; */
        return sifra_regije;
    }
    Pol DajPol() const {
        /* int niz[13];
        NapraviNiz(niz, jmbg);
        if (niz[9]<5) return Musko;
        else return Zensko; */
        if(kod<500) return Musko;
        else return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){ ime_i_prezime=novo_ime; }
};

GradjaninBiH* GradjaninBiH::prosli = nullptr;
GradjaninBiH* GradjaninBiH::zadnji = nullptr;

int main (){
    
	return 0;
}