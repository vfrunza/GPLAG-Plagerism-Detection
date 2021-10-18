/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <memory>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>

using namespace std;

class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){                                          //provjera vremena
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    tuple<int, int, int> Ocitaj()const{
        return tuple<int, int, int>(Datum::dan, Datum::mjesec, Datum::godina);
    }
    void Ispisi()const{
        cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
    }
    int DajDan()const {return this->dan;}
    int DajMjesec()const{return this->mjesec;}
    int DajGodinu()const{return this->godina;}
    friend class Pregled;
    friend class Pregledi;
};
class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute){
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    pair<int, int> Ocitaj()const{
        return pair<int, int>(Vrijeme::sati, Vrijeme:: minute);
    }
    void Ispisi()const{
        cout<<Vrijeme::sati<<":"<<Vrijeme::minute;
    }
    int DajMinute()const{
        return this->minute;
    }
    int DajSate()const{return this->sati;}
    friend class Pregled;
    friend class Pregledi;
};
class Pregled{
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    
    public:
    
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta; 
    }
    
  Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),vrijeme_pregleda(sati_pregleda, minute_pregleda){
      Pregled::ime_pacijenta=ime_pacijenta;
}
  void PromijeniPacijenta(const string &ime_pacijenta){
      Pregled::ime_pacijenta=ime_pacijenta;
  }
  void PromijeniDatum(const Datum &novi_datum){
       auto t1=novi_datum.Datum::Ocitaj();
       datum_pregleda.Datum::Postavi(get<0>(t1), get<1>(t1), get<2>(t1));
  }
  void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
      auto t2=novo_vrijeme.Vrijeme::Ocitaj();
      Pregled::vrijeme_pregleda.Vrijeme::Postavi(t2.first,t2.second);
  }
  void PomjeriDanUnaprijed(){
      auto t1=Pregled::datum_pregleda.Datum::Ocitaj();
      datum_pregleda.Datum::Postavi(get<0>(t1)+1, get<1>(t1), get<2>(t1));
  }
  void PomjeriDanUnazad(){                                                                  //prelazi mjesec..
      auto t1=Pregled::datum_pregleda.Datum::Ocitaj();
      datum_pregleda.Datum::Postavi(get<0>(t1)-1, get<1>(t1), get<2>(t1));
  }
  string DajImePacijenta() const{
      return Pregled::ime_pacijenta;
  }
  Datum DajDatumPregleda() const{
      return Pregled::datum_pregleda;
  }
  Vrijeme DajVrijemePregleda() const{
      return Pregled::vrijeme_pregleda;
  }
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
      auto t1=p1.DajDatumPregleda();
      auto t2=p2.DajDatumPregleda();
      return true;
  }
  void Ispisi() const{
      cout<<Pregled::ime_pacijenta;
      Pregled::datum_pregleda.Datum::Ispisi();
      Pregled::vrijeme_pregleda.Vrijeme::Ispisi();
      cout<<endl;
  }
 
 friend class Pregledi;
};

class Pregledi {
int broj_pregleda;
int mbp;
Pregled **p{};
Pregledi()=default;
void Alociraj(int br) {
    p=nullptr;
    try {
        p=new Pregled*[br];
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
public:
explicit Pregledi(int max_pregleda) : broj_pregleda(0), mbp(max_pregleda) {Alociraj(mbp);}
Pregledi(initializer_list<Pregled> spisak_pregleda) : broj_pregleda(spisak_pregleda.size()), mbp(spisak_pregleda.size()) {
    
    try {
        p=new Pregled*[broj_pregleda];
        for(int i=0; i<broj_pregleda; i++) p[i]=nullptr;
            int molim_te=-1;
        for(auto &molim_te_lijepo : spisak_pregleda) p[++molim_te]=new Pregled(molim_te_lijepo);
    }catch(...){
        IsprazniKolekciju();
        throw;
    }
}
~Pregledi() {
    for(int i=0; i<mbp; i++) delete p[i];
    delete[] p;
}
Pregledi(const Pregledi &p) : broj_pregleda(p.broj_pregleda), mbp(p.mbp) {
    Alociraj(mbp);
    try {
        for(int i=0; i<broj_pregleda; i++) this->p[i]=new Pregled(*p.p[i]);
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
Pregledi(Pregledi &&p1) : broj_pregleda(p1.broj_pregleda), mbp(p1.mbp) {
    this->p=p1.p;
    p1.p=nullptr;
}
Pregledi &operator =(const Pregledi &p1) {
    if(mbp!=p1.mbp) throw logic_error("Nesaglasne liste pregleda");
    if(&p1==this) return *this;
    
    try {
        for(int i=0; i<mbp; i++) this->p[i]=new Pregled(*p1.p[i]);
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
Pregledi &operator =(Pregledi &&p) {
    if(mbp!=p.mbp) throw logic_error("Nesaglasne liste pregleda");
    if(&p==this) return *this;
    
    this->p=p.p;
    broj_pregleda=p.broj_pregleda;
    p.p=nullptr;
}
void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(broj_pregleda==mbp) throw range_error("“Dostignut maksimalni broj pregleda");
    try {
        p[broj_pregleda++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }catch(bad_alloc) {
        broj_pregleda--;
        throw logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(broj_pregleda==mbp) throw range_error("“Dostignut maksimalni broj pregleda");
    try {
        p[broj_pregleda++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }catch(bad_alloc) {
        broj_pregleda--;
        throw logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
void RegistrirajPregled(Pregled *pregled) {
     if(broj_pregleda==mbp) throw range_error("“Dostignut maksimalni broj pregleda");
     try {
         p[broj_pregleda++]=pregled;
     }catch(bad_alloc) {
        broj_pregleda--;
        throw logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
int DajBrojPregleda() const {
    if(broj_pregleda==0) throw domain_error("Nema registriranih pregleda");
    return broj_pregleda;
}
int DajBrojPregledaNaDatum(const Datum &datum) const {
    if(broj_pregleda==0) throw domain_error("Nema registriranih pregleda");
    return count_if(p, p+broj_pregleda, [&](Pregled *pregled) {
        return (pregled->DajDatumPregleda().DajDan()==datum.DajDan() && pregled->DajDatumPregleda().DajMjesec()==datum.DajMjesec() && pregled->DajDatumPregleda().DajGodinu()==datum.DajGodinu());
    });
}
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju() {
    if(p==nullptr) return;
    for(int i=0; i<broj_pregleda; i++) delete p[i];
    delete[] p;
}
void ObrisiNajranijiPregled() {
    if(broj_pregleda==0) throw range_error("Prazna kolekcija");
    Pregled pregled=Pregledi::DajNajranijiPregled();
    Pregledi temp_pregledi = Pregledi(mbp);
    int brojac=0;
    for (int i=0; i<broj_pregleda; i++) {
        auto a=p[i];
        if (a->DajImePacijenta()==pregled.DajImePacijenta() && a->DajDatumPregleda().DajDan()==pregled.DajDatumPregleda().DajDan() && a->DajDatumPregleda().DajMjesec()==pregled.DajDatumPregleda().DajMjesec() && a->DajDatumPregleda().DajGodinu()==pregled.DajDatumPregleda().DajGodinu() && a->DajVrijemePregleda().DajSate()==pregled.DajVrijemePregleda().DajSate() && pregled.DajVrijemePregleda().DajMinute() == pregled.DajVrijemePregleda().DajMinute()) continue;
        temp_pregledi.p[brojac++] = p[i];
    }
    copy(temp_pregledi.p, temp_pregledi.p+mbp, p);
    broj_pregleda--;
}
void ObrisiPregledePacijenta(const string &ime_pacijenta) {
    if(broj_pregleda==0) range_error("Prazna kolekcija");
    if(broj_pregleda>0) {
        Pregledi temp=Pregledi(mbp);
        int brojac=0;
        for(int i=0; i<broj_pregleda; i++) {
            if(p[i]->DajImePacijenta()==ime_pacijenta) continue;
            temp.p[brojac++]=p[i];
        }
        broj_pregleda=brojac;
        copy(temp.p, temp.p+mbp, p);
    }
}
void IspisiPregledeNaDatum(const Datum &datum) const {
    bool ima_pregleda(false);
    for(int i = 0; i < broj_pregleda; i++) {
        if(p[i]->DajDatumPregleda().DajDan() == datum.DajDan() && p[i]->DajDatumPregleda().DajMjesec() == datum.DajMjesec() && p[i]->DajDatumPregleda().DajGodinu() == datum.DajGodinu()) {
            (*p[i]).Ispisi();
            cout << endl;
            ima_pregleda = true;
        }
    }
    if(!ima_pregleda) throw "Nema pregleda na traženi dan!\n"; 
}
void IspisiSvePreglede() const {
    bool ima_pregleda(false);
    for(int i = 0; i < broj_pregleda; i++) {
        (*p[i]).Ispisi();
        cout << endl;
        ima_pregleda = true;
    }
    if(!ima_pregleda) throw "Nema pregleda!\n"; 
}

};

Pregled &Pregledi::DajNajranijiPregled() {
    if(broj_pregleda==0) throw domain_error("Nema registriranih pregleda");
    Pregled *najraniji(p[0]);
    for(int i = 1; i < broj_pregleda; i++) {
        if(Pregled::DolaziPrije(*p[i], *najraniji)) najraniji = p[i];
    }
    return *najraniji;
}
Pregled Pregledi::DajNajranijiPregled() const {
    if(broj_pregleda==0) throw domain_error("Nema registriranih pregleda");
    Pregled *najraniji(p[0]);
    for(int i = 1; i < broj_pregleda; i++) {
        if(Pregled::DolaziPrije(*p[i], *najraniji)) najraniji = p[i];
    }
    return *najraniji;
}



int main (){
   
	return 0;
}
