/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

class Temperature {
    std::list<int> min;
    std::list<int> max;
    int min_dozvoljena,max_dozvoljena;
    public:
    Temperature(int minimalna, int maksimalna);
    void RegistrirajTemperature(std::pair<int,int> t);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int zadana) const;
    int DajBrojTemperaturaManjihOd(int zadana) const;
    friend bool operator !(Temperature t);
    friend Temperature operator ++(Temperature &t);
    friend Temperature operator ++(Temperature &t, int);
    friend Temperature operator --(Temperature &t);
    friend Temperature operator --(Temperature &t, int);
    friend std::vector<int> operator * (const Temperature &t);
    friend std::vector<int> operator - (const Temperature &t);
    friend std::vector<int> operator + (const Temperature &t);
    std::pair<int,int> operator [] (int index);
    friend Temperature operator +(Temperature t, int x);
    friend Temperature operator -(Temperature t, int x);
    friend Temperature operator +(Temperature t1, Temperature t2);
    friend Temperature operator -(Temperature ti, Temperature t2);
    Temperature &operator +=(int x);
    Temperature &operator -=(int x);
    friend bool operator ==(const Temperature &t1,const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);
    
    friend std::ostream &operator <<(std::ostream &ispisi, const Temperature &t);
};
//KONSTRUKTOR
Temperature::Temperature(int minimalna, int maksimalna) { 
    if (minimalna>maksimalna) throw std::range_error("Nekorektne temperature"); 
    min.push_back(minimalna);
    max.push_back(maksimalna);
    min_dozvoljena=*(min.begin());
    max_dozvoljena=*(max.begin());
}
//DODAVANJE NOVIH DNEVNIH TEMPERATURA
void Temperature::RegistrirajTemperature(std::pair<int,int> t) {
    if (t.first>t.second || t.first<Temperature::min_dozvoljena || t.first>Temperature::max_dozvoljena || t.second<Temperature::min_dozvoljena|| t.second>Temperature::max_dozvoljena) throw std::range_error("Nekorektne temperature");
    min.push_back(t.first);
    max.push_back(t.second);
}
//BRISANJE LISTI
void Temperature::BrisiSve() {
    min.erase(min.begin(), min.end());
    max.erase(max.begin(), max.end());
}
/*
void Temperature:BrisiNegativneTemperature() {
    
}*/
//PREBROJI ZA KOLIKO DANA SU UNESENE TEMPERATURE
int Temperature::DajBrojRegistriranihTemperatura() const {
    int parovi=std::count_if(min.begin(), min.end(), std::bind(std::less_equal<int>(),std::placeholders::_1,max_dozvoljena));
    return parovi;
}
//PRONALAZI NAJMANJU TEMPERATURU
int Temperature::DajMinimalnuTemperaturu() const {
    if (DajBrojRegistriranihTemperatura()==0) throw std::logic_error("Nema registriranih temperatura");
    auto temp=std::min_element(min.begin(), min.end());
    return *temp;
}
//PRONALAZI NAJVECU TEMPERATURU
int Temperature::DajMaksimalnuTemperaturu() const {
    if (DajBrojRegistriranihTemperatura()==0) throw std::logic_error("Nema registriranih temperatura");
    auto temp=std::max_element(max.begin(), max.end());
    return *temp;
}
//VRACA BROJ DANA U KOJIMA JE TEMP. BILA VECA OD ZADANE
int Temperature::DajBrojTemperaturaVecihOd(int zadana) const {
    if (DajBrojRegistriranihTemperatura()==0) throw std::logic_error("Nema registriranih temperatura");
    int veca_od=std::count_if(max.begin(), max.end(), std::bind(std::greater<int>(),std::placeholders::_1,zadana));
    return veca_od;
}
//VRACA BROJ DANA U KOJIMA JE TEMP. BILA MANJA OD ZADANE
int Temperature::DajBrojTemperaturaManjihOd(int zadana) const {
    if (DajBrojRegistriranihTemperatura()==0) throw std::logic_error("Nema registriranih temperatura");
    int manja_od=std::count_if(min.begin(), min.end(), std::bind(std::less<int>(),std::placeholders::_1,zadana));
    return manja_od;
}
//OPERATOR ZA PROVJERU DA LI JE UNESENA TEMPERATURA ZA BAR JEDAN DAN
bool operator !(Temperature t) {
    if (t.DajBrojRegistriranihTemperatura()==0) return true;
    return false;
}
//UVECAVA SVE MIN TEMPERATURE ZA 1, prefiksni
Temperature operator ++(Temperature &t) {
    std::transform(t.min.begin(), t.min.end(),t.min.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    if (std::count_if(t.min.begin(), t.min.end(), std::bind(std::greater<int>(), std::placeholders::_1,t.max_dozvoljena))>0) 
        throw std::logic_error("Ilegalna operacija");
    return t;
}

//UVECAVA SVE MIN TEMPERATURE ZA 1, postfiksni
Temperature operator ++(Temperature &t, int) {
    Temperature pom(t);
    std::transform(t.min.begin(), t.min.end(),t.min.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    if (std::count_if(t.min.begin(), t.min.end(), std::bind(std::greater<int>(), std::placeholders::_1,t.max_dozvoljena))>0) 
        throw std::logic_error("Ilegalna operacija");
    return pom;
}

//SMANJUJE SVE MAX TEMPERATURE ZA 1, prefiksni
Temperature operator --(Temperature &t) {
    std::transform(t.max.begin(), t.max.end(),t.max.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    if (std::count_if(t.max.begin(), t.max.end(), std::bind(std::less<int>(), std::placeholders::_1,t.min_dozvoljena))>0) 
        throw std::logic_error("Ilegalna operacija");
    return t;
}

//SMANJUJE SVE MAX TEMPERATURE ZA 1, postfiksni
Temperature operator --(Temperature &t, int) {
    Temperature pom(t);
    std::transform(t.max.begin(), t.max.end(),t.max.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    if (std::count_if(t.max.begin(), t.max.end(), std::bind(std::less<int>(), std::placeholders::_1,t.min_dozvoljena))>0) 
        throw std::logic_error("Ilegalna operacija");
    return pom;
}
//vraca razliku min i max temperature u vektoru
std::vector<int> operator *(const Temperature &t){
    std::vector<int> razlika(t.DajBrojRegistriranihTemperatura());
    std::transform(t.max.begin(), t.max.end(), t.min.begin(), razlika.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    return razlika;
}
//razlika minimalnih temperatura i min dozvoljene temperature
std::vector<int> operator -(const Temperature &t) {
    std::vector<int> razlika(t.DajBrojRegistriranihTemperatura());
    std::transform(t.min.begin(), t.min.end(), razlika.begin(), std::bind(std::minus<int>(), std::placeholders::_1, t.min_dozvoljena));
    return razlika;
}
//razlika maximalnih temperatura i max dozvoljenje temperature
std::vector<int> operator +(const Temperature &t) {
    std::vector<int> razlika(t.DajBrojRegistriranihTemperatura());
    std::transform(t.max.begin(), t.max.end(), razlika.begin(), std::bind(std::minus<int>(), t.max_dozvoljena, std::placeholders::_1));
    return razlika;
}
//OPERATOR VRACA TEMPERATURU ZA TAJ DAN, TJ ZADANI INDEX DANA
std::pair<int,int> Temperature::operator [] (int index) {
    if (index>DajBrojRegistriranihTemperatura()) throw std::range_error("Neispranav index");
    std::pair<int,int> trazeni;
    auto prvi=this->min.begin();
    auto drugi=this->max.begin();
    std::advance(prvi,index-1);
    std::advance(drugi, index-1);
    trazeni=std::make_pair(*prvi,*drugi);
    return trazeni;
}
//SABIRA SVAKU TEMPERATURU ZA X
Temperature operator +(Temperature t, int x) {
    Temperature a=t;
    std::transform(t.min.begin(), t.min.end(), a.min.begin(), std::bind(std::plus<int>(),x,std::placeholders::_1));
    std::transform(t.max.begin(), t.max.end(), a.max.begin(), std::bind(std::plus<int>(),x,std::placeholders::_1));
    int M=t.max_dozvoljena;
    if (std::count_if(a.max.begin(), a.max.end(), std::bind(std::greater<int>(), std::placeholders::_1,M))>0 || std::count_if(a.min.begin(), a.min.end(), std::bind(std::greater<int>(), std::placeholders::_1,M))>0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return a;
}
//ODUZIMA OD SVAKE TEMPERATURE X
Temperature operator -(Temperature t, int x) {
    Temperature a=t;
    std::transform(t.min.begin(), t.min.end(), a.min.begin(), std::bind(std::minus<int>(),x,std::placeholders::_1));
    std::transform(t.max.begin(), t.max.end(), a.max.begin(), std::bind(std::minus<int>(),x,std::placeholders::_1));
    int m=t.min_dozvoljena;
    if (std::count_if(a.max.begin(), a.max.end(), std::bind(std::less<int>(), std::placeholders::_1,m))>0 || std::count_if(a.min.begin(), a.min.end(), std::bind(std::less<int>(), std::placeholders::_1,m))>0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return a;
}
//SABIRA DNEVNU MAX I MIN TEMPERATURU
Temperature operator +(Temperature t1, Temperature t2) {
    Temperature a=t1;
    std::transform(t1.min.begin(), t1.min.end(), t2.min.begin(), a.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2));
    std::transform(t1.max.begin(), t1.max.end(), t2.max.begin(), a.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2));
    int M=t1.max_dozvoljena;
    if (std::count_if(a.max.begin(), a.max.end(), std::bind(std::greater<int>(), std::placeholders::_1,M))>0 || std::count_if(a.min.begin(), a.min.end(), std::bind(std::greater<int>(), std::placeholders::_1,M))>0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return a;
}
//ODUZIMA DNEVNU MAX I MIN TEMPERATURU
Temperature operator -(Temperature t1, Temperature t2) {
    Temperature a(t1);
    std::transform(t1.min.begin(), t1.min.end(), t2.min.begin(), a.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    std::transform(t1.max.begin(), t1.max.end(), t2.max.begin(), a.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    int m=t1.min_dozvoljena;
    if (std::count_if(a.max.begin(), a.max.end(), std::bind(std::less<int>(), std::placeholders::_1,m))>0 || std::count_if(a.min.begin(), a.min.end(), std::bind(std::less<int>(), std::placeholders::_1,m))>0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return a;
}
//RADI ISTO STO I ++, SAMO REZULTAT SMIJESTA U POSTOJECU KLASU
Temperature &Temperature::operator +=(int x) {
    std::transform(this->min.begin(), this->min.end(), this->min.begin(), std::bind(std::plus<int>(), x, std::placeholders::_1));
    if (std::count_if(this->min.begin(), this->min.end(), std::bind(std::greater<int>(), std::placeholders::_1, this->max_dozvoljena))>0) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(this->max.begin(), this->max.end(), this->max.begin(), std::bind(std::plus<int>(), x, std::placeholders::_1));
    if (std::count_if(this->max.begin(), this->max.end(), std::bind(std::greater<int>(), std::placeholders::_1, this->max_dozvoljena))>0) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
//RADI ISTO STO I --. REZULTAT SMJESI U POSTOJECU KLASU
Temperature &Temperature::operator -=(int x) {
    std::transform(this->min.begin(), this->min.end(), this->min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    if (std::count_if(this->min.begin(), this->min.end(), std::bind(std::less<int>(), std::placeholders::_1, this->min_dozvoljena))>0) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(this->max.begin(), this->max.end(), this->max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    if (std::count_if(this->max.begin(), this->max.end(), std::bind(std::less<int>(), std::placeholders::_1, this->min_dozvoljena))>0) 
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
//POREDI DA LI SU DVIJE TEMPERATURE JEDNAKE, LISTE, BROJ PAROVA, I DOZVOLJENE TEMPERATURE
bool operator ==(const Temperature &t1,const Temperature &t2) {
    if (t1.min_dozvoljena==t2.min_dozvoljena && t1.max_dozvoljena==t2.max_dozvoljena && t1.DajBrojRegistriranihTemperatura()==t2.DajBrojRegistriranihTemperatura())
        if (std::equal(t1.min.begin(), t1.min.end(), t1.min.begin(), std::equal_to<int>())==true && std::equal(t1.max.begin(), t1.max.end(), t1.max.begin(), std::equal_to<int>())==true) return true;
    return false;
}
//AKO SU RAZLICITE TEMP, VRACA TRUE
bool operator !=(const Temperature &t1, const Temperature &t2) {
    if (t1.min_dozvoljena!=t2.min_dozvoljena || t1.max_dozvoljena!=t2.max_dozvoljena || t1.DajBrojRegistriranihTemperatura()!=t2.DajBrojRegistriranihTemperatura())
        if (std::equal(t1.min.begin(), t1.min.end(), t1.min.begin(), std::equal_to<int>())==false || std::equal(t1.max.begin(), t1.max.end(), t1.max.begin(), std::equal_to<int>())==false) return true;
    return false;
}
//ISPIS NA EKRAN
std::ostream &operator <<(std::ostream &ispisi, const Temperature &t) {
    std::for_each(t.min.begin(), t.min.end(), [] (int x) { std::cout<<x<<" "; });
    std::cout<<std::endl;
    std::for_each(t.max.begin(), t.max.end(), [] (int x) { std::cout<<x<<" "; });
    std::cout<<std::endl;
    return ispisi;
}

int main ()
{
    try {
    Temperature a(12,46);
    a.RegistrirajTemperature(std::make_pair<int,int>(16,19));
    std::cout<<"Broj reg parova: "<<a.Temperature::DajBrojRegistriranihTemperatura()<<std::endl;
    std::cout<<a;
    a.RegistrirajTemperature(std::make_pair<int,int>(12,15));
    a.RegistrirajTemperature(std::make_pair<int,int>(13,24));
    a.RegistrirajTemperature(std::make_pair<int,int>(13,19));
    ++a;
    --a;
    std::cout<<"Nakon "<<a;
    Temperature b(a),c(a);
    b+=1;
std::cout<<"Nakon b: "<<b;
    std::vector<int> v(-a);
    for (int i=0; i<v.size(); i++)
        std::cout<<v[i]<<" ";
  //  c=b-a;
  //  std::cout<<"Nakon a-b, c= "<<c;
    b=a++;
    std::cout<<"Nakon ++, a= "<<a;
    std::cout<<"Nakon ++, b= "<<b;
    b=a--;
    std::cout<<"Nakon --, a= "<<a;
    std::cout<<"Nakon --, b= "<<b;
    std::pair<int,int> clan(a[2]);
    std::cout<<clan.first<<" "<<clan.second;
    a.Temperature::BrisiSve();
    std::cout<<"nakon bris: "<<a.Temperature::DajBrojRegistriranihTemperatura()<<std::endl;
    std::cout<<"Radi.";
    }
    catch (std::logic_error a) {
        std::cout<<a.what()<<std::endl;
    }
    catch (std::range_error b) {
        std::cout<<b.what()<<std::endl;
    }
	return 0;
}