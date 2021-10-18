/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
class Berza
{   int min, max;
    vector<int> v;
public:
    Berza(int mini, int maxi){
        if(mini<=0 || maxi<=0) throw range_error("Ilegalne granice cijene");
        min = mini;
        max = maxi;
    }
    
    explicit Berza(int maxi){
        if(maxi <= 0) throw range_error("Ilegalne granice cijene");
        min = 0;
        max = maxi;
    }
    void RegistrirajCijenu(int cijena){
        if(cijena > max || cijena < min) throw range_error("Ilegalna cijena");
        v.push_back(cijena);
    }
    int DajBrojRegistriranihCijena(){
        return v.size();
    }
    void BrisiSve(){
        v.resize(0);
    }
    int DajMinimalnuCijenu(){
         if(v.size()==0) throw range_error("Nema registriranih cijena");
        return *min_element(v.begin(), v.end());
    }
    int DajMaksimalnuCijenu(){
        if(v.size()==0) throw range_error("Nema registriranih cijena");
        return *max_element(v.begin(), v.end());
    }
    bool operator !(){
        if(v.size() == 0) return true;
        if(v.size() > 0) return false;
    }
    int DajBrojCijenaVecihOd(int c){
        if(v.size()==0) throw range_error("Nema registriranih cijena");
        return count_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, c));
    }
    void Ispisi() const{
        sort(v.begin(), v.end(), [](int x, int y){
            return x > y;
        });
        for_each(v.begin(), v.end(), [](double x){
            x/=10;
            cout << setprecision(2) << x;
        });
    }
    int operator [](int i) const{
        if(i<0 || i>v.size()) throw range_error("Neispravan indeks");
        return v[i];
    }
    
    
    
};
int main ()
{   Berza b(25);
int br;
    for(;;){
        
        cin >> br;
        if(br == -1) break;
        b.RegistrirajCijenu(br);
        
    }
    cout << "Maks: " << b.DajMaksimalnuCijenu();
    cout << "\nMin: " << b.DajMinimalnuCijenu();
    cout << "Unesi broj: "; cin >> br;
    cout << "\nBroj cijena vecih od broja: " << b.DajBrojCijenaVecihOd(br);
    b.Ispisi();
	return 0;
}
