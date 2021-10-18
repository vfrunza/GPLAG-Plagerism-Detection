/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class Temperature
{
    list<int>max;
    list<int>min;
    int mini,maxi;
    
    
    public:
    Temperature(int mini,int maxi)
    {
        if(mini>maxi) throw range_error("Nekorektne temperature");
        Temperature::mini=mini;
        Temperature::maxi=maxi;
    }
    void RegistrirajTemperature(pair<int,int> temp)
    {
        if(temp.first<mini || temp.second>maxi) throw range_error("Nekorektne temperature");
        min.push_back(temp.first);
        max.push_back(temp.second);
    }
    void BrisiSve()
    {
        max.clear();
        min.clear();
    }
    
    void BrisiNegativneTemperature()
    {
        remove_if(max.begin(),max.end(),bind(less<int>(),placeholders::_1,0));
        remove_if(min.begin(),min.end(),bind(less<int>(),placeholders::_1,0));
    }
    
    int DajBrojRegistrovanihTemperatura()const 
    {
        return max.size();
    }
    void Ispisi()const 
    {   
        cout<<"Temperature su:"<<endl;
        copy(max.begin(),max.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        copy(min.begin(),min.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        
    }
    int DajMinimalnuTemperaturu()const
    {
        return *min_element(min.begin(),min.end());
    }
    int DajMaksimalnuTemperaturu()const
    {
        return *max_element(max.begin(),max.end());
    }
    int BrojTemperaturaVecihOd(int n)const
    {
        int a=count_if(min.begin(),min.end(),bind(greater<int>(),n,placeholders::_1));
        a+=count_if(max.begin(),max.end(),bind(greater<int>(),n,placeholders::_1));
        return a;
    }
    
    int BrojTemperaturaManjihOd(int n)const
    {
        int a=count_if(min.begin(),min.end(),bind(less<int>(),n,placeholders::_1));
        a+=count_if(max.begin(),max.end(),bind(less<int>(),n,placeholders::_1));
        return a;
    }
    friend bool operator !(Temperature &t)
    {
        if(t.min.size()==0 && t.max.size()==0) return 1;
        return 0;
    }
    //friend void operator ++()
};
int main ()
{   
    Temperature t(-15,35);
    t.RegistrirajTemperature(make_pair(1,2));
    t.RegistrirajTemperature(make_pair(-6,6));
    t.RegistrirajTemperature(make_pair(3,5));
    t.Ispisi();
    t.BrisiSve();
    t.Ispisi();
    t.RegistrirajTemperature(make_pair(-1,2));
    t.RegistrirajTemperature(make_pair(-6,-6));
    t.RegistrirajTemperature(make_pair(-3,5));
   // t.BrisiNegativneTemperature();
    t.Ispisi();
    cout<<t.DajBrojRegistrovanihTemperatura();
    cout<<endl<<"Max temp je "<<t.DajMaksimalnuTemperaturu()<<endl;
    cout<<"Min temp je "<<t.DajMinimalnuTemperaturu()<<endl;
    
    cout<<t.BrojTemperaturaManjihOd(1)<<"-"<<t.BrojTemperaturaVecihOd(1)<<endl;
    cout<<!t<<endl;
    
   t.BrisiNegativneTemperature();
    t.Ispisi();
    
	return 0;
}