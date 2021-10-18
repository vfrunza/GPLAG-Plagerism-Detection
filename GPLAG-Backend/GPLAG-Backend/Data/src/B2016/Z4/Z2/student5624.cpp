/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdio>
enum Pol {Musko, Zensko};
bool IspravanDatum(int d, int m, int g){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0)
        broj_dana[1]++;
    if(g<1 || d<1 || m<1 ||m>12 || d>broj_dana[m-1])
        return false;
    return true;
}
class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod, kcifra;
    Pol pol;
    GradjaninBiH *pok_na_prethodni;
    static GradjaninBiH *save;
    GradjaninBiH operator=(GradjaninBiH jedan);
    void JMBGtoDMG(long long int j){
        long long int b=j;
        int br=0;
        while(b!=0){
            br++; b/=10;
        }
        if(br!=12 && br!=13) throw std::logic_error("JMBG nije validan");
        long long int a(j);
        kcifra=a%10;
        a/=10;
        kod=0;
        for(int i=0; i<3; i++){
            static int k =1;
            kod+=a%10*k;
            k*=10;
            a/=10;
        }
        if(kod<500) pol=Musko;
        else pol=Zensko;
        sifra_regije=0;
        for(int i=0; i<2; i++){
            static int k =1;
            sifra_regije+=a%10*k;
            k*=10;
            a/=10;
        }
        godina_rodjenja=0;
        for(int i=0; i<3; i++){
            static int k =1;
            godina_rodjenja+=a%10*k;
            k*=10;
            a/=10;
        }
        if( godina_rodjenja >17) godina_rodjenja+=1000;
        else godina_rodjenja+=2000;
        mjesec_rodjenja=0;
        for(int i=0; i<2; i++){
            static int k =1;
            mjesec_rodjenja+=a%10*k;
            k*=10;
            a/=10;
        }
        if(br==12) dan_rodjenja=a;
        else {
            dan_rodjenja=a%10;
            a/=10;
            dan_rodjenja+=a*10;
        }
    }
    void DMGtoJMBG(int d, int m, int g, int sifra, Pol pol){
        bool tri=true;
        if(d<10) tri=false;
        if(tri){
            int nizjmbg[13];
            nizjmbg[0]=d%10;
            d/=10;
            nizjmbg[1]=d; 
            if(m<10) nizjmbg[2]=0;
            else {
                nizjmbg[2]=m%10;
                m/=10;
            }
            nizjmbg[3]=m;
            nizjmbg[4]=g%10;
            g/=10;
            nizjmbg[5]=g%10;
            g/=10;
            nizjmbg[6]=g%10;
            nizjmbg[7]=sifra%10;
            sifra/=10;
            nizjmbg[8]=sifra%10;
            kod=DajKod();
            nizjmbg[9]=kod%10;
            kod/=10;
            nizjmbg[10]=kod%10;
            kod/=10;
            nizjmbg[11]=kod%10;
            kcifra=11-(7*(nizjmbg[0]+nizjmbg[6])+6*(nizjmbg[1]+nizjmbg[7])+5*(nizjmbg[2]+nizjmbg[8])+4*(nizjmbg[3]+nizjmbg[9])+3*(nizjmbg[4]+nizjmbg[10])+2*(nizjmbg[5]+nizjmbg[11]))%11;
            nizjmbg[12]=kcifra;
        }
        else{
            int nizjmbg[12];
            nizjmbg[0]=d; 
            if(m<10) nizjmbg[1]=0;
            else {
                nizjmbg[1]=m%10;
                m/=10;
            }
            nizjmbg[2]=m;
            nizjmbg[3]=g%10;
            g/=10;
            nizjmbg[4]=g%10;
            g/=10;
            nizjmbg[5]=g%10;
            nizjmbg[6]=sifra%10;
            sifra/=10;
            nizjmbg[7]=sifra%10;
            kod=DajKod();
            nizjmbg[8]=kod%10;
            kod/=10;
            nizjmbg[9]=kod%10;
            kod/=10;
            nizjmbg[10]=kod%10;
            kcifra=11-(7*(nizjmbg[5])+6*(nizjmbg[0]+nizjmbg[6])+5*(nizjmbg[1]+nizjmbg[7])+4*(nizjmbg[2]+nizjmbg[8])+3*(nizjmbg[3]+nizjmbg[9])+2*(nizjmbg[4]+nizjmbg[10]))%11;
            nizjmbg[11]=kcifra;
        }
    }
    int DajKod(){
        int br=0;
        GradjaninBiH *pok=pok_na_prethodni;
        while(pok!=nullptr){
            if(pok->DajSifruRegije()==sifra_regije&&pok->DajDanRodjenja()==dan_rodjenja &&pok->DajMjesecRodjenja()==mjesec_rodjenja && pok->DajGodinuRodjenja()==godina_rodjenja)br++; 
        }
        if(pol==Musko) return br;
        else return 500+br;
    }

    bool DaLiImaIspred(){
        GradjaninBiH *pok=pok_na_prethodni;
        while(pok!=nullptr){
            if(pok->DajJMBG()==jmbg) return false; 
            else pok=pok->pok_na_prethodni;
        }
        return true;
    }
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol()const;
    void PromijeniImeIPrezime(std::string novo_ime);
   // ~GradjaninBiH();{
      /*  GradjaninBiH *trenutni = save, *sljedeci;
        while(trenutni != this){
            sljedeci=trenutni;
            trenutni=trenutni->pok_na_prethodni;
        }
        sljedeci->pok_na_prethodni = trenutni->pok_na_prethodni;
    }*/
};
GradjaninBiH *GradjaninBiH::save=nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::jmbg=jmbg;
    JMBGtoDMG(jmbg);
    if(!IspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja))throw std::logic_error ("JMBG nije validan");
    pok_na_prethodni=save;
    save=this;
    if(!DaLiImaIspred()) throw std::logic_error("Vec postoji gradjanin sa istim JMBG-om");
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!IspravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja))throw std::logic_error ("Neispravni podaci");
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    GradjaninBiH::sifra_regije=sifra_regije;
    GradjaninBiH::pol=pol;
    DMGtoJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    pok_na_prethodni=save;
    save=this;
    if(!DaLiImaIspred()) throw std::logic_error("Vec postoji gradjanin sa istim JMBG-om");
}
std::string GradjaninBiH::DajImeIPrezime()const{
    return ime_i_prezime; 
} 
long long int GradjaninBiH::DajJMBG()const{
    return jmbg;
}
int GradjaninBiH::DajDanRodjenja() const{
    return dan_rodjenja;
}
int GradjaninBiH::DajMjesecRodjenja() const{
    return mjesec_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja() const{
    return godina_rodjenja;
}
int GradjaninBiH::DajSifruRegije() const{
    return sifra_regije;
}
Pol GradjaninBiH::DajPol() const{
    return pol;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    ime_i_prezime=novo_ime;
}
std::string DajIme(std::string s){
    std::string s1;
    int j(0);
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') j=i;
    }
    s1=s.substr(0, j);
    return s1;
}
int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG?"<<std::endl;
    int n;
    std::cin>>n;
    for(int i=0; i<n; i++){
        std::string s;
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
	    std::getline(std::cin, s);
	    std::cout<<"Unesite JMBG: "<<std::endl;
	    long long int a;
	    std::scanf("%lli", &a);
	    try{
	        GradjaninBiH jedan(s,a);
	        std::cout<<"Unijeli ste gradjanina "<<DajIme(s)<<" rodjenog "<<jedan.DajDanRodjenja()<<"."<<jedan.DajMjesecRodjenja()<<"."<<jedan.DajGodinuRodjenja()<<" u regiji "<<jedan.DajSifruRegije()<<", ";
	        if(jedan.DajPol()==Musko) std::cout<<"musko."<<std::endl;
	        else std::cout<<"zensko."<<std::endl;
	    }
	    catch(std::logic_error e){
	        std::cout<<e.what()<<std::endl;
	    }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int n1;
    std::cin>>n1;
    for(int i=0; i<n1; i++){
        std::cout<<"Unesite ime i prezime (u istom redu) "<<std::endl;
        std::string s;
        std::getline(std::cin, s);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gg)"<<std::endl;
        int a, b, c;
        std::cin>>a>>b>>c;
        std::cout<<"Unesite sifru regije: "<<std::endl;
        int d;
        std::cin>>d;
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        char e;
        std::cin>>e;
        Pol pOl;
        if(e=='M')pOl=Musko;
        else pOl=Zensko;
        std::cout<<"Unijeli ste gradjanina ";
        try{
            GradjaninBiH drugi(s, a,b,c,d,pOl);
            std::cout<<DajIme(s)<<" JMBG: "<<drugi.DajJMBG()<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
        }
        
    }
	return 0;
}