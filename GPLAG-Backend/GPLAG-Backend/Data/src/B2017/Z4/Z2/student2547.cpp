#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>
#include <tuple>

using namespace std;

#define e pow(10,-10)
#define pi 4*atan(1)

class Kugla {
    double x,y,z,r;
    mutable Kugla *prethodna=nullptr;
    static Kugla *posljednja;
    public:
    explicit Kugla(double r = 0) {
        if(prethodna==nullptr) {
            Kugla::r=r; x=0; y=0; z=0;
            prethodna=nullptr;
            posljednja=this;
        }
        else {
            Kugla *pom=posljednja;
            while(pom!=nullptr) {
                if(sqrt( (x-(*pom).x)*(x-(*pom).x) + (y-(*pom).y)*(y-(*pom).y) + (z-(*pom).z)*(z-(*pom).z) )<r+(*pom).DajPoluprecnik()) throw logic_error("Preklapanje");
                pom=(*pom).DajPrethodnu();    
            }
            Kugla::r=r; x=0; y=0; z=0;
            prethodna=posljednja;
            posljednja=this;
        }
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(prethodna==nullptr) {
            Kugla::r=r; Kugla::x=x; Kugla::y=y; Kugla::z=z;
            prethodna=nullptr;
            posljednja=this;
        }
        else {
            Kugla *pom=posljednja;
            while(pom!=nullptr) {
                if(sqrt( (x-(*pom).x)*(x-(*pom).x) + (y-(*pom).y)*(y-(*pom).y) + (z-(*pom).z)*(z-(*pom).z) )<r+(*pom).DajPoluprecnik()) throw logic_error("Preklapanje");
                pom=(*pom).DajPrethodnu();    
            }
            Kugla::r=r; Kugla::x=x; Kugla::y=y; Kugla::z=z;
            prethodna=posljednja;
            posljednja=this;
        }
    }
    explicit Kugla(const tuple<double, double, double> &centar, double r = 0) {
        if(prethodna==nullptr) {
            Kugla::r=r; x=get<0>(centar); y=get<1>(centar); z=get<2>(centar);
            prethodna=nullptr;
            posljednja=this;
        }
        else {
            Kugla *pom=posljednja;
            while(pom!=nullptr) {
                if(sqrt( (get<0>(centar)-(*pom).x)*(get<0>(centar)-(*pom).x) + (get<1>(centar)-(*pom).y)*(get<1>(centar)-(*pom).y) + (get<2>(centar)-(*pom).z)*(get<2>(centar)-(*pom).z) )<r+(*pom).DajPoluprecnik()) throw logic_error("Preklapanje");
                pom=(*pom).DajPrethodnu();    
            }
            Kugla::r=r; x=get<0>(centar); y=get<1>(centar); z=get<2>(centar);
            prethodna=posljednja;
            posljednja=this;
        }
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    Kugla *DajPrethodnu() const {
        return this->prethodna;
    }
    Kugla *DajPosljednju() const {
        return this->posljednja;
    }
    tuple<double, double, double> DajCentar() const {
        tuple<double, double, double> centar;
        get<0>(centar)=x; get<1>(centar)=y; get<2>(centar)=z;
        return centar;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return 2*(r*r*r*pi)/3;
    }
    Kugla &PostaviX(double x) {
        this->x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        this->y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        this->x=x; this->y=y; this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(const tuple<double, double, double> &centar) {
        x=get<0>(centar); y=get<1>(centar); z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; 
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    bool DaLiSadrzi(const Kugla &k) const {
        double d(RastojanjeCentara(*this,k));
        if(k.r+d<this->r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return sqrt( (k2.x-k1.x)*(k2.x-k1.x) + (k2.y-k1.y)*(k2.y-k1.y) + (k2.z-k1.z)*(k2.z-k1.z) );
    }
};

Kugla* posljednja=nullptr;

int main () {
    cout << "Unesite broj kugla: ";
    int n(0);
    while(n<1) {
        cin >> n;
        if(cin.fail() || n<1){
            cin.clear();
            cin.ignore(10000, '\n'); 
            n=0;
            cout << "Neispravan broj kugli, unesite ponovo!" << endl;;
        }
    }
    vector<shared_ptr<Kugla>> vektor_ptr;
    int i(0);
    while(i!=n) {
        double x,y,z,r;
        cout << "Unesite centar " << i+1 << ". kugle: ";
        cin >> x >> y >> z;
        int pom(0);
        while(pom==0) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n'); 
                cout << "Neispravan centar" << endl << "Unesite centar " << i+1 << ". kugle: ";
                cin >> x >> y >> z;
            }
            else pom++;
        }
        
        cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        cin >> r;
        if(cin.fail() || r<0){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ilegalan poluprecnik" << endl;
            continue;
        }
        /*try {
            Kugla din_kugla(x,y,z,r);
        }
        catch(logic_error er) {
            cout << er.what();
        }
        Kugla din_kugla(x,y,z,r);*/
        shared_ptr<Kugla> din_kugla(new Kugla(x,y,z,r));
        vektor_ptr.push_back(din_kugla);
        i++;
        
        
    }
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    cin.clear();
    cin.ignore(10000, '\n');
    double dx,dy,dz;
    cin >> dx >> dy >> dz;
    int pom(0);
    while(pom==0) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
            pom=0;
            cin >> dx >> dy >> dz;
        }
        else pom++;
    }
    transform(vektor_ptr.begin(), vektor_ptr.end(), vektor_ptr.begin(),[dx,dy,dz](shared_ptr<Kugla> a){
        (*a).Transliraj(dx,dy,dz); 
        return a; });
    sort(vektor_ptr.begin(), vektor_ptr.end(),[](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) -> bool {
        if((*k1).DajPovrsinu()<(*k2).DajPovrsinu()) return false;
        return true;
    } );
    cout << "Kugle nakon obavljenog sortiranja: " << endl;
    for_each(vektor_ptr.begin(), vektor_ptr.end(), [] (shared_ptr<Kugla> k) {
	    (*k).Ispisi();
	    cout << endl;
	} );
    //if(pr==0) cout << endl << "Ne postoje kugle koje se presjecaju!";
	return 0;

}