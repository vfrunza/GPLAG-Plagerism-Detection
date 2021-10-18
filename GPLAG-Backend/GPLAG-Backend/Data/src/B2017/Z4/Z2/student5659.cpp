#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <new>
#include <vector>

using namespace std;

const double pi (atan(1) * 4);

class Kugla {
private:
    static Kugla* posljednji=nullptr;
    double r;
    double x,y,z;
    Kugla* prethodni=nullptr;
    
public:
   bool ima(Kugla &bla){
       auto tmp=posljednji;
       while(tmp!=0){
          if(nekiuslovi) return false; // provjera jesu l' isti
           tmp=tmp->prethodni;
       }
       return true;
   }
    explicit Kugla(double r = 0){ 
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        Kugla::r = r; x = y = z = 0;
        if(ima)
        if(posljednji==nullptr) posljednji = this;
        else{
            prethodni=posljednji;
            posljednji=this;
        }
        }
     Kugla(double x, double y, double z, double r = 0){
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        Kugla::r = r; Kugla::x = x; Kugla::y = y; Kugla::z =z;
     }
    explicit Kugla(const tuple<double, double, double> &centar, double r = 0){
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        Kugla::r = r;   x = get<0>(centar); y = get<1>(centar); z = get<2>(centar);
    }
    ~Kugla(){
        auto tmp=posljednji;
        while(tmp!=nullptr&&tmp->posljednji!=this) tmp=tmp->prethodni;
        tmp->prethodni=prethodni;
        if(this==posljednji) posljednji=prethodni;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    tuple<double, double, double> DajCentar() const { return make_tuple(DajX(), DajY(), DajZ()); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4 * pow(DajPoluprecnik(), 2) * pi; }
    double DajZapreminu() const { return (4/3) * pow(DajPoluprecnik(), 3) * pi; }
    
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { PostaviX(x); PostaviY(y); PostaviZ(z); return *this; }
    Kugla &PostaviCentar(const tuple<double, double, double> &centar) { 
        PostaviX( get<0>(centar) ); PostaviY( get<1>(centar) ); PostaviZ( get<2>(centar) );
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) { 
        if(r < 0) throw domain_error("Ilegalan poluprecnik"); 
        Kugla::r = r; return *this; 
    }
    
    
    void Ispisi() const {
        cout<<"{ ("<<x<<","<<y<<","<<z<<") ,"<<r<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){ 
        x += delta_x;   y += delta_y;   z += delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    bool DaLiSadrzi(const Kugla &k) const {
        if(RastojanjeCentara(*this,k) + k.DajPoluprecnik() < Kugla::r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(k1.DajCentar() != k2.DajCentar() || k1.DajPoluprecnik() != k2.DajPoluprecnik()) return false;
    return true;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(k1.DajPoluprecnik() != k2.DajPoluprecnik()) return false;
    return true;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(k1.DajCentar() != k2.DajCentar()) return false;
    return true;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if(RastojanjeCentara(k1,k2) == k1.DajPoluprecnik() + k2.DajPoluprecnik()) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    if(RastojanjeCentara(k1,k2) == abs(k1.DajPoluprecnik() - k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(RastojanjeCentara(k1,k2) + k1.DajPoluprecnik() < k2.DajPoluprecnik() || 
    RastojanjeCentara(k1,k2) + k2.DajPoluprecnik() < k1.DajPoluprecnik()) return true;
    return false;
    }
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if(RastojanjeCentara(k1,k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik() && !DaLiSePreklapaju(k1,k2)) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    double t1;
    t1 = sqrt( pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2) );
    return t1;
}

int main ()
{
    
    cout<<"Unesite broj kugla: ";
    int n;
    cin>>n;
    
    vector <shared_ptr<Kugla>> vek;
    
    for(int i = 0; i < n; i++){
        double x,y,z;
        double r;
        
        cout<<"Unesite centar "<< i + 1 <<". kugle: ";
        cin>>x>>y>>z;
        if(!cin) { cout<<"Ileglane koordinate"<<endl;    i--;    continue; }
        tuple<double, double, double> temp(make_tuple(x,y,z));
        
        cout<<"Unesite poluprecnik "<< i + 1 <<" kugle: ";
        cin>>r;
        if(!cin) { cout<<"Ilegalan poluprecnik"<<endl;   i--;    continue; }
        
        try{
            shared_ptr<Kugla> p(make_shared<Kugla>(temp,r));
             vek.push_back(p);
        }
        catch(domain_error e){
            i--;
            cout<<e.what()<<endl;
        }
    }
    
        
        cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        int delta_z, delta_y, delta_x;
        cin>>delta_x>>delta_y>>delta_z;
        
       transform(vek.begin(), vek.end(), vek.begin(), [delta_x, delta_y, delta_z] ( shared_ptr<Kugla> &k1){ k1->Transliraj(delta_x, delta_y, delta_z); return k1; } );
        
        cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
        
        sort(vek.begin(), vek.end(), [] (const shared_ptr<Kugla> &k1, const shared_ptr<Kugla> &k2) {
            if(k1->DajZapreminu() > k2->DajZapreminu()) return true;
            return false;
        });
        for_each(vek.begin(), vek.end(), [](const shared_ptr<Kugla> &k) {    k->Ispisi();   });
        
        cout<<"Kugla sa najvecom povrsinom je: ";
        
        auto p =max_element(vek.begin(), vek.end(), [] (const shared_ptr<Kugla> &k1, const shared_ptr<Kugla> &k2){
            if(k1->DajPovrsinu() > k2->DajPovrsinu()) return true;
            return false;
        }); 
        (*p)->Ispisi();
        
        int br = 0;
        for_each(vek.begin(), vek.end(), [br,vek] (const shared_ptr<Kugla> &k1){
            for_each(vek.begin(), vek.end(), [br,k1] (const shared_ptr<Kugla> &k2){
                if(DaLiSeSijeku(*k1,*k2)) { 
                    cout<<"Presjecaju se kugle: ";
                    k1->Ispisi(); k2->Ispisi();
                }
            });
        });
        if(br == 0) cout<<"Ne postoje kugle koje se presjecaju!";
        
        
	return 0;
	
}
