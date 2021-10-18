/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <utility> 

// PAZITI NA UNOS VREMENA u svim slucajevima klasa
// PAZITI NA UNOS DATUMA u svim slucajnevima klasa
// PAZITI NA IZUZETKE

class Datum {
    
    private:
    int dan, mjesec, godina;
    
    public:
    // konstruktor
    Datum (int dan, int mjesec, int godina){
        Postavi(dan, mjesec, godina);
    }
    
    // mutator
    void Postavi (int dan, int mjesec, int godina){
        int dani_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)){
            dani_u_mjesecu[1]++;
        }
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>dani_u_mjesecu[mjesec-1]){
            throw std::domain_error("Neispravan datum");
        }
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    
    // inspektor
    std::tuple<int, int, int> Ocitaj() const{
        auto tmp = std::make_tuple(dan, mjesec, godina);
        return tmp;
    }
    // ispis
    void Ispisi() const{
        std::cout << Datum::dan << "/" << Datum::mjesec << "/" << Datum::godina;
    }
    
};

class Vrijeme {
  
    private:
    int sati, minute;
    
    public:
    // konstruktor
    Vrijeme (int sati, int minute){
        Postavi(sati, minute);
    }
    
    // mutator
    void Postavi(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59){
            throw std::domain_error("Neispravno vrijeme");
        }
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    
    // inspektori
    std::pair<int, int>Ocitaj() const{
        auto tmp = std::make_pair(sati, minute);
        return tmp;
    }
    
    // ispis
    void Ispisi() const{
        if(sati<10 && minute>=10){
            std::cout << "0" << sati << ":" << minute;
        } else if(sati<10 && minute<10){
            std::cout << "0" << sati << ":0" << minute;
        } else if(sati>=10 && minute<10){
            std::cout << sati << ":" << "0" << minute;
        } else {
            std::cout << sati << ":" << minute;
        }
    }
  
};

class Pregled {
  
    private:
    std::string IME_pacijenta;
    Datum DATUM_pregleda_pacijenta;
    Vrijeme VRIJEME_pregleda_pacijenta;
  
    public:
    // Zastititi se od pogresnog vremena
    // Zastititi se od pogresnog datuma
    // Konstruktori
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : IME_pacijenta(ime_pacijenta), DATUM_pregleda_pacijenta(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)), VRIJEME_pregleda_pacijenta(Vrijeme(sati_pregleda, minute_pregleda)) {};
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : IME_pacijenta(ime_pacijenta), DATUM_pregleda_pacijenta(datum_pregleda), VRIJEME_pregleda_pacijenta(vrijeme_pregleda){};
    
    // Mutatori
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme){
        VRIJEME_pregleda_pacijenta = novo_vrijeme;
    }
    void PromijeniDatum (const Datum &novi_datum){
        DATUM_pregleda_pacijenta = novi_datum;
    }
    void PromijeniPacijenta (const std::string &ime_pacijenta){
        IME_pacijenta = ime_pacijenta;
    }
    
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
   
    // Inspektori
    Datum DajDatumPregleda() const{
        return DATUM_pregleda_pacijenta;
    }
    Vrijeme DajVrijemePregleda() const{
        return VRIJEME_pregleda_pacijenta;
    }
    std::string DajImePacijenta() const{
        return IME_pacijenta;
    }
    
    // Ispis
    void Ispisi() const{
        std::cout << std::setw(30) << std::left << IME_pacijenta;
        
        DATUM_pregleda_pacijenta.Ispisi();
        
        std::cout << " " << std::right;
        VRIJEME_pregleda_pacijenta.Ispisi();
        
        std::cout << std::endl;
    }
    
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
};

void Pregled::PomjeriDanUnazad(){
    int dan, mjesec, godina;
    
    Datum dat = DATUM_pregleda_pacijenta;
    std::tuple<int,int,int> dt = dat.Ocitaj();
    
    dan = std::get<0>(dt);
    mjesec = std::get<1>(dt);
    godina = std::get<2>(dt);
    
    int dani_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if( (godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0) ){
        dani_u_mjesecu[1]++;
    }
    
    dan--; // pomjeri dan unazad
    
    if(dan < 1){
        mjesec--;
        if(mjesec < 1){
            dan = dani_u_mjesecu[mjesec-1];
            godina--;
            mjesec = 12;
            DATUM_pregleda_pacijenta.Postavi(dan, mjesec, godina);
            return;
        }
        dan = dani_u_mjesecu[mjesec-1];
        DATUM_pregleda_pacijenta.Postavi(dan, mjesec, godina);
    }
}
void Pregled::PomjeriDanUnaprijed(){
    int dan, mjesec, godina;
    Datum dat = DATUM_pregleda_pacijenta;
    std::tuple<int,int,int> dt = dat.Ocitaj();
    
    dan = std::get<0>(dt);
    mjesec = std::get<1>(dt);
    godina = std::get<2>(dt);
    
    int dani_u_mjesecu[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if( (godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0) ){
        dani_u_mjesecu[1]++;
    }
    
    dan++; // Pomjera dan
    
    // Verifikacija dana
    if(dani_u_mjesecu[mjesec-1] > dan){
        //za mjesec
        mjesec++;
        dan = 1;
        if(mjesec > 12){
            //za godinu
            godina++;
            mjesec = 1;
        }
    }
    DATUM_pregleda_pacijenta.Postavi(dan, mjesec, godina);
}

class Pregledi{
    
    private:
    Pregled **pregledi = nullptr;
    int max_broj_pregleda;
    int broj_pregleda;
    
    public:
    // Konstruktori
    explicit Pregledi(int max_broj_pregleda){
        Pregledi::max_broj_pregleda = max_broj_pregleda;
        Pregledi::broj_pregleda = 0;
        try{
            pregledi = new Pregled*[max_broj_pregleda];
            for(int i=0; i<max_broj_pregleda; i++){
                pregledi[i] = nullptr;
            }
        } catch(...){
            delete[] pregledi;
            throw;
        }
    }
    Pregledi (std::initializer_list<Pregled> spisak_pregleda){
        Pregledi::max_broj_pregleda = spisak_pregleda.size();
        Pregledi::broj_pregleda = spisak_pregleda.size();
        try{
            int brojac = 0;
            pregledi = new Pregled*[max_broj_pregleda];
            for(int i=0; i<max_broj_pregleda; i++){
                pregledi[i] = nullptr;
            }
            for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
                pregledi[brojac] = new Pregled(*it);
                brojac++;
            }
        } catch(...){
            for(int i=0; i<broj_pregleda; i++){
                delete pregledi[i];
                pregledi[i] = nullptr;
            }
            delete[] pregledi;
            throw;
        }
    }
    
    // Kopirajuci konstrukt
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    
    // Operatori dodjele
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    
    // Destruktor
    ~Pregledi(){
        if(pregledi == nullptr){
            return;
        }
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
    }
    
    // Registracija
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    
    // Inspektori
    int DajBrojPregleda() const{
        return broj_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        int brojac = std::count_if(pregledi, pregledi+broj_pregleda, [&datum](Pregled *pregled_tmp){
            Datum dat = pregled_tmp->DajDatumPregleda();
            std::tuple<int,int,int> dt1 = dat.Ocitaj();
            std::tuple<int,int,int> dt2 = datum.Ocitaj();
           if(std::get<2>(dt1) == std::get<2>(dt2)
           && std::get<1>(dt1) == std::get<1>(dt2)
           && std::get<0>(dt1) == std::get<0>(dt2)){
               return true;
           }  else {
               return false;
           }
        });
        return brojac;
    }
    Pregled &DajNajranijiPregled(){
        if(Pregledi::broj_pregleda == 0){
            throw std::domain_error("Nema registriranih pregleda");
        }
        auto najraniji_pregled = std::min_element(pregledi, pregledi+broj_pregleda, [](Pregled *pregled_1, Pregled *pregled_2){
           if(DolaziPrije(*pregled_1, *pregled_2)){
               return true;
           } 
           return false;
        });
        return **najraniji_pregled;
    }
    Pregled DajNajranijiPregled() const{
        if(Pregledi::broj_pregleda == 0){
            throw std::domain_error("Nema registriranih pregleda");
        }
        auto najraniji_pregled = std::min_element(pregledi, pregledi+broj_pregleda, [](Pregled *pregled_1, Pregled *pregled_2){
            if(DolaziPrije(*pregled_1, *pregled_2)){
                return true;
            }
            return false;
        });
        return **najraniji_pregled;
    }
    
    // Brisanje
    void IsprazniKolekciju(){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        broj_pregleda = 0;
    }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    
    // Ispisi
    void IspisiPregledNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(const Pregledi &p){
    Pregledi::max_broj_pregleda = p.max_broj_pregleda;
    Pregledi::broj_pregleda = p.broj_pregleda;
    try{
        pregledi = new Pregled*[max_broj_pregleda];
        
        for(int i=0; i<max_broj_pregleda; i++){
            pregledi[i] = nullptr;
        }
        
        for(int i=0; i<broj_pregleda; i++){
            pregledi[i] = new Pregled(*p.pregledi[i]);
        }
    } catch(...){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
        throw;
    }
}
Pregledi::Pregledi(Pregledi &&p){
    Pregledi::max_broj_pregleda = p.max_broj_pregleda;
    Pregledi::broj_pregleda = p.broj_pregleda;
    
    pregledi = p.pregledi;
    
    p.max_broj_pregleda = 0;
    p.broj_pregleda = 0;
    p.pregledi = nullptr;
}

Pregledi &Pregledi::operator =(const Pregledi &p){
    try{
        if(&p != this){
            
            for(int i=0; i<broj_pregleda; i++){
                delete pregledi[i];
            }
            delete[] pregledi;
            
            max_broj_pregleda = p.max_broj_pregleda;
            broj_pregleda = p.broj_pregleda;
            pregledi = new Pregled*[max_broj_pregleda];
            
            for(int i=0; i<max_broj_pregleda; i++){
                pregledi[i] = nullptr;
            }
            
            for(int i=0; i<broj_pregleda; i++){
                pregledi[i] = new Pregled(*p.pregledi[i]);
            }
        }
        return *this;
    } catch(...){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
        throw;
    }
}
Pregledi &Pregledi::operator =(Pregledi &&p){
    if(&p != this){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
        }
        delete[] pregledi;
        
        max_broj_pregleda = p.max_broj_pregleda;
        broj_pregleda = p.broj_pregleda;
        
        pregledi = p.pregledi;
        
        p.max_broj_pregleda = 0;
        p.broj_pregleda = 0;
        p.pregledi = nullptr;
    }
    return *this;
}

// Registracija
void Pregledi::RegistrirajPregled(Pregled *pregled){
    try{
        if(broj_pregleda+1 > max_broj_pregleda){
            delete pregled;
            throw::std::range_error("Dostignut maksimalni broj pregleda");
        }
        
        bool postoji_pregled(false);
        // trazi pregled
        for(int i=0; i<broj_pregleda; i++){
            if(pregledi[i] == pregled){
                postoji_pregled = true;
            }
        }
        
        if(postoji_pregled == true){
            pregledi[broj_pregleda] = new Pregled(*pregled);
            broj_pregleda++;
        } else {
            pregledi[broj_pregleda] = pregled;
            broj_pregleda++;
        }
    } catch(...){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
        throw;
    }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    try{
        if(broj_pregleda+1 > max_broj_pregleda){
            throw std::range_error("Dostignut maksimalni broj pregleda");
        }
        pregledi[broj_pregleda] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        broj_pregleda++;
    } catch(...){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
        throw;
    }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    try{
        if(broj_pregleda+1 > max_broj_pregleda){
            throw std::range_error("Dostignut maksimalni broj pregleda");
        }
        
        pregledi[broj_pregleda] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        broj_pregleda++;
    } catch(...){
        for(int i=0; i<broj_pregleda; i++){
            delete pregledi[i];
            pregledi[i] = nullptr;
        }
        delete[] pregledi;
        throw;
    }
}

// Brisanje 
void Pregledi::ObrisiNajranijiPregled(){
    if(broj_pregleda == 0){
        throw std::range_error("Prazna kolekcija");
    }
    int min = 0;
    Pregled tmp_pregled = DajNajranijiPregled();
    for(int i=0; i<broj_pregleda; i++){
        Datum dat1 = pregledi[i]->DajDatumPregleda();
        Datum dat2 = tmp_pregled.DajDatumPregleda();
        std::tuple<int,int,int> dt1 = dat1.Ocitaj();
        std::tuple<int,int,int> dt2 = dat2.Ocitaj();
        
        Vrijeme vri1 = pregledi[i]->DajVrijemePregleda();
        Vrijeme vri2 = tmp_pregled.DajVrijemePregleda();
        std::pair<int,int>vr1 = vri1.Ocitaj();
        std::pair<int,int>vr2 = vri2.Ocitaj();
        
        if(std::get<0>(dt1) == std::get<0>(dt2)
        && std::get<1>(dt1) == std::get<1>(dt2)
        && std::get<2>(dt1) == std::get<2>(dt2)
        && pregledi[i]->DajImePacijenta() == tmp_pregled.DajImePacijenta()
        && vr1.first == vr2.first
        && vr1.second == vr2.second){
            min = i;
        } 
    }
    delete pregledi[min];
    for(int i=min; i<broj_pregleda-1; i++){
        pregledi[i] = pregledi[i+1];
    }
    broj_pregleda--;
}
void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta){
    if(broj_pregleda == 0){
        throw std::range_error("Prazna kolekcija");
    }
    for(int i=0; i<broj_pregleda; i++){
        if(pregledi[i]->DajImePacijenta() == ime_pacijenta){
            delete pregledi[i];
            for(int j=i; j<broj_pregleda-1; j++){
                pregledi[j] = pregledi[j+1];
            }
            --broj_pregleda;
            i--;
        }
    }
}
 
// Ispisi
void Pregledi::IspisiSvePreglede() const{
    int brojac = 0;
    
    Pregledi tmp = *this;
    int bp = tmp.broj_pregleda;
    while(bp > brojac){
        // nadji najmanji i ispis ga
        Pregled najmanji_pregled = tmp.DajNajranijiPregled();
        najmanji_pregled.Ispisi();
        
        brojac++;
        // obrisi ga
        tmp.ObrisiNajranijiPregled();
    }
}
void Pregledi::IspisiPregledNaDatum(Datum &datum) const{ 
    int bp = DajBrojPregledaNaDatum(datum);
    Pregledi tmp(bp); // konstruktor Pregledi tmp kreira od int bp

    // prolazi kroz sve preglede i poredi datum
    for(int i=0; i<broj_pregleda; i++){
        Datum dat1 = pregledi[i]->DajDatumPregleda();
        Datum dat2 = datum;
        std::tuple<int,int,int> dt1 = dat1.Ocitaj();
        std::tuple<int,int,int> dt2 = dat2.Ocitaj();
        if(std::get<0>(dt1) == std::get<0>(dt2)
        && std::get<1>(dt1) == std::get<1>(dt2)
        && std::get<2>(dt1) == std::get<2>(dt2)){
            tmp.RegistrirajPregled(pregledi[i]->DajImePacijenta(), pregledi[i]->DajDatumPregleda(), pregledi[i]->DajVrijemePregleda());
        }
    }
    
    int brojP = tmp.broj_pregleda;
    int brojac = 0;

    while(brojP > brojac){
        // Uzima najraniji pregled i ipsisuje ga
        Pregled pregled = tmp.DajNajranijiPregled();
        pregled.Ispisi();
        // brise ga
        brojac++;
        tmp.ObrisiNajranijiPregled();
    }
}


// Prijateljska
bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    bool x(false);

    Datum dat1 = p1.DajDatumPregleda();
    Datum dat2 = p2.DajDatumPregleda();
    std::tuple<int,int,int> dt1 = dat1.Ocitaj();
    std::tuple<int,int,int> dt2 = dat2.Ocitaj();
    
    Vrijeme vri1 = p1.DajVrijemePregleda();
    Vrijeme vri2 = p2.DajVrijemePregleda();
    std::pair<int,int> vr1 = vri1.Ocitaj();
    std::pair<int,int> vr2 = vri2.Ocitaj();
    
    if(std::get<2>(dt1) <= std::get<2>(dt2)
    && std::get<1>(dt1) <= std::get<1>(dt2)
    && std::get<0>(dt1) <= std::get<0>(dt2)){
        x = true;
    }
    if((std::get<2>(dt1) < std::get<2>(dt2))
    ||(std::get<2>(dt1) <= std::get<2>(dt2) && std::get<1>(dt1) < std::get<1>(dt2))
    ||(std::get<2>(dt1) <= std::get<2>(dt2) && std::get<1>(dt1) <= std::get<1>(dt2) && std::get<0>(dt1) < std::get<0>(dt2))
    ||(x && vr1.first < vr2.first)
    ||(x && vr1.first <= vr2.first && vr1.second < vr2.second)){
        return true;
    }
    return false;
}

int main (){
    
    // TESTIRANI Konstrukotir dodjle i operatori dodjele NA KRAJU
    
    // TESTIRANJE KLASE DA LI RADI
    /* std::cout << "Kompajlira se!";
	return 0; */
	
	// TESTIRANJE KLASA - 01
	/* Vrijeme vrijeme1(10,10);
    vrijeme1.Ispisi();
    std::cout << std::endl;
    
	Vrijeme vrijeme2(15, 59);
	vrijeme2.Ispisi();
	std::cout << std::endl;
	
	Datum datum1(22, 7, 1996);
	datum1.Ispisi();
	std::cout << std::endl;
	
	Datum datum2(29,12,2016);
	datum2.Ispisi();
	std::cout << std::endl;
	
	Pregled pregled1("Irma Red", 4, 6, 1998, 2, 2);
	pregled1.Ispisi();
	std::cout << std::endl;
	
	Pregled pregled2("Kerim Red", datum1, vrijeme1);
	pregled2.Ispisi();
	std::cout << std::endl;
    
    Pregledi tmp1{pregled1, pregled2};
    tmp1.IspisiSvePreglede();
    std::cout << std::endl;
    
	Pregledi pregledi1{pregled1, pregled2};
	pregledi1.IspisiPregledNaDatum(datum1);
	std::cout << pregledi1.DajBrojPregleda() << std::endl;
	pregledi1.ObrisiNajranijiPregled();
	Datum tmp(14,10,2017);
	pregledi1.IspisiPregledNaDatum(tmp);
	std::cout << std::endl << std::endl;
	
	// testiranje dodjele
	Pregledi pregledi2 = pregledi1;
	pregledi1.IspisiSvePreglede();
	
	std::cout << std::endl << std::endl;
	Pregledi pregledi3 = {pregled1, pregled2};
	pregledi3.IspisiSvePreglede();
	
	// testiranje konstruktora kopije
	std::cout << std::endl << std::endl;
	pregledi3 = pregledi2;
	pregledi2.IspisiSvePreglede();
	
	return 0; */

	
	// PISANJE MAINA IZ TESTOVA
	
	int maks_broj_pregleda;
	std::cout << "Unesite maksimalan broj pregleda: ";
	std::cin >> maks_broj_pregleda;
	std::cin.ignore(10000, '\n');
    
    Pregledi pregledi(maks_broj_pregleda);
    
    int tmp_brojac(0);	
	while(tmp_brojac<maks_broj_pregleda){
	    std::string ime_pacijenta;
	    std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
	    std::getline(std::cin, ime_pacijenta);
	    
	    if(ime_pacijenta == "kraj"){
	        break;
	    }
	    
	    int dan, mjesec, godina;
	    std::cout << "Unesite dan mjesec i godinu pregleda: ";
	    std::cin >> dan >> mjesec >> godina;
	    
	    int sati, minute;
	    std::cout << "Unesite sate i minute pregleda: ";
	    std::cin >> sati >> minute;
	    
	    
	    // kreiranje objekata klasa
	    pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
	    std::cin.ignore(10000, '\n');
    	    
	    tmp_brojac++;
	}
	
	std::cout << "Trenutno su registrovani sljedeci pregledi";
	std::cout << std::endl;
	pregledi.IspisiSvePreglede();
	std::cout << std::endl; 
	
	// MENI
	int izbor(1);
	while(izbor < 7 && izbor > 0){
	    std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
	    std::cout << "1 - Broj pregleda na datum" << std::endl;
	    std::cout << "2 - Najraniji pregled" << std::endl;
	    std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
	    std::cout << "4 - Obrisi najraniji pregled" << std::endl;
	    std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
	    std::cout << "6 - Ispisi sve preglede" << std::endl;
	    std::cout << "7 - Kraj programa";
	    std::cout << std::endl;
	    std::cin >> izbor;

	    if(izbor == 1){
	        std::cin.ignore(10000, '\n');
	        int dd, mm, gggg;
	        std::cout << "Unesite dan mjesec i godinu : ";
	        std::cin >> dd >> mm >> gggg;
	        Datum datum (dd, mm, gggg);
	        std::cout << "Broj pregleda na datum " << dd << " " << mm << " " << gggg << " je: " << pregledi.DajBrojPregledaNaDatum(datum) << std::endl << std::endl;
	    } else if(izbor == 2){
	        std::cin.ignore(10000, '\n');
	        std::cout << "Najraniji pregled je: " << std::endl;
	        Pregled tmp = pregledi.DajNajranijiPregled();
	        tmp.Ispisi();
	        std::cout << std::endl;
	    } else if(izbor == 3){
	        std::cin.ignore(10000, '\n');
	        std::string ime_pacijenta;
	        std::cout << "Unesite ime pacijenta: ";
	        std::getline(std::cin, ime_pacijenta);
	        int broj_pregleda_prije = pregledi.DajBrojPregleda();
	        pregledi.ObrisiPregledePacijenata(ime_pacijenta);
	        int obrisano = std::abs(pregledi.DajBrojPregleda() - broj_pregleda_prije);
	        std::cout << "Uspjesno obrisano " << obrisano << " pregleda" << std::endl << std::endl;
	    } else if(izbor == 4){
	        std::cin.ignore(10000, '\n');
	        pregledi.ObrisiNajranijiPregled();
	        std::cout << "Najraniji pregled uspjesno obrisan" << std::endl << std::endl;
	    } else if(izbor == 5){
	        std::cin.ignore(10000, '\n');
	        int dd, mm, gggg;
	        std::cout << "Unesite dan mjesec i godinu : ";
	        std::cin >> dd >> mm >> gggg;
	        Datum datum(dd, mm, gggg);
	        std::cout << "Pregledi na datum " << dd << " " << mm << " " << gggg << " su: " << std::endl;
	        pregledi.IspisiPregledNaDatum(datum);
	        std::cout << std::endl;
	    } else if(izbor == 6){
	        std::cout << std::endl;
	        pregledi.IspisiSvePreglede();
	        std::cout << std::endl;
	    }
	}
	
	return 0; 
}