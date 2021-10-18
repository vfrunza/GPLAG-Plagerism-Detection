#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum (int d, int m, int g) {
       
        dan=d; mjesec=m; godina=g;
    }
    bool provjera (int d, int m, int g) const{
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) return false;
        else return true;
    }
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const { std::cout<<dan<<"."<<mjesec<<"."<<godina;}
};

class GradjaninBiH {
    std::string ip;
    long long int jmbg;
    std::string p;
    GradjaninBiH *prethodni=nullptr;
    static GradjaninBiH *zadnji;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        ip=ime_i_prezime;
        int JMBG[13];
        for(int i=0; i<13; i++) {JMBG[i]=jmbg/pow(10,abs(i-12)); jmbg=jmbg-JMBG[i]*pow(10,abs(i-12));}
        int dan=JMBG[0]*10+JMBG[1]; int mj=JMBG[2]*10+JMBG[3]; int god=JMBG[4]*100+JMBG[5]*10+JMBG[6];
        Datum dat(dan,mj,god);
        int kod=JMBG[9]*100+JMBG[10]*10+JMBG[11];
        int c=(11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11);
        if(c==11) c=0;
        if(dat.provjera(dan,mj,god)==false) throw std::logic_error("JMBG nije validan");
        if(c!=JMBG[12]) throw std::logic_error("JMBG nije validan");
        
        if(kod<500) p=Musko; else p=Zensko;
        GradjaninBiH::jmbg=0;
        for(int i=0; i<13; i++) GradjaninBiH::jmbg=JMBG[i]*pow(10,abs(12-i))+GradjaninBiH::jmbg;
        if(zadnji!=nullptr){
        GradjaninBiH *pok=this;
        while(pok!=nullptr) {
           
             pok=pok->prethodni;
            if( pok!=nullptr && GradjaninBiH::jmbg==pok->DajJMBG()) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
           
        }
        }
        prethodni=GradjaninBiH::zadnji; 
        GradjaninBiH::zadnji=this;
        
    }
    /*~GradjaninBiH() {
        GradjaninBiH *pok=this;
        GradjaninBiH *zad=zadnji;
        while(zad->prethodni!=pok){
            zad=zad->prethodni;
        }
        zad->prethodni=pok->prethodni;
    }*/
        
    GradjaninBiH(const GradjaninBiH &l)=delete;
    GradjaninBiH &operator =(const GradjaninBiH &l)=delete;
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        ip=ime_i_prezime;
        int JMBG[13];
        Datum dat(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
        if(dat.provjera(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false) throw std::logic_error("Neispravni podaci");
        if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
        int prva=godina_rodjenja/1000; int druga=(godina_rodjenja-prva*1000)/100; int treca=(godina_rodjenja-prva*1000-druga*100)/10; int cetvrta=godina_rodjenja%10;
        int kod=0;
        if(pol==Musko)  kod=0; else /*if(p=="Zensko")*/  kod=500;
        if(prethodni==nullptr && pol==Musko) kod=0; else if(pol==Musko && prethodni!=nullptr) kod=kod+1;
        if(prethodni==nullptr && pol==Zensko) kod=500; else if((prethodni!=nullptr && pol==Zensko)) kod=kod+1;
        JMBG[0]=dan_rodjenja/10; JMBG[1]=dan_rodjenja%10; JMBG[2]=mjesec_rodjenja/10; JMBG[3]=mjesec_rodjenja%10;
        JMBG[4]=druga; JMBG[5]=treca; JMBG[6]=cetvrta; JMBG[7]=sifra_regije/10; JMBG[8]=sifra_regije%10;
        JMBG[9]=kod/100; JMBG[10]=(kod-JMBG[9]*100)/10; JMBG[11]=kod%10; 
        int c=(11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11);
        if(c==11) c=0; JMBG[12]=c; 
        GradjaninBiH::jmbg=0;
        for(int i=0; i<13; i++) GradjaninBiH::jmbg=JMBG[i]*pow(10,abs(12-i))+GradjaninBiH::jmbg;
        
        if(prethodni!=nullptr) prethodni=zadnji;
        GradjaninBiH::zadnji=this;
    }
std::string DajImeIPrezime() const {return ip;}
long long int DajJMBG() const {return jmbg;}
int DajDanRodjenja() const {
    int JMBG[13];
    long long int j=jmbg;
    for(int i=0; i<13; i++) {JMBG[i]=j/pow(10,abs(i-12)); j=j-JMBG[i]*pow(10,abs(i-12));}
    int dan=JMBG[0]*10+JMBG[1]; return dan;}
int DajMjesecRodjenja() const {
    int JMBG[13];
    long long int j=jmbg;
    for(int i=0; i<13; i++) {JMBG[i]=j/pow(10,abs(i-12)); j=j-JMBG[i]*pow(10,abs(i-12));}
    int mj=JMBG[2]*10+JMBG[3]; return mj;}
int DajGodinuRodjenja() const {
    int JMBG[13];
    long long int j=jmbg;
    for(int i=0; i<13; i++) {JMBG[i]=j/pow(10,abs(i-12)); j=j-JMBG[i]*pow(10,abs(i-12));}
    int god=JMBG[4]*100+JMBG[5]*10+JMBG[6]; if(god<18) god=god+2000; else god=god+1000; return god;}
int DajSifruRegije() const {
    int JMBG[13];
    long long int j=jmbg;
    for(int i=0; i<13; i++) {JMBG[i]=j/pow(10,abs(i-12)); j=j-JMBG[i]*pow(10,abs(i-12));}
    return JMBG[7]*10+JMBG[8];}
Pol DajPol() const {
    int JMBG[13];
    long long int j=jmbg;
    for(int i=0; i<13; i++) {JMBG[i]=j/pow(10,abs(i-12)); j=j-JMBG[i]*pow(10,abs(i-12));}
    if((JMBG[9]*100+JMBG[10]*10+JMBG[11])<500) return Musko; else return Zensko;}
void PromijeniImeIPrezime(std::string novo_ime) {ip=novo_ime;}

};

GradjaninBiH *GradjaninBiH::zadnji=nullptr;

int main ()
{
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>n;
    std::cin.clear(); std::cin.ignore(1000, '\n');
    for(int i=0; i<n; i++) {
        try{
    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
    std::string ip;
    std::getline(std::cin,ip);
    std::cout<<"Unesite JMBG: "<<std::endl;
    long long int jmbg;
    std::cin>>jmbg;
    std::cin.clear(); std::cin.ignore(1000, '\n');
    GradjaninBiH g(ip,jmbg);
    int m=g.DajPol(); if(m==0) {
    std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<
    g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()
    <<" u regiji "<<g.DajSifruRegije()<<", musko."<<std::endl;}
    else {
        std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<
    g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()
    <<" u regiji "<<g.DajSifruRegije()<<", zensko."<<std::endl;
    }
        }
    catch(std::logic_error e) {std::cout<<e.what()<<std::endl; i--;}
    }
    
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>n;
    std::cin.clear(); std::cin.ignore(1000, '\n');
    for(int i=0; i<n; i++) {
        try{
    std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
    std::string ip;
    std::getline(std::cin,ip);
    std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
    int dan; int mj; int god; char znak;
    std::cin>>dan>>znak>>mj>>znak>>god;
    std::cin.clear(); std::cin.ignore(1000, '\n');
    std::cout<<"Unesite sifru regije: "<<std::endl;
    int sifra; std::cin>>sifra; std::cin.clear(); std::cin.ignore(1000, '\n');
    std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
    char p; std::cin>>p;
    std::cin.clear(); std::cin.ignore(1000, '\n');
    if(p=='M') {
    GradjaninBiH gr(ip,dan,mj,god,sifra,GradjaninBiH::Pol::Musko);
    std::cout<<"Unijeli ste gradjanina "<<gr.DajImeIPrezime()<<" JMBG: "<<gr.DajJMBG()<<"."<<std::endl;}
    else if(p=='Z') { GradjaninBiH gr(ip,dan,mj,god,sifra,GradjaninBiH::Pol::Zensko);
    std::cout<<"Unijeli ste gradjanina "<<gr.DajImeIPrezime()<<" JMBG: "<<gr.DajJMBG()<<"."<<std::endl;}
        }
    catch(std::logic_error e) {std::cout<<e.what()<<std::endl; i--;}
    }
    
	return 0;
}
