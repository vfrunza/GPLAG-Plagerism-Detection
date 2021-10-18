/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <vector>
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
    friend class Pregled;
    friend class Pregledi;
};
class Vrijeme{
    int sati;
    int minute;
    public:
    friend class Pregled;
    friend class Pregledi;
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
    friend class Datum;
    friend class Vrijeme;
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
        datum_pregleda(datum_pregleda.dan,datum_pregleda.mjesec,datum_pregleda.godina),
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
        Pregled::datum_pregleda=Datum(datum_pregleda.dan+1,datum_pregleda.mjesec,datum_pregleda.godina);
        
    }
    void PomjeriDanUnazad(){
        Pregled::datum_pregleda=Datum(datum_pregleda.dan-1,datum_pregleda.mjesec,datum_pregleda.godina);
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
        if(p1.datum_pregleda.godina < p2.datum_pregleda.godina) return true;
        else if(p1.datum_pregleda.godina > p2.datum_pregleda.godina) return false;
        else if(p1.datum_pregleda.godina == p2.datum_pregleda.godina){
            if(p1.datum_pregleda.mjesec < p2.datum_pregleda.mjesec) return true;
            else if(p1.datum_pregleda.mjesec > p2.datum_pregleda.mjesec) return false;
            else if(p1.datum_pregleda.mjesec == p2.datum_pregleda.mjesec){
                if(p1.datum_pregleda.dan < p2.datum_pregleda.dan) return true;
                else if(p1.datum_pregleda.dan > p2.datum_pregleda.dan) return false;
                else if(p1.datum_pregleda.dan == p2.datum_pregleda.dan){
                    if(p1.vrijeme_pregleda.sati < p2.vrijeme_pregleda.sati) return true;
                    else if(p1.vrijeme_pregleda.sati > p2.vrijeme_pregleda.sati) return false;
                    else if(p1.vrijeme_pregleda.sati == p2.vrijeme_pregleda.sati){
                        if(p1.vrijeme_pregleda.minute < p2.vrijeme_pregleda.minute) return true;
                        else if(p1.vrijeme_pregleda.minute > p2.vrijeme_pregleda.minute) return false;
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
};
class Pregledi{
    const int kapacitet;
    int broj_pacijenata;
    Pregled **pregledi;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.datum_pregleda.godina < p2.datum_pregleda.godina) return true;
        else if(p1.datum_pregleda.godina > p2.datum_pregleda.godina) return false;
        else if(p1.datum_pregleda.godina == p2.datum_pregleda.godina){
            if(p1.datum_pregleda.mjesec < p2.datum_pregleda.mjesec) return true;
            else if(p1.datum_pregleda.mjesec > p2.datum_pregleda.mjesec) return false;
            else if(p1.datum_pregleda.mjesec == p2.datum_pregleda.mjesec){
                if(p1.datum_pregleda.dan < p2.datum_pregleda.dan) return true;
                else if(p1.datum_pregleda.dan > p2.datum_pregleda.dan) return false;
                else if(p1.datum_pregleda.dan == p2.datum_pregleda.dan){
                    if(p1.vrijeme_pregleda.sati < p2.vrijeme_pregleda.sati) return true;
                    else if(p1.vrijeme_pregleda.sati > p2.vrijeme_pregleda.sati) return false;
                    else if(p1.vrijeme_pregleda.sati == p2.vrijeme_pregleda.sati){
                        if(p1.vrijeme_pregleda.minute < p2.vrijeme_pregleda.minute) return true;
                        else if(p1.vrijeme_pregleda.minute > p2.vrijeme_pregleda.minute) return false;
                    }
                }
            }
        }
        else return false;
    }
    public: 
    friend class Pregled;
    friend class Datum;
    friend class Vrijeme;
    explicit Pregledi(int max_br_pacijenata): kapacitet(max_br_pacijenata),broj_pacijenata(0){
        pregledi=new Pregled*[kapacitet]{};
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): kapacitet(spisak_pregleda.size()){
        broj_pacijenata=spisak_pregleda.size();
        pregledi=new Pregled*[kapacitet];
        int i=0;
        for(auto it(std::begin(spisak_pregleda)); it!=std::end(spisak_pregleda); it++){
            pregledi[i++]=new Pregled(*it);
        }
    }
    ~Pregledi(){
       if(pregledi!=nullptr){
           for(int i=0; i<broj_pacijenata; i++){
               delete pregledi[i];
           }
           delete[] pregledi;
       } 
    }
    Pregledi(const Pregledi &pregledi):kapacitet(pregledi.kapacitet){
        broj_pacijenata=pregledi.broj_pacijenata;
        Pregledi::pregledi=new Pregled*[kapacitet];
        auto it=pregledi.pregledi;
        for(int i=0; i<broj_pacijenata; i++){
            Pregledi::pregledi[i]=new Pregled(**it);
            it++;
        }
    }
    Pregledi(Pregledi &&p):kapacitet(p.kapacitet){
        broj_pacijenata=p.broj_pacijenata;
        Pregledi::pregledi=p.pregledi;
        p.pregledi=nullptr;
    }
    Pregledi &operator =(const Pregledi &p){
        if(p.kapacitet!=kapacitet) throw std::domain_error("Nesaglasni kapaciteti!");
        for(int i=0; i<p.broj_pacijenata; i++){
            if(i<broj_pacijenata) *(pregledi[i])=*(p.pregledi[i]);
            else pregledi[i]=new Pregled(*(p.pregledi[i]));
        }
        broj_pacijenata=p.broj_pacijenata;
        return *this; 
    }
    Pregledi &operator =(Pregledi &&p){
        if(p.kapacitet!=kapacitet) throw std::domain_error("Nesaglasni kapaciteti!");
        for(int i=0; i<broj_pacijenata; i++) delete pregledi[i];
        delete[] pregledi;
        broj_pacijenata=p.broj_pacijenata;
        pregledi=p.pregledi;
        p.pregledi=nullptr;
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(broj_pacijenata>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pacijenata]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        broj_pacijenata++;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        if(broj_pacijenata>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pacijenata]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
        broj_pacijenata++;
    }
    void RegistrirajPregled(Pregled *pregled){
        if(broj_pacijenata>=kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_pacijenata]=pregled;
        broj_pacijenata++;
    }
    int DajBrojPregleda()const{
        return Pregledi::broj_pacijenata;
    }
    int DajBrojPregledaNaDatum(const Datum &datum)const{
        int brojac(0);
        brojac=std::count_if(pregledi, pregledi+broj_pacijenata, [datum](const Pregled* pregled){
            if((*pregled).datum_pregleda.dan==datum.dan && (*pregled).datum_pregleda.mjesec==datum.mjesec && (*pregled).datum_pregleda.godina==datum.godina) return true;
            else return false;
        });
        return brojac;
    }
    Pregled &DajNajranijiPregled(){
        auto it=std::min_element(pregledi, pregledi+broj_pacijenata, [](const Pregled *pregled1,const Pregled *pregled2){
            if( DolaziPrije(*pregled1,*pregled2)==1) return true;
            else return false;
        });
        return **it;
    }
    Pregled DajNajranijiPregled()const{
        auto it=std::min_element(pregledi, pregledi+broj_pacijenata, [](const Pregled *pregled1,const Pregled *pregled2){
            if(DolaziPrije(*pregled1,*pregled2)==1) return true;
            else return false;
        });
        Pregled pom=**it;
        return pom;
    }
    void IsprazniKolekciju(){
        for(int i=0; i<broj_pacijenata; i++) delete pregledi[i], pregledi[i]=nullptr;
        broj_pacijenata=0;
    }
    void ObrisiNajranijiPregled(){
        if(broj_pacijenata==0) throw std::range_error("Prazna kolekcija");
        auto pom(DajNajranijiPregled().DajDatumPregleda());
        for(int i=0; i<broj_pacijenata; i++){
                if((*pregledi[i]).datum_pregleda.dan==pom.dan &&
                (*pregledi[i]).datum_pregleda.mjesec==pom.mjesec &&
                (*pregledi[i]).datum_pregleda.godina==pom.godina)
                delete pregledi[i], pregledi[i]=nullptr;
                
        }
        int brojac=0;
        Pregled **novi_pregledi=new Pregled*[kapacitet]{};
        for(int i=0; i<broj_pacijenata; i++){
            if(pregledi[i]!=nullptr) novi_pregledi[brojac]=new Pregled(*pregledi[i]),brojac++;
        }
        std::swap(novi_pregledi,pregledi);
        for(int i=0; i<broj_pacijenata; i++) delete novi_pregledi[i];
        delete[] novi_pregledi;
        broj_pacijenata=brojac;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        if(broj_pacijenata==0) throw std::range_error("Prazna kolekcija");
        for(int i=0; i<broj_pacijenata; i++){
            if((*pregledi[i]).DajImePacijenta()==ime_pacijenta) delete pregledi[i],pregledi[i]=nullptr;
        }
        int brojac=0;
        Pregled **novi_pregledi=new Pregled*[kapacitet]{};
        for(int i=0; i<broj_pacijenata; i++){
            if(pregledi[i]!=nullptr) novi_pregledi[brojac]=new Pregled(*pregledi[i]),brojac++;
        }
        std::swap(novi_pregledi,pregledi);
        for(int i=0; i<broj_pacijenata; i++) delete novi_pregledi[i];
        delete[] novi_pregledi;
        broj_pacijenata=brojac;
    }
    void IspisiPregledeNaDatum(const Datum &datum)const{
        for(int i=0; i<broj_pacijenata; i++){
            if((*pregledi[i]).datum_pregleda.dan==datum.dan && (*pregledi[i]).datum_pregleda.mjesec==datum.mjesec && (*pregledi[i]).datum_pregleda.godina==datum.godina)
            (*pregledi[i]).Ispisi();
        }
    }
    void IspisiSvePreglede()const{
        std::vector<Pregled> v;
        for(int i=0; i<broj_pacijenata; i++) v.push_back(*pregledi[i]);
        std::sort(v.begin(), v.end(), [](const Pregled v1,const Pregled v2){
            if(DolaziPrije(v1,v2)==1) return true;
            else return false;
        });
        for(int i=0; i<broj_pacijenata; i++){
            (v[i]).Ispisi();
        }
        /*
        std::for_each(pregledi,pregledi+broj_pacijenata,[v](Pregled *pregled){
            v.push_back(*pregled);
        });
        std::sort(pregledi, pregledi+broj_pacijenata, [](const Pregled *pregled1,const Pregled *pregled2){
            if(DolaziPrije(*pregled1,*pregled2)==1) return true;
            else return false;
        });
        for(int i=0; i<broj_pacijenata; i++){
            (*pregledi[i]).Ispisi();
        }*/
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
    Pregledi s(20);
    int max;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>max;
    std::string unos_imena;
    int brojac(0);
    while(unos_imena!="kraj" && brojac<max){
        brojac++;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
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
        s.RegistrirajPregled(unos_imena,dan,mjesec,godina,sati,minute);
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
