/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
enum Pol {Musko, Zensko};
long long int NapraviJMBG();
int KontrolaDrugiKonstruktor(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) return 1;     //neispravan datum
    return 0;
}
int KontrolaDatuma(long long int jmbg) {
    int niz[13];
    int brojac(12), pomocni, dan, mjesec, godina;
    while(jmbg>0) {
        pomocni=jmbg%10;
        jmbg/=10;
        niz[brojac]=pomocni;
        brojac--;
    }
    if(brojac==0) niz[0]=0;
    dan=niz[0]*10+niz[1];
    mjesec=niz[2]*10+niz[3];
    godina=niz[4]*100+niz[6]*10+niz[7];
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) return 1;         //neispravan datum
    return 0;
}
int KontrolaJMBG(long long int jmbg) {
    int niz[13], kontrola;
    int brojac(12), pomocni;
    while(jmbg>0) {
        pomocni=jmbg%10;
        jmbg/=10;
        niz[brojac]=pomocni;
        brojac--;
    }
    if(brojac==0) niz[0]=0;
    kontrola=(11-(7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11])))%11;
    if((kontrola==11 && niz[12]==0) || kontrola==niz[12]) return 0;             //ispravan
    else if(kontrola==10) return 1;
    return 1;
}
class GradjaninBiH {
        std::string ime_i_prezime;
        long long int jmbg;
        int dan_rodjenja, mjesec_rodjenja, godina_rodjenja;
        int sifra_regije;
        Pol pol {Musko};
        GradjaninBiH *pok_na_prethodnog;
        static GradjaninBiH *pok_na_posljednjeg;
    public: 
        enum Pol {Musko, Zensko};
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
            GradjaninBiH::ime_i_prezime=ime_i_prezime;
            if(KontrolaDatuma(jmbg) != 0 || KontrolaJMBG(jmbg) != 0) throw std::logic_error("JMBG nije validan");
            GradjaninBiH::jmbg=jmbg;
        }
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol): pol(Pol::pol) {
            GradjaninBiH::ime_i_prezime=ime_i_prezime;
            if(KontrolaDrugiKonstruktor(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)==1 || !(sifra_regije>=0 && sifra_regije<100)) throw std::logic_error("Neipravni podaci");
            GradjaninBiH::dan_rodjenja=dan_rodjenja; GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja; GradjaninBiH::godina_rodjenja=godina_rodjenja;
            GradjaninBiH::sifra_regije=sifra_regije;
            //GradjaninBiH::pol=pol;
        }
        std::string DajImeIPrezime() const {return ime_i_prezime; }
        long long int DajJMBG() const {return jmbg; }
        int DajDanRodjenja() const {return dan_rodjenja; }
        int DajMjesecRodjenja() const {return mjesec_rodjenja; }
        int DajGodinuRodjenja() const {return godina_rodjenja; }
        int DajSifruRegije() const {return sifra_regije; }
        Pol DajPol() const { /*return pol;*/};
        void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime=novo_ime; }
};
int main (){
    GradjaninBiH *niz[100];
    std::cout << "Stafa kralj";
	return 0;
}