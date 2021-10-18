/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class GradjaninBiH{
    long long int JMBG;
    std::string Ime_i_Prezime;
    GradjaninBiH *pocet;
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH *veza;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        if(ProvjeriJmbg(jmbg))JMBG=jmbg;
        else throw std::logic_error ("JMBG nije validan");
        Ime_i_Prezime=ime_i_prezime;
        veza=nullptr;
        pocet=nullptr;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol){
        long long int jmbg;
        if(KreirajJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol,jmbg)){
            JMBG=jmbg;;
        }
        else throw std::logic_error ("Neispravni podaci");
        Ime_i_Prezime=ime_i_prezime;
        veza=nullptr;
        pocet=nullptr;
    }
    GradjaninBiH(const GradjaninBiH &r) = delete; // Zabrana kopiranja
    GradjaninBiH &operator =(const GradjaninBiH &r) = delete;
    std::string DajImeIPrezime() const{
        return Ime_i_Prezime;
    }
    long long int DajJMBG() const{
        return JMBG;
    }
    void PostaviPoc(GradjaninBiH *pok){
        pocet=pok;
    }
    int DajDanRodjenja() const{
        return (DajCifru(JMBG,1)*10+DajCifru(JMBG,2));
    }
    int DajMjesecRodjenja() const{
        return (DajCifru(JMBG,3)*10+DajCifru(JMBG,4));
    }
    int DajGodinuRodjenja() const{
        int godina=0;
        if(DajCifru(JMBG,5)==0)godina=2000;
        else godina=1000;
        return (godina=godina+DajCifru(JMBG,5)*100+DajCifru(JMBG,6)*10+DajCifru(JMBG,7));
    }
    int DajSifruRegije() const{
        return (DajCifru(JMBG,8)*10+DajCifru(JMBG,9));
    }
    Pol DajPol() const{
        int x=DajCifru(JMBG,10)*100+DajCifru(JMBG,11)*10+DajCifru(JMBG,12);
        if(x<500)return Pol::Musko;
        return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){
        Ime_i_Prezime=novo_ime;
    }
    void Ispisi()const{
        std::cout<<DajImeIPrezime()<<" rodjenog "<<DajDanRodjenja()<<"."<<
        DajMjesecRodjenja()<<"."<<DajGodinuRodjenja()<<" u regiji "<<DajSifruRegije();
        if(DajPol()==Pol::Zensko)std::cout<<", zensko.";
        else{std::cout<<", musko.";}
        std::cout<<std::endl;
    }
    void Ispisi1()const{
        std::cout<<DajImeIPrezime()<<" JMBG: "<<DajJMBG()<<"."<<std::endl;
    }
    bool ProvjeriJmbg(long long int &jmbg);
    long long int DajCifru(long long int jmbg,int cifra)const{
        if(jmbg<pow(10,12) && cifra==1)return 0;
        else if(jmbg<pow(10,12))cifra+=1;
	    long long int c=jmbg/(pow(10,13-cifra));
	    return c%10;
    }
    ~GradjaninBiH()=default;
    bool KreirajJMBG(int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja,
    int sifra_regije, Pol pol,long long int &jmbg);
};
bool GradjaninBiH::KreirajJMBG(int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol,long long int &jmbg){
        jmbg=0;
        int pol_br=0;
        if(dan_rodjenja>31 || dan_rodjenja<1)return false;
        jmbg=dan_rodjenja*(pow(10,11));
        if(mjesec_rodjenja>12 || mjesec_rodjenja<1)return false;
        jmbg+=mjesec_rodjenja*(pow(10,9));
        if(godina_rodjenja<1917 || godina_rodjenja>2017)return false;
        if(godina_rodjenja<2000)godina_rodjenja-=1000;
        else if(godina_rodjenja>=2000)godina_rodjenja-=2000;
        jmbg+=godina_rodjenja*(pow(10,6));
        if(sifra_regije<1 || sifra_regije>99)return false;
        jmbg+=sifra_regije*(pow(10,4));
        if(pol==Pol::Musko){pol_br=0;}       //treba postaviti brojac muskih i zenskih//
        if(pol==Pol::Zensko){pol_br=500;}
        jmbg+=pol_br*10;
        int c13=11-(7*(DajCifru(jmbg,1)+DajCifru(jmbg,7))+6*(DajCifru(jmbg,2)+DajCifru(jmbg,8))+5*(DajCifru(jmbg,3)+DajCifru(jmbg,9))
        +4*(DajCifru(jmbg,4)+DajCifru(jmbg,10))+3*(DajCifru(jmbg,5)+DajCifru(jmbg,11))+2*(DajCifru(jmbg,6)+DajCifru(jmbg,12)))%11;
        if(c13==10)return false;
        if(c13==11)c13=0;
        jmbg+=c13;
        return ProvjeriJmbg(jmbg);
    }
bool Prestupna(long int godina){
    if(godina%400==0 || (godina%100!=0 && godina%4==0))return true;
    return false;
}
bool GradjaninBiH::ProvjeriJmbg(long long int &jmbg){
    if(jmbg>3112999999999)return false;
    int dani=DajCifru(jmbg,1)*10+DajCifru(jmbg,2);
    int mjesec=DajCifru(jmbg,3)*10+DajCifru(jmbg,4);
    int godina=0;
    if(DajCifru(jmbg,5)==0)godina=2000;
    else godina=1000;
    godina=godina+DajCifru(jmbg,5)*100+DajCifru(jmbg,6)*10+DajCifru(jmbg,7);
    if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12){
        if(dani<1 || dani>31)return false;
    }
    else if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11){
        if(dani<1 || dani>30)return false;
    }
    else if(mjesec==2 && Prestupna(godina)==true){
        if(dani>29 || dani<1)return false;
    }
    else if(mjesec==2 && Prestupna(godina)==false){
        if(dani<1 || dani>28)return false;
    }
    if(godina<(2017-100) || godina>2017)return false;
    long long int c13;
    c13=11-(7*(DajCifru(jmbg,1)+DajCifru(jmbg,7))+6*(DajCifru(jmbg,2)+DajCifru(jmbg,8))+5*(DajCifru(jmbg,3)+DajCifru(jmbg,9))
    +4*(DajCifru(jmbg,4)+DajCifru(jmbg,10))+3*(DajCifru(jmbg,5)+DajCifru(jmbg,11))+2*(DajCifru(jmbg,6)+DajCifru(jmbg,12)))%11;
    if(c13==11)jmbg=jmbg-DajCifru(jmbg,13);
    else if(c13==10)return false;
    else if(c13!=DajCifru(jmbg,13))return false;
    return true;
}

int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int njb;
    std::cin>>njb;
    GradjaninBiH *pocetak=nullptr;
    GradjaninBiH *sljed=nullptr;
    for(int i=0;i<njb;i++){
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string ime;
        std::getline(std::cin,ime,'\n');
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int jmbg;
        std::cin>>jmbg;
        try{
        auto priv=new GradjaninBiH(ime,jmbg);
        if(!pocetak)pocetak=priv;
        else sljed->veza=priv;
        sljed=priv;
        priv->PostaviPoc(pocetak);
        std::cout<<"Unijeli ste gradjanina ";priv->Ispisi();
        }
        catch(std::logic_error x){
            std::cout<<x.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int njb2;
    std::cin>>njb2;
    for(int i=0;i<njb2;i++){
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string ime;
        std::getline(std::cin,ime,'\n');
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
        int d,m,g;
        std::cin>>d;std::cin.get();std::cin>>m;std::cin.get();std::cin>>g;
        std::cout<<"Unesite sifru regije: "<<std::endl;
        int regija;
        std::cin>>regija;
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        GradjaninBiH::Pol pol;
        char polr;
        polr=std::cin.get();
        if(polr=='M')pol=GradjaninBiH::Pol::Musko;
        else if(polr=='Z')pol=GradjaninBiH::Pol::Zensko;
        else {throw std::range_error ("Nevalja pol");}
        try{
        auto priv=new GradjaninBiH(ime,d,m,g,regija,pol);
        if(!pocetak)pocetak=priv;
        else sljed->veza=priv;
        sljed=priv;
        std::cout<<"Unijeli ste gradjanina ";priv->Ispisi1();
        }
        catch(std::logic_error x){
            std::cout<<x.what()<<std::endl;
            i--;
        }
    }
     auto sacuvaj_slijedeci=pocetak;
     auto setac=pocetak;
        while(setac!=nullptr){
            sacuvaj_slijedeci=sacuvaj_slijedeci->veza;
            delete setac;
            setac=sacuvaj_slijedeci;
        }
    
	return 0;
}