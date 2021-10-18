#include <iostream> 
#include <stdexcept> 
#include <string>
class Datum{
    int day, month, year;
    public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan, mjesec, godina);
    } 
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        day=dan;
        month=mjesec;
        year=godina;
    } 
    int DajDan() const{
        return day;
    }
    int DajMjesec() const{
        return month;
    } 
    int DajGodinu() const{
        return year;
    } 
    void Ispisi() const{
        std::cout << day << "/" << month << "/" << year;
    }
}; 
class Kupac{ 
    std::string ip;
    Datum datum;
    public: 
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){ 
        ip=ime_i_prezime;
        datum=datum_rodjenja;
    } 
    
};
int main ()
{ 
    std::cout << "Kompajlira se";
	return 0;
}