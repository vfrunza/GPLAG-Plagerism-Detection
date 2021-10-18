/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>


using namespace std;
const double PI (atan(1)*4);
const double EPS(pow(10,-10));

typedef tuple<double,double,double> Tuple_d;

class Kugla {
    double x,y,z,r;
    bool Jedn(double x,double y){
        return fabs(x-y)<EPS*(fabs(x)+fabs(y));
    }
    public:
    explicit Kugla(double r=0);
    Kugla (double x,double y,double z, double r=0);
    explicit Kugla(const Tuple_d &centar, double r=0);
    double DajX()const;
    double DajY() const;
    double DajZ() const;
    Tuple_d DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x,double y,double z);
    Kugla &PostaviCentar(const Tuple_d &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y,double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};



Kugla::Kugla(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0; y=0; z=0; r=r;
}
Kugla::Kugla(double x,double y,double z, double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    this->x=x; 
    this->y=y; 
    this->z=z; 
    this->r=r;
}
Kugla::Kugla(const Tuple_d &centar, double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=get<0>(centar);    y=get<1>(centar);    z=get<2>(centar);
    this->r=r;
}
double Kugla::DajX() const{
    return x;
}
double Kugla::DajY() const{
    return y;
}
double Kugla::DajZ() const{
    return z;
}
Tuple_d Kugla::DajCentar()const {
    return std::make_tuple(x,y,z);
}
double Kugla::DajPoluprecnik() const {
    return r;
}
double Kugla::DajPovrsinu() const {
    double r(DajPoluprecnik());
    return 4*r*r*PI;
}
double Kugla::DajZapreminu() const {
    double r(DajPoluprecnik());
    return (4*r*r*r*PI)/3;
}
Kugla& Kugla::PostaviX(double x) {
    this->x=x;
    return *this;
}
Kugla& Kugla::PostaviY(double y) {
    this->y=y;
    return *this;
}
Kugla& Kugla::PostaviZ(double z) {
    this->z=z;
    return *this;
}
Kugla& Kugla::PostaviCentar(double x,double y,double z) {
    this->x=x;    this->y=y;    this->z=z;
    return *this;
}
Kugla& Kugla::PostaviCentar(const Tuple_d &centar){
    x=get<0>(centar);    y=get<1>(centar);    z=get<2>(centar);
    return *this;
}
Kugla& Kugla::PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    r=r;
    return *this;
}
void Kugla::Ispisi() const {
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
}
void Kugla::Transliraj(double delta_x,double delta_y,double delta_z) {
    x+=delta_x;    y+=delta_y;    z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if((fabs(k1.x-k2.x)<EPS*fabs(k1.x)+fabs(k2.x)) && (fabs(k1.y-k2.y)<EPS*fabs(k1.y)+fabs(k2.y)) && (fabs(k1.z-k2.z)<EPS*fabs(k1.z)+fabs(k2.z)) && (fabs(k1.r-k2.r)<EPS*fabs(k1.r)+fabs(k2.r)))
        return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.r-k2.r)<EPS*fabs(k1.r)+fabs(k2.r))
        return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if((fabs(k1.x-k2.x)<EPS*fabs(k1.x)+fabs(k2.x)) && (fabs(k1.y-k2.y)<EPS*fabs(k1.y)+fabs(k2.y)) && (fabs(k1.z-k2.z)<EPS*fabs(k1.z)+fabs(k2.z)))
        return true;
    return false;
}

bool Jednakost(double x,double y){
        return fabs(x-y)<EPS*(fabs(x)+fabs(y));
    }


bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    if(Jednakost(k1.r+k2.r,RastojanjeCentara(k1,k2))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    if(Jednakost(RastojanjeCentara(k1,k2),fabs(k1.r-k2.r))) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2)) return true;
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.r-k2.r)<RastojanjeCentara(k1,k2) && RastojanjeCentara(k1,k2)<k1.r+k2.r)
        return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(RastojanjeCentara(*this,k)<(r-k.r)) return true;
    return false;
}
double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
    int n;
    double x,y,z,r;
    cout<<"Unesite broj kugla: ";
    cin>>n;
    while(!cin or n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!\n";
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>n;
        
    }
    vector<shared_ptr<Kugla>> pokazivaci(n);
    for(int i=0;i<n;i++){
        try{
            cout<<"Unesite centar "<<i+1<<". kugle: ";
            cin>>x>>y>>z;
            if(!cin){
                cout<<"Neispravan centar"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                i--;
                continue;
            }
            cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            cin>>r;
            if(!cin){
                cout<<"Ilegalan poluprecnik"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
                i--;
                continue;
            }
            pokazivaci.at(i) = (make_shared<Kugla>(x,y,z,r));
        }
        catch(domain_error e){
            cout<<e.what()<<endl;
            i--;
        }
        
    }
    double delta_x(0),delta_y(0),delta_z(0);
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    cin>>delta_x>>delta_y>>delta_z;
    while(!cin){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
    }
    transform(pokazivaci.begin(),pokazivaci.end(),pokazivaci.begin(),[delta_x,delta_y,delta_z](shared_ptr<Kugla> kugla){
        kugla->Transliraj(delta_x,delta_y,delta_z);
        return kugla;
    });
    sort(pokazivaci.begin(),pokazivaci.end(),[](shared_ptr<Kugla> k1,shared_ptr<Kugla> k2){
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(pokazivaci.begin(),pokazivaci.end(),[](shared_ptr<Kugla> k){
        k->Ispisi();
        cout<<endl;
    });
    cout<<"Kugla sa najvecom povrsinom je: ";
    (*max_element(pokazivaci.begin(),pokazivaci.end(), [](shared_ptr<Kugla> k1,shared_ptr<Kugla>k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }))->Ispisi();
    cout<<endl;
    bool ima=false;
    //
    int i(0);
    for_each(pokazivaci.begin(),pokazivaci.end(),[&ima,&pokazivaci,&i](shared_ptr<Kugla> k1){
        auto it=pokazivaci.begin()+i;
        for_each(it,pokazivaci.end(),[k1,&ima](shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1,*k2)) {
                ima=true;
                cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                cout<<endl;
                k2->Ispisi();
                cout<<endl;
            }
        });
        i+=1;
    });
    if(ima==false) cout<<"Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
