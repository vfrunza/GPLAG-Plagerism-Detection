/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    private:
    std::string ime;
    mutable int broj_m=0;
    mutable int broj_z=0;
    long long int jmb;
    //GradjaninBiH *veza;
    //GradjaninBiH *pocetak=nullptr;
    //GradjaninBiH *predhodni;
    public:
    
    
enum Pol {Musko, Zensko};

GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
      /*  GradjaninBiH *novi=nullptr;
        novi->jmb = jmbg;
        novi->veza=nullptr;
        if(!pocetak) pocetak=novi;
        else predhodni->veza=novi;
        predhodni=novi;
        for(GradjaninBiH *p=pocetak; p!=nullptr; p++){
            p++;
            for(GradjaninBiH *p_1=p; p_1!=nullptr; p_1++){
            if((*p).jmb==(*p_1).jmb)
            throw std::logic_error ("“Vec postoji gradjanin sa istim JMBG");
            }
        }*/
    ProvjeraJmbg(jmbg);
    ime=ime_i_prezime;
    jmb=jmbg;
}
void ProvjeraJmbg(long long int jmbg);

GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol) {
     ime=ime_i_prezime;
     if(dan_rodjenja<=0 || dan_rodjenja>31) throw std::logic_error ("Neispravni podaci¸dan..");
     if(mjesec_rodjenja<=0 || mjesec_rodjenja>12) throw std::logic_error("Neispravni podaci mjeces..");
     else if(mjesec_rodjenja==2 && (dan_rodjenja==30 || dan_rodjenja==31)) throw std::logic_error("Neispravni podaci feb..");
     if(godina_rodjenja<0 || godina_rodjenja> 2017) throw std::logic_error("Neispravni podaci godina..");
     if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci regija...");
     if(godina_rodjenja>1000 && godina_rodjenja<=2000) godina_rodjenja-=1000;
     else if(godina_rodjenja>2000) godina_rodjenja-=2000;
     if(pol==1){

     jmb=dan_rodjenja*pow(10,11) + mjesec_rodjenja*pow(10, 9) + godina_rodjenja*pow(10, 6) + sifra_regije*pow(10, 4) + broj_z * 10;
     broj_z++;
      //if(broj_z>999) break;
     }
     else if(pol==0){
         jmb=dan_rodjenja*pow(10,11) + mjesec_rodjenja*pow(10, 9) + godina_rodjenja*pow(10, 6) + sifra_regije*pow(10, 4) + broj_m * 10;
         broj_m++;
         //if(broj_m>999) break;
   }
 } 
std::string DajImeIPrezime() const { return ime; }
long long int DajJMBG() const { return jmb; }
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const {
    Pol pol_gradjana;
    long long int kod=jmb;
    int p=kod%int(pow(10, 4));
    int pol=p/10;
    if(pol>=0 && pol<=499) pol_gradjana=Musko;
    else if(pol>499 &&  pol<=999) pol_gradjana=Zensko;
    else throw std::logic_error ("Neispravni podaci");
    return pol_gradjana;
}
void PromijeniImeIPrezime(std::string novo_ime);
};

int GradjaninBiH::DajDanRodjenja () const {
    long long int kod=jmb;
    int d_rodjenja=kod/100000000000;
    return d_rodjenja;
} 
int GradjaninBiH::DajMjesecRodjenja() const{
    long long int kod=jmb;
    int mj_rodjenja=kod/int(pow(10, 9));
    int m_rodjenja=mj_rodjenja%100;
    return m_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja() const{
    long long int kod=jmb;
    int god_rodjenja=kod/int(pow(10, 6));
    int g_rodjenja=god_rodjenja%1000;
    if(g_rodjenja>=0 && g_rodjenja<=17) g_rodjenja+=2000;
    else g_rodjenja+=1000;
    return g_rodjenja;
}
int GradjaninBiH::DajSifruRegije() const{
    long long int kod=jmb;
    int s=kod/int(pow(10, 4));
    int sifra=s%100;
    return sifra;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    ime=novo_ime;
}
void GradjaninBiH::ProvjeraJmbg(long long int jmbg){
    int broj[13];
    for(int i=0; i<13; i++){
        broj[i]=jmbg%10;
        jmbg=jmbg/10;
    }
    
    int c_13 = 11 - ( 7 * (broj[12] + broj[6]) + 6 * (broj[11] + broj[5]) + 
    5 * (broj[10] + broj[4]) + 4 * (broj[9] + broj[3]) + 3 * (broj[8] + broj[2]) + 2 * (broj[7] + broj[1]) ) % 11;
    
    if(c_13==11) c_13=0;
    else if(c_13==10) throw std::logic_error("JMBG nije validan iz gradjana");
    
}
bool ProvjeraJmbg(long long int jmbg){
    bool tacno(true);
    int broj[13];
    for(int i=12; i>=0; i--){
        broj[i]=jmbg%10;
        jmbg=jmbg/10;

    }
    /*for(int i=0; i<13; i++){
        std::cout<<broj[i]<<" ";
    }*/
    if( (broj[0]*10 + broj[1])<=0 || (broj[0]*10 + broj[1])>31 )   tacno=false;
    else if( (broj[2]*10 + broj[3]) <=0 || (broj[2]*10 + broj[3]) >12)  tacno=false;
    else if( (broj[4]*100 + broj[5]*10 + broj[6] ) < 0 || (1000 + broj[4]*100 + broj[5]*10 + broj[6] ) > 2017 ) tacno=false;
    return tacno;
}
bool Provjera(int dan, int mjesec, int godina, int sifra){
    bool tacno(true);
    if(dan<=0 || dan>31 || mjesec<=0 || mjesec>12 || godina<0 || godina> 2017 || sifra<0 || sifra>99) tacno=false;
    else if(mjesec==2 && (dan==30 || dan==31)) tacno=false;
    return tacno;
}
int main ()
{
    try{
   
        
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    int broj;
    std::cin>>broj;
    for(int i=0; i<broj; i++){
        std::cout<<"\nUnesite ime i prezime (u istom redu): "; 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        std::string ime;
        std::getline(std::cin, ime);
        std::cout<<"\nUnesite JMBG: ";
        long long int JMBG;
        std::cin>>JMBG;
        if(!(ProvjeraJmbg(JMBG))){ i--; std::cout<<"JMBG nije validan"; } 
        else if(ProvjeraJmbg(JMBG)){
            
        GradjaninBiH gradjan(ime, JMBG);
        
        if(gradjan.DajPol())
        std::cout<<"\nUnijeli ste gradjanina "<<gradjan.DajImeIPrezime()<<" rodjenog "<<gradjan.DajDanRodjenja()<<"."<<
        gradjan.DajMjesecRodjenja()<<"."<<gradjan.DajGodinuRodjenja()<<" u regiji "<<gradjan.DajSifruRegije()<<", zensko.";
        else std::cout<<"\nUnijeli ste gradjanina "<<gradjan.DajImeIPrezime()<<" rodjenog "<<gradjan.DajDanRodjenja()<<"."<<
        gradjan.DajMjesecRodjenja()<<"."<<gradjan.DajGodinuRodjenja()<<" u regiji "<<gradjan.DajSifruRegije()<<", musko.";
        } 
    }
    std::cout<<"\nKoliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int broj_g;
    std::cin>>broj_g;
    for(int i=0; i<broj_g; i++){
        std::cout<<"\nUnesite ime i prezime (u istom redu): "; 
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::string ime_prezime;
        std::getline(std::cin, ime_prezime);
        std::cout<<"\nUnesite datum rodjenja (format dd/mm/gggg): ";
        int dan, mjesec, godina;
        std::cin>>dan;
        std::cin.clear();
        std::cin.ignore(10000, '/');
        std::cin>>mjesec;
        std::cin.clear();
        std::cin.ignore(10000, '/');
        std::cin>>godina;
        std::cout<<"\nUnesite sifru regije: "; 
        int sifra;
        std::cin>>sifra;
        std::cout<<"\nUnesite M za musko, Z za zensko: "; 
        enum Pol{Musko, Zensko};
        char pol;
        std::cin>>pol;
                
        if(!(Provjera(dan, mjesec, godina, sifra))) {std::cout<<"Neispravni podaci"; i--;}
        else if(Provjera(dan, mjesec, godina, sifra)){
        if(pol=='M') { 
            GradjaninBiH gradjan (ime_prezime, dan, mjesec, godina, sifra, GradjaninBiH::Musko); 
            std::cout<<"\nUnijeli ste gradjanina "<<gradjan.DajImeIPrezime()<<" JMBG: "<<gradjan.DajJMBG()<<".";
        }
        else if(pol=='Z'){
            GradjaninBiH gradjan (ime_prezime, dan, mjesec, godina, sifra, GradjaninBiH::Zensko);
            std::cout<<"\nUnijeli ste gradjanina "<<gradjan.DajImeIPrezime()<<" JMBG: "<<gradjan.DajJMBG()<<".";
        }
        else  throw std::logic_error ("Neispravni podaci");
        } 
    }
    
    }
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }

	return 0;
}