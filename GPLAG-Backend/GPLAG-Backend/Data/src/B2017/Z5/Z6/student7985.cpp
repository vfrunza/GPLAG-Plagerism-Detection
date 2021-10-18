/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <functional> // **
#include <iomanip>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::range_error;

class Berza{
    vector<int> v;
    int min, max;
    static void BaciRange() { throw range_error("Ilegalne granicne cijene"); }
    static void BaciRange2() { throw range_error("Nema registriranih cijena"); }
    void TestIndeksa(int indeks) const {
        if(indeks < 1 || indeks > v.size()) throw range_error("Neispravan indeks");
    }
  public:
    Berza(int min, int max) : min(min), max(max) {
        if(min <= 0 || max <= 0) BaciRange();
    }
    explicit Berza(int max) :  min(0), max(max) {
        if(max <= 0) BaciRange();
    }
    void RegistrirajCijenu(int nova){
        if(nova < min || nova > max) throw range_error("Ilegalna cijena");
        v.push_back(nova); // **
    }
    int DajBrojRegistriranihCijena() const {
        return v.size();
    }
    void BrisiSve(){
        v.resize(0);
        min = 0; max = 0; // **
    }
    int DajMinimalnuCijenu() const {
        auto pok_min(std::min_element(v.begin(), v.end()) );
        if(pok_min == v.end()) BaciRange2();
        return *pok_min;
    }
    int DajMaksimalnuCijenu() const {
        auto pok_max(std::max_element(v.begin(), v.end()));
        if(pok_max == v.end()) BaciRange2();
        return *pok_max;
    }
    bool operator !() const{
        return DajBrojRegistriranihCijena() == 0;
    }
    int DajBrojCijenaVecihOd(int x) const {
        if(DajBrojRegistriranihCijena() == 0) BaciRange2();
        return std::count_if(v.begin(), v.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, x));
    }
    void Ispisi() const {
        vector<int> pom_v(v);
        std::sort(pom_v.begin(), pom_v.end(), std::greater<int>());
        std::for_each(pom_v.begin(), pom_v.end(), [](int vr){
            cout << std::fixed << std::setprecision(2) << vr/100. << endl;
        });
    }
    int operator[](int indeks) const {
        TestIndeksa(indeks);
        return v[indeks-1];
    }
};


int main ()
{
    
    Berza b(2, 300);
    b.RegistrirajCijenu(40);
    b.RegistrirajCijenu(22);
    b.RegistrirajCijenu(33);
    b.Ispisi();
	return 0;
}
