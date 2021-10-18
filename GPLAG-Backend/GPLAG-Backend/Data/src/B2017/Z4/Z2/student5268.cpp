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

class NepreklapajucaKugla{
    double pozicija[3];
    double r;
    NepreklapajucaKugla* prosla;
    static NepreklapajucaKugla* zadnja;
    
    void provjeriPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    

    bool PreklapajuSe(const NepreklapajucaKugla &k){
        return ( (r+k.r) > RastojanjeCentara(*this,k) || provjeriRealne(r+k.r,RastojanjeCentara(*this,k))); //NA FORUMU JE NAPISANO DA JE OVO DODEFINICIJA ZADATKA, KUGLE NE SMIJU IMATI NITI JEDNU JEDINU ZAJED TACKU
    }
    
    
    //Mora ici od pocetka ( a ne od prethodnih samo ) jer cemo ovu funkciju koristiti i za provjeru kod funkcija mutatora pa ce mozda promjena nekog od atributa 
    //prozuzrokovati preklapanje sa nekom kuglom koja je fakticki KASNIJE kreirana.. 
    void provjeriNepreklapanje(){
        for(auto pok(zadnja); pok!=nullptr; pok=pok->prosla){
            if(pok!=this and (*pok).PreklapajuSe(*this))
                throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    
    
    
 public:
 
    ~NepreklapajucaKugla(){
        NepreklapajucaKugla* sljedeca=nullptr;
        for(auto p(zadnja); p!=nullptr; p=p->prosla){
            if(p==this){
                if(p==zadnja){
                    zadnja=this->prosla;
                    
                }
                else{
                    sljedeca->prosla=this->prosla;
                }
            }
            sljedeca=p;
        }
    }
    
    
    explicit NepreklapajucaKugla(double r = 0) { 
        provjeriPoluprecnik(r);
        this->r=r;
    }
    
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        provjeriPoluprecnik(r);
        this->r=r;
        pozicija[0]=x;
        pozicija[1]=y;
        pozicija[2]=z;
        provjeriNepreklapanje();
        (*this).prosla=zadnja;
        zadnja=this;
        
    }
    
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
        provjeriPoluprecnik(r);
        this->r=r;
        pozicija[0]=get<0>(centar);
        pozicija[1]=get<1>(centar);
        pozicija[2]=get<2>(centar);
        provjeriNepreklapanje();
        (*this).prosla=zadnja;
        zadnja=this;
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
    
    
    NepreklapajucaKugla &PostaviX(double x) {
        pozicija[0]=x;
        provjeriNepreklapanje();
        return *this;
        
    }
    NepreklapajucaKugla &PostaviY(double y){
        pozicija[1]=y;
        provjeriNepreklapanje();
        return *this;
        
    }
    NepreklapajucaKugla &PostaviZ(double z){
        pozicija[2]=z;
        provjeriNepreklapanje();
        return *this;

    }
    
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        pozicija[0]=x;
        pozicija[1]=y;
        pozicija[2]=z;
        provjeriNepreklapanje();
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        pozicija[0]=get<0>(centar);
        pozicija[1]=get<1>(centar);
        pozicija[2]=get<2>(centar);
        provjeriNepreklapanje();
        return *this;
    }
    
    
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        this->r=r;
        provjeriNepreklapanje();
        return *this;
    }
    
    void Ispisi() const{
        std::cout<<"{"<<"("<<pozicija[0]<<","<<pozicija[1]<<","<<pozicija[2]<<"),"<<r<<"}";
    }
    
    
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        this->pozicija[0]+=delta_x;
        this->pozicija[1]+=delta_y;
        this->pozicija[2]+=delta_z;
        provjeriNepreklapanje();
    }
    
    
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
        double veci(vratiVeciManji(k.r,r));
        if(!provjeriRealne(veci,r)) return false;
        double manji(k.r);
        return provjeriRealne(veci-RastojanjeCentara(*this,k),manji) or (veci-RastojanjeCentara(*this,k)>manji); //veci-rastCentara>=manji uz EPS provjeru za jednakost
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    
};


NepreklapajucaKugla* NepreklapajucaKugla::zadnja=nullptr;



double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt( pow( (k1.pozicija[0]-k2.pozicija[0]),2) + pow( (k1.pozicija[1]-k2.pozicija[1]),2) + pow( (k1.pozicija[2] - k2.pozicija[2]),2));
}








int main ()
{
    cout<<"Unesite broj kugli: ";
    int n;
    cin>>n;
    while(!cin or n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!\n";
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>n;
    }
    
    vector<shared_ptr<NepreklapajucaKugla>> kugle;
    
    for(int i=0; i<n; i++){
        try{
            cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            double x,y,z;
            cin>>x>>y>>z;
            while(!cin){
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Neispravan centar, unesite ponovo:\n";
                cin>>x>>y>>z;
            }
            cout<<"Unesite poluprecnik: ";
            double r;
            cin>>r;
            while(r<0 or !cin){
                cout<<"Neispravan poluprecnik, unesite ponovo:\n";
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>r;
            }
            kugle.push_back(make_shared<NepreklapajucaKugla>(x,y,z,r));
        }
        catch(std::domain_error e){
            cout<<e.what()<<endl;
            i--;
        }
        
        catch(std::logic_error e){
            cout<<e.what()<<endl;
            i--;
        }
    }
    cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::sort(kugle.begin(),kugle.end(), [](shared_ptr<NepreklapajucaKugla> s1, shared_ptr<NepreklapajucaKugla> s2) {return s1->DajPovrsinu() < s2->DajPovrsinu();});
    std::for_each(kugle.begin(),kugle.end(), [](shared_ptr<NepreklapajucaKugla> s) { s->Ispisi(); cout<<endl;});

	return 0;
}
