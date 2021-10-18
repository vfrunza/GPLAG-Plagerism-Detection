/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>

void Testiraj(int dan, int mjesec, int godina){
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        brojdana[1]++;
    if(godina < 1800 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > brojdana[mjesec-1])
        throw std::domain_error("Nelegalan datum");
}

int Pretvorba(int dan, int mjesec, int godina){
    int dani, pomocna(mjesec);
    if(mjesec <= 2) pomocna+=12;
    dani = (dan + 13 * (pomocna + 1) / 5 + godina + godina / 4 + godina / 400 - godina / 100) % 7;
    if (dani == 1) dani = 7;
    else dani--;
    if(pomocna >= 13) dani--;
    return dani;
}


class Datum{
    int dan, mjesec, godina;
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

    Datum(int dan, int mjesec, int godina);
    
    Datum(int dan, Mjeseci mjesec, int godina);
    
    void Postavi(int dan, int mjesec, int godina);
    
    void Postavi(int dan, Mjeseci mjesec, int godina);
    
    int DajDan() const{ return dan; }
    
    Mjeseci DajMjesec() const{ return static_cast<Mjeseci>(mjesec); }
    
    int DajGodinu() const{ return godina; }
    
    char* DajImeMjeseca() const;
    
    Dani DanUSedmici() const{ return static_cast<Dani>(Pretvorba(dan, mjesec, godina)); }
    
    char* DajImeDanaUSedmici() const;
    
    Datum& PostaviNormalizirano(Datum &datum);
    
    void Naprijed(){ Datum::dan++; }
    void Nazad(){ Datum::dan--; }
    
    friend Datum &operator ++(Datum &prvo);
    friend Datum &operator ++(Datum &prvo, int);
    friend Datum &operator --(Datum &prvo);
    friend Datum &operator --(Datum &prvo, int);
    
    friend Datum operator +(const Datum& prvo, const int& zakoliko);
    friend Datum operator -(const Datum& prvo, const int& zakoliko);
    
    friend Datum& operator +=(Datum& prvo, const int& zakoliko);
    friend Datum& operator -=(Datum& prvo, const int& zakoliko);
    
    friend Datum operator -(const Datum& prvo, const Datum& drugo);
    
    friend bool operator ==(const Datum& prvo, const Datum& drugo);
    friend bool operator !=(const Datum& prvo, const Datum& drugo);
    friend bool operator <(const Datum& prvo, const Datum& drugo);
    friend bool operator >(const Datum& prvo, const Datum& drugo);
    friend bool operator <=(const Datum& prvo, const Datum& drugo);
    friend bool operator >=(const Datum& prvo, const Datum& drugo);
    
    friend std::ostream &operator <<(std::ostream &tok, const Datum &prvo);
    friend std::istream &operator >>(std::istream &ulaz, Datum &prvo);
    static std::string dani[];
    static std::string mjeseci[];
    
    operator std::string();
    explicit operator int();
    
};

std::string Datum::mjeseci[]{ "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
std::string Datum::dani[]{ "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};

Datum::Datum(int dan, int mjesec, int godina){
    Testiraj(dan, mjesec, godina);
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
    
Datum::Datum(int dan, Mjeseci mjesec, int godina){
    Testiraj(dan, mjesec, godina);
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
    
void Datum::Postavi(int dan, int mjesec, int godina){
    Testiraj(dan, mjesec, godina);
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
    
void Datum::Postavi(int dan, Mjeseci mjesec, int godina){
    Testiraj(dan, mjesec, godina);
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
    
char* Datum::DajImeMjeseca() const{
    return &mjeseci[mjesec-1][0]; 
}
    
char* Datum::DajImeDanaUSedmici() const{
    return &dani[DanUSedmici()-1][0]; 
}

Datum& Datum::PostaviNormalizirano(Datum &datum){
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(;;){
        if(datum.mjesec >= 1 && datum.mjesec <= 12) break;
        if(datum.mjesec < 1){ datum.mjesec += 12; datum.godina--; }
        else if(datum.mjesec > 12){ datum.mjesec -= 12; datum.godina++; }
    }
    if(datum.dan < 1){
        for(;;){
            if(datum.mjesec == 1){ datum.mjesec = 13; datum.godina--;}
            if(datum.dan >= 1 && datum.dan <= brojdana[datum.mjesec-1]) break;
            datum.dan += brojdana[datum.mjesec - 2];
            datum.mjesec--;
            if(datum.mjesec <= 1){
                datum.mjesec = 12; datum.godina--; 
                if((datum.godina % 4 == 0 && datum.godina % 100 != 0) || datum.godina % 400 == 0)
                    brojdana[1] = 29;
                else brojdana[1] = 28;
            }
        }
    }
    else if(datum.dan > brojdana[datum.mjesec - 1]){
        for(;;){
            if(datum.dan >= 1 && datum.dan <= brojdana[datum.mjesec-1]) break;
            datum.dan -= brojdana[datum.mjesec - 1];
            datum.mjesec++;
            if(datum.mjesec > 11){ 
                datum.mjesec = 1; datum.godina++; 
                if((datum.godina % 4 == 0 && datum.godina % 100 != 0) || datum.godina % 400 == 0)
                    brojdana[1] = 29;
                else brojdana[1] = 28;
            }
        }
    }
    if(datum.godina < 1800) throw std::domain_error("Nelegalan datum");
    return datum;
}

Datum &operator ++(Datum &prvo){
    prvo.Naprijed();
    return prvo.PostaviNormalizirano(prvo);
}

Datum &operator ++(Datum &prvo, int){
    prvo.Naprijed();
    return prvo.PostaviNormalizirano(prvo);
}

Datum &operator --(Datum &prvo){
    prvo.Nazad();
    return prvo.PostaviNormalizirano(prvo);
}

Datum &operator --(Datum &prvo, int){
    prvo.Nazad();
    return prvo.PostaviNormalizirano(prvo);
}

Datum operator +(const Datum& prvo, const int& zakoliko){
    Datum novi(prvo);
    novi.dan += zakoliko;
    return novi.PostaviNormalizirano(novi);
}

Datum operator -(const Datum& prvo, const int& zakoliko){
    Datum novi(prvo);
    novi.dan -= zakoliko;
    return novi.PostaviNormalizirano(novi);
}

Datum& operator +=(Datum& prvo, const int& zakoliko){
    prvo.dan = prvo.dan + zakoliko;
    return prvo.PostaviNormalizirano(prvo);
}

Datum& operator -=(Datum& prvo, const int& zakoliko){
    prvo.dan = prvo.dan - zakoliko;
    return prvo.PostaviNormalizirano(prvo);
}

Datum operator -(const Datum& prvo, const Datum& drugo){
    Datum novi(prvo);
    novi.dan -= drugo.dan; novi.godina -= drugo.godina; novi.mjesec -= drugo.mjesec;
    return novi.PostaviNormalizirano(novi);
}

bool operator ==(const Datum& prvo, const Datum& drugo){
    return (prvo.dan == drugo.dan && prvo.mjesec == drugo.mjesec && prvo.godina == drugo.godina);
}

bool operator !=(const Datum& prvo, const Datum& drugo){
    return (prvo.dan != drugo.dan || prvo.mjesec != drugo.mjesec || prvo.godina != drugo.godina);
}

bool operator <(const Datum& prvo, const Datum& drugo){
    if(prvo.godina < drugo.godina) return true;
    if(prvo.godina == drugo.godina && prvo.mjesec < drugo.mjesec) return true;
    if(prvo.godina == drugo.godina && prvo.mjesec == drugo.mjesec && prvo.dan < drugo.dan) return true;
    return false;
}

bool operator >(const Datum& prvo, const Datum& drugo){
    if(prvo.godina < drugo.godina) return false;
    if(prvo.godina == drugo.godina && prvo.mjesec < drugo.mjesec) return false;
    if(prvo.godina == drugo.godina && prvo.mjesec == drugo.mjesec && prvo.dan < drugo.dan) return false;
    return true;
}

bool operator <=(const Datum& prvo, const Datum& drugo){
    if(prvo == drugo) return true;
    if(prvo.godina < drugo.godina) return true;
    if(prvo.godina == drugo.godina && prvo.mjesec < drugo.mjesec) return true;
    if(prvo.godina == drugo.godina && prvo.mjesec == drugo.mjesec && prvo.dan < drugo.dan) return true;
    return false;
}

bool operator >=(const Datum& prvo, const Datum& drugo){
    if(prvo == drugo) return true;
    if(prvo.godina < drugo.godina) return false;
    if(prvo.godina == drugo.godina && prvo.mjesec < drugo.mjesec) return false;
    if(prvo.godina == drugo.godina && prvo.mjesec == drugo.mjesec && prvo.dan < drugo.dan) return false;
    return true;
}

std::ostream &operator <<(std::ostream &tok, const Datum &prvo){
    tok << prvo.dan << "." << prvo.DajImeMjeseca() << prvo.DajGodinu() << ".(" << prvo.DajImeDanaUSedmici() << ")";
    return tok;
}

std::istream &operator >>(std::istream &ulaz, Datum &prvo){
    //std::cout << prvo;
    std::string novi;
    std::string dan1, mjesec1, godina1;
    int brojac1(0), brojac2(0);
    ulaz >> novi;
    bool test1(false), test2(false);
    for(auto i : novi){
        if(brojac2 == 0) dan1.push_back(i);
        else if(brojac2 == 1) mjesec1.push_back(i);
        else if(brojac2 == 2) godina1.push_back(i);
        if(i < '0' || i > '9'){
            if(i != '/'){
                ulaz.setstate(std::ios_base::failbit);
                //std::cout << "pozvana";
                break;
            }
            else if(test1 || test2){
                if(test2){ ulaz.setstate(std::ios_base::failbit); break; }
                if(test1) brojac2++;    
                //std::cout << "pozvana" << std::endl;
                test1 = false;
                test2 = true;
            }
        }
        else {if(!test1) brojac1++; test1 = true; test2 = false;}
        //if(brojac1 == 2 && test1 == true) brojac2++;
    }
    if(brojac1 != 3 || brojac2 != 2) ulaz.setstate(std::ios_base::failbit);
    if(ulaz){
        //std::cout << brojac1 << " " << brojac2;
        dan1.pop_back();
        mjesec1.pop_back();
        //std::cout << dan1 << " " << mjesec1 << " " << godina1;
        Testiraj(std::stoi(dan1), std::stoi(mjesec1), std::stoi(godina1));
        prvo.Postavi(std::stoi(dan1), std::stoi(mjesec1), std::stoi(godina1));
    }
    return ulaz;
}

Datum::operator std::string(){
    std::string pomocna;
    pomocna += std::to_string((*this).dan);
    pomocna += "."; 
    pomocna += (*this).DajImeMjeseca();
    pomocna += std::to_string((*this).DajGodinu());
    pomocna += ".(";
    pomocna += (*this).DajImeDanaUSedmici();
    pomocna += ")";
    return pomocna;
}

Datum::operator int(){
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int suma(0);
    for(int i = 1800; i <= (*this).godina; i++)
        if(i < (*this).godina) {
            for(int j = 0; j < 12; j++){
                if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                    brojdana[1] = 29;
                else brojdana[1] = 28;
                suma += brojdana[j];
            }
        }
        else for(int j = 0; j < (*this).mjesec; j++){
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                    brojdana[1] = 29;
                else brojdana[1] = 28;
                suma += brojdana[j];
        }
            
    if(((*this).godina % 4 == 0 && (*this).godina % 100 != 0) || (*this).godina % 400 == 0)
        brojdana[1] = 29;
    else brojdana[1] = 28;
    suma += (*this).DajDan() - brojdana[(*this).mjesec-1];
    return suma;
}
    

int main ()
{
    //std::string mjeseci[]{ "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    //auto novo = static_cast<Mjeseci>(7);
    //std::cout << mjeseci[novo];
    
    Datum neki(1,1,1801), neki1(9,1,2018);
    //Datum novi;
    //std::cout << neki;
    //std::cin >> neki;
    //std::cout << neki;
    neki--;
    std::cout << neki;
    
	return 0;
}
