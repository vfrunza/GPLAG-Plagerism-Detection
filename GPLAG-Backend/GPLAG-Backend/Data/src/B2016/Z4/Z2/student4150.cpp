#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
class GradjaninBiH {
    long long int jmbg;
    int c1[13] = {};
    std::string ime;
    int d, m, g, s;
    int pol(long long int jmbg) const;
    bool prebroji(long long int jmbg);
    bool provjera(int dan, int mjesec, int godina);
    int sifra(long long int jmbg);
    void okreni(int &niz);
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
        GradjaninBiH::ime = ime_i_prezime;
        if(prebroji(jmbg) == false ) throw std::logic_error("JMBG nije validan");
        long long int jmbg3(jmbg);
        for(int i(12); i >=0; i--) {
            c1[i] = jmbg3%10;
            jmbg3/=10;
        }

            d = c1[0]*10 + c1[1];
            m = c1[2]*10 + c1[3];
            g = c1[6]*100 + c1[5]*10 + c1[6];
        if(provjera(d,m,g)==false) throw std::logic_error("JMBG nije validan");
        int c13 = 11 - (7*(c1[0]+c1[6])+6*(c1[1]+c1[7])+5*(c1[2]+c1[8])+4*(c1[3]+c1[9])+3*(c1[4]+c1[10])+2*(c1[5]+c1[11]))%11;
        if (c13 ==11)c1[12] = 0;
        else if(c13 == 10) throw std::logic_error("JMBG nije validan");
        GradjaninBiH::jmbg = jmbg;
    }
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        if(provjera(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) == false || sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
        ime = ime_i_prezime;
        c1[1] = dan_rodjenja%10;
        c1[0] = dan_rodjenja/10;
        c1[3] = mjesec_rodjenja%10 - 1;
        c1[2] = mjesec_rodjenja/10;
        c1[6] = godina_rodjenja%10;
        godina_rodjenja/=10;
        c1[5] = godina_rodjenja%10;
        c1[4] = godina_rodjenja/10;
        c1[8] = sifra_regije%10;
        c1[7] = sifra_regije/10;
  
        c1[11] = 0;
        c1[10] = 0;
        c1[9]  = 0;

        c1[12] = 11 - ((7*(c1[0]+c1[6]) + 6 * (c1[1]+c1[7]) + 5*(c1[2]+c1[8])+ 4*(c1[3]+c1[9])+3*(c1[4]+c1[10]) + 2*(c1[5]+c1[11]))%11) - 7; 
        if(c1[12]== 11) c1[12] = 0;
        if(c1[12] == 10) throw std::logic_error ("JMBG nije validan");
        
    }
    std::string DajImeIPrezime() const { return ime; }
    long long int DajJMBG() const {
        int m=13;
        long long int broj(0);
        if(c1[0]==0) m=12;
        for(int i(0); i < m;i++) {
            
            broj+=c1[i];
            broj*=10;
        }
        if(m==13) broj/=10;
        return broj;
    }
    int DajDanRodjenja() const { return c1[0]*10 + c1[1]; }
    int DajMjesecRodjenja() const { return c1[2]*10+c1[3]; }
    int DajGodinuRodjenja() const {  if((c1[4]*100 + c1[5]*10+c1[6]) < 18) return 2000 + c1[4]*100 + c1[5]*10 + c1[6];
        else return 1000 + c1[4]*100 + c1[5]*10 + c1[6];
    }
    int DajSifruRegije() const { return c1[7]*10+c1[8]; }
    Pol DajPol() const {
      int n;
        n = GradjaninBiH::pol(jmbg);
        if(n < 500 ) return Pol::Musko;
        else return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime = novo_ime;
    }
};
bool GradjaninBiH::provjera(int dan, int mjesec, int godina) {
    int mjeseci[] {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30 ,31};
    if(godina%4 == 0 && godina%100 != 0 || godina % 400 == 0) mjeseci[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan > mjeseci[mjesec-1]) return false;
    return true;
}
bool GradjaninBiH::prebroji(long long int jmbg) {
    int broj(0);
    while(jmbg != 0) {
        jmbg/=10;
        broj++;
    }
    if(broj >= 12 && broj <=13) return true;
    else return false;
}

int GradjaninBiH::sifra (long long int jmbg) {
    for(int i(0); i < 4; i++) {
        jmbg/=10;
    }
    int cifra(0);
    cifra+=jmbg%10;
    cifra*=10;
    jmbg/=10;
    cifra+=jmbg%10;
    int cifra2(0);
    for(int i(0); i < 2; i++) {
        cifra2+=cifra%10;
        cifra2*=10;
        cifra/=10;
}
return cifra2;
}
int GradjaninBiH::pol(long long int jmbg) const {
    jmbg/=10;
    int broj(0);
    for(int i(0); i < 3; i++) {
        broj+=jmbg%10;
        broj*=10;
        jmbg/=10;
        }
        int cifra2(0);
    for(int i(0); i < 3; i++) {
        cifra2 += broj%10;
        cifra2*=10;
        broj/=10;
    }
    return cifra2;
}
int main () {
  std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    int n;
    std::cin >> n;
    std::cin.clear(); 
    std::cin.ignore(10000, '\n');
    long long int jmbg;
    std::string ime;
    for(int i(0); i < n; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin, ime);
        std::cout << "Unesite JMBG: " << std::endl; 
        std::cin >> jmbg;

        try {
            GradjaninBiH g1(ime, jmbg);
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            int q;
            q = g1.DajGodinuRodjenja();
         
            std::cout << "Unijeli ste gradjanina "<<g1.DajImeIPrezime() << " rodjenog " << g1.DajDanRodjenja() << "." << g1.DajMjesecRodjenja()<<
            "." << g1.DajGodinuRodjenja() << " u regiji " << g1.DajSifruRegije() << ", ";
            if(g1.DajPol() == GradjaninBiH::Pol::Zensko) std::cout <<"zensko."<< std::endl;
            else std::cout << "musko." <<std::endl;
        }
        catch(std::logic_error e) {
            std::cout << e.what() << std::endl;
            i--;
            ime.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        ime.erase();
        }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    int br;
    std::cin >> br;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::string ime2;
    int d, m, g, s;
    char spol;
    
    GradjaninBiH::Pol pol;
    for(int i(0); i < br; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::getline(std::cin, ime2);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " <<std::endl;
        std::cin >> d >> std::ws >> m >> std::ws >> g;
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> s;
      std::cout << "Unesite M za musko, Z za zensko: "<< std::endl;
        std::cin >> spol;
        if(spol == 'M') pol = GradjaninBiH::Pol::Musko;
        if(spol == 'Z') pol = GradjaninBiH::Pol::Zensko;
        try {
            auto g2 = GradjaninBiH(ime2, d, m, g , s, pol);
            ime2.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if(g2.DajDanRodjenja()<10) std::cout << "Unijeli ste gradjanina "<< g2.DajImeIPrezime() << " JMBG: 0" << g2.DajJMBG() << "." << std::endl;
           else  std::cout << "Unijeli ste gradjanina " << g2.DajImeIPrezime() << " JMBG: " << g2.DajJMBG() << "." << std::endl;
 }catch(std::logic_error e) {
    std::cout << e.what() << std::endl;
    i--;
    ime2.clear();
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}    
}
	return 0;
}