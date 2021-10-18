/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>
#include <initializer_list>

class Datum{
    int Dan,Mj,God;
    
    public: 
    Datum(int dan=1, int mjesec=1, int godina=2000){
        if(dan<1 or dan>31 or mjesec<1 or mjesec>12) throw std::domain_error{"Neispravan datum"};
        else{
            Dan=dan;
            Mj=mjesec;
            God=godina;
        }
    };
    void Postavi(int dan, int mjesec, int godina){
        if(dan<1 or dan>31 or mjesec<1 or mjesec>12) throw std::domain_error{"Neispravan datum"};
        else {
            Dan=dan;
            Mj=mjesec;
            God=godina;
        }
    };
    std::tuple<int, int, int> Ocitaj() const{
        std::tuple<int,int,int> a=std::make_tuple(Dan,Mj,God);
        return a;
    };
    void Ispisi() const{
        std::cout<<Dan<<"/"<<Mj<<"/"<<God;
    };  
};
class Vrijeme{
    int S,Min;
    
    public:
    Vrijeme(int sati=0, int minute=0){
        if(sati<0 or sati>23 or minute <0 or minute >59) throw std::domain_error{"Neispravno vrijeme"};
        else{
            S=sati;
            Min=minute;
        }
    };
    void Postavi(int sati, int minute){
        if(sati<0 or sati>23 or minute <0 or minute >59) throw std::domain_error{"Neispravno vrijeme"};
        else{
            S=sati;
            Min=minute;
        }
    };
    std::pair<int, int> Ocitaj () const{
        std::pair<int,int> a=std::make_pair(S,Min);
        return a;
    };
    void Ispisi() const{
        if(S<10) std::cout<<"0"<<S<<":"<<Min;
        else std::cout<<S<<":"<<Min;
    };
};


class Pregled{
    Datum D;
    Vrijeme V;
    std::string ime;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){         //
        this->ime=ime_pacijenta;
        this->D=datum_pregleda;
        this->V=vrijeme_pregleda;
    };
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda){
        D.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda);
        V.Postavi(sati_pregleda,minute_pregleda);
        this->ime=ime_pacijenta;
    };
    void PromijeniPacijenta(const std::string &ime_pacijenta){                                                      //
        this->ime=ime_pacijenta;
    };
    void PromijeniDatum(const Datum &novi_datum){                                                                   //
        this->D=novi_datum;
    };
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){                                                             //
        this->V=novo_vrijeme;
    };
    void PomjeriDanUnaprijed(){
        std::tuple<int,int,int> a=D.Ocitaj();
        int tmp=std::get<0>(a);
        int tmp2=std::get<1>(a);
        int tmp3=std::get<2>(a);
        D.Postavi(tmp+1,tmp2,tmp3);
    };
    void PomjeriDanUnazad(){
        std::tuple<int,int,int> b=D.Ocitaj();
        int tmp=std::get<0>(b);
        int tmp2=std::get<1>(b);
        int tmp3=std::get<2>(b);
        D.Postavi(tmp-1,tmp2,tmp3);
    };
    std::string DajImePacijenta() const{
        return this->ime;
    };
    Datum DajDatumPregleda() const{
        return this->D;
    };
    Vrijeme DajVrijemePregleda() const{
        return this->V;
    };
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        bool rez=false;
        std::tuple<int,int,int>tmp=p1.D.Ocitaj();
        std::tuple<int,int,int>tmp2=p2.D.Ocitaj();
        std::pair<int,int>tmp3=p1.V.Ocitaj();
        std::pair<int,int>tmp4=p2.V.Ocitaj();
        if(std::get<2>(tmp)<std::get<2>(tmp2)){rez=true;return rez;}
        else if(std::get<2>(tmp)==std::get<2>(tmp2)and std::get<1>(tmp)<std::get<1>(tmp2)){rez=true;return rez;}
        else if(std::get<2>(tmp)==std::get<2>(tmp2)and std::get<1>(tmp)==std::get<1>(tmp2) and std::get<0>(tmp)<std::get<0>(tmp2)){rez=true;return rez;}
        else if(std::get<2>(tmp)==std::get<2>(tmp2)and std::get<1>(tmp)==std::get<1>(tmp2) and std::get<0>(tmp)==std::get<0>(tmp2) and std::get<1>(tmp3)<std::get<1>(tmp4)){rez=true;return rez;}
        else if(std::get<2>(tmp)==std::get<2>(tmp2)and std::get<1>(tmp)==std::get<1>(tmp2) and std::get<0>(tmp)<std::get<0>(tmp2) and std::get<1>(tmp3)==std::get<1>(tmp4)and std::get<0>(tmp3)<std::get<0>(tmp4)){rez=true;return rez;}
        else if(std::get<2>(tmp)==std::get<2>(tmp2)and std::get<1>(tmp)==std::get<1>(tmp2) and std::get<0>(tmp)<std::get<0>(tmp2) and std::get<1>(tmp3)==std::get<1>(tmp4)and std::get<0>(tmp3)==std::get<0>(tmp4)){rez=true;return rez;}
        return rez;
    };
    void Ispisi()const{
        std::cout<<std::setw(30)<<std::left<<ime<<" ";D.Ispisi();std::cout<<" ";V.Ispisi();std::cout<<std::endl;
    };
};

int main ()
{
	return 0;
}
