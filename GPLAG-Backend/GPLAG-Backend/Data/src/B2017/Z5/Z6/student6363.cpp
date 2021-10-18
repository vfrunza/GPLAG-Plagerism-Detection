#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <iterator>
using std::cin;
using std::cout;
using std::vector;
using std::endl;

class Berza
{
    vector<int> cd;
    int min, max;
    static bool Ispravno(const int x,const int y=0) {
        return (x>=0 && y>=0);
    }
public:
    Berza() {}
    explicit Berza(int max) {
        if(!Ispravno(max)) throw std::range_error("Ilegalne granicne cijene");
        Berza::max=max;
        min=0;
    }
    Berza(int min, int max) {
        if(!Ispravno(max,min)) throw std::range_error("Ilegalne granicne cijene");
        Berza::max=max;
        Berza::min=min;
    }

    void RegistrirajCijenu(int cijena) {
        if(cijena>max || cijena<min) throw std::range_error("Ilegalna cijena");
        cd.push_back(cijena);
    }

    int DajBrojRegistriranihCijena() const {
        return cd.size();
    }

    void BrisiSve() {
        cd.clear();
    }

    int DajMinimalnuCijenu() const {
        if(cd.empty()) throw std::range_error("Nema registriranih cijena");
        return *std::min_element(cd.begin(),cd.end());
    }

    int DajMaksimalnuCijenu() const {
        if(cd.empty()) throw std::range_error("Nema registriranih cijena");
        return *std::max_element(cd.begin(),cd.end());
    }


    int DajBrojCijenaVecihOd(int x) const {
        if(cd.empty()) throw std::range_error("Nema registriranih cijena");
        return static_cast<int>(std::count_if(cd.begin(),cd.end(),std::bind(std::greater<int>(),std::placeholders::_1,x)));
    }

    void Ispisi() const {
        vector<double> temp(cd.size());
        std::copy(cd.begin(),cd.end(),temp.begin());
        std::sort(temp.begin(),temp.end(),std::greater<int>());
        std::transform(temp.begin(),temp.end(),temp.begin(),std::bind(std::divides<double>(),std::placeholders::_1,100));
        std::streamsize ss = std::cout.precision();
        std::copy(temp.begin(),temp.end(),std::ostream_iterator<double>(cout <<std::fixed << std::setprecision(2)," \n"));
        cout.precision(ss);
    }
    bool operator !() const {
        return cd.empty();
    }
    int operator[](int indeks) const {
        if(indeks>cd.size()) throw std::range_error("Neispravan indeks");
        return cd.at(indeks-1);
    }
    Berza & operator ++() {
        std::transform(this->cd.begin(),this->cd.end(),cd.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
        auto i=std::find_if(this->cd.begin(),this->cd.end(),std::bind(std::greater<int>(),std::placeholders::_1,this->max));
        if(i!=cd.end()) {
            std::transform(this->cd.begin(),this->cd.end(),cd.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        }
        return *this;
    }
    Berza &operator--() {
        std::transform(cd.begin(),cd.end(),cd.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));

        auto i=std::find_if(this->cd.begin(),this->cd.end(),std::bind(std::less<int>(),std::placeholders::_1,this->min));
        if(i!=cd.end()) {
            std::transform(this->cd.begin(),this->cd.end(),cd.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        }
        return *this;
    }
    Berza operator--(int) {
        Berza temp;
        temp.cd=cd;
        --(*this);
        return temp;
    }
    Berza operator ++(int) {
        Berza temp;
        temp.cd=cd;
        ++(*this);
        return temp;
    }
    Berza operator -() {
        Berza temp;
        temp.cd=cd;
        std::transform(temp.cd.begin(),temp.cd.end(),temp.cd.begin(),std::bind(std::minus<int>(),max+min,std::placeholders::_1));
        return temp;
    }

    friend Berza operator - (const Berza &b1,const Berza &b2);
    friend Berza operator + (const Berza &b,int x);
    friend Berza operator - (int x,const Berza &b);
    friend Berza operator - (const Berza &b,int x);
    friend Berza operator + (int x,const Berza &b);
    friend bool operator ==(const Berza &b1,const Berza &b2);
    friend bool operator !=(const Berza &b1,const Berza &b2);
    friend Berza&operator +=(Berza &b,int x);
    friend Berza&operator -=(Berza &b,int x);
    friend Berza&operator -=(Berza &b1,const Berza &b2);
};

Berza operator + (const Berza &b,int x)
{
    Berza temp(b);
    std::transform(temp.cd.begin(),temp.cd.end(),temp.cd.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    auto i=std::find_if(temp.cd.begin(),temp.cd.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp.max));
    if(i!=temp.cd.end()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return temp;
}

Berza operator + (int x,const Berza &b)
{
    return b+x;
}

Berza operator - (const Berza &b,int x)
{
    Berza temp(b);
    std::transform(temp.cd.begin(),temp.cd.end(),temp.cd.begin(),std::bind(std::minus<int>(),std::placeholders::_1,x));
    auto i=std::find_if(temp.cd.begin(),temp.cd.end(),std::bind(std::less<int>(),std::placeholders::_1,temp.min));
    if(i!=temp.cd.end()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return temp;
}

Berza operator - (int x,const Berza &b)
{
    Berza temp(b);
    std::transform(b.cd.begin(),b.cd.end(),temp.cd.begin(),std::bind(std::minus<int>(),x,std::placeholders::_1));
    auto i=std::find_if(temp.cd.begin(),temp.cd.end(),std::bind(std::less<int>(),std::placeholders::_1,temp.min));
    if(i!=temp.cd.end()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return temp;
}

Berza operator - (const Berza &b1,const Berza &b2)
{
    if(b1.cd.size()!=b2.cd.size() || b1.max!=b2.max || b1.min!=b2.min)
        throw std::domain_error("Nesaglasni operandi");
    Berza temp;
    temp.cd=b1.cd;
    temp.max=b1.max;
    temp.min=b1.min;
    std::transform(b1.cd.begin(),b1.cd.end(),b2.cd.begin(),temp.cd.begin(),std::minus<int>());
    auto i=std::find_if(temp.cd.begin(),temp.cd.end(),std::bind(std::less<int>(),std::placeholders::_1,temp.min));
    if(i!=temp.cd.end()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return temp;
}


Berza&operator +=(Berza &b,int x)
{
    b=b+x;
    return b;
}

Berza&operator -=(Berza &b,int x)
{
    b=b-x;
    return b;
}

Berza&operator -=(Berza &b1,const Berza &b2)
{
    b1=b1-b2;
    return b1;
}

bool operator ==(const Berza &b1,const Berza &b2)
{
    return (b1.cd==b2.cd);
}

bool operator !=(const Berza &b1,const Berza &b2)
{
    return !(b1.cd==b2.cd);
}

int main ()
{
    try {
        Berza b1 = Berza(600,4000);
        Berza b2 = Berza(600,4000);
        int n;
        cout << "Unesite broj cijena: ";
        cin >> n;
        try {
            int i=0;
            cout << "Unesite cijene u kf: " << endl;
            while(i!=n) {
                int kf;
                cin >> kf;
                b1.RegistrirajCijenu(kf);
                i++;
            }

        } catch(std::exception &ex) {
            cout << "IZUZETAK: " << ex.what() << endl;
        }
        std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
        if(n-b1.DajBrojRegistriranihCijena()==0) cout<< "Sve ok" << endl;
        else cout << "Neuspjelo zapisivanje " << n-b1.DajBrojRegistriranihCijena() << " cijena" <<endl;

        cout << "Ispis: " << endl;
        b1.Ispisi();
        Berza b3=b1;
        b1.BrisiSve();
        std::cout << "Nakon brisanja b1, broj registrovanih cijena (b1): " << b1.DajBrojRegistriranihCijena();
        cout << endl;
        cout << " Max: " << b3.DajMaksimalnuCijenu() << " Min: " << b3.DajMinimalnuCijenu() <<endl;
        cout << "Broj cijena vecih od 1500: " << b3.DajBrojCijenaVecihOd(1500);
        if(b3==b2) cout << "b2 b3 isti" <<endl;
        if(b3!=b2) cout << "b2 b3 razlicit" << endl;
        cout << "Novi b3: ++" << endl;
        b3+=234;
        b3.Ispisi();
        cout << "Novi b3: --" << endl;
        b3-=12;
        b3.Ispisi();
        b2.RegistrirajCijenu(2321);
        b2.RegistrirajCijenu(659);
        b2.RegistrirajCijenu(1337);
        b2.RegistrirajCijenu(3000);
        cout << "B2: ispis " <<endl;
        b2.Ispisi();
        cout <<endl;
        cout << "B3-b2: " << endl;
        b3=b3-b2;
        b3.Ispisi();
    } catch(std::exception &ex) {
        cout << "Izuzetak: " << ex.what() << endl;
    }
    return 0;
}
