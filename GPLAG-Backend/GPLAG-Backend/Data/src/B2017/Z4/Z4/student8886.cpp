/B2017/2018: Zadaća 4, Zadatak 4
//ATT 22 i 23 //Potrebna funkcija PromijeniPacijenta
//ATT 24 //Potrebno da funkcija DajNajranijiPregled baca izuzetak
//ATT(15,16,17,19,20,21,25,26,27,28,31)//Pregledi(){} //Ispravka Br. 1
//ATT 9 11 12 // Potrebno poraviti {31,7,2018} da predje na 1.8.2018
//ATT 30 i 32
//ATT 18 potrebno u fun. za Registruj da prima nesto sto je shared_ptr ne *
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <vector>
#include <memory>
class Datum{
    int dan;
    int mjesec;
    int godina;
    public:
    Datum(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int,int,int> Ocitaj()const{
        return std::make_tuple(Datum::dan,Datum::mjesec,Datum::godina);
    }
    void Ispisi()const{
        std::cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
    }
    int DajDan()const{
        return Datum::dan;
    }
    int DajMjesec()const{
        return Datum::mjesec;
    }
    int DajGodinu()const{
        return Datum::godina;
    }
};
class Vrijeme{
    int sati;
    int minute;
    public:
    static bool DaLiJeIspravno(int sati, int minute){
        if(sati<=23 && sati>=0 && minute<=59 && minute>=0) return true;
        else return false;
    }
    Vrijeme(int sati, int minute){
        if(DaLiJeIspravno(sati,minute)==false) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute){
        if(DaLiJeIspravno(sati,minute)==false) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int,int> Ocitaj()const{
        return std::make_pair(Vrijeme::sati,Vrijeme::minute);
    }
    void Ispisi()const{
       		std::cout<<std::setw(2)<<std::setfill('0')<<std::right<<Vrijeme::sati<<":"<<std::setw(2)<<std::setfill('0')<<std::right<<Vrijeme::minute;
    }
    int DajSate()const{
        return Vrijeme::sati;
    }
    int DajMinute()const{
        return Vrijeme::minute;
    }
};
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    friend class Pregledi;
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        datum_pregleda(datum_pregleda.DajDan(),datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu()),
        vrijeme_pregleda(vrijeme_pregleda.DajSate(),vrijeme_pregleda.DajMinute()){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
        datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
        vrijeme_pregleda(sati_pregleda,minute_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenata(const std::string &ime_pacijenta){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        Pregled::datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        Pregled::vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed(){
        Pregled::datum_pregleda=Datum(datum_pregleda.DajDan()+1,datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu());
        
    }
    void PomjeriDanUnazad(){
        Pregled::datum_pregleda=Datum(datum_pregleda.DajDan()-1,datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu());
    }
    std::string DajImePacijenta()const{
        return Pregled::ime_pacijenta;
    }
    Datum DajDatumPregleda()const{
        return Pregled::datum_pregleda;
    }
    Vrijeme DajVrijemePregleda()const{
        return Pregled::vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.datum_pregleda.DajGodinu() < p2.datum_pregleda.DajGodinu()) return true;
        else if(p1.datum_pregleda.DajGodinu() > p2.datum_pregleda.DajGodinu()) return false;
        else if(p1.datum_pregleda.DajGodinu() == p2.datum_pregleda.DajGodinu()){
            if(p1.datum_pregleda.DajMjesec() < p2.datum_pregleda.DajMjesec()) return true;
            else if(p1.datum_pregleda.DajMjesec() > p2.datum_pregleda.DajMjesec()) return false;
            else if(p1.datum_pregleda.DajMjesec() == p2.datum_pregleda.DajMjesec()){
                if(p1.datum_pregleda.DajDan() < p2.datum_pregleda.DajDan()) return true;
                else if(p1.datum_pregleda.DajDan() > p2.datum_pregleda.DajDan()) return false;
                else if(p1.datum_pregleda.DajDan() == p2.datum_pregleda.DajDan()){
                    if(p1.vrijeme_pregleda.DajSate() < p2.vrijeme_pregleda.DajSate()) return true;
                    else if(p1.vrijeme_pregleda.DajSate() > p2.vrijeme_pregleda.DajSate()) return false;
                    else if(p1.vrijeme_pregleda.DajSate() == p2.vrijeme_pregleda.DajSate()){
                        if(p1.vrijeme_pregleda.DajMinute() < p2.vrijeme_pregleda.DajMinute()) return true;
                        else if(p1.vrijeme_pregleda.DajMinute() > p2.vrijeme_pregleda.DajMinute()) return false;
                    }
                }
            }
        }
    }
    void Ispisi()const{ //skontati zasto ne radis DajDatumPregleda().DajDan()
        std::cout<<std::setw(30)<<std::setfill(' ')<<std::left<<DajImePacijenta();
        datum_pregleda.Ispisi(); 
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
};

bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.datum_pregleda.DajGodinu() < p2.datum_pregleda.DajGodinu()) return true;
        else if(p1.datum_pregleda.DajGodinu() > p2.datum_pregleda.DajGodinu()) return false;
        else if(p1.datum_pregleda.DajGodinu() == p2.datum_pregleda.DajGodinu()){
            if(p1.datum_pregleda.DajMjesec() < p2.datum_pregleda.DajMjesec()) return true;
            else if(p1.datum_pregleda.DajMjesec() > p2.datum_pregleda.DajMjesec()) return false;
            else if(p1.datum_pregleda.DajMjesec() == p2.datum_pregleda.DajMjesec()){
                if(p1.datum_pregleda.DajDan() < p2.datum_pregleda.DajDan()) return true;
                else if(p1.datum_pregleda.DajDan() > p2.datum_pregleda.DajDan()) return false;
                else if(p1.datum_pregleda.DajDan() == p2.datum_pregleda.DajDan()){
                    if(p1.vrijeme_pregleda.DajSate() < p2.vrijeme_pregleda.DajSate()) return true;
                    else if(p1.vrijeme_pregleda.DajSate() > p2.vrijeme_pregleda.DajSate()) return false;
                    else if(p1.vrijeme_pregleda.DajSate() == p2.vrijeme_pregleda.DajSate()){
                        if(p1.vrijeme_pregleda.DajMinute() < p2.vrijeme_pregleda.DajMinute()) return true;
                        else if(p1.vrijeme_pregleda.DajMinute() > p2.vrijeme_pregleda.DajMinute()) return false;
                    }
                }
            }
        }
        return false;
    }
class Pregledi{
    int broj_pacijenata;
    std::vector<std::shared_ptr<Pregled>> pregledi;
    public: 
    friend class Pregled;
    Pregledi(){} //Ispravka Br. 1
    Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        auto it=spisak_pregleda.begin();
        for(auto i=0; i<spisak_pregleda.size(); i++){
            pregledi.push_back(std::make_shared<Pregled>(Pregled(it->DajImePacijenta(),it->DajDatumPregleda(),it->DajVrijemePregleda())));
            it++;
        }
    }
    Pregledi(const Pregledi &p){
        for(int i=0; i<p.pregledi.size(); i++){
            pregledi.push_back(std::make_shared<Pregled>(*p.pregledi[i]));
        }
    }
    Pregledi(Pregledi &&p){
        std::swap(p.pregledi,pregledi);
    }
    Pregledi &operator =(const Pregledi &p){
        pregledi.resize(p.pregledi.size());
        for(int i=0; i<p.pregledi.size(); i++){
            pregledi.push_back(std::make_shared<Pregled>(*p.pregledi[i]));
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&p){
        pregledi=std::move(p.pregledi);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        Pregled pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        pregledi.push_back(std::make_shared<Pregled>(pregled));
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        Pregled pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
        pregledi.push_back(std::make_shared<Pregled>(pregled));
    }
    void RegistrirajPregled(Pregled *pregled){
        pregledi.push_back(std::shared_ptr<Pregled>(pregled));
    }
    int DajBrojPregleda()const{
        return Pregledi::pregledi.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum)const{
        int brojac(0);
        brojac=std::count_if(pregledi.begin(), pregledi.end(), [datum](const std::shared_ptr<Pregled> pregled){
            if((*pregled).datum_pregleda.DajDan()==datum.DajDan() && (*pregled).datum_pregleda.DajMjesec()==datum.DajMjesec() && (*pregled).datum_pregleda.DajGodinu()==datum.DajGodinu()) return true;
            else return false;
        });
        return brojac;
    }
    Pregled &DajNajranijiPregled(){
        auto it=std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> pregled1,const std::shared_ptr<Pregled> pregled2){
            if(DolaziPrije(*pregled1,*pregled2)==1) return true;
            else return false;
        });
        return **it;
    }
    Pregled DajNajranijiPregled()const{
        auto it=std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> pregled1,const std::shared_ptr<Pregled> pregled2){
            if(DolaziPrije(*pregled1,*pregled2)==1) return true;
            else return false;
        });
        Pregled pom=**it;
        return pom; 
    }
    void IsprazniKolekciju(){
        for(int i=0; i<pregledi.size(); i++){
            pregledi.erase(pregledi.begin()+i);
        }
        pregledi.resize(0);
    }
    void ObrisiNajranijiPregled(){
        if(pregledi.size()==0) throw std::range_error("Prazna kolekcija");
        auto pom(DajNajranijiPregled().DajDatumPregleda());
        for(int i=0; i<pregledi.size(); i++){
                if((*pregledi[i]).datum_pregleda.DajDan()==pom.DajDan() &&
                (*pregledi[i]).datum_pregleda.DajMjesec()==pom.DajMjesec() &&
                (*pregledi[i]).datum_pregleda.DajGodinu()==pom.DajGodinu())
                pregledi.erase(pregledi.begin()+i),i--;
                
        }
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        if(pregledi.size()==0) throw std::range_error("Prazna kolekcija");
        for(int i=0; i<pregledi.size(); i++){
            if((*pregledi[i]).ime_pacijenta==ime_pacijenta) pregledi.erase(pregledi.begin()+i),i--;
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum)const{
        for(int i=0; i<pregledi.size(); i++){
            if((*pregledi[i]).datum_pregleda.DajDan()==datum.DajDan() && (*pregledi[i]).datum_pregleda.DajMjesec()==datum.DajMjesec() && (*pregledi[i]).datum_pregleda.DajGodinu()==datum.DajGodinu())
            (*pregledi[i]).Ispisi();
        }
    }
    void IspisiSvePreglede()const{
        std::vector<std::shared_ptr<Pregled>> novi_pregledi;
        novi_pregledi=std::move(pregledi);
        std::sort(std::begin(novi_pregledi),std::end(novi_pregledi),[](std::shared_ptr<Pregled> k1,std::shared_ptr<Pregled> k2){
            if(DolaziPrije(*k1,*k2)==1) return true;
            else return false;
        });
        for(int i=0; i<novi_pregledi.size(); i++){
            (*novi_pregledi[i]).Ispisi();
        }
    }
};
void Opcije(){
    std::cout<<std::endl;
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
    std::cout<<"1 - Broj pregleda na datum"<<std::endl;
    std::cout<<"2 - Najraniji pregled"<<std::endl;
    std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
    std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
    std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
    std::cout<<"6 - Ispisi sve preglede"<<std::endl;
    std::cout<<"7 - Kraj programa"<<std::endl;
}
int main ()
{
    try{
    std::vector<std::shared_ptr<Pregled>> v;
    Pregledi s{};
    std::string unos_imena;
    while(unos_imena!="kraj"){
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin, unos_imena);
        if(unos_imena=="kraj")break;
        int dan,mjesec,godina;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mjesec>>godina;
        Datum dat(dan,mjesec,godina);
        int sati,minute;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        Vrijeme vreme(sati,minute);
        s.RegistrirajPregled(new Pregled(unos_imena,dat,vreme));
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi";
    std::cout<<std::endl;
    s.IspisiSvePreglede();
    std::cout<<std::endl;
    for(;;){
        Opcije();
        int izbor_opcije;
        std::cin>>izbor_opcije;
        if(izbor_opcije==1){
            int dan,mjesec,godina;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>dan>>mjesec>>godina;
            Datum unos_datum(dan,mjesec,godina);
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<s.DajBrojPregledaNaDatum(unos_datum);
            std::cout<<std::endl;
        }
        
        else if(izbor_opcije==2){
            std::cout<<"Najraniji pregled je: ";
            std::cout<<std::endl;
            s.DajNajranijiPregled().Ispisi();
            std::cout<<std::endl;
        }
        else if(izbor_opcije==3){
            int broj=s.DajBrojPregleda();
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite ime pacijenta: ";
            std::string ime;
            std::getline(std::cin, ime);
            try{
            s.ObrisiPregledePacijenta(ime);
            std::cout<<"Uspjesno obrisano "<<broj-s.DajBrojPregleda()<<" pregleda";
            std::cout<<std::endl;
            }catch(std::range_error Izuzetak){
                std::cout<<Izuzetak.what()<<std::endl;
            }
        }
        else if(izbor_opcije==4){
            try{
            s.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan";
            std::cout<<std::endl;
            }catch(std::range_error Izuzetak){
                std::cout<<Izuzetak.what()<<std::endl;
            }
        }
        else if(izbor_opcije==5){
            int dan, mjesec, godina;
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>dan>>mjesec>>godina;
            Datum unos_datum(dan,mjesec,godina);
            std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:";
            std::cout<<std::endl;
            s.IspisiPregledeNaDatum(unos_datum);
            std::cout<<std::endl;
        }
        else if(izbor_opcije==6){
            s.IspisiSvePreglede();
            std::cout<<std::endl;
        }
        else if(izbor_opcije==7){
            return 0;
        }
    }
    }catch(std::domain_error Izuzetak){
        std::cout<<Izuzetak.what()<<std::endl;
    }catch(std::range_error Izuzetak){
        std::cout<<Izuzetak.what()<<std::endl;
    }
	return 0;
}

