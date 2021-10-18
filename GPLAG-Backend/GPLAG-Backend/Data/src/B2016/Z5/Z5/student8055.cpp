/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <functional>
class Temperature{
    std::list<int> mintemperatura;
    std::list<int> maxtemperatura;
    static int broj_registriranih_temperatura;
public:
    Temperature(std::list<int> a, std::list<int> b);
    void RegistrirajTemperature(std::map<int,int> mapa);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const{
        return broj_registriranih_temperatura;
    }
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTeperaturu() const;
    int DajBrojTeperaturaVecihOd() const;
    int DajBrojTeperaturaManjihOd() const;
    
    bool operator !();
    Temperature &operator ++() { 
      
		for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
		    (*it)++;
		}
		for(auto it=maxtemperatura.begin(); it!=maxtemperatura.end(); it++){
		    (*it)++;
		}
		for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
             for(auto it1=maxtemperatura.begin(); it1!=maxtemperatura.end(); it1++){
               if(*it>*it1) throw std::logic_error("Ilegalna operacija");
             }
        }
		return *this;
	}
		
     Temperature &operator --() { 
      
		for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
		    (*it)--;
		}
		for(auto it=maxtemperatura.begin(); it!=maxtemperatura.end(); it++){
		    (*it)--;
		}
		for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
             for(auto it1=maxtemperatura.begin(); it1!=maxtemperatura.end(); it1++){
               if(*it>*it1) throw std::logic_error("Ilegalna operacija");
             }
        }
		return *this;
	}
    
    
};

    int Temperature::broj_registriranih_temperatura=0;
        
    Temperature::Temperature(std::list<int> a, std::list<int> b){
          for(auto it=a.begin(); it!=a.end(); it++){
             for(auto it1=b.begin(); it1!=b.end(); it1++){
               if(*it>*it1) throw std::range_error("Nekorektne temperature");
             }
        }
        mintemperatura=a;
        maxtemperatura=b;
    }

    void Temperature::RegistrirajTemperature(std::map<int,int> mapa){
        for(auto it=mapa.begin(); it!=mapa.end(); it++){
         if(it->first>it->second) throw std::range_error("Nekorektne temperature");
             }
         for(auto it=mapa.begin(); it!=mapa.end(); it++){
             for(auto it1=mintemperatura.begin(); it1!=mintemperatura.end(); it1++){
                 for(auto it2=maxtemperatura.begin(); it2!=maxtemperatura.end(); it2++){
                     *it1=it->first;
                     *it2=it->second;
                     broj_registriranih_temperatura++;
                     
                 }
             }
         }
    }
    
    void Temperature::BrisiSve(){
        for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
            mintemperatura.remove(*it);
        }
        for(auto it=maxtemperatura.begin(); it!=maxtemperatura.end(); it++){
            maxtemperatura.remove(*it);
        }
        
    }

    int Temperature::DajMinimalnuTemperaturu() const{
    if(broj_registriranih_temperatura==0) throw std::logic_error("Nema registriranih temperatura");
        int min(100);
        for(auto it=mintemperatura.begin(); it!=mintemperatura.end(); it++){
            if(*it<min) min=*it;
        }
        return min;
        
    }
    
    int Temperature::DajMaksimalnuTeperaturu() const{
     if(broj_registriranih_temperatura==0) throw std::logic_error("Nema registriranih temperatura");
        int max(-100);
        for(auto it=maxtemperatura.begin(); it!=maxtemperatura.end(); it++){
            if(*it>max) max=*it;
        }
        return max;
        
    }
    int Temperature:: DajBrojTeperaturaVecihOd() const{
        if(broj_registriranih_temperatura==0) throw std::logic_error("Nema registriranih temperatura");
        
    }
    
    int Temperature:: DajBrojTeperaturaManjihOd() const{
        if(broj_registriranih_temperatura==0) throw std::logic_error("Nema registriranih temperatura");
    }
    
    bool Temperature::operator!(){
        bool a(true);
        if(broj_registriranih_temperatura==0) return false;
        return a;
    }
    
    
    



int main ()
{
	return 0;
}