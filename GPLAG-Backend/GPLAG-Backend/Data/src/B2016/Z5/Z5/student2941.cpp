/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>

using namespace std;

class Temperature {
    list<int> min;
    list<int> max;
    
    public:
    Temperature( int minimalna, int maximalna);
    void RegistrirajTemperature( pair<int, int> temp );
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTeperaturu() const;
    int DajBrojTeperaturaVecihOd(int temp) const;
    int DajBrojTeperaturaManjihOd(int temp) const;
    bool operator !();
    Temperature &operator ++();
    Temperature &operator --();
    friend Temperature operator ++(Temperature &t, int);
    friend Temperature operator --(Temperature &t, int);
    vector<int> operator *();
    vector<int> operator -();
    vector<int> operator +();
    pair<int,int> operator [](int i);
    friend Temperature operator +(const Temperature &t, int Y);
    friend Temperature operator -(const Temperature &t, int Y);
    friend Temperature operator +(int Y, const Temperature &t);
    friend Temperature operator -(int Y, const Temperature &t);
    friend Temperature &operator +=(Temperature &t, int Y);
    friend Temperature &operator -=(Temperature &t, int Y);
    friend bool operator ==(const Temperature &t1, const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);
    friend ostream &operator <<(ostream &tok, const Temperature &t);
};
    Temperature::Temperature( int minimalna, int maximalna) {
        if(maximalna<minimalna) throw range_error ("Nekorektne temperature");
        min.push_back(minimalna);
        max.push_back(maximalna);
    }
    void Temperature::RegistrirajTemperature( pair<int, int> temp ) {
        auto it1=min.begin();
        auto it2=max.begin();
        if(temp.first>temp.second || temp.first<*it1 || temp.second>*it2) throw range_error ("Nekorektne temperature");
        min.push_back(temp.first);
        max.push_back(temp.second);
    }
    void Temperature::BrisiSve() {
        auto it=min.begin(); int n=*it;
        auto it2=max.begin();  int n1=*it2;
        min.clear();
        max.clear();
        min.push_back(n);
        max.push_back(n1);
    }
    void Temperature::BrisiNegativneTemperature() {
        if(*max_element(max.begin(),max.end())<0) this->BrisiSve();
        auto it=min.begin(); it++;
        auto it1=max.begin(); it1++;
        pocetak:
        if(*it<0 && *it1<0) {
            it=min.erase(it);
            it1=max.erase(it1);
        }
        else { it++; it1++; }
        if(it==min.end() || it1==max.end()) {}
        else goto pocetak;
        
        
    }                                                                     //BrisiNegativneTemeprature
    int Temperature::DajBrojRegistriranihTemperatura() const {
        return min.size()-1;
    }
    int Temperature::DajMinimalnuTemperaturu() const {
        auto it=min.begin();
        it++;
        return *min_element(it, min.end());
    }
    int Temperature::DajMaksimalnuTeperaturu() const {
        auto it=max.begin();
        it++;
        return *max_element(it, max.end());
    }
    int Temperature::DajBrojTeperaturaVecihOd(int temp) const {
        auto it=max.begin();
        it++;
        int n=count_if(it, max.end(), bind( greater<int>(), placeholders::_1, temp));
        return n;
    }  
    int Temperature::DajBrojTeperaturaManjihOd(int temp) const {
        auto it=min.begin(); it++;
        return count_if(it, min.end(), bind( less<int>(), placeholders::_1, temp));
    }
    bool Temperature::operator !() {
        if(this->min.size()==1 && this->max.size()==1) return true;
        return false;
    }
    Temperature &Temperature::operator ++() {
        transform(min.begin(), min.end(), min.begin(), bind(plus<int>(), placeholders::_1, 1));
        vector<int> pom=*(*this);
        if(*min_element(pom.begin(),pom.end())<0) throw logic_error("Ilegalna operacija");
        return *this;
    }
    Temperature &Temperature::operator --() {
        transform(max.begin(), max.end(), max.begin(), bind( plus<int>(), placeholders::_1, -1));
        vector<int> pom=*(*this);
        if(*min_element(pom.begin(),pom.end())<0) throw logic_error("Ilegalna operacija");
        return *this;
    }
    Temperature operator ++(Temperature &t, int) {
        Temperature k=t;
        ++t;
        return k;
    }
    Temperature operator --(Temperature &t, int) {
       Temperature k=t;
       --t;
       return k;
    }
    vector<int> Temperature::operator *() {
        vector<int> vektor;
        vektor.resize(min.size()-1);
        auto it=max.begin(); it++;
        auto it1=min.begin(); it1++;
        auto it2=vektor.begin();
        transform(it, max.end(), it1, it2, minus<int>() );
        return vektor;
    }                                                                            
    vector<int> Temperature::operator -() {
        vector<int> vek(min.size()-1);
        //vector<int> pomocni(min.size()-1, *(min.begin()));
        auto it=min.begin(); it++;
        //auto it1=pomocni.begin();
        auto it2=vek.begin();
        transform(it, min.end(),it2, bind(plus<int>(), placeholders::_1, *(min.begin())));
        return vek;
    }
    vector<int> Temperature::operator +() {
        vector<int> vek(max.size()-1);
        vector<int> pomocni(max.size()-1, *(max.begin()));
        auto it=max.begin(); it++;
        auto it1=pomocni.begin();
        auto it2=vek.begin();
        transform(it1, pomocni.end(), it, it2, minus<int>());
        return vek;
    }
    pair<int,int> Temperature::operator [](int i) {
        if(i>min.size() || i<0) throw range_error ("Neispravan indeks");
        vector<int> minimalne(min.size());
        vector<int> maksimalne(max.size());
        auto it=min.begin(); it++;
        auto it1=max.begin(); it1++;
        copy(it, min.end(), minimalne.begin());
        copy(it1, max.end(), maksimalne.begin());
        return make_pair(minimalne[i-1], maksimalne[i-1]);
    }
    Temperature operator +(const Temperature &t, int Y) {
        vector<int> vek(t.min.size()-1, Y);
        Temperature pom=t;
        auto it=pom.min.begin(); it++;
        transform(it, pom.min.end(), vek.begin(), it, plus<int>());
        it=pom.max.begin(); it++;
        transform(it, pom.max.end(), vek.begin(), it, plus<int>());
        if(*max_element(pom.max.begin(),pom.max.end()) > *pom.max.begin() || *min_element(pom.min.begin(), pom.min.end()) < *pom.min.begin()) throw logic_error ("Prekoracen dozvoljeni opseg temperatura");
        return pom;
    }
    Temperature operator -(const Temperature &t, int Y) {
        vector<int> vek(t.min.size()-1, Y);
        Temperature pom=t;
        auto it=pom.min.begin(); it++;
        transform(it, pom.min.end(), vek.begin(), it, minus<int>());
        it=pom.max.begin(); it++;
        transform(it, pom.max.end(), vek.begin(), it, minus<int>());
        if(*max_element(pom.max.begin(),pom.max.end()) > *pom.max.begin() || *min_element(pom.min.begin(), pom.min.end()) < *pom.min.begin()) throw logic_error ("Prekoracen dozvoljeni opseg temperatura");
        return pom;
    }
    Temperature operator +(int Y, const Temperature &t) {
    Temperature pom= t + Y;
    return pom;
    }
    Temperature operator -(int Y, const Temperature &t) {
        vector<int> vek(t.min.size()-1, Y);
        Temperature pom=t;
        auto it=pom.min.begin(); it++;
        transform(vek.begin(), vek.end(), it, it, minus<int>());
        it=pom.max.begin(); it++;
        transform(vek.begin(), vek.end(), it, it, minus<int>());
        pom.min.swap(pom.max);
        if(*max_element(pom.max.begin(),pom.max.end()) > *pom.max.begin() || *min_element(pom.min.begin(), pom.min.end()) < *pom.min.begin()) throw logic_error ("Prekoracen dozvoljeni opseg temperatura");
        return pom;
    }
    Temperature &operator +=(Temperature &t, int Y) {
        return t=t+Y;
    }
    Temperature &operator -=(Temperature &t, int Y) {
        return t=t-Y;
    }
    bool operator ==(const Temperature &t1, const Temperature &t2) {
        if(t1.min.size()!= t2.min.size() || t1.max.size()!= t2.max.size()) return false;
        if(!equal(t1.min.begin(), t1.min.end(), t2.min.begin())) return false;
        if(!equal(t1.max.begin(), t1.max.end(), t2.max.begin())) return false;
        else return true;
    }
    bool operator !=(const Temperature &t1, const Temperature &t2) {
        return !(t1==t2);
    }
    ostream &operator <<(ostream &tok, const Temperature &t) {
        auto it=t.min.begin(); it++;
        ostream_iterator<int> iter(std::cout, " ");
        copy(it, t.min.end(), iter);
        tok<<endl;
        it=t.max.begin(); it++;
        copy(it, t.max.end(), iter);
        tok<<endl;
        return tok;
    }
    
int main ()
{       
	return 0;
}