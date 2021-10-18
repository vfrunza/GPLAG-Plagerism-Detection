/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>


using namespace std;
const double PI (atan(1)*4);
const double EPS(pow(10,-10));

typedef tuple<double,double,double> Tuple_d;

class NepreklapajucaKugla {
    double x,y,z,r;
    bool Jedn(double x,double y){
        return fabs(x-y)<EPS*(fabs(x)+fabs(y));
    }
    NepreklapajucaKugla* Prethodna=nullptr;
    NepreklapajucaKugla operator= (NepreklapajucaKugla &k);
    NepreklapajucaKugla (const NepreklapajucaKugla &k);
    
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k2);
    void Preklapanje();
    
    public:
    ~NepreklapajucaKugla();
    explicit NepreklapajucaKugla(double r=0);
    NepreklapajucaKugla (double x,double y,double z, double r=0);
    explicit NepreklapajucaKugla(const Tuple_d &centar, double r=0);
    double DajX()const;
    double DajY() const;
    double DajZ() const;
    Tuple_d DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x,double y,double z);
    NepreklapajucaKugla &PostaviCentar(const Tuple_d &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y,double delta_z);
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
static NepreklapajucaKugla* PosljednjaKugla=nullptr;

bool NepreklapajucaKugla::DaLiSePreklapaju(const NepreklapajucaKugla &k2) {
    auto k=this;
    if(RastojanjeCentara(*k,k2)<=(k->DajPoluprecnik()+k2.DajPoluprecnik())) throw logic_error("Nedozvoljeno preklapanje");
    return false;
}
void NepreklapajucaKugla::Preklapanje() {
    for(auto p=PosljednjaKugla;p!=nullptr;p=p->Prethodna) {
        if(this==p) {
            continue;
        }
        if(DaLiSePreklapaju(*p)) throw logic_error("Nedozvoljeno preklapanje");
        }
}

NepreklapajucaKugla::NepreklapajucaKugla(double r) {
    if(r<0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
    x=0; y=0; z=0; r=r;
    Preklapanje();
    this->Prethodna=PosljednjaKugla;
    PosljednjaKugla=this;
    
}
NepreklapajucaKugla::NepreklapajucaKugla(double x,double y,double z, double r) {
    if(r<0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
    this->x=x; 
    this->y=y; 
    this->z=z; 
    this->r=r;
    Preklapanje();
    this->Prethodna=PosljednjaKugla;
    PosljednjaKugla=this;
}
NepreklapajucaKugla::NepreklapajucaKugla(const Tuple_d &centar, double r) {
    if(r<0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
    x=get<0>(centar);    y=get<1>(centar);    z=get<2>(centar);
    this->r=r;
    Preklapanje();
    this->Prethodna=PosljednjaKugla;
    PosljednjaKugla=this;
}
double NepreklapajucaKugla::DajX() const{
    return x;
}
double NepreklapajucaKugla::DajY() const{
    return y;
}
double NepreklapajucaKugla::DajZ() const{
    return z;
}
Tuple_d NepreklapajucaKugla::DajCentar()const {
    return std::make_tuple(x,y,z);
}
double NepreklapajucaKugla::DajPoluprecnik() const {
    return r;
}
double NepreklapajucaKugla::DajPovrsinu() const {
    double r(DajPoluprecnik());
    return 4*r*r*PI;
}
double NepreklapajucaKugla::DajZapreminu() const {
    double r(DajPoluprecnik());
    return (4*r*r*r)/3;
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviX(double x) {
    this->x=x;
    return *this;
    Preklapanje();
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviY(double y) {
    this->y=y;
    return *this;
    Preklapanje();
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviZ(double z) {
    this->z=z;
    return *this;
    Preklapanje();
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(double x,double y,double z) {
    this->x=x;    this->y=y;    this->z=z;
    return *this;
    Preklapanje();
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviCentar(const Tuple_d &centar){
    x=get<0>(centar);    y=get<1>(centar);    z=get<2>(centar);
    return *this;
    Preklapanje();
}
NepreklapajucaKugla& NepreklapajucaKugla::PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
    r=r;
    return *this;
    Preklapanje();
}
void NepreklapajucaKugla::Ispisi() const {
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
}
void NepreklapajucaKugla::Transliraj(double delta_x,double delta_y,double delta_z) {
    x+=delta_x;    y+=delta_y;    z+=delta_z;
    Preklapanje();
}
//PREKLAPANJE



/*void Uvezi() {
    for(auto p=PosljednjaKugla;p!=nullptr;p->Prethodna) {
        Prethodna=PosljednjaKugla;
        PosljednjaKugla=this->Prethodna;
    }
}*/

NepreklapajucaKugla::~NepreklapajucaKugla() {
    if(this==PosljednjaKugla)  {
        PosljednjaKugla=this->Prethodna;
    }
    else {
        NepreklapajucaKugla* p1(PosljednjaKugla);
        for(NepreklapajucaKugla* p=PosljednjaKugla; p!=nullptr;p=p->Prethodna) {
            if(this==p) {
                p1->Prethodna=this->Prethodna;
            }
            p1=p;
        }
    }
}


bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const {
    if(RastojanjeCentara(*this,k)<(r-k.r)) return true;
    return false;
}
double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
    int n;
    double x,y,z,r;
    cout<<"Unesite broj kugli: ";
    cin>>n;
    while(!cin or n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!\n";
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>n;
        
    }
    vector<shared_ptr<NepreklapajucaKugla>> pokazivaci(n);
    for(int i=0;i<n;i++){
        try{
            cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            cin>>x>>y>>z;
            while(!cin){
                cout<<"Neispravan centar, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>x>>y>>z;
                //i--;
              
              //  cout<<"Unesite ponovo";
               // continue;
            }
            cout<<"Unesite poluprecnik: ";
            cin>>r;
            while(!cin || r<0){
                cout<<"Neispravan poluprecnik, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>r;
              //  cout<<"Unesite ponovo: ";
               // continue;
            }
            
        
            pokazivaci.at(i) = (make_shared<NepreklapajucaKugla>(x,y,z,r));
            
        }
        catch(domain_error e){
            cout<<e.what()<<endl;
            i--;
           // cout<<"Unesite ponovo: ";
        }
        catch(logic_error e) {
            cout<<e.what()<<endl;
            i--;
           // cout<<"Unesite ponovo: ";
        }
    }   
    
    
    while(!cin){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
    }
 
    sort(pokazivaci.begin(),pokazivaci.end(),[](shared_ptr<NepreklapajucaKugla> k1,shared_ptr<NepreklapajucaKugla> k2){
        return (k1->DajPovrsinu()<k2->DajPovrsinu());
    });
    cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(pokazivaci.begin(),pokazivaci.end(),[](shared_ptr<NepreklapajucaKugla> k){
        k->Ispisi();
        cout<<endl;
    });
    
	return 0;
}
