#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>
using namespace std;
const double PI(4*atan(1));
const long double EPSILON(10e-10);
class Kugla{
    double x,y,z,r;
    static bool Jednaki(const double &x, const double &y){
        return fabs(x-y)<EPSILON*(fabs(x)+fabs(y));
    }
    public:
explicit Kugla(double r=0);
Kugla(double x, double y, double z, double r=0);
explicit Kugla(const tuple<double, double, double> &centar, double r=0);
double DajX() const;
double DajY() const;
double DajZ() const;
tuple<double, double, double> DajCentar() const;
double DajPoluprecnik() const;
double DajPovrsinu() const;
double DajZapreminu() const;
Kugla &PostaviX(double x);
Kugla &PostaviY(double y);
Kugla &PostaviZ(double z);
Kugla &PostaviCentar(double x, double y, double z);
Kugla &PostaviCentar(tuple<double, double, double> &centar);
Kugla &PostaviPoluprecnik(double r);
void Ispisi() const;
void Transliraj(double delta_x, double delta_y, double delta_z);
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const;
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
Kugla::Kugla(double r):x(0),y(0),z(0){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
Kugla::Kugla(double x, double y, double z, double r):x(x),y(y),z(z){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
//expllicit se ne smije ponavljati i default parametar stavljamo samo u deklaraciji
Kugla::Kugla(const tuple<double, double, double> &centar, double r):x(get<0>(centar)), y(get<1>(centar)), z(get<2>(centar)){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
double Kugla::DajX() const{return x;}
double Kugla::DajY() const{return y;}
double Kugla::DajZ() const{return z;}
tuple<double, double, double> Kugla::DajCentar() const{
    return make_tuple(x,y,z);
}
double Kugla::DajPoluprecnik() const{return r;}
double Kugla::DajPovrsinu() const{
    return 4*r*r*PI;
}
double Kugla::DajZapreminu() const{
    return (4./3)*r*r*r*PI;
}
Kugla &Kugla::PostaviX(double x){Kugla::x=x; return *this;}
Kugla &Kugla::PostaviY(double y){Kugla::y=y; return *this;}
Kugla &Kugla::PostaviZ(double z){Kugla::z=z; return *this;}
Kugla &Kugla::PostaviCentar(double x, double y, double z){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
}
Kugla &Kugla::PostaviCentar(tuple<double, double, double> &centar){
    x=get<0>(centar);
    y=get<1>(centar);
    z=get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
}
void Kugla::Ispisi() const{
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return (Kugla::Jednaki(k1.x,k2.x) && Kugla::Jednaki(k1.y,k2.y) && Kugla::Jednaki(k1.z,k2.z) && Kugla::Jednaki(k1.r,k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return Kugla::Jednaki(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return (Kugla::Jednaki(k1.x,k2.x) && Kugla::Jednaki(k1.y,k2.y) && Kugla::Jednaki(k1.z,k2.z));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return Kugla::Jednaki(k1.r+k2.r,RastojanjeCentara(k1,k2));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return Kugla::Jednaki(fabs(k1.r-k2.r),RastojanjeCentara(k1,k2));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return RastojanjeCentara(k1,k2)<=k1.r+k2.r;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return RastojanjeCentara(k1,k2)<k1.r+k2.r && RastojanjeCentara(k1,k2)>fabs(k1.r-k2.r);
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
    return RastojanjeCentara(*this,k)<=this->r-k.r;
}
int main ()
{
    /*Kugla k(3,4,5,3);
    k.Ispisi();
    Kugla k1(3,4,5,2);
    cout<<DaLiSuIdenticne(k,k1)<<endl;
    cout<<k.DaLiSadrzi(k1)<<endl;
    cout<<DaLiSeSijeku(k,k1)<<endl;
    cout<<DaLiSePreklapaju(k,k1);
    */
    cout<<"Unesite broj kugla: ";
    int n;
    cin>>n;
    while(!cin || n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cin>>n;
    }
    vector<shared_ptr<Kugla>> v(n);
    for(int i=0;i<n;i++){
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z,r;
        cin>>x>>y>>z;
        if(!cin){
          cout<<"Neispravan centar"<<endl;
          cin.clear();
          cin.ignore(1000,'\n');
          i--;
        }else{
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        cin>>r;
        if(!cin){
          cout<<"Ilegalan poluprecnik"<<endl;
          cin.clear();
          cin.ignore(1000,'\n');
          i--;
        }
        else{
            try{
            v.at(i)=make_shared<Kugla>(x,y,z,r);
            }
            catch(domain_error izuzetak){
                cout<<izuzetak.what()<<endl;
                i--;
            }
        }
        }
    }
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x,y,z;
    cin>>x>>y>>z;
    while(!cin){
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cin>>x>>y>>z;
    }
    transform(v.begin(), v.end(), v.begin(),[x,y,z](shared_ptr<Kugla> &k){k->Transliraj(x,y,z); return k;});
    sort(v.begin(),v.end(),[](const shared_ptr<Kugla> &k1,const shared_ptr<Kugla> &k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Kugla> &k){k->Ispisi();});
    cout<<"Kugla sa najvecom povrsinom je: ";
    auto najveci=max_element(v.begin(),v.end(),[](const shared_ptr<Kugla> &k1,const shared_ptr<Kugla> &k2){return k2->DajPovrsinu()>k1->DajPovrsinu();});
    (*najveci)->Ispisi();
    int br(0);
    bool nesjekuse(true);
    for_each(v.begin(),v.end(),[&v,&br,&nesjekuse](const shared_ptr<Kugla> &k1){
        br++;
        for_each(v.begin()+br,v.end(),[&k1, &nesjekuse](const shared_ptr<Kugla> &k2){
            if(DaLiSeSijeku(*k1,*k2)){
                nesjekuse=false;
                cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
            }
            
        });
    });
    if(nesjekuse) cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
