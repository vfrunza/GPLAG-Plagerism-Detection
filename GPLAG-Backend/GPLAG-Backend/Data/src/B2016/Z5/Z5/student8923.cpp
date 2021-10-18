/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::list;
class Temperature
{
    private:
    list<int> lista_minimalnih;
    list<int> lista_maksimalnih;
    int min;
    
    int maks;
    public:
    Temperature(int minimalna,int maksimalna);
    void RegistrirajTemperature(pair<int,int> par_min_maks);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const{return lista_minimalnih.size();}
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temperatura) const;
    int DajBrojTemperaturaManjihOd(int temperatura) const;
    bool operator !(){if(lista_minimalnih.size()==0) return true; return false;}
    friend Temperature &operator ++(Temperature &temperature);
    friend Temperature operator ++(Temperature &temperature,int);
    friend Temperature &operator --(Temperature &temperature);
    friend Temperature operator --(Temperature &temperature,int);
    friend vector<int> operator *(Temperature temperature);
    friend vector<int> operator -(Temperature temperature);
    friend vector<int> operator +(Temperature temperature);
    pair<int,int> operator [](int indeks);
    friend bool operator ==(const Temperature &t1,const Temperature &t2);
    friend bool operator !=(const Temperature &t1,const Temperature &t2);
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t); //pokusati uraditi
    friend Temperature operator +(Temperature x,int y);
    friend Temperature operator +(int y,Temperature x);
    friend Temperature operator -(Temperature x,int y);
    friend Temperature operator -(int y,Temperature x);
    friend Temperature operator +(double y,Temperature x)=delete;
    friend Temperature operator -(double y,Temperature x)=delete;
    friend Temperature operator +(Temperature x,double y)=delete;
    friend Temperature operator -(Temperature x,double y)=delete;
    friend Temperature operator +=(Temperature &x,int y);
    friend Temperature operator -=(Temperature &x,int y);
    friend Temperature operator +=(const Temperature &x,double y)=delete;
    friend Temperature operator -=(const Temperature &x,double y)=delete;
   // friend Temperature operator +=(int y,Temperature &x);   //je li treba?
   // friend Temperature operator -=(int y,Temperature &x);   //je li treba?
   // friend Temperature operator +=(double y,Temperature &x)=delete;
  //  friend Temperature operator -=(double y,Temperature &x)=delete;
};
Temperature::Temperature(int minimalna,int maksimalna)
{
    if(minimalna>maksimalna) throw std::range_error("Nekorektne temperature");
    min=minimalna;
    maks=maksimalna;
}
void Temperature::RegistrirajTemperature(pair<int,int> par_min_maks)
{
    if(par_min_maks.first>par_min_maks.second) throw std::range_error("Nekorektne temperature");
    if(par_min_maks.first<min || par_min_maks.second<min || par_min_maks.first>maks || par_min_maks.second>maks)
    throw std::range_error("Nekorektne temperature");
    lista_minimalnih.push_back(par_min_maks.first);
    lista_maksimalnih.push_back(par_min_maks.second);
}
void Temperature::BrisiSve()
{
    list<int> pom;
    lista_minimalnih=pom;
    lista_maksimalnih=pom;
}
void Temperature::BrisiNegativneTemperature()
{
    auto it1=std::find_if(lista_minimalnih.begin(),lista_minimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,0));
    auto it2=std::find_if(lista_maksimalnih.begin(),lista_maksimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,0));
    if(it1==lista_minimalnih.end() || it2==lista_maksimalnih.end())
    return;
    if(std::distance(lista_minimalnih.begin(),it1)==std::distance(lista_maksimalnih.begin(),it2))
    {
        it1=lista_minimalnih.erase(it1);
        it2=lista_maksimalnih.erase(it2);
        if(it1==lista_minimalnih.end() || it2==lista_maksimalnih.end())
        return;
        else
        this->BrisiNegativneTemperature();
    }
}
int Temperature::DajMinimalnuTemperaturu() const
{
    if(lista_maksimalnih.size()==0) throw std::logic_error("Nema registriranih temperatura");
    int pom=*std::min_element(lista_minimalnih.begin(),lista_minimalnih.end());
    return pom;
}
int Temperature::DajMaksimalnuTemperaturu() const
{
    if(lista_minimalnih.size()==0) throw std::logic_error("Nema registriranih temperatura");
    int pom=*std::max_element(lista_maksimalnih.begin(),lista_maksimalnih.end());
    return pom;
}
int Temperature::DajBrojTemperaturaVecihOd(int temperatura) const
{
    if(lista_minimalnih.size()==0) throw std::logic_error("Nema registriranih temperatura");
    int pom=std::count_if(lista_maksimalnih.begin(),lista_maksimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperatura));
    return pom;
}
int Temperature::DajBrojTemperaturaManjihOd(int temperatura) const
{
    if(lista_minimalnih.size()==0) throw std::logic_error("Nema registriranih temperatura");
    int pom=std::count_if(lista_minimalnih.begin(),lista_minimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,temperatura));
    return pom;
}
Temperature &operator ++(Temperature &temperature)
{
    Temperature pom_temp=temperature;
    std::transform(temperature.lista_minimalnih.begin(),temperature.lista_minimalnih.end(),temperature.lista_minimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    int pom=std::count_if(temperature.lista_minimalnih.begin(),temperature.lista_minimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperature.maks));
    int pom2=std::count_if(temperature.lista_minimalnih.begin(),temperature.lista_minimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperature.DajMaksimalnuTemperaturu()));
    if(pom!=0 || pom2!=0) {temperature=pom_temp; throw std::logic_error("Ilegalna operacija");}
    return temperature;
}
Temperature operator ++(Temperature &temperature,int)
{
    Temperature pom_temp=temperature;
     std::transform(temperature.lista_minimalnih.begin(),temperature.lista_minimalnih.end(),pom_temp.lista_minimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    int pom=std::count_if(pom_temp.lista_minimalnih.begin(),pom_temp.lista_minimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperature.maks));
    int pom2=std::count_if(pom_temp.lista_minimalnih.begin(),pom_temp.lista_minimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperature.DajMaksimalnuTemperaturu()));
    if(pom!=0 || pom2!=0) throw std::logic_error("Ilegalna operacija");
    temperature=pom_temp;
    return pom_temp;
}
Temperature &operator --(Temperature &temperature)
{
    Temperature pom_temp=temperature;
    std::transform(temperature.lista_maksimalnih.begin(),temperature.lista_maksimalnih.end(),temperature.lista_maksimalnih.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    int pom=std::count_if(temperature.lista_maksimalnih.begin(),temperature.lista_maksimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,temperature.min));
     int pom2=std::count_if(temperature.lista_maksimalnih.begin(),temperature.lista_maksimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,temperature.DajMinimalnuTemperaturu()));
    if(pom!=0 || pom2!=0) {temperature=pom_temp; throw std::logic_error("Ilegalna operacija");}
    return temperature;
}
Temperature operator --(Temperature &temperature,int)
{
    Temperature pom_temp=temperature;
     std::transform(temperature.lista_maksimalnih.begin(),temperature.lista_maksimalnih.end(),pom_temp.lista_maksimalnih.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    int pom=std::count_if(pom_temp.lista_maksimalnih.begin(),pom_temp.lista_maksimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,temperature.min));
    int pom2=std::count_if(pom_temp.lista_maksimalnih.begin(),pom_temp.lista_maksimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,temperature.DajMinimalnuTemperaturu()));
    if(pom!=0 || pom2!=0) throw std::logic_error("Ilegalna operacija");
    temperature=pom_temp;
    return pom_temp;
}
vector<int> operator *(Temperature t)
{
    vector<int> v(t.lista_minimalnih.size());
    std::transform(t.lista_maksimalnih.begin(),t.lista_maksimalnih.end(),t.lista_minimalnih.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    return v;
}
vector<int> operator -(Temperature t)
{
    vector<int> v(t.lista_minimalnih.size());
    std::transform(t.lista_minimalnih.begin(),t.lista_minimalnih.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,t.min));
    return v;
}
vector<int> operator +(Temperature t)
{
    vector<int> v(t.lista_maksimalnih.size());
    std::transform(t.lista_minimalnih.begin(),t.lista_minimalnih.end(),v.begin(),std::bind(std::minus<int>(),t.maks,std::placeholders::_1));
    return v;
}
pair<int,int> Temperature::operator [](int indeks)
{
    if(indeks<1 || indeks>lista_minimalnih.size())
    throw std::range_error("Neispravan indeks");
    auto it1=lista_minimalnih.begin();
    auto it2=lista_maksimalnih.begin();
    std::advance(it1,indeks-1);
    std::advance(it2,indeks-1);
    pair<int,int> par;
    par=std::make_pair(*it1,*it2);
    return par;
}
bool operator ==(const Temperature &t1,const Temperature &t2)
{
    if(t1.min!=t2.min || t1.maks!=t2.maks || t2.lista_minimalnih.size()!=t1.lista_minimalnih.size() || t2.lista_maksimalnih.size()!=t1.lista_maksimalnih.size()) return false;
    bool pom1(false),pom2(false);
    pom1=std::equal(t1.lista_minimalnih.begin(),t1.lista_minimalnih.end(),t2.lista_minimalnih.begin(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
    pom2=std::equal(t1.lista_maksimalnih.begin(),t1.lista_maksimalnih.end(),t2.lista_maksimalnih.begin(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
if(pom1 && pom2) return true;
return false;
}
inline bool operator !=(const Temperature &t1,const Temperature &t2)
{
    return (!(t1==t2));
}
Temperature operator +(Temperature x,int y)
{
    std::transform(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),x.lista_maksimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    std::transform(x.lista_minimalnih.begin(),x.lista_minimalnih.end(),x.lista_minimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    int pom=std::count_if(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.maks));
    if(pom!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return x;
}
Temperature operator +(int y,Temperature x)
{
    std::transform(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),x.lista_maksimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    std::transform(x.lista_minimalnih.begin(),x.lista_minimalnih.end(),x.lista_minimalnih.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    int pom=std::count_if(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.maks));
    if(pom!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return x;
}
Temperature operator -(Temperature x,int y)
{
    std::transform(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),x.lista_maksimalnih.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    std::transform(x.lista_minimalnih.begin(),x.lista_minimalnih.end(),x.lista_minimalnih.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    int pom=std::count_if(x.lista_minimalnih.begin(),x.lista_minimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,x.min));
    if(pom!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return x;
}
Temperature operator -(int y,Temperature x)
{
    Temperature pom(x);
    std::transform(x.lista_maksimalnih.begin(),x.lista_maksimalnih.end(),pom.lista_minimalnih.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    std::transform(x.lista_minimalnih.begin(),x.lista_minimalnih.end(),pom.lista_maksimalnih.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    int pom1=std::count_if(pom.lista_minimalnih.begin(),pom.lista_minimalnih.end(),std::bind(std::less<int>(),std::placeholders::_1,x.min));
    int pom2=std::count_if(pom.lista_maksimalnih.begin(),pom.lista_maksimalnih.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.maks));
    if(pom1!=0 || pom2!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return pom;
}
inline Temperature operator +=(Temperature &x,int y)
{
    x=x+y;
    return x;
}
inline Temperature operator -=(Temperature &x,int y)
{
    x=x-y;
    return x;
}
/*inline Temperature operator +=(int y,Temperature &x)    //je li treba?
{
    x=y+x;;
    return x;
}
inline Temperature operator -=(int y,Temperature x)       //je li treba?
{
    x=y-x;
    return x;
}*/
std::ostream &operator <<(std::ostream &tok, const Temperature &t)
{
   if(t.lista_maksimalnih.size()!=0)
   {
   Temperature pom_t(t);
   if(pom_t.lista_minimalnih.size()!=0)
   {
   auto it1=pom_t.lista_minimalnih.begin();
   tok<<*it1<<" ";
   it1=pom_t.lista_minimalnih.erase(it1);
   
   if(pom_t.lista_minimalnih.size()==0)
    tok<<'\n';
   operator<<(tok,pom_t);
   }
   else if(pom_t.lista_maksimalnih.size()!=0)
   {
    auto it1=pom_t.lista_maksimalnih.begin();
   tok<<*it1<<" ";
   it1=pom_t.lista_maksimalnih.erase(it1);
   if(pom_t.lista_maksimalnih.size()!=0)
   operator<<(tok,pom_t);
   }
   }
   return tok;
}
int main ()
{
Temperature a(-14,19);
    a.RegistrirajTemperature({1,3});
    a.RegistrirajTemperature({1,4});
    a.RegistrirajTemperature({-3,7});
    a.RegistrirajTemperature({1,3});
    a.RegistrirajTemperature({2,5});
    a.RegistrirajTemperature({-5,6});
    
    std::vector<std::pair<int,int>> temperature;
    a++;
    
    for (int i{1}; i <= a.DajBrojRegistriranihTemperatura(); i++)
        temperature.push_back(a[i]);
    
    for(auto t : temperature)   
        std::cout << t.first << " " << t.second << std::endl;
        
    temperature.resize(0);
    a--;
    std::cout << std::endl;
    for (int i{1}; i <= a.DajBrojRegistriranihTemperatura(); i++)
        temperature.push_back(a[i]);
    
    for(auto t : temperature)   
        std::cout << t.first << " " << t.second << std::endl;
        
    try
    {
        std::cout << std::endl;
        a++;
        std::cout << "Ovo se ne smije ispisati.";
    }
    catch (const std::logic_error& e)
    {
        std::cout << e.what();
        temperature.resize(0);

        std::cout << std::endl;
        for (int i{1}; i <= a.DajBrojRegistriranihTemperatura(); i++)
            temperature.push_back(a[i]);
    
        for(auto t : temperature)   
            std::cout << t.first << " " << t.second << std::endl;
    }
    
    try
    {
        std::cout << std::endl;
        a--;
        std::cout << "Ovo se ne smije ispisati.";
    }
    catch (const std::logic_error& e)
    {
        std::cout << e.what();
        temperature.resize(0);

        std::cout << std::endl;
        for (int i{1}; i <= a.DajBrojRegistriranihTemperatura(); i++)
            temperature.push_back(a[i]);
    
        for(auto t : temperature)   
            std::cout << t.first << " " << t.second << std::endl;
    }
    return 0;
}