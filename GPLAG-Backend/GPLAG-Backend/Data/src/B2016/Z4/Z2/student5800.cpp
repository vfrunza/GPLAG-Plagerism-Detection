/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

class GradjaninBiH{
    public:enum Pol {Musko, Zensko};
    private:
    static  GradjaninBiH* zadnji;
    std::string ime_prezime;
    long long int JMBG;
    Pol pol;
    GradjaninBiH* prethodni=nullptr;
    public:
explicit GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol);
 GradjaninBiH(const GradjaninBiH &g)=delete;
std::string DajImeIPrezime() const;
~GradjaninBiH();
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;
void PromijeniImeIPrezime(std::string novo_ime);

};
bool ProvjeriDatum(int d, int m, int g) {
    int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw "Neispravan datum!";
    return true;
}
int UstimaniMrtvaci(long long int a,int n){
    int c;
    for(int i=0;i<n;i++){
        c=a%10;
        a/=10;
    }
    return c;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int dan=UstimaniMrtvaci(jmbg,13)*10+UstimaniMrtvaci(jmbg,12);
    int mjesec=UstimaniMrtvaci(jmbg,11)*10+UstimaniMrtvaci(jmbg,10);
    int god= UstimaniMrtvaci(jmbg,9)*100+UstimaniMrtvaci(jmbg,8)*10+UstimaniMrtvaci(jmbg,7);
    if(god<18)god+=2000;
    else god+=1000;
    try{ProvjeriDatum(dan,mjesec,god);}
    catch(...){
        throw std::logic_error("JMBG nije validan");
    }
    int c=11-(7* (UstimaniMrtvaci(jmbg,13) +UstimaniMrtvaci(jmbg,7) )+6* (UstimaniMrtvaci(jmbg,12) + UstimaniMrtvaci(jmbg,6) )+5* (UstimaniMrtvaci(jmbg,11) +UstimaniMrtvaci(jmbg,5) )+4* (UstimaniMrtvaci(jmbg,10) +UstimaniMrtvaci(jmbg,4) )+3* (UstimaniMrtvaci(jmbg,9) +UstimaniMrtvaci(jmbg,3) )+2* (UstimaniMrtvaci(jmbg,8) +UstimaniMrtvaci(jmbg,2) ))%11;
    if(c==10)throw std::logic_error("JMBG nije validan");
    if(c==11)c=0;
    for(auto it=zadnji;it!=nullptr;it=it->prethodni){
        if(it->JMBG==jmbg)throw std::domain_error("Vec postoji gradjanin sa istim JMBG");
    }
    if(zadnji==nullptr){
        zadnji=this;
    }
    else{
        this->prethodni=zadnji;
        zadnji=this;
    }
    //std::cout<<zadnji->DajImeIPrezime();
    ime_prezime=ime_i_prezime;
    JMBG=jmbg;
    if(UstimaniMrtvaci(JMBG,4)*100+UstimaniMrtvaci(JMBG,3)*10+UstimaniMrtvaci(JMBG,2)<500)pol=Pol::Musko;
    else pol=Pol::Zensko;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol){
    ime_prezime=ime_i_prezime;
    long long int jmbg=0;
    try{
        if(ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)){
            jmbg+=dan_rodjenja*pow(10,11);
            jmbg+=mjesec_rodjenja*pow(10,9);
            if(godina_rodjenja>2000)godina_rodjenja-=2000;
            else godina_rodjenja-=1000;
            jmbg+=godina_rodjenja*pow(10,6);
        }
    }
    catch(...){
        throw std::logic_error("Neispravni podaci");
    }
    if(sifra_regije>0 && sifra_regije<100){
        jmbg+=sifra_regije*pow(10,4);
    }
    else throw std::logic_error("Neispravni podaci");
    if(pol==Pol::Musko){
        int ss=0;
        PON1:
        jmbg+=ss*10;
        int c=11-(7* (UstimaniMrtvaci(jmbg,13) +UstimaniMrtvaci(jmbg,7) )+6* (UstimaniMrtvaci(jmbg,12) + UstimaniMrtvaci(jmbg,6) )+5* (UstimaniMrtvaci(jmbg,11) +UstimaniMrtvaci(jmbg,5) )+4* (UstimaniMrtvaci(jmbg,10) +UstimaniMrtvaci(jmbg,4) )+3* (UstimaniMrtvaci(jmbg,9) +UstimaniMrtvaci(jmbg,3) )+2* (UstimaniMrtvaci(jmbg,8) +UstimaniMrtvaci(jmbg,2) ))%11;
    if(c==10)throw std::logic_error("JMBG nije validan");
    if(c==11)c=0;
    jmbg+=c;
    try{
        for(auto it=zadnji;it!=nullptr;it=it->prethodni){
        if(it->JMBG==jmbg)throw std::domain_error("Vec postoji gradjanin sa istim JMBG");
    }
    }
    catch(...){
        ss++;
        goto PON1;
    }
    }
    else{
       int ss=500;
        PON2:
        jmbg+=ss*10;
        int c=11-(7* (UstimaniMrtvaci(jmbg,13) +UstimaniMrtvaci(jmbg,7) )+6* (UstimaniMrtvaci(jmbg,12) + UstimaniMrtvaci(jmbg,6) )+5* (UstimaniMrtvaci(jmbg,11) +UstimaniMrtvaci(jmbg,5) )+4* (UstimaniMrtvaci(jmbg,10) +UstimaniMrtvaci(jmbg,4) )+3* (UstimaniMrtvaci(jmbg,9) +UstimaniMrtvaci(jmbg,3) )+2* (UstimaniMrtvaci(jmbg,8) +UstimaniMrtvaci(jmbg,2) ))%11;
    if(c==10)throw std::logic_error("JMBG nije validan");
    if(c==11)c=0;
    jmbg+=c;
    try{
        for(auto it=zadnji;it!=nullptr;it=it->prethodni){
        if(it->JMBG==jmbg)throw std::domain_error("Vec postoji gradjanin sa istim JMBG");
    }
    }
    catch(...){
        ss++;
        goto PON2;
    }
    }
    if(zadnji==nullptr){
        zadnji=this;
    }
    else{
        this->prethodni=zadnji;
        zadnji=this;
    }
    //std::cout<<zadnji->DajImeIPrezime();
    ime_prezime=ime_i_prezime;
    JMBG=jmbg;
    //std::cout<<jmbg;
 }
 std::string GradjaninBiH::DajImeIPrezime() const{
    return ime_prezime;
}
GradjaninBiH::~GradjaninBiH(){
    auto it=zadnji;
    while(it!=this ){
        it=it->prethodni;
    }
    it->prethodni=this->prethodni;
}
long long int GradjaninBiH::DajJMBG() const{
    return JMBG;
}
int GradjaninBiH::DajDanRodjenja() const{
    return UstimaniMrtvaci(JMBG,13)*10+UstimaniMrtvaci(JMBG,12);
}
int GradjaninBiH::DajMjesecRodjenja() const{
    return UstimaniMrtvaci(JMBG,11)*10+UstimaniMrtvaci(JMBG,10);
}
int GradjaninBiH::DajGodinuRodjenja() const{
    int god= UstimaniMrtvaci(JMBG,9)*100+UstimaniMrtvaci(JMBG,8)*10+UstimaniMrtvaci(JMBG,7);
    if(god<18)god+=2000;
    else god+=1000;
    return god;
}
int GradjaninBiH::DajSifruRegije() const{
    return UstimaniMrtvaci(JMBG,6)*10+UstimaniMrtvaci(JMBG,5);
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    return pol;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    ime_prezime=novo_ime;
}
GradjaninBiH *GradjaninBiH::zadnji=nullptr;
int main ()
{
	std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++){
	    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
	    std::string ime;
	    std::cin.clear();
	    std::cin.ignore(100000,'\n');
	    std::getline(std::cin,ime);
	    std::cout<<"Unesite JMBG: "<<std::endl;
	    long long int jmbg;
	    std::cin>>jmbg;
	    try{
	    GradjaninBiH a(ime,jmbg);
	    std::cout<<"Unijeli ste gradjanina "<<a.DajImeIPrezime()<<" rodjenog "<<a.DajDanRodjenja()<<"."<<a.DajMjesecRodjenja()<<"."<<a.DajGodinuRodjenja()<<" u regiji "<<a.DajSifruRegije()<<", ";
	    if(a.DajPol()==GradjaninBiH::Pol::Musko)std::cout<<"musko."<<std::endl;
	    else std::cout<<"zensko."<<std::endl;
	    }
	    catch(std::logic_error e){
	        std::cout<<e.what()<<std::endl;
	        i--;
	    }
	}
	std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
	int m;
	std::cin>>m;
	for(int i=0;i<m;i++){
	    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
	    std::string ime;
	    std::cin.clear();
	    std::cin.ignore(100000,'\n');
	    std::getline(std::cin,ime);
	    std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
	    int dan,mjesec,godina;
	    char c1,c2;
	    std::cin>>dan>>c1>>mjesec>>c2>>godina;
	    std::cout<<"Unesite sifru regije: "<<std::endl;
	    int sr;
	    std::cin>>sr;
	    std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
	    char p;
	    std::cin>>p;
	    try{
	        if(p=='M'){
	        GradjaninBiH b(ime,dan,mjesec,godina,sr,GradjaninBiH::Pol::Musko);
	        std::cout<<"Unijeli ste gradjanina "<<b.DajImeIPrezime()<<" JMBG: "<<b.DajJMBG()<<"."<<std::endl;
	        }
	        else{
	        GradjaninBiH b(ime,dan,mjesec,godina,sr,GradjaninBiH::Pol::Zensko);
	        std::cout<<"Unijeli ste gradjanina "<<b.DajImeIPrezime()<<" JMBG: "<<b.DajJMBG()<<"."<<std::endl;
	        }
	    }
	    catch(std::logic_error e){
	        std::cout<<e.what()<<std::endl;
	        i--;
	    }
	}
    return 0;
}