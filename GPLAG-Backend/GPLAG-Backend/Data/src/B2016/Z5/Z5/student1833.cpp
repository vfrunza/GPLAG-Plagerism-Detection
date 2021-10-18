/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
class Temperature
{
    std::list<int> minimalne,maksimalne;
    int min_dozovoljena,max_dozvoljena;
    bool Provjera(int minimalna,int maksimalna) {
        return maksimalna>=minimalna;
    }
public:
    Temperature(int min,int max);
    void RegistrirajTemperature(std::pair<int,int> t);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura()const;
    int DajMinimalnuTemperaturu()const;
    int DajMaksimalnuTeperaturu()const;
    int DajBrojTeperaturaManjihOd(int n)const;
    int DajBrojTeperaturaVecihOd(int n)const ;
    bool operator!()const;
    Temperature operator ++();
    Temperature operator --();
    Temperature operator ++(int);
    Temperature operator --(int);
    std::vector<int> operator *();
    std::vector<int> operator -();
    std::vector<int> operator +();
    const std::pair<int,int> operator [] (int indeks) const {
        if(indeks<1 || indeks>minimalne.size()) throw std::range_error ("Neispravan indeks");
        auto it(minimalne.begin()),it2(maksimalne.begin());
        std::advance(it,indeks-1);
        std::advance(it2,indeks-1);
        std::pair<int,int> P({*it,*it2});
        return P;
    }
    Temperature operator +=(int Y);
    Temperature operator -=(int Y);
    friend Temperature operator +(Temperature X, int Y);
    friend Temperature operator -(Temperature X, int Y);
    friend Temperature operator +(int Y,Temperature X);
    friend Temperature operator -(int Y,Temperature X);
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &T);
    friend bool operator ==(Temperature t1, Temperature t20);
    friend bool operator !=(Temperature t1, Temperature t20);
};
Temperature::Temperature(int min,int max){

    if(!Provjera(min,max)) throw std::range_error ("Nekorektne temperature");
    min_dozovoljena=min;
    max_dozvoljena=max;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> t)
{
    if(!Provjera(t.first,t.second) || !Provjera(min_dozovoljena,t.first) || !Provjera(t.second,max_dozvoljena))throw std::range_error ("Nekorektne temperature");
    minimalne.push_back(t.first);
    maksimalne.push_back(t.second);
}
void Temperature::BrisiSve()
{
    minimalne.resize(0);
    maksimalne.resize(0);
}
void Temperature::BrisiNegativneTemperature()
{
    static int i=0;
    auto it1=std::find_if(minimalne.begin(),minimalne.end(), std::bind(std::less<int>(),std::placeholders::_1,0));
    auto it2=maksimalne.begin();
    int n=std::distance(minimalne.begin(),it1);
    std::advance(it2,n);
    if(it1!=minimalne.end()) {
        it1=minimalne.erase(it1);
        it2=maksimalne.erase(it2);
        i++;
    }
    it1=std::find_if(minimalne.begin(),minimalne.end(), std::bind(std::less<int>(),std::placeholders::_1,0));
    if(it1!=minimalne.end())
        BrisiNegativneTemperature();

    if(i==0) throw std::logic_error ("Takve temperature nisu registrirane");
}
int Temperature::DajBrojRegistriranihTemperatura()const
{
    return minimalne.size();
}
int Temperature::DajMinimalnuTemperaturu()const
{
    if(minimalne.size()==0) throw std::logic_error ("Nema registriranih temperatura");
    return *std::min_element(minimalne.begin(),minimalne.end());
}
int Temperature::DajMaksimalnuTeperaturu()const
{
    if(maksimalne.size()==0) throw std::logic_error ("Nema registriranih temperatura");
    return *std::max_element(maksimalne.begin(),maksimalne.end());
}
int Temperature::DajBrojTeperaturaManjihOd(int n)const
{
    int v(0);
    v=std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,n));
    v+=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,n));

    if(v==0) throw std::logic_error ("Nema registriranih temperatura");
    return v;
}
int Temperature::DajBrojTeperaturaVecihOd(int n)const
{
    int v(0);
    v=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
    v+=std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));

    if(v==0) throw std::logic_error ("Nema registriranih temperatura");
    return v;
}
bool Temperature::operator!() const
{
    if(maksimalne.size()==0) return true;
    else return false;
}
Temperature Temperature::operator ++()
{
    if(!equal(minimalne.begin(),minimalne.end(),maksimalne.begin(),std::bind(std::not_equal_to<int>(),std::placeholders::_1,std::placeholders::_2)))
        throw std::logic_error ("Ilegalna operacija");
    std::transform(minimalne.begin(),minimalne.end(),minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature Temperature::operator --()
{
    if(!equal(minimalne.begin(),minimalne.end(),maksimalne.begin(),std::bind(std::not_equal_to<int>(),std::placeholders::_1,std::placeholders::_2)))
        throw std::logic_error ("Ilegalna operacija");
    std::transform(maksimalne.begin(),maksimalne.end(),maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature Temperature::operator ++(int)
{
    Temperature pomocne(*this);
    ++*this;
    return pomocne;
}
Temperature Temperature::operator --(int)
{
    Temperature pomocne(*this);
    --*this;
    return pomocne;
}
std::vector<int> Temperature::operator *()
{
    std::vector<int> v(minimalne.size());
    std::transform(maksimalne.begin(),maksimalne.end(),minimalne.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    return v;

}
std::vector<int> Temperature::operator -()
{
    std::vector<int> v(minimalne.size());
    std::transform(minimalne.begin(),minimalne.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,min_dozovoljena));
    return v;

}
std::vector<int> Temperature::operator +()
{
    std::vector<int> v(minimalne.size());
    std::transform(maksimalne.begin(),maksimalne.end(),v.begin(),std::bind(std::minus<int>(),max_dozvoljena,std::placeholders::_1));
    return v;
}

Temperature Temperature::operator +=(int Y)
{
    std::transform(minimalne.begin(),minimalne.end(),minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));
    std::transform(maksimalne.begin(),maksimalne.end(),maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));

    int n=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,max_dozvoljena));
    n+=std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,max_dozvoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
Temperature Temperature::operator -=(int Y)
{
    std::transform(minimalne.begin(),minimalne.end(),minimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,Y));
    std::transform(maksimalne.begin(),maksimalne.end(),maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,Y));

    int n=std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,min_dozovoljena));
    n+=std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,min_dozovoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
bool operator ==(Temperature t1, Temperature t2)
{
    bool T1,T2;
    T1=std::equal(t1.minimalne.begin(),t1.minimalne.begin(),t2.minimalne.begin());
    T2=std::equal(t1.maksimalne.begin(),t1.maksimalne.begin(),t2.maksimalne.begin());
    if(T1 && T2) return true;
    else return false;
}
bool operator !=(Temperature t1, Temperature t2)
{
    bool T1,T2;
    T1=std::equal(t1.minimalne.begin(),t1.minimalne.begin(),t2.minimalne.begin());
    T2=std::equal(t1.maksimalne.begin(),t1.maksimalne.begin(),t2.maksimalne.begin());
    if(!T1 || !T2) return true;
    else return false;
}
Temperature operator +(Temperature X, int Y)
{
    Temperature M(X.min_dozovoljena,X.max_dozvoljena);
    M.maksimalne.resize(X.maksimalne.size());
    M.minimalne.resize(X.maksimalne.size());
    std::transform(X.minimalne.begin(),X.minimalne.end(),M.minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));
    std::transform(X.maksimalne.begin(),X.maksimalne.end(),M.maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));

    int n=std::count_if(M.minimalne.begin(),M.minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,X.max_dozvoljena));
    n+=std::count_if(M.maksimalne.begin(),M.maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,X.max_dozvoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return M;
}
Temperature operator -(Temperature X, int Y)
{
    Temperature M(X.min_dozovoljena,X.max_dozvoljena);
    M.maksimalne.resize(X.maksimalne.size());
    M.minimalne.resize(X.maksimalne.size());

    std::transform(X.minimalne.begin(),X.minimalne.end(),M.minimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,Y));
    std::transform(X.maksimalne.begin(),X.maksimalne.end(),M.maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,Y));

    int n=std::count_if(M.minimalne.begin(),M.minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,X.min_dozovoljena));
    n+=std::count_if(M.maksimalne.begin(),M.maksimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,X.min_dozovoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return M;
}
Temperature operator +(int Y,Temperature X)
{
    Temperature M(X.min_dozovoljena,X.max_dozvoljena);
    M.maksimalne.resize(X.maksimalne.size());
    M.minimalne.resize(X.maksimalne.size());

    std::transform(X.minimalne.begin(),X.minimalne.end(),M.minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));
    std::transform(X.maksimalne.begin(),X.maksimalne.end(),M.maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,Y));

    int n=std::count_if(M.minimalne.begin(),M.minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,X.max_dozvoljena));
    n+=std::count_if(M.maksimalne.begin(),M.maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,X.max_dozvoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return M;
}
Temperature operator -(int Y,Temperature X)
{
    Temperature M(X.min_dozovoljena,X.max_dozvoljena);
    M.maksimalne.resize(X.maksimalne.size());
    M.minimalne.resize(X.maksimalne.size());
    std::transform(X.minimalne.begin(),X.minimalne.end(),M.maksimalne.begin(),std::bind(std::plus<int>(),Y,std::placeholders::_1));
    std::transform(X.maksimalne.begin(),X.maksimalne.end(),M.minimalne.begin(),std::bind(std::plus<int>(),Y,std::placeholders::_1));
    int n=std::count_if(M.minimalne.begin(),M.minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,X.min_dozovoljena));
    n+=std::count_if(M.maksimalne.begin(),M.maksimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,X.min_dozovoljena));
    if(n!=0) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return M;
}
std::ostream &operator <<(std::ostream &tok, const Temperature &T)
{

    std::copy(T.minimalne.begin(), T.minimalne.end(),std::ostream_iterator<int>(tok, " "));
    std::cout  << std::endl;
    std::copy(T.maksimalne.begin(), T.maksimalne.end(),std::ostream_iterator<int>(tok, " "));

    return tok;
}

int main_ ()
{
    try {
        int min_dozovoljena,max_dozvoljena;
        std::cout << "Unesi min dozovoljenu i max dozvoljenu temperaturu: " << std::endl;
        std::cin>>min_dozovoljena>>max_dozvoljena;
        Temperature T(min_dozovoljena,max_dozvoljena);
        std::cout << "Unesi 5 dnevnih temperatura u paru: " << std::endl;
        for(int i=0; i<5; i++) {
            int min,max;
            std::cin>>min>>max;
            std::pair<int,int> t(min,max);
            T.RegistrirajTemperature(t);
        }
        T++;
        T--;
        ++T;
        --T;
        std::cout << "Broj registriranih temperatura: "<<T.DajBrojRegistriranihTemperatura() << std::endl;
        std::cout << "Minimalna temperatura: "<<T.DajMinimalnuTemperaturu() << std::endl;
        std::cout << "Maksimalna temperatura: "<<T.DajMaksimalnuTeperaturu() << std::endl;
        std::cout << "Broj temperatura manjih od 5: "<<T.DajBrojTeperaturaManjihOd(5) << std::endl;
        std::cout << "Broj temperatura vecih od 5: "<<T.DajBrojTeperaturaVecihOd(5) << std::endl;
        std::cout << "Povecamo temperature za 2 i dobijemo: ";
        T+2;
        std::cout<<std::endl<<T << std::endl;
        std::cout << "Smanjimo temperature za 2 i dobijemo: ";
        T-2;
        std::cout<<std::endl<<T << std::endl;
        std::cout << "Kad obrisemo sve negativne temperature imamo: ";
        T.BrisiNegativneTemperature();
        std::cout<<std::endl<<T;

        std::cout << "Unesi min dozovoljenu i max dozvoljenu temperaturu T2: " << std::endl;
        std::cin>>min_dozovoljena>>max_dozvoljena;
        Temperature T2(min_dozovoljena,max_dozvoljena);
        std::cout << "Unesi 5 dnevnih temperatura u paru: " << std::endl;
        for(int i=0; i<5; i++) {
            int min,max;
            std::cin>>min>>max;
            std::pair<int,int> t(min,max);
            T2.RegistrirajTemperature(t);
        }
        T2++;
        T2--;
        ++T2;
        --T2;
        std::cout << "Broj registriranih temperatura: "<<T2.DajBrojRegistriranihTemperatura() << std::endl;
        std::cout << "Minimalna temperatura: "<<T2.DajMinimalnuTemperaturu() << std::endl;
        std::cout << "Maksimalna temperatura: "<<T2.DajMaksimalnuTeperaturu() << std::endl;
        std::cout << "Broj temperatura manjih od 5: "<<T2.DajBrojTeperaturaManjihOd(5) << std::endl;
        std::cout << "Broj temperatura vecih od 5: "<<T2.DajBrojTeperaturaVecihOd(5) << std::endl;
        std::cout << "Povecamo temperature za 2 i dobijemo: ";
        T2+2;
        std::cout<<std::endl<<T2 << std::endl;
        std::cout << "Smanjimo temperature za 2 i dobijemo: ";
        T2-2;
        std::cout<<std::endl<<T2 << std::endl;
        std::cout << "Kad obrisemo sve negativne temperature imamo: ";
        T2.BrisiNegativneTemperature();
        std::cout<<std::endl<<T2;
        std::cout << "Da li su temperature jednake? ";
        bool A(T==T2);
        std::cout<<std::boolalpha<< A << std::endl;
        T2.BrisiSve();
        T.BrisiSve();
    } catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    } catch(std::range_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;

}
int main(){
    {
     Temperature a(-4,9);
    
    try
    {
        a.DajBrojTeperaturaVecihOd(5);
        std::cout << "Ovo se ne smije ispisati.";
    }
    catch (const std::logic_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        a.DajBrojTeperaturaManjihOd(5);
        std::cout << "Ovo se ne smije ispisati.";
    }
    catch (const std::logic_error &e)
    {
        std::cout << e.what();
    }
}  
return 0;
}