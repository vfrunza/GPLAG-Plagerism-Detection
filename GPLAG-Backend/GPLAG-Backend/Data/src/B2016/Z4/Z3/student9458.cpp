/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class Datum{
    int dan,mjesec,godina;
    bool JelDobar(int d, int m, int g){
        int brojdana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g % 4 == 0 && g % 100 != 0 )|| g % 400 == 0) brojdana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > brojdana[m-1])return false;
        return true;
    }
    public:
    int DajDan()const{return dan;}
    int DajMjesec()const{return mjesec;}
    int DajGodinu()const{return godina;}
    void Ispisi()const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
    Datum(int d, int m, int g);
};
class Kupac{
    std::string imeprezime;
    Datum datumrodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};
Datum::Datum(int d, int m, int g){
    if(JelDobar(d,m,g)){dan=d;mjesec=m;godina=g;}
    else throw std::domain_error("Neispravan datum");
}
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i=0; i<ime_i_prezime.length();i++){
        if(ime_i_prezime[i]<'0' && ime_i_prezime[i]>'9' && ime_i_prezime[i]<'A' && ime_i_prezime[i]<'a'&& ime_i_prezime[i]>'Z'&&ime_i_prezime[i]>'z'&& ime_i_prezime[i]!='-')throw std::domain_error("Neispravno ime i prezime");
    }
    imeprezime=ime_i_prezime; datumrodjenja(Datum::DajMjesec(),Datum::DajGodinu());
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    imeprezime=ime_i_prezime; datumrodjenja=datum_rodjenja;
}
std::string Kupac::DajImePrezime()const{
    return imeprezime;
}
Datum Kupac::DajDatumRodjenja()const{
    
}
int main ()
{
    
	return 0;
}