/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdexcept>
#define eps 0.000000001
#define pi 4*atan(1)

using namespace std;
bool nema_izac=true;
class Kugla{
    
    double x,y,z,r;
    
    public:
    
    explicit Kugla(double r=0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
         Kugla::x=0; Kugla::y=0; Kugla::z=0; Kugla::r=r;
    }
    
    Kugla(double x, double y, double z, double r=0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    
    explicit Kugla(const tuple<double, double, double> &centar, double r=0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        Kugla::x=get<0>(centar); Kugla::y=get<1>(centar); Kugla::z=get<2>(centar); Kugla::r=r;
    }
    
    double DajX() const{ return Kugla::x;}
    double DajY() const{ return Kugla::y;}
    double DajZ() const{ return Kugla::z;}
    
    tuple <double, double, double> DajCentar() const{ return tuple<double, double, double>{Kugla::x, Kugla::y, Kugla::z};}
    
    double DajPoluprecnik()const{ return Kugla::r;}
    double DajPovrsinu()const{return 2*pi*Kugla::r*Kugla::r;}
    double DajZapreminu()const{ return ((4*Kugla::r*Kugla::r*Kugla::r*pi)/3.);}
    
    Kugla &PostaviX(double x){Kugla::x=x; return *this;}
    Kugla &PostaviY(double y){Kugla::y=y; return *this;}
    Kugla &PostaviZ(double z){Kugla::z=z; return *this;}
    
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;
    }
    
    Kugla &PostaviCentar(const tuple<double, double, double> &centar){
        Kugla::x=get<0>(centar); Kugla::y=get<1>(centar); Kugla::z=get<2>(centar); return *this;
    }
    
    void Ispisi()const{
        cout<<"{("<<Kugla::x<<","<<Kugla::y<<","<<Kugla::z<<"),"<<Kugla::r<<"}";
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        Kugla::x+=delta_x; Kugla::y+=delta_y; Kugla::z+=delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.Kugla::DajX()-k2.Kugla::DajX())<eps*(abs(k1.Kugla::DajX())+abs(k2.Kugla::DajX()))){
            if(abs(k1.Kugla::DajY()-k2.Kugla::DajY())<eps*(abs(k1.Kugla::DajY())+abs(k2.Kugla::DajY()))){
                if(abs(k1.Kugla::DajZ()-k2.Kugla::DajZ())<eps*(abs(k1.Kugla::DajZ())+abs(k2.Kugla::DajZ()))){
                    if(abs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*(abs(k1.Kugla::DajPoluprecnik())+abs(k2.Kugla::DajPoluprecnik()))){
                        return true;                        
                    }
                }
            }
        }
        
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*(abs(k1.Kugla::DajPoluprecnik())+abs(k2.Kugla::DajPoluprecnik()))){
                        return true;                        
        }
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        if(abs(k1.Kugla::DajX()-k2.Kugla::DajX())<eps*(abs(k1.Kugla::DajX())+abs(k2.Kugla::DajX()))){
            if(abs(k1.Kugla::DajY()-k2.Kugla::DajY())<eps*(abs(k1.Kugla::DajY())+abs(k2.Kugla::DajY()))){
                if(abs(k1.Kugla::DajZ()-k2.Kugla::DajZ())<eps*(abs(k1.Kugla::DajZ())+abs(k2.Kugla::DajZ()))){
                    return true;
                }
            }
         }
         return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        if(fabs(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik()-RastojanjeCentara(k1,k2)) < eps*(fabs(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik())+fabs(RastojanjeCentara(k1,k2)))){
            return true;
        }
            return false;
        
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik()-RastojanjeCentara(k1,k2)) < eps*(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())+fabs(RastojanjeCentara(k1,k2)))){
            return true;
        }
            return false;
    }
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
       if(DaLiSeSijeku(k1,k2))return true;
       if(k2.DaLiSadrzi(k1) or k1.DaLiSadrzi(k2)) return true;
       return false;
      // return((fabs(k1.Kugla::r-k2.Kugla::r)<RastojanjeCentara(k1,k2))and (fabs(k1.Kugla::r+k2.Kugla::r)>RastojanjeCentara(k1,k2)));
    }
    
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<RastojanjeCentara(k1,k2))return true;
        else return false;                                                                      //popraviti
    }
    bool DaLiSadrzi(const Kugla &k)const{
       return((fabs(this->DajPoluprecnik()-k.Kugla::r)<RastojanjeCentara(*this,k))and (fabs(this->DajPoluprecnik()+k.Kugla::r)>RastojanjeCentara(*this,k)));
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
    }
};

int main (){
    cout<<"Unesite broj kugla: ";
    int br;
    cin>>br;
   while(br<=0 or cin.fail()){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        cin >>br;
    }
    vector<shared_ptr<Kugla>> v;
    v.resize(br);
    for(int i=0; i<br; i++){
        ponovo:
        double x,y,z;
        molim_te_lijepo:
         cout<<"Unesite centar "<<i+1<<". kugle: ";
        cin>>x>>y>>z;
        if(cin.fail()){
            cout<<"Neispravan centar "<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
           goto molim_te_lijepo;
        }
        double r;
         cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        cin>>r;
        while(cin.fail() or r<0){
            if(r<0 or true){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Ilegalan poluprecnik "<<endl;
            
            goto ponovo;
                
            }
            
        }
        
        try{
            v[i]=make_shared<Kugla>(Kugla{x,y,z,r});
        }catch(domain_error ima_izac){
            cout<<ima_izac.what()<<endl;
            i--;
        }
    }

    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    molim_te:
    double delta_x, delta_y, delta_z;
    cin>>delta_x>> delta_y>>delta_z;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
        goto molim_te;
    }
    transform(v.begin(),v.end(),v.begin(), [delta_x,delta_y,delta_z](shared_ptr<Kugla>pls){
        pls->Transliraj(delta_x,delta_y,delta_z); return pls;
    });
    sort(v.begin(),v.end(),[](shared_ptr<Kugla>k1, shared_ptr<Kugla>k2){
        return (k1->DajZapreminu()<k2->DajZapreminu());
    });
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Kugla> k){
        k->Ispisi(); cout<<endl;
    });
    cout<<"Kugla sa najvecom povrsinom je: ";
    auto p=max_element(v.begin(), v.end(),[](shared_ptr<Kugla>k1, shared_ptr<Kugla>k2){
        return (k1->DajPovrsinu()<k2->DajPovrsinu());
    }); 
    (*p)->Ispisi();
    cout<<endl;
    
    auto it1=v.begin(); auto it2=v.end();
    for_each(it1,it2-1,[it1,it2](shared_ptr<Kugla> kugla){
        for_each(it1+1,it2,[kugla, it1,it2](shared_ptr<Kugla> kugla2){
        if(DaLiSePreklapaju(*kugla,*kugla2) and it1!=it2){
            nema_izac=false;
            cout<<"Presjecaju se kugle: ";
            (*kugla).Ispisi(); cout<<endl; (*kugla2).Ispisi(); cout<<endl;
        }
            
        });
    });
    if(nema_izac)cout<<"Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
