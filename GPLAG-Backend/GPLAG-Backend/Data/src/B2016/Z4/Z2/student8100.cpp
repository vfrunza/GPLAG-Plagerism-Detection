/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>


bool DaLiJeJMBGFin(long long int jmbg){
    int brojac(0);
    while(jmbg!=0){
        brojac++;
        jmbg/10;
    }
    if(brojac==12) return false;
    return true;
}
/*
void NapraviJMBG(int dan, int mjesec, int god, int sifra, GradjaninBiH::Pol gender, int *&temp){
    //int temp[13];
    int zadnja(0);
    if(dan/10==0){
        zadnja = 11 - (7*(god%10)+6*(dan+sifra/10)+5*(mjesec/10+sifra%10)+4*()+3*()+2*())%11;
        if(zadnja == 10) throw std::logic_error ("JMBG nije validan");
        if(zadnja == 11) zadnja = 0;
        temp[0]=0; temp[1]=dan; temp[2]=mjesec/10; temp[3] = mjesec%10; temp[4]=god%100; temp[5]=(god/10)%10; temp[6]=god%10; temp[7]=sifra/10; temp[8]=sifra%10; temp[9]=; temp[10]=; temp[11]=; temp[12]=zadnja;
    }
    else{
        zadnja = 11 - (7*(dan/10+god%10)+6*(dan%10+sifra/10)+5*(mjesec/10+sifra%10)+4*()+3*()+2*())%11;
        if(zadnja == 10) throw std::logic_error ("JMBG nije validan");
        if(zadnja == 11) zadnja = 0;
        temp[0]=dan/10; temp[1]=dan%10; temp[2]=mjesec/10; temp[3] = mjesec%10; temp[4]=god%100; temp[5]=(god/10)%10; temp[6]=god%10; temp[7]=sifra/10; temp[8]=sifra%10; temp[9]=; temp[10]=; temp[11]=; temp[12]=zadnja;
    }
}*/

class GradjaninBiH{
    private:
        std::string ime_i_prezime;
        int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
        int niyyjmbg[13];
        long long int jmbg1;
    public:
        enum Pol {Musko, Zensko};
        Pol pol;
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
        std::string DajImeIPrezime() const;
        long long int DajJMBG() const;
        int DajDanRodjenja() const;
        int DajMjesecRodjenja() const;
        int DajGodinuRodjenja() const;
        int DajSifruRegije() const;
        Pol DajPol() const;
        void PromijeniImeIPrezime(std::string novo_ime);
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    this->ime_i_prezime = ime_i_prezime;
    this->jmbg1 = jmbg;
    int brojac(12);
    auto temp1 = jmbg;
    while(temp1!=0){
        this->niyyjmbg[brojac]=temp1%10;
        temp1/=10;
        brojac--;
    }
    //if(DaLiJeJMBGFin(jmbg)){
        this->dan_rodjenja = jmbg/1e+11;
        jmbg %= 100000000000;
        this->mjesec_rodjenja = jmbg/1e+9;
        jmbg%=1000000000;
        this->godina_rodjenja = jmbg/1e+6;
        jmbg%=1000000;
        this->sifra_regije = jmbg/1e+4;
        jmbg%=jmbg%10000;
        int temp = jmbg/10;
        if (temp<500) this->pol = Pol::Musko;
        else this->pol = Pol::Zensko;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    this->ime_i_prezime = ime_i_prezime;
    this->dan_rodjenja = dan_rodjenja;
    this->mjesec_rodjenja = mjesec_rodjenja;
    this->godina_rodjenja = godina_rodjenja;
    this->sifra_regije = sifra_regije;
    this->pol = pol;
}

std::string GradjaninBiH::DajImeIPrezime() const{ return ime_i_prezime;}
long long int GradjaninBiH::DajJMBG() const{ return jmbg1; }
int GradjaninBiH::DajDanRodjenja() const{return dan_rodjenja;}
int GradjaninBiH::DajMjesecRodjenja() const{ return mjesec_rodjenja;}
int GradjaninBiH::DajGodinuRodjenja() const{ return godina_rodjenja;}
int GradjaninBiH::DajSifruRegije() const{ return sifra_regije;}
GradjaninBiH::Pol GradjaninBiH::DajPol() const{ return pol;}

struct Cvor{
    GradjaninBiH gradjanin;
    Cvor *prethodni;
};
        
int main (){
	return 0;
}