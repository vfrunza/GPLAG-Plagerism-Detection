/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#define PI 4*atan(1)
#define EPS 10e-10
using namespace std;
class Kugla{
    double x, y, z, r;
public: 
    explicit Kugla(double r = 0){ if(r<0) throw domain_error("Ilegalan poluprecnik"); Kugla::x = 0; Kugla::y = 0; Kugla::z = 0; Kugla::r = r; }
    Kugla(double x, double y, double z, double r = 0){ if(r<0) throw domain_error("Ilegalan poluprecnik"); Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r;}
    explicit Kugla(const tuple<double, double, double> &centar, double r = 0){ 
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        x = get<0>(centar); y = get<1>(centar); z = get<2>(centar); Kugla::r = r;
    }
    double DajX() const{ return x; }
    double DajY() const{ return y; }
    double DajZ() const{ return z; }
    
    tuple<double, double, double> DajCentar() const { return tuple<double, double, double>(x,y,z); }
    double DajPoluprecnik () const{ return r; }
    double DajPovrsinu() const{ return 4*PI*r*r;}
    double DajZapreminu() const{ return (4/3)*r*r*r*PI; }
    Kugla &PostaviX(double x){
        Kugla::x = x; return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y = y; return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z = z; return *this;
    }
    
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x = x; Kugla::y = y; Kugla::z = z; return *this;
    }
    Kugla &PostaviCentar(const tuple<double, double, double> &centar){
        Kugla::x = get<0>(centar); Kugla::y = get<1>(centar); Kugla::z = get<2>(centar); return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        Kugla::r = r; return *this;
    }
    
    void Ispisi() const{
        cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}"; 
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        Kugla::x += delta_x; Kugla::y += delta_y; Kugla::z += delta_z; 
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSadrzi(const Kugla &k1, const Kugla &k2);
    

    };
    
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
     if (DaLiSuKoncentricne(k1,k2) && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EPS*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()))) return true; return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EPS*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()));
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return fabs(k1.DajX()-k2.DajX())<EPS*(fabs(k1.DajX())+fabs(k2.DajX()))
    && fabs(k1.DajY()-k2.DajY())<EPS*(fabs(k1.DajY())+fabs(k2.DajY()))
    && fabs(k1.DajZ()-k2.DajZ())<EPS*(fabs(k1.DajZ())+fabs(k2.DajZ()));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt(pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2));
    }
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return fabs(RastojanjeCentara(k1,k2)-(k1.DajPoluprecnik() + k2.DajPoluprecnik()))<EPS*(fabs(RastojanjeCentara(k1,k2))+fabs(k1.DajPoluprecnik() + k2.DajPoluprecnik()));
   // return RastojanjeCentara(k1, k2) == (k1.DajPoluprecnik() + k2.DajPoluprecnik());
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
     if(fabs(RastojanjeCentara(k1, k2)-(k1.DajPoluprecnik() - k2.DajPoluprecnik()))<EPS*(fabs(RastojanjeCentara(k1,k2))+fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()))) 
     return true; return false;
}
bool DaLiSadrzi(const Kugla &k1, const Kugla &k2){
    if( RastojanjeCentara(k1, k2) < (k1.DajPoluprecnik() - k2.DajPoluprecnik()) ) return true; return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return (RastojanjeCentara(k1, k2) < (k1.DajPoluprecnik() + k2.DajPoluprecnik())) && (sqrt(pow(k1.DajPoluprecnik()-k2.DajPoluprecnik(),2)) < RastojanjeCentara(k1,k2));
 } 
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return (DaLiSeSijeku(k1,k2) || DaLiSeDodirujuIznutra(k1, k2) || DaLiSadrzi(k1, k2));
}






int main ()
{   bool provjera(false);
    int n;
    bool ok(false);
    cout << "Unesite broj kugla: ";
    while(!ok){
        
    cin >> n;
    
    
            if(cin.fail() || n<=0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Neispravan broj kugli, unesite ponovo!\n";
            ok = false;
        } else
        {   
            cin.ignore(10000,'\n');
            ok = true;
            break;
        }
         }
   
    
    vector<shared_ptr<Kugla>> v;
    
    for(int i=0; i<n; i++){
        double x, y, z, r;
        for(;;){
            provjera=false;
            ok=false;
        while(!ok){
        cout << "Unesite centar " <<i+1<<". kugle: ";
        cin >> x >> y >> z;
         
            if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Neispravan centar\n";
            ok = false;
        } else
        {   
            cin.ignore(10000,'\n');
            ok = true;
            break;
        }
        
       }
       ok=false;
        while(!ok){
            
        cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        cin >> r;
        
        
            if(cin.fail() || r<0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Ilegalan poluprecnik\n";
            provjera = true;
            ok = false;
        } else 
        {   
            cin.ignore(10000,'\n');
            ok = true;
            break;
        }
        
         if(provjera) break;
        }
        if(!provjera) break;
        }
      //  }
       /* if(!ok){
            if(cin.fail())
        {
            cin.clear();
            cout << "Unesite ponovo";
            ok = false;
        } else
        {   
            cin.ignore();
            ok = true;
            break;
        }
        } */
        
     //   v[i]->PostaviPoluprecnik(r);
        v.push_back(make_shared<Kugla>(x,y,z,r));
    }
    ok = false;
    double dx,dy,dz;
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(!ok){
    cin >> dx >> dy >> dz;
    
            if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Neispravni parametri translacije, unesite ponovo!\n";
            ok = false;
        } else
        {   
            cin.ignore(10000,'\n');
            ok = true;
            break;
        }
        
    
    
    }
    for(int i=0; i<n; i++){
        v[i]->Transliraj(dx,dy,dz);
    }
    sort(v.begin(),v.end(),[](shared_ptr<Kugla> p1, shared_ptr<Kugla> p2){
        if(p1->DajPoluprecnik() < p2->DajPoluprecnik()) return true; else return false;
    });
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    //treba foreach
    for(int i=0; i<n; i++){
        v[i]->Ispisi(); cout << "\n";
    }
    shared_ptr<Kugla> max = *(max_element(v.begin(),v.end(),[](shared_ptr<Kugla> p1, shared_ptr<Kugla> p2){
        if(p1->DajPovrsinu() < p2->DajPovrsinu()) return true; else return false;
    }));
    cout << "Kugla sa najvecom povrsinom je: " ; max->Ispisi();
   int brojac(0);
    for_each(v.begin(), v.end(),[&brojac,&v](shared_ptr<Kugla> p1){
        
        for_each(v.begin()+brojac, v.end(), [&brojac,&p1](shared_ptr<Kugla> p2){
            if(DaLiSeSijeku(*p1,*p2)){ cout << "\nPresjecaju se kugle: ";
            p1->Ispisi(); cout << "\n"; p2->Ispisi(); brojac++; }
        });
    });
    if(brojac==0) cout << "\nNe postoje kugle koje se presjecaju!";
	return 0;
}
