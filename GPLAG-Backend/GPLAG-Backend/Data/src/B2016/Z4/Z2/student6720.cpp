#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH{
    GradjaninBiH *prethodni=nullptr;
    long long int jmbg;
    std::string ime_i_prezime;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije, kod_osobe;
    bool IspravanDatum(int dan, int mjesec, int godina);
    static GradjaninBiH* posljedni;
    int DajKod(int donja, int gornja);
    public:
    GradjaninBiH* DajPrethodni(){return prethodni;}
    ~GradjaninBiH(){
        if(posljedni==this)
            posljedni=this->prethodni;
        else
            if(prethodni==nullptr)
                posljedni=this->prethodni;
            else
                for(auto kraj=posljedni; kraj!=nullptr; kraj=kraj->prethodni)
                    if(kraj->prethodni==this){
                        kraj->prethodni=this->prethodni;
                        break;
                    }
    }
    enum Pol {Musko, Zensko}pol;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime () const{return ime_i_prezime;}
    long long int DajJMBG() const{return jmbg;}
    int DajDanRodjenja () const{return dan_rodjenja;}
    int DajMjesecRodjenja () const{return mjesec_rodjenja;}
    int DajGodinuRodjenja () const{return godina_rodjenja;}
    int DajSifruRegije() const{return sifra_regije;}
    Pol DajPol() const{return pol;}
    void PromijeniImeIPrezime(std::string novo_ime){this->ime_i_prezime=novo_ime;}
};

bool GradjaninBiH::IspravanDatum(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
        broj_dana[1]++;
    if(godina<1917 || godina>2017 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1])
        return false;
    return true;
}

GradjaninBiH *GradjaninBiH::posljedni=nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int c[13],i; c[0]=0;
    for(i=12;i>=0 && jmbg;--i, jmbg/=10)
        c[i]=jmbg%10;
    if(i>1 || jmbg!=0 || c[12]<0)
        throw std::logic_error("JMBG nije validan");
    int g=c[4]*100+c[5]*10+c[6], c13=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    if(g<=17) g+=2000; else g+=1000;
    if(!IspravanDatum(c[0]*10+c[1],c[2]*10+c[3],g) || c13==10 || (c13==11 && c[12]!=0) || (c13!=11 && c13!=c[12]))
        throw std::logic_error("JMBG nije validan");
    
    for(auto kraj=this->prethodni;kraj!=nullptr;kraj=kraj->prethodni)
        if(this->GradjaninBiH::DajJMBG()==kraj->GradjaninBiH::DajJMBG())
            throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            
    this->kod_osobe=c[9]*100+c[10]*10+c[11]; this->jmbg=jmbg; this->ime_i_prezime=ime_i_prezime; this->dan_rodjenja=c[0]*10+c[1]; this->mjesec_rodjenja=c[2]*10+c[3]; this->godina_rodjenja=g; this->sifra_regije=c[7]*10+c[8];
    if(kod_osobe<500)
        this->pol=Pol::Musko; else this->pol=Pol::Zensko;
    if(posljedni!=nullptr)
        this->prethodni=posljedni;
    posljedni=this;
}

int GradjaninBiH::DajKod(int donja, int gornja){
    for(int i=donja;i<=gornja;i++){
        bool nadjen(false);
        for(auto kraj=this->prethodni; kraj!=nullptr; kraj=kraj->prethodni)
            if(i==kraj->kod_osobe){
                nadjen=true; break;
            }
        if(nadjen==false)
            return i;
    }
    return -1;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!IspravanDatum(dan_rodjenja,mjesec_rodjenja, godina_rodjenja) || sifra_regije<0 || sifra_regije>99)
        throw std::logic_error("Neispravni podaci");
    this->ime_i_prezime=ime_i_prezime; this->dan_rodjenja=dan_rodjenja; this->mjesec_rodjenja=mjesec_rodjenja;this->godina_rodjenja=godina_rodjenja; this->sifra_regije=sifra_regije;this->pol=pol;
    if(pol==Pol::Musko)
        this->kod_osobe=DajKod(0,499);
    else this->kod_osobe=DajKod(500,999);
    int c[13];
    c[0]=dan_rodjenja/10; c[1]=dan_rodjenja%10; c[2]=mjesec_rodjenja/10; c[3]=mjesec_rodjenja%10;c[4]=(godina_rodjenja%1000)/100; c[5]=((godina_rodjenja%1000)%100)/10; c[6]=((godina_rodjenja%1000)%100)%10;
    c[7]=sifra_regije/10; c[8]=sifra_regije%10; c[9]=(kod_osobe/100); c[10]=(kod_osobe%100)/10; c[11]=(kod_osobe%100)%10;
    c[12]= 11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    if(c[12]==11) c[12]=0;

    long long int t_jmbg=0;
    for(int i=0;i<12;i++){
        t_jmbg+=c[i];
        t_jmbg*=10;
    }
    t_jmbg+=c[12];
    this->jmbg=t_jmbg;
    if(posljedni!=nullptr)
        this->prethodni=posljedni;
    posljedni=this;
}

int main ()
{
    GradjaninBiH *niz_gradjana_pok[100]{}; //Ne moze se napraviti niz pok na gradjane bez din. alokacije gradjana ili smjestanja istih negdje za cuvanje.
    
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int br_gradj,poz=0;
    std::cin>>br_gradj;
    
    for(int i=0;i<br_gradj;i++){
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        long long int jmbg;
        std::cout<<"Unesite JMBG: "<<std::endl;
        std::cin>>jmbg;
        try{
            niz_gradjana_pok[poz]=new GradjaninBiH(ime_i_prezime, jmbg);
            std::cout<<"Unijeli ste gradjanina " << niz_gradjana_pok[poz]->DajImeIPrezime() << " rodjenog "<< niz_gradjana_pok[poz]->DajDanRodjenja()<<"."<<niz_gradjana_pok[poz]->DajMjesecRodjenja()<<"."<<niz_gradjana_pok[poz]->DajGodinuRodjenja()<<" u regiji "<<niz_gradjana_pok[poz]->DajSifruRegije()<<",";
            if(niz_gradjana_pok[poz]->DajPol()==0)std::cout<<" musko."<<std::endl;
            else std::cout<<" zensko."<<std::endl;
            poz++;
        }catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl; i--;
        }
        catch(...){}
    }
    
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>br_gradj;
    
    for(int i=0;i<br_gradj;i++){
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
        long long int dan, mjesec, godina;
        std::cin>>dan; std::cin.ignore(1,'/'); std::cin>>mjesec; std::cin.ignore(1,'/'); std::cin>>godina;
        
        std::cout<<"Unesite sifru regije: "<<std::endl;
        int sifra_regije;
        std::cin>>sifra_regije;
        
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        char mz;
        std::cin>>mz;
        GradjaninBiH::Pol pol;
        if(mz=='M') pol=GradjaninBiH::Pol::Musko; else pol=GradjaninBiH::Pol::Zensko;
        
        try{
            niz_gradjana_pok[poz]=new GradjaninBiH(ime_i_prezime, dan, mjesec, godina, sifra_regije, pol);
            std::cout<<"Unijeli ste gradjanina "<<niz_gradjana_pok[poz]->DajImeIPrezime()<< " JMBG: "<<niz_gradjana_pok[poz]->DajJMBG()<<"."<<std::endl;
            poz++;
            
        }catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl; i--;
        }
        catch(...){}
    }
    
    for(int i=0;i<100;i++){
        delete niz_gradjana_pok[i];
        niz_gradjana_pok[i]=nullptr;
    }
    
	return 0;
}