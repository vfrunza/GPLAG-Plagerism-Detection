/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <functional>

const double Pi = std::atan(1)*4;
const double eps = 1e-10;

class FourierovRed
{
    double *redA, *redB, T;
    int N;
    
    bool JesuLiJednaki(double x, double y) const
    {
        if(std::fabs(x-y) <= eps * (std::fabs(x) + std::fabs(y))) return true;
        else return false;
    }
    
    public:
    
    FourierovRed(double T, std::initializer_list<double> redA, std::initializer_list<double> redB);
    FourierovRed(int N, double T, std::function<double(int)> F1, std::function<double(int)> F2);
    FourierovRed(int N, double p, double q, std::function<double(double)> F1, int M);
    double operator () (double h) const;
    FourierovRed &operator = (const FourierovRed &F);
    FourierovRed &operator = (FourierovRed &&F)
    {
        FourierovRed::N = F.N;
        FourierovRed::T = F.T;
        
        if(this != &F)
        {
            delete[] FourierovRed::redA;
            delete[] FourierovRed::redB;
            FourierovRed::redA = F.redA;
            FourierovRed::redB = F.redB;
            FourierovRed::redB[0] = 0;
            F.redA = nullptr;
            F.redB = nullptr;
        }
        return *this;
    }
    
    FourierovRed(const FourierovRed &F);
    FourierovRed(FourierovRed &&F)
    {
        FourierovRed::N = F.N;
        FourierovRed::T = F.T;
        FourierovRed::redA = F.redA;
        FourierovRed::redB = F.redB;
        FourierovRed::redB[0] = 0;
        F.redA = nullptr;
        F.redB = nullptr;
    }
    
    std::pair<double, double> operator [] (int h) const;
    ~FourierovRed()
    {
        delete[] redA;
        delete[] redB;
    }
    std::pair<double&, double&> operator [] (int h);
    
};

FourierovRed::FourierovRed(double T, std::initializer_list<double> redA, std::initializer_list<double> redB)
{
    FourierovRed::T = T;
    FourierovRed::N = std::max(redA.size(), redB.size());
    FourierovRed::redA = nullptr;
    FourierovRed::redB = nullptr;
    
    if(N <= 0) throw std::domain_error ("Stepen mora biti pozitivan");
    if(T <= 0) throw std::range_error("Neispravan interval");
    
    try
    {
        FourierovRed::redA = new double[N+1] {0};
        FourierovRed::redB = new double[N+1] {0};
        int i = 0;
        
        for(auto x : redA) FourierovRed::redA[i] = x, i++;
        i = 1;
        for(auto x : redB) FourierovRed::redB[i] = x, i++;
    }
    catch(...)
    {
        delete [] FourierovRed::redA;
        delete [] FourierovRed::redB;
        throw;
    }
}

FourierovRed::FourierovRed(int N, double T, std::function<double (int)> F1, std::function<double (int)> F2)
{
    FourierovRed::redA = nullptr;
    FourierovRed::redB = nullptr;
    
    if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    if(T <= 0) throw std::range_error("Neispravan interval");
    
    FourierovRed::N = N;
    FourierovRed::T = T;
    
    try
    {
        FourierovRed::redA = new double[N+1] {0};
        FourierovRed::redB = new double[N+1] {0};
        int i(0);
        
        while(i<=N)
        {
            FourierovRed::redA[i] = F1(i);
            i++;
        }
        i = 0;
        while(i<=N) 
        {
            FourierovRed::redB[i] = F2(i);
            i++;
        }
        FourierovRed::redB[0] = 0;
    }
    catch(...)
    {
        delete [] FourierovRed::redA;
        delete [] FourierovRed::redB;
        throw;
    }
}

FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> F, int M)
{
    FourierovRed::redA = nullptr;
    FourierovRed::redB = nullptr;
    
    if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    if(M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if(p > q) throw std::range_error("Neispravan interval");
    
    FourierovRed::N = N;
    FourierovRed::T = p-q;
    try
    {
        FourierovRed::redA = new double[N+1] {0};
        FourierovRed::redB = new double[N+1] {0};
        int i=0;
        
        while(i <= N)
        {
            double sumaA(0), sumaB(0);
            int j=1;
            while (j < M) 
            {
                sumaA += F(p + (j*T)/M)* std::cos((2*i*Pi)*((p/T) + (double(j)/M)));
                sumaB += F(p + (j*T)/M)* std::sin((2*i*Pi)*((p/T) + (double(j)/M)));
                j++;
            }
            sumaA *= double(2)/M;
            sumaB *= double(2)/M;
            
            redA[i] = ((F(p) + F(q))/M)*std::cos((2*i*Pi*p)/T) + sumaA;
            redB[i] = ((F(p) + F(q))/M)*std::sin((2*i*Pi*p)/T) + sumaB;
            i++;
        }
    }
    catch(...)
    {
        delete [] FourierovRed::redA;
        delete [] FourierovRed::redB;
        throw;
    }
}

FourierovRed::FourierovRed(const FourierovRed &F)
{
    FourierovRed::N = F.N;
    FourierovRed::T = F.T;
    
    FourierovRed::redA = nullptr;
    FourierovRed::redB = nullptr;
    try
    {
        FourierovRed::redA = new double[F.N+1];
        FourierovRed::redB = new double[F.N+1];
        int i = 0;
        
        while(i <= N) 
        {
            FourierovRed::redA[i] = F.redA[i];
            FourierovRed::redB[i] = F.redB[i];
            i++;
        }
        FourierovRed::redB[0] = 0;
    }
    catch(...)
    {
        delete [] FourierovRed::redA;
        delete [] FourierovRed::redB;
        throw;
    }
}

FourierovRed &FourierovRed::operator =(const FourierovRed &F)
{
    FourierovRed::N = F.N;
    FourierovRed::T = F.T;
    
    if(this != &F)
    {
        try
        {
            delete [] FourierovRed::redA;
            delete [] FourierovRed::redB;
            
            FourierovRed::redA = nullptr;
            FourierovRed::redB = nullptr;
            
            FourierovRed::redA = new double[F.N+1];
            FourierovRed::redB = new double[F.N+1];
            
            int i=0;
            
            while(i <= N)
            {
                FourierovRed::redA[i] = F.redA[i];
                FourierovRed::redB[i] = F.redB[i];
                i++;
            }
            FourierovRed::redB[0] = 0;
        }
        catch(...)
        {
            delete [] FourierovRed::redA;
            delete [] FourierovRed::redB;
            throw;
        }
    }
    return *this;
}

double FourierovRed::operator () (double h) const
{
    double suma(redA[0]/2);
    int i = 1;
    while(i <= N)
    {
        suma += redA[i] * std::cos((2*i*Pi*h)/T) + redB[i] * std::sin((2*i*Pi*h)/T);
        i++;
    }
    return suma;
}

std::pair<double&, double&> FourierovRed::operator [] (int h)
{
    if(h < 0 || h > N) throw std::range_error("Neispravan indeks");
    else if(FourierovRed::JesuLiJednaki(double(h), double(N)) && FourierovRed::JesuLiJednaki(redB[N], 0) && FourierovRed::JesuLiJednaki(redA[N], 0)) throw std::range_error("Neispravan indeks");
    return std::pair<double&, double&> (redA[h], redB[h]);
}

std::pair<double, double> FourierovRed::operator [](int h) const
{
    if(h < 0 || h > N) throw std::range_error("Neispravan indeks");
    else if(FourierovRed::JesuLiJednaki(double(h), double(N)) && FourierovRed::JesuLiJednaki(redB[N], 0) && FourierovRed::JesuLiJednaki(redA[N], 0)) throw std::range_error("Neispravan indeks");
    
    return std::pair<double, double> (redA[h], redB[h]);
}


int main ()
{
    FourierovRed a(1,{1,2,3,4,5,6}, {3,3,6,7});
	return 0;
}
