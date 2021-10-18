/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::cin;
using std::cout;


class GradjaninBiH{
    std::string ime_i_prezime;
    int JMBG[13];
    GradjaninBiH *prethodni=nullptr;
    static GradjaninBiH *posljednji;
    
    bool IspravnostDatuma(int dan, int mjesec, int godina);
    int DajDan()const { return JMBG[0]*10+JMBG[1];}
    int DajMjesec() const { return JMBG[2]*10+JMBG[3];}
    int DajGodinu()const { int vrati(JMBG[4]*100+JMBG[5]*10+JMBG[6]); if(vrati>17) return 1000+vrati; return 2000+vrati;}
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol):ime_i_prezime(ime_i_prezime){
        if(IspravnostDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false || sifra_regije<0 || sifra_regije>99)
            throw std::logic_error("Neispravni podaci");
    }
    std::string DajImeIPrezime() const{ return ime_i_prezime;}
    long long int DajJMBG() const{return JMBG;}
    int DajDanRodjenja() const{ return DajDan();}
    int DajMjesecRodjenja() const{ return DajMjesec();}
    int DajGodinuRodjenja() const{return DajGodinu();}
    GradjaninBiH(const GradjaninBiH &gr) = delete;
    GradjaninBiH &operator=(const GradjaninBiH &gr) = delete;
}; 

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg): ime_i_prezime(ime_i_prezime) {
    if(int(log10(jmbg))+1!=12 || int(log10(jmbg))+1!=13)
        throw std::logic_error("JMBG nije validan");
    for(int i=12; i>=0; i++){
            JMBG[i]=jmbg%10;
            jmbg/=10;
    }
    if(int(log10(jmbg))+1==12)
        JMBG[0]=0;
    int zadnjacifra=11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11;
    if(zadnjacifra==11)
        zadnjacifra=0;
    if(IspravnostDatuma(DajDan(),DajMjesec(),DajGodinu())==false || zadnjacifra==10 || JMBG[12]!=zadnjacifra)
        throw std::logic_error("JMBG nije validan");
    //ukoliko postoji gradjanin s istim br JMBG isto se baca izuzetak
}


bool GradjaninBiH::IspravnostDatuma(int dan, int mjesec, int godina){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) br_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>br_dana[mjesec-1])
        return false;
    return true;
}

int main (){
    
    try{
        GradjaninBiH g{"Manara", 131399613156};       
    }
    catch(std::logic_error izuzetak){
        cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}