/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <algorithm>
#include <memory>
#include <tuple>
#include <cmath>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <stdexcept>

using namespace std;

double E=pow(10,-11);
double PI=atan(1)*4;

bool jednakostest(double x, double y);

double kvad(double x) { return x*x;} 

class NepreklapajucaKugla{
    double ox,oy,oz,pp;
public:
    explicit NepreklapajucaKugla(double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        ox=0; 
        oy=0; 
        oz=0; 
        pp=r;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        if(!cin){
            cin.clear(); cin.ignore(1,'\n'); 
            throw domain_error("Ilegalan poluprecnik");
        }
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        ox=x;
        oy=y; 
        oz=z; 
        pp=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        ox=get<0>(centar); 
        oy=get<1>(centar); 
        oz=get<2>(centar); pp=r;
    }
    double DajX() const { return ox;}
    double DajY() const {return oy;}
    double DajZ() const { return oz;}
    NepreklapajucaKugla &PostaviX(double x) { ox=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y) { oy=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z) { oz=z; return *this;}
    std::tuple<double, double, double> DajCentar() const{
        auto rez=make_tuple(ox,oy,oz);
        return rez;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        ox=x;
        oy=y; 
        oz=z; return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        PostaviCentar(get<0>(centar),get<1>(centar),get<2>(centar));
        return *this;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        return sqrt(kvad(k1.ox-k2.ox)+kvad(k1.oy-k2.oy)+kvad(k1.oz-k2.oz));
    }
    double DajPoluprecnik() const { return pp;}
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        pp=r; 
        return *this;
    }
    double DajPovrsinu() const{ 
        return 4*PI*pp*pp;
    }
    double DajZapreminu() const { 
        return (4*PI*pp*pp*pp)/3;
    }
    void Ispisi() const {
        cout<<"{(";
        cout<<ox<<","<<oy<<","<<oz<<"),"<<pp<<"}";
        cout<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        ox+=delta_x; 
        oy+=delta_y; 
        oz+=delta_z;
    }
   
    friend bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
       double duzi,kraci;
          if(k1.DajPoluprecnik()<=k2.DajPoluprecnik()) { duzi=k2.DajPoluprecnik(); kraci=k1.DajPoluprecnik();return (duzi+kraci>RastojanjeCentara(k1,k2) && duzi-kraci<RastojanjeCentara(k1,k2));}
          else { duzi=k1.DajPoluprecnik(); kraci=k2.DajPoluprecnik(); return (duzi+kraci>RastojanjeCentara(k1,k2) && duzi-kraci<RastojanjeCentara(k1,k2));}
        

    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
        return RastojanjeCentara(*this,k)<this->DajPoluprecnik() && this->DajPovrsinu()>k.DajPovrsinu();
    }
};

void unosn(int &n){
    for(;;){
        cin>>n;
        if(!cin) {
            cin.clear(); 
            cin.ignore(1,'\n'); 
            cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
            
        }
        else if(n<=0) { cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;}
        else break;
    }
}

bool jednakostest(double x, double y){
        return fabs(x-y)<E*(fabs(x)+fabs(y));
    }



void check(double &x, double &y, double &z, int i){
    while(!cin){
            cin.clear(); cin.ignore(3,'\n'); cout<<"Neispravan centar"<<endl;
            cout<<"Unesite centar "<<i+1<<". kugle: ";
            cin>>x>>y>>z;
        }
}

int main ()
{
    cout<<"Unesite broj kugla: ";
    int n;
    unosn(n);
    vector<shared_ptr<NepreklapajucaKugla>> v;
    v.resize(n);
    for(int i=0; i<n; i++){
        double x,y,z;
        try{
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        cin>>x>>y>>z;
        check(x,y,z,i);
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: "; 
        double prec;
        cin>>prec;
        v[i]=make_shared<NepreklapajucaKugla>(x,y,z,prec);
        } catch(domain_error e) { cout<<e.what()<<endl; i--;}
    }
    double dx,dy,dz; 
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        bool a=true;
        cin>>dx>>dy>>dz;
        if(!cin){
            cin.clear(); cin.ignore(1,'\n'); 
            cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl; 
            a=false;
        }
        if(a)break;
    }
    
    transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](shared_ptr<NepreklapajucaKugla> kug){
        kug->Transliraj(dx,dy,dz); 
        return kug;
    });
    sort(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla> kug1, shared_ptr<NepreklapajucaKugla> kug2){
        return kug1->DajZapreminu()<((4*PI*kvad(kug2->DajPoluprecnik())*kug2->DajPoluprecnik())/3);
    });
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla>kug)
        {
            kug->Ispisi();
            
        });
    cout<<"NepreklapajucaKugla sa najvecom povrsinom je: ";
    auto isp=(max_element(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla> kug1, shared_ptr<NepreklapajucaKugla> kug2){
        return kug1->DajPovrsinu()<kug2->DajPovrsinu();
    }));
    isp->get()->Ispisi();
    
    bool ima=false;
    auto it1=v.begin(), it2=v.end();
    for_each(v.begin(),v.end(),[&it1,it2,&ima](shared_ptr<NepreklapajucaKugla> kug){
          it1++;
          for_each(it1,it2,[kug,&ima](shared_ptr<NepreklapajucaKugla> kug1){
               if (DaLiSeSijeku(*kug,*kug1)){
                   ima=true; 
                   cout<<"Presjecaju se kugle: ";
                   kug->Ispisi();
                   kug1->Ispisi();}});}
    );
	if(ima) return 0;
	else cout<<"Ne postoje kugle koje se presjecaju!";  
	return 0;
}
