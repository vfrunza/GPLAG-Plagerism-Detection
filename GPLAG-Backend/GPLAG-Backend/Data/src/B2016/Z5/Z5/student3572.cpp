#include <iostream>
#include <ostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

class Temperature {
    int min_ogranicenje, max_ogranicenje;
    list<int> min_dnevna, max_dnevna;
    public:
    Temperature (int min, int max) {
        if(max<min) throw range_error("Nekorektne temperature");
        min_ogranicenje=min;
        max_ogranicenje=max;
    }
    Temperature (const Temperature& temp) {
        min_ogranicenje=temp.min_ogranicenje;
        max_ogranicenje=temp.max_ogranicenje;
        min_dnevna.assign(temp.min_dnevna.begin(), temp.min_dnevna.end());
        max_dnevna.assign(temp.max_dnevna.begin(), temp.max_dnevna.end());
    }
    void RegistrirajTemperature (pair<int,int> nove) {
        if(nove.first<min_ogranicenje or nove.second>max_ogranicenje or nove.second<nove.first) throw range_error("Nekorektne temperature");
        min_dnevna.push_back(nove.first);
        max_dnevna.push_back(nove.second);
    }
    void BrisiSve () {
        min_dnevna.clear();
        max_dnevna.clear();
    }
    void BrisiNegativne () { // mozda i ovo moras preko algoritma
        int brojac(0);
        auto pok(max_dnevna.begin());
        for(auto i=min_dnevna.begin(); i!=min_dnevna.end(); i++) {
            if(*i<0) {
                min_dnevna.erase(i);
                break;
            }
            brojac++;
        }
        
        if(brojac!=min_dnevna.size()) {
             for(int i=0; i<brojac; i++) {
                pok++;
            }
            
             max_dnevna.erase(pok);
        }
    }
    int DajBrojRegistriranih () const {
        if(min_dnevna.empty()) throw logic_error("Nema registriranih temperatura");
        return min_dnevna.size();
    }
    int DajMaksimalnuTemperaturu () const {
        if(max_dnevna.empty()) throw logic_error("Nema registriranih temperatura");
        auto it(max_element(max_dnevna.begin(), max_dnevna.end()));
        return *it;
    }
    int DajMinimalnuTemperaturu() const {
        if(min_dnevna.empty()) throw logic_error("Nema registriranih temperatura");
        auto it(min_element(min_dnevna.begin(), min_dnevna.end()));
        return *it;
    }
    int DajBrojTemperaturaVecihOd (int od_ovog_veci) const {
        if(min_dnevna.empty()) throw logic_error("Nema registriranih temperatura");
        return count_if( max_dnevna.begin(), max_dnevna.end(), bind (greater<int>(), od_ovog_veci, placeholders::_1));
    }
    int DajBrojTemperaturaManjihOd (int od_ovog_manji) const {
        if(min_dnevna.empty()) throw logic_error("Nema registriranih temperatura");
        return count_if( min_dnevna.begin(), min_dnevna.end(), bind (less<int>(), od_ovog_manji, placeholders::_1));
    }
    
    const pair<int,int> operator[] (int x) const;
    friend bool Netacnost (const Temperature& temp);
    friend bool operator! (const Temperature& temp);
    friend bool operator== (const Temperature& t1, const Temperature& t2);
    friend bool operator!= (const Temperature& t1, const Temperature& t2);
    friend ostream& operator<< (ostream& tok, const Temperature& temp);
    friend Temperature& operator++ (Temperature& temp);
    friend Temperature& operator-- (Temperature& temp);
    friend Temperature operator++ (Temperature& temp, int);
    friend Temperature operator-- (Temperature& temp, int);
    friend vector<int> operator* (const Temperature& temp);
    friend vector<int> operator+ (const Temperature& temp);
    friend vector<int> operator- (const Temperature& temp);
    friend Temperature operator+ (Temperature temp, int koliko);
    friend Temperature operator+ (int koliko, Temperature temp);
    friend Temperature operator- (Temperature temp, int koliko);
    friend Temperature operator- (int koliko, Temperature temp);
    friend Temperature operator+= (Temperature temp, int koliko);
    friend Temperature operator-= (Temperature temp, int koliko);
    
   
};


Temperature operator+ (Temperature temp, int koliko) {
    transform(temp.min_dnevna.begin(), temp.min_dnevna.end(), temp.min_dnevna.begin(), bind(plus<int>(), koliko, placeholders::_1));
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), temp.max_dnevna.begin(), bind(plus<int>(), koliko, placeholders::_1));
    if(Netacnost(temp)) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}

Temperature operator+ (int koliko, Temperature temp) {
    return temp+koliko;
}

Temperature operator- (int koliko, Temperature temp) {
    int zapamti(temp.max_ogranicenje);
    temp.max_ogranicenje=temp.min_ogranicenje;
    temp.min_ogranicenje=zapamti;
    
    transform(temp.min_dnevna.begin(), temp.min_dnevna.end(), temp.min_dnevna.begin(), bind(minus<int>(), abs(koliko), placeholders::_1));
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), temp.max_dnevna.begin(), bind(minus<int>(), abs(koliko), placeholders::_1));
    if(Netacnost(temp)) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}

Temperature operator- (Temperature temp, int koliko) {
    return temp+(-koliko);
}

Temperature operator+= (Temperature temp, int koliko) {
    return temp+koliko;
}
Temperature operator-= (Temperature temp, int koliko) {
    return temp-koliko;
}

bool Netacnost (const Temperature& temp) {
        int broj_netacnih1(count_if(temp.min_dnevna.begin(), temp.min_dnevna.end(), bind(less<int>(), temp.min_ogranicenje, placeholders::_1)));
        if(broj_netacnih1>0) return false;
        int broj_netacnih2(count_if(temp.max_dnevna.begin(), temp.max_dnevna.end(), bind(greater<int>(), temp.max_ogranicenje, placeholders::_1)));
        if(broj_netacnih2>0) return false;
        return true;
    }

bool operator== (const Temperature& t1, const Temperature& t2) {
    return(t1.max_ogranicenje==t2.max_ogranicenje and t1.min_ogranicenje==t2.max_ogranicenje and t1.max_dnevna.size()==t2.max_dnevna.size()
    and t1.min_dnevna.size()==t2.min_dnevna.size() and t1.max_dnevna==t2.max_dnevna and t1.min_dnevna==t2.min_dnevna);
}

bool operator!= (const Temperature& t1, const Temperature& t2) {
    return(t1.max_ogranicenje!=t2.max_ogranicenje or t1.min_ogranicenje!=t2.max_ogranicenje or t1.max_dnevna.size()!=t2.max_dnevna.size()
    or t1.min_dnevna.size()!=t2.min_dnevna.size() or t1.max_dnevna!=t2.max_dnevna or t1.min_dnevna!=t2.min_dnevna);
}

vector<int> operator+ (const Temperature& temp) {
    vector<int> bile_manje_za(temp.max_dnevna.size());
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), bile_manje_za.begin(), bind(minus<int>(), abs(temp.max_ogranicenje), placeholders::_1));
    return bile_manje_za;
}

vector<int> operator- (const Temperature& temp) {
    vector<int> bile_vece_za(temp.min_dnevna.size());
    transform(temp.min_dnevna.begin(), temp.min_dnevna.end(), bile_vece_za.begin(), bind(minus<int>(), abs(temp.min_ogranicenje), placeholders::_1));
    return bile_vece_za;
}

vector<int> operator* (const Temperature& temp) {
    vector<int> razlika(temp.min_dnevna.size()); 
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), temp.min_dnevna.begin(), razlika.begin(), minus<int>());
    return razlika;
}

Temperature& operator++ (Temperature& temp) {
    transform(temp.min_dnevna.begin(), temp.min_dnevna.end(), temp.min_dnevna.begin(), bind(plus<int>(), 1, placeholders::_1));
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), temp.max_dnevna.begin(), bind(plus<int>(), 1, placeholders::_1));
    if(Netacnost(temp)) throw logic_error("Ilegalna operacija");
    return temp;
}

Temperature operator++ (Temperature& temp, int) {
    Temperature kopija(temp);
    ++temp;
    return kopija;
}

Temperature& operator-- (Temperature& temp) {
    transform(temp.min_dnevna.begin(), temp.min_dnevna.end(), temp.min_dnevna.begin(), bind(plus<int>(), -1, placeholders::_1));
    transform(temp.max_dnevna.begin(), temp.max_dnevna.end(), temp.max_dnevna.begin(), bind(plus<int>(), -1, placeholders::_1));
    if(Netacnost(temp)) throw logic_error("Ilegalna operacija");
    return temp;
}

Temperature operator-- (Temperature& temp, int) {
    Temperature kopija(temp);
    --temp;
    return kopija;
}

const pair<int,int> Temperature::operator[] (int x) const {
    if(x>min_dnevna.size() or x<=0) throw range_error("Neispravan indeks");
    auto minimalni(min_dnevna.begin()), maksimalni(max_dnevna.begin());
    advance(minimalni, x);
    advance(maksimalni, x);
    return make_pair(*minimalni,*maksimalni);
}

bool operator! (const Temperature& temp) {
    return temp.min_dnevna.empty();
}

ostream& operator<< (ostream& tok, const Temperature& temp) {
    copy(temp.min_dnevna.begin(), temp.min_dnevna.end(), ostream_iterator<int>(tok, " "));
    tok << endl;
    copy(temp.max_dnevna.begin(), temp.max_dnevna.end(), ostream_iterator<int>(tok, " "));
    return tok;
}


int main ()
{
	return 0;
}