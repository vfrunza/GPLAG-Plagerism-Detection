/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list> 
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

class Temperature
{
    int minMogucaTemp;
    int maksMogucaTemp;
    list<int> minTemperature;
    list<int> maksTemperature;
    
    void TestirajTemperature(int manja, int veca)
    {
        if(manja>veca)
        {
            throw range_error("Nekorektne temperature");
        }
    }
    
    void TestirajOpseg(int manja, int veca)
    {
        if(manja < minMogucaTemp || veca > maksMogucaTemp)
        {
            throw range_error("Nekorektne temperature");
        }
    }
    
  public:
    Temperature(int minTemp, int maksTemp)
    {
        TestirajTemperature(minTemp, maksTemp);
        maksMogucaTemp = maksTemp;
        minMogucaTemp = minTemp;
    }
    
    void RegistrirajTemperature(pair<int,int> ekstremi)
    {
        int minimalnaTemp = ekstremi.first;
        int maksimalnaTemp = ekstremi.second;
        TestirajTemperature(minimalnaTemp, maksimalnaTemp);
        TestirajOpseg(minimalnaTemp, maksimalnaTemp);
        minTemperature.push_back(minimalnaTemp);
        maksTemperature.push_back(maksimalnaTemp);
    }
    
    void BrisiSve()
    {
        minTemperature.clear();
        maksTemperature.clear();
    }
    
    void BrisiTemperature(pair<int, int> uneseniPar)
    {
        int brojac{0};
        auto itMax = maksTemperature.begin();
        for(auto itMin=minTemperature.begin() ; itMin != minTemperature.end() ; itMin++ , itMax++ )
        {
            if(*itMin==uneseniPar.first && *itMax==uneseniPar.second)
            {
                brojac++;
                minTemperature.erase(itMin);
                maksTemperature.erase(itMax);
            }
        }
        
        if(brojac==0)   throw logic_error("Takve temperature nisu registrirane");
    }
    
    int DajBrojRegistriranihTemperatura() const { return minTemperature.size(); }  
    
    int DajMinimalnuTemperaturu() const
    {
        auto najmanjaTemperatura = min_element(minTemperature.begin(), minTemperature.end() );
        return *najmanjaTemperatura;
    }
    
    int DajMaksimalnuTemperaturu() const
    {
        auto najvecaTemperatura =  max_element(maksTemperature.begin(), maksTemperature.end());
        return *najvecaTemperatura;
    }
    
    int DajBrojTemperaturaVecihOd(int temperatura)
    {
        return count_if(maksTemperature.begin(), maksTemperature.end(),   bind( greater<int>(), placeholders::_1, temperatura)  );
    }
    
    int DajBrojTemperaturaManjihOd(int temperatura)
    {
        return count_if(minTemperature.begin(),minTemperature.end(),   bind(less<int>(), placeholders::_1, temperatura)  );
    }
    
    bool operator !() 
    {
        return (this->maksTemperature.size()==0) ;
    }
    
    Temperature &operator ++() 
    {
        for_each(minTemperature.begin(), minTemperature.end(), bind( plus<int>(), placeholders::_1, 1) );
        
        list<int> razlikaMaksMinusMin(maksTemperature);
        transform( razlikaMaksMinusMin.begin(), razlikaMaksMinusMin.end(), minTemperature.begin(), razlikaMaksMinusMin.begin(), minus<int>() );
        if( any_of( razlikaMaksMinusMin.begin(), razlikaMaksMinusMin.end(), bind( less<int>(), placeholders::_1, 0 ) )  )
        {
            for_each( minTemperature.begin(), minTemperature.end(), bind( minus<int>(), placeholders::_1, 1)  );
            throw logic_error("Ilegalna operacija");
        }
        
        return *this;        
    }
    
    Temperature &operator --() 
    {
        for_each(maksTemperature.begin(), maksTemperature.end(), bind( minus<int>(), placeholders::_1,1));
        
        list<int> razlikaMaksMinusMin(maksTemperature);
        transform( razlikaMaksMinusMin.begin(), razlikaMaksMinusMin.end(), minTemperature.begin(), razlikaMaksMinusMin.begin(), minus<int>() );
        if( any_of( razlikaMaksMinusMin.begin(), razlikaMaksMinusMin.end(), bind( less<int>(), placeholders::_1, 0 ) ) )
        {
            for_each( minTemperature.begin(), minTemperature.end(), bind( plus<int>(), placeholders::_1, 1 ) );
            throw logic_error("Ilegalna operacija");
        }
        
        return *this;
    }
    
    pair<int,int> operator [](int indeks)
    {
        if(indeks<0 || indeks>=minTemperature.size())    
        {
            throw range_error("Neispravan indeks");
        }
        
        auto itMin = minTemperature.begin();
        auto itMax = maksTemperature.begin();
        
        for(int i=0; i<indeks;i++ )
        {
            itMin++;
            itMax++;
        }
        
        return make_pair(*itMin, *itMax );
    }
    
    Temperature operator +(int promjena)
    {
        Temperature noveTemperature(*this);
        for_each(noveTemperature.minTemperature.begin(), noveTemperature.minTemperature.end(), bind( plus<int>(), placeholders::_1, promjena ) );
        for_each(noveTemperature.maksTemperature.begin(), noveTemperature.maksTemperature.end(), bind( plus<int>(), placeholders::_1, promjena ) );
        return noveTemperature;
    }
    
    Temperature operator -(int promjena)
    {
        Temperature noveTemperature( *this );
        noveTemperature = noveTemperature + (-promjena);
        return noveTemperature;
    }
    
    friend Temperature operator +(int promjena, Temperature temper)
    {
        return (temper+promjena);
    }
    
    friend Temperature operator -(int promjena, Temperature temper)
    {
        return (temper-promjena);
    }
    
    Temperature  &operator +=(int promjena)
    {
        *this = *this + promjena;
        return *this;
    }
    
    Temperature &operator -=(int promjena)
    {
        *this = *this - promjena;
        return *this;
    }
    
    bool operator ==(Temperature drugaTemper)
    {
        return (this->minTemperature==drugaTemper.minTemperature && this->maksTemperature==drugaTemper.maksTemperature);
    }
    
    bool operator !=(Temperature drugaTemper)
    {
        return !(*this==drugaTemper);
    }
    
    friend ostream &operator <<(ostream &tok, Temperature temper)
    {
        for_each(temper.minTemperature.begin(), temper.minTemperature.end(), [&tok ](int i){ tok<<i<<" "; });
        tok<<endl;
        for_each(temper.maksTemperature.begin(), temper.maksTemperature.end(), [&tok ](int i){ tok<<i<<" "; });
        return tok;
    }
    
};

int main ()
{
	return 0;
}