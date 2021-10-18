/B2017/2018: Zadaća 4, Zadatak 4
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

class Datum {
int dan_pr, mjesec_pr, godina_pr;
void DajDane() const {return dan_pr;}
void DajMjesec() const {return mjesec_pr;}
void DajGodine() const {return godina_pr;}
public:
Datum(int dan, int mjesec, int godina) {
    if(dan<0 || mjesec<1 || mjesec>12 || godina<0 || godina>2018) throw std::domain_error("Neispravan datum");
    if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31) throw std::domain_error("Neispravan datum");
    if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30) throw std::domain_error("Neispravan datum");
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) {
        if(mjesec==2 && dan>29) throw std::domain_error("Neispravan datum");
    } else {
        if(mjesec==2 && dan>28) throw std::domain_error("Neispravan datum");
    }
    Datum::dan_pr=dan;
    Datum::mjesec_pr=mjesec;
    Datum::godina_pr=godina;
}
void Postavi(int dan, int mjesec, int godina) {
    if(dan<0 || mjesec<0 || mjesec>12 || godina<0 || godina>2018) throw std::domain_error("Neispravan datum");
    if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31) throw std::domain_error("Neispravan datum");
    if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30) throw std::domain_error("Neispravan datum");
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) {
        if(mjesec==2 && dan>29) throw std::domain_error("Neispravan datum");
    } else {
        if(mjesec==2 && dan>28) throw std::domain_error("Neispravan datum");
    }
    *this=Datum(dan, mjesec, godina);
}
std::tuple<int, int, int>Ocitaj() const {
    return std::make_tuple(dan_pr, mjesec_pr, godina_pr);
}
void Ispisi() const {std::cout << dan_pr << "/" << mjesec_pr << "/" << godina_pr << std::endl;}
friend class Pregled;
friend class Pregledi;
};


class Vrijeme {
int sati_pr, minute_pr;
void DajSate() const {return sati_pr;}
void DajMinute() const {return minute_pr;}
public:
Vrijeme(int sati, int minute) {
    if(sati<0 || minute<0 || sati>23 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati_pr=sati; 
    Vrijeme::minute_pr=minute;
}
void Postavi(int sati, int minute) {
    if(sati<0 || minute<0 || sati>23 || minute>59) throw std::domain_error("Neispravno vrijeme");
    *this=Vrijeme(sati, minute);    
}
std::pair<int, int>Ocitaj() const {
    return std::make_pair(sati_pr, minute_pr);
}
void Ispisi() const {std::cout << std::setw(2) << std::setfill('0') << sati_pr << ":" << std::setw(2) << minute_pr;}
friend class Pregled;
friend class Pregledi;
};


class Pregled {
std::string ime_pacijenta_pr;
Datum datum;
Vrijeme vrijeme;
public: 
Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum(datum_pregleda), vrijeme(vrijeme_pregleda) {
    Pregled::ime_pacijenta_pr=ime_pacijenta;
}
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda) {
    Pregled::ime_pacijenta_pr=ime_pacijenta;
}
void PromijeniPacijenta(const std::string &ime_pacijenta) {
    Pregled::ime_pacijenta_pr=ime_pacijenta;
}
void PromijeniDatum(const Datum &novi_datum) {datum=novi_datum;}
void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {vrijeme=novo_vrijeme;}
void PomjeriDanUnaprijed(); //
void PomjeriDanUnazad(); //
std::string DajImePacijenta() const {return ime_pacijenta_pr;}
Datum DajDatumPregleda() const {return datum;}
Vrijeme DajVrijemePregleda() const {return vrijeme;}
static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if(p1.Pregled::datum.godina_pr<p2.Pregled::datum.godina_pr) return false;
    else if(p1.Pregled::datum.godina_pr>p2.Pregled::datum.godina_pr) return true;
    else {
        if(p1.Pregled::datum.mjesec_pr<p2.Pregled::datum.mjesec_pr) return false;
        else if(p1.Pregled::datum.mjesec_pr>p2.Pregled::datum.mjesec_pr) return true;
        else {
            if(p1.Pregled::datum.dan_pr<p2.Pregled::datum.dan_pr) return false;
            else if(p1.Pregled::datum.dan_pr>p2.Pregled::datum.dan_pr) return true;
            else {
                if(p1.Pregled::vrijeme.sati_pr<p2.Pregled::vrijeme.sati_pr) return false;
                else if(p1.Pregled::vrijeme.sati_pr>p2.Pregled::vrijeme.sati_pr) return true;
                else {
                    if(p1.Pregled::vrijeme.minute_pr<p2.Pregled::vrijeme.minute_pr) return false;
                }
            }
        }
    }
    return true; // samo ako je p1>=p2 u minutama(nista nije navedeno ako je sve =);
}
/*void Ispisi() const {std::cout << std::setw(30) << std::left << ime_pacijenta_pr;
    std::cout << datum.dan_pr << "/" << datum.mjesec_pr << "/" << datum.godina_pr << " ";
    std::cout << std::setw(2) << std::setfill('0') << vrijeme.sati_pr << ":" << std::setw(2) << vrijeme.minute_pr << std::endl;
}*/

void Ispisi() const {
    std::cout << std::setw(30) << std::left << ime_pacijenta_pr;
    datum.Ispisi();
    std::cout << " ";
    vrijeme.Ispisi();
    std::cout << std::endl;
}
friend class Pregledi;
};

class Pregledi {
std::vector<std::shared_ptr<Pregled>> spisak;
int pronadji(int *dan, int *mjesec, int *godina, int *sati, int *minute) const {
    for(int i=0; i<spisak.size(); i++) {
        if(std::strcmp(dan, spisak[i]->Datum.DajDane())==0) {
            if(std::strcmp(mjesec, spisak[i]->Datum::DajMjesec())==0) {
                if(std::strcmp(godina, spisak[i]->Datum::DajGodine())==0) {
                    if(std::strcmp(sati, spisak[i]->Vrijeme::DajSate())==0) {
                        if(std::strcmp(minute, spisak[i]->Vrijeme::DajMinute())==0) {
                            return i;
                        } else return -1;       
                    } else return -1;
                } else return -1;
            } else return -1;
        } else return -1;
    }
    return -1;
}
public:
explicit Pregledi()=default;
Pregledi(std::initializer_list<Pregled>spisak_pregleda) {
    for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
        try {
            std::shared_ptr<Pregled>p(new Pregled(*it));
            spisak.push_back(p);
        }catch(std::bad_alloc) {
            for(int i=0; i<spisak_pregleda.size(); i++) {
                spisak[i]=nullptr;
            }
            throw;
        }
    }
}
~Pregledi() {
    for(int i=0; i<spisak.size(); i++) spisak[i]=nullptr;
}
Pregledi(const Pregledi &pregledi) {
    try {
        spisak.resize(pregledi.spisak.size());
        for(int i=0; i<pregledi.spisak.size(); i++) {
            std::shared_ptr<Pregled>p(new Pregled(*pregledi.spisak[i]));
            spisak[i]=p;
        }
    }catch(...) {
        for(int i=0; i<pregledi.spisak.size(); i++) spisak[i]=nullptr;
        throw;
    }
}
Pregledi(Pregledi &&pregledi) {spisak=std::move(pregledi.spisak);}
Pregledi  &operator =(const Pregledi &pregledi) {
    int stara_duzina=spisak.size();
    if(pregledi.spisak.size()>spisak.size()) {
        try {
            for(int i=spisak.size(); i<pregledi.spisak.size(); i++) {
                std::shared_ptr<Pregled>p(new Pregled(*pregledi.spisak[i]));
                spisak.push_back(p);
            }
        }catch(...) {
            for(int i=spisak.size(); i<pregledi.spisak.size(); i++) {
                spisak[i]=nullptr;
            }
            spisak.resize(stara_duzina);
            throw;
        }
    }
    spisak.resize(pregledi.spisak.size());
    for(int i=0; i<spisak.size(); i++) *spisak[i]=*pregledi.spisak[i];
    return *this;
}
Pregledi &operator =(Pregledi &&pregledi) {
    spisak=std::move(pregledi.spisak);
    return *this;
}
void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(pronadji(datum_pregleda.DajDane(), datum_pregleda.DajMjesec(), datum_pregleda.DajGodine(), vrijeme_pregleda.DajSate(), vrijeme_pregleda.DajMinute())!=-1) throw std::logic_error("Termin vec popunjen");
    spisak[spisak.size()]=std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(godina_pregleda<0 || godina_pregleda>2018 || sati_pregleda<0 || sati_pregleda>23 || minute_pregleda<0 || minute_pregleda>59 || mjesec_pregleda<1 || mjesec_pregleda>12) throw std::range_error("Neuspjesna registracija");
    if((mjesec_pregleda==1 || mjesec_pregleda==3 || mjesec_pregleda==5 || mjesec_pregleda==7 || mjesec_pregleda==8 || mjesec_pregleda==10 || mjesec_pregleda==12) && dan_pregleda>31) throw std::domain_error("Neispravan datum");
    if((mjesec_pregleda==4 || mjesec_pregleda==6 || mjesec_pregleda==9 || mjesec_pregleda==11) && dan_pregleda>30) throw std::domain_error("Neispravan datum");
    if(godina_pregleda%4==0 && (godina_pregleda%100!=0 || godina_pregleda%400==0)) {
        if(mjesec_pregleda==2 && dan_pregleda>29) throw std::domain_error("Neispravan datum");
    } else {
        if(mjesec_pregleda==2 && dan_pregleda>28) throw std::domain_error("Neispravan datum");
    }
    std::shared_ptr<Pregled>p(new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    spisak.push_back(p);
}
/*void RegistrirajPregled(Pregled *pregled) {
    std::shared_ptr<Pregled>p(new Pregled(Pregledi.ime_pacijenta_pr);
    spisak.push_back(p);
}*/
int DajBrojPregleda() const {return spisak.size();}
int DajBrojPregledaNaDatum(const Datum &datum) const {
    int brojac=0;
    for(int i=0; i<spisak.size(); i++) {
        if(1) brojac++;
    }
    return brojac;
}
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const {
    for(int i=0; i<spisak.size(); i++) {
        if() datum.Datum::Ispisi(); 
    }
}
void IspisiSvePreglede() const {
    for(int i=0; i<spisak.size(); i++) spisak[i]->Ispisi();
}
};

/*explicit Pregledi(int max_broj_pregleda);//
Pregledi(std::initializer_list<Pregled> spisak_pregleda);//
~Pregledi();//
Pregledi(const Pregledi &pregledi);//
Pregledi(Pregledi &&pregledi);//
Pregledi &operator =(const Pregledi &pregledi);//
Pregledi &operator =(Pregledi &&pregledi);//
void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);//
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);//
void RegistrirajPregled(Pregled *pregled);
int DajBrojPregleda() const;
int DajBrojPregledaNaDatum(const Datum &datum) const;
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju();
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const;
void IspisiSvePreglede() const;
*/

int main() {
    return 0;
}