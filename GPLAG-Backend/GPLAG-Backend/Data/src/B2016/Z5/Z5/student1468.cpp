/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <functional>


class Temperature
{
    std::list<int> minimalne_temperature;
    std::list<int> maximalne_temperature;
    int minimalna__dozvoljena_temperatura;
    int maximalna_dozvoljena_temperatura;
    
public:
    Temperature (int min, int max) 
    {
   
    minimalna__dozvoljena_temperatura=min;
    maximalna_dozvoljena_temperatura=max;
    if (min>max) throw std::range_error ("Nekorektne temperature");

    }
    void RegistrirajTemperature (std::pair <int,int> temperature);
    void BrisiSve ();
    int DajBrojRegistriranihTemperatura() const ;
    int  DajMinimalnuTemperaturu () const ;
    int  DajMaximalnuTemperaturu () const ;
    int  DajBrojTemperaturaVecihod (int temperatura) const ;
    int DajBrojTemperaturaManjihOd(int temperatura) const ;
    void BrisiTemperature (std::pair<int,int> temperature);

 bool operator ! () const 
{
    return (minimalne_temperature.empty());
}

Temperature &operator ++ ()
{
    std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind (std::plus<int>(),1,std::placeholders::_1));
    if(!std::equal(minimalne_temperature.begin(),minimalne_temperature.end(),maximalne_temperature.begin(),std::less_equal<int>()))
    {
        std::transform (minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
        throw std::logic_error("Ilegalna operacija");
    }
    return *this;
 
}
// sve minimalne dnevne temperature
// logic_error


Temperature  &operator -- ()
{
    std::transform (maximalne_temperature.begin(),maximalne_temperature.end(),maximalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    if(!std::equal(maximalne_temperature.begin(),maximalne_temperature.end(),minimalne_temperature.begin(),std::greater_equal<int>()))
    {
        std::transform (maximalne_temperature.begin(),maximalne_temperature.end(),maximalne_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
        throw std::logic_error("Ilegalna operacija");
    }
    return *this;
}
// logic_error

Temperature operator ++ (int)
{
    Temperature t (*this);
    std::transform (minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    //kopirano iz operator++()
    if(!std::equal(minimalne_temperature.begin(),minimalne_temperature.end(),maximalne_temperature.begin(),std::less_equal<int>()))
    {
        std::transform (minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
        throw std::logic_error("Ilegalna operacija");
    }
    return t;
}
// postfiksni
// logic_error

Temperature operator -- (int)
{
    Temperature t (*this);
    std::transform (maximalne_temperature.begin(),maximalne_temperature.end(),maximalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    //kopirano iz Temperature &operator --()
    if(!std::equal(maximalne_temperature.begin(),maximalne_temperature.end(),minimalne_temperature.begin(),std::greater_equal<int>()))
    {
        std::transform (maximalne_temperature.begin(),maximalne_temperature.end(),maximalne_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
        throw std::logic_error("Ilegalna operacija");
    }
    return t;
}
// postfiksni
// logic_error
Temperature &operator +=(int Y)
{
    *this = *this + Y;
    return *this;
}

Temperature &operator -=(int Y)
{
    *this = *this + Y;
    return *this;
}

std::pair<int, int> operator [](int i);

friend std::vector<int> operator *(Temperature X);
friend std::vector<int> operator +(Temperature X);
friend std::vector<int> operator -(Temperature X);
friend Temperature operator +(Temperature X, int Y);
friend Temperature operator +(int Y, Temperature X);
friend Temperature operator -(Temperature X, int Y);
friend Temperature operator -(int Y, Temperature X);
friend bool operator ==(Temperature X, Temperature Y);
friend bool operator !=(Temperature X, Temperature Y);
friend std::ostream &operator <<(std::ostream &tok, Temperature X);

};

std::vector<int> operator *(Temperature X)
{
    std::vector<int> razlika(X.minimalne_temperature.size());
    std::vector<int>::iterator razlike(razlika.begin());
    std::transform (X.maximalne_temperature.begin(), X.maximalne_temperature.end(), X.minimalne_temperature.begin(),razlike,std::minus<int>());
    return razlika;
    
}


std::vector<int> operator + (Temperature X)
{
    std::vector<int> v(X.minimalne_temperature.size());
    std::vector<int>::iterator razlike (v.begin());
    std::transform(X.maximalne_temperature.begin(), X.maximalne_temperature.end(),razlike,std::bind(std::minus<int>(), X.maximalna_dozvoljena_temperatura,std::placeholders::_1));
    return v;
}


std::vector<int> operator - (Temperature X)
{
    std::vector<int> v(X.minimalne_temperature.size());
    std::vector<int>::iterator razlike(v.begin());
    std::transform(X.minimalne_temperature.begin(), X.minimalne_temperature.end(),razlike,std::bind(std::minus<int>(),std::placeholders::_1, X.minimalna__dozvoljena_temperatura));
    return v;
}

std::pair<int,int> Temperature::operator [] (int i)
{

    // range_error
    if(i < 1 || i > DajBrojRegistriranihTemperatura())
        throw std::range_error("Neispravan indeks");
    std::pair<int,int> temp;
    auto it (minimalne_temperature.begin());
    std::advance(it,i-1);
    auto it1(maximalne_temperature.begin());
    std::advance(it1,i-1);
    temp.second=*it1;
    temp.first=*it;
    // omogućava da numeracija ide od 1
    return temp;
} 

// ne može se koristiti sa lijeve strane jednakosti

Temperature operator + (Temperature X, int Y)
{
    std::transform (X.minimalne_temperature.begin(),X.minimalne_temperature.end(),X.minimalne_temperature.begin(),std::bind(std::plus<int>(),Y,std::placeholders::_1));
    std::transform (X.maximalne_temperature.begin(),X.maximalne_temperature.end(),X.maximalne_temperature.begin(),std::bind(std::plus<int>(),Y,std::placeholders::_1));
    if(std::count_if(X.minimalne_temperature.begin(), X.minimalne_temperature.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, X.minimalna__dozvoljena_temperatura)) || std::count_if(X.maximalne_temperature.begin(), X.maximalne_temperature.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, X.maximalna_dozvoljena_temperatura)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return X;
}

Temperature operator +(int Y, Temperature X)
{
    return X + Y;
}
// logic_error


Temperature operator -(Temperature X, int Y)
{
    std::transform (X.minimalne_temperature.begin(),X.minimalne_temperature.end(),X.minimalne_temperature.begin(),std::bind (std::minus<int>(),std::placeholders::_1,Y));
    std::transform (X.maximalne_temperature.begin(),X.maximalne_temperature.end(),X.minimalne_temperature.begin(),std::bind (std::minus<int>(),std::placeholders::_1,Y));
    if(std::count_if(X.minimalne_temperature.begin(), X.minimalne_temperature.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, X.minimalna__dozvoljena_temperatura)) || std::count_if(X.maximalne_temperature.begin(), X.maximalne_temperature.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, X.maximalna_dozvoljena_temperatura)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return X;
}

Temperature operator -(int Y, Temperature X)
{
    std::transform(X.minimalne_temperature.begin(), X.minimalne_temperature.end(), X.minimalne_temperature.begin(), std::bind(std::minus<int>(),Y,std::placeholders::_1));
    std::transform(X.maximalne_temperature.begin(), X.maximalne_temperature.end(), X.minimalne_temperature.begin(), std::bind(std::minus<int>(),Y,std::placeholders::_1));
    std::list<int> temp(X.minimalne_temperature);
    X.minimalne_temperature = X.maximalne_temperature;
    X.maximalne_temperature = temp;
    if(std::count_if(X.minimalne_temperature.begin(), X.minimalne_temperature.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, X.minimalna__dozvoljena_temperatura)) || std::count_if(X.maximalne_temperature.begin(), X.maximalne_temperature.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, X.maximalna_dozvoljena_temperatura)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return X;
}
// logic error

bool operator == (Temperature X,Temperature Y)
{
   if (X.minimalne_temperature.size()!=Y.minimalne_temperature.size() || X.minimalna__dozvoljena_temperatura!=Y.minimalna__dozvoljena_temperatura  ||  X.maximalna_dozvoljena_temperatura!=Y.maximalna_dozvoljena_temperatura) return false;
    bool jednake_minimalne_temperature;
    jednake_minimalne_temperature = std::equal(X.minimalne_temperature.begin(), X.minimalne_temperature.end(), Y.minimalne_temperature.begin());
    bool jednake_maximalne_temperature;
    jednake_maximalne_temperature = std::equal(X.maximalne_temperature.begin(), X.maximalne_temperature.end(), Y.maximalne_temperature.begin());
    if(jednake_maximalne_temperature && jednake_minimalne_temperature)
        return true;
    return false;
}

bool operator !=(Temperature X, Temperature Y)
{
    return !(X == Y);
}


std::ostream &operator << (std::ostream &tok,Temperature T)
{ 
    std::ostream_iterator<int> t(tok," ");
    std::copy (T.minimalne_temperature.begin(),T.minimalne_temperature.end(),t);
    tok<<std::endl;  // ostream iterator
    std::copy (T.maximalne_temperature.begin(),T.maximalne_temperature.end(),t);
    return tok;
}

// min i max temp koja se može registrirati


void Temperature::RegistrirajTemperature (std::pair <int,int> temperature ) //  min i max dnevnu temperaturu
{
    if (temperature.first<minimalna__dozvoljena_temperatura
    || temperature.second<minimalna__dozvoljena_temperatura || temperature.first>maximalna_dozvoljena_temperatura || temperature.second>maximalna_dozvoljena_temperatura ) throw std::range_error ("jdfkf");

    minimalne_temperature.push_back(temperature.first);
    maximalne_temperature.push_back (temperature.second);

}

void Temperature:: BrisiSve ()
{
    minimalne_temperature.resize(0);
    maximalne_temperature.resize(0);
}

void Temperature::BrisiTemperature (std::pair<int,int> temperature)
{
    auto it1(std::find(std::begin(minimalne_temperature),std::end(minimalne_temperature),temperature.first));
    auto it2(std::find(std::begin(maximalne_temperature),std::end(minimalne_temperature),temperature.second));


    if (it1!= std::end(minimalne_temperature)) {
        minimalne_temperature.erase(it1);

    } else {
        throw std::logic_error ("Takve temperature nisu registrirane");
    }



    if (it2!=maximalne_temperature.end()) maximalne_temperature.erase(it2);
    else {
        throw std::logic_error ("Takve temperature nisu registrirane");
    }
}

int Temperature::DajBrojRegistriranihTemperatura() const
{
    return minimalne_temperature.size();
}
int Temperature::DajMinimalnuTemperaturu () const 
{
    return *(std::min_element(minimalne_temperature.begin(),minimalne_temperature.end()));   // izuzetak
}
int Temperature:: DajMaximalnuTemperaturu () const 
{
    return *(std::max_element(maximalne_temperature.begin(),maximalne_temperature.end()));   // izuzetak
}

int Temperature::DajBrojTemperaturaVecihod (int temperatura) const 
{
    return std::count_if (maximalne_temperature.begin(),maximalne_temperature.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperatura));
}


// izuzetak
int Temperature::DajBrojTemperaturaManjihOd (int temperatura) const 
{
    return std::count_if(minimalne_temperature.begin(),minimalne_temperature.end(),std::bind(std::less<int>(),std::placeholders::_1,temperatura));
}
// izuzetak


int main ()
{
    Temperature temp(-20, 40);
    temp.RegistrirajTemperature(std::pair<int,int>(5,34));
    temp.RegistrirajTemperature(std::pair<int,int>(20,30));
    temp.RegistrirajTemperature(std::pair<int,int>(0,25));
    temp.RegistrirajTemperature(std::pair<int,int>(-5,16));
    temp.RegistrirajTemperature(std::pair<int,int>(-10,39));
    std::cout << "Registrovano je " << temp.DajBrojRegistriranihTemperatura() << " temperatura." << std::endl;
    --temp;
    temp++;
    temp--;
    ++temp;
    std::cout << temp << std::endl;
    std::cout << temp - 3 << std::endl;
    std::cout << temp + 1 << std::endl;
    std::cout << 30 - temp << std::endl;
    std::vector<int> rez1(*temp), rez2(+temp), rez3(-temp);
    for(int element : rez1)
        std::cout << element << " ";
    std::cout << std::endl;
    for(int element : rez2)
        std::cout << element << " ";
    std::cout << std::endl;
    for(int element : rez3)
        std::cout << element << " ";
    std::cout << std::endl;
    std::cout << temp.DajBrojTemperaturaManjihOd(15) << " " << temp.DajBrojTemperaturaVecihod(15) << std::endl;
    return 0;
}