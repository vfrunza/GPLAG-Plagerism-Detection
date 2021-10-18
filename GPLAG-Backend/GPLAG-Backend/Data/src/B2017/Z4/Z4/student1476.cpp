/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>

class Datum{
    int dan,mjesec,godina;
    public:
    Datum (int dan, int mjesec, int godina);
    Datum(const Datum & a){
        dan=a.dan;
        mjesec=a.mjesec;
        godina=a.godina;
    }
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj() const{
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const{
        std::cout <<dan <<"/"<<mjesec<<"/"<<godina;
    }
};
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if( godina % 4== 0 && godina %  100 != 0 or godina % 400==0) broj_dana[1]++;
    if(godina<1 or mjesec<1 or dan <1 or dan >broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum!");
    Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if( godina % 4== 0 && godina %  100 != 0 or godina % 400==0) broj_dana[1]++;
    if(godina<1 or mjesec<1 or dan <1 or dan >broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
}
    

class Vrijeme{
    int sati,minute;
    public:
    Vrijeme (int sati, int minute){
        if(sati<0 or sati >23 or minute<0 or minute>59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Ispisi() const{
        std::cout << std::setw(2)<<std::setfill('0')<< std::right<<sati<<":"<< std::right<<std::setw(2)<<minute;
    }
};
class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    Pregled (const std::string &  ime_pacijenta1 , const Datum &datum_pregleda1,
    const Vrijeme& vrijeme_pregleda1) : ime_pacijenta(ime_pacijenta1), datum_pregleda(datum_pregleda1), vrijeme_pregleda(vrijeme_pregleda1) { }
    
    
    Pregled (const std::string& ime_pacijenta,int dan_pregleda, int mjesec_pregleda
    
    , int godina_pregleda, int sati_pregleda, int minute_pregleda) :datum_pregleda(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda)), vrijeme_pregleda(Vrijeme(sati_pregleda,minute_pregleda)) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    
    
    void PromijeniPacijenta(const std::string& ime_pacijenta){
        this->ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum& novi_datum){
        this->datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme& novo_vrijeme){
        this->vrijeme_pregleda=novo_vrijeme;
    }
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda () const ;
    std::string DajImePacijenta() const;
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    static bool DolaziPrije(const Pregled&p1,const Pregled&p2);
    void Ispisi() const;
};

    void Pregled::PomjeriDanUnaprijed(){
         int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
          auto x=datum_pregleda.Ocitaj();
         if( std::get<2>(x) % 4== 0 && std::get<2>(x) %  100 != 0 or std::get<2>(x) % 400==0) broj_dana[1]++;
        
        if(std::get<0>(x)==broj_dana[std::get<1>(x)-1]){
            if(std::get<1>(x)==12) datum_pregleda.Postavi(1,1,std::get<2>(x)+1);
            else datum_pregleda.Postavi(1,std::get<1>(x)+1,std::get<2>(x));
        }else{
            datum_pregleda.Postavi(std::get<0>(x)+1,std::get<1>(x),std::get<2>(x));
        }
    }
        std::string Pregled:: DajImePacijenta() const{
            return ime_pacijenta;
        }
        Datum  Pregled::DajDatumPregleda() const{
            return datum_pregleda;
        }
        Vrijeme Pregled::DajVrijemePregleda () const {
            return vrijeme_pregleda;
        }
        void Pregled::Ispisi() const{
            std::cout <<std::setw(30)<<std::left<<std::setfill(' ') << ime_pacijenta;
            datum_pregleda.Ispisi();
            std::cout<<" ";
            vrijeme_pregleda.Ispisi(); 
            std::cout<<std::endl;
        };
    
    
        static bool DolaziPrije(const Pregled& p1,const Pregled& p2){
            int d1, d2, m1,m2,g1,g2;
    
            std::tie(d1,m1,g1)=p1.DajDatumPregleda().Ocitaj();
            std::tie(d2,m2,g2)=p2.DajDatumPregleda().Ocitaj();
            if(g1<g2)
                return true;
            else if(g1==g2 and m1<m2)
                return true;
            else if( g1==g2 and m1==m2 and d1<d2)
                return true;
            return false;
        }
  


void  Pregled::PomjeriDanUnazad(){
         int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
         auto x=datum_pregleda.Ocitaj();
         if( std::get<2>(x) % 4== 0 && std::get<2>(x) %  100 != 0 or std::get<2>(x) % 400==0) broj_dana[1]++;
        if(std::get<0>(x)==1){
            if(std::get<1>(x)==1) datum_pregleda.Postavi(31,12,std::get<2>(x)-1);
            else datum_pregleda.Postavi(broj_dana[std::get<1>(x)-2],std::get<1>(x)-1,std::get<2>(x));
        }else{
            datum_pregleda.Postavi(std::get<0>(x)-1,std::get<1>(x),std::get<2>(x));
        }
    }
    
class Pregledi{
    std::vector<std::shared_ptr<Pregled>>  pok;
    int registrovani;
    public:
    explicit Pregledi() {registrovani=0;};
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
  //  ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi & operator=(const Pregledi & pregledi);
    Pregledi & operator= (Pregledi&&);
    void RegistrirajPregled(const std::string ime_pacijenta ,const Datum& datum_pregleda, const Vrijeme & vrijeme_pregleda);
    void RegistrirajPregled (const std::string& ime_pacijenta,int dan_pregleda, int mjesec_pregleda
    , int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr< Pregled> pregled);
    int DajBrojPregleda() const{
        return registrovani;
    }
    int DajBrojPregledaNaDatum(const Datum& datum) const;
    Pregled& DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IspraziKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string& ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum& datum) const;
    void IspisiSvePreglede()const;
};
    Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        
            registrovani=spisak_pregleda.size();
            pok.resize(spisak_pregleda.size());
            auto a=spisak_pregleda.begin();
            for (int i = 0; i < spisak_pregleda.size(); i++) {
                pok[i]=std::make_shared<Pregled> (*a);
                a++;
            }
        
    }
    Pregledi::Pregledi(Pregledi &&pregledi){
        pok=std::move(pregledi.pok);
        registrovani=pregledi.registrovani;
        pregledi.registrovani=0;
    }
   /* Pregledi:: ~Pregledi(){
        for (int i = 0; i < registrovani; i++) {
            delete  pok[i];
        }
        delete[] pok;
        pok=nullptr;
        registrovani=0;
        velicina=0;
    }*/
    Pregledi::Pregledi(const Pregledi& pregledi){
        std::vector<std::shared_ptr<Pregled>> p1(pregledi.registrovani) ;
            for (int i = 0; i < pregledi.registrovani; i++) {
                p1[i]= std::make_shared<Pregled>(*(pregledi.pok[i]));
            }
        pok=p1;
        registrovani=pregledi.registrovani;
    }
    Pregledi& Pregledi ::operator=(const Pregledi & pregledi){
       std::vector<std::shared_ptr<Pregled>> p1(pregledi.registrovani) ;
        if(&pregledi!=this){
      
            for (int i = 0; i < pregledi.registrovani; i++) {
                p1[i]= std::make_shared<Pregled> (*(pregledi.pok[i]));
            }
        pok=p1;
        registrovani=pregledi.registrovani;
        }
        return *this;
    }
    Pregledi& Pregledi :: operator= (Pregledi&& pregledi){
        if(&pregledi!=this){
        std::swap(pok,pregledi.pok);
        std::swap(registrovani,pregledi.registrovani);
        }
        return *this;
    }
    
    void Pregledi::RegistrirajPregled(const std::string ime_pacijenta ,const Datum& datum_pregleda, const Vrijeme & vrijeme_pregleda){
        
        pok.push_back(std::make_shared< Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        registrovani++;
    }
     void Pregledi::RegistrirajPregled(const std::string& ime_pacijenta,int dan_pregleda, int mjesec_pregleda
    , int godina_pregleda, int sati_pregleda, int minute_pregleda){
        
        pok.push_back(std::make_shared< Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
        registrovani++;
    }
    void Pregledi::RegistrirajPregled( std::shared_ptr<Pregled> p1){
        pok.push_back(p1);
        registrovani++;
    }
    int Pregledi::DajBrojPregledaNaDatum(const Datum& datum) const{
        int n;
        if(registrovani==0)
            throw std::domain_error("Nema registriranih pregleda");
        auto a= datum.Ocitaj();
        n=std::count_if(pok.begin(),pok.begin()+registrovani,[a] (std::shared_ptr< Pregled> p){ return a==p->DajDatumPregleda().Ocitaj();});
        return n;
    }
    
    Pregled&  Pregledi::DajNajranijiPregled(){
        if(registrovani==0)
            throw std::domain_error("Nema registriranih pregleda");
        auto a(std::min_element(pok.begin(),pok.begin()+registrovani,[](std::shared_ptr< Pregled> p1,std::shared_ptr< Pregled> p2){return DolaziPrije(*p1,*p2);}));
        return *(pok[a-pok.begin()]);
    }
    Pregled  Pregledi::DajNajranijiPregled() const{
        if(registrovani==0)
            throw std::domain_error("Nema registriranih pregleda");
        auto a(std::min_element(pok.begin(),pok.begin()+registrovani,[](std::shared_ptr< Pregled> p1,std::shared_ptr< Pregled> p2){return DolaziPrije(*p1,*p2);}));
        return *(pok[a-pok.begin()]);
    }
    
    void Pregledi:: ObrisiNajranijiPregled(){
        if(registrovani==0)
            throw std::domain_error("Nema registriranih pregleda");
        auto a(std::min_element(pok.begin(),pok.begin()+registrovani,[](std::shared_ptr< Pregled> p1,std::shared_ptr< Pregled> p2){return DolaziPrije(*p1,*p2);}));
        pok.erase(a);
        registrovani--;
    }
    void Pregledi::ObrisiPregledePacijenta(const std::string & ime_pacijenta){
        if(registrovani==0)
            throw std::domain_error("Nema registriranih pregleda");
        for (int i = 0; i < registrovani; i++) {
            if(pok[i]->DajImePacijenta()==ime_pacijenta){
                pok.erase(pok.begin()+i);
                registrovani --;
                i--;
            }
            
        }

        
        
    }
    void Pregledi::IspisiPregledeNaDatum(const Datum& datum) const{
        auto b=datum.Ocitaj();
        std::vector<std::shared_ptr<Pregled>> pomocni ;
        for (int i = 0; i < registrovani; i++) {
            auto a=pok[i]->DajDatumPregleda().Ocitaj();
            if(a==b){
                pomocni.push_back(pok[i]);
            }
        }
        std::stable_sort(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled>p2){
            return DolaziPrije(*p1,*p2);
        });
        for (int i = 0; i <pomocni.size() ; i++) {
                pomocni[i]->Ispisi();
        }
    }
    void Pregledi::IspisiSvePreglede() const{
       std::vector<std::shared_ptr<Pregled>> pomocni(registrovani) ;
        std::copy(pok.begin(),pok.begin()+registrovani,pomocni.begin());
        std::stable_sort(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled>p1, std::shared_ptr<Pregled>p2){
            return DolaziPrije(*p1,*p2);
        });
        for (int i = 0; i < registrovani; i++) {
            pomocni[i]->Ispisi();
        }
    }
    void Pregledi::IspraziKolekciju(){
        for (int i = 0; i < registrovani; i++) {

            pok[i]=nullptr;
        }
        registrovani=0;
    }
int main ()
{


    Pregledi pregledii;
    int uu(0);
    while (1) {
        
        std::string ime;
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin >> ime;
        if(uu==0){
        //std::getline(std::cin,ime);
        uu++;
        }
        else{
            /*std::cin.ignore(100,'\n');
            std::getline(std::cin,ime);*/
        }
        if(ime=="kraj") break;
        int dan,mjesec,godina,sati,minute;
        std::cout << "Unesite dan mjesec i godinu pregleda: " ;
        std::cin >> dan>>mjesec>>godina;
        std::cout << "Unesite sate i minute pregleda: " ;
        std::cin >> sati>>minute;
        
            pregledii.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);

     
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledii.IspisiSvePreglede();
    int opcija;

    while (1) {
        std::cout << "\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa" << std::endl;
        std::cin >> opcija;
         std::string s;
         int dan,mjesec,godina,k;
        switch(opcija){
            case 1:  std::cout << "Unesite dan mjesec i godinu : " ; std::cin >> dan>>mjesec>>godina; std::cout << "Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pregledii.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina))<<std::endl; break;
            case 2:  std::cout << "Najraniji pregled je:" << std::endl; pregledii.DajNajranijiPregled().Ispisi(); break;
            case 3: /*std::cin.ignore(100,'\n');*/ std::cout << "Unesite ime pacijenta: ";k=pregledii.DajBrojPregleda(); /*std::getline(std::cin,s);*/ std::cin >> s ;   pregledii.ObrisiPregledePacijenta(s); std::cout<< "Uspjesno obrisano "<<k-pregledii.DajBrojPregleda()<<" pregleda"<<std::endl; break;
            case 4: try{pregledii.ObrisiNajranijiPregled(); std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;} catch (std::domain_error a){ std::cout << a.what() << std::endl;} break;
            case 5: std::cout << "Unesite dan mjesec i godinu : "; std::cin >> dan>>mjesec>>godina;std::cout << "Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;  pregledii.IspisiPregledeNaDatum(Datum(dan,mjesec,godina)); break;
            case 6: pregledii.IspisiSvePreglede(); break;
            case 7: return 0;
           
            
        }
    }

	return 0;
}
