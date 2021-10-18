/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <list>
#include <cmath>
#include <initializer_list>
#include <iomanip>
#define PI 4*atan(1)

using namespace std;



class FourierovRed{
    double T;
    int N, velicinaa,velicinab;
    double *aovi, *bovi;
public:
    FourierovRed(double t, initializer_list<double> l11, initializer_list<double>l22)
    {
        list<double> l1;
        for(auto it=l11.begin(); it!=l11.end(); it++) l1.push_back(*it);
        list<double> l2; l2.push_back(0);
        for(auto it=l22.begin(); it!=l22.end(); it++) l2.push_back(*it);
        
        
        while(l1.size()<l2.size()) l1.push_back(0);
        while(l2.size()<l1.size()) l2.push_back(0);
        
        
        aovi=new double[l1.size()];
        bovi=new double [l2.size()];
        int i=0;
        for(auto it=l1.begin(), it1=l2.begin(); it!=l1.end(); it++, it1++){ aovi[i]=*it; bovi[i]=*it1; i++;}
        N=l2.size(); velicinaa=l1.size(); velicinab=l2.size();
    }
    FourierovRed(int br, double per, double f1(int), double f2(int)){
        if(br<=0) throw domain_error("Stepen mora biti pozitivan");
        N=br; T=per;
        aovi=new double[N+1]; velicinaa=N+1;
        bovi= new double[N+1]; velicinab=N+1;
        bovi[0]=0;
        for(int i=0; i<=N; i++) aovi[i]=f1(i);
        for(int i=1; i<=N; i++) bovi[i]=f2(i);
    }
    FourierovRed(int br, double p, double q, double f(double), int M){
        if(p>=q) throw range_error("Neispravan interval");
        if(M<=0) throw domain_error("Broj podintervala mora biti pozitivan");
        if(br<0) throw domain_error("Stepen mora biti pozitivan");
        T=q-p; N=br;
        aovi=new double[N+1]; velicinaa=N+1;
        bovi=new double[N+1]; velicinab=N+1;
        for(int i=0; i<=N; i++)
        {
            double nesuma=((f(p)+f(q))/M)*cos((2*i*PI*p)/T);
            double suma=0;
            for(int j=1; j<=M-1; j++)
               {
                   suma+=(f(p+(j*T)/M)*cos(2*j*PI*((p/T)+(j/M))));
               }
            aovi[i]=nesuma+(2/M)*suma;
        
        }
        bovi[0]=0;
        for(int i=1; i<=N; i++)
        {
            double nesuma=((f(p)+f(q))/M)*sin((2*(i)*PI*p)/T);
            double suma=0;
            for(int j=1; j<=M-1; j++)
                {
                    suma+=f(p+(j*T)/2)*sin(2*j*PI*((p/T)+(j/M)));
                }
            bovi[i]=nesuma+(2/M)*suma;
           
        }
    }
    
    ~FourierovRed() { delete [] aovi; delete [] bovi;}
    
    pair<double &,double &> operator [] (int ind){
        if(ind<0 || ind>=N) throw range_error("Neispravan indeks");
        if(ind==0){
            pair<double&,double&> p0(aovi[0],bovi[0]);
            return p0;
        }
        pair<double&,double&> p(aovi[ind],bovi[ind]);
        return p;
    }
    pair<double,double> operator [] (int ind) const{
        if(ind<0 || ind>=N) throw range_error("Neispravan indeks");
        if(ind==0){
            pair<double,double> p0(aovi[0],0);
            return p0;
        }
        pair<double,double> p=make_pair(aovi[ind],bovi[ind]);
        return p;
    }
    FourierovRed(const FourierovRed &f)
    {
        //cout<<"ASDAD"<<endl;
        N=f.N; T=f.T; velicinaa=f.velicinaa; velicinab=f.velicinab;
        aovi = new double [f.N+1];
        bovi = new double [f.N+1];
        for(int i=0; i<=N; i++) { aovi[i]=(f.aovi[i]); }
        for(int i=0; i<=N; i++) { bovi[i]=(f.bovi[i]); }
    }
    FourierovRed &operator = (FourierovRed &f)
    {
        //cout<<"ADADSASDADS"<<endl;
        delete [] aovi; delete [] bovi;
        N=f.N; T=f.T; velicinaa=f.velicinaa; velicinab=f.velicinab;
        aovi = new double [N+1];
        bovi = new double [N+1];
        for(int i=0; i<=N; i++) { aovi[i]=(f.aovi[i]); }
        for(int i=0; i<=N; i++) { bovi[i]=(f.bovi[i]); }
        return *this;

    }
    FourierovRed(FourierovRed &&f)
    {
       // cout<<"ADADSASDADS"<<endl;
        N=f.N; T=f.T; velicinaa=f.velicinaa; velicinab=f.velicinab; aovi=f.aovi; bovi=f.bovi;
        f.N=0; f.T=0; f.velicinaa=0; f.velicinab=0; f.aovi=nullptr; f.bovi=nullptr;
    }
    FourierovRed &operator = (FourierovRed &&f)
    {
        if(this==&f) return *this;
        delete [] aovi; delete [] bovi;
        N=f.N; T=f.T; velicinaa=f.velicinaa; velicinab=f.velicinab; aovi=f.aovi; bovi=f.bovi;
        f.N=0; f.T=0; f.velicinaa=0; f.velicinab=0; f.aovi=nullptr; f.bovi=nullptr;
        return *this;
    }
    void Ispisi(){
        cout<<"Period: "<<T<<endl<<"Stepen: "<<N<<endl;
        cout<<"Koeficijenti a: "<<endl;
        for(int i=0; i<velicinaa; i++) cout<<aovi[i]<<" ";
        cout<<endl<<"Koeficijenti b: "<<endl;
        for(int i=0; i<velicinab; i++) cout<<bovi[i]<<" ";

    }
    double operator ()(double x){
        double onajprvia=(aovi[0])/2;
        double sumaa=0;
        for(int i=1; i<=N; i++)
            sumaa+=((aovi[i]*cos((2*i*PI*x)/T)) + (bovi[i]*sin((2*i*PI*x)/T)));
        return onajprvia + sumaa;

    }
};

int main ()
{
    
   
	return 0;
}
