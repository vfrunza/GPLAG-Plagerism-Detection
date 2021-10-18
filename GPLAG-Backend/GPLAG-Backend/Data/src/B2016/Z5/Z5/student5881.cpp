/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

class Temperature{
    std::list<int> minimalne;
    std::list<int> maximalne;
    int min_dozvoljena, max_dozvoljena;
    std::list<int>::iterator it1;
    std::list<int>::iterator it2;
public:
    Temperature(int minimalna, int maximalna);
    void RegistrirajTemperature(std::pair<int,int> dnevne);
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTeperaturu() const;
    int DajBrojTeperaturaVecihOd(int x) const;
    int DajBrojTeperaturaManjihOd(int x) const;
    friend bool operator !(Temperature &temp);
    friend Temperature &operator ++(Temperature &temp);
    friend Temperature operator ++(Temperature &temp, int);
    friend Temperature &operator --(Temperature &temp);
    friend Temperature operator --(Temperature &temp, int);
    friend std::vector<int> operator *(Temperature &temp);
    friend std::vector<int> operator +(Temperature &temp);
    friend std::vector<int> operator -(Temperature &temp);
    std::pair<int,int> operator [](int index) const;
    friend Temperature operator +(Temperature &temp, int y);
    friend Temperature operator -(Temperature &temp, int y);
    friend Temperature operator +(int x, Temperature &temp);
    friend Temperature operator -(int x, Temperature &temp);
    friend Temperature &operator +=(Temperature &temp1, const int y);
    friend Temperature &operator -=(Temperature &temp1, const int y);
    friend bool operator ==(const Temperature &temp1, const Temperature &temp2);
    friend bool operator !=(const Temperature &temp1, const Temperature &temp2);
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &temp);
};

Temperature::Temperature(int minimalna, int maximalna){
    if(minimalna>maximalna) throw std::range_error("Nekorektne temperature");
    min_dozvoljena=minimalna; max_dozvoljena=maximalna; 
}

void Temperature::RegistrirajTemperature(std::pair<int,int> dnevne){
    if(dnevne.first<min_dozvoljena || dnevne.second>max_dozvoljena || dnevne.first>dnevne.second)
        throw std::range_error("Nekorektne temperature");
    minimalne.push_back(dnevne.first); maximalne.push_back(dnevne.second);
    it1=minimalne.begin(); it2=maximalne.begin();
}

void Temperature::BrisiNegativneTemperature(){
    if(it1==minimalne.end() && it2==maximalne.end()) return;
    if(*it1 < 0 && *it2 < 0){ it1=minimalne.erase(it1); it2=maximalne.erase(it2); }
    else{ it1++; it2++; }
    Temperature::BrisiNegativneTemperature();
}

int Temperature::DajBrojRegistriranihTemperatura() const { return minimalne.size(); }

int Temperature::DajMinimalnuTemperaturu() const{
    if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return *(std::min_element(minimalne.begin(),minimalne.end()));
}

int Temperature::DajMaksimalnuTeperaturu() const{
    if(maximalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return *(std::max_element(maximalne.begin(),maximalne.end()));
}

int Temperature::DajBrojTeperaturaVecihOd(int x) const{
    if(maximalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(maximalne.begin(), maximalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
}

int Temperature::DajBrojTeperaturaManjihOd(int x) const{
    if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, x));
}

bool operator !(Temperature &temp){
    if(temp.maximalne.size()==0 && temp.minimalne.size()==0) return true;
    return false;
}

Temperature &operator ++(Temperature &temp){
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    if(*std::max_element(temp.minimalne.begin(),temp.minimalne.end()) > temp.min_dozvoljena) throw std::logic_error("Ilegalna operacija"); 
    return temp;
}

Temperature operator ++(Temperature &temp, int){
    Temperature pom(temp);
    ++temp;
    return pom;
}

Temperature &operator --(Temperature &temp){
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), temp.maximalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    if(*std::min_element(temp.maximalne.begin(),temp.maximalne.end()) < temp.min_dozvoljena) throw std::logic_error("Ilegalna operacija"); 
    return temp;
}

Temperature operator --(Temperature &temp, int){
    Temperature pom(temp); --temp; return pom;
}

std::vector<int> operator *(Temperature &temp){
    std::vector<int> rez;
    rez.resize(temp.maximalne.size());
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), temp.minimalne.begin(), rez.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 0));
    return rez;
}

std::vector<int> operator +(Temperature &temp){
    std::vector<int> rez; auto pom(temp.max_dozvoljena);
    rez.resize(temp.maximalne.size());
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), temp.minimalne.begin(), rez.begin(), std::bind(std::minus<int>(), pom, std::placeholders::_1));
    return rez;
}

std::vector<int> operator -(Temperature &temp){
    std::vector<int> rez; auto pom(temp.min_dozvoljena);
    rez.resize(temp.minimalne.size());
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.maximalne.begin(), rez.begin(), std::bind(std::minus<int>(), std::placeholders::_1, pom));
    return rez;
}

std::pair<int,int> Temperature::operator [](int index) const{
    if(index<1 || index>minimalne.size()) throw std::range_error("Neispravan indeks");
    index--;
    auto min = minimalne.begin();
    std::advance(min, index);
    auto max = maximalne.begin();
    std::advance(max, index);
    return std::make_pair(*min,*max);
}

Temperature operator +(Temperature &temp, int y){
    Temperature rez(temp.min_dozvoljena,temp.max_dozvoljena);
    rez.minimalne.resize(temp.minimalne.size()); rez.maximalne.resize(temp.maximalne.size());
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), rez.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), rez.maximalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    if(rez.DajMaksimalnuTeperaturu()>rez.max_dozvoljena || rez.DajMinimalnuTemperaturu()<rez.min_dozvoljena) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rez;
}

Temperature operator -(Temperature &temp, int y){
    Temperature rez(temp.min_dozvoljena,temp.max_dozvoljena);
    rez.minimalne.resize(temp.minimalne.size()); rez.maximalne.resize(temp.maximalne.size());
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), rez.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), rez.maximalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    if(rez.DajMaksimalnuTeperaturu()>rez.max_dozvoljena || rez.DajMinimalnuTemperaturu()<rez.min_dozvoljena) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rez;
}

Temperature operator +(int x, Temperature &temp){
    return temp+x;
}

Temperature operator -(int x, Temperature &temp){
    Temperature rez(temp.min_dozvoljena,temp.max_dozvoljena);
    rez.minimalne.resize(temp.minimalne.size()); rez.maximalne.resize(temp.maximalne.size());
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), rez.minimalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::transform(temp.maximalne.begin(), temp.maximalne.end(), rez.maximalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    if(rez.DajMaksimalnuTeperaturu()>rez.max_dozvoljena || rez.DajMinimalnuTemperaturu()<rez.min_dozvoljena) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rez;
}

bool operator ==(const Temperature &temp1, const Temperature &temp2){
    if(!(temp1.minimalne.size()==temp2.minimalne.size() && temp1.maximalne.size()==temp2.maximalne.size())) return false;
    auto provjera_minimalnih = std::equal(temp1.minimalne.begin(), temp1.minimalne.end(), temp2.minimalne.begin(), std::equal_to<int>());
    auto provjera_maximalnih = std::equal(temp1.maximalne.begin(), temp1.maximalne.end(), temp2.maximalne.begin(), std::equal_to<int>());
    if(provjera_maximalnih==true && provjera_minimalnih==true) return true;
    return false;
}

bool operator !=(const Temperature &temp1, const Temperature &temp2){
    return ! (temp1 == temp2);
}

std::ostream &operator <<(std::ostream &tok, const Temperature &temp){
    std::ostream_iterator<int> vanjski(tok," ");
    std::copy(temp.minimalne.begin(), temp.minimalne.end(), vanjski);
    std::cout << std::endl;
    std::copy(temp.maximalne.begin(), temp.maximalne.end(), vanjski);
    return tok;
}

Temperature &operator +=(Temperature &temp1, const int y){
    temp1=temp1+y;
    return temp1;
}

Temperature &operator -=(Temperature &temp1, const int y){
    temp1=temp1-y;
    return temp1;
}

int main ()
{
	//std::cout << "I dalje radiiii";
	Temperature t(-10,50);
	t.RegistrirajTemperature(std::make_pair(-10,-10));
	t.RegistrirajTemperature(std::make_pair(-9,-4));
	t.RegistrirajTemperature(std::make_pair(10,30));
	t.RegistrirajTemperature(std::make_pair(1,4));
	
	Temperature t2(0,60);
	t2.RegistrirajTemperature(std::make_pair(2,3));
	t2.RegistrirajTemperature(std::make_pair(2,4));
	t2.RegistrirajTemperature(std::make_pair(35,44));
	t2.RegistrirajTemperature(std::make_pair(1,3));
	try{
	    //t++; 
	    //t--;
	    auto rez(t+11);
	    //for(int i=0; i<rez.size(); i++)
	    std::cout << rez;
	}
	catch(...){ std::cout << "napokon belaj" << std::endl; }
	
	//std::cout << "MIN: " << t.DajMinimalnuTemperaturu() << " MAX: " << t.DajMaksimalnuTeperaturu() ;
	/*auto rez(-t);
	for(int i=0; i<rez.size(); i++){
	    std::cout << rez[i] << " " ;
	}*/
	//auto rez1(t[3]);
	//std::cout << rez1.first << " " << rez1.second ;
	//auto c=1-t;
	//std::cout << c;
	//std:: cout << t.DajMinimalnuTemperaturu();
	//std::cout << t.DajBrojTeperaturaVecihOd(20);
	//std::cout << t;
	//auto vec = -t;
	//for(int i=0; i<vec.size(); i++) std::cout << vec[i] << " ";
	//auto rez(t==t2);
	//std::cout << rez;
	//t.BrisiNegativneTemperature();
	//std::cout << t;
	return 0;
}