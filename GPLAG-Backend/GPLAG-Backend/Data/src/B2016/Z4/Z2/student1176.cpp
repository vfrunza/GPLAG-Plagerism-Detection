#include <iostream> 
#include <string>  
#include <stdexcept>
enum Pol{Musko, Zensko};
class GradjaninBiH{ 
    std::string ip; 
    int dan, mjesec, godina, regija;  
    long long int jmb;
    Pol pol1;
    public: 
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        ip=ime_i_prezime; 
        jmb=jmbg;
        dan=jmbg/100000000000;
        mjesec=jmbg/1000000000%10+(jmbg/1000000000)%100/10*10;
        godina=(jmbg/1000000)%1000; 
        if(godina<18) godina+=2000;
        if(godina>17) godina+=1000;
        regija=(jmbg/10000)%100; 
        int sifra=(jmbg/10)%1000;
        if(sifra>=0 && sifra<=499) pol1=Musko;
        if(sifra>499 && sifra<=999) GradjaninBiH::pol1=Pol::Zensko; 
        int c13=11-(7*(dan/10+godina%10)+6*(dan%10+regija/10)+5*(mjesec/10+regija%10)+4*(mjesec%10+sifra/100)+3*(godina/100%10+sifra/10%10)+2*(godina/10%10+sifra%10))%11;
        if(c13==11) c13=0; 
        if(c13==10) throw std::logic_error("JMBG nije validan");
    } 
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        if(regija<0 || regija>99) throw std::logic_error("Neispravni podaci"); 
        int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina_rodjenja%4==0 && godina_rodjenja%100!=0 || godina_rodjenja%400==0) br_dana[1]++; 
        if(godina_rodjenja<1 || dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>br_dana[mjesec_rodjenja-1]) 
        throw std::logic_error("Neispravni podaci");
        ip=ime_i_prezime;
        dan=dan_rodjenja;
        mjesec=mjesec_rodjenja;
        godina=godina_rodjenja;
        regija=sifra_regije; 
        jmb=dan*100000000000+mjesec*1000000000+godina%1000*1000000+regija*10000+0*1000;
        pol1=pol;   
        int br1; 
    } 
    std::string DajImeIPrezime() const{
        return ip;
    } 
    long long int DajJMBG() const{
        return jmb;
    } 
    int DajDanRodjenja() const{
        return dan;
    }
    int DajMjesecRodjenja() const{
        return mjesec;
    } 
    int DajGodinuRodjenja() const{
        return godina;
    } 
    int DajSifruRegije() {
        return regija;
    } 
    Pol DajPol() const{
        return pol1;
    } 
    void PromijeniImeIPrezime(std::string novo_ime){
        ip=novo_ime;
    }
};
int main ()
{ 
    int n;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    std::cin >> n;  
    std::cin.clear();
    std::cin.ignore(10000, '\n');  
    long long int jmb;
    std::string ip; 
    for(int i(0); i<n; ++i){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl; 
        std::getline(std::cin, ip); 
        std::cout << "Unesite JMBG: " << std::endl;
        std::cin >> jmb; 
        try{
            GradjaninBiH gradanin(ip, jmb); 
            ip.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Unijeli ste gradjanina " << gradanin.DajImeIPrezime() << " rodjenog " << gradanin.DajDanRodjenja() << "." << 
            gradanin.DajMjesecRodjenja() << "." << gradanin.DajGodinuRodjenja() << " u regiji " << gradanin.DajSifruRegije() << ",";
            if(gradanin.DajPol()==Pol::Zensko) std::cout << " zensko." << std::endl;
            if(gradanin.DajPol()==Pol::Musko) std::cout << " musko." << std::endl; 
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl; 
            i--;
            ip.clear();  
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } 
        ip.erase();
    }  
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl; 
    int n2;
    std::cin >> n2;
    std::cin.clear();
    std::cin.ignore(10000, '\n'); 
    std::string ip2; 
    int g, m, d, sifra;
    char spol, x;
    Pol pol; 
    for(int i(0); i<n2; ++i){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl; 
        std::getline(std::cin, ip2);
        std::cout << "Unesite datum rodjenja (format dd/mm/gg): " << std::endl;
        std::cin >> d;
        std::cin >> x;
        std::cin >> m;
        std::cin >> x;
        std::cin >> g; 
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        std::cin >> spol;
        if(spol=='Z') pol=Zensko;
        if(spol=='M') pol=Musko; 
        try{
            auto gradanin2=GradjaninBiH(ip2, d, m, g, sifra, pol);
            ip2.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Unijeli ste gradjanina " << gradanin2.DajImeIPrezime() << " JMBG: " << gradanin2.DajJMBG() << "." << std::endl;
        } 
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
            i--;
            ip2.clear();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
	return 0;
}