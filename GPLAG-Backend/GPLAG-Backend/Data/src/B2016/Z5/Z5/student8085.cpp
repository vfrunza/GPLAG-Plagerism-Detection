/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <utility>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
#include <cmath>

using std::vector;
using std::list;
using std::pair;
using std::cout;

class Temperature
{
    list<int> min,max;
    int mala,velika;
    void Provjeri()const
    {
        if(min.empty() or max.empty())
            throw std::logic_error("Nema registriranih temperatura");
    }
    public:
    Temperature(int m,int v)
    {
        if(m>v)
            throw std::range_error("Nekorektne temperature");
        mala=m;
        velika=v;
    }
    void RegistrirajTemperature(pair<int,int> par)
    {
        bool neg1(false),neg2(false);
        if(par.first<0)
            neg1=true;
        if(par.second<0)
            neg2=true;
        if(par.first<0 and mala<0 and std::abs(mala)<std::abs(par.first))
            throw std::range_error("Nekorektne temperature");
        else if(par.second<0 and velika<0 and std::abs(velika)>std::abs(par.second))
            throw std::range_error("Nekorektne temperature");
        if(neg1 and neg2 and par.first>par.second)
            throw std::range_error("Nekorektne temperature");
        if(neg2 and !neg1)
            throw std::range_error("Nekorektne temperature");
        if(!neg1 and !neg2)
            if(par.first>par.second or par.first<mala or par.second>velika)
                throw std::range_error("Nekorektne temperature");
        min.push_back(par.first);
        max.push_back(par.second);
    }
    void BrisiSve()
    {
        min.clear();
        max.clear();
        mala=0;
        velika=0;
    }
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura()
    {
        if(min.size()!=max.size())
            cout<<"Nemojte prckati po internim stvarima!!";
        return min.size();
        
    }
    int DajMinimalnuTemperaturu()const;
    int DajMaksimalnuTemperaturu()const;
    int DajBrojTemperaturaVecihOd(int x)const;
    int DajBrojTemperaturaManjihOd(int x)const;
    bool operator!()const;
    Temperature &operator ++();
    Temperature operator ++(int);
    Temperature &operator --();
    Temperature operator --(int);
    vector<int> operator *();
    vector<int> operator +();
    vector<int> operator -();
    pair<int,int> operator [](int x);
    Temperature &operator +=(int b);
    Temperature &operator -=(int b);
    Temperature operator +(int b);
    Temperature operator -(int b);
    friend Temperature operator +(int a,Temperature b);
    friend Temperature operator -(int a,Temperature b);
    friend bool operator ==(const Temperature &a,const Temperature &b);
    friend bool operator !=(const Temperature &a,const Temperature &b);
    friend std::ostream &operator <<(std::ostream &tok,const Temperature &a);
};
std::ostream &operator <<(std::ostream &tok,const Temperature &a)
{
    std::ostream_iterator<int> it(tok," ");
    std::copy(a.min.begin(),a.min.end(),it);
    tok<<"\n";
    std::copy(a.max.begin(),a.max.end(),it);
    return tok;
}
bool operator ==(const Temperature &a,const Temperature &b)
{
    return a.min == b.min and a.max == b.max and a.mala == b.mala and a.velika == b.velika;
}
bool operator !=(const Temperature &a,const Temperature &b)
{
    return !(a == b);
}
Temperature operator +(int a,Temperature b)
{
    return b+=a;
}
Temperature operator -(int a,Temperature b)
{
    return b-=a;
}
Temperature Temperature::operator +(int b)
{
    return *this+=b;
}
Temperature Temperature::operator -(int b)
{
    return *this-=b;
}
Temperature &Temperature::operator +=(int b)
{
    if(b<0)
        *this-=(-b);
    else
    {
    auto pomoc2=+(*this);
    auto brojac=std::count_if(pomoc2.begin(),pomoc2.end(),std::bind(std::less<int>(),std::placeholders::_1,b));
    if(brojac)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(min.begin(),min.end(),min.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b));
    std::transform(max.begin(),max.end(),max.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b));
    }
    return *this;
}
Temperature &Temperature::operator -=(int b)
{
    if(b<0)
        *this+=(-b);
    else{
    auto pomoc=-(*this);
    auto brojac=std::count_if(pomoc.begin(),pomoc.end(),std::bind(std::less<int>(),std::placeholders::_1,b));
    if(brojac)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(min.begin(),min.end(),min.begin(),std::bind(std::minus<int>(),std::placeholders::_1,b));
    std::transform(max.begin(),max.end(),max.begin(),std::bind(std::minus<int>(),std::placeholders::_1,b));
    }
    return *this;
}
pair<int,int> Temperature::operator [](int x)
{
    if(x<=0 or x>min.size())
        throw std::range_error("Neispravan indeks");
    //znam da je ruzno sljedece rjesenje ali sta cu :(
    vector<int> v1(min.size()),v2(max.size());
    std::copy(min.begin(),min.end(),v1.begin());
    std::copy(max.begin(),max.end(),v2.begin());
    return {v1[x-1],v2[x-1]};
}
vector<int> Temperature::operator -()
{
    vector<int> v(min.size());
    std::transform(min.begin(),min.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,mala));
    return v;
}
vector<int> Temperature::operator +()
{
    vector<int> v(max.size());
    std::transform(max.begin(),max.end(),v.begin(),std::bind(std::minus<int>(),velika,std::placeholders::_1));
    return v;
}
vector<int> Temperature::operator *()
{
    vector<int> v(min.size());
    std::transform(min.begin(),min.end(),max.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_2,std::placeholders::_1));
    return v;
}
Temperature &Temperature::operator ++()
{
    auto pomoc=*(*this);
    auto brojac=std::count_if(pomoc.begin(),pomoc.end(),std::bind(std::less<int>(),std::placeholders::_1,1));
    if(brojac)
        throw std::logic_error("Ilegalna operacija");
    std::transform(min.begin(),min.end(),min.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature &Temperature::operator --()
{//zavrsi prepisivanje -- i za prefiksni isto a onda tek + - binarne
    auto pomoc=*(*this);
    auto brojac=std::count_if(pomoc.begin(),pomoc.end(),std::bind(std::less<int>(),std::placeholders::_1,1));
    if(brojac)
        throw std::logic_error("Ilegalna operacija");
    std::transform(max.begin(),max.end(),max.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature Temperature::operator ++(int)
{
    Temperature pomoc(mala,velika);
    pomoc.min.resize(min.size());
    pomoc.max.resize(max.size());
    std::copy(min.begin(),min.end(),pomoc.min.begin());
    std::copy(max.begin(),max.end(),pomoc.max.begin());
    ++(*this);
    return pomoc;
}
Temperature Temperature::operator --(int)
{
    Temperature pomoc(mala,velika);
    pomoc.min.resize(min.size());
    pomoc.max.resize(max.size());
    std::copy(min.begin(),min.end(),pomoc.min.begin());
    std::copy(max.begin(),max.end(),pomoc.max.begin());
    --(*this);
    return pomoc;
}
bool Temperature::operator!()const
{
    if(min.empty() and max.empty())
        return true;
    return false;
}
int Temperature::DajBrojTemperaturaManjihOd(int x)const
{
    Provjeri();
    int prvi=std::count_if(min.begin(),min.end(),std::bind(std::less<int>(),std::placeholders::_1,x));
    int drugi=std::count_if(max.begin(),max.end(),std::bind(std::less<int>(),std::placeholders::_1,x));
    return prvi+drugi;
}
int Temperature::DajBrojTemperaturaVecihOd(int x)const
{
    Provjeri();
    int prvi=std::count_if(min.begin(),min.end(),std::bind(std::greater<int>(),std::placeholders::_1,x));
    int drugi=std::count_if(max.begin(),max.end(),std::bind(std::greater<int>(),std::placeholders::_1,x));
    return prvi+drugi;
}
int Temperature::DajMinimalnuTemperaturu()const
{
    Provjeri();
    return *std::min_element(min.begin(),min.end());
}
int Temperature::DajMaksimalnuTemperaturu()const
{
    Provjeri();
    return *std::max_element(max.begin(),max.end());
}
void Temperature::BrisiNegativneTemperature()
{
    static int i=0;
    if(i>=min.size())
        return;
    auto b=(*this)[i];
    if(b.first<0 and b.second<0)
    {
        auto it=std::find(min.begin(),min.end(),b.first);
        min.erase(it);
        it=find(max.begin(),max.end(),b.second);
        max.erase(it);
    }
    i++;
    Temperature::BrisiNegativneTemperature();
}
int main ()
{
//AT9 - testiranje operatora pristupa[] i izuzetka
{
    Temperature a(-14,19);
    a.RegistrirajTemperature({1,3});
    a.RegistrirajTemperature({1,4});
    a.RegistrirajTemperature({-3,7});
    a.RegistrirajTemperature({1,3});
    a.RegistrirajTemperature({2,5});
    a.RegistrirajTemperature({-5,6});
    
    std::vector<std::pair<int,int>> temperature;
    try
    {
        for (int i{0}; i < a.DajBrojRegistriranihTemperatura(); i++)
        {
            temperature.push_back(a[i]);
            std::cout << "Ovo se ne smije ispisati.";
        }
    }
    catch(const std::range_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        for (int i{1}; i <= a.DajBrojRegistriranihTemperatura(); i++)
            temperature.push_back(a[i]);
    }
    catch(const std::range_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    for(auto t : temperature)   
        std::cout << t.first << " " << t.second << std::endl;
}
	return 0;
}