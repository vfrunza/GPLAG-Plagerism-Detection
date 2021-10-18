/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

#define EPSILON 0.0000000001

using std::make_shared;
using std::shared_ptr;
using std::vector;

using std::cout;
using std::cin;
using std::endl;
using std::get;


double vratiVeciManji(double x, double y, bool veci=true){
    if(veci){
        if(x>y) return x;
        return y;
    }
    else{
        if(x>y) return y;
        return x;
    }
}

bool provjeriRealne(double x, double y){
    if(fabs(x-y)<(EPSILON*(fabs(x)+fabs(y)))) return true;
    else return false;
}

class Kugla{
    double pozicija[3];
    double r;
    
    void provjeriPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    
 public:
    explicit Kugla(double r = 0) { 
        provjeriPoluprecnik(r);
        pozicija[0]=0;
        pozicija[1]=0;
        pozicija[2]=0;
        this->r=r;
    }
    Kugla(double x, double y, double z, double r = 0){
        provjeriPoluprecnik(r);
        this->r=r;
        pozicija[0]=x;
        pozicija[1]=y;
        pozicija[2]=z;
    }
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        provjeriPoluprecnik(r);
        this->r=r;
        pozicija[0]=get<0>(centar);
        pozicija[1]=get<1>(centar);
        pozicija[2]=get<2>(centar);
    }
    
    double DajX() const { return pozicija[0]; }
    double DajY() const { return pozicija[1]; }
    double DajZ() const { return pozicija[2]; }
    
    std::tuple<double, double, double> DajCentar() const {
        auto rez = std::make_tuple(pozicija[0],pozicija[1],pozicija[2]);
        return rez;
    }
    
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*4*atan(1); }
    double DajZapreminu() const { return (4/3)*r*r*r*4*atan(1); }
    
    
    Kugla &PostaviX(double x) {
        pozicija[0]=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        pozicija[1]=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        pozicija[2]=z;
        return *this;
    }
    
    Kugla &PostaviCentar(double x, double y, double z){
        pozicija[0]=x;
        pozicija[1]=y;
        pozicija[2]=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        pozicija[0]=get<0>(centar);
        pozicija[1]=get<1>(centar);
        pozicija[2]=get<2>(centar);
        return *this;
    }
    
    
    Kugla &PostaviPoluprecnik(double r){
        this->r=r;
        return *this;
    }
    
    void Ispisi() const{
        std::cout<<"{"<<"("<<pozicija[0]<<","<<pozicija[1]<<","<<pozicija[2]<<"),"<<r<<"}";
    }
    
    
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        this->pozicija[0]+=delta_x;
        this->pozicija[1]+=delta_y;
        this->pozicija[2]+=delta_z;
    }
    
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const{
        double veci(vratiVeciManji(k.r,r));
        if(!provjeriRealne(veci,r)) return false;
        double manji(k.r);
        return (provjeriRealne(veci-RastojanjeCentara(*this,k),manji) and !DaLiSuIdenticne(*this,k)) or (veci-RastojanjeCentara(*this,k)>manji);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};



bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSuIdenticne(k1,k2) and k1.r<EPSILON and k2.r<EPSILON) return true; //receno je na fourmu da tacka predstavlja i unutrasnjost i rub tako da ovo vrijedi
    return (k1.r+k2.r) > RastojanjeCentara(k1,k2);
    
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return DaLiSePreklapaju(k1,k2) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1);
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(provjeriRealne(k1.pozicija[0],k2.pozicija[0]) && provjeriRealne(k1.pozicija[1],k2.pozicija[1]) && provjeriRealne(k1.pozicija[2],k2.pozicija[2]) && provjeriRealne(k1.r,k2.r))
        return true;
    else return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt( pow( (k1.pozicija[0]-k2.pozicija[0]),2) + pow( (k1.pozicija[1]-k2.pozicija[1]),2) + pow( (k1.pozicija[2] - k2.pozicija[2]),2));
}


bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return provjeriRealne(k1.r,k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return RastojanjeCentara(k1,k2)<EPSILON;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    
    double veci(vratiVeciManji(k1.r,k2.r));
    double manji(vratiVeciManji(k1.r,k2.r,false));
    if(DaLiSuIdenticne(k1,k2) && k1.r<EPSILON and k2.r<EPSILON) return true; //dvije tacke koje su na istoj poziciji imaju u sustini jednu zajednicku tacku
    return provjeriRealne(veci-RastojanjeCentara(k1,k2),manji) && !DaLiSuIdenticne(k1,k2); //ne smiju biti identicne jer onda im rubovi nece imati TACNO JEDNU zajed tacku
    
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if(DaLiSuIdenticne(k1,k2) and k1.r<EPSILON and k2.r<EPSILON) return true;
    return provjeriRealne(RastojanjeCentara(k1,k2),k1.r+k2.r); //ako je rastojanje centara jednako zbiru poluprecnika onda se dodiruju tacno u jednoj tacki
}






int main ()
{

    cout<<"Unesite broj kugla: ";
    int n;
    cin>>n;
    while(!cin or n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!\n";
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>n;
    }
    
    vector<shared_ptr<Kugla>> kugle;
    
    for(int i=0; i<n; i++){
        try{
            cout<<"Unesite centar "<<i+1<<". kugle: ";
            double x,y,z;
            cin>>x>>y>>z;
            if(!cin){
                cout<<"Neispravan centar\n";
                cin.clear();
                cin.ignore(10000,'\n');
                i--;
                continue;
            }
            cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            double r;
            cin>>r;
            if(!cin or r<0){
                cout<<"Ilegalan poluprecnik\n";
                cin.clear();
                cin.ignore(10000,'\n');
                i--;
                continue;
            }
            kugle.push_back(make_shared<Kugla>(x,y,z,r));
        }
        catch(std::domain_error e){
            cout<<e.what()<<endl;
            i--;
        }
    }
    
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x,y,z;
    cin>>x>>y>>z;
    while(!cin){
        cout<<"Neispravni parametri translacije, unesite ponovo!";
        cout<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        cin>>x>>y>>z;
    }
    std::for_each(kugle.begin(),kugle.end(), [x,y,z](shared_ptr<Kugla> s) {s->Transliraj(x,y,z);});
    std::sort(kugle.begin(),kugle.end(), [](shared_ptr<Kugla> s1, shared_ptr<Kugla> s2) {return s1->DajZapreminu() < s2->DajZapreminu();});
    
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(kugle.begin(),kugle.end(), [](shared_ptr<Kugla> s) {s->Ispisi(); cout<<endl;});
    
    
    cout<<"Kugla sa najvecom povrsinom je: ";
    auto it = std::max_element(kugle.begin(),kugle.end(), [](shared_ptr<Kugla> s1, shared_ptr<Kugla> s2) {return s1->DajPovrsinu() < s2->DajPovrsinu();});
    (*it)->Ispisi();
    cout<<endl;
    
    bool sijeku_se(false);
    int brojac(0);
    std::for_each(kugle.begin(), kugle.end(), [&sijeku_se,&kugle, &brojac](shared_ptr<Kugla> s) { 
        brojac++;
        std::for_each(kugle.begin()+brojac,kugle.end(), [&s,&sijeku_se](shared_ptr<Kugla> s2) {
            if(s!=s2 and DaLiSeSijeku(*s,*s2)){
               cout<<"Presjecaju se kugle: ";
               s->Ispisi();
               cout<<endl;
               s2->Ispisi();
               sijeku_se=true;
               cout<<endl;
           }
           
        });
    }   );
    
    

    if(!sijeku_se)
        cout<<"Ne postoje kugle koje se presjecaju!";
    
    
    
	return 0;
}
