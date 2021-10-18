/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, broj;
    static GradjaninBiH *posljednji;
    GradjaninBiH *prethodni;
    
    
    public:
    enum Pol {Musko, Zensko} pol;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const { return mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return godina_rodjenja; }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(std::string novo_ime) { this->ime_i_prezime=novo_ime; }
};


GradjaninBiH *GradjaninBiH::posljednji=nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    long long int pomocna=jmbg;
    std::vector<int> v(13);
    int brojac(12);
    while(jmbg!=0){
        v[brojac] = jmbg % 10;
        jmbg/=10;
        brojac--;
    }
    jmbg=pomocna;
    
    int cifra_13=11-(7*(v[0]+v[6])+6*(v[1]+v[7])+5*(v[2]+v[8])+4*(v[3]+v[9])+3*(v[4]+v[10])+2*(v[5]+v[11]))%11;
    if(cifra_13==11){
        cifra_13=0;
    }
    if(cifra_13!=v[12]){
        throw std::logic_error("JMBG nije validan");
    }
    dan_rodjenja=v[0]*10+v[1];
    mjesec_rodjenja=v[2]*10+v[3];
    godina_rodjenja=(v[4]*10+v[5])*10+v[6];
    if(godina_rodjenja<=17){
        godina_rodjenja+=2000;
    }
    else{
        godina_rodjenja+=1000;
    }
    
    
     if(mjesec_rodjenja<1 || mjesec_rodjenja>12){
        throw std::logic_error("JMBG nije validan");
    }
    
    int februar=28;
    if(godina_rodjenja%4==0 && godina_rodjenja%100!=0 || godina_rodjenja%400==0){
        februar=29;
    }
    
    
    std::vector<int> br_dana {31,februar,31,30,31,30,31,31,30,31,30,31};
    if(dan_rodjenja>br_dana[mjesec_rodjenja-1]){
        throw std::logic_error("JMBG nije validan");
    }
    
    if(godina_rodjenja<1917 ||godina_rodjenja>2017){
        throw std::logic_error("JMBG nije validan");
    }
    
    this->ime_i_prezime=ime_i_prezime;
    this->jmbg=jmbg;
    
    int spol=(v[9]*10+v[10])*10+v[11];
    if(spol>=0 && spol<=499){
        pol=Pol::Musko;
    }
    else{
        pol=Pol::Zensko;
    }
    
    
    sifra_regije=v[7]*10+v[8];
    
    
    
    prethodni=posljednji;
    posljednji=this;
}







GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    this->ime_i_prezime=ime_i_prezime;
    if(mjesec_rodjenja<1 || mjesec_rodjenja>12){
        throw std::logic_error("Neispravni podaci");
    }
    
    int februar=28;
    if(godina_rodjenja%4==0 && godina_rodjenja%100!=0 || godina_rodjenja%400==0){
        februar=29;
    }
    
     std::vector<int> br_dana {31,februar,31,30,31,30,31,31,30,31,30,31};
    if(dan_rodjenja>br_dana[mjesec_rodjenja-1]){
        throw std::logic_error("Neispravni podaci");
    }
    
    if(godina_rodjenja<1917 || godina_rodjenja>2017){
        throw std::logic_error("Neispravni podaci");
    }
    
    if(sifra_regije<0 || sifra_regije>99){
        throw std::logic_error("Neispravni podaci");
    }
    
    std::vector<int> v(13);
    int brojac{};
    v[0]=dan_rodjenja/10;
    v[1]=dan_rodjenja%10;
    v[2]=mjesec_rodjenja/10;
    v[3]=mjesec_rodjenja%10;
    v[4]= godina_rodjenja < 2000 ? (godina_rodjenja-1000)/100 : (godina_rodjenja-2000)/100;
    v[5]=(godina_rodjenja/10)%10;
    v[6]=godina_rodjenja%10;
    v[7]=sifra_regije/10;
    v[8]=sifra_regije%10;
    int broj2;
    if(pol == Pol::Musko) broj = 0;
    else broj = 500;
    GradjaninBiH* pok = posljednji;
    while(pok != nullptr){
        if(pok->DajSifruRegije() == sifra_regije && pok->DajPol() == pol &&
            pok->DajDanRodjenja() == dan_rodjenja && pok->DajMjesecRodjenja() == mjesec_rodjenja
            && pok->DajGodinuRodjenja() == godina_rodjenja && pok->broj == broj2){
                broj2++;
                pok = posljednji;
            }
        else pok = pok->prethodni;
    }
    this->broj = broj2;
    v[9] = broj2 / 100;
    v[10] = (broj2/10) % 10;
    v[11] = broj2%10;
    v[12] = 11-(7*(v[0]+v[6])+6*(v[1]+v[7])+5*(v[2]+v[8])+4*(v[3]+v[9])+3*(v[4]+v[10])+2*(v[5]+v[11]))%11;
    if(v[12]==11){
        v[12]=0;
    }
    prethodni=posljednji;
    posljednji=this;
 }










int main(){
    
    
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    std::cin>>n;
    std::cin.ignore(100000, '\n');
    
   OVDJE:try{
    int brojac{};
    while(brojac!=n){
    std::cout<<"Unesite ime i prezime (u istom redu): ";
    std::string ime_i_prezime;
    std::getline(std::cin, ime_i_prezime);
    
    long long int jmbg;
    std::cout<<"Unesite JMBG: ";
    std::cin>>jmbg;
    std::cin.ignore(100000, '\n');
    
    GradjaninBiH gradjanin(ime_i_prezime, jmbg);
    brojac++;
    std::cout<<"Unijeli ste gradjanina "<<gradjanin.DajImeIPrezime()<<" rodjenog "<<gradjanin.DajDanRodjenja()<<
    "."<<gradjanin.DajMjesecRodjenja()<<"."<<gradjanin.DajGodinuRodjenja()<<" u regiji "<<gradjanin.DajSifruRegije()<<", "<<gradjanin.DajPol()<<"."<<std::endl;
    
   }
}




catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
    } goto OVDJE; 

    
    return 0;
}


    