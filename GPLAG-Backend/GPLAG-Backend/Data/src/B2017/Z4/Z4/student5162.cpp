/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <initializer_list>
#include <string>
#include <new>
#include <vector>
#include <memory>
#include <utility>

class Datum{
    int dan,mjesec,godina;
    void Testiraj_datum(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1||dan<1 ||mjesec<1 ||mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum!");
    }
public:
    Datum(int dan, int mjesec, int godina){
        Testiraj_datum(dan,mjesec,godina);
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        Testiraj_datum(dan,mjesec,godina);
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    std::tuple<int,int,int> Ocitaj() const{ return std::make_tuple(dan,mjesec,godina);}
    void Ispisi() const{ std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
class Vrijeme{
    int sati,minute;
    void Testiraj_vrijeme(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme!");
    }
public:
    Vrijeme(int sati,int minute){
        Testiraj_vrijeme(sati,minute);
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Postavi(int sati,int minute){
        Testiraj_vrijeme(sati,minute);
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    std::pair<int,int> Ocitaj() const{return std::make_pair(sati,minute);}
    void Ispisi() const{ if(sati/10==0) std::cout<<"0"<<sati<<":"; else std::cout<<sati<<":"; if(minute/10==0) std::cout<<"0"<<minute<<std::endl; else std::cout<<minute;}
};
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta),
    datum_pregleda(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda)), vrijeme_pregleda(Vrijeme(sati_pregleda,minute_pregleda)){}
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        Pregled::datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        Pregled::vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const{return ime_pacijenta;}
    Datum DajDatumPregleda() const{return datum_pregleda;}
    Vrijeme DajVrijemePregleda() const{return vrijeme_pregleda;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;

};
void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    std::tuple<int,int,int> pomocni(datum_pregleda.Ocitaj());
    if((std::get<2>(pomocni)%4==0 && std::get<2>(pomocni)%100!=0) || std::get<2>(pomocni)%400==0) broj_dana[1]++;
    std::get<0>(pomocni)++;
    if(std::get<0>(pomocni)>broj_dana[std::get<1>(pomocni)-1]){
        std::get<0>(pomocni)=1;
        std::get<1>(pomocni)++;
        if(std::get<1>(pomocni)>12){
            std::get<1>(pomocni)=1;
            std::get<2>(pomocni)++;
        }
    }
    PromijeniDatum(Datum(std::get<0>(pomocni),std::get<1>(pomocni), std::get<2>(pomocni)));
}
void Pregled::PomjeriDanUnazad(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    std::tuple<int,int,int> pomocni(datum_pregleda.Ocitaj());
    if((std::get<2>(pomocni)%4==0 && std::get<2>(pomocni)%100!=0) || std::get<2>(pomocni)%400==0) broj_dana[1]++;
    std::get<0>(pomocni)--;
    if(std::get<0>(pomocni)<1){
        std::get<1>(pomocni)--;
        if(std::get<1>(pomocni)<1){
            std::get<1>(pomocni)=12;
            std::get<2>(pomocni)--;
        }
        std::get<0>(pomocni)=broj_dana[std::get<1>(pomocni)-1];
    }
    PromijeniDatum(Datum(std::get<0>(pomocni),std::get<1>(pomocni), std::get<2>(pomocni)));
}
bool Pregled::DolaziPrije(const Pregled &p1,const Pregled &p2){
    std::tuple<int,int,int> prvi(p1.datum_pregleda.Ocitaj()), drugi(p2.datum_pregleda.Ocitaj());
    std::pair<int,int> prvo(p1.vrijeme_pregleda.Ocitaj()), drugo(p2.vrijeme_pregleda.Ocitaj());
    if(std::get<2>(prvi)>std::get<2>(drugi)) return false;
    else if(std::get<2>(prvi)==std::get<2>(drugi)){
        if(std::get<1>(prvi)>std::get<1>(drugi)) return false;
        else if(std::get<1>(prvi)==std::get<1>(drugi)){
            if(std::get<0>(prvi)>std::get<0>(drugi)) return false;
            else if(std::get<0>(prvi)==std::get<0>(drugi)){
                if(prvo.first>drugo.first) return false;
                else if(prvo.first==drugo.first){
                    if(prvo.second>drugo.second) return false;
                    else return true;
                }
            }
        }
    }
    return true;
}
void Pregled::Ispisi() const{
    std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<"\n";
}
class Pregledi{
    std::vector<std::shared_ptr<Pregled>> izvrseni_pregledi;
public:
    explicit Pregledi() {};
    Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        izvrseni_pregledi.resize(spisak_pregleda.size());
        int i(0);
        for(auto it(spisak_pregleda.begin()); it!=spisak_pregleda.end(); it++){
            izvrseni_pregledi.at(i)=std::make_shared<Pregled>(*it);
            i++;
        }
    }
    Pregledi(const Pregledi &pregledi){
        izvrseni_pregledi.resize(pregledi.izvrseni_pregledi.size()); 
        for(int i(0); i<pregledi.izvrseni_pregledi.size(); i++) 
        izvrseni_pregledi.at(i)=std::make_shared<Pregled>(*pregledi.izvrseni_pregledi[i]);
    }
    Pregledi(Pregledi &&pregledi){
        std::swap(izvrseni_pregledi,pregledi.izvrseni_pregledi);
        pregledi.izvrseni_pregledi.resize(0);
    }
    ~Pregledi() {}
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const{return izvrseni_pregledi.size();}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};
Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(&pregledi!=this){
          if(izvrseni_pregledi.size()<pregledi.izvrseni_pregledi.size()){
             for(int i(izvrseni_pregledi.size()); i<pregledi.izvrseni_pregledi.size(); i++)
                izvrseni_pregledi[i]=std::make_shared<Pregled>(Pregled(*pregledi.izvrseni_pregledi[i]));
             izvrseni_pregledi.resize(pregledi.izvrseni_pregledi.size());
            for(int i(0); i<izvrseni_pregledi.size(); i++)
                izvrseni_pregledi[i]=pregledi.izvrseni_pregledi[i];
            }
            else{
            izvrseni_pregledi.resize(pregledi.izvrseni_pregledi.size());
            for(int i(0); i<izvrseni_pregledi.size(); i++)
                 izvrseni_pregledi[i]=pregledi.izvrseni_pregledi[i];
            }
    }
    return *this;
}
Pregledi &Pregledi::operator=(Pregledi &&pregledi){
    std::swap(izvrseni_pregledi,pregledi.izvrseni_pregledi);
    pregledi.izvrseni_pregledi.resize(0);
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    izvrseni_pregledi.push_back(std::shared_ptr<Pregled>(std::make_shared<Pregled>(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda))));
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {

    izvrseni_pregledi.push_back(std::shared_ptr<Pregled>(std::make_shared<Pregled>(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda))));
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled){
    izvrseni_pregledi.push_back(std::shared_ptr<Pregled>(std::make_shared<Pregled>(Pregled(*pregled))));
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int konacni(0);
    konacni=std::count_if(izvrseni_pregledi.begin(), izvrseni_pregledi.end(), [datum] (std::shared_ptr<Pregled> pregledi) {return pregledi->DajDatumPregleda().Ocitaj()==datum.Ocitaj();});
    return konacni;
}
Pregled &Pregledi::DajNajranijiPregled(){
    auto it(std::min_element(izvrseni_pregledi.begin(), izvrseni_pregledi.end(), [] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {return Pregled::DolaziPrije(*p1,*p2);}));
    if(it==izvrseni_pregledi.end()) throw std::domain_error("Nema registriranih pregleda");
    return **it;
}
Pregled Pregledi::DajNajranijiPregled() const{
    auto it(std::min_element(izvrseni_pregledi.begin(), izvrseni_pregledi.end(), [] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {return Pregled::DolaziPrije(*p1,*p2);}));
    if(it==izvrseni_pregledi.end()) throw std::domain_error("Nema registriranih pregleda");
    return **it;
}
void Pregledi::IsprazniKolekciju(){
    izvrseni_pregledi.erase(izvrseni_pregledi.begin(), izvrseni_pregledi.end());
}
void Pregledi::ObrisiNajranijiPregled(){
    if(izvrseni_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    auto it(std::min_element(izvrseni_pregledi.begin(), izvrseni_pregledi.end(), [] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1,*p2);}));
    if(it==izvrseni_pregledi.end()) throw std::domain_error("Nema registriranih pregleda");
    izvrseni_pregledi.erase(it);
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i(0); i<izvrseni_pregledi.size(); i++){
        if(ime_pacijenta==izvrseni_pregledi[i]->DajImePacijenta()){
            izvrseni_pregledi.erase(izvrseni_pregledi.begin()+i);
            i--;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::vector<std::shared_ptr<Pregled>> vektor;
    for(int i(0); i<izvrseni_pregledi.size(); i++){
        if(izvrseni_pregledi[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) vektor.push_back(izvrseni_pregledi[i]);
    }
    std::sort(vektor.begin(),vektor.end(), [](std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {return p1->DajVrijemePregleda().Ocitaj()>p2->DajVrijemePregleda().Ocitaj();});
    for(auto it(vektor.begin()); it!=vektor.end(); it++)
        (*it)->Ispisi();
}
void Pregledi::IspisiSvePreglede() const{
    Pregledi novi_pregledi(*this);
    if(novi_pregledi.izvrseni_pregledi.size()==1) izvrseni_pregledi[0]->Ispisi();
    else{
    std::sort(novi_pregledi.izvrseni_pregledi.begin(),novi_pregledi.izvrseni_pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {return Pregled::DolaziPrije(*p1,*p2);});
    for(int i(0); i<novi_pregledi.izvrseni_pregledi.size(); i++){
        novi_pregledi.izvrseni_pregledi[i]->Ispisi();
    }
    }
}
int main ()
{
    Pregledi svi_pregledi;
    int i(0);
    for(;;){
        std::string s;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        if(i==0){
        std::getline(std::cin, s);
        i++;
        }else{
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, s);
        }
        if(s=="kraj") break;
        int dan,mjesec,godina;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mjesec>>godina;
        int sati,minute;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        try{
        svi_pregledi.RegistrirajPregled(s,dan,mjesec,godina,sati,minute);
        }catch(std::domain_error domena){
            std::cout<<domena.what()<<std::endl;
        }
    }
    int opcija;
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    svi_pregledi.IspisiSvePreglede();
    do{
    std::cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
    std::cin>>opcija;
    if(opcija==1){
        int d,m,g;
        std::cout<<"Unesite dan mjesec i godinu : ";
        std::cin>>d>>m>>g;
        std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<svi_pregledi.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
    }
    else if(opcija==2){
        std::cout<<"Najraniji pregled je:\n";
        svi_pregledi.IspisiPregledeNaDatum(svi_pregledi.DajNajranijiPregled().DajDatumPregleda());
        std::cout<<std::endl;
    }
    else if(opcija==3){
        int broj_pregleda(svi_pregledi.DajBrojPregleda());
        std::string s;
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite ime pacijenta: ";
        std::getline(std::cin,s);
        svi_pregledi.ObrisiPregledePacijenta(s);
        std::cout<<"Uspjesno obrisano "<<broj_pregleda-svi_pregledi.DajBrojPregleda()<<" pregleda"<<std::endl;
    }
    else if(opcija==4){
        try{
        svi_pregledi.ObrisiNajranijiPregled();
        }catch(std::range_error rang){
            std::cout<<rang.what()<<std::endl;
        }catch(std::domain_error domena){
            std::cout<<domena.what()<<std::endl;
        }
        std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
    }
    else if(opcija==5){
        int d,m,g;
        std::cout<<"Unesite dan mjesec i godinu : ";
        std::cin>>d>>m>>g;
        std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: \n";
        svi_pregledi.IspisiPregledeNaDatum(Datum(d,m,g));
        std::cout<<std::endl;
    }
    else if(opcija==6){
        svi_pregledi.IspisiSvePreglede();
        std::cout<<std::endl;
    }
    }while(opcija!=7);
	return 0;
}
