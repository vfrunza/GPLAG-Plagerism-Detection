#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
class Temperature{
     std::list<int>minimalne;
    std::list<int>maksima;
    
public:

Temperature(int mini,int maxi){std::pair<int,int>p; p.first=mini;p.second=maxi; RegistrirajTemperature(p);}
void RegistrirajTemperature(std::pair<int ,int >par){
     if(par.first>par.second ) throw std::range_error("Nekorektne temperature"); 
    else { minimalne.push_back(par.first); maksima.push_back(par.second);}
}
void BrisiSve() {
    auto it=maksima.begin(); it = maksima.erase(it); 
    auto p=minimalne.begin(); p=minimalne.erase(p);
}
/*void BrisiNegativneTemperature (){
    std::map<int,int>minmax;
   
    for_each(minimalne.begin(),minimalne.end(),)
   auto pokmin= std::find_if(minimalne.begin(), minimalne.end(),std::bind(std::less<int>(), std::placeholders::_1, 0)); 
   
   int poza=(pokmin-minimalne.begin());
   auto pokmax=std::find_if(maksima.begin(), maksima.end(),    std::bind(std::less<int>(), std::placeholders::_1, 0));
   int drugapoza=(pokmax-maksima.begin());
   if(poza==drugapoza) minimalne.remove(*pokmin); maksima.remove(*pokmax);
}*/
int DajBrojRegistriranihTemperatura() const;
int DajMinimalnuTemperaturu() const;
int DajMaksimalnuTemperaturu() const;
int DajBrojTeperaturaVecihOd(int zadana) const;
   
 

    
};

int Temperature::DajBrojRegistriranihTemperatura() const{
    if(minimalne.size()==0 || maksima.size()==0) throw std::logic_error("Nema registriranih temperatura");
     int l=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::greater<int>(), std::placeholders::_1, 0));
    int lp=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::less_equal<int>(), std::placeholders::_1, 0));
    int minimalac(l+lp);
    int r=std::count_if(maksima.begin(),maksima.end(),std::bind(std::greater<int>(), std::placeholders::_1, 0));
    int t=std::count_if(maksima.begin(),maksima.end(),std::bind(std::less_equal<int>(), std::placeholders::_1, 0));
    int maksimalacc(r+t);
    if(minimalac==maksimalacc) return minimalac;
}

int Temperature::DajMinimalnuTemperaturu() const{
    if(minimalne.size()==0 || maksima.size()==0) throw std::logic_error("Nema registriranih temperatura");
    if((*std::min_element(minimalne.begin(),minimalne.end()))<(*std::min_element(maksima.begin(),maksima.end()))){
	return (*std::min_element(minimalne.begin(),minimalne.end()));
}
else return *std::min_element(maksima.begin(),maksima.end());
}

int Temperature::DajMaksimalnuTemperaturu() const{
    if(minimalne.size()==0 || maksima.size()==0) throw std::logic_error("Nema registriranih temperatura");
    if((*std::max_element(minimalne.begin(),minimalne.end()))<(*std::max_element(maksima.begin(),maksima.end()))){
	return (*std::max_element(minimalne.begin(),minimalne.end()));
}
else return *std::max_element(maksima.begin(),maksima.end());
}

int Temperature::DajBrojTeperaturaVecihOd(int neka) const{
    if(minimalne.size()==0 || maksima.size()==0) throw std::logic_error("Nema registriranih temperatura");
    int prvi( std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,neka)));
    int drugi( std::count_if(maksima.begin(),maksima.end(),std::bind(std::greater<int>(),std::placeholders::_1,neka)));
    return prvi+drugi;
}






    

int main ()
{
    
    /*Temperature a(3,9);
    a.BrisiSve();
    auto it=a.maksima.begin();
    while(it!=a.maksima.end()){
    std::cout<<*it++;
    }*/
    
	return 0;
}