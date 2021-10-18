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


  
class Temperature{
  std::list<int> max;
  std::list<int> min;
  int minimalna_dozvoljena;
  int maksimalna_dozvoljena;
  int broj_registrovanih;
  
  public: 
  Temperature(int min, int max);
  void RegistrirajTemperature(std::pair<int, int> ParMinMax);
  void BrisiSve();
  void BrisiNegativneTemperature();
  int DajBrojRegistriranihTemperatura() const { return broj_registrovanih; }
  int DajMinimalnuTemperaturu() const;   //rijesiti samo pomocu algoritam i funkcional biblioteka(veznik bind)
  int DajMaksimalnuTemperaturu() const;   //-||-
  int DajBrojTemperaturaVecihOd(int x) const;   //-||-
  int DajBrojTemperaturaManjihOd(int x) const;  //-||-
  bool operator !(); 
  Temperature operator ++();
  Temperature operator --();
  Temperature operator ++(int);
  Temperature operator --(int);
  std::vector<int> operator*(); 
  std::vector<int> operator+();
  std::vector<int> operator-();
  //friend Temperature operator+(const Temperature &t, int x);
  //friend Temperature operator-(const Temperature &t, int x);
  //friend Temperature operator+(int x, const Temperature &t);
  //friend Temperature operator-(int x, const Temperature &t);
  std::pair<int, int> operator [](int x);
  friend bool operator ==(const Temperature &t1, const Temperature &t2);
  friend bool operator !=(const Temperature &t1, const Temperature &t2);
  friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
}; 

Temperature::Temperature(int min, int max){
    if(min > max) throw std::range_error("Nekorektne temperature");
    Temperature::minimalna_dozvoljena = min;
    Temperature::maksimalna_dozvoljena = max;
    Temperature::broj_registrovanih = 0;
}
void Temperature::RegistrirajTemperature(std::pair<int, int> ParMinMax){
    if(std::get<0>(ParMinMax) < minimalna_dozvoljena || std::get<1>(ParMinMax) > maksimalna_dozvoljena || std::get<0>(ParMinMax) > maksimalna_dozvoljena) throw std::range_error("Nekorektne temperature");
    Temperature::min.push_back(std::get<0>(ParMinMax));
    Temperature::max.push_back(std::get<1>(ParMinMax));
    broj_registrovanih++;
}
void Temperature::BrisiSve(){
    min.clear();
    max.clear();
    broj_registrovanih = 0;
}
void Temperature::BrisiNegativneTemperature(){
    
    bool nasao(false);
    int br(0);
    
    auto it1 = min.begin();
while(it1 != min.end()){
    
    for(it1 = min.begin(); it1 != min.end(); it1++){
        br++;
        if(*it1 < 0){
          nasao = true; break;  
        } 
    }
    if(nasao == true){
        auto it2 = max.begin();
        std::advance(it2, br-1);
        if(*it2 < 0){
                min.erase(it1);
                max.erase(it2);
                broj_registrovanih--;
                nasao = false;
                br=0;
        }
}  

}
}
/*
int Temperature::DajMinimalnuTemperaturu() const{
    if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    int min_temp = *(std::min_element(min.begin(), min.end(), [](int a, int b) {return a < b; }));
    return min_temp;
}

int Temperature::DajMaksimalnuTeperaturu() const{
    if(max.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    int max_temp = *(std::min_element(max.begin(), max.end(), [](int a, int b) {return a > b; }));
    return max_temp;
}

int Temperature::DajBrojTeperaturaVecihOd(int x) const{
    if(max.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    int brojac(0);
    std::for_each(max.begin(), max.end(), [x,&brojac] (int a) {if(a > x) brojac++; return brojac; });
    std::for_each(min.begin(), min.end(), [x,&brojac] (int a) {if(a > x) brojac++; return brojac; });
    return brojac;
}

int Temperature::DajBrojTeperaturaManjihOd(int x) const{
    if(max.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    
    int brojac(0);
    std::for_each(max.begin(), max.end(), [x,&brojac] (int a) {if(a < x) brojac++; return brojac; });
    std::for_each(min.begin(), min.end(), [x,&brojac] (int a) {if(a < x) brojac++; return brojac; });
    return brojac;
}
*/
std::ostream &operator <<(std::ostream &tok, const Temperature &t){
    if(t.max.size() == 0 || t.min.size() == 0) return tok;
    
    tok << std::for_each(t.min.begin(), t.min.end(), [] (int x) {std::cout << x << " "; });
    tok << std::endl;
    tok << std::for_each(t.max.begin(), t.max.end(), [] (int x) {std::cout << x << " "; }) ;
    return tok;
}
bool Temperature::operator !(){
    if(broj_registrovanih == 0) return true;
    else return false;
}
bool operator ==(const Temperature &t1, const Temperature &t2){
     
     if(t1.minimalna_dozvoljena != t2.minimalna_dozvoljena) return false;
     if(t1.DajBrojRegistriranihTemperatura() != t2.DajBrojRegistriranihTemperatura()) return false;
     return (t1.min.size() == t2.min.size() && std::equal(t1.min.begin(), t1.min.end(), t2.min.begin() ) && t1.max.size() == t2.max.size() && std::equal(t1.max.begin(), t1.max.end(), t2.max.begin()));
       
 }
bool operator !=(const Temperature &t1, const Temperature &t2){
     return !(t1 == t2);
 }
std::pair<int, int> Temperature::operator [](int x){
    if(x < 1 || x > min.size() || x > max.size()) throw std::range_error("Neispravan indeks");  
    std::list<int>::iterator pocetak_min = min.begin();
    std::list<int>::iterator pocetak_max = max.begin();
    std::advance(pocetak_min, x-1);
    std::advance(pocetak_max, x-1);
    int min = *pocetak_min;
    int max = *pocetak_max;
    return std::make_pair(min,max);
}
std::vector<int> Temperature::operator*() {
    std::vector<int> temp;
    for(auto it1 = min.begin(); it1 != min.end(); it1++){
        for(auto it2 = max.begin(); it2 != max.end(); it2++){
            temp.push_back(*it2-*it1);
        }
    }
    return temp;
}
std::vector<int> Temperature::operator+(){
    std::vector<int> temp;
    int razlika;
    for(auto it=max.begin(); it != max.end(); it++){
        razlika = *it - maksimalna_dozvoljena;
        temp.push_back(razlika);
    }
    return temp;
}
std::vector<int> Temperature::operator-(){
    std::vector<int> temp;
    int razlika;
    for(auto it=min.begin(); it != min.end(); it++){
        razlika = *it - minimalna_dozvoljena;
        temp.push_back(razlika);
    }
    return temp;
}
Temperature Temperature::operator ++(){
    for(auto it=this->min.begin(); it != this->min.end(); it++){
        if(*it + 1 > maksimalna_dozvoljena) throw std::logic_error("Ilegalna operacija");
         *it += 1;
    }
    return *this;
}
Temperature Temperature::operator --(){
    for(auto it=this->max.begin(); it != this->max.end(); it++){
        if(*it - 1 > minimalna_dozvoljena) throw std::logic_error("Ilegalna operacija");
         *it -= 1;
    }
    return *this;
}   
Temperature Temperature::operator ++(int){
    Temperature temp = *this;
    for(auto it=temp.max.begin(); it != temp.max.end(); it++){
        if(*it - 1 > minimalna_dozvoljena) throw std::logic_error("Ilegalna operacija");
         *it -= 1;
    }
    return temp;
}
Temperature Temperature::operator --(int){
    Temperature temp = *this;
    for(auto it=temp.min.begin(); it != temp.min.end(); it++){
        if(*it + 1 > maksimalna_dozvoljena) throw std::logic_error("Ilegalna operacija");
         *it += 1;
    }
    return temp;
}


int main (){
    
	return 0;
}