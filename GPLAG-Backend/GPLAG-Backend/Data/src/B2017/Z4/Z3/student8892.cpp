#include <iostream>
#include <tuple>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
    
    public:
    
    Datum (int dan, int mjesec, int godina){
        int broj_dana [12]{ 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)broj_dana[1]++;
        if(godina <1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])throw std::domain_error("Neispravan datum");
        this -> dan = dan; this -> mjesec = mjesec; this -> godina = godina;
    }
    void Postavi (int dan, int mjesec, int godina){
        int broj_dana [12]{ 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)broj_dana[1]++;
        if(godina <1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])throw std::domain_error("Neispravan datum");
        this -> dan = dan; this -> mjesec = mjesec; this -> godina = godina;
        this -> dan = dan; this -> mjesec = mjesec; this -> godina = godina;
    }
    std::tuple<int, int, int> Ocitaj () const{
        std::tuple <int, int, int> datum;
        datum = std::make_tuple (dan, mjesec, godina);
        return datum;
    }
    void Ispisi()const {
        std::cout << this -> dan << "/" << this -> mjesec << "/" << this -> godina;
    }
};

class Vrijeme {
    private:
    int sati, minute;
    
    public:
    Vrijeme (int sati, int minute){
        if(sati < 0 || sati > 23 || minute < 0 || minute > 59)throw std::domain_error("Neispravno vrijeme");
        this -> sati = sati; this -> minute = minute;
    }
    void Postavi(int sati, int minute){
        if(sati < 0 || sati > 23 || minute < 0 || minute > 59)throw std::domain_error("Neispravno vrijeme");
        this -> sati = sati; this -> minute = minute;
    }
    std::pair<int, int>  Ocitaj ()const{
        std::pair<int, int> vrijeme = std::make_pair(sati, minute);
        return vrijeme;
    }
    void Ispisi ()const {
        if(sati < 10)std::cout << "0" << sati;
        else std::cout << sati;
        if(minute < 10)std::cout << ":0"<< minute;
        else std::cout << ":" << minute;
    }
};

 class Pregled{
    private:
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    
    public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum_pregleda(0,0,0), vrijeme_pregleda(0,0){
        this -> ime_pacijenta = ime_pacijenta; this -> datum_pregleda = datum_pregleda; this -> vrijeme_pregleda = vrijeme_pregleda;
    }
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregelda, int sati_pregelda, int minute_pregleda): 
    datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregelda), vrijeme_pregleda(sati_pregelda, minute_pregleda){
        this -> ime_pacijenta = ime_pacijenta;
    }
    void PromijeniPacijenta (const std::string &ime_pacijenta){this -> ime_pacijenta = ime_pacijenta;}
    void PromijeniDatum (const Datum &novi_datum){datum_pregleda = novi_datum;}
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){vrijeme_pregleda = novo_vrijeme;}
    void PomjeriDanUnaprijed(){
        std::tuple<int, int, int> datum = datum_pregleda.Ocitaj();
        int dan = std::get<0>(datum);
        int mjesec = std::get<1>(datum);
        int godina = std::get<2>(datum);
        int broj_dana [12]{ 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)broj_dana[1]++;
        int mjesec_po_redu =mjesec - 1;
        dan ++;
        for(int i = 0; i < 12; i ++){
            if(mjesec_po_redu == i){
                if(dan > broj_dana[i]){
                    dan = 1;
                    mjesec++;
                }
                if(mjesec > 12){
                    mjesec = 1;
                    godina ++;
                }
            }
        }
        this -> datum_pregleda = Datum(dan, mjesec, godina);
    }
    void PomjeriDanUnazad(){
        std::tuple<int, int, int> datum = datum_pregleda.Ocitaj();
        int dan = std::get<0>(datum);
        int mjesec = std::get<1>(datum);
        int godina = std::get<2>(datum);
        int broj_dana [12]{ 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)broj_dana[1]++;
        int mjesec_po_redu = mjesec - 1;
        dan --;
        for(int i = 0; i < 12; i ++){
            if(mjesec_po_redu == i){
                if(dan < 0){
                    if(i == 1) dan = broj_dana[12];
                    else dan = broj_dana[i - 1];
                    mjesec--;
                }
                if(mjesec < 0){
                    mjesec = 12;
                    godina --;
                }
            }
        }
        this -> datum_pregleda = Datum(dan, mjesec, godina);
    }
    std::string DajImePacijenta () const{return ime_pacijenta;}
    Datum DajDatumPregleda ()const {return datum_pregleda;}
    Vrijeme DajVrijemePregleda ()const {return vrijeme_pregleda;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        std::tuple<int, int, int> prvi_datum, drugi_datum;
        int prvi_dan = std::get<0>(prvi_datum);
        int prvi_mjesec = std::get<1>(prvi_datum);
        int prvi_godina = std::get<2>(prvi_datum);
        int drugi_dan = std::get<0>(drugi_datum);
        int drugi_mjesec = std::get<1>(drugi_datum);
        int drugi_godina = std::get<2>(drugi_datum);
        
        std::pair<int,int> vrijeme1, vrijeme2;
        int sati1 = vrijeme1.first;
        int minute1 = vrijeme1.second;
        int sati2 = vrijeme2.first;
        int minute2 = vrijeme2.second;
        
        if(prvi_godina < drugi_godina)return true;
        else if(prvi_godina > drugi_godina)return false;
        else if(prvi_godina == drugi_godina){
            if(prvi_mjesec < drugi_mjesec)return true;
            else if(prvi_mjesec > drugi_mjesec)return false;
            else if(prvi_mjesec == drugi_mjesec){
                if(prvi_dan < drugi_dan)return true;
                else if(prvi_dan > drugi_dan)return false;
                else if(prvi_dan == drugi_dan){
                    if(sati1 < sati2)return true;
                    else if(sati1> sati2)return false;
                    else if(sati1 == sati2){
                        if(minute1 < minute2)return true;
                        else if(minute1 > minute2)return false;
                        else return false;
                    }
                }
            }
        }
        
    }
    void Ispisi() const{
        std::cout << std::setw(30)<<std::left<< ime_pacijenta; datum_pregleda.Ispisi(); std::cout<< " "; vrijeme_pregleda.Ispisi(); std::cout<< std::endl;
    }
    
};

class Pregledi{
    private:
    const int max_broj_pregleda;
    int broj_pregleda;
    Pregled **pregledi;
    public:
    explicit Pregledi (int maksimum):max_broj_pregleda(maksimum),broj_pregleda(0),pregledi(new Pregled*[max_broj_pregleda]){for(int i = 0; i < max_broj_pregleda; i++)pregledi[i] = nullptr;}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()){
        pregledi = new Pregled*[spisak_pregleda.size()];
        for(int i = 0; i < spisak_pregleda.size(); i++) pregledi[i] = new Pregled(*(spisak_pregleda.begin() + i));
    } 
    ~Pregledi(){
        for(int i = 0; i < broj_pregleda; i++)delete pregledi[i];
        delete[] pregledi;
    }
    Pregledi (const Pregledi &p): pregledi(new Pregled*[p.max_broj_pregleda]{}), max_broj_pregleda(p.max_broj_pregleda), broj_pregleda(p.broj_pregleda){
        try{
            for (int i = 0; i < p.max_broj_pregleda; i++)pregledi[i] = new Pregled(*p.pregledi[i]);
        }
        catch(...){
            for(int i = 0; i < p.broj_pregleda; i++)delete pregledi[i];
            delete [] pregledi;
        }
    }
    Pregledi (Pregledi &&p):pregledi(p.pregledi), max_broj_pregleda(p.max_broj_pregleda), broj_pregleda(p.broj_pregleda){
        p.pregledi =nullptr;
        p.broj_pregleda = 0;
    }
    Pregledi &operator = (const Pregledi &p){
        if(p.max_broj_pregleda != max_broj_pregleda)throw std::logic_error("Nesaglasni kapaciteti pregleda");
        if(p.broj_pregleda > broj_pregleda){
            try{
                for(int i = 0; i < p.broj_pregleda; i++)pregledi[i] = new Pregled(*p.pregledi[i]);
            }
            catch(...){
                for(int i = broj_pregleda; i < p.broj_pregleda; i++){
                    delete pregledi[i];
                    pregledi[i] = nullptr;
                }
                throw;
            }
        }
        else {
            for(int i = p.broj_pregleda; i < broj_pregleda; i++){
                delete pregledi[i];
                pregledi[i] = nullptr;
            }
        }
        for(int i = 0; i < broj_pregleda; i++)*pregledi[i] = *p.pregledi[i];
        return *this;
    }
    Pregledi &operator = (Pregledi &&p){
        if(p.max_broj_pregleda != max_broj_pregleda)throw std::logic_error("Nesaglasni kapaciteti pregleda");
        std::swap(broj_pregleda, p.broj_pregleda);
        std::swap(pregledi, p.pregledi);
        return *this;
    }
    
    void RegistrirajPregled (const std::string &ime, const Datum &datum, const Vrijeme &vrijeme){
        if(broj_pregleda >= max_broj_pregleda)throw std::range_error("Dostignut maksimalni broj pregleda");
        for(int i = 0; i < max_broj_pregleda; i++){
            if(pregledi[i] == nullptr){pregledi[i] = new Pregled(ime,datum, vrijeme);break;}
        }
        broj_pregleda ++;
    }
    void RegistrirajPregled (const std::string &ime, int dan, int mjesec, int godina, int sat, int minuta){
        if(broj_pregleda >= max_broj_pregleda)throw std::range_error("Dostignut maksimalni broj pregleda");
        for(int i = 0; i < max_broj_pregleda; i++ ){
            if(pregledi[i] == nullptr){pregledi[i] = new Pregled(ime, dan, mjesec, godina, sat, minuta); break;}
        }
        broj_pregleda++;
    }
    void RegistrirajPregled (Pregled *pregled){
        if(broj_pregleda >= max_broj_pregleda)throw std::range_error ("Dostignut maksimalni broj pregleda");
        pregledi[broj_pregleda++] = pregled;
    }
    int DajBrojPregleda()const {
        if(pregledi[0] == nullptr)throw std::domain_error ("Nema registriranih pregleda");
        return std::count_if(pregledi, pregledi+ broj_pregleda, [](const Pregled *pregled){if (pregled != nullptr) return true;});
    }
    int DajBrojPregledaNaDatum (const Datum &datum) const{
        if(pregledi[0] == nullptr)throw std::domain_error ("Nema registriranih pregleda");
        return std::count_if(pregledi,pregledi + broj_pregleda, [datum](const Pregled *pregled){
            std::tuple<int, int, int> za_porediti = pregled -> DajDatumPregleda().Ocitaj() ;
            std::tuple<int, int, int> datum2 = datum.Ocitaj();
            int prvi_dan = std::get<0>(za_porediti);
            int prvi_mjesec = std::get<1>(za_porediti);
            int prvi_godina = std::get<2>(za_porediti);
           
            int drugi_dan = std::get<0>(datum2);
            int drugi_mjesec = std::get<1>(datum2);
            int drugi_godina = std::get<2>(datum2);
            if(prvi_godina == drugi_godina){
                if(prvi_mjesec == drugi_mjesec){
                    if(prvi_dan == drugi_dan)return true;
                    else return false;
                }
                else return false;
            }
            else return false;
        });
    }
   Pregled &DajNajranijiPregled(){
       
   }
   Pregled DajNajranijiPregled()const{
       
   }

};


int main (){
    return 0;
}
