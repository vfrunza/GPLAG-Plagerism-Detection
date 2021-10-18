#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdio>
class GradjaninBiH{
    private: 
        int c[13];
        std::string s;
        static GradjaninBiH* pok;
        GradjaninBiH *prev;
    public:
        enum Pol{Musko,Zensko};
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol);
        std::string DajImeIPrezime()const{return s;}
        long long int DajJMBG() const{
            long long int ret(0); for(int i = 0; i < 13; i++) {ret*= 10; ret +=c[i]; ;}
            return ret;
        }
        GradjaninBiH(const GradjaninBiH &g) = delete;
        GradjaninBiH &operator=(const GradjaninBiH &g) = delete;
        ~GradjaninBiH(){
            for(auto i(pok);i !=nullptr;i=i->prev){
                if(i == this) {pok = this->prev; break;}
                if(i->prev == this) {i->prev = this->prev; break;}
            }
        }
        int DajDanRodjenja()const{return c[0]*10 +c[1];}
        int DajMjesecRodjenja()const{return c[2]*10+c[3];}
        int DajGodinuRodjenja()const{
            int ret(c[4]*100+c[5]*10+c[6]+1000); if(ret < 1100)ret += 1000;
            return ret;
        }
        int DajSifruRegije()const{return c[7]*10+c[8];}
        Pol DajPol() const{
            if(c[9]>= 5) return Pol::Zensko; return Pol::Musko;
        }
        void PromijeniImeIPrezime(std::string novo_ime){s = novo_ime;}
    private:
        static int numD(int mon, int god){
            int arr[]{31,28,31,30,31,30,31,31,30,31,30,31};
            if((god%4 == 0 && god%100 != 0) ||god%400 == 0) arr[1]++;
            return arr[mon-1];
        }
        static bool validDat(int god, int dan, int mon);
};
GradjaninBiH *GradjaninBiH::pok = nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja,int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol):prev(pok){
    if(!validDat(godina_rodjenja,dan_rodjenja,mjesec_rodjenja) || sifra_regije<0 || sifra_regije>99)
        throw std::logic_error("Neispravni podaci");
    s = ime_i_prezime; godina_rodjenja = godina_rodjenja%1000;
    c[0] = dan_rodjenja/10; c[1] = dan_rodjenja%10;
    c[2] = mjesec_rodjenja/10; c[3] = mjesec_rodjenja%10;
    c[4] = godina_rodjenja/100; c[5] = godina_rodjenja/10-c[4]*10;
    c[6] = godina_rodjenja%10; c[7] = sifra_regije/10; c[8] = sifra_regije%10;
    int min = 0, max = 499; if (pol ==Pol::Zensko)min = 500,max=999;
    for(int i = min; i <= max; i++){
        c[9] = i/100; c[10] = i/10-c[9]*10; c[11] = i%10;
        c[12] = 11 -(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
        if(c[12]==11) c[12] = 0; if(c[12] == 10) continue;
        bool nema(true); 
        for(auto ogod(pok); ogod != nullptr; ogod = ogod->prev)
            if(ogod->DajJMBG() == DajJMBG() && this != ogod) nema = false;
        if(nema) break;
    }
    pok = this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg):prev(pok){
    s = ime_i_prezime; int pos(12);
    while(jmbg){
        c[pos--] = jmbg%10;
        jmbg/=10;
    }if(pos == 0) c[0] = 0;
    int c13 = 11 -(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    if(c13 ==11) c13 = 0;
    if(c13 != c[12]) throw std::logic_error("JMBG nije validan");
    int dan = c[0]*10+c[1],mon = c[2]*10+c[3];
    int god = c[4]*100+c[5]*10+c[6];
    if(god <= 17) god+=2000;
    else if(god > 17) god += 1000;
    if(!validDat(god,dan,mon)) throw std::logic_error("JMBG nije validan");
    for(auto i(pok); i != nullptr;i=i->prev)
        if(i->DajJMBG() == DajJMBG() && this != i) 
            throw std::logic_error("Vec postoji gradjanin sa tim JMBG");
    
    pok = this;
}
bool GradjaninBiH::validDat(int god, int dan, int mon){
    return !(god < 1918 || dan < 1 || mon < 1|| mon > 12 || dan > numD(mon,god));
}


int main () {
    GradjaninBiH* niz[100]{};
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n; std::cin >> n; std::cin.ignore(100,'\n');
    for(int i = 0; i < n; i++){
        try{
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string s; std::getline(std::cin,s);
            std::cout << "Unesite JMBG: \n";
            long long int j; std::cin >> j; std::cin.ignore(100,'\n');
            niz[i] = new GradjaninBiH(s,j);
            std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " <<
            niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "."<< niz[i]->DajGodinuRodjenja()<<
            " u regiji " << niz[i]->DajSifruRegije() << ", ";
            if(niz[i]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.\n";
            else std::cout << "zensko.\n";
        }catch(std::logic_error err){
            std::cout << err.what() << std::endl; i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int n2; std::cin>> n2; std::cin.ignore(100,'\n');
    for(int i = 0; i < n2; i++){
        try{
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string s; std::getline(std::cin,s);
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
            int d,m,god; std::scanf("%d/%d/%d", &d,&m,&god);
            std::cout << "Unesite sifru regije: \n";
            int kod; std::cin >> kod; std::cin.ignore(100,'\n');
            std::cout << "Unesite M za musko, Z za zensko: \n";
            char c; c = std::getchar();
            auto pol = GradjaninBiH::Pol::Musko;
            if(c == 'Z') pol = GradjaninBiH::Pol::Zensko;
            niz[i+n] = new GradjaninBiH(s,d,m,god,kod,pol);
            std::cout << "Unijeli ste gradjanina " << niz[i+n]->DajImeIPrezime() <<
            " JMBG: " << niz[i+n]->DajJMBG() << ".\n";
            std::cin.ignore(100,'\n');
        }catch(std::logic_error err){
            std::cin.ignore(100,'\n');
            std::cout << err.what() << std::endl; i--;
        }
    }
    for(int i = 0; i < n + n2; i++) delete niz[i];
	return 0;
}