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
#include <functional>

class Datum {
int dan_pr, mjesec_pr, godina_pr;
Datum()=default;
public:
Datum(int dan, int mjesec, int godina) {
    if(dan<0 || mjesec<0 || mjesec>12 || godina<0 || godina>2018) throw std::domain_error("Neispravan datum");
    if((mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) && dan>31) throw std::domain_error("Neispravan datum");
    if((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) && dan>30) throw std::domain_error("Neispravan datum");
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) {
        if(mjesec==2 && dan>29) throw std::domain_error("Neispravan datum");
    } else {
        if(mjesec==2 && dan>28) throw std::domain_error("Neispravan datum");
    }
    Postavi(dan, mjesec, godina);
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
    dan_pr=dan;
    mjesec_pr=mjesec;
    godina_pr=godina;
}
std::tuple<int, int, int>Ocitaj() const {
    return std::make_tuple(dan_pr, mjesec_pr, godina_pr);
}
void Ispisi() const {std::cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu() << std::endl;}
int DajDan() const {return this->dan_pr;}
int DajMjesec() const {return this->mjesec_pr;}
int DajGodinu() const {return this->godina_pr;}
};

class Vrijeme {
int sati_pr, minute_pr;
public:
Vrijeme(int sati, int minute) {
    if(sati<0 || minute<0 || sati>23 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Postavi(sati, minute);
}
void Postavi(int sati, int minute) {
    if(sati<0 || minute<0 || sati>23 || minute>59) throw std::domain_error("Neispravno vrijeme");
    sati_pr=sati;
    minute_pr=minute;
}
std::pair<int, int>Ocitaj() const {
    return std::make_pair(sati_pr, minute_pr);
}
void Ispisi() const {std::cout << std::setw(2) << std::setfill('0') << sati_pr << ":" << std::setw(2) << minute_pr;}
int DajSate() const {return sati_pr;}
int DajMinute() const {return minute_pr;}
};

class Pregled {
Datum d;
Vrijeme v;
std::string ime_pacijenta;
Pregled()=default;
public:
Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : d(datum_pregleda), v(vrijeme_pregleda) {
    this->ime_pacijenta=ime_pacijenta;
}
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : d(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda) {
    this->ime_pacijenta=ime_pacijenta;
}
void PromijeniPacijenta(const std::string &ime_pacijenta) {this->ime_pacijenta=ime_pacijenta;}
void PromijeniDatum(const Datum &novi_datum) {
    int d1(novi_datum.DajDan());
    int m1(novi_datum.DajMjesec());
    int g1(novi_datum.DajGodinu());
    this->d.Postavi(d1, m1, g1);
}
void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
    int s1(novo_vrijeme.DajSate());
    int m1(novo_vrijeme.DajMinute());
    this->v.Postavi(s1, m1);
}
void PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp=d.DajDan();
    int temp1=d.DajMjesec();
    int temp2=d.DajGodinu();
    if(temp2==0 && (temp2%100!=0 || temp2%400==0)) broj_dana[1]++;
    temp++;
    if(temp>broj_dana[temp1-1]) temp=1; temp1++;
    if(temp1>12) temp1=1; temp2++;
    this->d.Postavi(temp,temp1,temp2);
}
void PomjeriDanUnazad() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp=d.DajDan();
    int temp1=d.DajMjesec();
    int temp2=d.DajGodinu();
    if(temp2==0 && (temp2%100!=0 || temp2%400==0)) broj_dana[1]++;
    temp--;
    if(temp<1) temp1--;
    if(temp1<1) temp1=12; temp=broj_dana[temp1-1]; temp2--;
    this->d.Postavi(temp,temp1,temp2);
}
std::string DajImePacijenta() const {return this->ime_pacijenta;}
Datum DajDatumPregleda() const {return this->d;}
Vrijeme DajVrijemePregleda() const {return this->v;}
static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
void Ispisi() const {
    std::cout << std::setw(30) << std::left << ime_pacijenta;
    d.Ispisi();
    std::cout << " ";
    v.Ispisi();
    std::cout << std::endl;
}
};

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if(p1.d.DajGodinu()<p2.d.DajGodinu()) return true;
    else return false;
    if(p1.d.DajMjesec()<p2.d.DajMjesec()) return true;
    else return false;
    if(p1.d.DajDan()<p2.d.DajDan()) return true;
    else return false;
    if(p1.v.DajSate()<p2.v.DajSate()) return true;
    else return false;
    if(p1.v.DajMinute()<p2.v.DajMinute()) return true;
    else return false;
    
    return false;
}

class Pregledi {
int broj_pregleda;
int silos;
Pregled **pregledi{};
Pregledi()=default;
void AlocirajNiz(int br) {
    pregledi=nullptr;
    try {
        pregledi=new Pregled*[br];
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
public:
explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0), silos(max_broj_pregleda) {AlocirajNiz(silos);}
Pregledi(std::initializer_list<Pregled> spisak_pregleda) : broj_pregleda(spisak_pregleda.size()), silos(spisak_pregleda.size()) {
    int brojac=0;
    try {
        pregledi=new Pregled*[broj_pregleda];
        for(int i=0; i<broj_pregleda; i++) pregledi[i]=nullptr;
        for(auto &i : spisak_pregleda) pregledi[brojac++]=new Pregled(i);
    }catch(...){
        IsprazniKolekciju();
        throw;
    }
}
~Pregledi() {
    for(int i=0; i<silos; i++) delete pregledi[i];
    delete[] pregledi;
}
Pregledi(const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), silos(pregledi.silos) {
    AlocirajNiz(silos);
    try {
        for(int i=0; i<broj_pregleda; i++) this->pregledi[i]=new Pregled(*pregledi.pregledi[i]);
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), silos(pregledi.silos) {
    this->pregledi=pregledi.pregledi;
    pregledi.pregledi=nullptr;
}
Pregledi &operator =(const Pregledi &pregledi) {
    if(silos!=pregledi.silos) throw std::logic_error("Nesaglasne liste pregleda");
    if(&pregledi==this) return *this;
    
    try {
        for(int i=0; i<silos; i++) this->pregledi[i]=new Pregled(*pregledi.pregledi[i]);
    }catch(...) {
        IsprazniKolekciju();
        throw;
    }
}
Pregledi &operator =(Pregledi &&pregledi) {
    if(silos!=pregledi.silos) throw std::logic_error("Nesaglasne liste pregleda");
    if(&pregledi==this) return *this;
    
    this->pregledi=pregledi.pregledi;
    broj_pregleda=pregledi.broj_pregleda;
    pregledi.pregledi=nullptr;
}
void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(broj_pregleda==silos) throw std::range_error("“Dostignut maksimalni broj pregleda");
    try {
        pregledi[broj_pregleda++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }catch(std::bad_alloc) {
        broj_pregleda--;
        throw std::logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(broj_pregleda==silos) throw std::range_error("“Dostignut maksimalni broj pregleda");
    try {
        pregledi[broj_pregleda++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }catch(std::bad_alloc) {
        broj_pregleda--;
        throw std::logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
void RegistrirajPregled(Pregled *pregled) {
     if(broj_pregleda==silos) throw std::range_error("“Dostignut maksimalni broj pregleda");
     try {
         pregledi[broj_pregleda++]=pregled;
     }catch(std::bad_alloc) {
        broj_pregleda--;
        throw std::logic_error("Nema dovoljno memorije!");
    }catch(...) {
        broj_pregleda--;
        throw;
    }
}
int DajBrojPregleda() const {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return broj_pregleda;
}
int DajBrojPregledaNaDatum(const Datum &datum) const {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return std::count_if(pregledi, pregledi+broj_pregleda, [&](Pregled *pregled) {
        return (pregled->DajDatumPregleda().DajDan()==datum.DajDan() && pregled->DajDatumPregleda().DajMjesec()==datum.DajMjesec() && pregled->DajDatumPregleda().DajGodinu()==datum.DajGodinu());
    });
}
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju() {
    if(pregledi==nullptr) return;
    for(int i=0; i<broj_pregleda; i++) delete pregledi[i];
    delete[] pregledi;
}
void ObrisiNajranijiPregled() {
    if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    Pregled pregled=Pregledi::DajNajranijiPregled();
    Pregledi temp_pregledi = Pregledi(silos);
    int brojac=0;
    for (int i=0; i<broj_pregleda; i++) {
        auto a=pregledi[i];
        if (a->DajImePacijenta()==pregled.DajImePacijenta() && a->DajDatumPregleda().DajDan()==pregled.DajDatumPregleda().DajDan() && a->DajDatumPregleda().DajMjesec()==pregled.DajDatumPregleda().DajMjesec() && a->DajDatumPregleda().DajGodinu()==pregled.DajDatumPregleda().DajGodinu() && a->DajVrijemePregleda().DajSate()==pregled.DajVrijemePregleda().DajSate() && pregled.DajVrijemePregleda().DajMinute() == pregled.DajVrijemePregleda().DajMinute()) continue;
        temp_pregledi.pregledi[brojac++] = pregledi[i];
    }
    std::copy(temp_pregledi.pregledi, temp_pregledi.pregledi+silos, pregledi);
    broj_pregleda--;
}
void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    if(broj_pregleda==0) std::range_error("Prazna kolekcija");
    Pregledi temp=Pregledi(silos);
    int brojac=0;
    for(int i=0; i<broj_pregleda; i++) {
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta) continue;
        temp.pregledi[brojac++]=pregledi[i];
    }
    broj_pregleda=brojac;
    std::copy(temp.pregledi, temp.pregledi+silos, pregledi);
}
void IspisiPregledeNaDatum(const Datum &datum) const {
    bool ima_pregleda(false);
    for(int i = 0; i < broj_pregleda; i++) {
        if(pregledi[i]->DajDatumPregleda().DajDan() == datum.DajDan() && pregledi[i]->DajDatumPregleda().DajMjesec() == datum.DajMjesec() && pregledi[i]->DajDatumPregleda().DajGodinu() == datum.DajGodinu()) {
            (*pregledi[i]).Ispisi();
            std::cout << std::endl;
            ima_pregleda = true;
        }
    }
    if(!ima_pregleda) throw std::domain_error("Nema pregleda na traženi dan!\n"); 
}
void IspisiSvePreglede() const {
    bool ima_pregleda(false);
    for(int i = 0; i < broj_pregleda; i++) {
        (*pregledi[i]).Ispisi();
        std::cout << std::endl;
        ima_pregleda = true;
    }
    if(!ima_pregleda) throw "Nema pregleda!\n"; 
}

};

Pregled &Pregledi::DajNajranijiPregled() {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled *najraniji(pregledi[0]);
    for(int i = 1; i < broj_pregleda; i++) {
        if(Pregled::DolaziPrije(*pregledi[i], *najraniji)) najraniji = pregledi[i];
    }
    return *najraniji;
}
Pregled Pregledi::DajNajranijiPregled() const {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled *najraniji(pregledi[0]);
    for(int i = 1; i < broj_pregleda; i++) {
        if(Pregled::DolaziPrije(*pregledi[i], *najraniji)) najraniji = pregledi[i];
    }
    return *najraniji;
}

int main () {
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max_broj;
    std::cin >> max_broj;
    int d,m,g;
    int h,m1;
    std::vector<std::shared_ptr<Pregled>>pregledi;
    pregledi.resize(max_broj);
    try {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        while(1) {
            int a=0;
            std::string ime;
            std::getline(std::cin, ime);
            int test=0;
            for(int i=0; i<ime.length(); i++) {
                if(ime.length()!=4) break;  
                if(ime[0]=='k') 
                    if(ime[1]=='r')
                        if(ime[2]=='a')
                            if(ime[3]=='j')
                                test=1; break;
            }
            if(test) break;
            else {
                std::cout << "Unesite dan mjesec i godinu pregleda: ";
                std::cin >> d >> m >> g;
                std::cout << "Unesite sate i minute: ";
                std::cin >> h >> m1;
                try {
                    pregledi[a++]=new Pregled(ime, Datum(d,m,g), Vrijeme(h,m1));
                }catch(...) {
                    std::cout << "Nedovoljno memorije!";
                    a--;
                }
            }
        }
        std::cout << "Unesite jednu od sljedecih opcija " << std::endl;
        std::cout << "1 - Broj pregleda na datum " << std::endl;
        std::cout << "2 - Najraniji pregled " << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta " << std::endl;
        std::cout << "4 - Obrisi najraniji pregled " << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum " << std::endl;
        std::cout << "6 - Ispisi sve preglede " << std::endl;
        std::cout << "7 - Kraj programa " << std::endl;
        for(;;) {   
            Datum datum1();
            int opcija, broj;
            std::cin >> opcija;
            switch(opcija) {
                case 1:
                    std::cout << "Unesite dan mjesec i godinu : ";
                    int a1, b1, c1;
                    std::cin >> a1 >> b1 >> c1;
                    datum1.Postavi(a1, b1, c1);
                    broj=pregled1.DajBrojPregledaNaDatum(datum1);
                    std::cout << "Broj pregleda na datum " << a1 << " " << b1 << " " << c1 << " je: " << broj << std::endl;
                    break;
                        
                case 2:
                    std::cout << std::endl;
                    break;
                
                case 3: 
                    std::cout << std::endl;
                    break;
                
                case 4:
                    std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
                    break;
                        
                case 5:
                    int a3, b3, c3; 

                    std::cout << std::endl;
                    break;
                
                case 6:
                    std::cout << std::endl;
                    break;
                
                case 7:
                    return 0;
                default:
                    break;
            }catch(std::domain_error jedan) {
                std::cout << jedan.what() << std::endl;
            }catch(std::range_error dva) {
                std::cout << dva.what() << std::endl;
            }catch(std::logic_error tri) {
                std::cout << tri.what() << std::endl;
            }catch(std::bad_alloc) {
                std::cout << "Nedovoljno memorije!" << std::endl;
                return 0;
            } 
        }
    }
	return 0;
}    
