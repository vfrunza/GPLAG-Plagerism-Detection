/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream> 
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <cctype>

using namespace std;
const double pi=4*atan(1);
const double epsilon=10e-10;

class Kugla
{
    mutable double x, y, z, r;
public:
    explicit Kugla(double r=0){
        x=0,y=0,z=0,r=0;
    }
    Kugla(double x, double y, double z, double r=0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        if(abs(r)<epsilon*(abs(r))){
            Kugla::y=0;
            Kugla::x=0;
            Kugla::z=0;
            Kugla::r=0;
        }else{
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        }
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        if(abs(r)<epsilon*abs(r)){
            x=0;
            y=0;
            z=0;
        }else{
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<2>(centar);
        }
    }
    double DajX() const{
        return x;
    }
    double DajY() const{
        return y;
    }
    double DajZ() const{
        return z;
    }
    std::tuple<double, double, double> DajCentar() const{
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const{
        return r;
    }
    double DajPovrsinu() const{
        return 4*r*r*pi;
    }
    double DajZapreminu() const{
        return (4./3)*r*r*r*pi;
    }
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        x=get<0>(centar);
        y=get<1>(centar);
        z=get<0>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.x-k2.x)<epsilon*(abs(k1.x)+abs(k2.x))&&abs(k1.y-k2.y)<epsilon*(abs(k1.y)+abs(k2.y))&&abs(k1.z-k2.z)<epsilon*(abs(k1.z)+abs(k2.z))&&abs(k1.r-k2.r)<epsilon*(abs(k1.r)+abs(k2.r))) return true;
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.r-k2.r)<epsilon*(abs(k1.r)+abs(k2.r))) return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.x-k2.x)<epsilon*(abs(k1.x)+abs(k2.x))&&abs(k1.y-k2.y)<epsilon*(abs(k1.y)+abs(k2.y))&&abs(k1.z-k2.z)<epsilon*(abs(k1.z)+abs(k2.z))) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        if(abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-(k1.r+k2.r))<epsilon*(abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)))+abs(k1.r+k2.r))) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        if(abs((sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+(k1.r))-k2.r)<epsilon*(abs((sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+(k1.r)))+abs(k2.r))) return true;
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        double x=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        if((x+k1.r<=k2.r||x+k2.r<=k1.r)||DaLiSeSijeku(k1,k2)==true) return true;
        return false;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double x=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        double y=k1.r+k2.r;
        if( x < y && !( x + k1.r <= k2.r|| x+k2.r<=k1.r)) return true;
        return false;
    }
    bool DaLiSadrzi(const Kugla &k) const{
        if(RastojanjeCentara(k, *this)+k.r<=r||RastojanjeCentara(k,*this)+r<=k.r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    }
};

int main ()
{
    try{
    int n;
    double deltax,deltay,deltaz;
    cout<<"Unesite broj kugla: ";
    cin>>n;
    while(n<=0||isdigit(n)!=0){
        cin.clear();
        cin.ignore(100000,'\n');
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin>>n;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    vector<shared_ptr<Kugla>>v;
    for(int i(0);i<n;i++){
        double r,x,y,z;
        label:
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        while(1){
            if(cin>>x>>y>>z){
                break;
            }
            else{
                cout<<"Neispravan centar"<<endl;
                cout<<"Unesite centar "<<i+1<<". kugle: ";
            }
            cin.clear();
            cin.ignore(10000,'\n');
        }
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        while(1){
            if(cin>>r/*cin.peek()=='\n'*/&&r>=0){
                break;
            }
            else{
            cout<<"Ilegalan poluprecnik"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto label;
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        Kugla k(x,y,z,r);
        v.push_back(make_shared<Kugla>(k));
        }
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(1){
    if(cin>>deltax>>deltay>>deltaz/*&&cin.peek()=='\n'*/&&deltax>=0&&deltay>=0&&deltaz>=0){
        break;
    }
    else{
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    }
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    transform(v.begin(),v.end(),v.begin(),[deltax,deltay,deltaz](shared_ptr<Kugla>k){
        k->Transliraj(deltax,deltay,deltaz);
        return k;
    });
    sort(v.begin(),v.end(),[](shared_ptr<Kugla>k1,shared_ptr<Kugla>k2){
        if(k1->DajZapreminu()<k2->DajZapreminu())return true; 
        return false;
    });
    for_each(v.begin(),v.end(),[](shared_ptr<Kugla>k){k->Ispisi();});
    cout<<"Kugla sa najvecom povrsinom je: ";
    shared_ptr<Kugla> k=*max_element(v.begin(),v.end(),[](shared_ptr<Kugla>k1,shared_ptr<Kugla>k2){
        if(k1->DajPovrsinu()<k2->DajPovrsinu())return true;
        return false;
    });
    k->Ispisi();
    bool pomocna=false;
    for_each(v.begin(),v.end()-1,[&](shared_ptr<Kugla>k1){
        for_each(v.begin()+1,v.end(),[&](shared_ptr<Kugla>k2){
            if(DaLiSeSijeku(*k1,*k2)){
                cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
                pomocna=true;
            }
        });
        
    });
    if(!pomocna) {cout<<"Ne postoje kugle koje se presjecaju!";
        
    }
    }catch(...){
        cout<<"greska";
    }
    
    return 0;
}
