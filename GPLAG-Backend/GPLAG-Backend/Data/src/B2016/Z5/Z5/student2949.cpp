/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <utility>
#include <list>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>

class Temperature {
    std::list<int> min_temp;
    std::list<int> max_temp;
    static int min_dozvoljena, max_dozvoljena;
public:

    Temperature(int MAX, int MIN){ if(MIN>MAX) throw std::range_error("Nekorektne temperature"); else min_dozvoljena=MIN; max_dozvoljena=MAX; }
    
    void RegistrirajTemperature(std::pair<int, int> DnevnaTemp){
        std::list<int>::iterator it_min(min_temp.begin());
        std::list<int>::iterator it_max(max_temp.begin());
       
        if(DnevnaTemp.first<min_dozvoljena || DnevnaTemp.second>max_dozvoljena || DnevnaTemp.first>DnevnaTemp.second) throw std::range_error("Nekorektne temperature");
            
        min_temp.insert(it_min, DnevnaTemp.first);
        max_temp.insert(it_max, DnevnaTemp.second);
        
    }
    
    void BrisiSve(){
        std::list<int>::iterator it_min(min_temp.begin());
        std::list<int>::iterator it_max(max_temp.begin());
        
        while(!(min_temp.empty())){
            it_min=min_temp.erase(it_min);
        }
        while(!(max_temp.empty())){
            it_max=max_temp.erase(it_max);
        }
    }
    
    void BrisiNegativneTemperature(){
        for(auto it1=min_temp.begin(), it2=max_temp.begin(); it1!=min_temp.end(), it2!=max_temp.end(); it1++, it2++){
            if(*it1<0 && *it2<0) {
                it1=min_temp.erase(it1);
                it2=max_temp.erase(it2);
            }
        }
    }
    
    int DajBrojRegistriranihTemperatura() const{
        int brojac(0);
        for(auto it=min_temp.begin(); it!=min_temp.end(); it++){
            brojac++;
        }
        if(brojac==0) throw std::logic_error("Nema registriranih temperatura"); 
        
    }
    int DajMinimalnuTemperaturu() const{ 
        if() throw std::logic_error("Nema registriranih temperatura"); 
        
    }
    int DajMaksimalnuTemperaturu() const{ 
        if() throw std::logic_error("Nema registriranih temperatura"); 
        
    }
    int DajBrojTemperaturaVecihOd() const{ 
        if() throw std::logic_error("Nema registriranih temperatura"); 
        
    }
    int DajBrojTemperaturaManjihOd() const{
        
    }
    
    friend bool operator ! (const Temperature &T){
        
    } 
    
    friend Temperature &operator ++(Temperature &t){
        for(auto it1=t.min_temp.begin(); it1!=t.min_temp.end(); it1++){
            *it1=*it1+1;
            if(*it1<min_dozvoljena) throw std::logic_error("Ilegalna operacija");
        }
        for(auto it2=t.max_temp.begin(); it2!=t.max_temp.end(); it2++){
            *it2=*it2+1;
            if(*it2>max_dozvoljena) throw std::logic_error("Ilegalna operacija");
        }
        return t;
    }
    
    friend Temperature operator ++(Temperature &t, int){
        Temperature pom;
        pom.min_temp=t.min_temp;
        pom.max_temp=t.max_temp;
        for(auto it1=t.min_temp.begin(); it1!=t.min_temp.end(); it1++){
            *it1=*it1+1;
            if(*it1<min_dozvoljena) throw std::logic_error("Ilegalna operacija");
        }
        for(auto it2=t.max_temp.begin(); it2!=t.max_temp.end(); it2++){
            *it2=*it2+1;
            if(*it2>max_dozvoljena) throw std::logic_error("Ilegalna operacija");
        } 
        
        return pom;
    }
    
    friend Temperature &operator --(Temperature &t){
        for(auto it1=t.min_temp,begin(); it1!=t.min_temp.end(); it1++){
            *it=*it-1;
            if(*it1<min_dozvoljena) thros std::logic_error("Ilegalna operacija");
        }
        for(auto it2=t.max_temp.begin(); it2!=t.max_temp.end(); it2++){
            *it2=*it2-1;
            if(*it2>max_dozvoljena) throw std::logic_error("Ilegalna operacija");
        }
        return t;
    }
    
    friend Temperature operator --(Temperature &t, int){
        Temperature pom;
        pom.min_temp=t.min_temp;
        pom.max_temp=t.max_temp;
        for(auto it1=t.min_temp.begin(); it1!=t.min_temp.end(); it1++){
            *it=*it-1;
            if(*it1<min_dozvoljena) thros std::logic_error("Ilegalna operacija");
        }
        for(auto it2=t.max_temp.begin(); it2!=t.max_temp.end(); it2++){
            *it2=*it2-1;
            if(*it2>max_dozvoljena) throw std::logic_error("Ilegalna operacija");
        }        
        
        return pom;
    }
    
    friend std::vector<int> operator *(Temperature &t){
        std::vector<int> vektor;
        int temp;
        for(auto it1=t.max_temp.begin(), it2=t.min_temp.begin(); it1!=t.max_temp.end(), it2!=t.min_temp.end(); it1++, it2++){
            temp=*it1-*it2;
            vektor.push_back(temp);
        }
        
        return vektor;
    }
    
};

int main ()
{
	return 0;
}