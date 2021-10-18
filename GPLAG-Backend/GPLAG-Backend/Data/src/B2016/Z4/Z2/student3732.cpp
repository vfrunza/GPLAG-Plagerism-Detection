/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <new>
#define vector !zabranjeno!!
#define deque !zabranjeno!!
#define list !zabranjeno!!
#define set !zabranjeno!!
#define map !zabranjeno!!


class GradjaninBiH{
    public:
     enum Pol {Musko, Zensko};
     private:
    std::string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    long long int jmbg;
    int kod_osobe;
    GradjaninBiH *prethodni=nullptr;
    Pol pol;
    public:
    static GradjaninBiH* posljednji;
GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol);
std::string DajImeIPrezime() const{
    return ime_i_prezime;
}
~GradjaninBiH(){
    if(this==posljednji) posljednji=posljednji->prethodni;
    else{
    GradjaninBiH *poslje=posljednji;
    while(poslje->prethodni!=nullptr&&poslje->prethodni!=this) poslje=poslje->prethodni;
    poslje->prethodni=this->prethodni;
    }
}
long long int DajJMBG() const{
    return jmbg;
}
int DajDanRodjenja() const {
    return dan_rodjenja;
}
int DajMjesecRodjenja() const{
    return mjesec_rodjenja;
}
int DajGodinuRodjenja() const{
    int tmp=godina_rodjenja;
    if(tmp>=917){ tmp+=1000; return tmp;}
    if(tmp<=17){ tmp+=2000; return tmp;}
    return tmp+1000;
    
}
int DajSifruRegije() const{
    return sifra_regije;
}
Pol DajPol() const{
    return pol;
}
void PromijeniImeIPrezime(std::string novo_ime){
    ime_i_prezime=novo_ime;
}
};
GradjaninBiH* GradjaninBiH::posljednji = nullptr;
bool ispravan_datum(int d,int m,int g){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
    return true;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
     if((jmbg<0||int(log10(jmbg))<11||int(log10(jmbg))>12)) throw std::logic_error("JMBG nije validan");
        auto pok=posljednji;
    while(pok!=nullptr){
        if(jmbg==pok->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pok=pok->prethodni;
    }
    auto tmp=jmbg;
    int niz[13],i{};
    if(int(log10(jmbg))+1==12){
        niz[i]=0; i++;
    }
    while(tmp!=0){
        niz[i]=tmp%10;
        tmp/=10;
        i++;
        
    }
    int cifre[13];
    for(int j{};j<13;j++) cifre[j]=niz[13-j-1];
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    int c13=11-(7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11;
    if(c13==11) c13=0;
    if(c13==10||c13!=cifre[12]) throw std::logic_error("JMBG nije validan");
    int dan=cifre[1]+cifre[0]*10;
    int mjesec=cifre[3]+cifre[2]*10;
    int godina=cifre[4]*100+cifre[5]*10+cifre[6];
    if(!ispravan_datum(dan,mjesec,godina)) throw std::logic_error("JMBG nije validan");
    godina_rodjenja=godina; dan_rodjenja=dan; mjesec_rodjenja=mjesec;
    int sifra=cifre[7]*10+cifre[8];
    GradjaninBiH::sifra_regije=sifra;
    int tmp2=cifre[9]*100+cifre[10]*10+cifre[11];
    kod_osobe=tmp2;
    if(tmp2>=0&&tmp2<500) pol=Pol::Musko;
    else pol=Pol::Zensko;
    GradjaninBiH::jmbg=jmbg;
    prethodni=posljednji;
    posljednji=this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
    if(!ispravan_datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)||sifra_regije<0||sifra_regije>99) throw std::logic_error("Neispravni podaci");
    GradjaninBiH::ime_i_prezime=ime_i_prezime; GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::sifra_regije=sifra_regije;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::pol=pol;
    auto pok=posljednji;
    int min;
    if(pol==Pol::Musko) min=0;
    else min=500;
    while(pok!=nullptr){
        if(pol==pok->pol&&dan_rodjenja==pok->dan_rodjenja&&sifra_regije==pok->sifra_regije&&min==pok->kod_osobe) min++;
        pok=pok->prethodni;
    }
    int niz1[3],z{};
    while(z!=3){
        niz1[z]=godina_rodjenja%10;
        godina_rodjenja/=10;
        z++;
    }
    godina_rodjenja=0;
    for(int j=2;j>=0;j--) godina_rodjenja=godina_rodjenja*10+niz1[j];
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    kod_osobe=min;
    long long int JMBG{dan_rodjenja};
    JMBG*=100; JMBG+=mjesec_rodjenja;
    JMBG*=1000; JMBG+=godina_rodjenja;
    JMBG*=100; JMBG+=sifra_regije;
    JMBG*=1000; JMBG+=kod_osobe;
    JMBG*=10;
    int niz[13],i{};
    if(int(log10(JMBG))+1==12){
        niz[i]=0; i++;
    }
    long long int tmp=JMBG;
    while(tmp!=0){
        niz[i]=tmp%10;
        tmp/=10;
        i++;
    }
    int cifre[13];
    for(int j{};j<13;j++) cifre[j]=niz[13-j-1];
int c13=11-(7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11;
    if(c13==11) c13=0;
    JMBG+=c13;
    jmbg=JMBG;
    prethodni=posljednji;
    posljednji=this;
}

int main(){
std::vector<int> bla;
    
  GradjaninBiH g("Gigo Bosnic", 1,1,2016, 20, GradjaninBiH::Pol::Zensko);
  std::cout << g.DajJMBG() << std::endl;
        
        /*GradjaninBiH g("Gile Sampion", 14,12,1994, 17, GradjaninBiH::Pol::Musko);
        std::cout << g.DajJMBG() << std::endl;
        GradjaninBiH g1("Gile Sampion", 16,12,1994, 17, GradjaninBiH::Pol::Musko);;
        std::cout << g1.DajJMBG() << std::endl;
        //jmbg kad je prvi januar i slicno
*/
}

int _main (){
    
    std::cout << "Koliko gradjana zelite unijeti po JMBG? "<< std::endl;
    int br1;
    std::cin >> br1;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    
    std::string ime;
    long long int jmbg;
    for(int i=0; i<br1; i++){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;  std::getline(std::cin, ime);
        std::cout << "Unesite JMBG: " << std::endl; std::cin >> jmbg;
        try{ 
            GradjaninBiH g1(ime, jmbg);
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unijeli ste gradjanina " << g1.DajImeIPrezime() << " rodjenog " << g1.DajDanRodjenja() << "." << g1.DajMjesecRodjenja() << "." << g1.DajGodinuRodjenja() << " u regiji " << g1.DajSifruRegije() << ", " ;
        if(g1.DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko." << std::endl;
        else std::cout << "zensko."<< std::endl;
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        
        ime.erase();
    }
    
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    int br2;
    std::cin >> br2;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    
    std::string ime_i_prezime;
    int dan, mjesec, god, sifra;
    char spol, gutac;
    GradjaninBiH::Pol pol;
    for(int i=0; i<br2; i++){
        std::cout << "Unesite ime i prezime (u istom redu): "<< std::endl; std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl; std::cin >> dan; std::cin >> gutac; std::cin >> mjesec; std::cin >> gutac; std::cin >> god;
        std::cout << "Unesite sifru regije: " << std::endl; std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: "<< std::endl; std::cin >> spol; if(spol == 'M') pol = GradjaninBiH::Pol::Musko; if(spol == 'Z') pol = GradjaninBiH::Pol::Zensko;
        try{
            auto g2 = GradjaninBiH(ime_i_prezime, dan, mjesec, god, sifra, pol);
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unijeli ste gradjanina " << g2.DajImeIPrezime() << " JMBG: " << g2.DajJMBG() << "." << std::endl; 
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        
    }
    
	return 0;
}