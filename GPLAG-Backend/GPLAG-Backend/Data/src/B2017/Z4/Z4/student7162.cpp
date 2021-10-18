/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <string>
#include <iomanip>
#include <vector>
#include <utility> 
#include <tuple>

// KOPIRAN IZ ZADATAK 3
// PREVELIK ZA PREKUCATI

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
    
    // inspektori
    std::tuple<int,int,int> Ocitaj() const{
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
    std::pair<int,int> Ocitaj() const{
        auto tmp = std::make_pair(sati, minute);
        return tmp;
    }
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
    std::vector<std::shared_ptr<Pregled>> vektor_pregleda;
    
    public:
    // Konstruktori
    explicit Pregledi(){
        vektor_pregleda.resize(0);
    }
    Pregledi (std::initializer_list<Pregled> spisak_pregleda){
        try{
            for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++){
                vektor_pregleda.push_back(std::make_shared<Pregled>(*it));
            }
        } catch(...){
            for(int i=0; i<vektor_pregleda.size(); i++){
                vektor_pregleda[i] = nullptr;
            }
            vektor_pregleda.resize(0);
            throw;
        }
    }
    
    // Kopirajuci konstrukt
    Pregledi (const Pregledi &pregledi){
        try{
            for(int i = 0; i<pregledi.vektor_pregleda.size(); i++){
                vektor_pregleda.push_back(std::make_shared<Pregled>(*pregledi.vektor_pregleda[i]));
            }
        } catch(...){
            for(int i=0; i<vektor_pregleda.size(); i++){
                vektor_pregleda[i] = nullptr;
            }
            vektor_pregleda.resize(0);
            throw;
        }
    }
    Pregledi (Pregledi &&pregledi){
        vektor_pregleda = pregledi.vektor_pregleda;
        pregledi.vektor_pregleda.resize(0);
    }
    
    // Operatori dodjele
    Pregledi &operator =(const Pregledi &pregledi){
        try{
            if(&pregledi != this){
                for(int i=0; i<vektor_pregleda.size(); i++){
                    vektor_pregleda[i] = nullptr;
                }
                
                vektor_pregleda.resize(0);
                
                for(int i=0; i<pregledi.vektor_pregleda.size(); i++){
                    vektor_pregleda.push_back(std::make_shared<Pregled>(*pregledi.vektor_pregleda[i]));
                }
            }
            return *this;
        } catch(...){
            for(int i=0; i<vektor_pregleda.size(); i++){
                vektor_pregleda[i] = nullptr;
            }
            vektor_pregleda.resize(0);
            throw;
        }
    }
    Pregledi &operator =(Pregledi &&pregledi){
        if(&pregledi != this){
            for(int i=0; i<vektor_pregleda.size(); i++){
                vektor_pregleda[i] = nullptr;
            }
            vektor_pregleda.resize(0);
            vektor_pregleda = pregledi.vektor_pregleda;
            pregledi.vektor_pregleda.resize(0);
        }
        return *this;
    }
    
    // Destruktor
    ~Pregledi(){
        for(int i=0; i<vektor_pregleda.size(); i++){
            vektor_pregleda[i] = nullptr;
        }
        vektor_pregleda.resize(0);
    }
    
    // Registracija
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    
    // Inspektori
    int DajBrojPregleda() const{
        return vektor_pregleda.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        int brojac = std::count_if(vektor_pregleda.begin(), vektor_pregleda.end(), [&datum](std::shared_ptr<Pregled> pregled_tmp){
            Datum dat1 = pregled_tmp->DajDatumPregleda();
            Datum dat2 = datum;
            
            std::tuple<int,int,int> dt1 = dat1.Ocitaj();
            std::tuple<int,int,int> dt2 = dat2.Ocitaj();
            
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
        if(vektor_pregleda.size() == 0){
            throw std::domain_error("Nema registriranih pregleda");
        }
        auto najraniji_pregled = std::min_element(vektor_pregleda.begin(), vektor_pregleda.end(), [](std::shared_ptr<Pregled> pregled_1, std::shared_ptr<Pregled> pregled_2){
           if(DolaziPrije(*pregled_1, *pregled_2)){
               return true;
           } 
           return false;
        });
        return **najraniji_pregled;
    }
    Pregled DajNajranijiPregled() const{
        if(vektor_pregleda.size() == 0){
            throw std::domain_error("Nema registriranih pregleda");
        }
        auto najraniji_pregled = std::min_element(vektor_pregleda.begin(), vektor_pregleda.end(), [](std::shared_ptr<Pregled> pregled_1, std::shared_ptr<Pregled> pregled_2){
           if(DolaziPrije(*pregled_1, *pregled_2)){
               return true;
           } 
           return false;
        });
        return **najraniji_pregled;
    }
    
    // Brisanje
    void IsprazniKolekciju(){
        for(int i=0; i<vektor_pregleda.size(); i++){
            vektor_pregleda[i] = nullptr;
        }
        vektor_pregleda.resize(0);
    }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    
    // Ispisi
    void IspisiPregledNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const{
        Pregledi tmp = *this;
        int brojP = tmp.vektor_pregleda.size();
        
        for(int i=0; i<brojP; i++){
            auto najraniji_pregled = tmp.DajNajranijiPregled();
            najraniji_pregled.Ispisi();
            tmp.ObrisiNajranijiPregled();
        }
    }
};

// Registracija
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled){
    try{
        vektor_pregleda.push_back(pregled);
    } catch(...){
        for(int i=0; i<vektor_pregleda.size(); i++){
            vektor_pregleda[i] = nullptr;
        }
        vektor_pregleda.resize(0);
        throw;
    }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    try{
        vektor_pregleda.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    } catch(...){
        for(int i=0; i<vektor_pregleda.size(); i++){
            vektor_pregleda[i] = nullptr;
        }
        vektor_pregleda.resize(0);
        throw;
    }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    try{
        vektor_pregleda.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    } catch(...){
        for(int i=0; i<vektor_pregleda.size(); i++){
            vektor_pregleda[i] = nullptr;
        }
        vektor_pregleda.resize(0);
        throw;
    }
}

// Brisanje 
void Pregledi::ObrisiNajranijiPregled(){
    if(vektor_pregleda.size() == 0){
        throw std::range_error("Prazna kolekcija");
    }
    
    int min = 0;
    auto najraniji_pregled = DajNajranijiPregled();
    int i;
    
    for(i=0; i<vektor_pregleda.size(); i++){
        Datum dat1 = vektor_pregleda[i]->DajDatumPregleda();
        Datum dat2 = najraniji_pregled.DajDatumPregleda();
        
        std::tuple<int,int,int> dt1 = dat1.Ocitaj(); 
        std::tuple<int,int,int> dt2 = dat2.Ocitaj();
        
        Vrijeme vri1 = vektor_pregleda[i]->DajVrijemePregleda();
        Vrijeme vri2 = najraniji_pregled.DajVrijemePregleda();
        
        std::pair<int,int> vr1 = vri1.Ocitaj();
        std::pair<int,int> vr2 = vri2.Ocitaj();
        
        if(std::get<0>(dt1) == std::get<0>(dt2)
        && std::get<1>(dt1) == std::get<1>(dt2)
        && std::get<2>(dt1) == std::get<2>(dt2)
        && vektor_pregleda[i]->DajImePacijenta() == najraniji_pregled.DajImePacijenta()
        && vr1.first == vr1.first
        && vr2.second == vr2.second){
            min = i;
            break;
        } 
    }
    vektor_pregleda[min] = nullptr;
    vektor_pregleda.erase(vektor_pregleda.begin() + min);
}
void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta){
    if(vektor_pregleda.size() == 0){
        throw std::range_error("Prazna kolekcija");
    }
    for(int i=0; i<vektor_pregleda.size(); i++){
        if(vektor_pregleda[i]->DajImePacijenta() == ime_pacijenta){
            vektor_pregleda[i] = nullptr;
            vektor_pregleda.erase(vektor_pregleda.begin() + i);
            i--;
        }
    }
}

// Ispisi
void Pregledi::IspisiPregledNaDatum(Datum &datum) const{ 
    Pregledi tmp;
    
    // prolazi kroz sve preglede i poredi datum
    for(int i=0; i<vektor_pregleda.size(); i++){
        Datum dat1 = vektor_pregleda[i]->DajDatumPregleda();
        Datum dat2 = datum;
        
        std::tuple<int,int,int> dt1 = dat1.Ocitaj();
        std::tuple<int,int,int> dt2 = dat2.Ocitaj();
        
        if(std::get<0>(dt1) == std::get<0>(dt2)
        && std::get<1>(dt1) == std::get<1>(dt2)
        && std::get<2>(dt1) == std::get<2>(dt2)){
            tmp.RegistrirajPregled(vektor_pregleda[i]->DajImePacijenta(), vektor_pregleda[i]->DajDatumPregleda(), vektor_pregleda[i]->DajVrijemePregleda());
        }
    }

    int brojP = tmp.vektor_pregleda.size();

    for(int i=0; i<brojP; i++){
        tmp.DajNajranijiPregled().Ispisi();
        tmp.ObrisiNajranijiPregled();
    }
}

// Prijateljska
bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    Datum dat1 = p1.DajDatumPregleda();
    Datum dat2 = p2.DajDatumPregleda();
    
    std::tuple<int,int,int> dt1 = dat1.Ocitaj();
    std::tuple<int,int,int> dt2 = dat2.Ocitaj();
    
    Vrijeme vri1 = p1.DajVrijemePregleda();
    Vrijeme vri2 = p2.DajVrijemePregleda();
    
    std::pair<int,int> vr1 = vri1.Ocitaj();
    std::pair<int,int> vr2 = vri2.Ocitaj();
    
    bool x(false);
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
    
    // TESTIRANI KOPIRAJUCI I OPERATORI DODJELE NA KRAJU PROGRAMA
    
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
	

    
    Pregledi pregledi;
    
    int tmp_brojac(0);	
	while(1){
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
	
	/* Datum datum1 (22,7,1996);
	Datum datum2 (1,1,2001);
	
	Vrijeme vrijeme1 (12,11);
	Vrijeme vrijeme2 (13,13);
	
	Pregled pregled1 ("Kerim", datum1, vrijeme1);
	Pregled pregled2 ("Irma", datum2, vrijeme2);
	
	Pregledi pregledi{pregled1, pregled2};
	
	pregledi.RegistrirajPregled("Mujo", 2,2,2002,2,2);
	
	Pregledi pregledi2 = pregledi;
	Pregledi pregledi3 = {pregled1, pregled2};
	Pregledi pregledi4 (pregledi2);
	
	pregledi.IspisiSvePreglede();
	pregledi2.IspisiSvePreglede();
	pregledi3.IspisiSvePreglede();
	pregledi4.IspisiSvePreglede();*/
	
	
	return 0; 
}