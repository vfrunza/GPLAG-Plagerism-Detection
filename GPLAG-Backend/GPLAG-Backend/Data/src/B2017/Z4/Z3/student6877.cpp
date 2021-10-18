/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>

class Datum {
    int dan, mjesec, godina, test;
    public:
    Datum (int dan, int mjesec, int godina) { 
        this->Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        // uslov
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
 /*   std::tuple<int, int, int> Ocitaj() const {
        std::make_tuple    
    }*/
    void Ispisi() const {
        std::cout << this->dan << "/" << this->mjesec << "/" << this->godina << std::endl;
    }
};


class Vrijeme {
      
    public:
    Vrijeme(int sati, int minute);  
    void Postavi(int sati, int minute);  
    std::pair<int, int> Ocitaj () const;  
    void Ispisi() const; 
};

int main () {
    Datum datum(31, 5, 2018);
    datum.Ispisi();
    datum.Postavi(5, 88, 2232);
    datum.Ispisi();
    
	return 0;
}
