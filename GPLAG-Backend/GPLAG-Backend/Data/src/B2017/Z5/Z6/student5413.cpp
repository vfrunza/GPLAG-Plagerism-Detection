/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

class Berza
{
    int Min_cijena, Max_cijena;
    vector<int> cijene;
public:
    Berza(int min_cijena, int max_cijena);
    Berza(int max_cijena);
    Berza(const Berza &b);
    Berza &operator =(const Berza &b);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.resize(0); }
    int DajMinimalnuCijenu();
    int DajMaksimalnuCijenu();
    friend bool operator !(const Berza &b);
    int DajBrojCijenaVecihOd(int cijena);
    void Ispisi() const;
    int &operator [](int i);
    Berza operator ++();
    Berza operator ++(int);
    Berza operator --();
    Berza operator --(int);
    friend Berza operator -(Berza &b);
    friend Berza operator +(const Berza &b, int n);
    friend Berza operator -(const Berza &b, int n);
    friend Berza operator +(const Berza &b1, const Berza &b2);
    friend Berza operator -(const Berza &b1, const Berza &b2);
    friend Berza operator +=(Berza &b, int n);
    friend Berza operator -=(Berza &b, int n);
    friend Berza operator +=(Berza &b1, const Berza &b2);
    friend Berza operator -=(Berza &b1, const Berza &b2);
    friend bool operator ==(const Berza &b1, const Berza &b2);
    friend bool operator !=(const Berza &b1, const Berza &b2);
};

Berza &Berza::operator =(const Berza &b)
{
    if(&b != this)
    {
        cijene.resize(0);
        cijene.resize(b.cijene.size());
        Min_cijena = b.Min_cijena;
        Max_cijena = b.Max_cijena;
        copy(b.cijene.begin(), b.cijene.end(), cijene.begin());
    }
    
    return *this;
}

Berza::Berza(const Berza &b) : cijene(0)
{
    cijene.resize(b.cijene.size());
    Min_cijena = b.Min_cijena;
    Max_cijena = b.Max_cijena;
    copy(b.cijene.begin(), b.cijene.end(), cijene.begin());
}

bool operator !=(const Berza &b1, const Berza &b2)
{
    return !(b1 == b2);
}

bool operator ==(const Berza &b1, const Berza &b2)
{
    if(b1.cijene.size() != b2.cijene.size()) return false;
    
    return equal(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin());
}

Berza operator -=(Berza &b1, const Berza &b2)
{
    if(b1.cijene.size() != b2.cijene.size() || b1.Min_cijena != b2.Min_cijena || b1.Max_cijena != b2.Max_cijena)
        throw domain_error("Nesaglasni operandi");
        
    transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), b1.cijene.begin(), minus<int>());
    
    int preko = count_if(b1.cijene.begin(), b1.cijene.end(), bind(less<int>(), placeholders::_1, b1.Min_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return b1;
}

Berza operator +=(Berza &b1, const Berza &b2)
{
    if(b1.cijene.size() != b2.cijene.size() || b1.Min_cijena != b2.Min_cijena || b1.Max_cijena != b2.Max_cijena)
        throw domain_error("Nesaglasni operandi");
        

    transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), b1.cijene.begin(), plus<int>());
    
    int preko = count_if(b1.cijene.begin(), b1.cijene.end(), bind(greater<int>(), placeholders::_1, b1.Max_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return b1;
}

Berza operator -=(Berza &b, int n)
{
    transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), bind(minus<int>(), placeholders::_1, n));
    
    int preko = count_if(b.cijene.begin(), b.cijene.end(), bind(less<int>(), placeholders::_1, b.Min_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return b;   
}

Berza operator +=(Berza &b, int n)
{
    transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), bind(plus<int>(), placeholders::_1, n));
    
    int preko = count_if(b.cijene.begin(), b.cijene.end(), bind(greater<int>(), placeholders::_1, b.Max_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return b;
}

Berza operator -(const Berza &b1, const Berza &b2)
{
    if(b1.cijene.size() != b2.cijene.size() || b1.Min_cijena != b2.Min_cijena || b1.Max_cijena != b2.Max_cijena)
        throw domain_error("Nesaglasni operandi");
        
    Berza temp = b1;
    
    transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), temp.cijene.begin(), minus<int>());
    
    int preko = count_if(temp.cijene.begin(), temp.cijene.end(), bind(less<int>(), placeholders::_1, b1.Min_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return temp;
}

Berza operator +(const Berza &b1, const Berza &b2)
{
    if(b1.cijene.size() != b2.cijene.size() || b1.Min_cijena != b2.Min_cijena || b1.Max_cijena != b2.Max_cijena)
        throw domain_error("Nesaglasni operandi");
        
    Berza temp = b1;
    
    transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), temp.cijene.begin(), plus<int>());
    
    int preko = count_if(temp.cijene.begin(), temp.cijene.end(), bind(greater<int>(), placeholders::_1, b1.Max_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return temp;
}

Berza operator -(const Berza &b, int n)
{
    Berza temp = b;
    
    transform(temp.cijene.begin(), temp.cijene.end(), temp.cijene.begin(), bind(minus<int>(), placeholders::_1, n));
    
    int preko = count_if(temp.cijene.begin(), temp.cijene.end(), bind(less<int>(), placeholders::_1, b.Min_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return temp;
}

Berza operator +(const Berza &b, int n)
{
    Berza temp = b;
    
    transform(temp.cijene.begin(), temp.cijene.end(), temp.cijene.begin(), bind(plus<int>(), placeholders::_1, n));
    
    int preko = count_if(temp.cijene.begin(), temp.cijene.end(), bind(greater<int>(), placeholders::_1, b.Max_cijena));
    
    if(preko != 0)
        throw domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return temp;
}

Berza operator -(Berza &b)
{
    Berza temp = b;
    int zbir; 
    zbir = b.Min_cijena + b.Max_cijena;
    
    transform(temp.cijene.begin(), temp.cijene.end(), temp.cijene.begin(), bind(minus<int>(), zbir, placeholders::_1));
    
    return temp;
}

Berza Berza::operator --(int)
{
    --(*this);
    return *this;
}

Berza Berza::operator --()
{
    transform(cijene.begin(), cijene.end(), cijene.begin(), bind(minus<int>(), placeholders::_1, 100));
    
    int preko = count_if(cijene.begin(), cijene.end(), bind(less<int>(), placeholders::_1, Min_cijena));
    
    if(preko != 0)
        throw range_error("Prekoracen dozvoljeni opseg cijena");
    
    return *this;
}

Berza Berza::operator ++(int)
{
    ++(*this);
    return *this;
}

Berza Berza::operator ++()
{
    transform(cijene.begin(), cijene.end(), cijene.begin(), bind(plus<int>(), placeholders::_1, 100));
    
    int preko = count_if(cijene.begin(), cijene.end(), bind(greater<int>(), placeholders::_1, Max_cijena));
    
    if(preko != 0)
        throw range_error("Prekoracen dozvoljeni opseg cijena");
    
    return *this;
}

int &Berza::operator [](int i)
{
    if(i < 1 || i > cijene.size())
        throw range_error("Neispravan indeks");
    
    return cijene[i - 1];
}

void Berza::Ispisi() const
{
    Berza temp(*this);
    
    sort(temp.cijene.begin(), temp.cijene.end(), greater<int>());
    for_each(temp.cijene.begin(), temp.cijene.end(), [](int cijena)->void { cout << fixed << setprecision(2) << cijena / 100. << endl; });
}

int Berza::DajBrojCijenaVecihOd(int cijena)
{
    if(cijene.size() == 0)
        throw range_error("Nema registriranih cijena");
        
    int brojac = count_if(cijene.begin(), cijene.end(), bind(greater<int>(), placeholders::_1, cijena));
    
    return brojac;
}

bool operator !(const Berza &b)
{
    return (b.cijene.size() == 0);
}

Berza::Berza(int min_cijena, int max_cijena) : cijene(0)
{
    if(min_cijena <= 0 || max_cijena <= 0)
        throw range_error("Ilegalne granice cijene");
    
    Min_cijena = min_cijena;
    Max_cijena = max_cijena;
}

Berza::Berza(int max_cijena) : cijene(0)
{
    if(max_cijena <= 0)
        throw range_error("Ilegalne granice cijene");
    
    Min_cijena = 0;
    Max_cijena = max_cijena;
}

void Berza::RegistrirajCijenu(int cijena)
{
    if(cijena < Min_cijena || cijena > Max_cijena)
        throw range_error("Ilegalna cijena");
    
    cijene.push_back(cijena);
}

int Berza::DajMinimalnuCijenu()
{
    if(cijene.size() == 0)
        throw range_error("Nema registriranih cijena");
    
    return *min_element(cijene.begin(), cijene.end());
}

int Berza::DajMaksimalnuCijenu()
{
    if(cijene.size() == 0)
        throw range_error("Nema registriranih cijena");
        
    return *max_element(cijene.begin(), cijene.end());
}



int main ()
{
    try
    {
        Berza berza = Berza(100, 2000);
        berza.RegistrirajCijenu(150);
        berza.RegistrirajCijenu(1000);
        berza.RegistrirajCijenu(1500);
        cout << "Broj registrovanih cijena: " << berza.DajBrojRegistriranihCijena() << endl;
        berza.Ispisi();
        berza += 100;
        berza.Ispisi();
        berza -= 150;
        berza.Ispisi();
        berza++;
        berza.Ispisi();
        ++berza;
        berza.Ispisi();
        --berza;
        berza.Ispisi();
        berza--;
        berza.Ispisi();
        cout << "Minimalna cijena: " << berza.DajMinimalnuCijenu() << endl;
        cout << "Maksimalna cijena: " << berza.DajMaksimalnuCijenu() << endl;
        cout << "Broj cijena vecih od 800: " << berza.DajBrojCijenaVecihOd(800) << endl;
        berza.BrisiSve();
        cout << "Broj registrovanih cijena: " << berza.DajBrojRegistriranihCijena() << endl;
    }
    catch(range_error re)
    {
        cout << re.what() << endl;
    }
    catch(domain_error de)
    {
        cout << de.what() << endl;
    }
    
	return 0;
}
