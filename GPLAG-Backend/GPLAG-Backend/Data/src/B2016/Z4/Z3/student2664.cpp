/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>



class Datum {
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi() const {
        std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu()<<std::endl;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina % 4 == 0 || godina % 100 != 0 || godina % 4 == 0) broj_dana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
    Datum::dan = dan; Datum::mjesec = mjesec ; Datum::godina = godina;
}


//KLASA KUPAC

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;  
    public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajIMePrezime() const{
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const{
        return datum_rodjenja;
    }
    void Ispisi() const;
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    //ispitati ispravnost datuma
   
    
    
    //ispitati ispravnost imena i prezimena
    
    for (int i = 0 ; i < ime_i_prezime.size(); i++){
        if( ime_i_prezime.at(i) < 65 || ime_i_prezime.at(i) > 122) throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime = ime_i_prezime;
    Kupac::datum_rodjenja = datum_rodjenja;
    
}

void Kupac::Ispisi() const {
    std::cout<<DajIMePrezime()<<"("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")";
}
int main ()
{
	return 0;
}