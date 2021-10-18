/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <functional>
using namespace std;

class Berza{
    vector<int> v;
    int mincijena, makscijena;
public:
    Berza(int nm, int nv){
        if(nm<0 || nv<0) throw range_error("Ilegalne granice cijene");
        mincijena=nm; makscijena=nv;
    }
    explicit Berza(int nv=0){
        if(nv<0) throw range_error("Ilegalne granice cijene");
        mincijena=0; makscijena=nv;
    }
    void RegistrirajCijenu(int n);
    int DajBrojRegistriranihCijena() const;
    void BrisiSve();
    int DajMinimalnuCijenu();
    int DajMaksimalnuCijenu();
    friend bool operator !(Berza b);
    int DajBrojCijenaVecihOd(int n);
    void Ispisi() const;
     friend Berza operator + (Berza b, int n);
    friend Berza operator - (Berza b, int n);
    friend Berza operator - (int n, Berza b);
    friend bool operator == (Berza b1, Berza b2);
    friend bool operator !=(Berza b1, Berza b2);
    friend Berza &operator +=(Berza &b, int n);
    friend Berza &operator -= (Berza &b, int n);
    friend Berza &operator ++ (Berza &b);
    friend Berza operator ++ (Berza &b, int);
    friend Berza operator - (Berza &b);
    int operator [] (int ind) const;
};

void Berza::BrisiSve(){
        v.resize(0);
    }

int Berza::DajBrojRegistriranihCijena() const
    {
        return v.size();
    }

int Berza::DajMinimalnuCijenu(){
        if(v.size()==0) throw range_error("Nema registriranih cijena");
        auto it = v.begin(); auto it1=v.end();
        int n= *min_element(it, it1, [](int a, int b){return a<b;});
        return n;

    }

int Berza::DajMaksimalnuCijenu()
    {
        if(v.size()==0) throw range_error("Nema registriranih cijena");
        auto it = v.begin(); auto it1=v.end();
        int n= *min_element(it, it1, [](int a, int b){return a>b;});
        return n;
    }

bool operator !(Berza b){ return b.v.size()==0;}

int Berza::DajBrojCijenaVecihOd(int n){
        if(v.size()==0) throw range_error("Nema registriranih cijena");
        return count_if(&v[0], &v[v.size()], bind(greater<int>(), placeholders::_1, n));

    }

void Berza::Ispisi() const{
        vector<int> v1 = v;
        auto it=v1.begin(); auto it1=v1.end();
        sort(it, it1, greater<int>());
        for(int i=0; i<v1.size(); i++)
        {
            double n=v1[i];
            cout<<setprecision(2)<<fixed<<n/100<<endl;
        }
    }

Berza operator + (Berza b, int n)
    {
        Berza b1(0, b.makscijena);
        vector<int> v1(b.v.size(), n);
        b1.v=v1;
        transform(&b.v[0], &b.v[b.v.size()], &b1.v[0], &b.v[0], plus<int>());
        if(count_if(&b.v[0], &b.v[b.v.size()-1], bind(greater<int>(), placeholders::_1, b.makscijena))>0) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return b;
    }

Berza operator + (int n, Berza b)
    {
        return b+n;
    }

Berza operator - (Berza b, int n)
    {
        Berza b1(0, b.makscijena);
        vector<int> v1(b.v.size(), n);
        b1.v=v1;
        transform(&b.v[0], &b.v[b.v.size()], &b1.v[0], &b.v[0], minus<int>());
        if(count_if(&b.v[0], &b.v[b.v.size()-1], bind(less<int>(), placeholders::_1, b.mincijena))>0) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return b;
    }

Berza operator - (int n, Berza b)
    {
        Berza b1(0, 99999999);
        vector<int> v1(b.v.size(), n);
        b1.v=v1;
        transform(&b1.v[0], &b1.v[b1.v.size()], &b.v[0], &b1.v[0], minus<int>());
        b1.mincijena=b.mincijena; b1.makscijena=b.makscijena;
        if(count_if(&b1.v[0], &b1.v[b1.v.size()-1], bind(less<int>(), placeholders::_1, b1.mincijena))>0) throw domain_error("Prekoracen dozvoljeni opseg cijena");
        return b1;
    }

bool operator == (Berza b1, Berza b2)
    {
        if(b1.v.size() != b2.v.size()) return false;
        return equal(&b1.v[0], &b1.v[b1.v.size()-1], &b2.v[0], equal_to<int>());
    }

bool operator !=(Berza b1, Berza b2){
        return !(b1==b2);
    }

Berza &operator +=(Berza &b, int n){
        b=b+n; return b;
    }

Berza &operator -= (Berza &b, int n)
    {
        b=b-n;
        return b;
    }

Berza &operator ++ (Berza &b)
    {
        Berza b1(0, b.makscijena);
        vector<int> v1(b.v.size(), 100);
        b1.v=v1;
        transform(&b.v[0], &b.v[b.v.size()], &b1.v[0], &b.v[0], plus<int>());
        if(count_if(&b.v[0], &b.v[b1.v.size()-1], bind(greater<int>(), placeholders::_1, b.makscijena))>0) throw range_error("Prekoracen dozvoljeni opseg cijena");
        return b;
    }

Berza operator ++ (Berza &b, int)
    {
        Berza pom(b.mincijena, b.makscijena);
        pom.v.resize(b.v.size());
        copy(&b.v[0],&b.v[b.v.size()], &pom.v[0]);
        ++b;
        return pom;
    }

void Berza::RegistrirajCijenu(int n)
    {
        if(n<mincijena || n>makscijena) throw range_error("Ilegalna cijena");
        v.push_back(n);
    }
int Berza::operator [] (int ind) const
    {
        if(ind<1 || ind>v.size()) throw range_error("Neispravan indeks");
        return v[ind-1];
    }
    
Berza operator - (Berza &b)
    {
        int n= b.mincijena+b.makscijena;
        Berza b1(0, b.makscijena*2);
        vector<int> v1(b.v.size(), n);
        b1.v=v1;
        transform(&b1.v[0], &b1.v[b1.v.size()], &b.v[0], &b1.v[0], minus<int>());
        b1.makscijena=b.makscijena; b1.mincijena=b.makscijena;
        return b1;
    }

int main ()
{
    
	return 0;
}
