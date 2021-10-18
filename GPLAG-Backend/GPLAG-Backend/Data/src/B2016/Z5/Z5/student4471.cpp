/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

const long long int M = std::numeric_limits<int>::max();
class Temperature{
    std::list<int> minimalne;
    std::list<int> maksimalne;
    
    public:
    Temperature(int min,int max);
    void RegistrirajTemperature(std::pair<int,int> par);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temp) const;
    int DajBrojTemperaturaManjihOd(int temp) const;
    
    //operatori
    friend bool operator !(const Temperature &t);
     //unarni operatori koji vracaju referencu
    friend Temperature &operator++(Temperature &t);
    friend Temperature &operator--(Temperature &t);
    
    //unarni operatori koji ne vracaju referencu
    friend Temperature operator++(Temperature &t, int);
    friend Temperature operator--(Temperature &tr1, int);
    friend std::vector<int> operator *(Temperature &t);
    friend std::vector<int> operator +(Temperature &t);
    friend std::vector<int> operator -(Temperature &t);
    
    std::pair<int, int> operator [](int indeks)const{
        if(indeks<1 || indeks>minimalne.size())throw std::range_error("Neispravan indeks");
        auto it1=minimalne.begin();
        auto it2 = maksimalne.begin();
        std::advance(it1,indeks);
        std::advance(it2,indeks);
        return std::pair<int,int>(*it1,*it2);
    }
    
    friend Temperature operator +(Temperature &x,int y);
    friend Temperature operator+(int y, Temperature &x);
    
    friend Temperature operator -(Temperature &x,int y);
    friend Temperature operator -(int y, Temperature &x);
    
    friend Temperature &operator +=(Temperature &x,int y){return x=x+y;}
    friend Temperature &operator +=(int y, Temperature &x){return x=y+x;};
    
    friend Temperature &operator -=(Temperature &x,int y){return x=x-y;}
    friend Temperature &operator -=(int y, Temperature &x){return x=y-x;}
    
    friend bool operator ==(Temperature &t1,Temperature &t2);
    friend bool operator !=(Temperature &t1,Temperature &t2);
    friend std::ostream &operator <<(std::ostream &tok,const Temperature &r1);
};

Temperature::Temperature(int min, int max){
    if(min>max)throw std::range_error("Nekorektne temperature");
    minimalne.push_back(min);
    maksimalne.push_back(max);
}

//zagarantovano je da ce bit na prvom mjestu u LISTI MAKSIMALNA TEMP !!!
void Temperature::RegistrirajTemperature(std::pair<int,int> par){
    if(par.first>par.second)throw std::range_error("Nekorektne temperature");
    if(par.first<*std::min_element(minimalne.begin(),minimalne.end()))throw std::range_error("Nekorektne temperature");
    if(par.second>*std::max_element(maksimalne.begin(),maksimalne.end()))throw std::range_error("Nekorektne temperature");
    minimalne.push_back(par.first);
    maksimalne.push_back(par.second);
}


void Temperature::BrisiSve(){
    minimalne.clear();
    maksimalne.clear();
    minimalne.resize(0);
    maksimalne.resize(0);
}

void Temperature::BrisiNegativneTemperature(){
    static auto it1 = minimalne.begin();
    static auto it2 = maksimalne.begin();
    if(it1 == minimalne.end()){
        //ne radi nista !!
    }else{
        if(*it1<0 && *it2<0){
            it1 = minimalne.erase(it1);
            it2 = maksimalne.erase(it2);
            BrisiNegativneTemperature();
        }else{
            it1++;
            it2++;
        }
    }  
}

int Temperature::DajBrojRegistriranihTemperatura() const{
    return minimalne.size();
}

int Temperature::DajMinimalnuTemperaturu() const{
    if(minimalne.empty())throw std::logic_error("Nema registriranih temperatura");
    return *minimalne.begin();
}

int Temperature::DajMaksimalnuTemperaturu() const{
    if(maksimalne.empty())throw std::logic_error("Nema registriranih temperatura");
    return *maksimalne.begin();
}

//posto vracaju broj dana u kojima je temp veca dovoljno je proci kroz maksimalne temp !
int Temperature::DajBrojTemperaturaVecihOd(int temp) const{
    if(maksimalne.empty())throw std::logic_error("Nema registriranih temperatura");
    int brmax = std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp ));
    return brmax;
}
    
int Temperature::DajBrojTemperaturaManjihOd(int temp) const{
    if(maksimalne.empty())throw std::logic_error("Nema registriranih temperatura");
    int brmin = std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,temp ));
    return brmin;
}

bool operator !(const Temperature &t){
    if(t.minimalne.size() == 0)return true;
    else return false;
}

//prefisksne verzije 
Temperature &operator++(Temperature &t){
    std::transform(++t.minimalne.begin(),t.minimalne.end(),++t.minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    //provjera da li je neka minimalna premasila maksimalnu
    std::vector<int> v(t.minimalne.size()-1,M);
    std::transform(++t.minimalne.begin(),t.minimalne.end(),++t.maksimalne.begin(),v.begin(),std::bind(std::greater<int>(),std::placeholders::_1,std::placeholders::_2));
    if(v.at(0) != M)throw std::logic_error("Ilegalna operacija");
    else return t;
}

Temperature &operator--(Temperature &t){
    std::transform(++t.maksimalne.begin(),t.maksimalne.end(),++t.maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return t;  
}

//unarni operatori koji ne vracaju referencu
Temperature operator++(Temperature &t, int){
    Temperature pomocni(t);
    try{
    ++t;
    }catch(std::logic_error e){
        throw e;
    }
    return pomocni;
}
Temperature operator--(Temperature &t, int){
    Temperature pomocni(t);
    try{
    --t;
    }catch(std::logic_error e){
        throw e;
    }
    return pomocni; 
}


std::vector<int> operator *(Temperature &t){
     std::vector<int> v(t.minimalne.size()-1);
     std::transform(++t.maksimalne.begin(),t.maksimalne.end(),++t.minimalne.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
     return v;
}

std::vector<int> operator-(Temperature &t){
    std::vector<int> v(t.minimalne.size()-1);
    std::transform(++t.minimalne.begin(),t.minimalne.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,*t.minimalne.begin()));
    return v;   
}
std::vector<int> operator+(Temperature &t){
    std::vector<int> v(t.maksimalne.size()-1);
    std::transform(++t.maksimalne.begin(),t.maksimalne.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,*t.maksimalne.begin()));
    return v;   
}

Temperature operator +(Temperature &x,int y){
    Temperature t(x);
   
    std::transform(++t.minimalne.begin(),t.minimalne.end(),++t.minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    std::transform(++t.maksimalne.begin(),t.maksimalne.end(),++t.maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    //provjera
    auto max = *std::max_element(++t.maksimalne.begin(),t.maksimalne.end());
    auto min =*std::min_element(++t.minimalne.begin(),t.minimalne.end());
    
    auto max2 =*std::max_element(++t.minimalne.begin(),t.minimalne.end());
    if(max>*t.maksimalne.begin() || min<*t.minimalne.begin() || max2>*t.maksimalne.begin())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}

//druga verzija
Temperature operator+(int y, Temperature &x){
    return x+y;
}

//MINUS
Temperature operator -(Temperature &x,int y){
    Temperature t(x);
   
    std::transform(++t.minimalne.begin(),t.minimalne.end(),++t.minimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    std::transform(++t.maksimalne.begin(),t.maksimalne.end(),++t.maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    //provjera
    auto min = *std::min_element(++t.maksimalne.begin(),t.maksimalne.end());
    auto min2 =*std::min_element(++t.minimalne.begin(),t.minimalne.end());
    if(min<*t.minimalne.begin() || min2<*t.minimalne.begin())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}

//druga verzija
Temperature operator-(int y, Temperature &x){
    Temperature t(x);
    std::transform(++t.minimalne.begin(),t.minimalne.end(),++t.minimalne.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    std::transform(++t.maksimalne.begin(),t.maksimalne.end(),++t.maksimalne.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    std::swap(t.minimalne,t.maksimalne);
    
    return t;
}


bool operator ==(Temperature &t1,Temperature &t2){
    bool jednaki(true);
    if(t1.minimalne.size()!=t2.minimalne.size() || t1.maksimalne.size() != t2.maksimalne.size() || 
    *t1.minimalne.begin() !=*t2.minimalne.begin() ||  *t1.maksimalne.begin() !=*t2.maksimalne.begin() )return false;
    if(t1.minimalne != t2.minimalne || t1.maksimalne != t2.maksimalne)return false;
    else return true;
}

bool operator !=(Temperature &t1,Temperature &t2){
    return !(t1==t2);
}


std::ostream &operator <<(std::ostream &tok, const Temperature &t){
    //prvo minimalne sa razmacima ispisujem
    std::ostream_iterator<int> out_it (tok," ");
    std::copy(t.minimalne.begin(),t.minimalne.end(),out_it);
  
    tok<<std::endl;
    
    //sada maksimalne
    std::copy(t.maksimalne.begin(),t.maksimalne.end(),out_it);
    return tok;
}

int main ()
{

/*
    Temperature temp(0,10);
    temp.RegistrirajTemperature({1,3});
    temp.RegistrirajTemperature({2,4});
    temp.RegistrirajTemperature({3,6});
    temp.RegistrirajTemperature({4,8});
    std::cout<<temp;
    */
   
    
	return 0;
}