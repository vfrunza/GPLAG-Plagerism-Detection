/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
public:
enum Pol {Musko, Zensko};
private:
    static GradjaninBiH* zadnji;
    GradjaninBiH* prije;
    long long int jmbg;
    std::string ime_i_prezime;
    static long long int PretvoriUInt(std::string broj) {
        long long int x=0;
        for(int i(0);i<broj.size();i++) { x*=10; x += broj[i]-'0'; }
        return x;
    }
    static std::string DajString(long long int broj) {
        std::string s;
        while(broj!=0) {
            int c = broj%10;
            s+= c + '0';
            broj/=10;
        }
        for(int i(0);i<s.length()/2;i++)
            std::swap(s[i],s[s.length()-1-i]);
        if(s.length()==12) s = "0" + s;
        return s;
    }
    static int UInt(char x) { return x - '0'; }
    int NapraviCifru(std::string x) {
        int c = 11 - ( 7 * (UInt(x[0]) + UInt(x[6])) + 6*(UInt(x[1]) + UInt(x[7])) + 5*(UInt(x[2]) + UInt(x[8])) + 4 * (UInt(x[3]) + UInt(x[9])) + 3* (UInt(x[4]) + UInt(x[10])) + 2*(UInt(x[5]) + UInt(x[11]))) % 11;
        if(c == 11) c=0;
        return c;
    }
    void ProvjeriCifru(std::string x, long long int jmbg) {
        int c = 11 - ( 7 * (UInt(x[0]) + UInt(x[6])) + 6*(UInt(x[1]) + UInt(x[7])) + 5*(UInt(x[2]) + UInt(x[8])) + 4 * (UInt(x[3]) + UInt(x[9])) + 3* (UInt(x[4]) + UInt(x[10])) + 2*(UInt(x[5]) + UInt(x[11]))) % 11;
        if(c == 11) c=0;
        if(c==10 || c != jmbg%10)
            throw std::logic_error("JMBG nije validan");
    }
    void ProvjeriDatum(int d,int m, int g) {
        if(g<1917 || g>2017)
            throw std::logic_error("Neispravni podaci");
        if(m<1 || m>12) throw std::logic_error("Neispravni podaci");
        int mjeseci[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if( g%400 == 0 || (g%4 ==0 && g%100 !=0)) mjeseci[2]=29;
        if( d<1 || d>mjeseci[m]) throw std::logic_error("Neispravni podaci");
    }
    void ProvjeriMaticne(long long int jmbg) {
        GradjaninBiH *z = zadnji;
        while(z) {
            if(z->DajJMBG() == jmbg)
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            z=z->prije;
        }
    }
    void ProvjeriPodatke() {
        ProvjeriCifru(DajString(jmbg), jmbg);
        if( DajSifruRegije() < 0 || DajSifruRegije() > 99)
            throw std::logic_error("Neispravni podaci");
        ProvjeriDatum(DajDanRodjenja(), DajMjesecRodjenja(), DajGodinuRodjenja());
        ProvjeriMaticne(jmbg);
    }
    
    std::string DajStringDuzineTri(int x) {
        std::string tmp = DajString(x);
        while(tmp.length()!=3) tmp = "0" + tmp;
        return tmp;
    }
    
    long long int DajMuJMBG(int dan_rodjenja,int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        std::string _jmbg = DajString(dan_rodjenja) + DajString(mjesec_rodjenja) + DajString(godina_rodjenja).substr(1) + DajString(sifra_regije);
        if(_jmbg.length()==8) _jmbg = "0" + _jmbg;
        std::string kod; int kontrolna=-1;
        int o; if(pol == Pol::Musko) o=0; else o=500;
        bool kodovi[500]{0};
        GradjaninBiH* tmp = zadnji;
        while(tmp) {
            if( dan_rodjenja == tmp->DajDanRodjenja() && mjesec_rodjenja == tmp->DajMjesecRodjenja() && godina_rodjenja == tmp -> DajGodinuRodjenja() &&
                sifra_regije == tmp->DajSifruRegije() && pol == tmp->DajPol() ) kodovi[ PretvoriUInt(DajString(tmp->DajJMBG()).substr(9,3))-o] = true;
            tmp = tmp -> prije;
        }
        for(int i(0);i<500;i++) {
            if(!kodovi[i]) {
                if(NapraviCifru(_jmbg + DajStringDuzineTri(i))==10) continue;
                kod = DajStringDuzineTri(i+o);
                kontrolna = NapraviCifru(_jmbg + DajStringDuzineTri(i));
                break;
            }
        }
        _jmbg = _jmbg + kod;
        _jmbg += kontrolna + '0';
        return PretvoriUInt(_jmbg);
    }
    GradjaninBiH* next(GradjaninBiH* ptr) {
        GradjaninBiH* tmp = zadnji;
        if(tmp==ptr)
            return nullptr;
        while(tmp->prije!=ptr) tmp = tmp -> prije;
        return tmp;
    }
public:
GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
~GradjaninBiH();
std::string DajImeIPrezime() const { return ime_i_prezime; }
long long int DajJMBG() const { return jmbg; }
int DajDanRodjenja() const { return PretvoriUInt(DajString(jmbg).substr(0,2)); };
int DajMjesecRodjenja() const { return PretvoriUInt(DajString(jmbg).substr(2,2)); };
int DajGodinuRodjenja() const { if (DajString(jmbg)[4] == '0') return PretvoriUInt("2"+DajString(jmbg).substr(4,3)); else return PretvoriUInt("1"+DajString(jmbg).substr(4,3)); };
int DajSifruRegije() const { return PretvoriUInt(DajString(jmbg).substr(7,2)); } 
Pol DajPol() const { char tmp = DajString(jmbg)[9]; if( UInt(tmp)>=5) return Pol::Zensko; else return Pol::Musko; }
void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
};

GradjaninBiH* GradjaninBiH::zadnji;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    this->ime_i_prezime = ime_i_prezime;
    this->jmbg = jmbg;
    this->prije = GradjaninBiH::zadnji;
    ProvjeriPodatke();
    GradjaninBiH::zadnji = this;
}

GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH *tmp = next(this);
    if(tmp) tmp->prije = prije;
    if(this == GradjaninBiH::zadnji)
        GradjaninBiH::zadnji = prije;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    this->ime_i_prezime = ime_i_prezime;
    if(sifra_regije<0 || sifra_regije>99)
        throw std::logic_error("Neispravni podaci");
    ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
    jmbg = DajMuJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol);
    zadnji = this;
}

int intaj(std::string broj) {
        int x=0;
        for(int i(0);i<broj.length();i++) { x*=10; x += broj[i]-'0'; }
        return x;
    }

void DajArgumente(std::string datum, int &d, int &m, int &g) {
    d = intaj(datum.substr(0,2));
    m = intaj(datum.substr(3,2));
    g = intaj(datum.substr(6));
}

int main ()
{
   std::string ime;
   long long int JMBG;
   std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
   int n;
   std::cin>>n;
   for(int i(0);i<n;i++) {
       std::cin.ignore(10000,'\n');
       std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
       std::getline(std::cin,ime);
       std::cout<<"Unesite JMBG: "<<std::endl;
       std::cin>>JMBG;
       try {
           auto gradjanin = GradjaninBiH(ime,JMBG);
           std::string spol = (gradjanin.DajPol()!=0) ? "zensko" : "musko";
           std::cout<<"Unijeli ste gradjanina " << gradjanin.DajImeIPrezime()<<" rodjenog "<<gradjanin.DajDanRodjenja()<<"."<<gradjanin.DajMjesecRodjenja()<<"."<<gradjanin.DajGodinuRodjenja()<<" u regiji "
                    <<gradjanin.DajSifruRegije()<<", "<<spol<<"."<<std::endl; 
       } catch(std::logic_error belaj) {
           --i;
           std::cout<< belaj.what() << std::endl;
       }
   }
   std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
   std::cin>>n;
   for(int i(0);i<n;i++) {
       std::cin.ignore(10000,'\n');
       std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
       std::getline(std::cin, ime);
       int d,m,g;
       std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
       std::string datum;
       std::getline(std::cin, datum);
       DajArgumente(datum,d,m,g);
       std::cout<<"Unesite sifru regije: "<<std::endl;
       int s;
       std::cin>>s;
       std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
       char c;
       std::cin>>c;
       GradjaninBiH::Pol pol = (c=='M') ? GradjaninBiH::Pol::Musko : GradjaninBiH::Pol::Zensko;
       try {
           auto gradjanin1 = GradjaninBiH(ime, d,m,g,s,pol);
           std::cout<<"Unijeli ste gradjanina "<< gradjanin1.DajImeIPrezime() << " JMBG: "<< gradjanin1.DajJMBG()<<"."<<std::endl;
       } catch (std::logic_error belaj) {
           --i;
           std::cout<<belaj.what()<<std::endl;
       }
   }
   
   /*std::string ime = "Murga Drot";
           GradjaninBiH g(ime, 2905017170007);
           std::cout << g.DajDanRodjenja() <<"/"<<g.DajMjesecRodjenja() <<"/" <<g.DajGodinuRodjenja()<<std::endl;
           std::cout <<  g.DajSifruRegije()<< std::endl; 
           std::cout << g.DajPol() << std::endl;*/
	return 0;
}