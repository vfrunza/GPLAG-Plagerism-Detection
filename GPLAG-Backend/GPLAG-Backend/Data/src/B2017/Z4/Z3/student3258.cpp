/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <memory>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina; //provjera
    }
    void Postavi(int dan, int mjesec, int godina){
       *this=Datum(dan,mjesec,godina); //provjera
    }
    tuple<int, int, int> Ocitaj()const{
        return tuple<int,int,int>(dan,mjesec,godina);
    }
    void Ispisi()const{
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
};

class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute){
        *this=Vrijeme(sati, minute);
    }
    pair<int, int> Ocitaj()const{
        return pair<int, int>(sati, minute);
    }
    void Ispisi()const{
        cout<<sati<<":"<<minute;
    }
    friend class Pregled;
};

class Pregled{
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    string ime_pacijenta;
    public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    Pregled(const string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,int godina_pregleda, int sat_pregleda, int minute_pregleda): datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sat_pregleda,minute_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromjeniPacijenta(const string ime_pacijenta){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){datum_pregleda=novi_datum;}
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){vrijeme_pregleda=novo_vrijeme;}
    void PomjeriDanUnaprijed(){
        tuple<int, int, int> temp=datum_pregleda.Datum::Ocitaj();
        //provjera vremena..
        datum_pregleda.Datum::Postavi(get<0>(temp)+1,get<1>(temp),get<2>(temp)); 
    }
    void PomjeriDanUnazad(){
        tuple<int, int, int> temp=datum_pregleda.Datum::Ocitaj();
        //provjera vremena..
        datum_pregleda.Datum::Postavi(get<0>(temp)-1,get<1>(temp),get<2>(temp)); 
    }
    string DajImePacijenta()const{return ime_pacijenta;}
    Datum DajDatumPregleda()const{return datum_pregleda;}
    Vrijeme DajVrijemePregleda()const{return vrijeme_pregleda;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.Pregled::datum_pregleda.godina<p2.Pregled::datum_pregleda.godina)return false;
        if(p1.Pregled::datum_pregleda.godina>p2.Pregled::datum_pregleda.godina)return true;
         
         if(p1.Pregled::datum_pregleda.mjesec<p2.Pregled::datum_pregleda.mjesec)return false;
        if(p1.Pregled::datum_pregleda.mjesec>p2.Pregled::datum_pregleda.mjesec)return true;
        
         if(p1.Pregled::datum_pregleda.dan<p2.Pregled::datum_pregleda.dan)return false;
        if(p1.Pregled::datum_pregleda.dan>p2.Pregled::datum_pregleda.dan)return true;
        
         if(p1.Pregled::vrijeme_pregleda.sati<p2.Pregled::vrijeme_pregleda.sati)return false;
        if(p1.Pregled::vrijeme_pregleda.sati>p2.Pregled::vrijeme_pregleda.sati)return true;
        
        if(p1.Pregled::vrijeme_pregleda.minute<p2.Pregled::vrijeme_pregleda.minute)return false;
        if(p1.Pregled::vrijeme_pregleda.minute>p2.Pregled::vrijeme_pregleda.minute)return true;
        
        return true;
    }
    void Ispisi()const{
        cout<<setw(30)<<left<<ime_pacijenta;
        datum_pregleda.Datum::Ispisi();
        cout<<" ";
        vrijeme_pregleda.Vrijeme::Ispisi();
}

friend class Pregledi;
};

class Pregledi{
    int broj_pregleda;
    const int max_broj;
    Pregled** pregled;
    void Alociraj(int br){
        pregled=nullptr;
        try {
            pregled=new Pregled*[br];
        }catch(...) {
            IsprazniKolekciju();
            throw;
        }
        return *this;
    }
public:
    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0), max_broj(max_broj_pregleda), pregled(nullptr) {Alociraj(max_broj_pregleda);}
    Pregledi(initializer_list<Pregled>spisak_pregleda) : broj_pregleda(spisak_pregleda.size()), max_broj(pregledi.broj_pregleda), pregled(nullptr) {
        int brojac=0;
        try {
            pregled=new Pregled*[broj_pregleda];
            for(int i=0; i<broj_pregleda; i++) pregled[i]=nullptr;
            for(auto &i : spisak_pregleda) pregled[brojac++]=new Pregled(x);
        }catch(...) {
            IsprazniKolekciju();
            throw;
        }
    }
    ~Pregledi(){
        if(pregled==nullptr) return;
        for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
        delete[] pregled;
    }
    Pregledi(const Pregledi &pregledi):broj_pregleda(pregledi.broj_pregleda), max_broj(pregledi.broj_pregleda),pregled(nullptr){
        Alociraj(max_broj);
        try{
            for(int i=0;i<broj_pregleda;i++){
                this->pregled[i]=new Pregled (*pregledi.pregled[i]);
            }
        }catch(...){
            IsprazniKolekciju();
            throw;
        }
    }
    Pregledi(Pregledi &&pregledi):broj_pregleda(pregled.broj_pregleda), max_broj(pregledi.broj_pregleda), pregled(nullptr){
        pregled=pregledi.pregled;
        pregledi.pregled=nullptr;
    }
    
    Pregledi &operator =(const Pregledi &pregledi){
        if(max_broj!=pregledi.max_broj)throw std::logic_error("Nesaglasne liste pregleda");
        if(&pregledi==this)return *this;
        for(int i=0; i<broj_pregleda;i++)delete pregledi[i];
        broj_pregleda=pregledi.broj_pregleda;
        try{
            for(int i=0;i<broj_pregleda;i++)pregled[i]=new Pregled(*pregledi.pregled[i]);
        }catch(...){
            IsprazniKolekciju();
            throw;
        }
        return *this;
    }
    
    Pregledi &operator =(Pregledi && pregledi){
        if(max_broj!=pregledi.max_broj)throw std::logic_error("Nesaglasne liste pregleda");
        if(&pregledi==this)return *this;
        pregledi=pregledi.pregled;
        broj_pregleda=pregledi.broj_pregleda;
        pregledi.pregled=nullptr;
        return *this;
        
    }
    
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme vrijeme_pregleda){
        if(broj_pregleda==max_broj)throw std::range_error("Raspored popunjen");
        try{
            pregled[broj_pregleda++]=new Pregled(ime_pacijenta,datum_pregleda, vrijeme_pregleda);
        }catch(bad_alloc){
            broj_pregleda--;
            throw logic_error("Neuspjesna registracija pregleda");
        }catch(...){
            broj_pregleda--;
            throw;
        }
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sat_pregleda, int minute_pregleda) {
        if(broj_pregleda==max_broj)throw std::range_error("Raspored popunjen");
        try{
            pregled[broj_pregleda++]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda, sat_pregleda, minute_pregleda);
        }catch(bad_alloc){
            broj_pregleda--;
            throw logic_error("Neuspjesna registracija pregleda");
        }catch(...){
            broj_pregleda--;
            throw;
        }
    }
    /*void RegistrirajPregled(Pregled &pregled){
        if(broj_pregleda==max_broj) throw range_error("Raspored popunjen");
        this->pregled[broj_pregleda++]=new Pregled(*pregled);
    }*/
    int DajBrojPregleda() const {return broj_pregleda;}
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int brojac=0;
        
        return brojac;
    }
    
};









int main (){
    
    
	return 0;
}
