#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <iterator>
#include <stdexcept>
using namespace std;
const double PI(4*atan(1));
const long double EPSILON(10e-10);
class NepreklapajucaKugla{
    double x,y,z,r;
    NepreklapajucaKugla *pok_na_prethodnu=nullptr;
    static NepreklapajucaKugla *pok_na_pocetak;
    static bool Jednaki(const double &x, const double &y){
        return fabs(x-y)<EPSILON*(fabs(x)+fabs(y));
    }
    static bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return RastojanjeCentara(k1,k2)<=k1.r+k2.r;
}
    public:
explicit NepreklapajucaKugla(double r=0);
NepreklapajucaKugla(double x, double y, double z, double r=0);
explicit NepreklapajucaKugla(const tuple<double, double, double> &centar, double r=0);
double DajX() const;
double DajY() const;
double DajZ() const;
tuple<double, double, double> DajCentar() const;
double DajPoluprecnik() const;
double DajPovrsinu() const;
double DajZapreminu() const;
//static NepreklapajucaKugla *DajPokNaPocetak(){return pok_na_pocetak;}
NepreklapajucaKugla &PostaviX(double x);
NepreklapajucaKugla &PostaviY(double y);
NepreklapajucaKugla &PostaviZ(double z);
NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
NepreklapajucaKugla &PostaviCentar(tuple<double, double, double> &centar);
NepreklapajucaKugla &PostaviPoluprecnik(double r);
void Ispisi() const;
void Transliraj(double delta_x, double delta_y, double delta_z);
NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) = delete;
/*friend bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
bool DaLiSadrzi(const NepreklapajucaKugla &k) const;*/
friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
~NepreklapajucaKugla();
};
NepreklapajucaKugla *NepreklapajucaKugla::pok_na_pocetak(nullptr);
NepreklapajucaKugla::NepreklapajucaKugla(double r):x(0),y(0),z(0){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    if(!pok_na_pocetak) pok_na_pocetak=this;
    else{
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    pok_na_prethodnu=pok_na_pocetak;
    pok_na_pocetak=this; 
    }
}
NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r):x(x),y(y),z(z){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    if(!pok_na_pocetak) pok_na_pocetak=this;
    else{
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    pok_na_prethodnu=pok_na_pocetak;
    pok_na_pocetak=this; 
    }
}
//expllicit se ne smije ponavljati i default parametar stavljamo samo u deklaraciji
NepreklapajucaKugla::NepreklapajucaKugla(const tuple<double, double, double> &centar, double r):x(get<0>(centar)), y(get<1>(centar)), z(get<2>(centar)){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    if(!pok_na_pocetak) pok_na_pocetak=this;
    else{
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    pok_na_prethodnu=pok_na_pocetak;
    pok_na_pocetak=this; 
    }
}
double NepreklapajucaKugla::DajX() const{return x;}
double NepreklapajucaKugla::DajY() const{return y;}
double NepreklapajucaKugla::DajZ() const{return z;}
tuple<double, double, double> NepreklapajucaKugla::DajCentar() const{
    return make_tuple(x,y,z);
}
double NepreklapajucaKugla::DajPoluprecnik() const{return r;}
double NepreklapajucaKugla::DajPovrsinu() const{
    return 4*r*r*PI;
}
double NepreklapajucaKugla::DajZapreminu() const{
    return (4./3)*r*r*r*PI;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x){
    NepreklapajucaKugla::x=x;
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y){
    NepreklapajucaKugla::y=y; 
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z){
    NepreklapajucaKugla::z=z;
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z){
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(tuple<double, double, double> &centar){
    x=get<0>(centar);
    y=get<1>(centar);
    z=get<2>(centar);
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    return *this;
}
void NepreklapajucaKugla::Ispisi() const{
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
    for(auto it=pok_na_pocetak;it!=nullptr;it=it->pok_na_prethodnu){
       if(DaLiSePreklapaju(*this,*it)) throw logic_error("Nedozvoljeno preklapanje"); 
    }
}
/*bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return (NepreklapajucaKugla::Jednaki(k1.x,k2.x) && NepreklapajucaKugla::Jednaki(k1.y,k2.y) && NepreklapajucaKugla::Jednaki(k1.z,k2.z) && NepreklapajucaKugla::Jednaki(k1.r,k2.r));
}
bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return NepreklapajucaKugla::Jednaki(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return (NepreklapajucaKugla::Jednaki(k1.x,k2.x) && NepreklapajucaKugla::Jednaki(k1.y,k2.y) && NepreklapajucaKugla::Jednaki(k1.z,k2.z));
}*/
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
}
/*bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return NepreklapajucaKugla::Jednaki(k1.r+k2.r,RastojanjeCentara(k1,k2));
}
bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return NepreklapajucaKugla::Jednaki(fabs(k1.r-k2.r),RastojanjeCentara(k1,k2));
}
bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return RastojanjeCentara(k1,k2)<k1.r+k2.r;
}
bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return RastojanjeCentara(k1,k2)<k1.r+k2.r && RastojanjeCentara(k1,k2)>fabs(k1.r-k2.r);
}
bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const{
    return RastojanjeCentara(*this,k)<this->r-k.r;
}*/
NepreklapajucaKugla::~NepreklapajucaKugla(){
    int n(0);
    for(auto it=pok_na_pocetak;it!=this;it=it->pok_na_prethodnu){
        n++;
    }
    auto it(pok_na_pocetak);
    if(!n) pok_na_pocetak=pok_na_pocetak->pok_na_prethodnu;
    else{
    for(int i=1;i<n;i++){
        it=it->pok_na_prethodnu;
    }
    it->pok_na_prethodnu=this->pok_na_prethodnu;
    }
}
int main ()
{
    /*NepreklapajucaKugla k1(2, 3, 1, 5);
    NepreklapajucaKugla k2(10, 7, 8, 2);
    try{
      //NepreklapajucaKugla k3(4, 6, 3, 7);  
    }
    catch(logic_error izuzetak){
        cout<<izuzetak.what();
    }
    NepreklapajucaKugla k3(-10, -7, -8, -2); 
    NepreklapajucaKugla k4(-2, -3, -1, -5);*/
    /*NepreklapajucaKugla k(3,4,5,3);
    k.Ispisi();
    NepreklapajucaKugla k1(3,4,5,2);
    cout<<DaLiSuIdenticne(k,k1)<<endl;
    cout<<k.DaLiSadrzi(k1)<<endl;
    cout<<DaLiSeSijeku(k,k1)<<endl;
    cout<<DaLiSePreklapaju(k,k1);
    */
    cout<<"Unesite broj kugli: ";
    int n;
    cin>>n;
    while(n<=0 || !cin){
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>n;
    }
    vector<shared_ptr<NepreklapajucaKugla>> v(n);
    for(int i=0;i<n;i++){
        cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        double x,y,z,r;
        cin>>x>>y>>z;
        while(!cin){
          cout<<"Neispravan centar, unesite ponovo: "<<endl;
          cin.clear();
          cin.ignore(1000,'\n');
          cin>>x>>y>>z;
        }
        cout<<"Unesite poluprecnik: ";
        cin>>r;
        while(r<0 || !cin){
          cout<<"Neispravan poluprecnik, unesite ponovo: "<<endl;
          cin.clear();
          cin.ignore(1000,'\n');
          cin>>r;
        }
            try{
            v.at(i)=make_shared<NepreklapajucaKugla>(x,y,z,r); 
            }catch(logic_error izuzetak){
                cout<<izuzetak.what()<<endl;
                i--;
            }
        }
    /*cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x,y,z;
    cin>>x>>y>>z;*/
    //transform(v.begin(), v.end(), v.begin(),[x,y,z](shared_ptr<NepreklapajucaKugla> &k){k->Transliraj(x,y,z); return k;});
    sort(v.begin(),v.end(),[](const shared_ptr<NepreklapajucaKugla> &k1,const shared_ptr<NepreklapajucaKugla> &k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
    cout<<endl<<"Kugle nakon obavljenog sortiranja: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla> &k){k->Ispisi();});
    /*
    cout<<"NepreklapajucaKugla sa najvecom povrsinom je: ";
    auto najveci=max_element(v.begin(),v.end(),[](const shared_ptr<NepreklapajucaKugla> &k1,const shared_ptr<NepreklapajucaKugla> &k2){return k2->DajPovrsinu()>k1->DajPovrsinu();});
    (*najveci)->Ispisi();
    int br(0);
    bool nesjekuse(true);
    for_each(v.begin(),v.end(),[&v,&br,&nesjekuse](const shared_ptr<NepreklapajucaKugla> &k1){
        br++;
        for_each(v.begin()+br,v.end(),[&k1, &nesjekuse](const shared_ptr<NepreklapajucaKugla> &k2){
            if(DaLiSeSijeku(*k1,*k2)){
                nesjekuse=false;
                cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
            }
            
        });
    });
    if(nesjekuse) cout<<"Ne postoje kugle koje se presjecaju!";*/
	return 0;
}
