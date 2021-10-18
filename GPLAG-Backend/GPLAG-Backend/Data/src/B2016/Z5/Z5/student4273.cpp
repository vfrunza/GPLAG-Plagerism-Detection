/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cin; using std::cout; using std::endl;

/*class Ispis {
    int el;
    public:
    Ispis(int::iterator x) : el(*x) { cout << el; }
};*/

class Temperature {
    std::list<int> minimalne, maksimalne;
    int min_doz, max_doz;
    public:
    Temperature(int min, int maks);
    void RegistrirajTemperature (std::pair<int, int> par_temp) {
        if (par_temp.first<min_doz || par_temp.second>max_doz || par_temp.first>par_temp.second) throw std::range_error("Nekorektne temperature");
        minimalne.push_back(par_temp.first);
        maksimalne.push_back(par_temp.second);
    }
    void BrisiSve() { minimalne.clear(); maksimalne.clear(); }
    void BrisiNegativneTemperture();
    int DajBrojRegistriranihTemperatura() { return minimalne.size()+maksimalne.size(); }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int temp);
    int DajBrojTemperaturaManjihOd(int temp);
    bool operator !(); //const Temperature &t
    std::pair<int,int> operator [](int i) const;
    //Postfiksni
    friend Temperature operator ++(Temperature &t, int);
    friend Temperature operator --(Temperature &t, int);
    //Prefiksni
    friend Temperature &operator ++(Temperature &t);
    friend Temperature &operator --(Temperature &t);
    friend std::vector<int> operator *(Temperature &t);
    friend std::vector<int> operator +(Temperature &t);
    friend std::vector<int> operator -(Temperature &t);
    friend Temperature operator+(Temperature t, int broj);
    friend Temperature operator -(Temperature t, int broj);
    friend Temperature operator+(int broj, Temperature t);
    friend Temperature operator -(int broj, Temperature t);
    friend std::ostream &operator << (std::ostream &tok, const Temperature &t);
};

Temperature::Temperature(int min, int maks) : minimalne(), maksimalne() {
    if (min>maks) throw std::range_error("Nekorektne temperature");
    min_doz=min; max_doz=maks;
}
/*
void Temperature::BrisiNegativneTemperture() {
    auto it(maksimalne.begin());
    std::copy_if(minimalne.begin(), minimalne.end(), minimalne.begin() [&it] (int x) { 
        auto it1(it);
        //cout << x << " " << *it1 << endl << bool(x<0) << " " << bool(*it1<0) << endl; 
        if (x<0 && (*it1)<0) {
            it=
            return true;
        }
        return false; 
    });
    //std::remove_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), 0));
}*/

int Temperature::DajMinimalnuTemperaturu() {
    if (minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return *(std::min_element(minimalne.begin(), minimalne.end()));
}
int Temperature::DajMaksimalnuTemperaturu() {
    if (maksimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return *(std::max_element(maksimalne.begin(), maksimalne.end()));
}

int Temperature::DajBrojTemperaturaVecihOd(int temp) {
    if (minimalne.size()==0 && maksimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    //int br1(std::count_if(minimalne.begin(), minimalne.end(), [temp] (int x) { return x>temp; }));
    //int br2(std::count_if(maksimalne.begin(), maksimalne.end(), [temp] (int x) { return x>temp; }));
    int br1(std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp)));
    int br2(std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp)));
    return br1+br2;
}
int Temperature::DajBrojTemperaturaManjihOd(int temp) {
    if (minimalne.size()==0 && maksimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    //int br1(std::count_if(minimalne.begin(), minimalne.end(), [temp] (int x) { return x<temp; }));
    //int br2(std::count_if(maksimalne.begin(), maksimalne.end(), [temp] (int x) { return x<temp; }));
    int br1(std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temp)));
    int br2(std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temp)));
    return br1+br2;
}

bool Temperature::operator !() {
    if (minimalne.size()==0 && maksimalne.size()==0) return true;
    return false; 
}
//Unarni operatori “++” i“−−”povećavaju sve minimalne odnosno smanjuju sve maksimalne dnevne temperature za jedinicu. 
//Oba ili samo jedan?
//Postfiksni
Temperature operator ++(Temperature &t, int) {
    //Provjerimo da li ce doci do ilegalne operacije
    auto it(t.maksimalne.begin());
    int brojac_kriticnih(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, *it++)));
    int brojac_kriticnih2(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, t.max_doz-1)));
    if (brojac_kriticnih!=0 || brojac_kriticnih2!=0) throw std::logic_error("Ilegalna operacija");
    Temperature pomocni(t);
    std::transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    //std::for_each(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return pomocni;
}
Temperature operator --(Temperature &t, int) {
    Temperature pomocni(t);
    auto it(t.minimalne.begin());
    int brojac_kriticnih(std::count_if(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, *it++)));
    int brojac_kriticnih2(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, t.min_doz+1)));
    if (brojac_kriticnih!=0 || brojac_kriticnih2!=0) throw std::logic_error("Ilegalna operacija");
    //std::for_each(t.minimalne.begin(), t.minimalne.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    std::transform(t.maksimalne.begin(), t.maksimalne.end(), t.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return pomocni;
}
//Prefiksni
Temperature &operator ++(Temperature &t) {
    //Provjerimo da li ce doci do ilegalne operacije
    auto it(t.maksimalne.begin());
    int brojac_kriticnih(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, *it++)));
    int brojac_kriticnih2(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, t.max_doz-1)));
    if (brojac_kriticnih!=0 || brojac_kriticnih2!=0) throw std::logic_error("Ilegalna operacija");
    std::transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    //std::transform(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return t;
}
Temperature &operator --(Temperature &t) {
    auto it(t.minimalne.begin());
    int brojac_kriticnih(std::count_if(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, *it++)));
    int brojac_kriticnih2(std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, t.min_doz+1)));
    if (brojac_kriticnih!=0 || brojac_kriticnih2!=0) throw std::logic_error("Ilegalna operacija");
    //std::for_each(t.minimalne.begin(), t.minimalne.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    std::transform(t.maksimalne.begin(), t.maksimalne.end(), t.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return t;
}

std::vector<int> operator *(Temperature &t) {
    std::vector<int> rez(t.minimalne.size()); //Ispravi ovo!
    std::list<int>::iterator it(t.minimalne.begin());
    std::transform(t.maksimalne.begin(), t.maksimalne.end(), rez.begin(), std::bind(std::minus<int>(), std::placeholders::_1, *it++));
    return rez;
}

std::vector<int> operator +(Temperature &t) {
    std::vector<int> rez(t.maksimalne.size());
    std::transform(t.maksimalne.begin(), t.maksimalne.end(), rez.begin(), std::bind(std::minus<int>(), t.max_doz, std::placeholders::_1));
    return rez;
}

std::vector<int> operator -(Temperature &t) {
    std::vector<int> rez(t.minimalne.size());
    std::transform(t.minimalne.begin(), t.minimalne.end(), rez.begin(), std::bind(std::minus<int>(), std::placeholders::_1, t.min_doz));
    return rez;
}

std::pair<int,int> Temperature::operator [](int i) const {
    if (i<1 || i>maksimalne.size()) throw std::range_error ("Neispravan indeks"); //Numeracija od 1
    std::vector<int> vek(minimalne.size());
    std::copy(minimalne.begin(), minimalne.end(), vek.begin());
    int min(vek[i-1]);
    std::copy(maksimalne.begin(), maksimalne.end(), vek.begin());
    int maks(vek[i-1]);
    auto temp(std::make_pair(min,maks));
    return temp;
}

/*std::ostream &operator <<(std::ostream &tok, const Temperature &t) {
    //ovo treba izvesti bez petlji i pomoćnih funkcija
    std::for_each(t.minimalne.begin(), t.minimalne.end(), Ispis());
}*/
    
int main () {   
    Temperature temp(-40, 40);
    int min(0), maks(0);
    int n;
    cout << "Koliko temperatura zelite unijeti? ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Unesite minimalnu i maksimalnu temperaturu: ";
        cin >> min; cin >> maks;
        try {
            temp.RegistrirajTemperature(std::make_pair(min, maks));
        }
        catch(std::range_error i) {
            cout << "Izuzetak: " << i.what() << endl;
        }
    }
    try {
    cout << "Broj registriranih temperatura: " << temp.DajBrojRegistriranihTemperatura() << endl;
    cout << "Najmanja zabiljezena temperatura: " << temp.DajMinimalnuTemperaturu() << endl;
    cout << "Najveca zabiljezena temperatura: " << temp.DajMaksimalnuTemperaturu() << endl;
    cout << "Broj temperatura vecih od 15: " << temp.DajBrojTemperaturaVecihOd(15) << endl;
    cout << "Broj temperatura manjih od 15: " << temp.DajBrojTemperaturaManjihOd(15) << endl;
    //temp.BrisiNegativneTemperture();
    cout << "Broj registriranih temperatura(obje pozitivne): " << temp.DajBrojRegistriranihTemperatura() << endl;
    cout << "Broj registriranih temperatura: " << temp.DajBrojRegistriranihTemperatura() << endl;
	std::cout << "Drugi par temperatura: " <<  temp[2].first << " " << temp[2].second << endl;
	auto vek(+temp);
    for (int i=0; i<vek.size(); i++)
        cout << vek[i] << " ";
    cout << endl;
    auto vek2(-temp);
    for (int i=0; i<vek2.size(); i++)
        cout << vek2[i] << " ";
    cout << endl;
    auto vek3(*temp);
    for (int i=0; i<vek3.size(); i++)
        cout << vek3[i] << " ";
    cout << endl;
	temp++; 
	temp--;
	cout << "Najmanja zabiljezena temperatura: " << temp.DajMinimalnuTemperaturu() << endl;
    cout << "Najveca zabiljezena temperatura: " << temp.DajMaksimalnuTemperaturu() << endl;
    temp.BrisiSve();
    }
    catch (std::logic_error i) {
        cout << i.what() << endl;
    }
    catch (std::range_error i) {
        cout << i.what() << endl;
    }
	return 0;
}