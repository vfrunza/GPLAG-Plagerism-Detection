/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <iomanip>

class Berza
{
    int min,max;
    std::vector<int> cijene;
    void BaciIzuzetak();
public:
    Berza (int min, int max):min(min),max(max) {
        if (min<0 || max<0) throw std::range_error ("Ilegalne granicne cijene");
    }
    explicit Berza (int max): min(0),max(max) {
        if (max<0) throw std::range_error ("Ilegalne granicne cijene");
    }
    void RegistrirajCijenu (int cijena);
    int DajBrojRegistriranihCijena () const {return cijene.size();}
    void BrisiSve () {cijene.resize(0);}
    int DajMinimalnuCijenu () const;
    int DajMaksimalnuCijenu () const;
    bool operator ! () {return cijene.size()==0;}
    int DajBrojCijenaVecihOd (int cijena) const;
    void Ispisi() const;
    int operator [] (int indeks) const;
    Berza &operator++();
    Berza operator++(int);
    Berza &operator--();
    Berza operator--(int);
    Berza operator-();
    friend Berza operator+ (const Berza &b, int n);
    friend Berza operator- (const Berza &b, int n);
    friend Berza operator+ (int n, const Berza &b);
    friend Berza operator- (int n, const Berza &b);
    friend Berza operator- (const Berza &b1, const Berza &b2);
    Berza &operator+=(int n);
    Berza &operator-=(int n);
    Berza &operator-=(const Berza &b);
    friend bool operator == (const Berza &b1, const Berza &b2);
    friend bool operator != (const Berza &b1, const Berza &b2);
};

bool operator== (const Berza &b1, const Berza &b2)
{
    if (std::not_equal_to<int>()(b1.cijene.size(),b2.cijene.size())) return false;
    return std::equal (b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),std::equal_to<int>());
}

bool operator!= (const Berza &b1, const Berza &b2)
{
    if (std::not_equal_to<int>() (b1.cijene.size(),b2.cijene.size())) return true;
    return !std::equal(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),std::equal_to<int>());
}

Berza &Berza::operator-=(const Berza &b)
{
    if (std::not_equal_to<int>()(b.min,min) || std::not_equal_to<int>()(b.max,max) || std::not_equal_to<int>()(b.cijene.size(),cijene.size())) 
        throw std::domain_error ("Nesaglasni operandi");
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),b.cijene.begin(),cijene.begin(),std::minus<int>());
    try
    {
        BaciIzuzetak();
    }
    catch (std::domain_error iz)
    {
        *this=temp; throw;
    }
    return *this;
}

Berza &Berza::operator-= (int n)
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    try
    {
        BaciIzuzetak();
    }
    catch (std::domain_error iz)
    {
        *this=temp; throw;
    }
    return *this;
}

Berza &Berza::operator+= (int n)
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    try 
    {
        BaciIzuzetak();
    }
    catch (std::domain_error iz)
    {
        *this=temp; throw;
    }
    return *this;
}

Berza operator- (const Berza &b1, const Berza &b2)
{
    if (std::not_equal_to<int>()(b1.min,b2.min) || std::not_equal_to<int>() (b1.max,b2.max) || std::not_equal_to<int>()(b1.cijene.size(),b2.cijene.size()))
        throw std::domain_error ("Nesaglasni operandi");
    Berza temp(b1.min,b1.max);
    temp.cijene.resize(b1.cijene.size());
    std::transform(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),temp.cijene.begin(),std::minus<int>());
    temp.BaciIzuzetak();
    return temp;
}

void Berza::BaciIzuzetak ()
{
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max))!=0)
        throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::less<int>(),std::placeholders::_1,min))!=0)
        throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
}

Berza operator- (int n, const Berza &b)
{
    auto temp(b);
    std::transform(temp.cijene.begin(),temp.cijene.end(),temp.cijene.begin(),std::bind(std::minus<int>(),n,std::placeholders::_1));
    temp.BaciIzuzetak();
    return temp;
}

inline Berza operator+(int n, const Berza &b)
{
    return b+n;
}

Berza operator+ (const Berza &b, int n)
{
    auto temp(b);
    std::transform(temp.cijene.begin(),temp.cijene.end(),temp.cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    temp.BaciIzuzetak();
    return temp;
}

Berza operator- (const Berza &b, int n)
{
    auto temp(b);
    std::transform(temp.cijene.begin(),temp.cijene.end(),temp.cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    temp.BaciIzuzetak();
    return temp;
}

Berza Berza::operator- ()
{
    auto temp(*this);
    std::transform(temp.cijene.begin(),temp.cijene.end(),temp.cijene.begin(),std::bind(std::minus<int>(),temp.min+temp.max,std::placeholders::_1));
    return temp;
}

Berza Berza::operator--(int)
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::less<int>(),std::placeholders::_1,min))!=0)
    {
        *this=temp;
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
    }
    return temp;
}

Berza &Berza::operator--()
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::less<int>(),std::placeholders::_1,min))!=0)
    {
        *this=temp;
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
    }
    return *this;
}

Berza Berza::operator++ (int)
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max))!=0)
    {
        *this=temp;
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
    }
    return temp;
}

Berza &Berza::operator++ ()
{
    auto temp(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if (std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max))!=0) {
        *this=temp;
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");}
    return *this;
}

int Berza::operator[] (int indeks) const
{
    if (indeks<1 || indeks>cijene.size()) throw std::range_error ("Neispravan indeks");
    return cijene[indeks-1];
}

int Berza::DajBrojCijenaVecihOd (int cijena) const
{
    if (cijene.size()==0) throw std::range_error ("Nema registriranih cijena");
    return std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,cijena));
}

void Berza::RegistrirajCijenu (int cijena)
{
    if (cijena<min || cijena>max) throw std::range_error ("Ilegalna cijena");
    cijene.push_back(cijena);
}

int Berza::DajMinimalnuCijenu () const
{
    if (cijene.size()==0) throw std::range_error ("Nema registriranih cijena");
    return *std::min_element(cijene.begin(),cijene.end());
}

int Berza::DajMaksimalnuCijenu () const
{
    if (cijene.size()==0) throw std::range_error ("Nema registriranih cijena");
    return *std::max_element(cijene.begin(),cijene.end());
}

void Berza::Ispisi () const
{
    std::vector<bool> vec(cijene.size(),false);
    for (int i=0;i<cijene.size();i++)
    {
        int maxi(0);
        while (vec[maxi]==true) maxi++;
        for (int j=0;j<cijene.size();j++)
        {
            if (std::logical_and<int>()(std::greater<int>()(cijene[j],cijene[maxi]),std::not_equal_to<int>()(vec[j],true)))
            maxi=j;
        }
        vec[maxi]=true;
        std::cout<<std::fixed<<std::setprecision(2)<<double(cijene[maxi])/100<<std::endl;
    }
    std::cout.unsetf(std::ios::floatfield);
}

int main ()
{
    int min,max;
    std::cout<<"Unesite minimalnu i maksimalnu cijenu: ";
    while (std::cin>>min>>max,min<0 || max<0)
        std::cout<<"Unesite ponovo!Parametri moraju biti nenegativni!\n";
    Berza b(min,max);
    for(;;)
    {
        int n;
        std::cout<<"Odaberite opciju:\n1 - Dodaj cijenu\n2 - Ispis\n3 - Povecaj za 1KM\n4 - Smanji za 1 KM\n5 - Povecaj/smanji\n";
        std::cout<<"6 - Maksimalna cijena\n7 - Minimalna cijena\n8 - Broj vecih od\n9 - Kraj\n";
        std::cin>>n;
        if (n==1)
        {
            int c;
            std::cout<<"Unesite cijenu: "; std::cin>>c;
            try{b.RegistrirajCijenu(c);}
            catch(...)
            {std::cout<<"Unesite ponovo!\n";}
        }
        else if (n==2) b.Ispisi();
        else if (n==3) 
        {
            try{b++;}
            catch(...)
            {std::cout<<"Prekoracen opseg!\n";}
        }
        else if (n==4)
        {
            try{b--;}
            catch(...)
            {std::cout<<"Prekoracen opseg!\n";}
        }
        else if (n==5)
        {
            std::cout<<"Unesite pomak: \n"; int p;
            std::cin>>p;
            if (p<0) {
                try{b-=p;}
                catch(...)
                {std::cout<<"Prekoracen opseg!\n";}
            }
            else {
                try {b+=p;}
                catch(...)
                {std::cout<<"Prekoracen opseg!\n";}
            }
        }
        else if (n==6) std::cout<<"Maksimalna cijena je "<<b.DajMaksimalnuCijenu()<<"\n";
        else if (n==7) std::cout<<"Minimalna cijene je "<<b.DajMinimalnuCijenu()<<"\n";
        else if (n==8)
        {
            int bp;
            std::cout<<"Unesite broj: "; std::cin>>bp;
            std::cout<<"Broj cijena vecih od "<<bp<<" je "<<b.DajBrojCijenaVecihOd(bp);
        }
        else if (n==9) break;
    }
	return 0;
}
