/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdexcept>

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    bool ProvjeraDatuma(int d,int m,int god){
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(god%4==0 && (god%100!=0 || god%400==0))   {broj_dana[1]++;}
        if(god<1 || m <1 || m>12 || d<1 || d>broj_dana[m-1]){
            return false;
        }
        return true;
    }
    bool ProvjeraJMBG(long long int jmbg){
        GradjaninBiH::jmbg=jmbg;
        int kod(jmbg%100);
        int d=DajDanRodjenja();
        int m=DajMjesecRodjenja();
        int g=DajGodinuRodjenja();
        int sif=DajSifruRegije();
        int pol=DajPol();
        if(ProvjeraDatuma(d,m,g)==false || !(sif>=0 && sif<100) || !(pol>=0 && pol<=1) || kod==11 || kod==10){ GradjaninBiH::jmbg=0;return false;}
        return true;
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije,Pol pol);
    long long int DajJMBG()const {return jmbg;}
    std::string DajImeIPrezime() const{return ime_i_prezime;}
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime){GradjaninBiH::ime_i_prezime=novo_ime;}
};
GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    long long int kopija(jmbg);
    kopija%=1000;
    kopija/=10;
    if(kopija>=0 && kopija <=499) return Pol(0);
    return Pol(1);    
}
int GradjaninBiH::DajSifruRegije() const{
    long long int kopija(jmbg);
    kopija%=1000000;
    kopija/=10000;
    return kopija;    
}
int GradjaninBiH::DajGodinuRodjenja() const{
    long long int kopija(jmbg);
    kopija/=1000000;
    int dan(DajDanRodjenja());
    int mjesec(DajMjesecRodjenja());
    dan*=100000;
    dan+=(mjesec*1000);
    kopija=kopija-dan;
    if(kopija>=117 && kopija<=999) kopija+=1000;
    if(kopija>=0 && kopija<=116) kopija+=2000;
    return kopija;    
}
int GradjaninBiH::DajMjesecRodjenja() const{
    long long int kopija(jmbg);
    kopija/=1000000000;
    int dan(DajDanRodjenja());
    kopija= kopija-(dan*100);
    return kopija;    
}
int GradjaninBiH::DajDanRodjenja() const{
    long long int kopija(jmbg);
    kopija/=100000000000;
    return kopija;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije,Pol pol){
        PromijeniImeIPrezime(ime_i_prezime);
        if(!(ProvjeraDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) || !(sifra_regije>=0 && sifra_regije<100)) {throw std::domain_error("Neispravni podaci");}
        int kopija(godina_rodjenja);
        if(godina_rodjenja/1000==1) kopija=godina_rodjenja-1000;
        if (godina_rodjenja/1000==2) {kopija=godina_rodjenja-2000; }
        
        jmbg=dan_rodjenja*100000000000+(long long int)mjesec_rodjenja*1000000000+kopija*1000000+sifra_regije*10000+pol*1000;
        
    }
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    if(!(ProvjeraJMBG(jmbg))) throw std::logic_error("JMBG nije validan");
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::jmbg=jmbg;
}   

int main (){
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    int n=0;
    std::cin>>n;
    if(n<0) {std::cout<<"\nNeispravan parametar"; return 0;}

    for(int i=0;i<n;i++){
        try{
            std::cout<<"\nUnesite ime i prezime (u istom redu): ";
            std::cin.ignore(10000, '\n');
            
            std::string ime;
            std::getline(std::cin, ime);
            
            std::cout<<"\nUnesite JMBG: ";
            long long int jmbg=0;
            std::cin>>jmbg;
            GradjaninBiH a(ime, jmbg);
            std::cout<<"\nUnijeli ste gradjanina "<<a.DajImeIPrezime()<<" rodjenog "<<a.DajDanRodjenja()<<"."<<a.DajMjesecRodjenja()<<"."<<a.DajGodinuRodjenja()<<" u regiji "<<a.DajSifruRegije()<<", ";
            if(a.DajPol()==0) {std::cout<<"musko.";}
            if(a.DajPol()==1) {std::cout<<"zensko.";}
        }catch(std::domain_error izu){
            std::cout<<izu.what();i--;
        }
    }
	return 0;
}