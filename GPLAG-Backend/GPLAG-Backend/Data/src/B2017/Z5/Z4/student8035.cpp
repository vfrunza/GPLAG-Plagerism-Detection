/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <initializer_list>
#include <functional>
#include <cmath>
#include <stdexcept>

const double PI=(4.*std::atan(1.));
class FourierovRed
{
    int N;
    double T;
    double **A;
    double **B;
public:
    FourierovRed(double t, std::initializer_list<double> a, std::initializer_list<double> b)
    {
        T=t;
        
        if(a.size()==0 &&  b.size()!=0)
        {
            N=b.size()+1;
            A=new double*[N];
            B=new double*[N];
            *A=new double(0);
            *B=new double(0);
            auto it=b.begin();
            for(int i=1;i<N;i++)
            {
                *(A+i)=new double(0);
                *(B+i)=new double(*it);
                it++;
            }
        }
        else if(b.size()==0 && a.size()!=0)
        {
            N=a.size();
            A=new double*[N];
            B=new double*[N];
            auto it=a.begin();
            for(int i=0;i<N;i++)
            {
                *(A+i)=new double(*it);
                *(B+i)=new double(0);
                it++;
            }
        }
        else if(a.size()==0 && b.size()==0) N=0;
        else
        {
            N=a.size();
            if(b.size()+1>a.size()) N=b.size()+1;
            A=new double*[N];
            B=new double*[N];
            auto it1=a.begin();
            auto it2=b.begin();
            for(int i=0;i<N;i++)
            {
                if(it1!=a.end()) { *(A+i)=new double(*it1); it1++; }
                else *(A+i)=new double(0);
                if(it2!=b.end() && i!=0) { *(B+i)=new double(*it2); it2++; }
                else *(B+i)=new double(0);
            }
        }
        
    }
    FourierovRed(int n, double t, std::function<double(int)> f1, std::function<double(int)> f2)
    {
        if(n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        T=t;
        N=n;
        N++;
        A=new double*[N];
        B=new double*[N];
        for(int i=0;i<N;i++)
        {
            *(A+i)=new double(f1(i));
            *(B+i)=new double(f2(i));
        }
    }
    FourierovRed(int n, double p, double q, std::function<double(double)> f, int M)
    {
        if(n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        if(M<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if(p>q) throw std::range_error("Neispravan interval");
        T=q-p;
        N=n;
        N++;
        A=new double*[N];
        B=new double*[N];
        for(int k=0;k<N;k++)
        {
            double rez1=(f(p)+f(q))/double(M);
            double rez2=rez1;
            
            rez1*=std::cos((2*k*PI*p)/T);
            rez2*=std::sin((2*k*PI*p)/T);
            
            double suma1(0),suma2(0);
            for(int i=1;i<M;i++)
            {
                suma1+=f(p+((i*T)/double(M)))*std::cos(2*k*PI*((p/T)+(double(i)/M)));
                suma2+=f(p+((i*T)/double(M)))*std::sin(2*k*PI*((p/T)+(double(i)/M)));
            }
            suma1*=(2./M);
            suma2*=(2./M);
            rez1+=suma1;
            rez2+=suma2;
            *(A+k)=new double(rez1);
            *(B+k)=new double(rez2);
        }
    }
    ~FourierovRed()
    {
        for(int i=0;i<N;i++) delete *(A+i),delete *(B+i);
        delete[] A;
        delete[] B;
    }
    double operator ()(double x) const
    {
        double rez(0);
        for(int k=1;k<N;k++)
        {
            rez+=*A[k]*std::cos((2*k*PI*x)/(T))+*B[k]*std::sin((2*k*PI*x)/(T));
        }
        rez+=(*A[0])/2.;
        return rez;
    }
    std::pair<double, double> operator [](int k) const
    {
        if(k<0 || k>=N) throw std::range_error("Neispravan indeks");
        if(k==0) 
        {
            *B[0]=0;
            return {*A[k],*B[k]};
        }
        return {*A[k],*B[k]};
    }
    std::pair<double &, double &> operator [](int k)
    {
        if(k<0 || k>=N) throw std::range_error("Neispravan indeks");
        if(k==0) 
        {
            *B[0]=0;
            return {*A[k],*B[k]};
        }
        return {*A[k],*B[k]};
    }
    
    FourierovRed(const FourierovRed &red)
    {
        A=new double*[red.N];
        B=new double*[red.N];
        T=red.T;
        N=red.N;
        for(int i=0;i<N;i++)
        {
            *(A+i)=new double((**(red.A+i)));
            *(B+i)=new double((**(red.B+i)));
        }
    }
    FourierovRed(FourierovRed &&red)
    {
        T=red.T;
        N=red.N;
        A=red.A;
        B=red.B;
        red.A=nullptr;
        red.B=nullptr;
        red.N=0;
    }
    FourierovRed &operator =(const FourierovRed &red)
    {
        if(this!=&red)
        {
            this->~FourierovRed();
            A=new double*[red.N];
            B=new double*[red.N];
            T=red.T;
            N=red.N;
            for(int i=0;i<N;i++)
            {
                *(A+i)=new double((**(red.A+i)));
                *(B+i)=new double((**(red.B+i)));
            }
        }
        return *this;
    }
    FourierovRed &operator =(FourierovRed &&red)
    {
        if(this!=&red)
        {
            this->~FourierovRed();
            T=red.T;
            N=red.N;
            A=red.A;
            B=red.B;
            red.A=nullptr;
            red.B=nullptr;
            red.N=0;
        }
        return *this;
    }
};



int main ()
{
    // AT12 (S) Pomjerajuci konstruktor kopije, pomjerajuci operator dodjele, destruktivna samododjela.
    // Ovaj autotest (takodjer) koristi preklapanje operatora new[] i delete[]. Ukoliko se detektuje bilo
    // kakva alokacija unutar pomjerajuceg konstruktora kopije i/ili pomjerajuceg operatora dodjele, AT pada.
    // Ono sto je najvaznije to je da ce AT pasti ukoliko imate samo obicni konstruktor kopije i operator dodjele,
    // a niste implementirali uopste njihove pomjerajuce verzije. Tada ce vam umjesto pomjerajuceg biti pozvan
    // obicni, a on svakako vrsi (i treba da vrsi) alokacije, pa ce AT da padne...
    // Pretpostavljam da je moguc i slucaj gdje su pomjerajuci konstruktor i operator dodjele ispravni, a da
    // ovaj autotest padne (NPR u slucaju alokacije nekih pomocnih varijabli). U tom slucaju mozete se obratiti
    // na mail bcocalic1@etf.unsa.ba (uz obrazlozenje zasto ste radili alokacije).
    // Takodjer, imat cete segmentation fault ukoliko niste predvidjeli destruktivnu samododjelu. 
    double L=2;
    auto k1=[L](int k) { return (k == 0) ? 2*L : 0; };
    auto k2=[L](int k) { return (k%2==0) ? 2*L/(k*AT_PI) : -2*L/(k*AT_PI); };
    FourierovRed f1(50, 2*L, k1, k2);
    FourierovRed f2(7,{7, 7}, {7});
    Alocirano=0;
    MAX_RAM=0;
    try {
        f2=std::move(f1);
        std::cout<<"Pomjerajuci operator dodjele: OK"<<std::endl;
    }
    catch(std::bad_alloc e) {
        std::cout<<"Pomjerajuci operator dodjele: PROBLEM - izvrsava neke alokacije"<<std::endl;
        std::cout<<"Ukoliko ipak smatrate da vam je kod tacan javite na bcocalic1@etf.unsa.ba (uz obrazlozenje)"<<std::endl;
    }
    Alocirano=0;
    MAX_RAM=std::numeric_limits<int>::max();
    f2=std::move(f2); // Samododjela
    Alocirano=0;
    MAX_RAM=0;
    try {
        FourierovRed f3(std::move(f2));
        std::cout<<"Pomjerajuci konstruktor: OK"<<std::endl;
        std::cout<<"Prvih 5 koeficijenata:"<<std::endl;
        AT_Ispisi("a", "b");
        std::cout << std::fixed << std::setprecision(3); // Dovoljno je na 3 decimale
        for (int i=0; i<5; i++) {
            AT_Ispisi(f3[i]);
        }
    }
    catch(std::bad_alloc e) {
        std::cout<<"Pomjerajuci konstruktor: PROBLEM - izvrsava neke alokacije"<<std::endl;
        std::cout<<"Ukoliko ipak smatrate da vam je kod tacan javite na bcocalic1@etf.unsa.ba (uz obrazlozenje)"<<std::endl;
    }
	return 0;
}
