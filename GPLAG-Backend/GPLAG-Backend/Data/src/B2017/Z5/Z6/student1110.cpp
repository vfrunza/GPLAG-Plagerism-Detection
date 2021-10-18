/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;

class Berza {
    int min,max;
    vector<int> cijene;
    public:
    Berza(int min, int max);
    explicit Berza(int max);
    Berza RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena(){return (cijene.size());}
    void BrisiSve(){cijene.resize(0);}
    int DajMinimalnuCijenu();
    int DajMaksimalnuCijenu();
    bool operator !() const { if(cijene.size()==0) return true; return false;}
    int DajBrojCijenaVecihOd(int c);
    void Ispisi() const;    
    int operator[](int i) const;
    Berza &operator ++();
    Berza &operator --();
    Berza operator++(int);
    Berza operator--(int);
    Berza operator-();
    Berza operator+(int x);
    Berza operator-(int x);
    Berza operator+(Berza x);
    Berza operator-(Berza x);
    friend Berza operator-(Berza y,Berza x);
    Berza &operator +=(const Berza &x) {
        transform(cijene.begin(),cijene.end(),x.cijene.begin(),cijene.begin(),plus<int>());
        if(!count_if(cijene.begin(),cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
    }
    Berza &operator -=(const Berza &x) {
        transform(cijene.begin(),cijene.end(),x.cijene.begin(),cijene.begin(),minus<int>());
        if(!count_if(cijene.begin(),cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
    }
    bool operator==( Berza &x) {
        return (this->DajBrojRegistriranihCijena()==x.DajBrojRegistriranihCijena() && equal(cijene.begin(),cijene.end(),x.cijene.begin()));
    }
    bool operator !=(Berza &x) {
        return !(*this==x);
    }
};
    Berza::Berza(int min, int max) {
        if(min<=0 || max<=0) throw range_error("Ilegalne granicne cijene");
        this->min=min; this->max=max;
    }
    Berza::Berza(int max) {
        if(max<=0) throw range_error("Ilegalne granicne cijene");
        this->min=0; this->max=max;
    }
    Berza Berza::RegistrirajCijenu(int cijena) {
        if(cijena<min || cijena>max) throw range_error("Ilegalna cijena");
        cijene.push_back(cijena);
        return *this;
    }
    int Berza::DajMinimalnuCijenu() {
        if(cijene.size()==0) throw range_error("Nema registriranih cijena");
        return *min_element(cijene.begin(),cijene.end());
    }
    int Berza::DajMaksimalnuCijenu() {
        if(cijene.size()==0) throw range_error("Nema registiranih cijena");
        return *max_element(cijene.begin(), cijene.end());
    }
    int Berza::DajBrojCijenaVecihOd(int c) {
        if(cijene.size()==0) throw range_error("Nema registriranih cijena");
        return count_if(cijene.begin(),cijene.end(),bind(greater<int>(),placeholders::_1,c));
    }
    void Berza::Ispisi() const { 
        vector<int> novi(cijene);
        sort(novi.begin(),novi.end(),greater<int>());
        for(auto it=novi.begin(); it!=novi.end();it++ ) {
            cout<<setprecision(2)<<fixed<<(double)(*it/100)<<endl;
        }
    }
    int Berza::operator[] (int i) const {
        if(i<0 || i>cijene.size()) throw range_error("Neispravan indeks");
        return cijene[i];
    }
  Berza& Berza::operator ++() {
        transform(cijene.begin(),cijene.end(),cijene.begin(),bind(plus<int>(),placeholders::_1,1));
        
        if(!count_if(cijene.begin(),cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
   return *this;
    } 
    Berza& Berza::operator--() {
        transform(cijene.begin(),cijene.end(),cijene.begin(),bind(minus<int>(),placeholders::_1,1));
        if(!count_if(cijene.begin(),cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
   return *this;
    }
    
    Berza Berza::operator++(int) {
        Berza pom(*this);
        ++pom;
        return pom;
    }
    Berza Berza::operator--(int) {
        Berza pom(*this);
        ++pom;
        return pom;
    }
    
    Berza Berza::operator-(){
        Berza novi(*this);
        int zbir=max+min;
        transform(cijene.begin(),cijene.end(),novi.cijene.begin(),bind(minus<int>(),zbir,placeholders::_1));
        return novi;
    }
    Berza Berza::operator+(int x) { 
        Berza novi(*this);
        transform(cijene.begin(),cijene.end(),novi.cijene.begin(), bind(plus<int>(),placeholders::_1,x));
        if(!count_if(novi.cijene.begin(),novi.cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return novi;
    }
    Berza Berza::operator-(int x){
        Berza novi(*this);
        transform(cijene.begin(),cijene.end(),novi.cijene.begin(),bind(minus<int>(),x,placeholders::_1));
        if(!count_if(novi.cijene.begin(),novi.cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return novi;
    }

    Berza Berza::operator+(Berza x) {
        Berza novi(x);
        transform(cijene.begin(),cijene.end(),x.cijene.begin(),novi.cijene.begin(),plus<int>());
        if(!count_if(novi.cijene.begin(),novi.cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return novi;
    }
    Berza Berza::operator-(Berza x){
        Berza novi(x);
        transform(cijene.begin(),cijene.end(),x.cijene.begin(),novi.cijene.begin(),minus<int>());
        if(!count_if(novi.cijene.begin(),novi.cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return novi;
    }
 /*   Berza operator-(Berza y, Berza x) {
        if(y.DajBrojRegistriranihCijena()!=x.DajBrojRegistriranihCijena() || y.DajMaksimalnuCijenu()!=x.DajMaksimalnuCijenu() || y.DajMinimalnuCijenu()!=x.DajMinimalnuCijenu()) throw domain_error("Nesaglasni operandi"); 
        Berza novi(y);
        transform(y.cijene.begin(),y.cijene.end(),x.cijene.begin(),novi.cijene.begin(),bind(minus<int>(),y,placeholders::_1));
       // if(!count_if(novi.cijene.begin(),novi.cijene.end(),bind(greater<int>(),placeholders::_1,max))) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return novi;
    }
    */
    
    
int main ()
{
    Berza x(10,1000),y(10,1000);
    try{
    x.RegistrirajCijenu(50);
    x.RegistrirajCijenu(30);
    y.RegistrirajCijenu(50);
    y.RegistrirajCijenu(30);
    y.RegistrirajCijenu(1000);
    y++;
    Berza z=x+y;
    cout<<"Registrirano je: "<<z.DajBrojRegistriranihCijena();
    z.Ispisi();
    }
    catch(range_error x) {
        cout<<x.what();
    }
    catch(domain_error x) {
        cout<<x.what();
    }
	return 0;
}
