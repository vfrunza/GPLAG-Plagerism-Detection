/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator> 
#include <vector> 


using namespace std;

class Temperature
{
    list<int> minimalne;
    list<int>maksimalne;
    int minPrag,maxPrag;

public:

    Temperature(int min, int max) {
        if(min>max)throw range_error("Nekorektne temperature");
        //minimalne.push_back(min);
        //maksimalne.push_back(max);
        minPrag = min;
        maxPrag= max;
    }


    void RegistrirajTemperature(pair<int,int>p) {
        if(p.first<minPrag || p.second>maxPrag || p.first>p.second) throw range_error("Nekorektne temperature");

        minimalne.push_back(p.first);
        maksimalne.push_back(p.second);
    }


    void BrisiSve() {
        minimalne.clear();
        maksimalne.clear();
    }

    void BrisiNegativneTemperature() {
        for(auto itMin=minimalne.begin(),itMax = maksimalne.begin(); itMin!=minimalne.end(); itMin++,itMax++) {
            if(*itMin<0 && *itMax<0) {
                itMin = minimalne.erase(itMin);
                itMin--;
                itMax = maksimalne.erase(itMax);
                itMax--;
            }
        }
    }

    int DajBrojRegistriranihTemperatura()const {
        return minimalne.size();
    }


    int DajMinimalnuTemperaturu()const {
        if(DajBrojRegistriranihTemperatura()==0) throw logic_error("Nema registriranih temperatura");
        return *min_element(minimalne.begin(),minimalne.end());
    }
    int DajMaksimalnuTemperaturu()const {
        if(DajBrojRegistriranihTemperatura()==0) throw logic_error("Nema registriranih temperatura");
        return *max_element(minimalne.begin(),minimalne.end());
    }


    int DajBrojTemperatureVecihOd(int t)const {
        if(DajBrojRegistriranihTemperatura()==0) throw logic_error("Nema registriranih temperatura");
        return count_if(maksimalne.begin(),maksimalne.end(),bind(less<int>(),t,placeholders::_1));
    }

    int DajBrojTemperaturaManjihOd(int t)const {
        if(DajBrojRegistriranihTemperatura()==0) throw logic_error("Nema registriranih temperatura");
        return count_if(minimalne.begin(),minimalne.end(),bind(less<int>(),placeholders::_1,t));
    }

    bool operator!()const {
        return DajBrojRegistriranihTemperatura()==0;
    }

    Temperature& operator++() {

        std::transform(minimalne.begin(),minimalne.end(), minimalne.begin(), bind(std::plus<int>(),placeholders::_1,1));
        vector<int> razlike;
        std::transform(maksimalne.begin(),maksimalne.end(), minimalne.begin(), back_inserter(razlike),std::minus<int>());

        if(count_if(razlike.begin(),razlike.end(),bind(greater<int>(),0,placeholders::_1))!=0) {
            std::transform(minimalne.begin(),minimalne.end(), minimalne.begin(), bind(std::minus<int>(),placeholders::_1,1));
            throw logic_error("Ilegalna operacija");
        }

        return *this;

    }

    /*
    friend Temperature operator++(Temperature&t,int){
        Temperature pomocni(t);
        ++t;
        return pomocni;
    }*/

    Temperature operator++(int) {
        Temperature pomocni(*this);
        ++(*this);
        return pomocni;
    }

    Temperature& operator--() {
        std::transform(maksimalne.begin(),maksimalne.end(), maksimalne.begin(), bind(std::minus<int>(),placeholders::_1,1));
        vector<int> razlike;
        std::transform(maksimalne.begin(),maksimalne.end(), minimalne.begin(), back_inserter(razlike),std::minus<int>());

        if(count_if(razlike.begin(),razlike.end(),bind(greater<int>(),0,placeholders::_1))!=0) {
            std::transform(minimalne.begin(),minimalne.end(), minimalne.begin(), bind(std::minus<int>(),placeholders::_1,1));
            throw logic_error("Ilegalna operacija");
        }

        return *this;
    }

    Temperature operator--(int) {
        Temperature pomocni(*this);
        --(*this);
        return pomocni;
    }

    vector<int> operator*()const {
        vector<int> razlike;
        std::transform(maksimalne.begin(),maksimalne.end(), minimalne.begin(), back_inserter(razlike),std::minus<int>());

        return razlike;
    }

    vector<int> operator+()const {
        vector<int>m;
        transform(maksimalne.begin(),maksimalne.end(),back_inserter(m),bind(minus<int>(),maxPrag,placeholders::_1));

        return m;
    }

    vector<int> operator-()const {
        vector<int>m;
        transform(minimalne.begin(),minimalne.end(),back_inserter(m),bind(minus<int>(),placeholders::_1,minPrag   ));

        return m;
    }


    pair<int,int> operator[](int indeks)const {
        if(indeks<0||indeks>minimalne.size()) throw range_error("Neispravan indeks");

        auto itMin = minimalne.begin();
        std::advance (itMin,indeks-1);


        auto itMax = maksimalne.begin();
        std::advance (itMax,indeks-1);

        return make_pair(*itMin, *itMax);

    }


    friend Temperature operator+(const Temperature&x,int broj) {
        
        Temperature t(x);
        std::transform(t.minimalne.begin(),t.minimalne.end(), t.minimalne.begin(), bind(std::plus<int>(),placeholders::_1,broj));
        std::transform(t.maksimalne.begin(),t.maksimalne.end(), t.maksimalne.begin(), bind(std::plus<int>(),placeholders::_1,broj));



        vector<int> razlike;
        std::transform(t.maksimalne.begin(),t.maksimalne.end(), t.minimalne.begin(), back_inserter(razlike),std::minus<int>());

        if(count_if(razlike.begin(),razlike.end(),bind(greater<int>(),0,placeholders::_1))!=0) {
            std::transform(t.minimalne.begin(),t.minimalne.end(), t.minimalne.begin(), bind(std::minus<int>(),placeholders::_1,1));
            throw logic_error("Prekoracen dozvoljeni opseg temperatura");
        }
        
        return t;
    }

    friend Temperature operator+(int broj, const Temperature&x) {
    
        return x+broj;
    }
    
    

    friend Temperature operator-(const Temperature&x,int broj) {
        
        Temperature t(x);
        std::transform(t.minimalne.begin(),t.minimalne.end(), t.minimalne.begin(), bind(std::minus<int>(),placeholders::_1,broj));
        std::transform(t.maksimalne.begin(),t.maksimalne.end(), t.maksimalne.begin(), bind(std::minus<int>(),placeholders::_1,broj));



        vector<int> razlike;
        std::transform(t.maksimalne.begin(),t.maksimalne.end(), t.minimalne.begin(), back_inserter(razlike),std::minus<int>());

        if(count_if(razlike.begin(),razlike.end(),bind(greater<int>(),0,placeholders::_1))!=0) {
            std::transform(t.minimalne.begin(),t.minimalne.end(), t.minimalne.begin(), bind(std::minus<int>(),placeholders::_1,1));
            throw logic_error("Prekoracen dozvoljeni opseg temperatura");
        }
        
        return t;
    }

    friend Temperature operator-(int broj, const Temperature&x) {
        
        //PROVJERI
          Temperature t(x);
        std::transform(x.minimalne.begin(),x.minimalne.end(), t.maksimalne.begin(), bind(std::minus<int>(),broj,placeholders::_1));
        std::transform(x.maksimalne.begin(),x.maksimalne.end(), t.minimalne.begin(), bind(std::minus<int>(),broj,placeholders::_1));

        
        return t;
    }

    friend Temperature& operator+=(Temperature&t,int broj){
        t=t+broj;
        return t;
    }


    friend Temperature& operator-=(Temperature&t,int broj){
        t=t-broj;
        return t;
    }


    friend bool operator==(const Temperature&t1, const Temperature&t2){
         vector<int> razlikeMax;
        std::transform(t1.maksimalne.begin(),t1.maksimalne.end(), t2.maksimalne.begin(), back_inserter(razlikeMax),std::minus<int>());
        vector<int> razlikeMin;
        std::transform(t1.minimalne.begin(),t1.minimalne.end(), t2.minimalne.begin(), back_inserter(razlikeMax),std::minus<int>());

        
        if(count_if(razlikeMax.begin(),razlikeMax.end(),bind(not_equal_to<int>(),0,placeholders::_1))!=0)
        return false;
        if(count_if(razlikeMin.begin(),razlikeMin.end(),bind(not_equal_to<int>(),0,placeholders::_1))!=0)
        return false;
        
        if(t1.minPrag!=t2.minPrag||t1.maxPrag!=t2.maxPrag) return false;
        
        
        return true;
    }
    
    friend bool operator !=(const Temperature&t1, const Temperature&t2){
        return !(t1==t2);   
    }
    
    
    friend ostream& operator<<(ostream&izlaz,const Temperature&t){
         ostream_iterator<int> out_it (izlaz," ");
        std::copy ( t.minimalne.begin(),t.minimalne.end(), out_it );
        izlaz<<endl;
        std::copy ( t.maksimalne.begin(), t.maksimalne.end(), out_it );
        
        
        return izlaz;
    }
    
    

};
int main ()
{
   std::cout << "Ovo je dummy AT, mora postojati. Testovi za ovaj zadatak jos nisu specificirani!" << std::endl;
 Temperature t(1,50);
 
 t.RegistrirajTemperature(make_pair(10,20));
 t.RegistrirajTemperature(make_pair(8,40));
 t.RegistrirajTemperature(make_pair(19,50));
 
 cout<<t<<endl;
 t++;
 cout<<t<<endl;
 
 t--;
 cout<<t<<endl;
    return 0;
}