/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>

using namespace std;

class Temperature
{
    list<int> min;
    list<int> max;
    
    public:
    Temperature(){}
    Temperature(int min1, int max1):min(min1),max(max1)
    {
        if (min1 > max1) throw range_error("Nekorektne temperature");
    }
    
    void RegistrirajTemperature(pair<int, int> p)
    {
        if (p.first > p.second) throw range_error("Nekorektne temperature");
        min.push_back(p.first);
        max.push_back(p.second);
    }
    
    void BrisiSve()
    {
        min.clear();
        max.clear();
    }
    
    void BrisiSveNegativne()
    {
        auto iter1 = min.begin();
        auto iter2 = max.begin();
        while (iter1 != min.end())
        {
            if (*iter1 < 0 && *iter2 < 0)
            {
                auto pom1 = iter1;
                auto pom2 = iter2;
                iter1 = min.erase(pom1);
                iter1--;
                iter2 = max.erase(pom2);
                iter2--;
            }
            iter1++;
            iter2++;
        }
    }
    
    int DajBrojRegistriranihTemperatura()
    {
        int br = 0;
        auto iter = min.begin();
        while (iter != min.end())
        {
            br++;
            iter++;
        }
        
        return br;
    }
    
    int DajMinimalnuTemperaturu()
    {
        auto iter = min.begin();
        auto m = iter;
        while (iter != min.end())
        {
            if (*iter < *m) *m = *iter;
            iter++;
        }
        
        return *m;
    }
    
    int DajMaksimalnuTemperaturu()
    {
        auto iter = max.begin();
        auto m = iter;
        while (iter != max.end())
        {
            if (*iter > *m) *m = *iter;
            iter++;
        }
        
        return *m;
    }
    
    int DajBrojTemperaturaVecihOd(int n)
    {
        int br = 0;
        auto iter1 = min.begin();
        while (iter1 != min.end())
        {
            if (*iter1 > n) br++;
            iter1++;
        }
        auto iter2 = max.begin();
        while (iter2 != max.end())
        {
            if (*iter2 > n) br++;
            iter2++;
        }
        
        return br;
    }
    
    int DajBrojTemperaturaManjihOd(int n)
    {
        int br = 0;
        auto iter1 = min.begin();
        while (iter1 != min.end())
        {
            if (*iter1 < n) br++;
            iter1++;
        }
        auto iter2 = max.begin();
        while (iter2 != max.end())
        {
            if (*iter2 < n) br++;
            iter2++;
        }
        
        return br;
    }
};

int main ()
{
    Temperature t;
    t.RegistrirajTemperature(make_pair(1, 25));
    t.RegistrirajTemperature(make_pair(-55, 5));
    t.RegistrirajTemperature(make_pair(20, 33));
    cout << t.DajBrojRegistriranihTemperatura() << endl;
    cout << t.DajMinimalnuTemperaturu() << endl;
    cout << t.DajMaksimalnuTemperaturu() << endl;
    cout << t.DajBrojTemperaturaManjihOd(19) << endl;
	return 0;
}