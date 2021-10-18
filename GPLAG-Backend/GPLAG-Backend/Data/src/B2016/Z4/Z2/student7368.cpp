/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    std::string ime_i_prezime;
    int nizC[12];
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
    long long int jmbg;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije;
    enum Pol {Musko,Zensko};
    Pol pol;
    void ProvjeriIPostavi(int dan,int mjesec, int godina,int sifra);
    void Provjerijmbg(long long int maticni_broj);
    void ProvjeraKopije(long long int maticni_broj);
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        PromijeniImeIPrezime(ime_i_prezime);
        long long int maticni=jmbg;
        Provjerijmbg(maticni);
        GradjaninBiH::jmbg=jmbg;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        PromijeniImeIPrezime(ime_i_prezime);
        ProvjeriIPostavi(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije);
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        GradjaninBiH::ime_i_prezime=novo_ime;
    }
    std::string DajImeIPrezime() const {return ime_i_prezime;}
    long long int DajJMBG() const {return jmbg;}
    int DajDanRodjenja() const {return dan_rodjenja;}
    int DajMjesecRodjenja() const {return mjesec_rodjenja;}
    int DajGodinuRodjenja() const {
        int datum;
        if (godina_rodjenja<=17) datum=2*1000+godina_rodjenja;
        else datum=1000+godina_rodjenja;
        return datum;
    }
    int DajSifruRegije() const {return sifra_regije;}
    Pol DajPol() const {return pol;}
};
    void GradjaninBiH::ProvjeriIPostavi(int dan,int mjesec, int godina, int sifra){
        int broj_dana[]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (godina%4==0 && ( godina %100 !=0 || godina%400==0)) broj_dana[1]++;
        if (sifra<0 || sifra >99 || godina<1 || godina>2017 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
           throw std::logic_error ("JMBG nije validan");
        
        
}
    void GradjaninBiH::Provjerijmbg(long long int maticni_broj) {
        long long int kopija_maticnog=maticni_broj;
        if (kopija_maticnog<0) throw std::logic_error ("JMBG nije validan");
        int i=0;
        while (kopija_maticnog>0){
           nizC[i]=kopija_maticnog%10;
           kopija_maticnog/=10;
    }
    c1=nizC[0]; c2=nizC[1]; c3=nizC[2]; c4=nizC[3]; c5=nizC[4]; c6=nizC[5]; c7=nizC[6]; c8=nizC[7]; c9=nizC[8]; c10=nizC[9];
    c11=nizC[10]; c12=nizC[11];
    c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
    while (c13>11){
        c13-=11;
    }
}
int main ()
{
	return 0;
}